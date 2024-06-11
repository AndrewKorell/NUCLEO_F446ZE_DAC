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
	uint16_t min;
	uint16_t max;
	uint16_t no_waves;
	uint16_t mean;
	uint16_t rms;
	float samples_per_period;
}wave_stats;

wave_stats GetRmsRaw(uint16_t* sine_data, uint16_t size);
void ProcessSineInRam(uint16_t* sine_data, uint16_t size);


#endif /* INC_SINE_PROC_H_ */
