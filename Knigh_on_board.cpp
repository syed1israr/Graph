#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define inp(arr, n) for (int i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;
#define inf LLONG_MAX
const int MOD = 1e9+7;
#define f first
#define s second



/* Knight on a chessboard question 

TC:- 
1
3 3
1 1
2 2
*/
int n, m, x, y, a, b;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

vector<vector<int>> dist;

using state = pii;

bool check(int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

int bfs(int stx, int sty) {
    dist = vector<vector<int>>(n + 1, vector<int>(m + 1, inf));  // +1 for 1-based index
    queue<state> q;
    q.push({stx, sty});
    dist[stx][sty] = 0;
    
    while (!q.empty()) {
        state curr = q.front();
        q.pop();
        
        for (int k = 0; k < 8; k++) {
            int nx = curr.f + dx[k];
            int ny = curr.s + dy[k];
            if (check(nx, ny) && dist[nx][ny] > dist[curr.f][curr.s] + 1) {
                dist[nx][ny] = dist[curr.f][curr.s] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return dist[a][b];  // Return the distance to target
}

void solve() {
    cin >> n >> m >> x >> y >> a >> b;
    
    bfs(x, y);  // Call BFS to populate distances
    
    for(int i = 1; i <= n; i++) {  // 1-based indexing
        for(int j = 1; j <= m; j++) {
            if (dist[i][j] == inf) 
                cout << -1 << " ";  // Print -1 for unreachable cells
            else
                cout << dist[i][j] << " ";  // Print distance
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// Sieve of Eratosthenes
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
