#include "GPS.h"
#include "../../LIB/common_macros.h"
#include "../../LIB/tm4c123gh6pm.h"
#include "stdlib.h"
#include <math.h>
#include "../../MCAL/UART/UART.h"
#include <string.h>

char GPS[80];
char GPS_logName[] = "$GPRMC,";

char GPS_formated[12][20];
char *token;

float lat1, long1;
float lat2 = 1000, long2 = 1000; //Choose What you want

void Get_GPRMC() {
    //Recieve Correct Log
    char flag = 1;
    do {
        flag = 1;
        for (char i = 0; i < 7; i++) {
            if (GPS_logName[i] != UART_recieveByte(0)) {
                flag = 0; break;
            }
        }
    } while (flag == 0);
    
    strcpy(GPS, "");

    char recievedByte;
    char fillCounter = 0;
/*
    **THERE ARE 2 ALTERNATIVES FOR WRITING THE CODE THAT WILL WRITE TO GPS ARRAY**
    **IN THE VIDEO, THE ONE THAT IS COMMENTED BELOW ON LINE 32 IS THE ONE WRITTEN**
    **I DO NOT KNOW WHY HE DIDN'T WRITE IT LIKE THE ONE I WROTE UNDER IT WHICH IS NOT COMMENTED**
*/

    /*
    do {
        recievedByte = UART_recieveByte(0);
        GPS[fillCounter++] = recievedByte;
    }while(recievedByte != '*');
    */
    do {
        GPS[fillCounter++] = UART_recieveByte(0);
    }while(recievedByte != '*');

}

void parseGPRMC() {
    char noOfTokenStrings = 0;
    
    token = strtkn(GPS, ",");

    do {
        strcpy(GPS_formated[noOfTokenStrings], token);
        token = strtkn(NULL, ",");
        noOfTokenStrings++;

    }while(token != NULL);

    if (noOfTokenStrings == 12) {
        if (strcmp(GPS_formated[1], 'A') == 0) {
            if (strcmp(GPS_formated[3], "N") == 0) {
                lat1 = atof(GPS_formated[2]);
            } else {
                lat1 = -atof(GPS_formated[2]);
            }
            if (strcmp(GPS_formated[6], "E") == 0) {
                long1 = atof(GPS_formated[5]);
            } else {
                long1 = atof(GPS_formated[5]);
            }
        }
    }
}

float convertToDegrees(float nmeaCoord) {
    int degrees = (int)(nmeaCoord / 100);              // Get the degree part
    float minutes = nmeaCoord - (degrees * 100);       // Get the minutes part
    return degrees + (minutes / 60.0);                 // Convert to decimal
}

float convertToRad(float degrees) {
    return degrees * (PI/180);
}
/*
    lat1 = current
    lat2 = destination
*/
float Calculate_Distance (float lat1, float long1, float lat2, float long2) {
    // Convert to Rad
    lat1 = convertToRad(convertToDegrees(lat1));
    long1 = convertToRad(convertToDegrees(long1));
    lat2 = convertToRad(convertToDegrees(lat2));
    long2 = convertToRad(convertToDegrees(long2));
    // Differences
    double diff_lat = lat2 - lat1;
    double diff_long = long2 - long1;
    //Haversine Formula
    double a = sin(diff_lat/2) * sin(diff_lat/2) + cos(lat1) * cos(lat2) * sin(diff_long/2) * sin(diff_long/2);

    double c = 2* atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;

}