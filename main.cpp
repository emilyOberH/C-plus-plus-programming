#include <iostream>
#include <vector>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    cout << Travel::getSummaryDistance()<<endl; //should be 0
    Travel myTravel("My summer journey", "Lodz", "Paris");
    myTravel.setDistance(1500);
    cout << myTravel.getDistance()<<endl; //should be 1500
    myTravel.addViaPoint("Berin");
    myTravel.setDescription("My longer summer journey");
    myTravel.setDistance(1600);
    cout<<myTravel.size()<<endl; //should be 3

    myTravel[2] = "Berlin"; //changes the city name
    cout<<myTravel; //should print for example:
    //My longer summer journey: 1600km
    //Lodz -> Berlin -> Paris
    Travel yourTravel("Your winter journey", "Warsaw", "Zakopane");
    yourTravel.addViaPoint("Lodz");
    yourTravel.addViaPoint("Poznan");
    yourTravel.addViaPoint("Cracow");
    cout <<endl<< yourTravel[3]<<endl; //shold be Poznan
    yourTravel.removeViaPoint("Poznan");
    yourTravel.setDistance(500);
    cout << yourTravel[3]<<endl; //shold be Cracow
    cout << yourTravel.size()<<endl; //should be 4
    cout << yourTravel<<endl; //should print for example:
    //Your winter journey: 500km
    //Warsaw -> Lodz -> Cracow -> Zakopane
    cout << Travel::getSummaryDistance()<<endl; //should be 2100
    cout << Travel::getSummaryDistance(); //should be 0

    return 0;
}
