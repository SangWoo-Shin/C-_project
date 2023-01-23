/*
 Name: Sangwoo Shin
Email: sshin36@myseneca.ca
ID: 119294213
Section: NFF
Date: 2022-10-16
*/

#ifndef SpellChecker_h
#define SpellChecker_h
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

namespace sdds
{
    class SpellChecker
    {
    private:
        std::string m_badWords[6] {};
        std::string m_goodWords[6] {};
        size_t count[6] {};
    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}
#endif /* SpellChecker_h */
