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

bool good(ll n, ll k, ll m){
    ll cnt = 0;
    for (int i=1;i<=n;i++){
        // num of elements of the form i * j < m
        // j < m / i
        cnt += std::min(n, ((m + i - 1) / i) - 1);
    }

    // std::cout << m << ' ' << cnt << '\n';

    return cnt <= k - 1;
}

void solve(){
    ll n, k;
    std::cin >> n >> k;

    ll low = 0;
    ll high = n * n + 1;

    while (low + 1 < high){
        auto mid = (low + high) >> 1;

        if (good(n, k, mid))
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

