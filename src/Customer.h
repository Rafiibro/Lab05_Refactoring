#include <utility>

// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Rental.h"

class Customer {
public:
    Customer();
    explicit Customer( std::string  name );
    virtual void addRental( const Rental& arg );
    virtual std::string getName() const;
    virtual std::string statement();
    std::ostringstream& afficher(std::ostringstream& out);
private:
    int frequentRenterPoints;
    std::string _name;
    std::vector< Rental > _rentals;
    double amount = 0;
};

inline Customer::
Customer() {}

inline Customer::Customer( std::string  name ) : _name(std::move( name )), frequentRenterPoints(0) {}

inline void Customer::addRental( const Rental& arg ) { _rentals.push_back( arg ); }

inline std::string Customer::getName() const { return _name; }

#endif // CUSTOMER_H