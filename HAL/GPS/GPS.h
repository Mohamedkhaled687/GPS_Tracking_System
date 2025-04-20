#define PI 3.14159265359

const double EARTH_RADIUS = 6371000; //earth_radius in meters


/* PROTOTYPES */
void Get_GPRMC();
void parse_GPRMC();
float convertToRad(float degrees);
float Calculate_Distance ();