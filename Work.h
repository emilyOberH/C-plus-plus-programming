#ifndef WORK_H_INCLUDED
#define WORK_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Work
{
    public:
        Work(string, string);
        virtual ~Work();

        string getDescription() const { return description; }
        void setDescription(string val) { description = val; }
        string getWorker() const { return worker; }
        void setWorker(string val) { worker = val; }

        static int count();

        virtual double getCost() const = 0;
        virtual void print(ostream&) const; //virtual string getString() const;

    protected:
        string description;
        string worker;
    private:
        static int counter;
};

class PieceWork: public Work{
public:
    PieceWork(string description, string worker, int _numberOfExecutions, double _costOfAction): Work(description, worker){
        numberOfExecutions = _numberOfExecutions;
        costOfAction = _costOfAction;
    }
    ~PieceWork();
    double getCost() const;
    void print(ostream &out) const;

private:
    int numberOfExecutions;
    double costOfAction;

};

class FieldWork: public Work
{
    public:
        FieldWork(string description, string worker, double _width, double _length, double _cost): Work(description, worker){
            width = _width;
            length = _length;
            cost = _cost;
        }
        ~FieldWork();
        double getCost() const;
        void print(ostream &out) const;

    private:
        double width;
        double length;
        double cost;
};

class TimeWork: public Work{
public:
    TimeWork(string description, string worker, int _numberOfHours, double _costPerHour): Work(description, worker){
        numberOfHours = _numberOfHours;
        costPerHour = _costPerHour;
    }
    ~TimeWork();
    double getCost() const;
    void print(ostream &out) const;

private:
    int numberOfHours;
    double costPerHour;
};



#endif // WORK_H_INCLUDED
