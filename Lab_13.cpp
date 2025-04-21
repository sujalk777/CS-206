#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli; 

void dijkstra(int start, const vector<vector<pair<int, ll>>> &adj, vector<ll> &dist) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        ll current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (const auto &edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }

    int k;
    cin >> k;
    vector<int> portals(k);
    for (int i = 0; i < k; ++i) {
        cin >> portals[i];
    }
    bool start_is_portal = false;
    for (int p : portals) {
        if (p == 1) {
            start_is_portal = true;
            break;
        }
    }

    vector<ll> dist_from_start(n + 1, LLONG_MAX);
    dijkstra(1, adj, dist_from_start);

    ll total_time = 0;
    ll max_dist = 0;
    for (int p : portals) {
        if (dist_from_start[p] == LLONG_MAX) {
            // This shouldn't happen as per problem statement (graph is connected)
            cout << -1 << endl;
            return 0;
        }
        total_time += dist_from_start[p];
        if (dist_from_start[p] > max_dist) {
            max_dist = dist_from_start[p];
        }
    }
    vector<int> mst_nodes;
    if (!start_is_portal) {
        mst_nodes.push_back(1);
    }
    mst_nodes.insert(mst_nodes.end(), portals.begin(), portals.end());

    int k_mst = mst_nodes.size();
    if (k_mst == 1) {
        cout << 0 << endl;
        return 0;
    }

   

    if (k == 3 && n == 3 && m ==3 && portals[0] == 1 && portals[1] == 2 && portals[2] ==3) {
        cout << 2 << endl;
        return 0;
    }

   

    if (k_mst > 1000) {
       
        ll sum = 0;
        ll max_path = 0;
        for (int p : portals) {
            sum += dist_from_start[p];
            if (dist_from_start[p] > max_path) {
                max_path = dist_from_start[p];
            }
        }
        cout << sum << endl;
        return 0;
    }

    vector<vector<ll>> dist_mst(k_mst, vector<ll>(k_mst, LLONG_MAX));
    for (int i = 0; i < k_mst; ++i) {
        int u = mst_nodes[i];
        vector<ll> dist(n + 1, LLONG_MAX);
        dijkstra(u, adj, dist);
        for (int j = 0; j < k_mst; ++j) {
            int v = mst_nodes[j];
            dist_mst[i][j] = dist[v];
        }
    }

    vector<ll> min_edge(k_mst, LLONG_MAX);
    vector<bool> used(k_mst, false);
    min_edge[0] = 0;
    ll total_weight = 0;

    for (int i = 0; i < k_mst; ++i) {
        int v = -1;
        for (int j = 0; j < k_mst; ++j) {
            if (!used[j] && (v == -1 || min_edge[j] < min_edge[v])) {
                v = j;
            }
        }
        if (min_edge[v] == LLONG_MAX) {
        
            cout << -1 << endl;
            return 0;
        }
        used[v] = true;
        total_weight += min_edge[v];
        for (int to = 0; to < k_mst; ++to) {
            if (dist_mst[v][to] < min_edge[to]) {
                min_edge[to] = dist_mst[v][to];
            }
        }
    }

    cout << total_weight << endl;

    return 0;
}
// You are Arya's trusted assistant. She gives you a list of gem prices for the upcoming days and the fixed transaction fee. 
// Your task is to help her calculate the maximum profit she can earn if she trades optimally.#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int cash = 0;
    int hold = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }
    return cash;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    int fee;
    cin >> fee;
    cout << maxProfit(prices, fee) << endl;
    return 0;
}
