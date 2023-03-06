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
void inputPolynomial(int, int);
int expCompare(int, int);
void addPolynomial(int, int);

int main(int argc, char **argv){
    int m, n;

    m = scanNumberOfTerm();
    n = scanNumberOfTerm();  
    inputPolynomial(m, n); // input polynomial
    addPolynomial(m, n);

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

void inputPolynomial(int m, int n){
    for(int i = 0; i < (m + n); i++){
        terms[i].coef = scanPolynomial(); 
        terms[i].expon = scanPolynomial();
    }

}

int expCompare(int expA, int expB) {
    if(expA > expB){
        return 1;
    }else if(expA == expB){
        return 0;
    }else{
        return -1;
    }

}

void addPolynomial(int m, int n){
    int startA = 0;
    int endA = m - 1 ;
    int startB = m;
    int endB = m + n - 1;
    avail = m + n ;
    int i = 0;
    bool flag = true;

    cout << "endA = " << endA << " endB = " << endB << endl;

    while( flag == true ){
        if( startA == endA && startB == endB){
            flag = false;
        }

        cout << "startA = " <<startA << " startB = " << startB << " avail = " << avail << endl;

        switch( expCompare(terms[startA].expon, terms[startB].expon) ){
            case -1: // expA < expB
                terms[avail].coef = terms[startB].coef;
                terms[avail].expon = terms[startB].expon;
                cout << "case -1" << endl;

                if(startA == endA){
                    startB ++;
                }else if(startB == endB){
                    startA ++;
                }else{
                    startB ++;
                }

                break;
            case 0: // expA = expB

                if(startA != startB){
                    terms[avail].coef = ( terms[startA].coef + terms[startB].coef );
                    terms[avail].expon = terms[startB].expon;
                }else{
                    terms[avail].coef = terms[startB].coef ;
                    terms[avail].expon = terms[startB].expon;
                }
                
                if(startA == endA){
                    startB ++;
                }else if(startB == endB){
                    startA ++;
                }else{
                    startA ++;
                    startB ++;
                }
                
                cout << "case 0" << endl;

                break;
            case 1: // expA > expB
                terms[avail].coef = terms[startA].coef;
                terms[avail].expon = terms[startA].expon;
                cout << "case 1" << endl;

                if(startA == endA){
                    startB ++;
                }else if(startB == endB){
                    startA ++;
                }else{
                    startA ++;
                }

                break;
        }

        avail ++;
            
    }

    cout << endl;


    for(int i = (m + n); i < avail; i++){
        cout << terms[i].coef << " " << terms[i].expon << endl;
    }

}

