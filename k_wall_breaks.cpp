#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<ll, ll>
#define inp(arr, n) for (ll i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;
#define inf LLONG_MAX
const int MOD = 1e9+7;
using state = pair<pii,ll>;
#define f first
#define s second
/*
3 4 2
S###
###E
.#..
*/
ll n, m, k;
vector<string> g;
vector<vector<vector<ll>>> dist;

ll dx[] = {0, 1, 0, -1}; 
ll dy[] = {1, 0, -1, 0};

bool inside(ll i, ll j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

vector<state> get_neighbour(state curr) {
    vector<state> res;
    for (ll i = 0; i < 4; i++) {
        ll nx = curr.f.f + dx[i];
        ll ny = curr.f.s + dy[i];
        if (inside(nx, ny)) {
            ll nz = curr.s;
            if (g[nx][ny] == '#') {
                nz++;
            }
            if (nz > k) continue;
            res.push_back({{nx, ny}, nz});
        }
    }
    return res;
}

void bfs(state st) {
    queue<state> q;
    dist = vector<vector<vector<ll>>>(n, vector<vector<ll>>(m, vector<ll>(k + 1, inf)));
    dist[st.f.f][st.f.s][st.s] = 0;
    q.push(st);
    
    while (!q.empty()) {
        state curr = q.front();
        q.pop();
        for (auto v : get_neighbour(curr)) {
            if (dist[v.f.f][v.f.s][v.s] > dist[curr.f.f][curr.f.s][curr.s] + 1) {
                dist[v.f.f][v.f.s][v.s] = dist[curr.f.f][curr.f.s][curr.s] + 1;
                q.push(v);
            }
        }
    }
}

void PROBLEM_SOLVING_FUNCION_HERE() {
    cin >> n >> m >> k;
    g.resize(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> g[i];
    }
    
    pii st, en;
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (g[i][j] == 'S') {
                st = {i, j};
            } else if (g[i][j] == 'E') {
                en = {i, j};
            }
        }
    }
    bfs({st, 0});
    
    ll best_dist = inf;
    for (ll i = 0; i <= k; i++) {
        best_dist = min(best_dist, dist[en.f][en.s][i]);
    }
    cout << best_dist << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

 
    
     PROBLEM_SOLVING_FUNCION_HERE();

    return 0;
}


