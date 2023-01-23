/*
 Name: Sangwoo Shin
Email: sshin36@myseneca.ca
ID: 119294213
Section: NFF
Date: 2022-10-16
*/

#include "Book.h"
namespace sdds
{
    const std::string& Book::title() const
    {
        return _title;
    }

    const std::string& Book::country() const
    {
        return _country;
    }

    const size_t& Book::year() const
    {
        return _year;
    }

    double& Book::price()
    {
        return *_price;
    }

    Book::Book(const std::string& strBook)
    {
        std::string str = strBook;
        double temPrice {};
        
        str.erase(0, str.find_first_not_of(' '));
        author = str.substr(0, str.find(','));
        author.erase(author.find_last_not_of(' ') + 1);
        str.erase(0, str.find(',') + 1);
        
        str.erase(0, str.find_first_not_of(' '));
        _title = str.substr(0, str.find(','));
        _title.erase(_title.find_last_not_of(' ') + 1);
        str.erase(0, str.find(',') + 1);
        
        str.erase(0, str.find_first_not_of(' '));
        _country = str.substr(0, str.find(','));
        _country.erase(_country.find_last_not_of(' ') + 1);
        str.erase(0, str.find(',') + 1);
        
        str.erase(0, str.find_first_not_of(' '));
        temPrice = std::stod(str.substr(0, str.find(',')));
        _price = new double(temPrice);
        str.erase(0, str.find(',') + 1);
        
        str.erase(0, str.find_first_not_of(' '));
        _year = std::stoi(str.substr(0, str.find(',')));
        str.erase(0, str.find(',') + 1);
        
        str.erase(0, str.find_first_not_of(' '));
        description = str.substr(0, str.find('\n'));
        description.erase(description.find_last_not_of(' ') + 1);
        str.erase(0, str.find('\n') + 1);
    }

    std::ostream& Book::display(std::ostream& os) const
    {
        os << std::setw(20) << author << " | " << std::setw(22) << _title << " | " << std::setw(5) << _country << " | " << std::setw(4) << _year << " | " << std::setw(6);
        os << std::fixed;
        os << std::setprecision(2);
        os << *_price << " | " << description << std::endl;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Book& book)
    {
        return book.display(os);
    }

    void Book::cleanUp()
    {
        delete _price;
        _price = nullptr;
    }
}
