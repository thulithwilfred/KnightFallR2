
/**
 ************************************************************************
 * @file sara_r4.c
 * @author Wilfred MK
 * @date 13.05.2021 (Last Updated)
 * @brief Entry thread, instantiates auxilliary modules.
 **********************************************************************
 **/

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <drivers/sensor.h>
#include <logging/log.h>
#include <usb/usb_device.h>
#include <drivers/uart.h>

#include "dbg_led.h"
#include "sara_r4.h"
#include "sensors_custom.h"
#include "sam_m8q.h"
#include "tsd10_adc.h"

/* Compile Time Threads - These threads start runtime after the delay specified, else at ~t=0 */
/* Aux Threads */
K_THREAD_DEFINE(debug_led, STACK_SIZE_LED_THREAD, thread_flash_debug_led, NULL, NULL, NULL, THREAD_PRIORITY_LED_THREAD, 0, 50);
K_THREAD_DEFINE(sensor_driver, STACK_SIZE_SENSORS, thread_sensors, NULL, NULL, NULL, THREAD_PRIORITY_SENSORS, 0, 10);

/* Network Threads - Modem */
K_THREAD_DEFINE(modem_send, STACK_SIZE_MODEM_THREAD, thread_modem_ctrl, NULL, NULL, NULL, THREAD_PRIORITY_MODEM, 0, 50);
K_THREAD_DEFINE(modem_receive, STACK_SIZE_MODEM_THREAD, thread_modem_receive, NULL, NULL, NULL, THREAD_PRIORITY_MODEM, 0, 200);

/* TSD-10 ADC Thread */
//! Enable CMAKE COMPILE FOR THIS FILE WHEN TESTING
//K_THREAD_DEFINE(tsd10_adc, STACK_SIZE_TSD_THREAD, thread_tsd10_adc, NULL, NULL, NULL, THREAD_PRIORITY_TSD_THREAD, 0, 50);

/* GPS Communications Thread */

/**
 * @brief Entry thread to start the USB driver which the Shell 
 *          instance is dependant on. 
 * 
 */
void main(void)
{
    /* Start USB Driver */
    usb_enable(NULL);
}