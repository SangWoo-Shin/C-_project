// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-11-25
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef Utilities_h
#define Utilities_h
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <list>

namespace sdds
{
    class Utilities
    {
    private:
        size_t m_widthField = 1;
        static char m_delimiter;
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}


#endif /* Utilities_h */
