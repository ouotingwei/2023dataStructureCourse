#include<iostream>
#define MAX_ITEM 100

using namespace std;

typedef struct{
    float coef;
    int expon;
}polynomial;

polynomial terms[MAX_ITEM] = {0};
polynomial outPut[MAX_ITEM] = {0};
int outnow = 0;
void polyadd(int numa, int numb, int starta, int startb);
bool attach(float coef, int expon);

int main(){
    int starta = 0;
    int startb, numa, numb;

    cin >> numa >> numb;
    startb = numa;

    for(int i = 0; i < numa + numb; i++){
        cin >> terms[i].coef;
        cin >> terms[i].expon;
    }

    polyadd(numa, numb, starta, startb);

    return 0;
}

void polyadd(int numa, int numb, int starta, int startb){
    int anow = starta;
    int bnow = startb;
    while( anow < starta + numa && bnow < startb + numb ){
        int expdif = terms[anow].expon - terms[bnow].expon;
        if( expdif == 0 ){
            attach(terms[anow].coef + terms[bnow].coef, terms[anow].expon);
            anow++;
            bnow++;
        }else if( expdif > 0 ){
            attach(terms[anow].coef, terms[anow].expon);
            anow++;
        }else{
            attach(terms[bnow].coef, terms[bnow].expon);
            bnow++;
        }

    }

    for(; anow < starta + numa; anow++){
        attach(terms[anow].coef, terms[anow].expon);
    }

    for(; bnow < startb + numb; bnow++){
        attach(terms[bnow].coef, terms[bnow].expon);
    }

    cout << endl;

    for(int i = 0; i < outnow; i++){
        cout << outPut[i].coef << " " << outPut[i].expon << endl;
    }

    cout << endl;

}

bool attach(float coef, int expon){
    if(coef == 0.){
        return false;
    }
    outPut[outnow].coef = coef;
    outPut[outnow].expon = expon;
    outnow++;

    return true;
}