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
    int n, k;
    std::cin >> n >> k;
    std::vector<ll> a(n);

    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    ll low = 0;
    ll high = 1e18;

    while (low + 1 < high){
        auto mid = (low + high) >> 1;
        auto good = [&](){
            int segs = 1;
            ll sum = 0;
            for (int i=0;i<n;i++){
                if (a[i] > mid) return false;
                if (sum + a[i] <= mid && n - i - 1 >= k - segs){
                    sum += a[i];
                } else {
                    sum = a[i];
                    segs++;
                }
            }

            return segs == k;
        };

        if (good()) 
            high = mid;
        else 
            low = mid;
    }

    std::cout << high << '\n';
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

