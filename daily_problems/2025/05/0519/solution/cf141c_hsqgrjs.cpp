#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<std::string, int>> a(n);

    for(int i = 0; i < n; i++) {
        auto& [x, y] = a[i];
        std::cin >> x >> y;

    }

    std::sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second < y.second;
    });
    std::vector<std::string> b[n];
    for (auto [x, y] : a)
    {
        b[y].push_back(x);
    }
    std::vector<std::pair<std::string, int>> ans;
    bool ok = 1;
    std::stack<std::pair<std::string, int>> sum;
    for(auto x : b[0]) sum.push({x, n});
    for(int i = 1; i < n; i++) {
        if(b[i].size() == 0) continue;
        if(sum.size() + ans.size() < i) {
            std::cout << -1 << "\n";
            return ;
        }
        while(ans.size() < i) {
            ans.push_back(sum.top());
            sum.pop();
        }
        for(auto x : b[i]) sum.push({x, n - i});
    }
    while(sum.size()) {
        ans.push_back(sum.top());
        sum.pop();
    }
    for(auto [s, x] : ans) {
        std::cout << s << " " << x << "\n";
    }
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
