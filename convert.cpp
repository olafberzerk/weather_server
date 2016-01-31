/*
/*
 * convert.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: Brady
 */

#include <arduino.h>
// delta max = 0.6544 wrt dewPoint()
// 6.9 x faster than dewPoint()
// reference: http://en.wikipedia.org/wiki/Dew_point
double dewPointFast(double celsius, double humidity)
{
  delay(2000);
  double a = 17.271;
  double b = 237.7;
  double temp = (a * celsius) / (b + celsius) + log(humidity*0.01);
  double Td = (b * temp) / (a - temp);
  return Td;
}

//Celsius to Kelvin conversion
double Kelvin(double celsius)
{
  return celsius + 273.15;
}

double Fahrenheit(double celsius)
{
  return 1.8 * celsius + 32;
}



