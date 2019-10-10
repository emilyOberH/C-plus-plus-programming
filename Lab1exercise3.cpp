#include <iostream>
#include <cstdio>
using namespace std;

void getVal(int **, int);
void printVal(int **, int);
void sumVal(int **, int **, int);
void productVal(int **, int **, int **, int);

int main(){
    int n = -1;
    while(n<0){
        cout<<"\nEnter a positive length of a square matrix: ";
        cin>>n;
    }

    int **A = new int*[n];
    for(int i=0; i<n; ++i){
        A[i] = new int[n];
    }
    int **B = new int*[n];
    for(int j=0; j<n; ++j){
        B[j] = new int[n];
    }
    int **C = new int*[n];
    for(int k=0; k<n; ++k){
        B[k] = new int[n];
    }

    getVal(A, n);
    getVal(B, n);
    printVal(A, n);
    printVal(B, n);
    sumVal(A, B, n);
    productVal(A, B, C, n);

    delete []A;
    delete []B;
    return 0;
}

void getVal(int **A, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout<<"\nEnter value for value["<<i<<"]["<<j<<"]: ";
            cin>>A[i][j];
        }
    }
}

void printVal(int **A, int n){
    cout<<"\nContents of array:\t"<<endl;;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void sumVal(int **A, int **B, int n){
    cout<<"\nSum of arrays:\t"<<endl;;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout<<A[i][j]+B[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void productVal(int **A, int **B, int **C, int n){
    cout<<"\nProduct of arrays:\t"<<endl;;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            C[i][j] = 0;
            for(int k=0; k<n; ++k){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    printVal(C, n);
}
