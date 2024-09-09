#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define inp(arr, n) for (int i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;

class GraphCycleDetector {
private:
    int n, m;
    vector<vector<int>> adjList;
    vector<int> color, parent, cycleNodes, cycleCount, prefixOrder;
    bool cycleDetected = false;

    void dfs(int node, int par) {
        parent[node] = par;
        color[node] = 2;  // Mark as visiting

        for (int neighbor : adjList[node]) {
            if (color[neighbor] == 1) {
                dfs(neighbor, node);
            } else if (color[neighbor] == 2 && neighbor != par) {
                // Cycle detected
                if (!cycleDetected) {
                    int temp = node;
                    while (temp != neighbor) {
                        cycleNodes.push_back(temp);
                        temp = parent[temp];
                    }
                    cycleNodes.push_back(temp);
                    reverse(cycleNodes.begin(), cycleNodes.end());
                }
                cycleCount[node]++;
                cycleCount[parent[neighbor]]--;
                cycleDetected = true;
            }
        }
        color[node] = 3;  // Mark as visited
        prefixOrder.push_back(node);
    }

    void processCycleCounts() {
        for (int node : prefixOrder) {
            cycleCount[parent[node]] += cycleCount[node];
        }
    }

    void countCycleNodes() {
        int cycleNodeCount = 0;
        for (int i = 0; i < n; i++) {
            if (cycleCount[i] > 0) cycleNodeCount++;
        }
        cout << cycleNodeCount << endl;
    }

public:
    void initializeGraph() {
        cin >> n >> m;
        adjList.resize(n + 1);
        color.assign(n + 1, 1);  // Unvisited
        parent.assign(n + 1, 0);
        cycleCount.assign(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adjList[x].push_back(y);
        }
    }

    void detectCycle() {
        for (int i = 1; i <= n; i++) {
            if (color[i] == 1) {
                dfs(i, 0);
            }
        }
    }

    void reportResults() {
        if (cycleDetected) {
            prr(cycleNodes);
        } else {
            cout << "No cycle found\n";
        }

        processCycleCounts();
        countCycleNodes();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    GraphCycleDetector detector;
    detector.initializeGraph();
    detector.detectCycle();
    detector.reportResults();

    return 0;
}
