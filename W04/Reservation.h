//Name: Sangwoo Shin
//ID: 1199294213
//Email: sshin36@myseneca.ca
//SEction: NDD
//Date:

#ifndef Rservation_h
#define Rservation_h
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <utility>

namespace sdds
{
    class Reservation
    {
    private:
        std::string reservation_id;
        std::string Name;
        std::string Email;
        unsigned int numOfPeople;
        unsigned int Day;
        unsigned int Hour;
    public:
        Reservation() {};
        void update(int day, int time);
        std::string eraseSpace(std::string tem, size_t end);
        Reservation(const std::string& res);
        std::ostream& display(std::ostream&os) const;
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}


#endif /* Rservation_h */
