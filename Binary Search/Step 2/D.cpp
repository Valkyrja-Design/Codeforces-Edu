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

using ll = long long;
using ull = unsigned long long;

constexpr ll MOD = 1e9+7;
constexpr ll MAXN = 100000;

ll inv(long long i){
    return i <= 1 ? i : MOD - (MOD / i) * inv(MOD % i) % MOD;
}

struct Info{
    int t;
    int z;
    int y;
};

ll can_inflate(ll t, const Info& info){
    ll can = 0;
    ll bal = std::min(1LL * info.z, t / info.t);
    can += bal;
    ll left = t - info.t * bal;
    // we can inflate zi ballons for yi + zi * ti secs
    bal = (left / (info.y + info.z * info.t));
    left -= bal * (info.y + info.z * info.t);
    can += info.z * bal;
    left = std::max(0LL, left - info.y);
    can += left >= info.z * info.t ? info.z : left / info.t;

    return can;
}

void solve(){
    ll m, n;
    std::cin >> m >> n;
    std::vector<Info> a(n);
    for (auto& x : a){
        std::cin >> x.t >> x.z >> x.y;
    }

    ll low = 0;
    ll high = 1e9;

    while (low < high){
        ll mid = (low + high) >> 1;
        ll can = 0;
        for (int i=0;i<n;i++){
            can += can_inflate(mid, a[i]);
        }

        if (can >= m)
            high = mid;
        else 
            low = mid + 1;
    }
    std::cout << low << '\n';
    for (int i=0;i<n;i++){
        auto can = can_inflate(low, a[i]);
        std::cout << std::min(m, can) << ' ';
        m -= std::min(m, can);
    }
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
   4 2 3 1 5
*/