/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef Autoshop_h
#define Autoshop_h
#include "Vehicle.h"
#include <iostream>
#include <vector>
#include <list>
#include <vector>
#include <string>
#include <iomanip>

namespace sdds
{
    class Autoshop
    {
    private:
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        ~Autoshop();
        template <typename T>
        void select(T test, std::list<const Vehicle*>& vehicles)
        {
            for(auto itr = m_vehicles.begin(); itr != m_vehicles.end(); itr++)
            {
                if(test(*itr))
                {
                    vehicles.push_back(*itr);
                }
            }
        }
    };
}

#endif /* Autoshop_h */
