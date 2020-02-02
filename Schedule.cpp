#include "Schedule.h"
#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include <vector>

double Schedule::sum = 0;


Schedule::Schedule(string d, double b)
{
    description = d;
    budget = b;
}

Schedule::~Schedule()
{
    //dtor
}


Work & Schedule::operator[](unsigned i)
{
    ostringstream s;
    s << i;
    if(i > works.size()) throw IndexError("Result not found.");
    list<Work*>::iterator it = works.begin();
    for(unsigned j = 1; j < i && it != works.end(); j++, it++);
    return **it;//**it; //dereference of the iterator returns SportData*, so the dereference again
}

void Schedule::insert(unsigned i, Work* item){
        list<Work*>::iterator it = works.begin();
        for(unsigned j = 1; j < i && it != works.end(); j++, it++);

        double costItem = (item->getCost());
        if(budget-sum-costItem>=0){
            Schedule::sum += costItem;
            works.insert(it, item);
        }else{
            delete item;
            throw DeficitError("Too expensive");//work on
        }


}

void Schedule::removeFirst(){
    for(auto i: works){
        Schedule::sum -= i->getCost();
        delete i;
        works.erase(works.begin());
        break;
    }
}

void Schedule::clear(){
    for(auto i: works)
        delete i;
    works.clear();
}

double Schedule::summaryCost() const{
    return Schedule::sum;
}


ostream& operator<<(ostream& out, const Schedule& s){
    int j = 1;
    out <<endl<< s.description << ", total budget: " << s.budget<<", remaining money: "<<s.budget-s.sum<<endl;


    for (auto i: s.works)
    {
        out<< j << ". ";
        i->print(out); //polymorphic call
        out << endl;
        ++j;
    }
    return out;
}
