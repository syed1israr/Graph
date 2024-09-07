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

const int inf = 1e9;

void HELP_ME_(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> graph[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // u --> v with weight
        graph[u].push_back({v, w});
    }

    vector<int> dist(n + 1, inf);
    vector<bool> marked(n + 1, false);

    dist[1] = 0;

    priority_queue<pair<int, int>> q;

    q.push({-dist[1], 1});

    while (!q.empty()) {
        int curr = q.top().second;
        q.pop();

        if (marked[curr]) continue;
        marked[curr] = true;

        for (auto it : graph[curr]) {
            int v = it.first;
            int w = it.second;
            if (dist[curr] + w < dist[v]) {
                dist[v] = dist[curr] + w;
                q.push({-dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
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
