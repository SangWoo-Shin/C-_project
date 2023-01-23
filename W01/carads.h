//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-09-18
//Professor: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef carads_h
#define carads_h

#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>


extern double g_taxrate;
extern double g_discount;

namespace sdds
{
    void listArgs(int argc, char** argv);
    void extractChar(std::istream& is, char ch);

    class Cars
    {
    private:
        char* brands {};
        char* model {};
        int manuYear {};
        double price {};
        char status {};
        bool promoDiscount {};
    public:
        Cars();
        Cars(const Cars& old_car);
        Cars& operator=(const Cars& old_car);
        std::istream& read(std::istream& is);
        void showInfo(void);
        void display(bool reset);
        char getStatus();
        friend void operator>>(const Cars& car1, Cars& car2);
        operator bool() const;
        ~Cars();
    };
    std::istream& operator>>(std::istream& is, Cars& car);


}


#endif /* carads_h */
