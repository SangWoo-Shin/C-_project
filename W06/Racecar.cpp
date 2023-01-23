/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Racecar.h"

namespace sdds
{
    Racecar::Racecar(std::istream& in) : Car(in)
    {
        std::string str;
        std::getline(in, str, '\n');
        
        str.erase(0, str.find_first_not_of(' '));
        m_booster = std::stod(str.substr(0, str.find('\n')));
        str.erase(0, str.find('\n') + 1);
    }

    void Racecar::display(std::ostream& out) const
    {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const
    {
        return Car::topSpeed() * (1 + m_booster);
    }
}
