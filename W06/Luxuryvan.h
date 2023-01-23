/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef Luxuryvan_h
#define Luxuryvan_h
#include "Van.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

namespace sdds
{
    class Luxuryvan : public Van
    {
    private:
        std::string m_consumption;
    public:
        Luxuryvan(std::istream& in);
        void display(std::ostream& out) const;
        std::string consumption() const;
    };
}

#endif /* Luxuryvan_h */
