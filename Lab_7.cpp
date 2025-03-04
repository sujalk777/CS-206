// to calculate the Difference of maximum and minimum totalGold we can get.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, int p, vector<vector<int>>& g, vector<int>& c, int s, int& m) {
    m = max(m, s);
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u, g, c, s + c[v], m);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int m = 0;

    for (int i = 0; i < n; ++i) {
        dfs(i, -1, g, c, 0, m);
    }

    cout << m << endl;

    return 0;
}
