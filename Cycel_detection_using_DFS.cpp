#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define inp(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;

int n, m;
vector<vector<int>> g;
vector<int> col, parent;
bool is_cycle_present = false;
vector<int> any_Cycle;

void dfs(int node, int par) {
    parent[node] = par;
    col[node] = 2;  // visiting
    
    for (auto v : g[node]) {
        if (col[v] == 1) {
            dfs(v, node);
        } else if (col[v] == 2 && v != par) {
            cout << "Hit : " << node << endl;
            if (!is_cycle_present) {
                int temp = node;
                while (temp != v) {
                    any_Cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_Cycle.push_back(temp);
                reverse(any_Cycle.begin(), any_Cycle.end());
            }
            is_cycle_present = true;
        }
    }
    col[node] = 3;  // visited
}

void find_cycle_in_graph() {
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);  // unvisited
    parent.assign(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) {
            dfs(i, 0);
        }
    }
    
    if (is_cycle_present) {
        prr(any_Cycle);
    } else {
        cout << "No cycle found\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    find_cycle_in_graph();
    return 0;
}
