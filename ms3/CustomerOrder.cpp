// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-12-03
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"

namespace sdds
{
    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder()
    {
        m_name.clear();
        m_product.clear();
        m_cntItem = 0;
        m_lstItem = nullptr;
    }

    CustomerOrder::CustomerOrder(const std::string& record)
    {
        Utilities utils;
        size_t idx = 0;
        bool more = true;
        bool addItem = true;
        m_cntItem = 0;
        m_lstItem = nullptr;
        if(!record.empty())
        {
            while(more)
            {
                m_name = utils.extractToken(record, idx, more);
                m_product = utils.extractToken(record, idx, more);
                while(addItem)
                {
                    if(m_lstItem == nullptr)
                    {
                        m_lstItem = new Item* [m_cntItem + 1];
                        m_lstItem[0] = new Item(utils.extractToken(record, idx, more));
                        m_cntItem++;
                    }
                    else
                    {
                        Item** tempItem = nullptr;
                        tempItem = new Item* [m_cntItem + 1];
                        for(size_t i = 0; i < m_cntItem; i++)
                        {
                            tempItem[i] = m_lstItem[i];
                        }
                        delete[] m_lstItem;
                        tempItem[m_cntItem] = new Item(utils.extractToken(record, idx, more));
                        m_lstItem = tempItem;
                        m_cntItem++;
                    }
                    if(!more)
                    {
                        addItem = false;
                    }
                }
            }
            if(this->m_widthField < utils.getFieldWidth())
            {
                this->m_widthField = utils.getFieldWidth();
            }
        }
        else
        {
            more = false;
        }
    }

    CustomerOrder::CustomerOrder(CustomerOrder& src)
    {
        throw "Cannot make copies.";
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
    {
        if(this != &src)
        {
            *this = std::move(src);
        }
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
    {
        if(this != &src)
        {
            if(m_lstItem)
            {
                for(size_t i = 0; i < m_cntItem; i++)
                {
                    delete m_lstItem[i];
                }
                delete[] m_lstItem;
            }
            m_lstItem = src.m_lstItem;
            src.m_lstItem = nullptr;
            m_name = src.m_name;
            m_product = src.m_product;
            m_widthField = src.m_widthField;
            m_cntItem = src.m_cntItem;
            src.m_cntItem = 0;
            src.m_name.clear();
            src.m_product.clear();
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder()
    {
        if(m_lstItem)
        {
            for(size_t i = 0; i < m_cntItem; i++)
            {
                delete m_lstItem[i];
                m_lstItem[i] = nullptr;
            }
            delete[] m_lstItem;
            m_lstItem = nullptr;
        }
    }

    bool CustomerOrder::isOrderFilled() const
    {
        bool orderFilled = true;
        for(size_t i = 0; i < m_cntItem; i++)
        {
            if(!m_lstItem[i]->m_isFilled)
            {
                orderFilled = false;
                i = m_cntItem;
            }
        }
        return orderFilled;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const
    {
        bool itemFilled = true;
        for(size_t i = 0; i < m_cntItem; i++)
        {
            if(m_lstItem[i]->m_itemName == itemName)
            {
                if(!m_lstItem[i]->m_isFilled)
                {
                    itemFilled = false;
                    i = m_cntItem;
                }
            }
        }
        return itemFilled;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os)
    {
        bool result = false;
        for (size_t i = 0; i < m_cntItem && !result; i++)
        {
            if (m_lstItem[i]->m_itemName == station.getItemName() && !(m_lstItem[i]->m_isFilled))
            {
                if (station.getQuantity() > 0)
                {
                    station.updateQuantity();
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                    result = true;
                }
                else
                {
                    os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const
    {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            os << "[" << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
            os << std::setfill(' ') << std::setw((int)m_widthField) << std::left
                << m_lstItem[i]->m_itemName << " - ";
            if (m_lstItem[i]->m_isFilled)
            {
                os << "FILLED" << std::right << std::endl;
            }
            else
            {
                os << "TO BE FILLED" << std::right<< std::endl;
            }
        }
    }
}
