/*
 Name: Sangwoo Shin
Email: sshin36@myseneca.ca
ID: 119294213
Section: NFF
Date: 2022-10-16
*/

#ifndef Book_h
#define Book_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

namespace sdds
{
    class Book
    {
    private:
        std::string author;
        std::string _title;
        std::string _country;
        size_t _year;
        double* _price;
        std::string description;
    public:
        Book() {};
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        std::ostream& display(std::ostream& os) const;
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
        void cleanUp();
        template <typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(description);
        }
    };

}

#endif /* Book_h */
