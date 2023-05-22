#include<iostream>
#include<queue>

using namespace std;

void cost_input(int **cost, int S){
    for(int i = 0; i < S; i++){
        int a, b, d;
        cin >> a >> b >> d;
        cost[a-1][b-1] = d;
        cost[b-1][a-1] = d;
    }
}

void find_minimum_BFS(int **cost, int start, int end, int S){
    int smallest = 20001;
    bool *visited = new bool[S];
    for(int i = 0; i < S; i++){
        visited[i] = false;
    }

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if(current == end){
            break;
        }

        for(int neighbor = 0; neighbor < S; neighbor++){
            if(cost[current][neighbor] != 0 && cost[current][neighbor] != 20001 && visited[neighbor] == false){
                visited[neighbor] = true;
                if(cost[current][neighbor] < smallest){
                    smallest = cost[current][neighbor];
                }
            
            q.push(neighbor);
            }
        }
    }
    cout << smallest << endl;
}

int main(){
    int C, S, Q;
    cin >> C >> S >> Q;

    int **cost = new int*[C];
    for(int i = 0; i < C; i++){
        cost[i] = new int[C];
    }

    for(int i = 0; i < C; i++){
        for(int j = 0 ; j < C; j++){
            if(i == j){
                cost[i][j] = 0;
            }else{
                cost[i][j] = 20001;
            }  
        }
    }

    cost_input(cost, S);
    find_minimum_BFS(cost, 1, 7, S);


    return 0;
}