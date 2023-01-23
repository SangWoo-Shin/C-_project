/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Utilities.h"

namespace sdds
{
    Vehicle* createInstance(std::istream& in)
    {
        Vehicle* vehicle = nullptr;
        std::string tag;
        
        getline(in, tag);
        tag.erase(0, tag.find_first_not_of(' '));
        
        std::stringstream str(tag);
        if(!tag.empty())
        {
            if(tag[0] == 'c' || tag[0] == 'C')
            {
                vehicle = new Car(str);
            }
            else if(tag[0] == 'v' || tag[0] == 'V')
            {
                vehicle = new Van(str);
            }
            else if(tag[0] == 'r' || tag[0] == 'R')
            {
                vehicle = new Racecar(str);
            }
            else if(tag[0] == 'l' || tag[0] == 'L')
            {
                vehicle = new Luxuryvan(str);
            }
            else
            {
                std::string err {};
                getline(str, err, ',');
                throw "Unrecognized record type: [" + err + "]";
            }
        }
        return vehicle;
    }
}
