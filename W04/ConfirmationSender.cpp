//Name: Sangwoo Shin
//ID: 1199294213
//Email: sshin36@myseneca.ca
//SEction: NDD
//Date:

#include "ConfirmationSender.h"

namespace sdds
{
ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
{
    for(size_t i = 0; i < count; i++)
    {
        if(reserve[i] == &res)
        {
            return *this;
        }
    }
    const Reservation** tem = new const Reservation*[count + 1];
    for(size_t i = 0; i < count; i++)
    {
        tem[i] = reserve[i];
    }
    tem[count] = &res;
    if(count > 0)
    {
        delete[] reserve;
        reserve= nullptr;
    }
    reserve = tem;
    count++;
    
    return *this;
}

ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
{
    bool found = false;
    for (size_t i = 0; i < count && !found; i++)
    {
        if (reserve[i] == &res)
        {
            found = true;
            reserve[i] = nullptr;
            for(size_t foundIdx = i; foundIdx < count - 1; foundIdx++)
            {
                reserve[foundIdx] = reserve[foundIdx + 1];
            }
        }
    }
    if (found)
    {
        const Reservation** tem = new const Reservation*[count - 1];
        for (size_t i = 0; i < count - 1; i++)
        {
            tem[i] = reserve[i];
        }
        delete[] reserve;
        reserve = nullptr;
        reserve = tem;
        count--;
    }
    return *this;
}
std::ostream& ConfirmationSender::display(std::ostream& os) const
{
    os << "--------------------------\n" << "Confirmations to Send" << std::endl;
    os << "--------------------------" << std::endl;
    if(count > 0)
    {
        for(size_t i = 0; i <count; i++)
        {
            os << *reserve[i];
        }
    }
    else
    {
        os << "There are no confirmations to send!" << std::endl;
    }
    os << "--------------------------" << std::endl;
    return os;
}

    std::ostream& operator <<(std::ostream& os, const ConfirmationSender& sender)
    {
        return sender.display(os);
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
    {
        *this = src;
    }

    ConfirmationSender& ConfirmationSender::operator= (const ConfirmationSender& src)
    {
        if(this != &src)
        {
            if(count != 0)
            {
                delete[] reserve;
                reserve = nullptr;
            }
            count = src.count;
            reserve = new const Reservation*[src.count];
            for(size_t i = 0; i < count; i++)
            {
                reserve[i] = src.reserve[i];
            }
        }       
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender &&src)
    {
        *this = std::move(src);
    }

    ConfirmationSender& ConfirmationSender::operator= (ConfirmationSender&& src)
    {
        if(this != &src)
        {
            if(count != 0)
            {
                delete[] reserve;
                reserve = nullptr;
            }
            reserve = src.reserve;
            count = src.count;
            src.reserve = nullptr;
            src.count = 0;
        }
        return *this;
    }

    ConfirmationSender::~ConfirmationSender()
    {
        if(reserve)
        {
            delete[] reserve;
            reserve = nullptr;
        }
    }
}
