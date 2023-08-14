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

void solve(){
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> a(n);

    for (int i=0;i<n;i++){
        std::cin >> a[i].first >> a[i].second;
    }

    double low = 0;
    double high = 1e5 + 1;

    for (int i=0;i<100;i++){
        if (high - low < 1e-6) break;
        auto mid = (low + high) / 2;

        std::vector<double> v(n);
        for (int i=0;i<n;i++){
            v[i] = a[i].first - mid * a[i].second;
        }

        std::sort(v.rbegin(), v.rend());
        auto sum = std::accumulate(v.begin(), v.begin() + k, 0.0);

        if (sum >= 0)
            low = mid;
        else 
            high = mid;
    }

    std::cout << std::setprecision(10) << low << '\n';
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

