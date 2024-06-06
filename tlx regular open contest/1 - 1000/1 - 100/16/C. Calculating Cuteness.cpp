#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

int mod = 1e9 + 7;
int n, m;

i64 compute(int t, int cur, std::vector<std::vector<i64>>& dp) {
    if(t == 0) return 1;
    
    if(dp[t][cur] != -1) return dp[t][cur];
    
    if(cur == 1) dp[t][cur] = ((m - 1) * compute(t - 1, 0, dp)) % mod;
    
    else dp[t][cur] = ((m - 1) * compute(t - 1, 0, dp)) % mod + compute(t - 1, 1, dp) % mod;
    
    return dp[t][cur];
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
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(2, -1));
    
    i64 ans = (compute(t, 0, dp) - binexp(m - 1, n) + mod) % mod;
    
    std::cout << ans;
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
