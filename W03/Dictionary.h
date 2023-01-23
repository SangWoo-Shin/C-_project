//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-10-01
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef Dictionary_h
#define Dictionary_h

#define _CRT_NO_SECURE_WARNGINGS
#include <iostream>
#include <iomanip>
#include <string>

namespace sdds
{
    
    class Dictionary
    {
        std::string m_term{};
        std::string m_definition{};
    public:
        Dictionary();
        Dictionary& operator=(const Dictionary& dic);
        bool operator==(const Dictionary& dic);
        const std::string& getTerm() const {return m_term;}
        const std::string& getDefinition() const {return m_definition;}
        Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{}
        std::ostream& display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary);


}

#endif /* Dictionary_h */
