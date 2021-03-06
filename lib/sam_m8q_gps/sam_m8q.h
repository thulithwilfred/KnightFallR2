#ifndef SAM_M8Q_H
#define SAM_M8Q_H

/* Structure containing the recieved in values of a GLL message */
struct samGLLMessage
{
    double lat, lon;
};

/* GLL Data Packet Message Queue, Sends data to sensor control */
extern struct k_msgq gps_msgq;

/* ==================================================================== */
/* ==============================THREAD DEFINES======================== */
/* ==================================================================== */
/* Debug Thread Stack size */
#define STACK_SIZE_GPS_THREAD 2048

/* ==================================================================== */
/* ==============================MISC Defines========================== */
/* ==================================================================== */
#define MAX_READ_SIZE 128

/* Debug Thread Priority */
/* Lower Numerics has higher priority, -Ve Priorities are cooperitive threads, +Ve Priorities  are Preemtible  */
#define THREAD_PRIORITY_GPS 3

/* ==================================================================== */
/* ==============================SAM M8Q CONFIG========================== */
/* ==================================================================== */
#define SAM_CMD_DELAY 3
#define SAM_TIMEOUT 10
#define GPS_NO_LOCK_TIMEOUT 240
#define GPS_POLL_TIME 190
#define GLL_MSG_FIELDS 10
#define GPS_NO_LOCK_VAL 0.00

/* Notifies the GPS polling thread to stop polling */
extern bool gpsTimeOutOccured;

/* Device tree node identifier for UART0 - Connected to GPS Module*/
#define UART0 DT_LABEL(DT_NODELABEL(uart0))

void thread_gps_ctrl(void *p1, void *p2, void *p3);

int sam_m8q_uart_init(void);

void sam_mdm_receiver_flush(const struct device *uart_device);

void sam_m8q_setup(void);

bool sam_recv(struct samGLLMessage *gllMsgPacket);

bool sam_recv_parse(struct samGLLMessage *gllMsgPacket, char *gllMsg, int sizeofBuffer);

double GpsToDecimalDegrees(const char *nmeaPos, char quadrant);

#endif