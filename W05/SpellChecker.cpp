/*
 Name: Sangwoo Shin
Email: sshin36@myseneca.ca
ID: 119294213
Section: NFF
Date: 2022-10-16
*/

#include "SpellChecker.h"
namespace sdds
{
    SpellChecker::SpellChecker(const char* filename)
    {
        size_t idx {};
        std::ifstream file(filename);
        if (!file)
        {
            throw "Bad file name!";
        }
        else
        {
            do
            {
                file >> m_badWords[idx] >> m_goodWords[idx];
                idx++;
            } while (file);
            file.close();
        }
    }

    void SpellChecker::operator()(std::string& text)
    {
        for(auto i = 0; i < 6; i++)
        {
            while(text.find(m_badWords[i]) != std::string::npos)
            {
                text.replace(text.find(m_badWords[i]),m_badWords[i].size(), m_goodWords[i]);
                count[i]++;
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const
    {
        std::cout << "Spellchecker Statistics" << std::endl;
        for(int i = 0; i < 6; i++)
        {
            out << std::right << std::setw(15) << m_badWords[i] << ": " << count[i] << " replacements" << std::endl;
        }
    }
}
