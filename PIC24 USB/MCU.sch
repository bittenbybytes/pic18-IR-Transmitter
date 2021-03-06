EESchema Schematic File Version 2
LIBS:PIC24_USB_IR_Transmitter-rescue
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
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date "3 aug 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 850  2900 0    60   Input ~ 0
~MCLR
$Comp
L GND-RESCUE-PIC24_USB_IR_Transmitter #PWR048
U 1 1 53DA26E1
P 1750 3500
F 0 "#PWR048" H 1750 3500 30  0001 C CNN
F 1 "GND" H 1750 3430 30  0001 C CNN
F 2 "" H 1750 3500 60  0000 C CNN
F 3 "" H 1750 3500 60  0000 C CNN
	1    1750 3500
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-PIC24_USB_IR_Transmitter #PWR049
U 1 1 53DA26EE
P 2200 5150
F 0 "#PWR049" H 2200 5150 30  0001 C CNN
F 1 "GND" H 2200 5080 30  0001 C CNN
F 2 "" H 2200 5150 60  0000 C CNN
F 3 "" H 2200 5150 60  0000 C CNN
	1    2200 5150
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-PIC24_USB_IR_Transmitter #PWR050
U 1 1 53DA26F4
P 8050 3300
F 0 "#PWR050" H 8050 3300 30  0001 C CNN
F 1 "GND" H 8050 3230 30  0001 C CNN
F 2 "" H 8050 3300 60  0000 C CNN
F 3 "" H 8050 3300 60  0000 C CNN
	1    8050 3300
	1    0    0    -1  
$EndComp
$Comp
L +3,3V #PWR051
U 1 1 53DA2840
P 8050 2650
F 0 "#PWR051" H 8050 2610 30  0001 C CNN
F 1 "+3,3V" H 8050 2760 30  0000 C CNN
F 2 "" H 8050 2650 60  0000 C CNN
F 3 "" H 8050 2650 60  0000 C CNN
	1    8050 2650
	1    0    0    -1  
$EndComp
$Comp
L +3,3V #PWR052
U 1 1 53DA284D
P 1750 2800
F 0 "#PWR052" H 1750 2760 30  0001 C CNN
F 1 "+3,3V" H 1750 2910 30  0000 C CNN
F 2 "" H 1750 2800 60  0000 C CNN
F 3 "" H 1750 2800 60  0000 C CNN
	1    1750 2800
	1    0    0    -1  
$EndComp
$Comp
L +3,3V #PWR053
U 1 1 53DA2853
P 2200 4550
F 0 "#PWR053" H 2200 4510 30  0001 C CNN
F 1 "+3,3V" H 2200 4660 30  0000 C CNN
F 2 "" H 2200 4550 60  0000 C CNN
F 3 "" H 2200 4550 60  0000 C CNN
	1    2200 4550
	1    0    0    -1  
$EndComp
$Comp
L +3,3V #PWR054
U 1 1 53DA2865
P 1450 3850
F 0 "#PWR054" H 1450 3810 30  0001 C CNN
F 1 "+3,3V" H 1450 3960 30  0000 C CNN
F 2 "" H 1450 3850 60  0000 C CNN
F 3 "" H 1450 3850 60  0000 C CNN
	1    1450 3850
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 53DA32F3
P 8700 2950
F 0 "X1" H 8700 3100 60  0000 C CNN
F 1 "CRYSTAL_12MHZ" H 8700 2800 60  0000 C CNN
F 2 "Crystals_Oscillators_SMD:Q_49U3HMS" H 8700 2950 60  0000 C CNN
F 3 "~" H 8700 2950 60  0000 C CNN
	1    8700 2950
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C9
U 1 1 53DA330C
P 9050 2650
AR Path="/53DA330C" Ref="C9"  Part="1" 
AR Path="/53DA26B9/53DA330C" Ref="C9"  Part="1" 
F 0 "C9" H 9050 2750 40  0000 L CNN
F 1 "22p" H 9056 2565 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 9088 2500 30  0000 C CNN
F 3 "~" H 9050 2650 60  0000 C CNN
	1    9050 2650
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C10
U 1 1 53DA3319
P 9050 3250
AR Path="/53DA3319" Ref="C10"  Part="1" 
AR Path="/53DA26B9/53DA3319" Ref="C10"  Part="1" 
F 0 "C10" H 9050 3350 40  0000 L CNN
F 1 "22p" H 9056 3165 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 9088 3100 30  0000 C CNN
F 3 "~" H 9050 3250 60  0000 C CNN
	1    9050 3250
	0    -1   -1   0   
$EndComp
$Comp
L GND-RESCUE-PIC24_USB_IR_Transmitter #PWR055
U 1 1 53DA331F
P 9550 3050
F 0 "#PWR055" H 9550 3050 30  0001 C CNN
F 1 "GND" H 9550 2980 30  0001 C CNN
F 2 "" H 9550 3050 60  0000 C CNN
F 3 "" H 9550 3050 60  0000 C CNN
	1    9550 3050
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C3
U 1 1 53DA3435
P 1450 4150
AR Path="/53DA3435" Ref="C3"  Part="1" 
AR Path="/53DA26B9/53DA3435" Ref="C3"  Part="1" 
F 0 "C3" H 1450 4250 40  0000 L CNN
F 1 "100n" H 1456 4065 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 1488 4000 30  0000 C CNN
F 3 "~" H 1450 4150 60  0000 C CNN
	1    1450 4150
	-1   0    0    1   
$EndComp
$Comp
L GND-RESCUE-PIC24_USB_IR_Transmitter #PWR056
U 1 1 53DA3460
P 1450 4450
F 0 "#PWR056" H 1450 4450 30  0001 C CNN
F 1 "GND" H 1450 4380 30  0001 C CNN
F 2 "" H 1450 4450 60  0000 C CNN
F 3 "" H 1450 4450 60  0000 C CNN
	1    1450 4450
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C4
U 1 1 53DA3506
P 2200 4850
AR Path="/53DA3506" Ref="C4"  Part="1" 
AR Path="/53DA26B9/53DA3506" Ref="C4"  Part="1" 
F 0 "C4" H 2200 4950 40  0000 L CNN
F 1 "100n" H 2206 4765 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 2238 4700 30  0000 C CNN
F 3 "~" H 2200 4850 60  0000 C CNN
	1    2200 4850
	-1   0    0    1   
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C7
U 1 1 53DA35D7
P 1750 3200
AR Path="/53DA35D7" Ref="C7"  Part="1" 
AR Path="/53DA26B9/53DA35D7" Ref="C7"  Part="1" 
F 0 "C7" H 1750 3300 40  0000 L CNN
F 1 "100n" H 1756 3115 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 1788 3050 30  0000 C CNN
F 3 "~" H 1750 3200 60  0000 C CNN
	1    1750 3200
	-1   0    0    1   
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C8
U 1 1 53DA3748
P 8050 2950
AR Path="/53DA3748" Ref="C8"  Part="1" 
AR Path="/53DA26B9/53DA3748" Ref="C8"  Part="1" 
F 0 "C8" H 8050 3050 40  0000 L CNN
F 1 "100n" H 8056 2865 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 8088 2800 30  0000 C CNN
F 3 "~" H 8050 2950 60  0000 C CNN
	1    8050 2950
	-1   0    0    1   
$EndComp
Text HLabel 3300 5400 0    60   BiDi ~ 0
SCL
Text HLabel 3300 5300 0    60   BiDi ~ 0
SDA
Entry Wire Line
	9950 5400 10050 5500
Entry Wire Line
	9950 5300 10050 5400
Entry Wire Line
	9950 5200 10050 5300
Entry Wire Line
	9950 5100 10050 5200
Entry Wire Line
	9950 5000 10050 5100
Entry Wire Line
	2550 2200 2650 2300
Entry Wire Line
	2550 2300 2650 2400
Entry Wire Line
	2550 2400 2650 2500
Text Label 3200 2300 2    60   ~ 0
RE5
Text Label 3200 2400 2    60   ~ 0
RE6
Text Label 3200 2500 2    60   ~ 0
RE7
Text HLabel 10150 1650 2    60   BiDi ~ 0
RE[0..7]
Text Label 7550 5000 2    60   ~ 0
RE0
Text Label 7550 5100 2    60   ~ 0
RE1
Text Label 7550 5200 2    60   ~ 0
RE2
Text Label 7550 5300 2    60   ~ 0
RE3
Text Label 7550 5400 2    60   ~ 0
RE4
$Comp
L +3,3V #PWR057
U 1 1 53DBFFDE
P 8550 4550
F 0 "#PWR057" H 8550 4510 30  0001 C CNN
F 1 "+3,3V" H 8550 4660 30  0000 C CNN
F 2 "" H 8550 4550 60  0000 C CNN
F 3 "" H 8550 4550 60  0000 C CNN
	1    8550 4550
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C12
U 1 1 53DC00CE
P 8350 4700
AR Path="/53DC00CE" Ref="C12"  Part="1" 
AR Path="/53DA26B9/53DC00CE" Ref="C12"  Part="1" 
F 0 "C12" H 8350 4800 40  0000 L CNN
F 1 "10u" H 8356 4615 40  0000 L CNN
F 2 "Capacitors_SMD:c_1206" H 8388 4550 30  0000 C CNN
F 3 "~" H 8350 4700 60  0000 C CNN
	1    8350 4700
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-PIC24_USB_IR_Transmitter #PWR058
U 1 1 53DC0153
P 8350 4950
F 0 "#PWR058" H 8350 4950 30  0001 C CNN
F 1 "GND" H 8350 4880 30  0001 C CNN
F 2 "" H 8350 4950 60  0000 C CNN
F 3 "" H 8350 4950 60  0000 C CNN
	1    8350 4950
	1    0    0    -1  
$EndComp
$Comp
L PIC24FJXXXGB106 U1
U 1 1 53DA2811
P 4550 2100
F 0 "U1" H 4000 2050 60  0000 C CNN
F 1 "PIC24FJXXXGB106" H 5150 -1400 60  0000 C CNN
F 2 "SMD_Packages:TQFP_64" H 4550 2100 60  0000 C CNN
F 3 "~" H 4550 2100 60  0000 C CNN
	1    4550 2100
	1    0    0    -1  
$EndComp
Text HLabel 3450 3900 0    60   Input ~ 0
PGEC
Text HLabel 3450 4000 0    60   BiDi ~ 0
PGED
$Comp
L R-RESCUE-PIC24_USB_IR_Transmitter R7
U 1 1 53DEB244
P 1350 2900
F 0 "R7" V 1430 2900 40  0000 C CNN
F 1 "100R" V 1357 2901 40  0000 C CNN
F 2 "SMD_Packages:SMD-0603_r" V 1280 2900 30  0000 C CNN
F 3 "~" H 1350 2900 30  0000 C CNN
	1    1350 2900
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-PIC24_USB_IR_Transmitter R2
U 1 1 53DEB251
P 1000 2550
F 0 "R2" V 1080 2550 40  0000 C CNN
F 1 "10k" V 1007 2551 40  0000 C CNN
F 2 "SMD_Packages:SMD-0603_r" V 930 2550 30  0000 C CNN
F 3 "~" H 1000 2550 30  0000 C CNN
	1    1000 2550
	-1   0    0    1   
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C11
U 1 1 53DEB257
P 1000 3200
AR Path="/53DEB257" Ref="C11"  Part="1" 
AR Path="/53DA26B9/53DEB257" Ref="C11"  Part="1" 
F 0 "C11" H 1000 3300 40  0000 L CNN
F 1 "100n" H 1006 3115 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 1038 3050 30  0000 C CNN
F 3 "~" H 1000 3200 60  0000 C CNN
	1    1000 3200
	-1   0    0    1   
$EndComp
$Comp
L GND-RESCUE-PIC24_USB_IR_Transmitter #PWR059
U 1 1 53DEB25D
P 1000 3500
F 0 "#PWR059" H 1000 3500 30  0001 C CNN
F 1 "GND" H 1000 3430 30  0001 C CNN
F 2 "" H 1000 3500 60  0000 C CNN
F 3 "" H 1000 3500 60  0000 C CNN
	1    1000 3500
	1    0    0    -1  
$EndComp
$Comp
L +3,3V #PWR060
U 1 1 53DEB263
P 1000 2200
F 0 "#PWR060" H 1000 2160 30  0001 C CNN
F 1 "+3,3V" H 1000 2310 30  0000 C CNN
F 2 "" H 1000 2200 60  0000 C CNN
F 3 "" H 1000 2200 60  0000 C CNN
	1    1000 2200
	1    0    0    -1  
$EndComp
Text Label 9700 1650 0    60   ~ 0
RE[0..7]
Text HLabel 7400 3600 2    60   BiDi ~ 0
PORTD0
Text HLabel 7400 3900 2    60   BiDi ~ 0
PORTD1
Text HLabel 7400 4000 2    60   BiDi ~ 0
PORTD2
Text HLabel 7400 4100 2    60   BiDi ~ 0
PORTD3
Text HLabel 7400 4200 2    60   BiDi ~ 0
PORTD4
Text HLabel 7400 4300 2    60   BiDi ~ 0
PORTD5
Text HLabel 7400 4400 2    60   BiDi ~ 0
PORTD6
Text HLabel 7400 4500 2    60   BiDi ~ 0
PORTD7
Text HLabel 7400 3200 2    60   BiDi ~ 0
PORTD8
Text HLabel 7400 3300 2    60   BiDi ~ 0
PORTD9
Text HLabel 7400 3400 2    60   BiDi ~ 0
PORTD10
Text HLabel 7400 3500 2    60   BiDi ~ 0
PORTD11
Text HLabel 2400 5250 0    60   BiDi ~ 0
AN15/RP29/RB15
Text HLabel 2000 5200 0    60   BiDi ~ 0
AN14/RP14/RB14
Text HLabel 2700 3800 0    60   BiDi ~ 0
AN0
Text HLabel 2700 3700 0    60   BiDi ~ 0
AN1
Text HLabel 2700 3600 0    60   BiDi ~ 0
AN2
Text HLabel 2700 3500 0    60   BiDi ~ 0
AN3
Text HLabel 2700 3400 0    60   BiDi ~ 0
AN4
Text HLabel 2700 3300 0    60   BiDi ~ 0
AN5
Text HLabel 2950 2600 0    60   BiDi ~ 0
RP21/RG6
Text HLabel 2950 2700 0    60   BiDi ~ 0
RP26/RG7
Text HLabel 2950 2800 0    60   BiDi ~ 0
RP19/RG8
Text HLabel 2950 3000 0    60   BiDi ~ 0
RP27/RG9
$Comp
L +5V #PWR061
U 1 1 53EB0ECB
P 8450 1800
F 0 "#PWR061" H 8450 1890 20  0001 C CNN
F 1 "+5V" H 8450 1890 30  0000 C CNN
F 2 "" H 8450 1800 60  0000 C CNN
F 3 "" H 8450 1800 60  0000 C CNN
	1    8450 1800
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-PIC24_USB_IR_Transmitter R15
U 1 1 53EB0F03
P 8450 2100
F 0 "R15" V 8530 2100 40  0000 C CNN
F 1 "100K" V 8457 2101 40  0000 C CNN
F 2 "SMD_Packages:SMD-0603_r" V 8380 2100 30  0001 C CNN
F 3 "" H 8450 2100 30  0000 C CNN
	1    8450 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3100 1900 3100
Wire Wire Line
	1900 3100 1900 3450
Wire Wire Line
	7300 3100 7950 3100
Wire Wire Line
	7950 3100 7950 3200
Wire Wire Line
	3450 4800 2550 4800
Wire Wire Line
	2550 4800 2550 4600
Wire Wire Line
	3450 4200 1750 4200
Wire Wire Line
	1750 4200 1750 4400
Wire Wire Line
	1750 4100 3450 4100
Wire Wire Line
	1750 3900 1750 4100
Wire Wire Line
	1950 3200 3450 3200
Wire Wire Line
	7300 2800 7900 2800
Wire Wire Line
	7900 2800 7900 2700
Wire Wire Line
	7300 2900 8350 2900
Wire Wire Line
	8350 2900 8350 2650
Wire Wire Line
	8350 2650 8850 2650
Wire Wire Line
	8350 3250 8850 3250
Wire Wire Line
	8350 3250 8350 3000
Wire Wire Line
	8350 3000 7300 3000
Wire Wire Line
	9250 2650 9350 2650
Wire Wire Line
	9350 2650 9350 3250
Wire Wire Line
	9350 3250 9250 3250
Wire Wire Line
	9350 2950 9550 2950
Wire Wire Line
	9550 2950 9550 3050
Connection ~ 9350 2950
Connection ~ 8700 3250
Connection ~ 8700 2650
Wire Wire Line
	1750 3900 1450 3900
Wire Wire Line
	1450 3850 1450 3950
Connection ~ 1450 3900
Wire Wire Line
	1750 4400 1450 4400
Wire Wire Line
	1450 4350 1450 4450
Connection ~ 1450 4400
Wire Wire Line
	2550 4600 2200 4600
Wire Wire Line
	2200 4550 2200 4650
Connection ~ 2200 4600
Wire Wire Line
	3450 4700 2400 4700
Wire Wire Line
	2400 4700 2400 5100
Wire Wire Line
	2400 5100 2200 5100
Wire Wire Line
	2200 5050 2200 5150
Connection ~ 2200 5100
Wire Wire Line
	1750 2800 1750 3000
Wire Wire Line
	1950 2950 1950 3200
Wire Wire Line
	1950 2950 1750 2950
Connection ~ 1750 2950
Wire Wire Line
	1750 3400 1750 3500
Wire Wire Line
	1900 3450 1750 3450
Connection ~ 1750 3450
Wire Wire Line
	7950 3200 8050 3200
Wire Wire Line
	8050 3150 8050 3300
Connection ~ 8050 3200
Wire Wire Line
	7900 2700 8050 2700
Wire Wire Line
	8050 2650 8050 2750
Connection ~ 8050 2700
Wire Bus Line
	2550 1650 10150 1650
Wire Bus Line
	2550 1650 2550 2400
Wire Bus Line
	10050 1650 10050 5500
Wire Wire Line
	2650 2300 3450 2300
Wire Wire Line
	2650 2400 3450 2400
Wire Wire Line
	2650 2500 3450 2500
Wire Wire Line
	7300 5000 9950 5000
Wire Wire Line
	7300 5200 9950 5200
Wire Wire Line
	7300 5300 9950 5300
Wire Wire Line
	7300 5400 9950 5400
Wire Wire Line
	7300 4700 8550 4700
Wire Wire Line
	8550 4700 8550 4550
Wire Wire Line
	7300 4600 8150 4600
Wire Wire Line
	8150 4400 8350 4400
Wire Wire Line
	8350 4400 8350 4500
Wire Wire Line
	8350 4900 8350 4950
Wire Wire Line
	8150 4600 8150 4400
Wire Wire Line
	7300 5100 9950 5100
Wire Wire Line
	3450 2900 1600 2900
Wire Wire Line
	850  2900 1100 2900
Wire Wire Line
	1000 2800 1000 3000
Connection ~ 1000 2900
Wire Wire Line
	1000 3400 1000 3500
Wire Wire Line
	1000 2200 1000 2300
Wire Wire Line
	3450 5300 3300 5300
Wire Wire Line
	3450 5400 3300 5400
Wire Wire Line
	7300 3200 7400 3200
Wire Wire Line
	7300 3300 7400 3300
Wire Wire Line
	7300 3600 7400 3600
Wire Wire Line
	7300 3500 7400 3500
Wire Wire Line
	7300 3400 7400 3400
Wire Wire Line
	7300 3900 7400 3900
Wire Wire Line
	7300 4000 7400 4000
Wire Wire Line
	7300 4100 7400 4100
Wire Wire Line
	7300 4200 7400 4200
Wire Wire Line
	7300 4300 7400 4300
Wire Wire Line
	7300 4400 7400 4400
Wire Wire Line
	7300 4500 7400 4500
Wire Wire Line
	3450 5100 3200 5100
Wire Wire Line
	3200 5100 3200 5200
Wire Wire Line
	3200 5200 2000 5200
Wire Wire Line
	3450 5200 3250 5200
Wire Wire Line
	3250 5200 3250 5250
Wire Wire Line
	3250 5250 2400 5250
Wire Wire Line
	2700 3700 3450 3700
Wire Wire Line
	2700 3500 3450 3500
Wire Wire Line
	2700 3600 3450 3600
Wire Wire Line
	3450 3400 2700 3400
Wire Wire Line
	3450 3300 2700 3300
Wire Wire Line
	2700 3800 3450 3800
Wire Wire Line
	3450 3000 2950 3000
Wire Wire Line
	3450 2800 2950 2800
Wire Wire Line
	3450 2700 2950 2700
Wire Wire Line
	3450 2600 2950 2600
Wire Wire Line
	7300 2400 8450 2400
Wire Wire Line
	8450 2400 8450 2350
Wire Wire Line
	8450 1850 8450 1800
Text Label 7900 2400 0    60   ~ 0
VBUS_SENSE
Wire Wire Line
	7300 2500 8650 2500
Wire Wire Line
	8650 2500 8650 2150
$Comp
L +3,3V #PWR062
U 1 1 53EB1BF4
P 8650 2150
F 0 "#PWR062" H 8650 2110 30  0001 C CNN
F 1 "+3,3V" H 8650 2260 30  0000 C CNN
F 2 "" H 8650 2150 60  0000 C CNN
F 3 "" H 8650 2150 60  0000 C CNN
	1    8650 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2600 7500 2600
Wire Wire Line
	7300 2700 7500 2700
Text HLabel 7500 2700 2    60   BiDi ~ 0
D+
Text HLabel 7500 2600 2    60   BiDi ~ 0
D-
Wire Wire Line
	7300 4800 7850 4800
Wire Wire Line
	7300 4900 7850 4900
Text HLabel 7850 4800 2    60   BiDi ~ 0
RF0
Text HLabel 7850 4900 2    60   BiDi ~ 0
RF1
Wire Wire Line
	3450 4300 3350 4300
Wire Wire Line
	3450 4400 3350 4400
Text HLabel 3350 4300 0    60   BiDi ~ 0
AN8/RP8/RB8
Text HLabel 3350 4400 0    60   BiDi ~ 0
AN9/RP9/RB9
Wire Wire Line
	3450 4500 3350 4500
Wire Wire Line
	3450 4600 3350 4600
Text HLabel 3350 4500 0    60   BiDi ~ 0
AN10/RB10
Text HLabel 3350 4600 0    60   BiDi ~ 0
AN11/RB11
Text HLabel 3300 4900 0    60   BiDi ~ 0
AN12/RB12
Wire Wire Line
	3300 4900 3450 4900
Text HLabel 3300 5000 0    60   BiDi ~ 0
AN13/RB1
Wire Wire Line
	3300 5000 3450 5000
Text HLabel 7350 2300 2    60   BiDi ~ 0
RP16/RF3
Wire Wire Line
	7300 2300 7350 2300
$Comp
L CRYSTAL X2
U 1 1 53F4D63C
P 9050 3950
F 0 "X2" H 9050 4100 60  0000 C CNN
F 1 "32khz" H 9050 3800 60  0000 C CNN
F 2 "Crystals:Crystal_Round_Horizontal_3mm_BigPad" H 9050 3950 60  0001 C CNN
F 3 "" H 9050 3950 60  0000 C CNN
	1    9050 3950
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C5
U 1 1 53F4D6C5
P 9400 3600
AR Path="/53F4D6C5" Ref="C5"  Part="1" 
AR Path="/53DA26B9/53F4D6C5" Ref="C5"  Part="1" 
F 0 "C5" H 9400 3700 40  0000 L CNN
F 1 "?" H 9406 3515 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 9438 3450 30  0000 C CNN
F 3 "~" H 9400 3600 60  0000 C CNN
	1    9400 3600
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-PIC24_USB_IR_Transmitter C6
U 1 1 53F4D77C
P 9400 4300
AR Path="/53F4D77C" Ref="C6"  Part="1" 
AR Path="/53DA26B9/53F4D77C" Ref="C6"  Part="1" 
F 0 "C6" H 9400 4400 40  0000 L CNN
F 1 "?" H 9406 4215 40  0000 L CNN
F 2 "SMD_Packages:SMD-0603_c" H 9438 4150 30  0000 C CNN
F 3 "~" H 9400 4300 60  0000 C CNN
	1    9400 4300
	0    -1   -1   0   
$EndComp
$Comp
L GND-RESCUE-PIC24_USB_IR_Transmitter #PWR063
U 1 1 53F4D7BA
P 9800 4000
F 0 "#PWR063" H 9800 4000 30  0001 C CNN
F 1 "GND" H 9800 3930 30  0001 C CNN
F 2 "" H 9800 4000 60  0000 C CNN
F 3 "" H 9800 4000 60  0000 C CNN
	1    9800 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 3700 8850 3700
Wire Wire Line
	8850 3700 8850 3600
Wire Wire Line
	8850 3600 9200 3600
Wire Wire Line
	9050 3650 9050 3600
Connection ~ 9050 3600
Wire Wire Line
	9050 4250 9050 4300
Wire Wire Line
	8850 4300 9200 4300
Wire Wire Line
	8850 4300 8850 3800
Wire Wire Line
	8850 3800 7300 3800
Connection ~ 9050 4300
Wire Wire Line
	9600 3600 9650 3600
Wire Wire Line
	9650 3600 9650 4300
Wire Wire Line
	9650 4300 9600 4300
Wire Wire Line
	9650 3900 9800 3900
Wire Wire Line
	9800 3900 9800 4000
Connection ~ 9650 3900
Text Label 8100 3700 0    60   ~ 0
SOSCI
Text Label 8100 3800 0    60   ~ 0
SOSCO
$EndSCHEMATC
