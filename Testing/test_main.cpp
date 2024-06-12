/*
 * MyFirstTest.cpp
 *
 *  Created on: Jun 4, 2024
 *      Author: andyk
 */

#include <gtest/gtest.h>


extern "C"
{
#include "../Common/inc/testables.h"
#include "../Common/inc/wave_data.h"
#include "../Common/inc/sine_proc.h"
}


int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}


TEST(BasicCTest, PassingSumTest)
{
	int x = sum(10, 20);
	EXPECT_EQ(x, 30);
}

TEST(BasicCTest, PassingProductTest)
{
	int x = product(10, 20);
	EXPECT_EQ(x, 200);
}

TEST(WaveTest, TestRmsProcess)
{
	uint16_t wave_data[125] = { 685, 629, 349, 196, 90, 69, 101, 547, 1223, 1947, 2056, 2823, 3506, 3929, 4016, 4019, 3983, 3523, 2882, 2192, 1344, 794, 614, 167, 70, 119, 581, 1192, 1996, 2602, 2832, 3495, 3946, 4016, 4018, 4020, 3279, 2861, 2115, 1307, 677, 318, 167, 62, 108, 595, 1228, 1950, 2763, 3168, 3508, 3935, 4012, 4018, 3923, 3529, 2852, 2087, 1332, 642, 220, 136, 84, 122, 598, 1255, 1995, 2641, 3411, 3532, 3949, 4007, 4019, 3633, 3218, 2337, 2075, 1301, 667, 192, 84, 85, 356, 601, 1262, 2035, 2767, 3232, 3866, 3958, 4009, 4015, 3557, 2973, 2859, 1642, 1287, 635, 171, 75, 86, 512, 605, 1254, 2049, 2799, 3428, 3662, 4004, 4013, 4014, 3532, 2903, 2306, 2072, 1017, 624, 189, 68, 91, 566, 1133, 1256, 2039, 2825 };
	wave_stats wave = GetRmsRaw(wave_data, 125);
	EXPECT_EQ(wave.rms, 2540);
	EXPECT_EQ(wave.min, 62);
	EXPECT_EQ(wave.max, 4020);
	EXPECT_EQ(wave.no_waves, 6);
	EXPECT_NEAR(wave.samples_per_period, 18.8, .1);

}
