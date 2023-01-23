/*
   Name: Sangwoo Shin
   Email: sshin36@myseneca.ca
   ID: 119294213
   date: 2022-11-
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "CrimeStatistics.h"

namespace sdds
{
    CrimeStatistics::CrimeStatistics(const char* fileName)
    {
        std::ifstream file(fileName);
        if(!file)
        {
            std::cerr << "ERROR: Cannot open file [" << fileName << "].\n";
            return;
        }
        else
        {
            Crime tem_crime;
            while(file)
            {
                std::string str {};
                std::getline(file, str, '\n');

                if(str[0] != '\0')
                {
                    tem_crime.province = str.substr(0, 25);
                    tem_crime.province.erase(tem_crime.province.find_last_not_of(' ') + 1);
                    str.erase(0, 25);
                    
                    tem_crime.district = str.substr(0, 25);
                    tem_crime.district.erase(tem_crime.district.find_last_not_of(' ') + 1);
                    str.erase(0, 25);
                    
                    tem_crime.crime = str.substr(0, 25);
                    tem_crime.crime.erase(tem_crime.crime.find_last_not_of(' ') + 1);
                    str.erase(0, 25);
                    
                    tem_crime.year = stoi(str.substr(0, 5));
                    str.erase(0, 5);
                    
                    tem_crime.m_case = stoi(str.substr(0, 5));
                    str.erase(0, 5);
                    
                    tem_crime.m_resolved = stoi(str.substr(0, 5));
                    str.erase(0, 5);
                    
                    arr_Crime.push_back(tem_crime);
                }
            }
        }
    }

    void CrimeStatistics::display(std::ostream& out) const
    {
        for (auto cri : arr_Crime)
        {
            std::cout << cri << std::endl;
        }
        int total {};
        std::for_each(arr_Crime.begin(), arr_Crime.end(), [&total](Crime _crime) {
            total += _crime.m_case;
        });
        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        out << "| " << std::right << std::setw(79) << "Total Crimes:  " << total << " |" << std::endl;
        total = 0;
        std::for_each(arr_Crime.begin(), arr_Crime.end(), [&total](Crime _crime) {
            total += _crime.m_resolved;
        });
        out << "| " << std::right << std::setw(79) << "Total Resolved Cases:  " << total << " |" << std::endl;
    }

    std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
    {
        out << "| " << std::left << std::setw(21) << theCrime.province
        <<  " | " << std::setw(15) << theCrime.district << " | " <<
        std::setw(20) << theCrime.crime << " | " << std::right <<
        std::setw(6) << theCrime.year << " | " << std::setw(4) <<
        theCrime.m_case << " | " << std::setw(3) << theCrime.m_resolved << " |";
        return out;
    }

    void CrimeStatistics::sort(std::string name)
    {
        if(name == "Province")
        {
            std::sort(arr_Crime.begin(), arr_Crime.end(), [](Crime x, Crime y)
            {
                return x.province < y.province;
            });
        }
        else if(name == "Crime")
        {
            std::sort(arr_Crime.begin(), arr_Crime.end(), [](Crime x, Crime y)
            {
                return x.crime < y.crime;
            });
        }
        else if(name == "Cases")
        {
            std::sort(arr_Crime.begin(), arr_Crime.end(), [](Crime x, Crime y)
            {
                return x.m_case < y.m_case;
            });
        }
        else if(name == "Resolved")
        {
            std::sort(arr_Crime.begin(), arr_Crime.end(), [](Crime x, Crime y)
            {
                return x.m_resolved < y.m_resolved;
            });
        }
        else
        {
            throw "Invalid field name!";
        }
    }

    void CrimeStatistics::cleanList()
    {
        std::transform(arr_Crime.begin(), arr_Crime.end(), arr_Crime.begin(), [](Crime token)
        {
                if(token.crime == "[None]")
                {
                    token.crime = "";
                }
            return token;
        });
    }

    bool CrimeStatistics::inCollection(std::string name) const
    {
        auto cnt = std::count_if(arr_Crime.begin(), arr_Crime.end(), [=](const Crime& x)
        {
            return x.crime == name;
        });
        return cnt > 0 ? true : false;
    }

    std::list<Crime> CrimeStatistics::getListForProvince(std::string name) const
    {
        std::list<Crime> _list;
        std::copy_if(arr_Crime.begin(), arr_Crime.end(), back_inserter(_list), [=](const Crime& x)
        {
            return x.province == name;
        });
        return _list;
    }
}
