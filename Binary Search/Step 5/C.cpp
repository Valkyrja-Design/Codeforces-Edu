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

bool good(const std::vector<ll>& a, const std::vector<ll>& b, ll n, ll k, ll m){
    ll cnt = 0;

    for (auto x : a){
        // we count the elements b_i such that 
        // x + b_i < m -> b_i < m - x
        ll want = m - x;
        auto j = std::lower_bound(b.begin(), b.end(), want) - b.begin();
        cnt += j;
    }

    return cnt <= k - 1;
}

void solve(){
    ll n, k;
    std::cin >> n >> k;

    std::vector<ll> a(n), b(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }
    for (int i=0;i<n;i++){
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    ll low = 0;
    ll high = 1e10;

    while (low + 1 < high){
        auto mid = (low + high) >> 1;

        if (good(a, b, n, k, mid))
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

