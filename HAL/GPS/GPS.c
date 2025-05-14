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

/* Global Variables */
float lat1 = 0.0;
float long1 = 0.0;

static char GPS[80];
static const char GPS_logName[] = "$GPRMC,";
static char GPS_output[80];
static char GPS_formated[12][20];
static char *token;
static float lat1_temp, long1_temp, lat2_temp, long2_temp;

/*
 * Function: GPS_UART_Init
 * Description: Initialize UART for GPS
 * Parameters: None
 * Return: None
 */
void GPS_UART_Init()
{
    UART_ConfigType UART2_Configurations; // UART2 configuration structure

    UART2_Configurations.uart_number = UART2;
    UART2_Configurations.DataBits = 8;
    UART2_Configurations.parity = 0;
    UART2_Configurations.stop_bits = 1;
    UART2_Configurations.IBRD = 104;
    UART2_Configurations.FBRD = 11;

    UART_Config(&UART2_Configurations);
}

/*
 * Function: Get_GPRMC
 * Description: Get GPRMC data
 * Parameters: None
 * Return: None
 */

void Get_GPRMC(void)
{

    // Intialize the UART2
    GPS_UART_Init();
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

/*
 * Function: parse_GPRMC
 * Description: Parse GPRMC data
 * Parameters: None
 * Return: None
 */

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

/*
 * Function: convertToRad
 * Description: Convert degrees to radians
 * Parameters: float degrees
 * Return: float
 */

float convertToRad(float degrees)
{
    return degrees * (PI / 180);
}

/*
 * Function: convertToDegree
 * Description: Convert radians to degrees
 * Parameters: float angle
 * Return: float
 */

float convertToDegree(float angle)
{
    int degree = (int)angle / 100;
    float minutes = angle - (float)degree * 100;
    return (degree + (minutes / 60));
}

/*
 * Function: Calculate_Distance
 * Description: Calculate distance between two points
 * Parameters: float lat2, float long2
 * Return: float
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