#include<iostream>
#define MAX_TERMS 100

using namespace std;

typedef struct{
    float coef;
    int expon;

}polinomial;

polinomial terms[MAX_TERMS];
int avail = 0;

int scanNumberOfTerm();
int scanPolynomial();
void add();

int main(int argc, char **argv){
    add();

    return 0;
}

int scanNumberOfTerm(){
    int input= 0;
    cin >> input;

    if( input >= 1 && input <= 99 ){
        return input;
    }else{
        cout << "[W]input error !" << endl;
        return scanNumberOfTerm();
    }

}

int scanPolynomial(){
    int input= 0;
    cin >> input;

    if(input >= -1000 && input <= 1000){
        return input;
    }else{
        cout << "[W]input error !" << endl;
        return scanPolynomial();
    }
}

void add(){
    int m = scanNumberOfTerm();
    int n = scanNumberOfTerm();

    
}