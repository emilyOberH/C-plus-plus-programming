#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool isTriangle(int, int, int);
int perimeter(int, int, int);
double area(int, int, int, int);

int main(){
    char ch = 'y';
    do{
        int a, b, c;
        cout<<"\nEnter value of side a: ";
        cin>>a;
        cout<<"\nEnter value of side b: ";
        cin>>b;
        cout<<"\nEnter value of side c: ";
        cin>>c;

        if(isTriangle(a,b,c)){
            cout<<"\nSides "<<a<<", "<<b<<" and "<<c<<" can be sides of a triangle.";
            cout<<"\nPerimeter of triangle: "<<perimeter(a,b,c);
            cout<<"\nArea of triangle: "<<area(a,b,c,perimeter(a,b,c));
        }else{
            cout<<"\nSides "<<a<<", "<<b<<" and "<<c<<" can NOT be sides of a triangle.";
            cout<<"\nPerimeter could not be found. Not a triangle.";
            cout<<"\nArea could not be found. Not a triangle.";
        }
        cout<<"\n\nRepeat the program?(y/n) ";
        cin.clear();
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    return 0;
}


bool isTriangle(int a, int b, int c){
    int maxVal;
    int min1;
    int min2;
    if(a>=b&&a>=c){
        maxVal = a;
        min1 = b;
        min2 = c;
    }else if(b>=a&&b>=c){
        maxVal = b;
        min1 = a;
        min2 = c;
    }else{
        maxVal = c;
        min1 = a;
        min2 = b;
    }

    if(min1+min2>=maxVal){
        return true;
    }else{
        return false;
    }
}

int perimeter(int a, int b, int c){
    return a+b+c;
}

double area(int a, int b, int c, int peri){
   double s = peri/2.0;
   double area = sqrt(s*(s-a)*(s-b)*(s-c));
   return area;
}
