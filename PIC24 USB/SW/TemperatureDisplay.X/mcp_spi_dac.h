/* 
 * File:   mcp_spi_dac.h
 * Author: h.angerer
 *
 * Created on 15. September 2014, 13:43
 */

#ifndef MCP_SPI_DAC_H
#define	MCP_SPI_DAC_H

#ifdef	__cplusplus
extern "C" {
#endif
/** @brief MCP4822 SPI DAC command word */
	typedef struct DacCommand{
		union{
			struct{
				unsigned data : 12; /// < DAC value: Vout = Output Gain * Vref * data / 4096; Vref = 2.048V
				unsigned notShutdown : 1; /// < Ouput Shutdown (0 = Output active, 1 = shut down)
				unsigned noOutputGain : 1; /// < Output Gain Selection (0 = x2 Output Gain, 1 = x1 Output Gain)
				unsigned : 1; /// < Reserved
				unsigned notA_B : 1; /// < DAC Channel Selection (0 = Channel A, 1 = Channel B)
							};

			struct{
				unsigned char loByte;
				unsigned char hiByte;
			};
			struct{
				unsigned short raw;
			};
		};
	}DacCommand;


#ifdef	__cplusplus
}
#endif

#endif	/* MCP_SPI_DAC_H */

