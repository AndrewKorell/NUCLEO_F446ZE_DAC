/*
 * sine_proc.h
 *
 *  Created on: Jun 10, 2024
 *      Author: andyk
 */

#ifndef INC_SINE_PROC_H_
#define INC_SINE_PROC_H_

typedef struct
{
	uint16_t offset;
	uint16_t peak;
	uint16_t peak_to_peak;
	uint16_t mean;
	uint16_t rms;
	float samples_per_period;
}wave_stats;


typedef struct
{
	uint16_t start;
	uint16_t end;
	uint16_t size;
	uint16_t no_waves;
}wave_data;


wave_data PreprocessWave(uint16_t* sine_data, uint16_t size);
wave_stats GetRmsRaw(uint16_t* sine_data, uint16_t size);

#endif /* INC_SINE_PROC_H_ */
