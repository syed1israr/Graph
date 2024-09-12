#include <bits/stdc++.h>
using namespace std;

/*************************************************MACROS*************************************************************************/
#define int long long
#define pii pair<int, int>
#define inp(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;
/********************************************************************************************************************************/

int n, m;
vector<vector<int>> graph;
vector<int> visited;
vector<int> indeg;
vector<int> topo;

void kahns() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        topo.push_back(curr);
        for(auto v : graph[curr]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                q.push(v);
            }
        }
    }
}

void process_test_case() {
  
    cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    indeg.assign(n + 1, 0);
    topo.clear(); 

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }

    kahns();
    prr(topo);
}


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

// Function to calculate LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

/*************************************************MAIN*************************************************************************/
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        process_test_case();
    }

    return 0;
}
