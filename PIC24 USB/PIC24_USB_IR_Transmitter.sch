EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:CircuitHub
LIBS:microchip_hele
LIBS:led_hele
LIBS:PIC24_USB_IR_Transmitter-cache
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date "3 aug 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	950  2550 950  3350
Wire Wire Line
	950  2550 1000 2550
Wire Wire Line
	1000 2700 950  2700
Connection ~ 950  2700
Wire Wire Line
	1000 3000 950  3000
Connection ~ 950  3000
Wire Wire Line
	1000 3150 950  3150
Connection ~ 950  3150
$Comp
L GND #PWR01
U 1 1 52D43B6B
P 2200 3350
F 0 "#PWR01" H 2200 3350 30  0001 C CNN
F 1 "GND" H 2200 3280 30  0001 C CNN
F 2 "" H 2200 3350 60  0000 C CNN
F 3 "" H 2200 3350 60  0000 C CNN
	1    2200 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 3150 2200 3150
Wire Wire Line
	2200 3150 2200 3350
Wire Wire Line
	2250 2000 2250 1950
$Comp
L +5V #PWR02
U 1 1 52D43B8D
P 2250 1950
F 0 "#PWR02" H 2250 2040 20  0001 C CNN
F 1 "+5V" H 2250 2040 30  0000 C CNN
F 2 "" H 2250 1950 60  0000 C CNN
F 3 "" H 2250 1950 60  0000 C CNN
	1    2250 1950
	1    0    0    -1  
$EndComp
$Comp
L CP C1
U 1 1 52D43BC9
P 1200 1350
F 0 "C1" H 1250 1450 40  0000 L CNN
F 1 "47uF" H 1250 1250 40  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 1300 1200 30  0001 C CNN
F 3 "" H 1200 1350 300 0000 C CNN
	1    1200 1350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 52D43BD6
P 1200 1050
F 0 "#PWR03" H 1200 1140 20  0001 C CNN
F 1 "+5V" H 1200 1140 30  0000 C CNN
F 2 "" H 1200 1050 60  0000 C CNN
F 3 "" H 1200 1050 60  0000 C CNN
	1    1200 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 52D43BDC
P 1200 1650
F 0 "#PWR04" H 1200 1650 30  0001 C CNN
F 1 "GND" H 1200 1580 30  0001 C CNN
F 2 "" H 1200 1650 60  0000 C CNN
F 3 "" H 1200 1650 60  0000 C CNN
	1    1200 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 1050 1200 1150
Wire Wire Line
	1200 1550 1200 1650
Wire Wire Line
	2100 2700 5550 2700
Wire Wire Line
	2100 2850 5550 2850
Text Label 2250 2850 0    60   ~ 0
D+
Text Label 2250 2700 0    60   ~ 0
D-
$Comp
L C C2
U 1 1 52D44076
P 8850 3950
F 0 "C2" H 8850 4050 40  0000 L CNN
F 1 "100n" H 8856 3865 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 8888 3800 30  0001 C CNN
F 3 "" H 8850 3950 60  0000 C CNN
	1    8850 3950
	0    -1   -1   0   
$EndComp
Text GLabel 2150 5450 2    60   Output ~ 0
~MCLR~
Wire Wire Line
	1800 5450 2150 5450
Wire Wire Line
	1800 5550 1900 5550
Wire Wire Line
	1900 5550 1900 4850
Connection ~ 2000 5450
Wire Wire Line
	1800 5650 2450 5650
Wire Wire Line
	2450 5650 2450 5900
$Comp
L GND #PWR05
U 1 1 52D450A4
P 2450 5900
F 0 "#PWR05" H 2450 5900 30  0001 C CNN
F 1 "GND" H 2450 5830 30  0001 C CNN
F 2 "" H 2450 5900 60  0000 C CNN
F 3 "" H 2450 5900 60  0000 C CNN
	1    2450 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 5750 2100 5750
Wire Wire Line
	1800 5850 2100 5850
Text GLabel 2100 5750 2    60   Output ~ 0
PGD
Text GLabel 2100 5850 2    60   BiDi ~ 0
PGC
Text GLabel 5350 1100 0    60   Input ~ 0
~MCLR~
$Comp
L GND #PWR06
U 1 1 52D45877
P 10800 4000
F 0 "#PWR06" H 10800 4000 30  0001 C CNN
F 1 "GND" H 10800 3930 30  0001 C CNN
F 2 "" H 10800 4000 60  0000 C CNN
F 3 "" H 10800 4000 60  0000 C CNN
	1    10800 4000
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 52D45886
P 10800 2450
F 0 "#PWR07" H 10800 2540 20  0001 C CNN
F 1 "+5V" H 10800 2540 30  0000 C CNN
F 2 "" H 10800 2450 60  0000 C CNN
F 3 "" H 10800 2450 60  0000 C CNN
	1    10800 2450
	1    0    0    -1  
$EndComp
$Comp
L MOS_N Q1
U 1 1 52D4589F
P 10700 3700
F 0 "Q1" H 10710 3870 60  0000 R CNN
F 1 "2N7002" H 10710 3550 60  0000 R CNN
F 2 "SMD_Packages:SOT-23-GDS" H 10700 3700 60  0001 C CNN
F 3 "" H 10700 3700 60  0000 C CNN
	1    10700 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	10800 3900 10800 4000
$Comp
L R R4
U 1 1 52D4596A
P 10800 2750
F 0 "R4" V 10880 2750 40  0000 C CNN
F 1 "100R" V 10807 2751 40  0000 C CNN
F 2 "SMD_Packages:SMD-1206" V 10730 2750 30  0001 C CNN
F 3 "" H 10800 2750 30  0000 C CNN
	1    10800 2750
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 52D45985
P 10800 3250
F 0 "D3" H 10800 3350 50  0000 C CNN
F 1 "IR_LED" H 10800 3150 50  0000 C CNN
F 2 "LEDs:LED-3MM" H 10800 3250 60  0001 C CNN
F 3 "" H 10800 3250 60  0000 C CNN
	1    10800 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	10800 3500 10800 3450
Wire Wire Line
	10800 3050 10800 3000
Wire Wire Line
	10800 2500 10800 2450
Text GLabel 5250 1900 0    60   BiDi ~ 0
SDA
Text GLabel 5250 1750 0    60   BiDi ~ 0
SCL
Wire Wire Line
	5250 1900 5550 1900
Wire Wire Line
	5250 1750 5550 1750
$Comp
L R R3
U 1 1 52D45E25
P 4450 5450
F 0 "R3" V 4530 5450 40  0000 C CNN
F 1 "330R" V 4457 5451 40  0000 C CNN
F 2 "SMD_Packages:SMD-0603_r" V 4380 5450 30  0001 C CNN
F 3 "" H 4450 5450 30  0000 C CNN
	1    4450 5450
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 52D45E2B
P 4450 5950
F 0 "D2" H 4450 6050 50  0000 C CNN
F 1 "USER_LED" H 4450 5850 50  0000 C CNN
F 2 "LEDs:LED-0603" H 4450 5950 60  0001 C CNN
F 3 "" H 4450 5950 60  0000 C CNN
	1    4450 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 6200 4450 6150
Wire Wire Line
	4450 5750 4450 5700
Wire Wire Line
	4450 4200 5550 4200
Wire Wire Line
	4450 4200 4450 5200
$Comp
L R R1
U 1 1 52D45EB1
P 1650 1200
F 0 "R1" V 1730 1200 40  0000 C CNN
F 1 "330R" V 1657 1201 40  0000 C CNN
F 2 "SMD_Packages:SMD-0603_r" V 1580 1200 30  0001 C CNN
F 3 "" H 1650 1200 30  0000 C CNN
	1    1650 1200
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 52D45EB7
P 1650 1700
F 0 "D1" H 1650 1800 50  0000 C CNN
F 1 "LED_POWER" H 1650 1600 50  0000 C CNN
F 2 "LEDs:LED-0603" H 1650 1700 60  0001 C CNN
F 3 "" H 1650 1700 60  0000 C CNN
	1    1650 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	1650 1950 1650 1900
Wire Wire Line
	1650 1500 1650 1450
Wire Wire Line
	1650 850  1650 950 
$Comp
L GND #PWR08
U 1 1 52D45EC1
P 1650 1950
F 0 "#PWR08" H 1650 1950 30  0001 C CNN
F 1 "GND" H 1650 1880 30  0001 C CNN
F 2 "" H 1650 1950 60  0000 C CNN
F 3 "" H 1650 1950 60  0000 C CNN
	1    1650 1950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR09
U 1 1 52D45EC7
P 1650 850
F 0 "#PWR09" H 1650 940 20  0001 C CNN
F 1 "+5V" H 1650 940 30  0000 C CNN
F 2 "" H 1650 850 60  0000 C CNN
F 3 "" H 1650 850 60  0000 C CNN
	1    1650 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3300 8450 3300
Wire Wire Line
	8450 3400 8350 3400
Wire Wire Line
	8350 3400 8350 3450
Wire Wire Line
	8450 3100 8350 3100
Wire Wire Line
	8350 3100 8350 3050
$Comp
L CONN_4 P5
U 1 1 52D4648F
P 8800 3250
F 0 "P5" V 8750 3250 50  0000 C CNN
F 1 "CONN_4" V 8850 3250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 8800 3250 60  0001 C CNN
F 3 "" H 8800 3250 60  0000 C CNN
	1    8800 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 52D4649C
P 8350 3450
F 0 "#PWR010" H 8350 3450 30  0001 C CNN
F 1 "GND" H 8350 3380 30  0001 C CNN
F 2 "" H 8350 3450 60  0000 C CNN
F 3 "" H 8350 3450 60  0000 C CNN
	1    8350 3450
	1    0    0    -1  
$EndComp
Text Notes 3850 3150 0    60   ~ 0
Analog
Text Notes 8600 3000 0    60   ~ 0
UART
Wire Wire Line
	3600 5000 3700 5000
Wire Wire Line
	3700 5000 3700 5050
Wire Wire Line
	3600 4700 3700 4700
Wire Wire Line
	3700 4700 3700 4650
$Comp
L CONN_4 P2
U 1 1 52D464AE
P 3250 4850
F 0 "P2" V 3200 4850 50  0000 C CNN
F 1 "CONN_4" V 3300 4850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 3250 4850 60  0001 C CNN
F 3 "" H 3250 4850 60  0000 C CNN
	1    3250 4850
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 52D464B4
P 3700 5050
F 0 "#PWR011" H 3700 5050 30  0001 C CNN
F 1 "GND" H 3700 4980 30  0001 C CNN
F 2 "" H 3700 5050 60  0000 C CNN
F 3 "" H 3700 5050 60  0000 C CNN
	1    3700 5050
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 52D464BA
P 3700 4650
F 0 "#PWR012" H 3700 4740 20  0001 C CNN
F 1 "+5V" H 3700 4740 30  0000 C CNN
F 2 "" H 3700 4650 60  0000 C CNN
F 3 "" H 3700 4650 60  0000 C CNN
	1    3700 4650
	-1   0    0    -1  
$EndComp
Text Notes 3450 4600 2    60   ~ 0
I2C
Text GLabel 4100 4900 2    60   BiDi ~ 0
SDA
Text GLabel 4100 4800 2    60   BiDi ~ 0
SCL
$Comp
L CONN_6 P1
U 1 1 52D46642
P 1450 5700
F 0 "P1" V 1400 5700 60  0000 C CNN
F 1 "CONN_6" V 1500 5700 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x06" H 1450 5700 60  0001 C CNN
F 3 "" H 1450 5700 60  0000 C CNN
	1    1450 5700
	-1   0    0    1   
$EndComp
Text Notes 1350 5350 0    60   ~ 0
ICSP
$Comp
L +5V #PWR013
U 1 1 52D469A9
P 3800 4200
F 0 "#PWR013" H 3800 4290 20  0001 C CNN
F 1 "+5V" H 3800 4290 30  0000 C CNN
F 2 "" H 3800 4200 60  0000 C CNN
F 3 "" H 3800 4200 60  0000 C CNN
	1    3800 4200
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 52D469AF
P 3950 4200
F 0 "#PWR014" H 3950 4290 20  0001 C CNN
F 1 "+5V" H 3950 4290 30  0000 C CNN
F 2 "" H 3950 4200 60  0000 C CNN
F 3 "" H 3950 4200 60  0000 C CNN
	1    3950 4200
	-1   0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 52D469B5
P 3800 4500
F 0 "R5" V 3880 4500 40  0000 C CNN
F 1 "4k7" V 3807 4501 40  0000 C CNN
F 2 "SMD_Packages:SMD-0603_r" V 3730 4500 30  0001 C CNN
F 3 "" H 3800 4500 30  0000 C CNN
	1    3800 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4900 3800 4750
Connection ~ 3800 4900
$Comp
L R R6
U 1 1 52D46B46
P 3950 4500
F 0 "R6" V 4030 4500 40  0000 C CNN
F 1 "4k7" V 3957 4501 40  0000 C CNN
F 2 "SMD_Packages:SMD-0603_r" V 3880 4500 30  0001 C CNN
F 3 "" H 3950 4500 30  0000 C CNN
	1    3950 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 4800 3950 4750
Connection ~ 3950 4800
Wire Wire Line
	3950 4250 3950 4200
Wire Wire Line
	3800 4250 3800 4200
Text Label 8200 3200 0    60   ~ 0
RX
Text Label 8200 3300 0    60   ~ 0
TX
NoConn ~ 2100 3000
NoConn ~ 1800 5950
Text Label 4600 4200 0    60   ~ 0
USER_LED
$Comp
L CONN_8 P7
U 1 1 52D8FEBD
P 1450 6850
F 0 "P7" V 1400 6850 60  0000 C CNN
F 1 "CONN_8" V 1500 6850 60  0000 C CNN
F 2 "pin_array_8_50mil" H 1450 6850 60  0001 C CNN
F 3 "" H 1450 6850 60  0000 C CNN
	1    1450 6850
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 52D8FECF
P 2000 7250
F 0 "#PWR015" H 2000 7250 30  0001 C CNN
F 1 "GND" H 2000 7180 30  0001 C CNN
F 2 "" H 2000 7250 60  0000 C CNN
F 3 "" H 2000 7250 60  0000 C CNN
	1    2000 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 6900 2000 6900
Wire Wire Line
	2000 6900 2000 7250
$Comp
L +5V #PWR016
U 1 1 52D8FF66
P 2000 6350
F 0 "#PWR016" H 2000 6440 20  0001 C CNN
F 1 "+5V" H 2000 6440 30  0000 C CNN
F 2 "" H 2000 6350 60  0000 C CNN
F 3 "" H 2000 6350 60  0000 C CNN
	1    2000 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 6350 2000 6800
Wire Wire Line
	2000 6500 1800 6500
NoConn ~ 1800 6600
NoConn ~ 1800 6700
Wire Wire Line
	2000 6800 1800 6800
Connection ~ 2000 6500
Wire Wire Line
	1800 7000 2300 7000
Wire Wire Line
	1800 7100 2300 7100
Wire Wire Line
	1800 7200 2300 7200
Text GLabel 2300 7000 2    60   BiDi ~ 0
SDA
Text GLabel 2300 7100 2    60   BiDi ~ 0
SCL
Text GLabel 2300 7200 2    60   Input ~ 0
~LCD_RESET~
Text GLabel 5250 3950 0    60   Input ~ 0
~LCD_RESET~
Wire Wire Line
	5550 3950 5250 3950
Wire Wire Line
	3600 4800 4100 4800
Wire Wire Line
	3600 4900 4100 4900
Wire Wire Line
	7550 3200 8450 3200
Wire Wire Line
	5550 1100 5350 1100
$Comp
L LM317_SOT223 U2
U 1 1 53DC072C
P 5450 6850
F 0 "U2" H 5450 7150 60  0000 C CNN
F 1 "LM1117_SOT223_3V3" H 5500 6600 60  0000 L CNN
F 2 "SMD_Packages:SOT223" H 5450 6850 60  0000 C CNN
F 3 "~" H 5450 6850 60  0000 C CNN
	1    5450 6850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR017
U 1 1 53DC073B
P 4950 6550
F 0 "#PWR017" H 4950 6640 20  0001 C CNN
F 1 "+5V" H 4950 6640 30  0000 C CNN
F 2 "" H 4950 6550 60  0000 C CNN
F 3 "" H 4950 6550 60  0000 C CNN
	1    4950 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 6700 4950 6700
Wire Wire Line
	4950 6700 4950 6550
Wire Wire Line
	5850 6700 6050 6700
Wire Wire Line
	6050 6700 6050 6600
$Comp
L +3,3V #PWR018
U 1 1 53DC0908
P 6050 6600
F 0 "#PWR018" H 6050 6560 30  0001 C CNN
F 1 "+3,3V" H 6050 6710 30  0000 C CNN
F 2 "" H 6050 6600 60  0000 C CNN
F 3 "" H 6050 6600 60  0000 C CNN
	1    6050 6600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 53DC0948
P 5450 7300
F 0 "#PWR019" H 5450 7300 30  0001 C CNN
F 1 "GND" H 5450 7230 30  0001 C CNN
F 2 "" H 5450 7300 60  0000 C CNN
F 3 "" H 5450 7300 60  0000 C CNN
	1    5450 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 7200 5450 7300
$Comp
L GND #PWR020
U 1 1 53DC0A13
P 6000 7300
F 0 "#PWR020" H 6000 7300 30  0001 C CNN
F 1 "GND" H 6000 7230 30  0001 C CNN
F 2 "" H 6000 7300 60  0000 C CNN
F 3 "" H 6000 7300 60  0000 C CNN
	1    6000 7300
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 53DC0A22
P 6000 6950
F 0 "C13" H 6000 7050 40  0000 L CNN
F 1 "10u" H 6006 6865 40  0000 L CNN
F 2 "Capacitors_SMD:c_1206" H 6038 6800 30  0000 C CNN
F 3 "~" H 6000 6950 60  0000 C CNN
	1    6000 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 6750 6000 6700
Connection ~ 6000 6700
Wire Wire Line
	6000 7150 6000 7300
Wire Wire Line
	4350 1300 4650 1300
Wire Wire Line
	4350 1400 4650 1400
Wire Wire Line
	4350 1500 4650 1500
Wire Wire Line
	4350 1600 4650 1600
Wire Wire Line
	4350 1700 4650 1700
Wire Wire Line
	4350 1800 4650 1800
Wire Wire Line
	4350 1900 4650 1900
Entry Wire Line
	4650 1300 4750 1400
Entry Wire Line
	4650 1400 4750 1500
Entry Wire Line
	4650 1500 4750 1600
Entry Wire Line
	4650 1600 4750 1700
Entry Wire Line
	4650 1700 4750 1800
Entry Wire Line
	4650 1800 4750 1900
Entry Wire Line
	4650 1900 4750 2000
Wire Bus Line
	4750 1300 4750 2150
Text Label 4400 1300 0    60   ~ 0
RE1
Text Label 4400 1400 0    60   ~ 0
RE2
Text Label 4400 1500 0    60   ~ 0
RE3
Text Label 4400 1600 0    60   ~ 0
RE4
Text Label 4400 1700 0    60   ~ 0
RE5
Text Label 4400 1800 0    60   ~ 0
RE6
Text Label 4400 1900 0    60   ~ 0
RE7
Entry Wire Line
	4650 1200 4750 1300
Wire Wire Line
	4350 1200 4650 1200
Text Label 4400 1200 0    60   ~ 0
RE0
$Comp
L CONN_8X2 P8
U 1 1 53DEA70D
P 3950 1550
F 0 "P8" H 3950 2000 60  0000 C CNN
F 1 "CONN_8X2" V 3950 1550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x08" H 3950 1550 60  0001 C CNN
F 3 "" H 3950 1550 60  0000 C CNN
	1    3950 1550
	1    0    0    -1  
$EndComp
Wire Bus Line
	4750 2150 5550 2150
$Comp
L +3,3V #PWR021
U 1 1 53DEBDEC
P 1900 4850
F 0 "#PWR021" H 1900 4810 30  0001 C CNN
F 1 "+3,3V" H 1900 4960 30  0000 C CNN
F 2 "" H 1900 4850 60  0000 C CNN
F 3 "" H 1900 4850 60  0000 C CNN
	1    1900 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 2500 5250 2500
Wire Wire Line
	5550 2400 5250 2400
Text GLabel 5250 2500 0    60   BiDi ~ 0
PGD
Text GLabel 5250 2400 0    60   Input ~ 0
PGC
Text Label 5150 2150 0    60   ~ 0
RE[0..7]
$Sheet
S 9200 1150 1150 1650
U 53E9F776
F0 "Dot Matrix Sheet" 60
F1 "DotMatrix.sch" 60
F2 "R1" I L 9200 2050 60 
F3 "R2" I L 9200 2150 60 
F4 "R3" I L 9200 2250 60 
F5 "R4" I L 9200 2350 60 
F6 "R5" I L 9200 2450 60 
F7 "R6" I L 9200 2550 60 
F8 "R7" I L 9200 2650 60 
F9 "C1" I L 9200 1250 60 
F10 "C2" I L 9200 1350 60 
F11 "C3" I L 9200 1450 60 
F12 "C4" I L 9200 1550 60 
F13 "C5" I L 9200 1650 60 
$EndSheet
Wire Wire Line
	7550 1250 9200 1250
Wire Wire Line
	7550 1350 9200 1350
Wire Wire Line
	7550 1450 9200 1450
Wire Wire Line
	7550 1550 9200 1550
Wire Wire Line
	7550 1650 9200 1650
Wire Wire Line
	7550 2050 9200 2050
Wire Wire Line
	7550 2150 9200 2150
Wire Wire Line
	7550 2250 9200 2250
Wire Wire Line
	7550 2350 9200 2350
Wire Wire Line
	7550 2450 9200 2450
Wire Wire Line
	7550 2550 9200 2550
Wire Wire Line
	7550 2650 9200 2650
$Comp
L +3,3V #PWR022
U 1 1 53EA7361
P 8350 3050
F 0 "#PWR022" H 8350 3010 30  0001 C CNN
F 1 "+3,3V" H 8350 3160 30  0000 C CNN
F 2 "" H 8350 3050 60  0000 C CNN
F 3 "" H 8350 3050 60  0000 C CNN
	1    8350 3050
	1    0    0    -1  
$EndComp
$Comp
L CONN_8 P4
U 1 1 53EA5F01
P 3950 3550
F 0 "P4" V 3900 3550 60  0000 C CNN
F 1 "CONN_8" V 4000 3550 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 3950 3550 60  0001 C CNN
F 3 "" H 3950 3550 60  0000 C CNN
	1    3950 3550
	-1   0    0    -1  
$EndComp
$Comp
L +3,3V #PWR023
U 1 1 53EA6763
P 4400 3150
F 0 "#PWR023" H 4400 3110 30  0001 C CNN
F 1 "+3,3V" H 4400 3260 30  0000 C CNN
F 2 "" H 4400 3150 60  0000 C CNN
F 3 "" H 4400 3150 60  0000 C CNN
	1    4400 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 53EA6786
P 4400 4000
F 0 "#PWR024" H 4400 4000 30  0001 C CNN
F 1 "GND" H 4400 3930 30  0001 C CNN
F 2 "" H 4400 4000 60  0000 C CNN
F 3 "" H 4400 4000 60  0000 C CNN
	1    4400 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3900 4400 3900
Wire Wire Line
	4400 3900 4400 4000
Wire Wire Line
	4300 3200 4400 3200
Wire Wire Line
	4400 3200 4400 3150
Wire Wire Line
	4300 3300 5550 3300
Wire Wire Line
	4300 3400 5550 3400
Wire Wire Line
	4300 3500 5550 3500
Wire Wire Line
	4300 3600 5550 3600
Wire Wire Line
	4300 3700 5550 3700
Wire Wire Line
	4300 3800 5550 3800
Wire Wire Line
	3250 1000 3250 1400
Wire Wire Line
	3250 1000 4800 1000
Wire Wire Line
	4800 1000 4800 1550
Wire Wire Line
	4850 1450 4850 950 
Wire Wire Line
	4850 950  3200 950 
Wire Wire Line
	3200 950  3200 1500
Wire Wire Line
	4900 1350 4900 900 
Wire Wire Line
	4900 900  3150 900 
Wire Wire Line
	3150 900  3150 1600
Wire Wire Line
	4800 1550 5550 1550
Wire Wire Line
	5550 1450 4850 1450
Wire Wire Line
	5550 1350 4900 1350
Wire Wire Line
	5550 1250 4950 1250
Wire Wire Line
	4950 1250 4950 850 
Wire Wire Line
	4950 850  3100 850 
Wire Wire Line
	3100 850  3100 1700
$Comp
L GND #PWR025
U 1 1 53EA8972
P 3450 2000
F 0 "#PWR025" H 3450 2000 30  0001 C CNN
F 1 "GND" H 3450 1930 30  0001 C CNN
F 2 "" H 3450 2000 60  0000 C CNN
F 3 "" H 3450 2000 60  0000 C CNN
	1    3450 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1900 3450 1900
Wire Wire Line
	3450 1800 3450 2000
Wire Wire Line
	3550 1800 3450 1800
Connection ~ 3450 1900
Wire Wire Line
	3100 1700 3550 1700
Wire Wire Line
	3150 1600 3550 1600
Wire Wire Line
	3200 1500 3550 1500
Wire Wire Line
	3250 1400 3550 1400
$Comp
L +5V #PWR026
U 1 1 53EAABDE
P 3500 1150
F 0 "#PWR026" H 3500 1240 20  0001 C CNN
F 1 "+5V" H 3500 1240 30  0000 C CNN
F 2 "" H 3500 1150 60  0000 C CNN
F 3 "" H 3500 1150 60  0000 C CNN
	1    3500 1150
	1    0    0    -1  
$EndComp
$Comp
L +3,3V #PWR027
U 1 1 53EAAC01
P 3350 1150
F 0 "#PWR027" H 3350 1110 30  0001 C CNN
F 1 "+3,3V" H 3350 1260 30  0000 C CNN
F 2 "" H 3350 1150 60  0000 C CNN
F 3 "" H 3350 1150 60  0000 C CNN
	1    3350 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1200 3500 1200
Wire Wire Line
	3500 1200 3500 1150
Wire Wire Line
	3550 1300 3350 1300
Wire Wire Line
	3350 1300 3350 1150
$Comp
L MCP48X2 U4
U 1 1 53EAE6EA
P 8650 4300
F 0 "U4" H 8500 4500 60  0000 C CNN
F 1 "MCP48X2" H 8650 4000 60  0000 C CNN
F 2 "SMD_Packages:MSOP-8" H 8650 4300 60  0001 C CNN
F 3 "" H 8650 4300 60  0000 C CNN
	1    8650 4300
	1    0    0    -1  
$EndComp
$Comp
L CONN_4 P3
U 1 1 53EAE987
P 10200 4350
F 0 "P3" V 10150 4350 50  0000 C CNN
F 1 "CONN_4" V 10250 4350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 10200 4350 60  0001 C CNN
F 3 "" H 10200 4350 60  0000 C CNN
	1    10200 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 4200 9600 4200
Wire Wire Line
	9600 4200 9600 4300
Wire Wire Line
	9600 4300 9850 4300
Wire Wire Line
	9250 4400 9850 4400
Wire Wire Line
	9250 4300 9550 4300
Wire Wire Line
	8100 4200 8150 4200
Wire Wire Line
	8100 3850 8100 4200
Wire Wire Line
	9550 3950 9550 4750
$Comp
L GND #PWR028
U 1 1 53EB3792
P 9550 4750
F 0 "#PWR028" H 9550 4750 30  0001 C CNN
F 1 "GND" H 9550 4680 30  0001 C CNN
F 2 "" H 9550 4750 60  0000 C CNN
F 3 "" H 9550 4750 60  0000 C CNN
	1    9550 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 3950 9050 3950
Connection ~ 9550 4300
Wire Wire Line
	8650 3950 8100 3950
Connection ~ 8100 3950
$Comp
L GND #PWR029
U 1 1 53EB8094
P 9800 4600
F 0 "#PWR029" H 9800 4600 30  0001 C CNN
F 1 "GND" H 9800 4530 30  0001 C CNN
F 2 "" H 9800 4600 60  0000 C CNN
F 3 "" H 9800 4600 60  0000 C CNN
	1    9800 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 4200 9800 4200
Wire Wire Line
	9800 4200 9800 4100
Wire Wire Line
	9800 4500 9800 4600
Wire Wire Line
	9800 4500 9850 4500
Text Label 9600 4400 0    60   ~ 0
VOUTB
$Comp
L GND #PWR030
U 1 1 53EB8CF7
P 9350 5300
F 0 "#PWR030" H 9350 5300 30  0001 C CNN
F 1 "GND" H 9350 5230 30  0001 C CNN
F 2 "" H 9350 5300 60  0000 C CNN
F 3 "" H 9350 5300 60  0000 C CNN
	1    9350 5300
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 53EB8D1B
P 9350 4950
F 0 "R13" V 9430 4950 40  0000 C CNN
F 1 "10k" V 9357 4951 40  0000 C CNN
F 2 "SMD_Packages:SMD-0603_r" V 9280 4950 30  0001 C CNN
F 3 "" H 9350 4950 30  0000 C CNN
	1    9350 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 4500 9350 4500
Wire Wire Line
	9350 4500 9350 4700
Wire Wire Line
	7550 4650 9350 4650
Connection ~ 9350 4650
Wire Wire Line
	9350 5200 9350 5300
Wire Wire Line
	7550 4400 8150 4400
Wire Wire Line
	7550 4500 8150 4500
Wire Wire Line
	7550 4300 8150 4300
Text Label 7900 4300 0    60   ~ 0
~CS~DAC
Text Label 7900 4400 0    60   ~ 0
SCKDAC
Text Label 7900 4500 0    60   ~ 0
SDIDAC
Text Label 7900 4650 0    60   ~ 0
~LDAC~
$Comp
L +5V #PWR031
U 1 1 53EC555A
P 8100 3850
F 0 "#PWR031" H 8100 3940 20  0001 C CNN
F 1 "+5V" H 8100 3940 30  0000 C CNN
F 2 "" H 8100 3850 60  0000 C CNN
F 3 "" H 8100 3850 60  0000 C CNN
	1    8100 3850
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR032
U 1 1 53EC5C84
P 9800 4100
F 0 "#PWR032" H 9800 4190 20  0001 C CNN
F 1 "+5V" H 9800 4190 30  0000 C CNN
F 2 "" H 9800 4100 60  0000 C CNN
F 3 "" H 9800 4100 60  0000 C CNN
	1    9800 4100
	-1   0    0    -1  
$EndComp
Wire Notes Line
	2500 2650 5400 2650
Wire Notes Line
	5400 2900 2500 2900
Wire Notes Line
	2500 2900 2500 2650
Text Notes 2500 2650 0    60   ~ 0
Differential Pair: Z0 = 90R\nFR4 1.6mm: W= 60mil, S = 24mil\n
Wire Notes Line
	5400 2650 5400 2900
Text Label 10050 3700 0    60   ~ 0
IR_LED
$Comp
L R R14
U 1 1 53EF297E
P 2250 2250
F 0 "R14" V 2330 2250 40  0000 C CNN
F 1 "0R" V 2257 2251 40  0000 C CNN
F 2 "SMD_Packages:SMD-1206" V 2180 2250 30  0001 C CNN
F 3 "" H 2250 2250 30  0000 C CNN
	1    2250 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2550 2250 2550
Wire Wire Line
	2250 2550 2250 2500
Text Notes 2350 2300 0    60   ~ 0
replace with polyfuse\nor ferrite if needed
$Comp
L GND #PWR033
U 1 1 53EFE3A1
P 4450 6200
F 0 "#PWR033" H 4450 6200 30  0001 C CNN
F 1 "GND" H 4450 6130 30  0001 C CNN
F 2 "" H 4450 6200 60  0000 C CNN
F 3 "" H 4450 6200 60  0000 C CNN
	1    4450 6200
	-1   0    0    -1  
$EndComp
Text Label 9600 4300 0    60   ~ 0
VOUTA
$Comp
L GND #PWR034
U 1 1 52D43B2E
P 950 3350
F 0 "#PWR034" H 950 3350 30  0001 C CNN
F 1 "GND" H 950 3280 30  0001 C CNN
F 2 "" H 950 3350 60  0000 C CNN
F 3 "" H 950 3350 60  0000 C CNN
	1    950  3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3700 10500 3700
$Sheet
S 5550 1000 2000 3800
U 53DA26B9
F0 "MCUSection" 50
F1 "MCU.sch" 50
F2 "~MCLR" I L 5550 1100 60 
F3 "SCL" B L 5550 1750 60 
F4 "SDA" B L 5550 1900 60 
F5 "RE[0..7]" B L 5550 2150 60 
F6 "PGEC" I L 5550 2400 60 
F7 "PGED" B L 5550 2500 60 
F8 "PORTD0" B R 7550 2050 60 
F9 "PORTD1" B R 7550 2150 60 
F10 "PORTD2" B R 7550 2250 60 
F11 "PORTD3" B R 7550 2350 60 
F12 "PORTD4" B R 7550 2450 60 
F13 "PORTD5" B R 7550 2550 60 
F14 "PORTD6" B R 7550 2650 60 
F15 "PORTD7" B R 7550 1250 60 
F16 "PORTD8" B R 7550 1350 60 
F17 "PORTD9" B R 7550 1450 60 
F18 "PORTD10" B R 7550 1550 60 
F19 "PORTD11" B R 7550 1650 60 
F20 "AN0" B L 5550 3300 60 
F21 "AN1" B L 5550 3400 60 
F22 "AN2" B L 5550 3500 60 
F23 "AN3" B L 5550 3600 60 
F24 "AN4" B L 5550 3700 60 
F25 "AN5" B L 5550 3800 60 
F26 "RP21/RG6" B L 5550 1250 60 
F27 "RP26/RG7" B L 5550 1350 60 
F28 "RP19/RG8" B L 5550 1450 60 
F29 "RP27/RG9" B L 5550 1550 60 
F30 "D+" B L 5550 2850 60 
F31 "D-" B L 5550 2700 60 
F32 "RF0" B L 5550 3950 60 
F33 "RF1" B L 5550 4200 60 
F34 "AN8/RP8/RB8" B R 7550 4500 60 
F35 "AN9/RP9/RB9" B R 7550 4400 60 
F36 "AN10/RB10" B R 7550 4650 60 
F37 "AN11/RB11" B R 7550 4050 60 
F38 "AN12/RB12" B R 7550 4150 60 
F39 "AN13/RB1" B R 7550 3700 60 
F40 "AN15/RP29/RB15" B R 7550 3200 60 
F41 "AN14/RP14/RB14" B R 7550 3300 60 
F42 "RP16/RF3" B R 7550 4300 60 
$EndSheet
$Comp
L CONN_1 P6
U 1 1 53EB4765
P 6900 5000
F 0 "P6" H 6980 5000 40  0000 L CNN
F 1 "CONN_1" H 6900 5055 30  0001 C CNN
F 2 "Symbols:Symbol_OSHW-Logo_SilkScreen" H 6900 5000 60  0001 C CNN
F 3 "" H 6900 5000 60  0000 C CNN
	1    6900 5000
	1    0    0    -1  
$EndComp
Text Label 2100 2550 0    60   ~ 0
VIN
$Comp
L USB-MINI-B CON1
U 1 1 53ED0E9A
P 1550 2850
F 0 "CON1" H 1300 3300 60  0000 C CNN
F 1 "USB-MINI-B" H 1500 2350 60  0000 C CNN
F 2 "Connect:USB_MINI_B" H 1550 2850 60  0001 C CNN
F 3 "" H 1550 2850 60  0000 C CNN
	1    1550 2850
	-1   0    0    -1  
$EndComp
$Comp
L MCP9700 U5
U 1 1 53EC8FC0
P 6100 5900
F 0 "U5" H 6050 6150 60  0000 C CNN
F 1 "MCP9700" H 6050 5750 60  0000 C CNN
F 2 "Discret:TO92-123" H 6150 5900 60  0001 C CNN
F 3 "" H 6150 5900 60  0000 C CNN
	1    6100 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 4050 7750 4050
Wire Wire Line
	7750 4050 7750 5850
Wire Wire Line
	7750 5850 6500 5850
Text Label 6900 5850 0    60   ~ 0
VOUT_TEMP_SEMS
$Comp
L GND #PWR035
U 1 1 53ECDE47
P 6700 6150
F 0 "#PWR035" H 6700 6150 30  0001 C CNN
F 1 "GND" H 6700 6080 30  0001 C CNN
F 2 "" H 6700 6150 60  0000 C CNN
F 3 "" H 6700 6150 60  0000 C CNN
	1    6700 6150
	1    0    0    -1  
$EndComp
$Comp
L C C14
U 1 1 53ECF8B3
P 6700 5850
F 0 "C14" H 6700 5950 40  0000 L CNN
F 1 "100n" H 6706 5765 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 6738 5700 30  0001 C CNN
F 3 "" H 6700 5850 60  0000 C CNN
	1    6700 5850
	1    0    0    -1  
$EndComp
$Comp
L +3,3V #PWR036
U 1 1 53ED014E
P 6700 5500
F 0 "#PWR036" H 6700 5460 30  0001 C CNN
F 1 "+3,3V" H 6700 5610 30  0000 C CNN
F 2 "" H 6700 5500 60  0000 C CNN
F 3 "" H 6700 5500 60  0000 C CNN
	1    6700 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 5750 6600 5750
Wire Wire Line
	6600 5750 6600 5600
Wire Wire Line
	6600 5600 6700 5600
Wire Wire Line
	6700 5500 6700 5650
Connection ~ 6700 5600
Wire Wire Line
	6500 5950 6600 5950
Wire Wire Line
	6600 5950 6600 6100
Wire Wire Line
	6600 6100 6700 6100
Wire Wire Line
	6700 6050 6700 6150
Connection ~ 6700 6100
Text Notes 10600 7650 0    60   ~ 0
0.2
$EndSCHEMATC
