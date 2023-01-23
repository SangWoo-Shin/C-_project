// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-12-03
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        Utilities utils;
        ifstream is(file);
        string tmp;
        string itemname;
        string Cur_station;
        string Nex_station;
        size_t pos = 0;
        bool more = true;
        
        utils.setDelimiter('|');
        vector<Workstation*> first;
        while (!is.eof()) {
            getline(is, tmp);
            pos = 0;
            more = true;
            itemname = utils.extractToken(tmp, pos, more);
            Workstation* ws;
            ws = *(find_if(stations.begin(), stations.end(), [&](Workstation* sp) {
                return sp->getItemName() == itemname;
                }));
            m_activeLine.push_back(ws);
            first.push_back(ws);
        }
        is.seekg(ios::beg);
        while (!is.eof())
        {
            getline(is, tmp);
            pos = 0;
            more = true;
            Cur_station = utils.extractToken(tmp, pos, more);
            if (more)
            {
                Workstation* Ws1;
                Workstation* Ws2;
                Nex_station = utils.extractToken(tmp, pos, more);
                Ws2 = *(find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* wp)
                                {
                    return wp->getItemName() == Nex_station;
                    }));

                remove(first.begin(), first.end(), Ws2);
                Ws1 = *(find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* wp)
                                {
                    return wp->getItemName() == Cur_station;
                    }
                ));
                Ws1->setNextStation(Ws2);
            }
        }
        m_cntCustomerOrder = g_pending.size();
        m_firstStation = first.front();
    }
    void LineManager::reorderStations()
    {
        std::vector<Workstation*> temp;
        Workstation* ws;
        temp.push_back(m_firstStation);
        while ((ws = temp.back()->getNextStation()))
        {
            temp.push_back(ws);
        }
        m_activeLine.clear();
        m_activeLine = temp;
    }
    bool LineManager::run(std::ostream& os)
    {
        static size_t cnt{};
        cnt++;

        os << "Line Manager Iteration: " << cnt << endl;
        
        if (!g_pending.empty())
        {
            *m_firstStation += move(g_pending.front());
            g_pending.pop_front();
        }
        
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws)
                 {
            ws->fill(os);
            });
        
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws)
                 {
            ws->attemptToMoveOrder();
            });
        
        return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
    }
    void LineManager::display(std::ostream& os) const
    {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws)
                 {
            ws->display(os);
            });
    }
}
