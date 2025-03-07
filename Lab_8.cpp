#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

bool isprime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> generate() {
    vector<int> p;
    for (int i = 11; i <= 99; i++) {
        if (isprime(i)) {
            p.push_back(i);
        }
    }
    return p;
}

int shortestPath(int src, int des) {
    if (src == des) return 0;

    vector<int> p = generate();
    vector<bool> visited(100, false);

    queue<pair<int, int>>q;
    q.push({src, 0});
    visited[src] = true;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int num = curr.first;
        int steps = curr.second;

        string a= to_string(num);

        for (int i = 0; i < 2; i++) {
            for (char c = '0'; c <= '9'; c++) {
                if (c == a[i]) continue;

                string newn = a;
                newn[i] = c;
                int newNum = stoi(newn);

                if (newNum >= 11 && newNum <= 99 && isprime(newNum) && !visited[newNum]) {
                    if (newNum == des) {
                        return steps + 1;
                    }
                    visited[newNum] = true;
                    q.push({newNum, steps + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    int src, des;
    cin >> src >> des;

    int result = shortestPath(src, des);
    cout << result << endl;

    return 0;
}
