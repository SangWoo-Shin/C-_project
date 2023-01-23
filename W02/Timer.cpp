//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-09-23
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_NO_SECURE_WARNINGS
#include "Timer.h"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std::chrono;
namespace sdds
{
    void Timer::start()
    {
        startPoint = std::chrono::system_clock::now();
    }

    long long Timer::stop()
    {
        stopPoint = std::chrono::system_clock::now();
        auto diff = stopPoint - startPoint;
        std::chrono::duration_cast<nanoseconds>(diff);
        
        return diff.count();
    }
}

