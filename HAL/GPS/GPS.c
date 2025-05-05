#include "GPS.h"
#include "stdlib.h"
#include <math.h>
#include "../../MCAL/UART/UART.h"
#include <string.h>

char GPS[80];
char GPS_logName[] = "$GPRMC,";
char GPS_output[80];
char GPS_formated[12][20];
char *token;
//30.063768832165547, 31.279524810824068 (MIDDLE OF 11YARD PLAYGROUND IN COLLEGE)
float lat1, long1;

void Get_GPRMC() {
    //Recieve Correct Log
		char i;
    char flag = 1;
		char recievedByte;
    char fillCounter = 0;
    //UART_recieveString(UART0, GPS);
    do {
        flag = 1;
        for (i = 0; i < 7; i++) {
            if (GPS_logName[i] != UART_recieveByte(0)) {
                flag = 0; break;
            }
        }
    } while (flag == 0);
    
    strcpy(GPS, "");

    do {
        recievedByte = UART_recieveByte(0);
        GPS[fillCounter++] = recievedByte;
    }while(recievedByte != '*');
    
}

void parse_GPRMC() {
    char noOfTokenStrings = 0;
    
    token = strtok(GPS, ",");

    do {
        strcpy(GPS_formated[noOfTokenStrings], token);
        token = strtok(NULL, ",");
        noOfTokenStrings++;

    }while(token != NULL);

    if (noOfTokenStrings == 11) {
        if (strcmp(GPS_formated[1], "A") == 0) {
            if (strcmp(GPS_formated[3], "N") == 0) {
                lat1 = atof(GPS_formated[2]);
            } else {
                lat1 = -atof(GPS_formated[2]);
            }
            if (strcmp(GPS_formated[5], "E") == 0) {
                long1 = atof(GPS_formated[4]);
            } else {
                long1 = atof(GPS_formated[4]);
            }
        }
    }
}

float convertToRad(float degrees) {
    return degrees * (PI/180);
}
/** 
 * @param lat2 Desination Lat
 * @param long2 Destination Long
 */
float Calculate_Distance (float lat2, float long2) {
		float diff_lat;
		float diff_long;
		float a;
		float c;
    // Convert to Rad
    lat1 = convertToRad(lat1);
    long1 = convertToRad(long1);
    lat2 = convertToRad(lat2);
    long2 = convertToRad(long2);
    // Differences
    diff_lat = lat2 - lat1;
    diff_long = long2 - long1;
    //Haversine Formula
    a = sin(diff_lat/2) * sin(diff_lat/2) + cos(lat1) * cos(lat2) * sin(diff_long/2) * sin(diff_long/2);

    c = 2* atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;

}