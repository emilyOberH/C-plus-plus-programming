#include <iostream>
#include "Schedule.h"
#include "Work.h"
using namespace std;

int main()
{
    Schedule repairs("Expected repairs of my room", 2000); //budget=2000€
    cout << Work::count(); //0
    try {
        repairs.insert(1, new FieldWork("floor", "John", 4.5, 6, 30)); //4.5x6, 30€
        repairs.insert(2, new FieldWork("walls", "Luke", 21, 2.5, 15)); //21x2.5, 15€
        repairs.insert(1, new PieceWork("electricpoints", "Ben", 7, 20)); //7pcs, 20€
        repairs.insert(4, new TimeWork("cleaning", "Mary", 18, 10)); //18h, 10€
        repairs.insert(4, new PieceWork("lighting", "Tom", 4, 30)); //4pcs, 30€}
    }catch(Schedule::DeficitError &e) {
        cout << e.what(); //lighting too expensive - only 102.50 free money
    }
    cout<<repairs;
    //Expected repairs of my room, total budget: 2000.00, remaining money: 102.50:
    //1. electric points (Ben), cost: 140.00
    //2. floor (Jonh), cost: 810.00
    //3. walls (Luke), cost: 787.50
    //4. cleaning (Mary), cost: 160.00

    cout << Work::count()<<endl; //4
    cout << repairs.summaryCost() << endl; //1897.50
    repairs.removeFirst();
    cout << Work::count()<<endl; //3
    cout << repairs.summaryCost() << endl; //1757.50
    try {
    cout << repairs[1].getCost() << endl; //810.00
    cout << repairs[5].getCost() << endl; //IndexError exception
    } catch(Schedule::IndexError &e) {
    cout << e.what(); //item no. 5 not found
    }
    repairs.clear();
    cout << Work::count(); //0
    return 0;
}
