// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
    template<typename T>
    class GeneratingList {

        std::vector<T> list;
    public:

        GeneratingList(){}
        GeneratingList(const char* f) {
            std::ifstream file(f);
            if (!file)
                throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

            while (file) {
                T t;
                if (t.load(file))
                    list.push_back(T(t));
            }
        }

        size_t size() const { return list.size(); }
        const T& operator[](size_t i) const { return list[i]; }

        //TODO: Implement the Luhn Algorithm to check the
        //      valadity of SIN No's
        bool validationSIN(const std::string num)
        {
            bool valid = false;
            int sum {};
            std::string temNum;
            for(auto i = num.length(); i > 0; i--)
            {
                temNum = num[i - 1];
                if((num.length() - i) % 2 == 0)
                {
                    sum += std::stoi(temNum);
                }
                else
                {
                    if(2 * std::stoi(temNum) >= 10)
                    {
                        sum += (2 * std::stoi(temNum) - 9);
                    }
                    else
                    {
                        sum += 2 * std::stoi(temNum);
                    }
                }
            }
            if(sum % 10 == 0)
            {
                valid = true;
            }
            
            return valid;
        }

        //TODO: Overload the += operator with a raw pointer
        // as a second operand.
        void operator+= (const T* object)
        {
            list.push_back(*object);
        }
        
        //TODO: Overload the += operator with a smart pointer
        // as a second operand.
        void operator+=(const std::unique_ptr<T>& object)
        {
            list.push_back(*object);
        }
        
        void print(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.print(os);
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
        rd.print(os);
        return os;
    }
}
#endif // !SDDS_GENERATINGLIST_H
