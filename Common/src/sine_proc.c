/*
 * sine_proc.c
 *
 *  Created on: Jun 3, 2024
 *      Author: Andrew Korell
 */
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "../inc/sine_proc.h"


uint16_t adc_max = 1;
uint16_t adc_min = 4095;
const double raw_scale = 4096.0;



/*
 * Andrew Korell 2024-06-13
 * Expected Data is a Sine Wave
 * 1. end = Find the last rising/falling edge and determine the trigger threshold
 * 2. start = Find the first rising/falling edge with the threshold in 1
 * 3. Wave Count = count the number of rising/falling edges in the data set
 * return wave_data
 */

uint16_t wave_count = 0;
uint16_t prev_trig = 0;

wave_data PreprocessWave(uint16_t* sine_data, uint16_t size)
{

	//uint16_t wave_count = 0;
	bool is_falling = false;
	bool is_rising = false;
    uint16_t thres = 0;
    uint16_t end = 0;
    uint16_t start = 0;
	uint16_t x = size-1;

	while(x > 0 && !is_rising && !is_falling)
	{
		if(x < 5) break;

		if(sine_data[x-2] > sine_data[x-1] && sine_data[x-1] > sine_data[x])
		{
			is_falling = true;
			thres = sine_data[x];
			end = x;
			break;
		}

		if(sine_data[x-2] < sine_data[x-1] && sine_data[x-1] < sine_data[x])
		{
			is_rising = true;
			thres = sine_data[x];
			end = x;
			break;
		}

		x--;
	}

	//find beginning of RMS sample and count edges for time states
	x = 2;
	prev_trig = 0;
	wave_count = 0;
	while(x < end)
	{
		if(is_rising && sine_data[x] > sine_data[x-1] && sine_data[x-1] < thres && sine_data[x+1] > thres)
		{

			if(start == 0) start = x;

			if(x > (prev_trig + 15))
				wave_count++;

			prev_trig = x;

		}

		if(is_falling && sine_data[x] < sine_data[x-1] && sine_data[x-1] > thres && sine_data[x+1] < thres )
		{
			if(start == 0) start = x;

			if(x > (prev_trig + 15))
				wave_count++;

			prev_trig = x;
		}
		x++;
	}

	wave_data wd = { start, end, (end - start), wave_count };

	return wd;

}


/*
 * Andrew Korell 2024-16-13
 * This will calculate the RMS, Mean, Frequency, and Period of the sine wave
 * The output is raw data
 *
 */
wave_stats GetRmsRaw(uint16_t* sine_data, uint16_t size)
{
	double acc = 0;
	double mean = 0;
	uint16_t adc_min = 4095;
	uint16_t adc_max = 1;

	wave_data wd = PreprocessWave(sine_data, size);

	for(uint16_t i = wd.start; i < wd.end; i++)
	{
		acc += pow((double) (sine_data[i] / raw_scale), 2);
		if(sine_data[i] > adc_max) adc_max = sine_data[i];
		if(sine_data[i] < adc_min) adc_min = sine_data[i];
	}


	mean = (acc / (float) (wd.size));

	double root = sqrt(mean);

	uint16_t rms = (uint16_t) (root * raw_scale);

	float period = (float) (wd.size) / (float) wd.no_waves;

	wave_stats wave = { adc_min, adc_max, (adc_max-adc_min), (uint16_t) (mean * raw_scale), rms, period };

	return wave;
}


