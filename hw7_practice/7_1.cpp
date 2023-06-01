#include<iostream>

using namespace std;

int C, S, Q;
void input(int **);
void allcost(int **);
void output(int **);

int main(){
    cin >> C >> S >> Q;
    int **cost = new int*[C];
    for(int i = 0; i < C; i++){
        cost[i] = new int[C];
    }

    input(cost);
    allcost(cost);
    output(cost);

    return 0;
}

void input(int **cost){
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            if(i == j){
                cost[i][j] = 0;
            }else{
                cost[i][j] = 20001;
            }
        }
    }

    int a, b, noise;
    for(int i = 0; i < S; i++){
        cin >> a >> b >> noise;
        cost[a-1][b-1] = noise;
        cost[b-1][a-1] = noise;
    }
}

void allcost(int **cost){
    for(int k = 0; k < C; k++){
        for(int i = 0; i < C; i++){
            for(int j = 0; j < C; j++){
                if(cost[i][k] + cost[k][j] < cost[i][j]){
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
}

void output(int **cost){
    int outa[Q];
    int outb[Q];
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        outa[i] = a-1;
        outb[i] = b-1;
    }

    for(int i = 0; i < Q; i++){
        if(cost[outa[i]][outb[i]] == 20001){
            cout << "no path" << endl;
        }else{
            cout << cost[outa[i]][outb[i]] << endl;
        }
    }
}