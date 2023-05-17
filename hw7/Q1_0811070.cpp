#include<iostream>

using namespace std;

void cost_input(int **cost, int S){
    for(int i = 0; i < S; i++){
        int a, b, d;
        cin >> a >> b >> d;
        cost[a-1][b-1] = d;
        cost[b-1][a-1] = d;
    }
}

void allcost(int **cost, int **distance, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            distance[i][j] = cost[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(distance[i][k] + distance[k][j] < distance[i][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                } 
            }
        }
    } 
}

void output(int **distance, int Q){
    int outa[Q] = {0};
    int outb[Q] = {0};
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        outa[i] = a-1;
        outb[i] = b-1;
    }

    for(int i = 0; i < Q; i++){
        if(distance[outa[i]][outb[i]] == 20001){
            cout << "no path" << endl;
        }else{
            cout << distance[outa[i]][outb[i]] << endl;
        }
    }

}

int main(){
    int C, S, Q;
    cin >> C >> S >> Q;

    int **cost = new int*[C];
    int **distance = new int*[C];
    for(int i = 0; i < C; i++){
        cost[i] = new int[C];
        distance[i] = new int[C];
    }

    for(int i = 0; i < C; i++){
        for(int j = 0 ; j < C; j++){
            if(i == j){
                cost[i][j] = 0;
                distance[i][j] = 0;
            }else{
                cost[i][j] = 20001;
                distance[i][j] = 20001;
            }  
        }
    }

    cost_input(cost, S);
    allcost(cost, distance, C);
    output(distance, Q);

    return 0;
}