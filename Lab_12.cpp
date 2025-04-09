#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChocolates(int n, int m, vector<vector<int>> &mat) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = mat[n - 1][j1];
            else
                dp[n - 1][j1][j2] = mat[n - 1][j1] + mat[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int ans = 0;
                for (int d1 = -1; d1 <= 1; d1++) {
                    for (int d2 = -1; d2 <= 1; d2++) {
                        int nj1 = j1 + d1;
                        int nj2 = j2 + d2;
                        if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                            int value = 0;
                            if (j1 == j2)
                                value = mat[i][j1];
                            else
                                value = mat[i][j1] + mat[i][j2];
                            value += dp[i + 1][nj1][nj2];
                            ans = max(ans, value);
                        }
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }

    return dp[0][0][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    cout << maxChocolates(n, m, mat) << endl;
    return 0;
}
