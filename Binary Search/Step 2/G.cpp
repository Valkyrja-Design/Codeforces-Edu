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

bool good(int k, int n, const std::vector<ll>& v, ll m){
    ll sum = 0;
    // the number of councils it can contribute to 
    for (auto x : v){
        sum += std::min(x, m);
    }

    return sum >= m * k;
}

void solve(){
    int k, n;
    std::cin >> k >> n;
    std::vector<ll> a(n);

    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    ll low = 0;
    ll high = 1e11;
    while (low + 1 < high){
        auto mid = (low + high) >> 1;
        
        if (good(k, n, a, mid))
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