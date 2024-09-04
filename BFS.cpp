#include <bits/stdc++.h>
using namespace std;

/*************************************************MACROS*************************************************************************/
#define int long long
#define endl "\n"
#define pii pair<int, int>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define inp(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;
/********************************************************************************************************************************/

int n, m;
#define f first
#define s second
using state = pair<int, int>;
vector<vector<char>> arr;
vector<vector<int>> vis;
vector<vector<int>> dist;

int dx[] = {0, 1, 0, -1}; 
int dy[] = {1, 0, -1, 0};

bool is_valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#');
}

vector<state> neighbours(state node) {
    vector<state> neighs;
    for (int k = 0; k < 4; k++) {
        int x = node.f + dx[k];
        int y = node.s + dy[k];
        if (is_valid(x, y)) {
            neighs.push_back({x, y});
        }
    }
    return neighs;
}

void bfs(state start) {
    vis.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, 1e9));

    queue<state> q;
    q.push(start);
    vis[start.f][start.s] = 1;
    dist[start.f][start.s] = 0;

    while (!q.empty()) {
        state current = q.front(); q.pop();

        for (state v : neighbours(current)) {
            if (!vis[v.f][v.s]) {
                vis[v.f][v.s] = 1;
                dist[v.f][v.s] = dist[current.f][current.s] + 1;
                q.push(v);
            }
        }
    }
}

void HELP_ME_() {
    cin >> n >> m;
    arr.resize(n);
    state start, end;

    for (int i = 0; i < n; i++) {
        arr[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                start = {i, j};
            } else if (arr[i][j] == 'F') {
                end = {i, j};
            }
        }
    }

    bfs(start);

    if (dist[end.f][end.s] == 1e9) {
        cout << "Finish is not reachable" << endl;
    } else {
        cout << dist[end.f][end.s] << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    HELP_ME_();
    return 0;
}
