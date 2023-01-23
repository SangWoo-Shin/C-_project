/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Car.h"

namespace sdds
{
    Car::Car(std::istream& is)
    {
        std::string str;
        std::getline(is, str, ',');
        std::getline(is, str, ',');
        str.erase(0, str.find_first_not_of(' '));
        maker = str.substr(0, str.find(','));
        maker.erase(maker.find_last_not_of(' ') + 1);
        
        std::getline(is, str, ',');
        str.erase(0, str.find_first_not_of(' '));
        str.substr(0, str.find(','));
        if(str[0] == 'n' || str[0] == ' ' || str.empty() || str[0] == 'u' || str[0] == 'b')
        {
            condi = str.substr(0, str.find(','));
        }
        else
        {
            std::string err = "Invalid record!";
            throw err;
        }
        
        std::getline(is, str, ',');
        str.erase(0, str.find_first_not_of(' '));
        try {
            t_Speed = std::stod(str);
        }
        catch (...) {
            std::string err = "Invalid record!";
            throw err;
        }
    }

    std::string Car::condition() const
    {
        std::string _condition;
        if(condi[0] == 'n' || condi[0] == ' ' || condi[0] == '\0')
        {
            _condition = "new";
        }
        else if(condi[0] == 'u')
        {
            _condition = "used";
        }
        else if(condi[0] == 'b')
        {
            _condition = "broken";
        }
        else
        {
            _condition = "null";
        }
        return _condition;
    }

    double Car::topSpeed() const
    {
        return t_Speed;
    }

    void Car::display(std::ostream& out) const
    {
        out << "| " << std::setw(10) << std::right << maker << " | " <<
        std::setw(6) << std::left << condition() << " | " << std::fixed <<
        std::setprecision(2) << std::setw(6) << topSpeed() << " |";
    }
}


