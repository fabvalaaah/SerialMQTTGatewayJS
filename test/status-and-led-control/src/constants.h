#ifndef _CONSTANTS_H    /* Guard against multiple inclusion */
#define _CONSTANTS_H

#include "system_config.h"
#include "system_definitions.h"
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <xc.h> 
#include <sys/attribs.h>
#include "peripheral\peripheral.h"      /* Peripheral library definitions. */
#include "system/common/sys_module.h"   // SYS function prototypes

/* Software timer*/
#define SOFT_TIMER_ONE_SHOT 1
#define SOFT_TIMER_REPEAT 0

/* board power */
#define LAT_BOARD_EN                LATBbits.LATB12
#define TRIS_BOARD_EN               TRISBbits.TRISB12
    
/* CAN 5V enable for external sensors */
#define LAT_CAN_EN                  LATBbits.LATB7
#define TRIS_CAN_EN                 TRISBbits.TRISB7

/* CAN TRANSCEIVER RS (enable pin) */
#define LAT_CAN_TRS_EN                  LATBbits.LATB6
#define TRIS_CAN_TRS_EN                 TRISBbits.TRISB6

/* power LED */
#define LAT_POW_LED                 LATEbits.LATE6
#define TRIS_POW_LED                TRISEbits.TRISE6

/* State LED */
#define LAT_STATE_LED               LATBbits.LATB3
#define TRIS_STATE_LED              TRISBbits.TRISB3

/* CAN ERROR LED */
#define LAT_CAN_ERR_LED             LATGbits.LATG6
#define TRIS_CAN_ERR_LED            TRISGbits.TRISG6

/* buzzer */
#define LAT_BUZZER                  LATBbits.LATB8
#define TRIS_BUZZER                 TRISBbits.TRISB8

/* BLE_CTS */
#define LAT_BLE_CTS                  LATFbits.LATF0
#define TRIS_BLE_CTS                 TRISFbits.TRISF0

/* GPSB UART converter enable */
#define LAT_GPSB_CONV_EN                  LATEbits.LATE4
#define TRIS_GPSB_CONV_EN                 TRISEbits.TRISE4

/* GPSB UART voltage selector */
#define LAT_GPSB_VOLT_SEL                  LATBbits.LATB4
#define TRIS_GPSB_VOLT_SEL                TRISBbits.TRISB4
#define GPSB_VOLT_SEL_5V 1
#define GPSB_VOLT_SEL_3_3V 0

/* GPS UART*/
#define LAT_GPS_WAKE_UP  LATGbits.LATG6
#define TRIS_GPS_WAKE_UP TRISEbits.TRISE2
#define LAT_GPS_ENABLE   LATFbits.LATF1
#define TRIS_GPS_ENABLE  TRISFbits.TRISF1
#define LAT_GPS_RESET    LATEbits.LATE1
#define TRIS_GPS_RESET   TRISEbits.TRISE1

#define PBCLK2 100000000L
#define PBCLK3 100000000L
#define FREQ_BUZZER  4000

#define FIFO_LENGTH 100

typedef enum {
    TIMER_HANDLER_STATE_LED,
    TIMER_HANDLER_SUTDOWN,
    TIMER_HANDLER_GPS_ON,
    TIMER_HANDLER_GPS_OFF,
    TIMER_HANDLER_WAIT_FOR_LOGGED_ON,
    TIMER_HANDLER_GPS_RESET,
    TIMER_HANDLER_GPS_UART_INIT,
    TIMER_HANDLER_GPSB_LOG_ON
}SOFTWARE_TIMER_HANDLER;

#endif /* _EXAMPLE_FILE_NAME_H */
