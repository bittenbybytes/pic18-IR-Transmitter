/**
 * @brief This file provides mimics the GPIO API of the arduino environment.
 *
 * This offers basic access to GPIO pins through an API abstraction layer similar
 * to the one provided within the arduino environment. This enhances portability
 * for higher level code. The similarity with the arduino API should even allow
 * exchanging code with arduino sketches and libraries.
 */

#ifndef ARDUINO_GPIO_H
#define	ARDUINO_GPIO_H

#ifdef	__cplusplus
extern "C"
{
#endif

	/**
	 * @brief GPIO pin modes
	 * 
	 * Selectable GPIO pin modes to be applied.
	 * @see pinMode
	 */
	typedef enum PinModeGPIO{
		INPUT, /**< Pin is used to read the signal state (voltage) of the attached line. */
		OUTPUT /**< Pin is used to drive the signal state (voltage) of the attached line. */
	}PinModeGPIO;

#define A0 -1
#define A1 -2
#define A2 -3
#define A3 -4
#define A4 -5
#define A5 -6

	/**
	 * @brief Set the GPIO pin mode (direction).
	 *
	 * Set the pin mode of a GPIO pin to be used as input or output. All GPIO
	 * pins are by default set as input on reset and on power on. They need to 
	 * be setup as output to drive signal lines using @c digitalWrite as shown
	 * below.
	 *
	 * @warning Setting analog pins to digital output will disable analog input
	 * for all higher numbered analog channels on many PIC devices!
	 *
	 * @code
	 * pinMode(0, OUTPUT);
	 * pinMode(0, HIGH);
	 * @endcode
	 * @param pin GPIO pin to be set.
	 * @param mode GPIO pin mode to be applied.
	 * @see digitalWrite
	 * @see digitalRead
	 */
	void pinMode(int pin, enum PinModeGPIO mode);

#ifndef HIGH
#define HIGH (1)
#endif

#ifndef LOW
#define LOW (0)
#endif

	/**
	 * @brief Write a digital state to a GPIO pin.
	 *
	 * Drive the connected signal line HIGH(V+) or LOW(GND) if the selected GPIO
	 * pin is configured as output. If the selected GPIO pin is configured as
	 * input weak internal pull-up or pull-down resistors will be enabled if
	 * available in the device. Note that GPIO are set to input by default so
	 * they need to be set up as output before the can drive signal lines as
	 * shown below.
	 * @code
	 * pinMode(0, OUTPUT);
	 * pinMode(0, HIGH);
	 * @endcode
	 * @param pin GPIO pin to be set.
	 * @param level Signal line level to be driven.
	 * @see pinMode
	 * @see digitalRead
	 */
	void digitalWrite(int pin, unsigned level);
		
	/**
	 * @brief Read the digital state of a GPIO pin.
	 *
	 * Read the state HIGH(V+) or LOW(GND) of the signal line connected to the
	 * selected GPIO input pin. The pin must be set up as input, otherwise the
	 * GPIO pin will drive against the external level.
	 * If the line is not driven externally the default state may be set using
	 * internal pull-up or pull-down resistors.
	 * @code
	 * pinMode(0, OUTPUT);
	 * @endcode
	 * @param pin GPIO pin to be set.
	 * @return Describe what the function returns.
	 * @see pinMode
 	 * @see digitalWrite
	 */
	unsigned digitalRead(int pin);

#ifdef	__cplusplus
}
#endif

#endif	/* ARDUINO_GPIO_H */

