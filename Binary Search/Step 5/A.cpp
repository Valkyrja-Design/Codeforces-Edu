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

bool good(const std::vector<std::pair<int, int>>& a, ll k, ll m){
    ll cnt = 0;
    for (const auto& [l, r] : a){
        if (m >= l)
            cnt += std::min(m, 1LL * (r + 1)) - l;
    }

    // std::cout << m << ' ' << cnt << '\n';

    return cnt <= k;
}

void solve(){
    ll n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i].first >> a[i].second;
    }

    ll low = -2 * 1e9 - 1;
    ll high = 2 * 1e9 + 1;

    while (low + 1 < high){
        auto mid = (low + high) >> 1;

        if (good(a, k, mid))
            low = mid;
        else 
            high = mid;
    }

    std::cout << low << '\n';
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

