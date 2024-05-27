This is a practice portfolio project

#Hardware

ST NUCLEO_F466ZE Development board

#Dev Environment 

STM32CubeMX and STMCube IDE 

#Purpose

A portfolio project. But, it resembles an implemetnation I was unhappy with in the past. I think it's a good portfolio project it focuses on the kind of sensors I have worked with on a daily basis gets into low-level timers and performance, and doesn't overly rely on libraries or middleware. 

#Design 

For now DAC1 is fed out of PA4 with a 20K resistor from PA4 down to AGND. I am measuring the output on an oscilloscope and varifying internal values using the debugger. 

#Plan Part 1

1. Generate a SIN Wave on DAC1 in the While loop using standard function calls 
2. Generate a SIN wave in TIM6. 
3. Make the Sinewave adjustable by commands on UART2 (frequency and offset)


#Plan Part 2 

1. Read the sinewave on the ADC channel
2. Analyze the sinewave for Peak-Peak, Frequency, and RMS
