#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

int mod = 1e9 + 7;
int n, m;
std::vector<std::vector<i64>> dp;

i64 compute(int t, int e, std::vector<std::vector<i64>>& dp) {
    if(t == 0) return (e == 0)? 1: 0;
    
    if(dp[t][e] != -1) return dp[t][e];
    
    dp[t][e] = (e == 1)? compute(t - 1, 0, dp) % mod: 
    (m - 1) * (compute(t - 1, 0, dp) % mod + compute(t - 1, 1, dp) % mod) % mod;
    
    return dp[t][e];
}

i64 binexp(int x, int y) {
    if(y == 0) return 1LL;
    
    i64 z = binexp(x, y / 2);
    if(y & 1) return (((z * z) % mod) * x) % mod * 1LL;
    return (z * z) % mod * 1LL;
}

void solve() {
    std::cin >> n >> m;
    
    int t = n;
    dp.assign(n + 1, std::vector<i64>(2, -1));
    
    i64 a1 = compute(t, 0, dp) % mod;
    i64 a2 = compute(t, 1, dp) % mod;
    
    i64 a = (a1 + a2 - binexp(m - 1, n) + mod) % mod;
    
    std::cout << a;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    
    /*
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    */
    
    int tst = 1;
    while(tst--) solve();
    
    return 0;
}

// g++ -std=c++20 <filename>.cpp
