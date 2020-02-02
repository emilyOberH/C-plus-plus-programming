#ifndef SCHEDULE_H
#define SCHEDULE_H

#include<string>
#include<iostream>
#include<list>
#include<stdexcept>

#include "Work.h"

using namespace std;

class Schedule
{
    public:

        class IndexError: public out_of_range
        {
            public:
                IndexError(string msg): out_of_range(msg) {}
        };

        class DeficitError: public logic_error
        {
            public:
                DeficitError(string msg): logic_error(msg) {}
        };

        class EmptyError: public logic_error
        {
            public:
                EmptyError(string msg): logic_error(msg) {}
        };

        Schedule(string, double);
        virtual ~Schedule();

        void insert(unsigned, Work*);
        void removeFirst();
        void clear();
        double summaryCost() const;

        Work& operator[](unsigned);
        friend ostream& operator<<(ostream&, const Schedule&);

    private:
        string description;
        double budget;
        static double sum;
        list<Work*> works;
};



#endif // SCHEDULE_H
