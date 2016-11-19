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
LIBS:test-cache
LIBS:mcp23017_qfn28
LIBS:I2C_Backpack-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L GND #PWR13
U 1 1 56D3274C
P 3000 3050
F 0 "#PWR13" H 3000 2800 50  0001 C CNN
F 1 "GND" H 3000 2900 50  0000 C CNN
F 2 "" H 3000 3050 50  0000 C CNN
F 3 "" H 3000 3050 50  0000 C CNN
	1    3000 3050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR9
U 1 1 56D3276B
P 2550 3100
F 0 "#PWR9" H 2550 2950 50  0001 C CNN
F 1 "+5V" H 2550 3240 50  0000 C CNN
F 2 "" H 2550 3100 50  0000 C CNN
F 3 "" H 2550 3100 50  0000 C CNN
	1    2550 3100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR7
U 1 1 56D3279B
P 2000 3450
F 0 "#PWR7" H 2000 3300 50  0001 C CNN
F 1 "+5V" H 2000 3590 50  0000 C CNN
F 2 "" H 2000 3450 50  0000 C CNN
F 3 "" H 2000 3450 50  0000 C CNN
	1    2000 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR8
U 1 1 56D327A9
P 2000 4450
F 0 "#PWR8" H 2000 4200 50  0001 C CNN
F 1 "GND" H 2000 4300 50  0000 C CNN
F 2 "" H 2000 4450 50  0000 C CNN
F 3 "" H 2000 4450 50  0000 C CNN
	1    2000 4450
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 56D327CE
P 2000 3700
F 0 "R3" V 2080 3700 50  0000 C CNN
F 1 "R" V 2000 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1930 3700 50  0000 C CNN
F 3 "" H 2000 3700 50  0000 C CNN
	1    2000 3700
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 56D327FB
P 2000 4200
F 0 "R4" V 2080 4200 50  0000 C CNN
F 1 "R" V 2000 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1930 4200 50  0000 C CNN
F 3 "" H 2000 4200 50  0000 C CNN
	1    2000 4200
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P2
U 1 1 56D328D3
P 1600 3950
F 0 "P2" H 1600 4050 50  0000 C CNN
F 1 "CONN_01X01" V 1700 3950 50  0000 C CNN
F 2 "" H 1600 3950 50  0000 C CNN
F 3 "" H 1600 3950 50  0000 C CNN
	1    1600 3950
	-1   0    0    1   
$EndComp
Text Label 2100 3950 0    60   ~ 0
LCD_VO
$Comp
L GND #PWR14
U 1 1 56D32937
P 3400 3050
F 0 "#PWR14" H 3400 2800 50  0001 C CNN
F 1 "GND" H 3400 2900 50  0000 C CNN
F 2 "" H 3400 3050 50  0000 C CNN
F 3 "" H 3400 3050 50  0000 C CNN
	1    3400 3050
	1    0    0    -1  
$EndComp
Text Label 4500 4950 0    60   ~ 0
LCD_E
Text Label 4500 4850 0    60   ~ 0
LCD_RS
$Comp
L GND #PWR15
U 1 1 56D32AF9
P 4500 3450
F 0 "#PWR15" H 4500 3200 50  0001 C CNN
F 1 "GND" H 4500 3300 50  0000 C CNN
F 2 "" H 4500 3450 50  0000 C CNN
F 3 "" H 4500 3450 50  0000 C CNN
	1    4500 3450
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 56D32B1B
P 4500 3200
F 0 "R5" V 4580 3200 50  0000 C CNN
F 1 "R" V 4500 3200 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4430 3200 50  0000 C CNN
F 3 "" H 4500 3200 50  0000 C CNN
	1    4500 3200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR12
U 1 1 56D33CF3
P 2900 5950
F 0 "#PWR12" H 2900 5800 50  0001 C CNN
F 1 "+5V" H 2900 6090 50  0000 C CNN
F 2 "" H 2900 5950 50  0000 C CNN
F 3 "" H 2900 5950 50  0000 C CNN
	1    2900 5950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR11
U 1 1 56D34088
P 2850 5450
F 0 "#PWR11" H 2850 5200 50  0001 C CNN
F 1 "GND" H 2850 5300 50  0000 C CNN
F 2 "" H 2850 5450 50  0000 C CNN
F 3 "" H 2850 5450 50  0000 C CNN
	1    2850 5450
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 56D340B9
P 2750 5200
F 0 "C2" H 2775 5300 50  0000 L CNN
F 1 "100n" H 2775 5100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2788 5050 50  0000 C CNN
F 3 "" H 2750 5200 50  0000 C CNN
	1    2750 5200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR10
U 1 1 56D33CCA
P 2850 4850
F 0 "#PWR10" H 2850 4700 50  0001 C CNN
F 1 "+5V" H 2850 4990 50  0000 C CNN
F 2 "" H 2850 4850 50  0000 C CNN
F 3 "" H 2850 4850 50  0000 C CNN
	1    2850 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3050 3000 2950
Wire Wire Line
	3100 2950 3100 3850
Wire Wire Line
	3100 3850 2550 3850
Wire Wire Line
	2550 3850 2550 3100
Wire Wire Line
	3200 3950 3200 2950
Wire Wire Line
	1800 3950 3200 3950
Connection ~ 2000 3950
Wire Wire Line
	2000 3850 2000 4050
Wire Wire Line
	2000 4350 2000 4450
Wire Wire Line
	2000 3450 2000 3550
Wire Wire Line
	3400 3050 3400 2950
Wire Wire Line
	3500 2950 3500 4450
Wire Wire Line
	4100 2950 4100 4050
Wire Wire Line
	4200 2950 4200 4000
Wire Wire Line
	4300 2950 4300 3950
Wire Wire Line
	4000 2950 4000 4100
Wire Wire Line
	4400 2950 4400 4400
Wire Wire Line
	4500 2950 4500 3050
Wire Wire Line
	4500 3350 4500 3450
Wire Wire Line
	4300 3950 5400 3950
Wire Wire Line
	5400 3950 5400 5150
Wire Wire Line
	4200 4000 5350 4000
Wire Wire Line
	5350 4000 5350 5250
Wire Wire Line
	4100 4050 5300 4050
Wire Wire Line
	5300 4050 5300 5350
Wire Wire Line
	4000 4100 5250 4100
Wire Wire Line
	5250 4100 5250 5450
Wire Wire Line
	2900 6050 3450 6050
Wire Wire Line
	2900 6050 2900 5950
Wire Wire Line
	2950 4950 2950 5150
Wire Wire Line
	2950 5150 3450 5150
Wire Wire Line
	3450 5250 2950 5250
Wire Wire Line
	2950 5400 2950 5250
Wire Wire Line
	2750 5050 2750 4950
Wire Wire Line
	2750 5350 2750 5400
Wire Wire Line
	2850 4950 2850 4850
Connection ~ 2850 4950
Wire Wire Line
	2750 4950 2950 4950
Wire Wire Line
	2850 5400 2850 5450
Connection ~ 2850 5400
Wire Wire Line
	2750 5400 2950 5400
$Comp
L GND #PWR2
U 1 1 56D3469F
P 1200 2850
F 0 "#PWR2" H 1200 2600 50  0001 C CNN
F 1 "GND" H 1200 2700 50  0000 C CNN
F 2 "" H 1200 2850 50  0000 C CNN
F 3 "" H 1200 2850 50  0000 C CNN
	1    1200 2850
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 56D346A5
P 1200 2650
F 0 "C1" H 1225 2750 50  0000 L CNN
F 1 "1u" H 1225 2550 50  0000 L CNN
F 2 "Capacitors_SMD:C_1812_HandSoldering" H 1238 2500 50  0000 C CNN
F 3 "" H 1200 2650 50  0000 C CNN
	1    1200 2650
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR1
U 1 1 56D346AB
P 1200 2400
F 0 "#PWR1" H 1200 2250 50  0001 C CNN
F 1 "+5V" H 1200 2540 50  0000 C CNN
F 2 "" H 1200 2400 50  0000 C CNN
F 3 "" H 1200 2400 50  0000 C CNN
	1    1200 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2500 1200 2400
Wire Wire Line
	1200 2800 1200 2850
$Comp
L GND #PWR16
U 1 1 56D34884
P 4500 6200
F 0 "#PWR16" H 4500 5950 50  0001 C CNN
F 1 "GND" H 4500 6050 50  0000 C CNN
F 2 "" H 4500 6200 50  0000 C CNN
F 3 "" H 4500 6200 50  0000 C CNN
	1    4500 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 6150 4500 6150
Wire Wire Line
	4500 6150 4500 6200
Wire Wire Line
	2200 5750 3450 5750
$Comp
L +5V #PWR5
U 1 1 56D34B25
P 1900 5850
F 0 "#PWR5" H 1900 5700 50  0001 C CNN
F 1 "+5V" H 1900 5990 50  0000 C CNN
F 2 "" H 1900 5850 50  0000 C CNN
F 3 "" H 1900 5850 50  0000 C CNN
	1    1900 5850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 56D34B2B
P 1900 6850
F 0 "#PWR6" H 1900 6600 50  0001 C CNN
F 1 "GND" H 1900 6700 50  0000 C CNN
F 2 "" H 1900 6850 50  0000 C CNN
F 3 "" H 1900 6850 50  0000 C CNN
	1    1900 6850
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 56D34B31
P 1900 6100
F 0 "R1" V 1980 6100 50  0000 C CNN
F 1 "R" V 1900 6100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1830 6100 50  0000 C CNN
F 3 "" H 1900 6100 50  0000 C CNN
	1    1900 6100
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 56D34B37
P 1900 6600
F 0 "R2" V 1980 6600 50  0000 C CNN
F 1 "R" V 1900 6600 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1830 6600 50  0000 C CNN
F 3 "" H 1900 6600 50  0000 C CNN
	1    1900 6600
	1    0    0    -1  
$EndComp
Connection ~ 1900 6350
Wire Wire Line
	1900 6250 1900 6450
Wire Wire Line
	1900 6750 1900 6850
Wire Wire Line
	1900 5850 1900 5950
Wire Wire Line
	2200 5750 2200 6350
Wire Wire Line
	2200 6350 1900 6350
Wire Wire Line
	3450 5950 3350 5950
Wire Wire Line
	3350 5950 3350 6050
Connection ~ 3350 6050
Wire Wire Line
	3450 5850 3250 5850
Wire Wire Line
	3250 5850 3250 6050
Connection ~ 3250 6050
Text Label 2050 6350 0    60   ~ 0
A0
$Comp
L CONN_01X04 P1
U 1 1 56D3568B
P 1250 5500
F 0 "P1" H 1250 5750 50  0000 C CNN
F 1 "CONN_01X04" V 1350 5500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x04" H 1250 5500 50  0000 C CNN
F 3 "" H 1250 5500 50  0000 C CNN
	1    1250 5500
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR3
U 1 1 56D35911
P 1550 5200
F 0 "#PWR3" H 1550 5050 50  0001 C CNN
F 1 "+5V" H 1550 5340 50  0000 C CNN
F 2 "" H 1550 5200 50  0000 C CNN
F 3 "" H 1550 5200 50  0000 C CNN
	1    1550 5200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 56D35974
P 1550 5800
F 0 "#PWR4" H 1550 5550 50  0001 C CNN
F 1 "GND" H 1550 5650 50  0000 C CNN
F 2 "" H 1550 5800 50  0000 C CNN
F 3 "" H 1550 5800 50  0000 C CNN
	1    1550 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 5650 1550 5650
Wire Wire Line
	1550 5650 1550 5800
Wire Wire Line
	1450 5350 1550 5350
Wire Wire Line
	1550 5350 1550 5200
Wire Wire Line
	3450 5450 3200 5450
Wire Wire Line
	3200 5450 3200 5600
Wire Wire Line
	3200 5600 1700 5600
Wire Wire Line
	1700 5600 1700 5450
Wire Wire Line
	1700 5450 1450 5450
Wire Wire Line
	3250 5550 3450 5550
Wire Wire Line
	3250 5550 3250 5650
Wire Wire Line
	3250 5650 1650 5650
Wire Wire Line
	1650 5650 1650 5550
Wire Wire Line
	1650 5550 1450 5550
Text Label 1500 5450 0    60   ~ 0
SCL
Text Label 1500 5550 0    60   ~ 0
SDA
$Comp
L LCD16X2 DS1
U 1 1 56D326FB
P 3750 2450
F 0 "DS1" H 2950 2850 50  0000 C CNN
F 1 "LCD16X2" H 4450 2850 50  0000 C CNN
F 2 "WC1602A" H 3750 2400 50  0000 C CIN
F 3 "" H 3750 2450 50  0000 C CNN
	1    3750 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 5150 4450 5150
Wire Wire Line
	5350 5250 4450 5250
Wire Wire Line
	5300 5350 4450 5350
Wire Wire Line
	5250 5450 4450 5450
Wire Wire Line
	3900 2950 3900 4150
Wire Wire Line
	3900 4150 5200 4150
Wire Wire Line
	5200 4150 5200 5550
Wire Wire Line
	5200 5550 4450 5550
Wire Wire Line
	3800 2950 3800 4200
Wire Wire Line
	3800 4200 5150 4200
Wire Wire Line
	5150 4200 5150 5650
Wire Wire Line
	5150 5650 4450 5650
Wire Wire Line
	3700 2950 3700 4250
Wire Wire Line
	3700 4250 5100 4250
Wire Wire Line
	5100 4250 5100 5750
Wire Wire Line
	5100 5750 4450 5750
Wire Wire Line
	3600 2950 3600 4350
Wire Wire Line
	3600 4350 5050 4350
Wire Wire Line
	5050 4350 5050 5850
Wire Wire Line
	5050 5850 4450 5850
Text Label 4600 5850 0    60   ~ 0
D0
Text Label 4600 5750 0    60   ~ 0
D1
Text Label 4600 5650 0    60   ~ 0
D2
Text Label 4600 5550 0    60   ~ 0
D3
Text Label 4600 5450 0    60   ~ 0
D4
Text Label 4600 5350 0    60   ~ 0
D5
Text Label 4600 5250 0    60   ~ 0
D6
Text Label 4600 5150 0    60   ~ 0
D7
Wire Wire Line
	4400 4400 4950 4400
Wire Wire Line
	4950 4400 4950 5050
Wire Wire Line
	4950 5050 4450 5050
$Comp
L MCP23017_QFN28 U1
U 1 1 56D36D3C
P 3850 5250
F 0 "U1" H 3700 5900 60  0000 C CNN
F 1 "MCP23017_QFN28" H 3950 4200 60  0000 C CNN
F 2 "PIC24 USB:QFN28_6x6mm" H 3850 5800 60  0000 C CNN
F 3 "" H 3850 5800 60  0000 C CNN
	1    3850 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4450 4900 4450
Wire Wire Line
	4900 4450 4900 4950
Wire Wire Line
	4900 4950 4450 4950
Wire Wire Line
	3300 2950 3300 4550
Wire Wire Line
	3300 4550 4850 4550
Wire Wire Line
	4850 4550 4850 4850
Wire Wire Line
	4850 4850 4450 4850
Text Label 4500 5050 0    60   ~ 0
LCD_BL
$EndSCHEMATC
