/******************************************************************************
 *
 * Module: GPS
 *
 * File Name: GPS.h
 *
 * Description: Header file for GPS module
 *
 * Author: Ahmed Mostafa
 *
 *******************************************************************************/

#ifndef GPS_H
#define GPS_H

/*******************************************************************************
 *                                Definations                                  *
 *******************************************************************************/

#define PI 3.14159265359     // pi
#define EARTH_RADIUS 6371000 // earth_radius in meters

/* External Variables */
extern float lat1;
extern float long1;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Function: GPS_UART_Init
 * Description: Initialize UART for GPS
 * Parameters: None
 * Return: None
 */
void GPS_UART_Init();

/*
 * Function: Get_GPRMC
 * Description: Get GPRMC data
 * Parameters: None
 * Return: None
 */
void GPS_getGPRMC();

/*
 * Function: parse_GPRMC
 * Description: Parse GPRMC data
 * Parameters: None
 * Return: None
 */
void GPS_parseGPRMC();

/*
 * Function: convertToRad
 * Description: Convert degrees to radians
 * Parameters: float degrees
 * Return: float
 */
float convertToRad(float degrees);

/*
 * Function: convertToDegree
 * Description: Convert radians to degrees
 * Parameters: float angle
 * Return: float
 */
float convertToDegree(float angle);

/*
 * Function: Calculate_Distance
 * Description: Calculate distance between two points
 * Parameters: float lat2, float long2
 * Return: float
 */
float Calculate_Distance(float lat2, float long2);

#endif // GPS_H