#ifndef MCP3008_H
#define MCP3008_H

/* Debug Thread Stack size */
#define STACK_SIZE_ADC_THREAD 2048
/* Debug Thread Priority */
#define THREAD_PRIORITY_ADC 5 /* Lower Numerics has higher priority, -Ve Priorities are cooperitive threads, +Ve Priorities  are Preemtible  */
/* MCP DEFINES */
#define MCP3008_REF 5.01           //Volts - Calibrate as requried
#define MCP3008_RESOLUTION 1024.00 //10-Bit Resolution
#define MCP3008_MAX_CLK 1350000    //Hz
#define MCP3008_SLAVENUM 0
#define MCP3008_SINGLE_ENDED_CH0 0x80
#define MCP3008_LEADING_BYTE 0x01
#define ADC_SAMPLES 5
/* SPI CONFIG */
#define SPI_CS_PIN 31
#define SPI_CS_DELAY 2
#define SPI DT_NODELABEL(spi3)
/* DATA MESSAGE Q */
extern struct k_msgq tsd_msgq;
/* Data packet from MCP3008 to sensor control */
struct tsd_data
{
    float tsd_NTU, tsd_mV;
};

void thread_adc_ctrl(void *p1, void *p2, void *p3);

float adc_to_mV(uint16_t adcRead);

float adc_to_voltage(uint16_t adcRead);

float millivolts_to_NTU(int mV);

#endif
