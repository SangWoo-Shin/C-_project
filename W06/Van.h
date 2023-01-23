/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef Van_h
#define Van_h
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

namespace sdds
{
    class Van : public Vehicle
    {
    private:
        std::string maker;
        std::string _type;
        std::string condi;
        std::string purpose;
        double t_Speed;
    public:
        Van(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        std::string type() const;
        std::string usage() const;
        void display(std::ostream& out) const;
    };
}

#endif /* Van_h */
