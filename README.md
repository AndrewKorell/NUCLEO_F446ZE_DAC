#This is a practice portfolio project 
#hardware: ST NUCLEO_F466ZE Development board
#Dev Environment: STM32CubeMX and STMCube IDE 

##Purpose
It resembles something I worked on but didn't have enough time to get into. It sets me up for a couple audio project ideas I'm interesting in. There are a few low-level coding challenges with the timers and sample rates. Doesn't rely on blindly implementing middleware. 


##Design 
For now DAC1 is fed out of PA4 with a 20K resistor from PA4 down to AGND. 
I am measuring the output on an oscilloscope and varifying internal values using the debugger. 

##Plan Part 1
1. Generate a SIN Wave on DAC1 in the While loop using standard function calls 
2. Generate a SIN wave in TIM6. 
3. Make the Sinewave adjustable by commands on UART2 (frequency and offset)


##Plan Part 2 
1. Read the sinewave on the ADC channel
2. Analyze the sinewave for Peak-Peak, Frequency, and RMS
