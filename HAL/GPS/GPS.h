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

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void Get_GPRMC();
void parse_GPRMC();
float convertToRad(float degrees);
float convertToDegree(float angle); 
float Calculate_Distance(float lat2, float long2);

#endif // GPS_H