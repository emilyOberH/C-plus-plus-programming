#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void get(int *, int);
void print(int *, int);
void avg(int *, int);
void mini(int *A, int n);
void maxi(int *A, int n);
void reversed(int *, int);

int main(){
    int n = -1;
    while(n<0){
        cout<<"\nEnter a positive length of an array: ";
        cin>>n;
    }

    int *A = new int[n];
    get(A,n);
    print(A,n);
    avg(A, n);
    mini(A,n);
    maxi(A,n);
    reversed(A,n);

    delete []A;
    return 0;
}

void get(int *A, int n){
    for(int i=0; i<n; ++i){
        cout<<"\nEnter integer #"<<i+1<<" of array: ";
        cin>>A[i];
    }
}


void print(int *A, int n){
    cout<<"\nContents of array: "<<endl;
    for(int i=0; i<n; ++i){
        cout<<A[i]<<"\t";
    }
}

void avg(int *A, int n){
    cout<<"\nArithmetic mean of array: "<<endl;
    int sum = 0;
    double counter = 0.0;
    for(int i=0; i<n; ++i){
        sum+=A[i];
        ++counter;
    }
    cout<<sum/counter;
}

void mini(int *A, int n){
    cout<<"\nSmallest value in array: "<<endl;
    int minVal = A[0];
    for(int i=0; i<n; ++i){
        if(A[i]<minVal){
           minVal=A[i];
        }
    }
    cout<<minVal;
}

void maxi(int *A, int n){
    cout<<"\nBiggest value in array: "<<endl;
    int maxVal = A[0];
    for(int i=0; i<n; ++i){
        if(A[i]>maxVal){
           maxVal=A[i];
        }
    }
    cout<<maxVal;
}

void reversed(int *A, int n){
    cout<<"\nContents of array in reversed order: "<<endl;
    for(int i=n-1; i>=0; --i){
        cout<<A[i]<<"\t";
    }
}
