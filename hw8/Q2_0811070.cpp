#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numActions, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numActions);
    vector<int> inDegree(numActions, 0);
    
    for (const auto& prerequisite : prerequisites) {
        int ai = prerequisite[0];
        int bi = prerequisite[1];
        
        graph[bi].push_back(ai);
        inDegree[ai]++;
    }

    queue<int> q;
    
    for (int i = 0; i < numActions; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> order;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        order.push_back(curr);
        
        for (int neighbor : graph[curr]) {
            inDegree[neighbor]--;
            
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if (order.size() == numActions) {
        return order;
    } else {
        return vector<int>(); 
    }
}

int main() {
    int numActions, numPrerequisites;
    cin >> numActions >> numPrerequisites;
    
    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    
    for (int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    
    vector<int> order = findOrder(numActions, prerequisites);
    
    if (order.empty()) {
        cout << -1 << endl;
    } else {
        for (int action : order) {
            cout << action << " ";
        }
        cout << endl;
    }
    
    return 0;
}
