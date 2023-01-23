//Name: Sangwoo Shin
//ID: 119294213
//Email: sshin36@myseneca.ca
//Date: 2022-09-23
//Professof: Hong Huang
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_NO_SECURE_WARNGINGS
#include "TennisLog.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

namespace sdds
{
    void extractChar(std::istream& is, char ch)
    {
        if(is.peek() == ch)
        {
            is.ignore();
        }
        else
        {
            is.ignore(1000, ch);
        }
    }

    TennisLog::TennisLog() {};

    TennisLog::TennisLog(const char* fileName)
    {
        std::string str;
        std::ifstream file(fileName);
        unsigned int index = 0;
        if (file.is_open() == false)
        {
            std::cout << "Cannot open file [" << fileName << "]. \n";
        }
        else
        {
            file.seekg(56); // not to read header
            while(file)
            {
                std::getline(file, str, '\n');
                if(str != "") // to remove empty line
                {
                    index++;
                }
                numOfMatch = index;
            }
            match = new TennisMatch[numOfMatch];
            file.clear();
            file.seekg(56);
            index = 0;
        }
        
        while(index < numOfMatch)
        {
            std::getline(file, str, ',');
            match[index].tournament_ID = str;
            std::getline(file, str, ',');
            match[index].tournament_Name = str;
            file >> match[index].match_ID;
            extractChar(file, ',');
            std::getline(file, str, ',');
            match[index].winner = str;
            std::getline(file, str, '\n');
            match[index].loser = str;
            index++;
        }
        file.close();
    }

    void TennisLog::addMatch(const TennisMatch& newMatch)
    {
        TennisMatch* temMatch {};
        delete[] temMatch;
        temMatch = new TennisMatch[numOfMatch + 1];
        if(numOfMatch != 0)
        {
            for(unsigned int i = 0; i < numOfMatch; i++)
            {
                temMatch[i] = match[i];
            }
        }
        temMatch[numOfMatch] = newMatch;
        delete[] match;
        match = temMatch;
        temMatch = nullptr;
        numOfMatch++;
    }

    TennisLog TennisLog::findMatches(std::string name)
    {
        TennisLog find {};
        for(unsigned int i = 0; i < numOfMatch; i++)
        {
            if(match[i].winner == name || match[i].loser == name)
            {
                find.addMatch(match[i]);
            }
        }
        
        return find;
    }

    TennisMatch TennisLog::operator[](size_t index)
    {
        TennisMatch game;
       if(numOfMatch > 0)
       {
           game = match[index];
       }
        return game;
    }

    TennisLog::operator size_t() const
    {
        return numOfMatch;
    }

    std::ostream& TennisMatch::display(std::ostream& os) const
    {
        if(this->match_ID == 0)
        {
            std::cout << "Empty Match";
        }
        else
        {
            std::cout << std::right << std::setw(20);
            std::cout.fill('.');
            std::cout << "Tourney ID" << " : " << std::left << std::setw(30);
            std::cout.fill('.');
            std::cout << this->tournament_ID << std::endl;
            std::cout << std::right << std::setw(20);
            std::cout.fill('.');
            std::cout << "Match ID" << " : " << std::left << std::setw(30);
            std::cout.fill('.');
            std::cout << this->match_ID << std::endl;
            std::cout << std::right << std::setw(20);
            std::cout.fill('.');
            std::cout << "Tourney" << " : " << std::left << std::setw(30);
            std::cout.fill('.');
            std::cout << this->tournament_Name << std::endl;
            std::cout << std::right << std::setw(20);
            std::cout.fill('.');
            std::cout << "Winner" << " : " << std::left << std::setw(30);
            std::cout.fill('.');
            std::cout << this->winner << std::endl;
            std::cout << std::right << std::setw(20);
            std::cout.fill('.');
            std::cout << "Loser" << " : " << std::left << std::setw(30);
            std::cout.fill('.');
            std::cout << this->loser << std::endl;
        }
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const TennisMatch& games)
    {
        return games.display(os);
    }
    TennisLog::~TennisLog()
    {
        delete[] match;
        match = nullptr;
    }

    TennisLog::TennisLog (TennisLog& log) // copy constructor
    {
        *this = log;
    }

    
    TennisLog& TennisLog::operator=(const TennisLog& log) // copy assignment
    {
      
      if (this != &log) // self-asignment check
      {
            if (this->match)
            {
                delete[] this->match;
                match = nullptr;
            }
            this->numOfMatch = log.numOfMatch;
            this->match = new TennisMatch[numOfMatch];
            for(auto i = 0u; i < log.numOfMatch; i++)
            {
                this->match[i] = log.match[i];
            }
      }
        return *this;
    }
    TennisLog::TennisLog(TennisLog&& log) // move constructor
    {
        *this = std::move(log);
    }
    
    TennisLog& TennisLog::operator=(TennisLog&& log) // move assignement
    {
      if (this != &log)  // self-asignment check
      {
        this->numOfMatch = log.numOfMatch;
        if (this->match)
        {
            delete[] this->match;
        }
        this->match = log.match;
        log.match = nullptr;
          log.numOfMatch = 0;
      }
      return *this;
    }
}
