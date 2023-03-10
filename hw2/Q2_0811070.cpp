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
void mulPolynomial(int, int);

int main(int argc, char **argv){
    int m, n;

    m = scanNumberOfTerm();
    n = scanNumberOfTerm();  
    inputPolynomial(m, n); // input polynomial
    mulPolynomial(m, n);

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

void mulPolynomial(int m, int n){
    int startA = 0;
    int endA = m - 1 ;
    int startB = m;
    int endB = m + n - 1;
    avail = m + n ;
    bool flag = true;
    int Start = 0;

    //cout << "endA = " << endA << " endB = " << endB << endl;

    //multiple
    for(int i = startA; i <= endA; i++){
        for(int j = startB; j <= endB; j++){
            terms[avail].coef = ( terms[i].coef * terms[j].coef );
            terms[avail].expon = ( terms[i].expon + terms[j].expon );
            avail ++;
        }
    }

    //add terms
    Start = avail;
    int exponCNT = terms[m + n].expon;
    while(exponCNT >= 0){
	for(int i = (m + n); i < avail; i++){
	   	if(terms[i].expon == exponCNT){
			terms[Start].coef = terms[Start].coef + terms[i].coef;
			terms[Start].expon = exponCNT;
			flag = false;
		}
	}
	if( flag == false){
		Start ++;
		flag = true;
	}
	exponCNT --;
    }
        
    cout << endl;
    for(int i = avail; i < Start; i++){
        cout << terms[i].coef << " " << terms[i].expon << endl;
    }
   
}
