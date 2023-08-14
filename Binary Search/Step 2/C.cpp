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

void solve(){
    ll n, x, y;
    std::cin >> n >> x >> y;

    ll low = 1;
    ll high = 2 * 1e9;

    while (low < high){
        ll mid = (low + high) >> 1;
        // first copy
        ll can = std::min(x, y) <= mid;
        ll left = std::max(0LL, mid - std::min(x, y));
        can += left / x + left / y;

        if (can >= n)
            high = mid;
        else 
            low = mid + 1;
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
   4 2 3 1 5
*/