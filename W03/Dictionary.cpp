//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-10-01
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <string>
#include "Dictionary.h"

namespace sdds
{
    Dictionary::Dictionary() {}

    Dictionary& Dictionary:: operator=(const Dictionary& dic)
    {
        if (this != &dic)
        {
            m_term = dic.getTerm();
            m_definition = dic.getDefinition();
        }
        return *this;
    }

    std::ostream& Dictionary:: display(std::ostream& os) const
    {
        os << std::setw(20) << getTerm() << ": " << getDefinition();
        return os;
    }

    bool Dictionary::operator==(const Dictionary & dic)
    {
        return m_term.compare(dic.m_term) == 0 && m_definition.compare(dic.m_definition) == 0 ? true : false;
    }

    std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary)
    {
        return dictionary.display(os);
    }
}
