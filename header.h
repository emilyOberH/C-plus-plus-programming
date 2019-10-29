#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class ShoppingCart{
    string name;
    vector <string> names;
    vector <double> cost;
    static int counter;
    static double totalCostCounter;
    static int itemCounter;

public:
    ShoppingCart(string);
    ShoppingCart(const ShoppingCart &);
    ~ShoppingCart() = default;
    ShoppingCart & operator = (const ShoppingCart &);
    //
    string getCustomer()const;
    void setCustomer(string n);
    void addItem(string name, double cost);
    void removeItem(string given);
    int size()const;
    double totalCost()const;
    int getItemCount()const;
    double& operator[](string s);
    //

    friend ostream& operator<<(ostream&, const ShoppingCart&);
};


#endif // HEADER_H_INCLUDED
