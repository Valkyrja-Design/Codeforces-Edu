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

void solve(){
    int n, m, d;
    std::cin >> n >> m >> d;
    struct Edge{
        int v;
        int w;
    };
    std::vector<std::vector<Edge>> adj(n);

    for (int i=0;i<m;i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
    }
    ll low = -1;
    ll high = 1e9+1;

    std::vector<bool> visited(n, false);
    std::queue<int> q;
    std::vector<int> dist(n, INT_MAX);
    bool found = false;

    while (low + 1 < high){
        visited.assign(n, false);
        q = {};
        dist.assign(n, INT_MAX);
        auto mid = (low + high) >> 1;
        auto good = [&]() -> bool {
            q.push(0);
            visited[0] = true;
            dist[0] = 0;
            while (!q.empty()){
                int u = q.front();
                q.pop();
                for (const auto& e : adj[u]){
                    if (e.w <= mid && !visited[e.v]){
                        dist[e.v] = dist[u] + 1;
                        visited[e.v] = true;
                        q.push(e.v);
                    }
                }
            }

            return dist[n-1] <= d;
        };

        if (good()){
            high = mid;
            found = true;
        } else{
            low = mid;
        }
    }

    if (!found){
        std::cout << "-1\n";
    } else {
        q = {};
        visited.assign(n, false);
        dist.assign(n, INT_MAX);
        q.push(0);
        visited[0] = true;
        std::vector<int> p(n);
        dist[0] = 0;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (const auto& e : adj[u]){
                if (e.w <= high && !visited[e.v]){
                    dist[e.v] = dist[u] + 1;
                    visited[e.v] = true;
                    p[e.v] = u;
                    q.push(e.v);
                }
            }
        }
        int u = n-1;
        std::vector<int> path;
        while (u){
            path.push_back(u + 1);
            u = p[u];
        }
        path.push_back(1);
        std::reverse(path.begin(), path.end());
        std::cout << path.size() - 1 << '\n';
        for (int u : path) std::cout << u << ' ';
        std::cout << '\n';
    }
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

