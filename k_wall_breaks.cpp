#include <bits/stdc++.h>
using namespace std;

/*************************************************MACROS*************************************************************************/
#define int long long
#define pii pair<int, int>
#define inp(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;
/********************************************************************************************************************************/

/*
3 4 
S###
###E
.#..
*/

using state = pair<pii, int>;
#define f first
#define s second
#define inf 1e18
int n, m, k;
vector<string> arr;
vector<vector<vector<int>>> dist;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<state> get_neighbour(state cur) {
    vector<state> res;
    for (int i = 0; i < 4; i++) {
        int nx = cur.f.f + dx[i];
        int ny = cur.f.s + dy[i];
        if (inside(nx, ny)) {
            int nz = cur.s;
            if (arr[nx][ny] == '#') {
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
    dist = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(k + 1, inf)));
    dist[st.f.f][st.f.s][st.s] = 0;
    q.push(st);

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        // Relaxing all neighbors
        for (auto v : get_neighbour(cur)) {
            if (dist[v.f.f][v.f.s][v.s] == inf) {
                dist[v.f.f][v.f.s][v.s] = dist[cur.f.f][cur.f.s][cur.s] + 1;
                q.push(v);
            }
        }
    }
}

void HELP_ME_() {
    cin >> n >> m >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pii st, en;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'S') {
                st = {i, j};
            } else if (arr[i][j] == 'E') {
                en = {i, j};
            }
        }
    }
    bfs({st, 0});
    
    int best_dist = inf;
    for(int i=0; i<=k;i++){
        best_dist = min(best_dist,dist[en.f][en.s][i]);
    }
    cout<<best_dist<<endl;
}

/*************************************************MAIN*************************************************************************/
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    HELP_ME_();

    return 0;
}

// Number of Divisors till n  
vector<int> sieve(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= max_n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= max_n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}
