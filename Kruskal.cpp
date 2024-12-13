#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<ll, ll>
#define inp(arr, n) for (ll i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;
#define inf LLONG_MAX
const int MOD = 1e9 + 7;

struct unionFind {
    ll n, component_size, *size, *parent;

    unionFind(ll a) : n(a) {
        size = new ll[n + 1];
        parent = new ll[n + 1];
        initialize();
    }

    void initialize() {
        component_size = n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    ll find(ll x) {
        if (x != parent[x]) {
            return parent[x] = find(parent[x]);
        }
        return x;
    }

    void merge(ll x, ll y) {
        ll xRoot = find(x), yRoot = find(y);
        if (xRoot != yRoot) {
            if (size[xRoot] >= size[yRoot]) {
                parent[yRoot] = xRoot;
                size[xRoot] += size[yRoot];
            } else {
                parent[xRoot] = yRoot;
                size[yRoot] += size[xRoot];
            }
            component_size -= 1;
        }
    }

    void reset() { initialize(); }

    ll componentCount() { return component_size; }
};

vector<vector<pii>> graph(100100);

void PROBLEM_SOLVING_FUNCION_HERE() {
    int n, m;
    cin >> n >> m;

    vector<pair<pii, ll>> edgeList;
    unionFind uf(n);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back({{a, b}, c});
    }

    sort(edgeList.begin(), edgeList.end(), [](const auto& x, const auto& y) {
        return x.second < y.second;
    });

    ll cost = 0, edgeCount = 0;
    for (auto& v : edgeList) {
        int x = v.first.first, y = v.first.second;
        if (uf.find(x) != uf.find(y)) {
            edgeCount++;
            cost += v.second;
            graph[x].push_back({y, v.second});
            graph[y].push_back({x, v.second});
            uf.merge(x, y);
        }
    }

    if (edgeCount != n - 1) cost = -1;
    cout << cost << '\n';

    if (cost != -1) {
        for (int i = 1; i <= n; i++) {
            cout << i << ": ";
            for (auto& edge : graph[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int __runtTime_terror;
    cin >> __runtTime_terror;
    while (__runtTime_terror--) {
        PROBLEM_SOLVING_FUNCION_HERE();
    }

    return 0;
}
