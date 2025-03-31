// Each member of the Row Family was known for a special talent – they could make numbers appear in rows. Similarly, each member of the Column Family had the ability to make numbers appear in columns.
// One day, the kingdom was tasked with a very important challenge. The Row Family and the Column Family were each given a list of magical sums. 
// The Row Family was given a list where the sum of each row of numbers should be a certain value. The Column Family was given a similar list, but it told them the sum of each column they must form. 
// The task was simple but challenging: both families had to work together to build a matrix of non-negative numbers, where the sums of the rows match the numbers in the Row Family’s list,
// and the sums of the columns match the numbers in the Column Family’s list. Now, brave one, your quest is to find any matrix that satisfies these magical conditions! You are guaranteed that at least one such matrix exists.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    cin >> m;
    vector<int> c(m);
    for (int j = 0; j < m; ++j) {
        cin >> c[j];
    }

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val = min(r[i], c[j]);
            matrix[i][j] = val;
            r[i] -= val;
            c[j] -= val;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j];
            if (j < m - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
