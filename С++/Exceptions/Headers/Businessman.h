//
// Created by danpe on 08.11.2019.
//

#ifndef EXCEPTIONS_BUSINESSMAN_H
#define EXCEPTIONS_BUSINESSMAN_H

#include <ostream>
#include "Person.h"

struct Payment {
    char * date;
    char * country;
};

class Businessman : public virtual Person {
protected:
    int licenceNumber;
    int paymentSize = 0;
    Payment* payment;
public:
    explicit Businessman(char * surname = "", char * name = "", int birthdayYear = 0,
                         int licenceNumber = 0);

    int getPaymentSize() const;
    void setPaymentSize(int paymentSize);
    int getLicenceNumber() const;
    void setLicenceNumber(int licenceNumber);
    const Payment *getPayment() const;
    void setPayment(Payment *payment);
    char *getDate(int index) const;
    void setDate(char *date, int index);
    char *getCountry(int index) const;
    void setCountry(char *country, int index);

    template <class T>
    friend std::istream &operator>>(std::istream &is, Businessman &businessman);
    friend std::ostream &operator<<(std::ostream &os, const Businessman &businessman);

    void table() override;
};



#endif //EXCEPTIONS_BUSINESSMAN_H
