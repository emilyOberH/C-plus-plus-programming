#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class Travel{
    string description;
    string startP;
    string endP;
    double distance;
    vector <string> additionalPoints;
    static double allDist;

public:
    Travel(string, string, string);
    Travel(const Travel&);
    ~Travel()= default;

    //
    void setDescription(string);
    string getDescription()const;
    void setDistance(double);
    double getDistance()const;
    void addViaPoint(string);
    void removeViaPoint(string);
    int size();
    static double getSummaryDistance();
    //

    string &operator[](int);
    friend ostream&operator<<(ostream&, const Travel&);

};

#endif // HEADER_H_INCLUDED
