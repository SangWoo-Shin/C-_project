// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-11-25
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"

namespace sdds
{ 
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station(const std::string& record)
    {
        Utilities utils;
        size_t idx = 0;
        bool more = true;
        if(!record.empty())
        {
            station_id = ++id_generator;
            
            station_name = utils.extractToken(record, idx, more);
            serialNum = stoi(utils.extractToken(record, idx, more));
            numOfItem = stoi(utils.extractToken(record, idx, more));
            if(station_name.length() > m_widthField)
            {
                m_widthField = station_name.length();
            }
            station_desc = utils.extractToken(record, idx, more);
        }
        else
        {
            more = false;
        }
        
    }
    const std::string& Station::getItemName() const
    {
        return station_name;
    }
    size_t Station::getNextSerialNumber()
    {
        return serialNum++;
    }
    size_t Station::getQuantity() const
    {
        return numOfItem;
    }
    void Station::updateQuantity()
    {
        if(numOfItem - 1 >= 0)
        {
            numOfItem--;
        }
    }
    void Station::display(std::ostream& os, bool full) const
    {
        if(full)
        {
            os << std::setw(3) << std::right << std::setfill('0') << station_id << " | " << std::setw(15) << std::setfill(' ') << std::left << station_name << " | " << std::setw(6) << std::right << std::setfill('0') << serialNum << " | " << std::setfill(' ') << std::right << std::setw(4) << numOfItem << " | " << std::left << station_desc << std::endl;
        }
        else
        {
            os << std::setw(3) << std::right << std::setfill('0') << station_id << " | " << std::setw(15) << std::setfill(' ') << std::left << station_name << " | " << std::setw(6) << std::right << std::setfill('0') << serialNum << " | " << std::endl;
        }
    }
}
