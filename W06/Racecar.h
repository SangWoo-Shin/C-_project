/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef Racecar_h
#define Racecar_h
#include "Car.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

namespace sdds
{
    class Racecar : public Car
    {
    private:
        double m_booster;
    public:
        Racecar(std::istream& in);
        void display(std::ostream& out) const;
        double topSpeed() const;
    };
}

#endif /* Racecar_h */
