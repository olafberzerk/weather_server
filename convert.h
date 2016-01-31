/*
 * convert.h
 *
 *  Created on: Jan 29, 2016
 *      Author: Brady
 */

#ifndef CONVERT_H_
#define CONVERT_H_


// delta max = 0.6544 wrt dewPoint()
// 6.9 x faster than dewPoint()
// reference: http://en.wikipedia.org/wiki/Dew_point
double dewPointFast(double celsius, double humidity);

//Celsius to Kelvin conversion
double Kelvin(double celsius);

double Fahrenheit(double celsius);

#endif /* CONVERT_H_ */
