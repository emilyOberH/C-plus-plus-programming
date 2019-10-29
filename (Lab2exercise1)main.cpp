#include <iostream>
#include <cstdlib>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    ShoppingCart myShopping1("Scott Tiger");
    cout << myShopping1.getCustomer()<<endl; 
    myShopping1.addItem("Notebook", 20);
    myShopping1.addItem("Bag", 100);
    cout << myShopping1.size()<<endl; 
    cout << myShopping1.totalCost()<<endl; 
    cout << myShopping1.getItemCount()<<endl;
    cout<<myShopping1;
    myShopping1["Notebook"] = 1900; 

    return 0;
}
