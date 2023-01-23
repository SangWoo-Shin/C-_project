/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-6
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Van.h"

namespace sdds
{
    Van::Van(std::istream& is)
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
        if(str[0] == 'p' || str[0] == 'm' || str[0] == 'c')
        {
            _type = str;
        }
        else
        {
            throw "Invalid record!";
        }
        
        std::getline(is, str, ',');
        str.erase(0, str.find_first_not_of(' '));
        str.substr(0, str.find(','));
        if(str[0] == 'd' || str[0] == 'p' || str[0] == 'c')
        {
            purpose = str;
            str.erase(0, str.find(',') + 1);
        }
        else
        {
            throw "Invalid record!";
        }
        
        std::getline(is, str, ',');
        str.erase(0, str.find_first_not_of(' '));
        str.substr(0, str.find(','));
        if(str[0] == 'n' || str[0] == ' ' || str[0] == '\0' || str[0] == 'u' || str[0] == 'b')
        {
            condi = str;
            str.erase(0, str.find(',') + 1);
        }
        else
        {
            throw "Invalid record!";
        }
        
        std::getline(is, str, ',');
        str.erase(0, str.find_first_not_of(' '));
        t_Speed = std::stod(str.substr(0, str.find('\n')));
    }

    std::string Van::condition() const
    {
        std::string _condition;
        switch(condi[0])
        {
            case 'n':
                _condition = "new";
                break;
            case 'u':
                _condition = "used";
                break;
            case 'b':
                _condition = "broken";
                break;
            default:
                _condition = "null";
                break;
        }
        return _condition;
    }

    double Van::topSpeed() const
    {
        return t_Speed;
    }

    std::string Van::type() const
    {
        std::string type_;
        switch(_type[0])
        {
            case 'p':
                type_ = "pickup";
                break;
            case 'm':
                type_ = "mini-bus";
                break;
            case 'c':
                type_ = "camper";
                break;
            default:
                type_ = "null";
                break;
        }
        return type_;
    }

    std::string Van::usage() const
    {
        std::string _purpose;
        switch(purpose[0])
        {
            case 'd':
                _purpose = "delivery";
                break;
            case 'p':
                _purpose = "passenger";
                break;
            case 'c':
                _purpose = "camping";
                break;
            default:
                _purpose = "null";
                break;
        }
        return _purpose;
    }

    void Van::display(std::ostream& out) const
    {
        out << "| " << std::setw(8) << std::right << maker << " | " <<
        std::setw(12) << std::left << type() << " | " << std::setw(12) << usage()
        << " | " << std::setw(6) << condition() << " | " << std::fixed <<
        std::setprecision(2) << std::setw(6) << topSpeed() << " |";
    }
}
