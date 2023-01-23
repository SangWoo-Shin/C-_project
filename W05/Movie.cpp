/*
 Name: Sangwoo Shin
Email: sshin36@myseneca.ca
ID: 119294213
Section: NFF
Date: 2022-10-16
*/

#include "Movie.h"
namespace sdds
{
    const std::string& Movie::title() const
    {
        return _title;
    }

    Movie::Movie()
    {
        _title = "";
        year = 0;
        description = "";
    }

    Movie::Movie(const std::string& strMovie)
    {
        std::string str = strMovie;
        
        str.erase(0, str.find_first_not_of(' '));
        _title = str.substr(0, str.find(','));
        _title.erase(_title.find_last_not_of(' ') + 1);
        str.erase(0, str.find(',') + 1);
        
        str.erase(0, str.find_first_not_of(' '));
        year = std::stoi(str.substr(0, str.find(',')));
        str.erase(0, str.find(',') + 1);
        
        str.erase(0, str.find_first_not_of(' '));
        description = str.substr(0, str.find('\n'));
        description.erase(description.find_last_not_of(' ') + 1);
        str.erase(0, str.find('\n') + 1);
    }

    std::ostream& Movie::display(std::ostream& os) const
    {
        os << std::setw(40) << _title << " | " << std::setw(4) << year << " | " << description << std::endl;
        return os;
    }

    std::ostream& operator<< (std::ostream& os, const Movie& movie)
    {
        return movie.display(os);
    }
}
