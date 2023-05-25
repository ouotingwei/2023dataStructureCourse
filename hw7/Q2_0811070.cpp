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

vector<street> input_edge(int S){
    vector<street> p;
    int a, b, cost;
    
    for(int i=0; i<S; i++){
        cin >> a >> b >> cost;
        street input;
        input.edge1 = a;
        input.edge2 = b;
        input.noise = cost;
        p.push_back(input);
    }

    sort(p.begin(), p.end(), compare);
    return p;
}

int find_root(int *father, int p){
    if(father[p] != p){
        int root = find_root(father, father[p]);
        father[p] = root;
        return root;
    }else{
        return p;
    }
}

void union_set(int *father, int a, int b){
    int root_a = find_root(father, a);
    int root_b = find_root(father, b);
    
    if(root_a != root_b){
        father[root_a] = root_b;
    }
}

int find_minimum_noise(vector<street> st, int C, int S, int a, int b){
    int rootTree[C];
    int ed1, ed2, minNoice = -1;

    for(int i = 0; i < C; i++){
        rootTree[i] = i;
    }

    for(int i=0; i<S; i++){
        ed1 = st[i].edge1 - 1;
        ed2 = st[i].edge2 - 1;
        union_set(rootTree, ed1, ed2);

        if(find_root(rootTree, a-1) == find_root(rootTree, b-1)){
            minNoice = st[i].noise;
            break;
        }
    }

    return minNoice;
}

int main(){
    int C, S, Q, a, b;
    cin >> C >> S >> Q;
    int ANS[Q];

    for(int i=0; i<Q; i++){
        ANS[i] = -1;
    }

    vector<street> graph = input_edge(S);

    for(int i=0; i<Q; i++){
        cin >> a >> b;
        ANS[i] = find_minimum_noise(graph, C, S, a, b);
    }

    for(int i=0; i<Q; i++){
        if(ANS[i] == -1){
            cout << "no path" << endl;
        }else{
            cout << ANS[i] << endl;
        }
    }
    
    return 0;
}