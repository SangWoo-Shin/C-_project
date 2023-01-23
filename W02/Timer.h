//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-09-23
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef Timer_h
#define Timer_h

#define _CRT_NO_SECURE_WARNINGS
#include "Timer.h"
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std::chrono;
namespace sdds
{
    class Timer
    {
        std::chrono::time_point<system_clock> startPoint;
        std::chrono::time_point<system_clock> stopPoint;
    public:
        void start();
        long long stop();
    };
}
#endif /* Timer_h */
