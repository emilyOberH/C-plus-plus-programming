#include "header.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ShoppingCart::counter = 0;
double ShoppingCart::totalCostCounter = 0;
int ShoppingCart::itemCounter = 0;

ShoppingCart::ShoppingCart(string n){
        name = n;
    }

ShoppingCart::ShoppingCart(const ShoppingCart &source){
        name = source.name;
    }


string ShoppingCart::getCustomer()const{
    return name;
}

double ShoppingCart::totalCost()const{
    return totalCostCounter;
}

int ShoppingCart::getItemCount()const{
    return itemCounter;
}

double& ShoppingCart::operator[](string s){
    for(int i=0; i<size(); ++i){
        if(s==names[i]){
            return cost[i];
        }
    }
    throw string("\nItem could not be found.");
}

void ShoppingCart::setCustomer(string n){
    name = n;
}

void ShoppingCart::addItem(string name, double c){
    totalCostCounter += c;
    ++itemCounter;
    names.push_back(name);
    cost.push_back(c);
}

void ShoppingCart::removeItem(string given){
    int counter = 0;
    for(unsigned i=0; i<names.size(); ++i){
        if(names[i]==given){
            totalCostCounter -= cost[i];
            --itemCounter;
            for(unsigned j=i; j<names.size()-1; ++j){
                names[i] = names[i+1];
                cost[i] = cost[i+1];
            }
            names.pop_back();
            cost.pop_back();
            ++counter;
        }
    }
    if(counter==0){
        cout<<"Item not found!"<<endl;
    }
}

int ShoppingCart::size()const{
    return names.size();
}

ostream& operator<<( ostream&o, const ShoppingCart&t){
    o <<"Customer: "<<t.getCustomer()<<endl;
    o <<"Items: "<<endl;
    for(int i=0; i<t.size(); ++i){
        cout<<t.names[i]<<", "<<t.cost[i]<<endl;
    }
    o <<"Total cost: "<<t.totalCost();
    return o;
}
