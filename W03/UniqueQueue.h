//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-10-01
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef UniqueQueue_h
#define UniqueQueue_h
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Queue.h"

namespace sdds
{
    template <typename T>
    class UniqueQueue : public Queue <T, 100>
    {
    public:

        bool push(const T& item)
        {
            if (this->size() < 100)
            {
                for (size_t i = 0; i < this->size(); i++)
                    if (this->operator[](i) == item)
                    {
                        return false;
                    }
                Queue<T,100>::push(item);
            }
            return true;
        }
        ~UniqueQueue() {}
    };

 
    template<>
    bool UniqueQueue<double>::push(const double& item)
    {
        if (this->size() < 100)
        {
            for (size_t i = 0; i < this->size(); i++)
                if (std::fabs(this->operator[](i) - item) <= 0.005 )
                {
                    return false;
                }
            Queue<double, 100>::push(item);
        }
        return true;
    }
}

#endif /* UniqueQueue_h */
