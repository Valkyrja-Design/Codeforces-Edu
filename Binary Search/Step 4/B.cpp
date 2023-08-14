#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
#include <iomanip>

using ll = long long;
using ull = unsigned long long;

constexpr ll MOD = 1e9+7;
constexpr ll MAXN = 100000;

ll inv(long long i){
    return i <= 1 ? i : MOD - (MOD / i) * inv(MOD % i) % MOD;
}

struct Edge{
    int v;
    int w;
};

bool good(std::vector<double>& dist, const std::vector<std::vector<Edge>>& adj, int n, double m){
    dist.assign(n, INT_MAX);
    dist[0] = 0;
    for (int i=0;i<n;i++){
        for (const auto& [v, w] : adj[i]){
            dist[v] = std::min(dist[v], dist[i] + w - m);
        }
    }

    return dist[n-1] <= 0;
}   

void solve(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<Edge>> adj(n);

    for (int i=0;i<m;i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
    }

    double low = -1;
    double high = 101;
    std::vector<double> dist(n);

    // checking if there is a max weight path with weight >= 0
    // from 0 to n-1
    for (int i=0;i<100;i++){
        if (high - low < 1e-6) break;
        auto mid = (low + high) / 2;    

        if (good(dist, adj, n, mid))
            high = mid;
        else 
            low = mid;
    }

    good(dist, adj, n, high);
    std::vector<int> p(n, -1);
    for (int i=0;i<n;i++){
        for (const auto& [v, w] : adj[i]){
            if (dist[v] == dist[i] + w - high)
                p[v] = i;
        }
    }
    
    std::vector<int> path;
    int u = n - 1;
    while (u != -1){
        path.push_back(u + 1);
        u = p[u];
    }

    std::reverse(path.begin(), path.end());
    std::cout << path.size() - 1 << '\n';
    for (int u : path) std::cout << u << ' ';
    std::cout << '\n';
}      

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--){
        solve();
    }
}

/*

*/

