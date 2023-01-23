//Name: Sangwoo Shin
//ID: 1199294213
//Email: sshin36@myseneca.ca
//SEction: NDD
//Date:

#define CRT_NO_SECURE_WARNINGS
#include "Reservation.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <utility>

namespace sdds
{
    void Reservation::update(int day, int time)
    {
        Day = day;
        Hour = time;
    }

    std::string Reservation::eraseSpace(std::string tem, size_t end)
    {
        for(size_t i = 0; i < end; i++)
        {
            if(tem[i] == ' ')
            {
                if(i == 0)
                {
                    tem.erase(i, 1);
                    i--;
                }
                else if (tem[i+1] == ' ')
                {
                    tem.erase(i, 1);
                    i--;
                }
                else if(i+1 == tem.length())
                {
                    tem.erase(i, 1);
                    i--;
                }
            }
        }
        return tem;
    }

    Reservation::Reservation(const std::string& res)
    {
        std::string data {res};
        std::string tem {};
        size_t start {};
        size_t end {};
        for(auto i = 0; i < 6; i++)
        {
            if(i == 0)
            {
                end = data.find(':');
                tem = data.substr(0, end);
                data.erase(end, 1);
                tem = eraseSpace(tem, end);
                reservation_id = tem;
            }
            else if(i > 0 && i < 5)
            {
                start = end;
                end = data.find(',');
                start != end ? tem = data.substr(start, end - start) : tem = data[start];
                data.erase(end, 1);
                tem = eraseSpace(tem, end - start);
                if(i == 1)
                {
                    Name = tem;
                }
                else if(i == 2)
                {
                    Email = tem;
                }
                else if(i == 3)
                {
                    numOfPeople = stoi(tem);
                }
                else if(i == 4)
                {
                    Day = stoi(tem);
                }
            }
            else if(i == 5)
            {
                start = end;
                end = data.find('\n');
                tem = data.substr(start, end - start);
                Hour = stoi(tem);
            }
        }
    }

    std::ostream& Reservation::display(std::ostream&os) const
    {
        os << "Reservation" << std::setw(11) << std::right << reservation_id << ":" << std::setw(21) << std::right << Name << "  <" << std::setw(23) << std::left << Email + ">";
        if(Hour >= 6 && Hour <= 9)
        {
            os << "Breakfast on day " << Day << " @ " << Hour << ":00 for "<< numOfPeople;
        }
        else if(Hour >= 11 && Hour <= 15)
        {
            os << "Lunch on day " << Day << " @ " << Hour << ":00 for "<< numOfPeople;
        }
        else if(Hour >= 17 && Hour <= 21)
        {
            os << "Dinner on day " << Day << " @ " << Hour << ":00 for "<< numOfPeople;
        }
        else
        {
            os << "Drinks on day " << Day << " @ " << Hour << ":00 for "<< numOfPeople;
        }
        (numOfPeople > 1) ? os << " people.\n" : os << " person.\n";
        
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res)
    {
        return res.display(os);
    }
}

