/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef Car_h
#define Car_h
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>

namespace sdds
{
    class Car : public Vehicle
    {
    private:
        std::string maker;
        std::string condi;
        double t_Speed;
    public:
        Car(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };
}

#endif /* Car_h */
