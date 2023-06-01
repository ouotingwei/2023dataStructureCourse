#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct{
    int noise;
    int edge1;
    int edge2;
}street;

int C, S, Q;
bool compare(street , street);
vector<street> input();
int find_root(int *, int);
void unionset(int *, int, int);
int find_minimum(vector<street>, int , int);

int main(){
    cin >> C >> S >> Q;
    vector<street> st = input();

    int ans[Q];
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        ans[i] = find_minimum(st, a, b);
    }

    for(int i = 0; i < Q; i++){
        if(ans[i] == -1){
            cout << "no path" << endl;
        }else{
            cout << ans[i] << endl;
        }
    }

    return 0;
}

bool compare(street a, street b){
    return a.noise < b.noise;
}

vector<street> input(){
    vector<street> q;
    int a, b, cost = 0;
    for(int i = 0; i < S; i++){
        street input;
        cin >> a >> b >> cost;
        input.noise = cost;
        input.edge1 = a;
        input.edge2 = b;
        q.push_back(input);
    }

    sort(q.begin(), q.end(), compare);
    return q;
}

int find_root(int *rootTree, int p){
    if(rootTree[p] != p){
        int root = find_root(rootTree, rootTree[p]);
        rootTree[p] = root;
        return root;
    }else{
        return p;
    }
}

void unionset(int *rootTree, int ed1, int ed2){
    int roota = find_root(rootTree, ed1);
    int rootb = find_root(rootTree, ed2);

    if(roota != rootb){
        rootTree[roota] = rootb;
    }
}

int find_minimum(vector<street> st, int a, int b){
    int rootTree[C];
    for(int i = 0; i < C; i++){
        rootTree[i] = i;
    }

    int ed1, ed2, min = -1;
    for(int i = 0; i < S; i++){
        ed1 = st[i].edge1-1;
        ed2 = st[i].edge2-1;
        unionset(rootTree, ed1, ed2);
        if(find_root(rootTree, a-1) == find_root(rootTree, b-1)){
            min = st[i].noise;
            break;
        }
    }

    return min;
}