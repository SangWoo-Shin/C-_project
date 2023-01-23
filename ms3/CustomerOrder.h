// Name: Sangwoo Shin
// Seneca Student ID: 119294213
// Seneca email: sshin36@myseneca.ca
// Date of completion: 2022-11-25
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CustomerOrder_h
#define CustomerOrder_h
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <iomanip>

namespace sdds
{
    
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder
    {
    private:
        std::string m_name;
        std::string m_product;
        size_t m_cntItem;
        Item** m_lstItem {};
        static size_t m_widthField;
    public:
        CustomerOrder();
        CustomerOrder(const std::string& str);
        CustomerOrder(CustomerOrder& src);
        CustomerOrder(CustomerOrder&& src) noexcept;
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };
}


#endif /* CustomerOrder_h */
