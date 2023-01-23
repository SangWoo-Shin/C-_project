//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-09-18
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_NO_SECURE_WARNINGS
#include "carads.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>

double g_taxrate = 0;
double g_discount = 0;
namespace sdds
{
    void listArgs(int argc, char* argv[])
    {
        std::cout << "Command Line:\n";
        std::cout << "--------------------------\n";
        for (auto i = 0; i < argc; i++)
            std::cout << "  " << i + 1 << ": " << argv[i] << "\n";
        std::cout << "--------------------------\n\n";
    }

    void extractChar(std::istream& is, char ch)
    {
        if(is.peek() == ch)
        {
            is.ignore();
        }
        else
        {
            is.ignore(1000, ch);
            //is.setstate(ios::failbit);
        }
    }
        
    std::istream& Cars::read(std::istream& is)
    {
        std::string str;
        char temStatus {};
        int year;
        double temPrice;
        char discount {};
        
        if(is)
        {
            is >> temStatus;
            status = temStatus;
            extractChar(is, ',');
            std::getline(is, str, ',');
            delete[] brands;
            brands = new char[str.length() + 1];
            strcpy(brands, str.c_str());
            std::getline(is, str, ',');
            delete[] model;
            model = new char[str.length() + 1];
            strcpy(model, str.c_str());
            is >> year;
            manuYear = year;
            extractChar(is, ',');
            is >> temPrice;
            price = temPrice;
            extractChar(is, ',');
            is >> discount;
            discount == 'Y' ? promoDiscount = true : promoDiscount = false;
            extractChar(is, '\n');
        }
        return is;
    }
        
    Cars::Cars() : brands {}, model {}, manuYear{}, price{}, status{}, promoDiscount{} {};

    void Cars::showInfo(void)
    {
        std::cout << ". " << std::setw(10) << brands << "| " << std::setw(15) << model << "| ";
        std::cout << std::setw(5);
        std::cout.precision(2);
        std::cout << manuYear << "|" << std::setw(12);
        std::cout << std::setprecision(2);
        std::cout << std::right << std::fixed << price*(1 + g_taxrate) << "|";
        if(promoDiscount)
        {
            std::cout << std::right << std::setw(12) << std::fixed << std::setprecision(2) << (price * (1 + g_taxrate) * (1 - g_discount));
        }
        std::cout << std::endl;
    }
        
    void Cars::display(bool reset)
    {
        static int index = 1;
        if(reset == true)
        {
            index = 1;
            std::cout << std::left << std::setw(2) << index;
            showInfo();
        }
        else
        {
            if(brands)
            {
                std::cout << std::left << std::setw(2) << index;
                showInfo();
            }
            else
            {
                std::cout << "COUNTER. No Car" << std::endl;
            }
        }
        index++;
    }
    char Cars::getStatus()
    {
        return status;
    }
    
    Cars::operator bool() const
    {
        bool result = false;
        if(status == 'N')
        {
            result = true;
        }
        return result;
    }

    Cars::~Cars()
    {
        delete[] brands;
        delete[] model;
    }

    Cars::Cars(const Cars& old_car)
    {
        strcpy(brands, old_car.brands);
        strcpy(model, old_car.model);
        manuYear = old_car.manuYear;
        price = old_car.price;
        status = old_car.status;
        promoDiscount = old_car.promoDiscount;
    }
    Cars& Cars::operator=(const Cars& old_car)
    {
        if(this != &old_car)
        {
            char* newCarBrand = new char[strlen(old_car.brands) + 1];
            strcpy(newCarBrand, old_car.brands);
            delete[] brands;
            brands = newCarBrand;
            char* newCarModel = new char[strlen(old_car.model) + 1];
            strcpy(newCarModel, old_car.model);
            delete[] model;
            model = newCarModel;
            manuYear = old_car.manuYear;
            price = old_car.price;
            status = old_car.status;
            promoDiscount = old_car.promoDiscount;
        }
        return *this;
    }

    std::istream& operator>>(std::istream& is, Cars& car)
    {
        return car.read(is);
    }

    void operator>>(const Cars& car1, Cars& car2)
    {
        car2 = car1;
    }
}

//[std::getline]
//[std::string::c_str]
//[std::string::length]

