// Implement a Least Frequently Used (LFU) cache data structure of size cacheSize that handles two types of queries, GET and PUT.
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int capacity;
int minFreq;
unordered_map<int, pair<int, int>> keyVal;
unordered_map<int, list<int>::iterator> keyT;
unordered_map<int, list<int>> freq;

void update(int key) {
    int f = keyVal[key].second;
    freq[f].erase(keyT[key]);
    if (freq[f].empty()) {
        freq.erase(f);
        if (f == minFreq) minFreq++;
    }
    f++;
    keyVal[key].second = f;
    freq[f].push_front(key);
    keyT[key] = freq[f].begin();
}

int get(int key) {
    if (keyVal.find(key) == keyVal.end()) {
        return -1;
    }
    update(key);
    return keyVal[key].first;
}

void put(int key, int value) {
    if (capacity <= 0) return;

    if (keyVal.find(key) != keyVal.end()) {
        keyVal[key].first = value;
        update(key);
        return;
    }

    if (static_cast<int>(keyVal.size()) >= capacity) {
        int evictKey = freq[minFreq].back();
        freq[minFreq].pop_back();
        keyVal.erase(evictKey);
        keyT.erase(evictKey);
    }

    keyVal[key] = {value, 1};
    freq[1].push_front(key);
    keyT[key] = freq[1].begin();
    minFreq = 1;
}

vector<int> implement(int cacheSize, vector<string>& queries) {
    capacity = cacheSize;
    minFreq = 0;
    keyVal.clear();
    keyT.clear();
    freq.clear();

    vector<int> result;

    for (const string& query : queries) {
        istringstream iss(query);
        string operation;
        iss >> operation;

        if (operation == "GET") {
            int key;
            iss >> key;
            int value = get(key);
            result.push_back(value);
        } else if (operation == "PUT") {
            int key, value;
            iss >> key >> value;
            put(key, value);
        }
    }

    return result;
}

int main() {
    int cacheSize, q;
    cin >> cacheSize >> q;
    cin.ignore();

    vector<string> queries(q);
    for (int i = 0; i < q; i++) {
        getline(cin, queries[i]);
    }

    vector<int> result = implement(cacheSize, queries);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
// Ques-2 you need to convert the given prime number to another prime number
// but you need to cover minimum steps and the intermdiate number should also be a  prime.

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
