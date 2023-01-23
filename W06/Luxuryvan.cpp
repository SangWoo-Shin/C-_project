/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Luxuryvan.h"

namespace sdds
{
    Luxuryvan::Luxuryvan(std::istream& in) : Van(in)
    {
        std::string str;
        std::getline(in, str, '\n');
        
        str.erase(0, str.find_first_not_of(' '));
        str.substr(0, str.find('\n'));
        str.erase(str.find_last_not_of(' ') + 1);
        if(str[0] == 'e')
        {
            m_consumption = str;
            str.erase(0, str.find('\n') + 1);
        }
        else
        {
            std::string err = "Invalid record!";
            throw err;
        }
    }
    void Luxuryvan::display(std::ostream& out) const
    {
        Van::display(out);
        out << consumption();
    }
    std::string Luxuryvan::consumption() const
    {
        return m_consumption[0] == 'e' ? " electric van  *" : "";
    }
}
