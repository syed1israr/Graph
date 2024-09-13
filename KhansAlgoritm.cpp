#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define inp(arr, n) for (int i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;
const int inf = LLONG_MAX;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> graph;
vector<int> indeg;
vector<int> topo;

void bfs() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for (auto v : graph[curr]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
}

void PROBLEM_SOLVING_FUNCION_HERE() {
    // Problem-solving logic goes here
    cin >> n >> m;
    graph.resize(n);
    indeg.assign(n, 0);
    topo.clear();  // Reset the topo vector
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        indeg[y]++;
    }
    
    bfs();
    if(topo.size() !=n){
        cout<<"Hey there is a Cycle , remove it please"<<endl;
    }
    prr(topo);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    PROBLEM_SOLVING_FUNCION_HERE();

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

// LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}
