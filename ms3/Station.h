// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-11-25
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef Station_h
#define Station_h
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <iomanip>

namespace sdds
{
    class Station
    {
    private:
        int station_id;
        std::string station_name;
        std::string station_desc;
        unsigned int serialNum;
        unsigned int numOfItem;
        static size_t m_widthField;
        static int id_generator;
    public:
        Station(const std::string& record);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}

#endif /* Station_h */
