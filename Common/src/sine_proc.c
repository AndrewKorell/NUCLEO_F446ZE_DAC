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


uint16_t zero_crossing_count = 0;
uint16_t adc_data;
uint16_t adc_max = 1;
uint16_t adc_min = 4095;
const uint32_t adc_thres = 200;
uint16_t adc_thr_stp = 0;
uint16_t adc_pp;
const double raw_scale = 4096.0;


uint16_t GetPeakToPeak()
{
	return adc_max - adc_min;
}



wave_stats GetRmsRaw(uint16_t* sine_data, uint16_t size)
{
	//wave_stats wave;

	double acc = 0;
	double mean = 0;
	adc_min = 4095;
	adc_max = 1;
	uint16_t wave_count = 0;
	bool is_falling = false;
	bool is_rising = false;
    uint16_t thres = 0;
    uint16_t end = 0;
    uint16_t start = 0;
	uint16_t x = size;

	//find last edge in sample data, determine if is rising or falling
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
	uint16_t prev_trig = 0;
	while(x < end)
	{
		if(is_rising && sine_data[x] > sine_data[x-1] && sine_data[x-1] < thres && sine_data[x+1] > thres)
		{

			if(start == 0) start = x;

			if(x > (prev_trig + 1)) wave_count++;

			prev_trig = x;

		}

		if(is_falling && sine_data[x] < sine_data[x-1] && sine_data[x-1] > thres && sine_data[x+1] < thres )
		{
			if(start == 0) start = x;

			if(x > (prev_trig + 1)) wave_count++;

			prev_trig = x;
		}
		x++;
	}

	for(uint16_t i = start; i < end; i++)
	{
		acc += pow((double) (sine_data[i] / raw_scale), 2);
		if(sine_data[i] > adc_max) adc_max = sine_data[i];
		if(sine_data[i] < adc_min) adc_min = sine_data[i];
	}


	//wave.min = adc_min;
	//wave.max = adc_max;

	mean = (acc / (float) (end - start));

	double root = sqrt(mean);

	uint16_t rms = (uint16_t) (root * raw_scale);

	float period = (float) (end-start) / (float) wave_count;

	wave_stats wave = { adc_min, adc_max, wave_count, (uint16_t) mean, rms, period };

	return wave;

}


void ProcessSineInRam(uint16_t* sine_data, uint16_t size)
{

	volatile uint32_t period_step = 0;
	adc_max = 2048;
	adc_min = 2048;
	adc_thr_stp = 0;
	zero_crossing_count = 0;

	for(uint16_t i = 0; i < size; i++)
	{
		adc_data = sine_data[i];
		//printf("%d\n", adc_data);

		if(sine_data[i] > adc_max)
		{
			adc_max = adc_data;
			//printf("new max %d", (uint16_t) adc_max);
		}
		else if(sine_data[i] < adc_min)
		{
			adc_min = sine_data[i];
			//printf("new min %d", (uint16_t) adc_min);
		}

		//measure period by counting steps between points where adc_thres is crossed
		//in an upward direction.
		if((i > 0) && (sine_data[i] > (adc_thres + 10)) && (sine_data[i-1] <= (adc_thres - 10)))
		{
			zero_crossing_count++;
			adc_thr_stp = period_step;
			period_step = 0;
		}
		period_step++;
	}
}

