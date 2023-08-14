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
    std::string a, b;
    std::cin >> a >> b;

    int n = a.length();
    std::vector<int> v(n);
    for (int i=1;i<=n;i++){
        int x;
        std::cin >> x;
        x--;
        v[x] = i;
    }

    int low = 0;
    int high = n;

    while (low + 1 < high){
        auto mid = (low + high) >> 1;
        int i = 0;
        for (int j=0;j<a.size() && i<b.size();j++){
            if (v[j] <= mid) continue;
            if (a[j] == b[i]) i++;
        }

        if (i == b.size())
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
   4 2 3 1 5
*/