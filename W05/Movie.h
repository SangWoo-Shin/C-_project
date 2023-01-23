/*
 Name: Sangwoo Shin
Email: sshin36@myseneca.ca
ID: 119294213
Section: NFF
Date: 2022-10-16
*/

#ifndef Movie_h
#define Movie_h
#include <iostream>
#include <iomanip>
#include <string>

namespace sdds
{
    class Movie
    {
    private:
        std::string _title;
        size_t year;
        std::string description;
    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string& strMovie);
        template<typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(_title);
            spellChecker(description);
        }
        std::ostream& display(std::ostream& os) const;
        friend std::ostream& operator<< (std::ostream& os, const Movie& movie);
    };
}

#endif /* Movie_h */
