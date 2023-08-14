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
    double c;
    std::cin >> c;

    double low = 1;
    double high = 1e5;

    for (int i=0;i<1000;i++){
        if (high - low > 1e-6){
            auto mid = low + (high - low) / 2;
            auto val = mid * mid + std::sqrt(mid);
            if (val >= c)
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
   4 2 3 1 5
*/