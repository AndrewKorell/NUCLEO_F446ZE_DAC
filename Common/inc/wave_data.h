/*
 * wave_data.h
 *
 *  Created on: Jun 3, 2024
 *      Author: Andrew Korell
 */

#ifndef INC_WAVE_DATA_H_
#define INC_WAVE_DATA_H_

//32 bit sinewave for 12-bit DAC
const uint16_t sinewave_len = 32;
const uint32_t sinewave_data[32] = {2048, 2447, 2831, 3185, 3495, 3750, 3939, 4056, 4095, 4057, 3940, 3752, 3497, 3188, 2834, 2450, 2051, 1651, 1267, 913, 602, 347, 157, 40, 0, 38, 153, 342, 595, 905, 1258, 1642 };



#endif /* INC_WAVE_DATA_H_ */
