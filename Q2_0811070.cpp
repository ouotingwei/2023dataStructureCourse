#include<iostream>

using namespace std;

int inputSize();
int inputLeaves();
int FindMaxJump(int[], int n);

int main(int argc, char **argv){
    int maxJump = 0;
    int row = inputSize();
    int column = inputSize();
    int leaves2d[row][column] = {0};

    for( int i = 0; i < row; i++){
        for( int j = 0; j < column; j++){
            //cout << i << " " << j << " :" ;
            leaves2d[i][j] = inputLeaves();
        }
    }

    /*
    for(int i = 0; i < row; i++){
        int leaves[column] = {0};
        int tempMaxJump = 0;

        for(int j = 0; j < column; j++){
            leaves[j] = leaves2d[i][j];
        }

        tempMaxJump = FindMaxJump(&leaves[0], column);
        if(tempMaxJump > maxJump){
            maxJump = tempMaxJump;
        }

    }
    */

    for(int i = 0; i < column; i++){
        int leaves[row] = {0};
        int tempMaxJump = 0;

        for(int j = 0; j < row; j++){
            leaves[j] = leaves2d[j][i];
        }

        tempMaxJump = FindMaxJump(&leaves[0], row);
        if(tempMaxJump > maxJump){
            maxJump = tempMaxJump;
        }
    }

    cout << maxJump << endl;

    return 0;
}

int inputSize(){
    int input = 0;
    cin >> input;
    if ( input >= 1 && input <= 1000 ){
        return input;
    }else{
        cout << "[W]input error !" << endl;
        return inputSize();
    }
}

int inputLeaves(){
    int input = 0;
    cin >> input;
    if( input >= -1 && input <= 1 ){
        return input;
    }else{
        cout << "[W]input error !" << endl;
        return inputLeaves();
    }

}

int FindMaxJump(int *leaves, int n){
    int maleCNT = 0;
    int cnt = 0;
    int maxjump = 0;

    for(int i=0; i<n; i++){
        if(*(leaves + i) == 1){
            maleCNT ++ ;
        }
    }

    int locationMale[maleCNT] = {0};

    for(int i=0; i<n; i++){
        if(*(leaves + i) == 1){
            locationMale[cnt] = i;
            cnt++;
        }
    }
    
    //from left to right
    for(int i=0; i<maleCNT; i++){
        int start = locationMale[i];
        int jump = 0;
        bool flag = true;
        cnt = start;
        while(flag == true){
            if(cnt == n - 1 && *(leaves + cnt) != -1){
                flag = false;
                //cout << "touch1" << endl;
            }else if(*(leaves + cnt + 1) == 1){
                flag = false;
                //cout << "touch2" << endl;
            }else if(*(leaves + cnt) == -1){
                jump = cnt - start - 1;
                //cout << jump << endl;
                //cout << "touch3" << endl;
                flag = false;
            }

            cnt ++;
        }

        flag = true;
        if(jump > maxjump){
            maxjump = jump;
            //cout <<"maxjump = "<<maxjump << endl;
        }
        
    }
    
    //from right to left
    for(int i=(maleCNT-1); i>=0; i--){
        int start = locationMale[i];
        int jump = 0;
        bool flag = true;
        cnt = start;
        while(flag == true){
            if(cnt == 0 && *(leaves + i) != -1){
                flag = false;
                //cout << "touch1" << endl;
            }else if(*(leaves + cnt - 1) == 1){
                flag = false;
                //cout << "touch2" << endl;
            }else if(*(leaves + cnt) == -1){
                jump = start - (cnt+1);
                //cout << jump << endl;
                //cout << "touch3" << endl;
                flag = false;
            }

            cnt --;
        }

        flag = true;
        if(jump > maxjump){
            maxjump = jump;
        }
        
    }
    return maxjump;
}


