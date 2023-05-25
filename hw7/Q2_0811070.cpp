#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct{
    int noise;
    int edge1;
    int edge2;
}street;

bool compare(street a, street b){
    return a.noise < b.noise;
}

vector<street> input_edge(int s){
    vector<street> p;
    int a, b, cost;
    street input;
    for(int i=0; i<s; i++){
        cin>>a>>b>>cost;
        input.edge1 = a;
        input.edge2 = b;
        input.noise = cost;
        p.push_back(input);
    }

    sort(p.begin(), p.end(), compare);
    return p;
}



int main(){
    int C, S, Q;
    cin >> C >> S >> Q;
    vector<street> path = input_edge(S);
    
    return 0;
}