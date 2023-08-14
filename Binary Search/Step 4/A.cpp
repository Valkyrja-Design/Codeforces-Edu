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

std::pair<int, int> good(int n, int d, std::vector<int>& a, double m){
    std::vector<std::pair<double, int>> pref_min(n+1);
    pref_min[0] = {-m, 0};
    double curr = -m;
    for (int i=1;i<=n;i++){
        curr += a[i - 1] - m;
        if (curr < pref_min[i-1].first){
            pref_min[i] = {curr, i};
        } else {
            pref_min[i] = pref_min[i - 1];
        }

        if (i - d >= 0 && pref_min[i - d].first <= curr)
            return {pref_min[i - d].second + 1, i};
    }

    return {-1, -1};
}

void solve(){
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n);
    
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    double low = -1;
    double high = 101;

    std::pair<int, int> ans;
    for (int i=0;i<100;i++){
        auto mid = (low + high) / 2;

        auto p = good(n, d, a, mid);
        if (p.first != -1){
            low = mid;
            ans = p;
        } else{
            high = mid;
        }
    }

    std::cout << ans.first << ' ' << ans.second << '\n';
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

