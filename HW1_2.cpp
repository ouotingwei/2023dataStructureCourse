#include<iostream>

using namespace std;

int m, n;
void input2dSize();

int main(int argc, char **argv){
    input2dSize();
    int leaves[n][m];
    

    return 0;
}

void inputLeaves(){
    cin >> m >> n;
    if ( m >= 1 && m <= 1000 && n >= 1 && n <= 1000 ){
        return 0;
    }else{
        cout << "[W]input error !" << endl;
        return inputN();
    }
}


