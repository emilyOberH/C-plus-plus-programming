#include <iostream>
#include <cstdlib>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    ShoppingCart myShopping1("Scott Tiger");
    cout << myShopping1.getCustomer()<<endl; //should be Scott Tiger
    myShopping1.addItem("Notebook", 20);
    myShopping1.addItem("Bag", 100);
    cout << myShopping1.size()<<endl; //should be 2
    cout << myShopping1.totalCost()<<endl; //should be 2100
    cout << myShopping1.getItemCount()<<endl;
    cout<<myShopping1;
    myShopping1["Notebook"] = 1900; //changes the cost of the product

    return 0;
}
