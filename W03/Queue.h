//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-10-01
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <iomanip>
#include <string>
#include "Dictionary.h"

namespace sdds
{

    template <typename T, unsigned int Capacity>
    class Queue
    {
    private:
        T object[Capacity] {};
        size_t count{};
        static T dummy;
        
    public:
        Queue() {};
        
        T& operator[](size_t index)
        {
            return index < count ? object[index] : dummy;
        }

        size_t size() const
        {
            return count;
        }

        virtual ~Queue() {}
        
        virtual bool push(const T& item)
        {
            if (count < Capacity)
            {
                object[count] = item;
                count++;
                return true;
            }
            return false;
        }

        T pop()
        {
            if (count > 0)
            {
                T tem = object[0];
                for (size_t i = 0; i < count - 1; i++)
                {
                    object[i] = object[i + 1];
                }
                count--;
                return tem;
            }
            return dummy;
        }
            
        void display(std::ostream& os = std::cout) const
        {
            os << "----------------------" << std::endl;
            os << "| Dictionary Content |" << std::endl;
            os << "----------------------" << std::endl;
            for (size_t i = 0; i < count; i++)
            {
                os << object[i] << std::endl;
            }
            os << "----------------------" << std::endl;
            
        }
    };
    template <typename T, unsigned int Capacity>
    T Queue<T, Capacity> ::dummy {};

    template<>
    Dictionary Queue<Dictionary, 100>::dummy = Dictionary("Empty Term","Empty Substitute");

}
#endif /* Queue_h */
