//Name: Sangwoo Shin
//ID: 1199294213
//Email: sshin36@myseneca.ca
//SEction: NDD
//Date:


#ifndef ConfirmationSender_h
#define ConfirmationSender_h
#include "Reservation.h"

namespace sdds
{
    class ConfirmationSender
    {
    private:
        const Reservation** reserve;
        size_t count{};
    public:
        ConfirmationSender() {};
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        std::ostream& display(std::ostream& os) const;
        friend std::ostream& operator <<(std::ostream& os, const ConfirmationSender& sender);
        ConfirmationSender(const ConfirmationSender& src); // copy constructor
        ConfirmationSender& operator= (const ConfirmationSender& src); // copy assignment
        ConfirmationSender(ConfirmationSender &&src); // move constructor
        ConfirmationSender& operator= (ConfirmationSender&& src); // move assignment
        ~ConfirmationSender();
    };
}

#endif /* ConfirmationSender_h */
