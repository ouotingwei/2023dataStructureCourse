#include<iostream>

using namespace std;

int **input();
void traversal(int **, int, int);
int C, S, Q;

int main(){
    int **graph = input();
    traversal(graph);

    for(int i = 0; i < Q; i++){
        int start, end;
        cin >> start >> end;
        traversal(graph, start, end);
    }

    return 0;
}

int **input(){
    cin >> C >> S >> Q;

    int **graph = new int*[C];
    for(int i = 0; i < C; i++){
        graph[i] = new int[C];
    }

    for(int i = 0; i < C; i++){
        for(int j = 0 ; j < C; j++){
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < S; i++){
        int a, b, d;
        cin >> a >> b >> d;
        graph[a-1][b-1] = d;
        graph[b-1][a-1] = d;
    }

    return graph;
}

void traversal(int **graph, int start, int end){
    
}