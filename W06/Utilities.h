/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef Utilities_h
#define Utilities_h
#include "Vehicle.h"
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

namespace sdds
{
    Vehicle* createInstance(std::istream& in);
}


#endif /* Utilities_h */
