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
    int n;
    std::cin >> n;
    std::vector<std::pair<ll, ll>> a(n);

    for (int i=0;i<n;i++){
        std::cin >> a[i].first >> a[i].second;
    }

    double low = 0;
    double high = 2 * 1e9;

    // we want to check if max_i{(x_i - x) / v_i} <= t
    // for some x. For any i, x is in [x_i - tv_i, x_i + tv_i]
    // so all segments should intersect
    for (int i=0;i<100;i++){
        if (high - low > 1e-6){
            auto mid = (low + high) / 2;

            auto good = [&](){
                double lmax = LLONG_MIN;
                double rmin = LLONG_MAX;

                for (int i=0;i<n;i++){
                    double l = a[i].first - mid * a[i].second;
                    double r = a[i].first + mid * a[i].second;
                    lmax = std::max(l, lmax);
                    rmin = std::min(r, rmin);
                }

                return lmax <= rmin;
            };

            if (good())
                high = mid;
            else 
                low = mid;
        }
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

