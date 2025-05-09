/******************************************************************************
 *
 * Module: GPS
 *
 * File Name: GPS.c
 *
 * Description: Source file for GPS module
 *
 * Author: Ahmed Mostafa
 *
 *******************************************************************************/

#include "GPS.h"
#include "stdlib.h"
#include <math.h>
#include "../../MCAL/UART/UART.h"
#include <string.h>

static char GPS[80];
static const char GPS_logName[] = "$GPRMC,";
static char GPS_output[80];
static char GPS_formated[12][20];
static char *token;
// 30.063768832165547, 31.279524810824068 (MIDDLE OF 11YARD PLAYGROUND IN COLLEGE)
static float lat1, long1;
static float lat1_temp, long1_temp, lat2_temp, long2_temp;

void Get_GPRMC(void)
{
    // Recieve Correct Log
    char i;
    char flag = 1;
    char recievedByte;
    char fillCounter = 0;
    do
    {
        flag = 1;
        for (i = 0; i < 7; i++)
        {
            if (GPS_logName[i] != UART_recieveByte(UART2))
            {
                flag = 0;
                break;
            }
        }
    } while (flag == 0);

    strcpy(GPS, "");

    do
    {
        recievedByte = UART_recieveByte(UART2);
        GPS[fillCounter++] = recievedByte;
    } while (recievedByte != '*');
}

void parse_GPRMC(void)
{
    char noOfTokenStrings = 0;

    token = strtok(GPS, ",");

    do
    {
        strcpy(GPS_formated[noOfTokenStrings], token);
        token = strtok(NULL, ",");
        noOfTokenStrings++;

    } while (token != NULL);

    if (noOfTokenStrings > 7)
    {
        if (strcmp(GPS_formated[1], "A") == 0)
        {
            if (strcmp(GPS_formated[3], "N") == 0)
            {
                lat1 = atof(GPS_formated[2]);
            }
            else
            {
                lat1 = -atof(GPS_formated[2]);
            }
            if (strcmp(GPS_formated[5], "E") == 0)
            {
                long1 = atof(GPS_formated[4]);
            }
            else
            {
                long1 = atof(GPS_formated[4]);
            }
        }
    }
}

float convertToRad(float degrees)
{
    return degrees * (PI / 180);
}

float convertToDegree(float angle)
{
    int degree = (int)angle / 100;
    float minutes = angle - (float)degree * 100;
    return (degree + (minutes / 60));
}

/**
 * @param lat2 Desination Lat
 * @param long2 Destination Long
 */

float Calculate_Distance(float lat2, float long2)
{
    float diff_lat;
    float diff_long;
    float a;
    float c;
    // Convert to Rad
    lat1_temp = convertToRad(convertToDegree(lat1));
    long1_temp = convertToRad(convertToDegree(long1));
    lat2_temp = convertToRad((lat2));
    long2_temp = convertToRad((long2));
    // Differences
    diff_lat = lat2_temp - lat1_temp;
    diff_long = long2_temp - long1_temp;
    // Haversine Formula
    a = sin(diff_lat / 2) * sin(diff_lat / 2) + cos(lat1_temp) * cos(lat2_temp) * sin(diff_long / 2) * sin(diff_long / 2);

    c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}