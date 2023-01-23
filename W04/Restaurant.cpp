//Name: Sangwoo Shin
//ID: 1199294213
//Email: sshin36@myseneca.ca
//SEction: NDD
//Date: 2022/10/09

#include "Restaurant.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <utility>

namespace sdds
{
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
    {
    
        reserve = new Reservation*[cnt];
        for(auto i = 0u; i < cnt; i++)
        {
            reserve[i] = new Reservation(*reservations[i]);
        }
        count = cnt;
    }

    std::ostream& Restaurant::display(std::ostream& os) const
    {
        static unsigned int call_cnt {};
        call_cnt++;
        os << "--------------------------\n" << "Fancy Restaurant (" << call_cnt << ")" << std::endl;
        os << "--------------------------" << std::endl;
        if(reserve != nullptr)
        {
            for(size_t i = 0; i < count; i++)
            {
                os << *reserve[i];
            }
        }
        else
        {
            os << "This restaurant is empty!" << std::endl;
        }
        os << "--------------------------" << std::endl;
        return os;
    }

    std::ostream& operator <<(std::ostream& os, const Restaurant& restaurant)
    {
        return restaurant.display(os);
    }

    Restaurant::Restaurant(const Restaurant& src) // copy constructor
    {
        *this = src;
    }

    Restaurant& Restaurant::operator= (const Restaurant& src) // copy assignment
    {
        if(this != &src)
        {
            if(this->count != 0)
            {
                for (auto i = 0u; i < count; ++i)
                {
                    delete reserve[i];
                }
                delete[] reserve;
                reserve = nullptr;
            }
            if(src.count > 0)
            {
                count = src.count;
                reserve = new Reservation*[count];
                for(size_t i = 0; i < src.count; i++)
                {
                    this->reserve[i] = new Reservation(*src.reserve[i]);
                }
            }
        }
        return *this;
    }

    Restaurant& Restaurant::operator=(Restaurant&& src)
    {
        if(this != &src)
        {
            if(count != 0)
            {
                for (auto i = 0u; i < count; ++i)
                {
                    delete reserve[i];
                }
                delete[] reserve;
                reserve = nullptr;
            }
            reserve = src.reserve;
            count = src.count;
            src.reserve = nullptr;
            src.count = 0;
        }
         return *this;
    }

    Restaurant::Restaurant(Restaurant &&src) // move constructor
    {
        *this = std::move(src);
    }
        
    Restaurant::~Restaurant()
    {
        for (auto i = 0u; i < count; ++i)
        {
            delete reserve[i];
        }
        delete[] reserve;
        reserve = nullptr;
    }
}
