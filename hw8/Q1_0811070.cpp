#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numActions, vector<vector<int>>& prerequisites) {
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
    
    int count = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        count++;
        
        for (int neighbor : graph[curr]) {
            inDegree[neighbor]--;
            
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return count == numActions;
}

int main() {
    int numActions, numPrerequisites;
    cin >> numActions >> numPrerequisites;
    
    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    
    for (int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    
    if (canFinish(numActions, prerequisites)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
