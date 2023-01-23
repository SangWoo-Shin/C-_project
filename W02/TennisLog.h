//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-09-23
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef TennisLog_h
#define TennisLog_h

#define _CRT_NO_SECURE_WARNGINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

namespace sdds
{
    void extractChar(std::istream& is, char ch);

    struct TennisMatch
    {
        std::string tournament_ID {};
        std::string tournament_Name {};
        unsigned int match_ID {};
        std::string winner {};
        std::string loser {};
        std::ostream& display(std::ostream& os) const;
    };
    std::ostream& operator <<(std::ostream& os, const TennisMatch& games);


    class TennisLog
    {
        unsigned int numOfMatch {0u};
        TennisMatch* match {nullptr};
    public:
        TennisLog();
        TennisLog(const char* fileName);
        void addMatch(const TennisMatch& newMatch);
        TennisLog findMatches(std::string name);
        TennisMatch operator[](size_t);
        operator size_t() const;
        ~TennisLog(); // destructor
        TennisLog (TennisLog& log); // copy constructor
        TennisLog& operator=(const TennisLog& log); // copy assignment
        TennisLog(TennisLog&& log); // move constructor
        TennisLog& operator=(TennisLog&& log); // move assignment
    };
}

#endif /* TennisLog_h */
