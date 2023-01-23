//Name: Sangwoo Shin
//ID: 1199294213
//Email: sshin36@myseneca.ca
//SEction: NDD
//Date:


#ifndef Restaurant_h
#define Restaurant_h
#include "Reservation.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <utility>

namespace sdds
{
    class Restaurant
    {
    private:
        Reservation** reserve;
        size_t count {};
    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        std::ostream& display(std::ostream& os) const;
        friend std::ostream& operator <<(std::ostream& os, const Restaurant& restaurant);
        Restaurant(const Restaurant& src) ; // copy constructor
        Restaurant& operator= (const Restaurant& src) ; // copy assignment
        Restaurant(Restaurant &&src) ; // move constructor
        Restaurant& operator= (Restaurant&& src) ; // move assignment
        ~Restaurant();
    };
}
#endif
