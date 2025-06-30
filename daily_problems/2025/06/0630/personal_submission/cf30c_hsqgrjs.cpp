#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;
struct Point {
    int x, y, t;
    double p;
};

double dis(int x1, int y1, int x2, int y2) {
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<Point> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
    }   


    std::sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.t < y.t;
    });

    double dp[1001] = {0};
    for(int i = 0; i < n; i++) {
        dp[i] = a[i].p;
        for(int j = 0; j < i; j++) {
            if(a[i].t - a[j].t >= dis(a[i].x, a[i].y, a[j].x, a[j].y)) {
                dp[i] = std::max(dp[i], dp[j] + a[i].p);
            }
        }
    }
    std::cout << std::fixed << std::setprecision(10) << *std::max_element(dp, dp + n) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
