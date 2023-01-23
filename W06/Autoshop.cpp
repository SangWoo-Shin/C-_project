/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Autoshop.h"

namespace sdds
{
    Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream& out) const
    {
        for(auto itr = m_vehicles.begin(); itr != m_vehicles.end(); itr++)
        {
            (*itr)->display(out);
            out << std::endl;
        }
    }

    Autoshop::~Autoshop()
    {
        for(auto itr = m_vehicles.begin(); itr != m_vehicles.end(); itr++)
        {
            delete (*itr);
        }
    }
}
