#define PI 3.14159265359

const double EARTH_RADIUS = 6378000;


/* PROTOTYPES */
void Get_GPRMC();
void parse_GPRMC();
float convertToDecimalDegrees(float nmeaCoord);
float convertToRad(float degrees);
float Calculate_Distance (float lat1, float long1, float lat2, float long2);