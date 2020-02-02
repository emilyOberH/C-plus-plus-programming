#include "Work.h"

int Work::counter = 0;

Work::Work(string _description, string _worker)
{
    description = _description;
    worker = _worker;
    counter++;
}

Work::~Work()
{
    counter--;
}

int Work::count()
{
    return counter;
}


void Work::print(ostream &out) const
{
    out << description << " (" << worker << "), cost: ";
}

void PieceWork::print(ostream &out) const
{
    Work::print(out);
    out <<numberOfExecutions*costOfAction; ////
}
void FieldWork::print(ostream &out) const
{
    Work::print(out);
    out << width*length*cost; ////
}
void TimeWork::print(ostream &out) const
{
    Work::print(out);
    out << ((numberOfHours-(numberOfHours/9))*costPerHour); ////
}


double PieceWork::getCost() const{
    return (numberOfExecutions*costOfAction);
}
PieceWork::~PieceWork(){
}

double FieldWork::getCost() const{
    return width*length*cost;
}
FieldWork::~FieldWork(){
}

double TimeWork::getCost() const{
    return ((numberOfHours-(numberOfHours/9))*costPerHour);
}
TimeWork::~TimeWork(){
}
