/*
 * sine_proc.h
 *
 *  Created on: Jun 10, 2024
 *      Author: andyk
 */

#ifndef INC_SINE_PROC_H_
#define INC_SINE_PROC_H_


uint16_t GetRmsRaw(uint16_t* sine_data, uint16_t size);
void ProcessSineInRam(uint16_t* sine_data, uint16_t size);


#endif /* INC_SINE_PROC_H_ */
