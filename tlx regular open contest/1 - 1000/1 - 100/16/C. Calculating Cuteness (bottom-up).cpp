#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

int mod = 1e9 + 7;
int n, m;

i64 binexp(int x, int y) {
    if(y == 0) return 1LL;
    
    i64 z = binexp(x, y / 2);
    if(y & 1) return (((z * z) % mod) * x) % mod * 1LL;
    return (z * z) % mod * 1LL;
}

void solve() {
    std::cin >> n >> m;
    
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(2));
    dp[0][0] = 1; dp[0][1] = 0;
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (m - 1) * ((dp[i - 1][0] + dp[i - 1][1]) % mod) % mod;
        dp[i][1] = dp[i - 1][0] % mod;
    }
    
    i64 ans = (dp[n][0] + dp[n][1] - binexp(m - 1, n) + mod) % mod;
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
