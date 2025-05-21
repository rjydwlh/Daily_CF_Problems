#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for(int i = 0; i < n; i++) std::cin >> s[i];
    int sum = 0;
    for(int i = 0; i < n; i++) sum += count(s[i].begin(), s[i].end(), 'B');
    // debug(sum);
    auto check = [&](int x, int y, std::vector<std::string> s) mutable -> bool {
        int vis = 0;
        s[x][y] = '#';
        vis++;
        for(int i = x - 1; i >= 0; i--) {
            if(s[i][y] == 'B' || s[i][y] == '#') {
                vis+= (s[i][y] == 'B');
                s[i][y] = '#';
                for(int j = y - 1; j >= 0; j--) {
                    if(s[i][j] == 'B'|| s[i][j] == '#') {
                        vis+= (s[i][j] == 'B');
                        s[i][j] = '#';
                    } else break;
                }
                for(int j = y + 1; j < m; j++) {
                    if(s[i][j] == 'B'|| s[i][j] == '#') {
                        vis += (s[i][j] == 'B');
                        s[i][j] = '#';
                    } else break;
                }
            } else {
                break;
            }
        }
        for(int i = x + 1; i < n; i++) {
            if(s[i][y] == 'B' || s[i][y] == '#') {
                vis += (s[i][y] == 'B');
                s[i][y] = '#';
                for(int j = y - 1; j >= 0; j--) {
                    if(s[i][j] == 'B'|| s[i][j] == '#') {
                        vis += (s[i][j] == 'B');
                        s[i][j] = '#';
                    } else break;
                }
                for(int j = y + 1; j < m; j++) {
                    if(s[i][j] == 'B'|| s[i][j] == '#') {
                        vis += (s[i][j] == 'B');
                        s[i][j] = '#';
                    } else break;
                }
            } else {
                break;
            }
        }
        for(int i = y + 1; i < m; i++) {
            if(s[x][i] == 'B' || s[x][i] == '#') {
                vis+= (s[x][i] == 'B');
                s[x][i] = '#';
                for(int j = x - 1; j >= 0; j--) {
                    if(s[j][i] == 'B' || s[j][i] == '#') {
                        vis+= (s[j][i] == 'B');
                        s[j][i] = '#';
                    } else {
                        break;
                    }
                }

                for(int j = x + 1; j < n; j++) {
                    if(s[j][i] == 'B' || s[j][i] == '#') {
                        vis+= (s[j][i] == 'B');
                        s[j][i] = '#';
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
        }
        for(int i = y - 1; i >= 0; i--) {
            if(s[x][i] == 'B' || s[x][i] == '#') {
                vis += (s[x][i] == 'B');
                s[x][i] = '#';
                for(int j = x - 1; j >= 0; j--) {
                    if(s[j][i] == 'B' || s[j][i] == '#') {
                        vis+= (s[j][i] == 'B');
                        s[j][i] = '#';
                    } else {
                        break;
                    }
                }

                for(int j = x + 1; j < n; j++) {
                    if(s[j][i] == 'B' || s[j][i] == '#') {
                        vis+= (s[j][i] == 'B');
                        s[j][i] = '#';
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
        }
        return vis == sum;
    };
    
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'B') ok &= check(i, j, s);
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1; 
    while (t--)
        solve();
    return 0;
}
