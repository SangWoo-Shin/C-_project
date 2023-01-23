/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef CrimeStatistics_h
#define CrimeStatistics_h

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <functional>
#include <list>
#include <iomanip>
#include <fstream>

namespace sdds
{
    struct Crime
    {
        std::string province;
        std::string district;
        std::string crime;
        unsigned int m_case;
        unsigned int year;
        unsigned int m_resolved;
    };

    std::ostream& operator<<(std::ostream& out, const Crime& theCrime);

    class CrimeStatistics
    {
    private:
        std::vector<Crime> arr_Crime;
    public:
        CrimeStatistics(const char* fileName);
        void display(std::ostream& out) const;
        void sort(std::string name);
        void cleanList();
        bool inCollection(std::string name) const;
        std::list<Crime> getListForProvince(std::string name) const;
    };
}
#endif /* CrimeStatistics_h */
