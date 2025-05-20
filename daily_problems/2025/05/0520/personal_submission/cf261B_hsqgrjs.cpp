#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, p;
    std::cin >> n;
    std::vector<int> a(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++) std::cin >> a[i];
    std::cin >> p;
    for(int i = 1; i <= n; i++) sum += a[i];
    if(sum <= p) {
        std::cout << n << "\n";
        return ;
    }

    i64 dp[n + 1][p + 1] = {0};
    long double ans = 0;
    for(int i = 1; i <= n; i++) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int j = 1; j <= n; j++) {
            if(j != i) {
                for(int j2 = n; j2 > 0; j2--) {
                    for(int k = p; k >= a[j]; k--) {
                        dp[j2][k] += dp[j2 - 1][k - a[j]];
                    }
                }
            }
        }

        for(int j = 1; j <= n; j++) {
            for(int k = max(p - a[i] + 1, 0); k <= p; k++) {
                long double t1 = dp[j][k];
                if(t1 == 0) continue;
                for(int t = 1; t <= n - j - 1; t++) {
                    t1 *= 1.0 * t / (t + j + 1);
                }
                t1 *= 1.0 * j / (j + 1);
                ans += t1;
            }
        }
        
    }

    std::cout << fixed << setprecision(6) << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;  
    while (t--)
        solve();
    return 0;
}
