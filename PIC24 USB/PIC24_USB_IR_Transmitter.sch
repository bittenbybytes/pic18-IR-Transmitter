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
LIBS:PIC24_USB_IR_Transmitter-cache
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date "3 aug 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L USB-MINI-B CON1
U 1 1 52D43B15
P 1450 3150
F 0 "CON1" H 1200 3600 60  0000 C CNN
F 1 "USB-MINI-B" H 1400 2650 60  0000 C CNN
F 2 "Connect:USB_MINI_B" H 1450 3150 60  0001 C CNN
F 3 "" H 1450 3150 60  0000 C CNN
	1    1450 3150
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 52D43B2E
P 850 3650
F 0 "#PWR01" H 850 3650 30  0001 C CNN
F 1 "GND" H 850 3580 30  0001 C CNN
F 2 "" H 850 3650 60  0000 C CNN
F 3 "" H 850 3650 60  0000 C CNN
	1    850  3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  2850 850  3650
Wire Wire Line
	850  2850 900  2850
Wire Wire Line
	900  3000 850  3000
Connection ~ 850  3000
Wire Wire Line
	900  3300 850  3300
Connection ~ 850  3300
Wire Wire Line
	900  3450 850  3450
Connection ~ 850  3450
$Comp
L GND #PWR02
U 1 1 52D43B6B
P 2100 3650
F 0 "#PWR02" H 2100 3650 30  0001 C CNN
F 1 "GND" H 2100 3580 30  0001 C CNN
F 2 "" H 2100 3650 60  0000 C CNN
F 3 "" H 2100 3650 60  0000 C CNN
	1    2100 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3450 2100 3450
Wire Wire Line
	2100 3450 2100 3650
Wire Wire Line
	2000 2850 2150 2850
Wire Wire Line
	2150 2850 2150 2650
$Comp
L +5V #PWR03
U 1 1 52D43B8D
P 2150 2650
F 0 "#PWR03" H 2150 2740 20  0001 C CNN
F 1 "+5V" H 2150 2740 30  0000 C CNN
F 2 "" H 2150 2650 60  0000 C CNN
F 3 "" H 2150 2650 60  0000 C CNN
	1    2150 2650
	1    0    0    -1  
$EndComp
$Comp
L CP C1
U 1 1 52D43BC9
P 1250 1850
F 0 "C1" H 1300 1950 40  0000 L CNN
F 1 "47uF" H 1300 1750 40  0000 L CNN
F 2 "c_tant_B" H 1350 1700 30  0001 C CNN
F 3 "" H 1250 1850 300 0000 C CNN
	1    1250 1850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 52D43BD6
P 1250 1550
F 0 "#PWR04" H 1250 1640 20  0001 C CNN
F 1 "+5V" H 1250 1640 30  0000 C CNN
F 2 "" H 1250 1550 60  0000 C CNN
F 3 "" H 1250 1550 60  0000 C CNN
	1    1250 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 52D43BDC
P 1250 2150
F 0 "#PWR05" H 1250 2150 30  0001 C CNN
F 1 "GND" H 1250 2080 30  0001 C CNN
F 2 "" H 1250 2150 60  0000 C CNN
F 3 "" H 1250 2150 60  0000 C CNN
	1    1250 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 1550 1250 1650
Wire Wire Line
	1250 2050 1250 2150
Wire Wire Line
	2000 3000 2250 3000
Wire Wire Line
	2000 3150 2250 3150
Text Label 2150 3150 0    60   ~ 0
D+
Text Label 2150 3000 0    60   ~ 0
D-
Text GLabel 2250 3000 2    60   BiDi ~ 0
D-
Text GLabel 2250 3150 2    60   BiDi ~ 0
D+
Wire Wire Line
	8050 5300 9600 5300
Wire Wire Line
	9600 5300 9600 5100
Wire Wire Line
	8050 5400 9600 5400
Wire Wire Line
	9600 5400 9600 5600
Wire Wire Line
	4750 4600 5150 4600
Wire Wire Line
	4750 4100 5150 4100
$Comp
L C C2
U 1 1 52D44076
P 4950 4350
F 0 "C2" H 4950 4450 40  0000 L CNN
F 1 "100n" H 4956 4265 40  0000 L CNN
F 2 "Capacitors_SMD:c_0603" H 4988 4200 30  0001 C CNN
F 3 "" H 4950 4350 60  0000 C CNN
	1    4950 4350
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 52D44088
P 9750 5350
F 0 "C6" H 9750 5450 40  0000 L CNN
F 1 "100n" H 9756 5265 40  0000 L CNN
F 2 "Capacitors_SMD:c_0603" H 9788 5200 30  0001 C CNN
F 3 "" H 9750 5350 60  0000 C CNN
	1    9750 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4600 4950 4550
Wire Wire Line
	4950 4100 4950 4150
Wire Wire Line
	9600 5100 10000 5100
Wire Wire Line
	9750 5100 9750 5150
Wire Wire Line
	9600 5600 10000 5600
Wire Wire Line
	9750 5600 9750 5550
Wire Wire Line
	5550 4300 5150 4300
Wire Wire Line
	5150 4300 5150 4100
Wire Wire Line
	5550 4400 5150 4400
Wire Wire Line
	5150 4400 5150 4600
$Comp
L GND #PWR06
U 1 1 52D44BA2
P 4750 4200
F 0 "#PWR06" H 4750 4200 30  0001 C CNN
F 1 "GND" H 4750 4130 30  0001 C CNN
F 2 "" H 4750 4200 60  0000 C CNN
F 3 "" H 4750 4200 60  0000 C CNN
	1    4750 4200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 52D44BB1
P 4750 4550
F 0 "#PWR07" H 4750 4640 20  0001 C CNN
F 1 "+5V" H 4750 4640 30  0000 C CNN
F 2 "" H 4750 4550 60  0000 C CNN
F 3 "" H 4750 4550 60  0000 C CNN
	1    4750 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4600 4750 4550
Connection ~ 4950 4600
Wire Wire Line
	4750 4200 4750 4100
Connection ~ 4950 4100
$Comp
L GND #PWR08
U 1 1 52D44CD9
P 10000 5200
F 0 "#PWR08" H 10000 5200 30  0001 C CNN
F 1 "GND" H 10000 5130 30  0001 C CNN
F 2 "" H 10000 5200 60  0000 C CNN
F 3 "" H 10000 5200 60  0000 C CNN
	1    10000 5200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR09
U 1 1 52D44CDF
P 10000 5500
F 0 "#PWR09" H 10000 5590 20  0001 C CNN
F 1 "+5V" H 10000 5590 30  0000 C CNN
F 2 "" H 10000 5500 60  0000 C CNN
F 3 "" H 10000 5500 60  0000 C CNN
	1    10000 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 5600 10000 5500
Connection ~ 9750 5600
Wire Wire Line
	10000 5100 10000 5200
Connection ~ 9750 5100
Wire Wire Line
	8050 3900 8200 3900
Wire Wire Line
	8050 4000 8200 4000
Text GLabel 8200 3900 2    60   BiDi ~ 0
D+
Text GLabel 8200 4000 2    60   BiDi ~ 0
D-
Wire Wire Line
	8050 4500 9600 4500
$Comp
L C C5
U 1 1 52D44DE2
P 9600 4750
F 0 "C5" H 9600 4850 40  0000 L CNN
F 1 "100n" H 9606 4665 40  0000 L CNN
F 2 "Capacitors_SMD:c_0603" H 9638 4600 30  0001 C CNN
F 3 "" H 9600 4750 60  0000 C CNN
	1    9600 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 4500 9600 4550
$Comp
L GND #PWR010
U 1 1 52D44E23
P 9600 5000
F 0 "#PWR010" H 9600 5000 30  0001 C CNN
F 1 "GND" H 9600 4930 30  0001 C CNN
F 2 "" H 9600 5000 60  0000 C CNN
F 3 "" H 9600 5000 60  0000 C CNN
	1    9600 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 4950 9600 5000
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
L GND #PWR011
U 1 1 52D450A4
P 2450 5900
F 0 "#PWR011" H 2450 5900 30  0001 C CNN
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
Text GLabel 5400 5300 0    60   BiDi ~ 0
PGD
Text GLabel 5400 5400 0    60   BiDi ~ 0
PGC
Wire Wire Line
	5400 5400 5550 5400
Wire Wire Line
	5400 5300 5550 5300
Text GLabel 5350 1250 0    60   Input ~ 0
~MCLR~
Text GLabel 7150 4300 2    60   Input ~ 0
P1A
Text GLabel 7150 4400 2    60   Output ~ 0
IR_LED
Text GLabel 8200 2000 0    60   Input ~ 0
IR_LED
$Comp
L GND #PWR012
U 1 1 52D45877
P 9050 2300
F 0 "#PWR012" H 9050 2300 30  0001 C CNN
F 1 "GND" H 9050 2230 30  0001 C CNN
F 2 "" H 9050 2300 60  0000 C CNN
F 3 "" H 9050 2300 60  0000 C CNN
	1    9050 2300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR013
U 1 1 52D45886
P 9050 750
F 0 "#PWR013" H 9050 840 20  0001 C CNN
F 1 "+5V" H 9050 840 30  0000 C CNN
F 2 "" H 9050 750 60  0000 C CNN
F 3 "" H 9050 750 60  0000 C CNN
	1    9050 750 
	1    0    0    -1  
$EndComp
$Comp
L MOS_N Q1
U 1 1 52D4589F
P 8950 2000
F 0 "Q1" H 8960 2170 60  0000 R CNN
F 1 "2N7002" H 8960 1850 60  0000 R CNN
F 2 "Transistors_SMD:sot23" H 8950 2000 60  0001 C CNN
F 3 "" H 8950 2000 60  0000 C CNN
	1    8950 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 2200 9050 2300
Wire Wire Line
	8200 2000 8750 2000
$Comp
L R R4
U 1 1 52D4596A
P 9050 1050
F 0 "R4" V 9130 1050 40  0000 C CNN
F 1 "100R" V 9057 1051 40  0000 C CNN
F 2 "SMD_Packages:SM1206" V 8980 1050 30  0001 C CNN
F 3 "" H 9050 1050 30  0000 C CNN
	1    9050 1050
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 52D45985
P 9050 1550
F 0 "D3" H 9050 1650 50  0000 C CNN
F 1 "IR_LED" H 9050 1450 50  0000 C CNN
F 2 "LEDs:LED-3MM" H 9050 1550 60  0001 C CNN
F 3 "" H 9050 1550 60  0000 C CNN
	1    9050 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	9050 1800 9050 1750
Wire Wire Line
	9050 1350 9050 1300
Wire Wire Line
	9050 800  9050 750 
Text GLabel 5450 4000 0    60   Output ~ 0
P1B
Text GLabel 5450 4100 0    60   Output ~ 0
P1C
Text GLabel 5450 4200 0    60   Output ~ 0
P1D
Text GLabel 5250 1900 0    60   BiDi ~ 0
SDA
Text GLabel 5250 1750 0    60   BiDi ~ 0
SCL
Wire Wire Line
	5250 1900 5550 1900
Wire Wire Line
	5250 1750 5550 1750
$Comp
L CONN_6 P3
U 1 1 52D45B33
P 3850 3600
F 0 "P3" V 3800 3600 60  0000 C CNN
F 1 "CONN_6" V 3900 3600 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06" H 3850 3600 60  0001 C CNN
F 3 "" H 3850 3600 60  0000 C CNN
	1    3850 3600
	-1   0    0    1   
$EndComp
Text Notes 3800 3250 0    60   ~ 0
PWM
$Comp
L GND #PWR014
U 1 1 52D45B51
P 4300 3950
F 0 "#PWR014" H 4300 3950 30  0001 C CNN
F 1 "GND" H 4300 3880 30  0001 C CNN
F 2 "" H 4300 3950 60  0000 C CNN
F 3 "" H 4300 3950 60  0000 C CNN
	1    4300 3950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR015
U 1 1 52D45B57
P 4350 3300
F 0 "#PWR015" H 4350 3390 20  0001 C CNN
F 1 "+5V" H 4350 3390 30  0000 C CNN
F 2 "" H 4350 3300 60  0000 C CNN
F 3 "" H 4350 3300 60  0000 C CNN
	1    4350 3300
	1    0    0    -1  
$EndComp
Text GLabel 4450 3450 2    60   Input ~ 0
P1A
Text GLabel 4450 3550 2    60   Input ~ 0
P1B
Text GLabel 4450 3650 2    60   Input ~ 0
P1C
Text GLabel 4450 3750 2    60   Input ~ 0
P1D
Wire Wire Line
	4200 3850 4300 3850
Wire Wire Line
	4300 3850 4300 3950
Wire Wire Line
	4200 3350 4350 3350
Wire Wire Line
	4350 3350 4350 3300
Wire Wire Line
	4200 3450 4450 3450
Wire Wire Line
	4200 3550 4450 3550
Wire Wire Line
	4200 3650 4450 3650
Wire Wire Line
	4200 3750 4450 3750
$Comp
L R R3
U 1 1 52D45E25
P 4450 5450
F 0 "R3" V 4530 5450 40  0000 C CNN
F 1 "330R" V 4457 5451 40  0000 C CNN
F 2 "SMD_Packages:SM0603_Resistor" V 4380 5450 30  0001 C CNN
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
	5550 5100 4450 5100
Wire Wire Line
	4450 5100 4450 5200
$Comp
L GND #PWR016
U 1 1 52D45E92
P 4450 6200
F 0 "#PWR016" H 4450 6200 30  0001 C CNN
F 1 "GND" H 4450 6130 30  0001 C CNN
F 2 "" H 4450 6200 60  0000 C CNN
F 3 "" H 4450 6200 60  0000 C CNN
	1    4450 6200
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 52D45EB1
P 1700 1700
F 0 "R1" V 1780 1700 40  0000 C CNN
F 1 "330R" V 1707 1701 40  0000 C CNN
F 2 "SMD_Packages:SM0603_Resistor" V 1630 1700 30  0001 C CNN
F 3 "" H 1700 1700 30  0000 C CNN
	1    1700 1700
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 52D45EB7
P 1700 2200
F 0 "D1" H 1700 2300 50  0000 C CNN
F 1 "POWER_LED" H 1700 2100 50  0000 C CNN
F 2 "LEDs:LED-0603" H 1700 2200 60  0001 C CNN
F 3 "" H 1700 2200 60  0000 C CNN
	1    1700 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	1700 2450 1700 2400
Wire Wire Line
	1700 2000 1700 1950
Wire Wire Line
	1700 1350 1700 1450
$Comp
L GND #PWR017
U 1 1 52D45EC1
P 1700 2450
F 0 "#PWR017" H 1700 2450 30  0001 C CNN
F 1 "GND" H 1700 2380 30  0001 C CNN
F 2 "" H 1700 2450 60  0000 C CNN
F 3 "" H 1700 2450 60  0000 C CNN
	1    1700 2450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR018
U 1 1 52D45EC7
P 1700 1350
F 0 "#PWR018" H 1700 1440 20  0001 C CNN
F 1 "+5V" H 1700 1440 30  0000 C CNN
F 2 "" H 1700 1350 60  0000 C CNN
F 3 "" H 1700 1350 60  0000 C CNN
	1    1700 1350
	1    0    0    -1  
$EndComp
$Comp
L CONN_6 P4
U 1 1 52D45EDE
P 4650 6700
F 0 "P4" V 4600 6700 60  0000 C CNN
F 1 "CONN_6" V 4700 6700 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06" H 4650 6700 60  0001 C CNN
F 3 "" H 4650 6700 60  0000 C CNN
	1    4650 6700
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR019
U 1 1 52D45EFD
P 5150 7050
F 0 "#PWR019" H 5150 7050 30  0001 C CNN
F 1 "GND" H 5150 6980 30  0001 C CNN
F 2 "" H 5150 7050 60  0000 C CNN
F 3 "" H 5150 7050 60  0000 C CNN
	1    5150 7050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR020
U 1 1 52D45F03
P 5150 6350
F 0 "#PWR020" H 5150 6440 20  0001 C CNN
F 1 "+5V" H 5150 6440 30  0000 C CNN
F 2 "" H 5150 6350 60  0000 C CNN
F 3 "" H 5150 6350 60  0000 C CNN
	1    5150 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 6950 5150 6950
Wire Wire Line
	5150 6950 5150 7050
Wire Wire Line
	5000 6450 5150 6450
Wire Wire Line
	5150 6450 5150 6350
Wire Wire Line
	5550 5600 5300 5600
Wire Wire Line
	5300 5600 5300 6550
Wire Wire Line
	5300 6550 5000 6550
Wire Wire Line
	5000 6650 5350 6650
Wire Wire Line
	5350 6650 5350 5700
Wire Wire Line
	5350 5700 5550 5700
Wire Wire Line
	5400 5800 5550 5800
Wire Wire Line
	5400 5800 5400 6750
Wire Wire Line
	5400 6750 5000 6750
Wire Wire Line
	5000 6850 5450 6850
Wire Wire Line
	5450 6850 5450 5900
Wire Wire Line
	5450 5900 5550 5900
Wire Wire Line
	8150 3300 8450 3300
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
L GND #PWR021
U 1 1 52D4649C
P 8350 3450
F 0 "#PWR021" H 8350 3450 30  0001 C CNN
F 1 "GND" H 8350 3380 30  0001 C CNN
F 2 "" H 8350 3450 60  0000 C CNN
F 3 "" H 8350 3450 60  0000 C CNN
	1    8350 3450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR022
U 1 1 52D464A2
P 8350 3050
F 0 "#PWR022" H 8350 3140 20  0001 C CNN
F 1 "+5V" H 8350 3140 30  0000 C CNN
F 2 "" H 8350 3050 60  0000 C CNN
F 3 "" H 8350 3050 60  0000 C CNN
	1    8350 3050
	1    0    0    -1  
$EndComp
Text Notes 4550 6350 0    60   ~ 0
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
L GND #PWR023
U 1 1 52D464B4
P 3700 5050
F 0 "#PWR023" H 3700 5050 30  0001 C CNN
F 1 "GND" H 3700 4980 30  0001 C CNN
F 2 "" H 3700 5050 60  0000 C CNN
F 3 "" H 3700 5050 60  0000 C CNN
	1    3700 5050
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR024
U 1 1 52D464BA
P 3700 4650
F 0 "#PWR024" H 3700 4740 20  0001 C CNN
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
F 2 "Connect:PINHEAD1-6" H 1450 5700 60  0001 C CNN
F 3 "" H 1450 5700 60  0000 C CNN
	1    1450 5700
	-1   0    0    -1  
$EndComp
Text Notes 1350 5350 0    60   ~ 0
ICSP
Wire Wire Line
	5450 4200 5550 4200
Wire Wire Line
	5450 4100 5550 4100
Wire Wire Line
	5450 4000 5550 4000
$Comp
L +5V #PWR025
U 1 1 52D469A9
P 3800 4200
F 0 "#PWR025" H 3800 4290 20  0001 C CNN
F 1 "+5V" H 3800 4290 30  0000 C CNN
F 2 "" H 3800 4200 60  0000 C CNN
F 3 "" H 3800 4200 60  0000 C CNN
	1    3800 4200
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR026
U 1 1 52D469AF
P 3950 4200
F 0 "#PWR026" H 3950 4290 20  0001 C CNN
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
F 2 "SMD_Packages:SM0603_Resistor" V 3730 4500 30  0001 C CNN
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
F 2 "SMD_Packages:SM0603_Resistor" V 3880 4500 30  0001 C CNN
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
Text Label 5100 6550 0    60   ~ 0
AN0
Text Label 5100 6650 0    60   ~ 0
AN1
Text Label 5100 6750 0    60   ~ 0
AN2
Text Label 5100 6850 0    60   ~ 0
AN3
Wire Wire Line
	7050 4300 7150 4300
Wire Wire Line
	7050 4400 7150 4400
NoConn ~ 2000 3300
NoConn ~ 1800 5950
Text Label 4800 5100 0    60   ~ 0
USER_LED
$Comp
L CONN_1 P6
U 1 1 52D65590
P 9600 4350
F 0 "P6" H 9680 4350 40  0000 L CNN
F 1 "CONN_1" H 9600 4405 30  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01" H 9600 4350 60  0001 C CNN
F 3 "" H 9600 4350 60  0000 C CNN
	1    9600 4350
	0    -1   -1   0   
$EndComp
Text Label 8600 4500 0    60   ~ 0
VUSB
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
L GND #PWR027
U 1 1 52D8FECF
P 2000 7250
F 0 "#PWR027" H 2000 7250 30  0001 C CNN
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
L +5V #PWR028
U 1 1 52D8FF66
P 2000 6350
F 0 "#PWR028" H 2000 6440 20  0001 C CNN
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
Text GLabel 5050 4700 0    60   Input ~ 0
~LCD_RESET~
Wire Wire Line
	5550 4700 5050 4700
Wire Wire Line
	3600 4800 4100 4800
Wire Wire Line
	3600 4900 4100 4900
Wire Wire Line
	8450 3200 8150 3200
$Sheet
S 5550 1000 2000 2600
U 53DA26B9
F0 "MCUSection" 50
F1 "MCU.sch" 50
F2 "~MCLR" I L 5550 1250 60 
F3 "SCL" B L 5550 1750 60 
F4 "SDA" B L 5550 1900 60 
F5 "RE[0..7]" B L 5550 2150 60 
F6 "PGEC" I L 5550 2400 60 
F7 "PGED" B L 5550 2500 60 
$EndSheet
Wire Wire Line
	5550 1250 5350 1250
$Comp
L LM317_SOT223 U2
U 1 1 53DC072C
P 2650 1500
F 0 "U2" H 2650 1800 60  0000 C CNN
F 1 "LM1117_SOT223_3V3" H 2700 1250 60  0000 L CNN
F 2 "SMD_Packages:SOT223" H 2650 1500 60  0000 C CNN
F 3 "~" H 2650 1500 60  0000 C CNN
	1    2650 1500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR029
U 1 1 53DC073B
P 2150 1200
F 0 "#PWR029" H 2150 1290 20  0001 C CNN
F 1 "+5V" H 2150 1290 30  0000 C CNN
F 2 "" H 2150 1200 60  0000 C CNN
F 3 "" H 2150 1200 60  0000 C CNN
	1    2150 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1350 2150 1350
Wire Wire Line
	2150 1350 2150 1200
Wire Wire Line
	3050 1350 3250 1350
Wire Wire Line
	3250 1350 3250 1250
$Comp
L +3,3V #PWR030
U 1 1 53DC0908
P 3250 1250
F 0 "#PWR030" H 3250 1210 30  0001 C CNN
F 1 "+3,3V" H 3250 1360 30  0000 C CNN
F 2 "" H 3250 1250 60  0000 C CNN
F 3 "" H 3250 1250 60  0000 C CNN
	1    3250 1250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR031
U 1 1 53DC0948
P 2650 1950
F 0 "#PWR031" H 2650 1950 30  0001 C CNN
F 1 "GND" H 2650 1880 30  0001 C CNN
F 2 "" H 2650 1950 60  0000 C CNN
F 3 "" H 2650 1950 60  0000 C CNN
	1    2650 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1850 2650 1950
$Comp
L GND #PWR032
U 1 1 53DC0A13
P 3200 1950
F 0 "#PWR032" H 3200 1950 30  0001 C CNN
F 1 "GND" H 3200 1880 30  0001 C CNN
F 2 "" H 3200 1950 60  0000 C CNN
F 3 "" H 3200 1950 60  0000 C CNN
	1    3200 1950
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 53DC0A22
P 3200 1600
F 0 "C13" H 3200 1700 40  0000 L CNN
F 1 "10u" H 3206 1515 40  0000 L CNN
F 2 "Capacitors_SMD:c_1206" H 3238 1450 30  0000 C CNN
F 3 "~" H 3200 1600 60  0000 C CNN
	1    3200 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1400 3200 1350
Connection ~ 3200 1350
Wire Wire Line
	3200 1800 3200 1950
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
L +3,3V #PWR033
U 1 1 53DEBDEC
P 1900 4850
F 0 "#PWR033" H 1900 4810 30  0001 C CNN
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
$EndSCHEMATC
