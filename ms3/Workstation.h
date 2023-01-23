// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-12-03
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"
namespace sdds {
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station {
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation = nullptr;
    public:
        Workstation(const std::string& str);
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);

        Workstation(const Workstation& src) = delete;
        Workstation& operator=(const Workstation& src) = delete;
        Workstation(Workstation&& src) = delete;
        Workstation& operator=(Workstation&& src) = delete;
    };


}


#endif
