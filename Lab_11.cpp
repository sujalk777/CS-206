// You are given an unsorted array of integers, nums, which may contain both positive and negative numbers.
// Your task is to find and return the smallest positive integer that is missing from the array.

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; ++i) {
        while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << n + 1 << endl;
    return 0;
}


// Decrement the character by 1. The letter 'a' cannot be decremented.
// Increment the character by 1. Letter 'z'cannot be incremented.
// For example, increment 'f' to 'g'or decrement 'f'to 'e'

// The string should be modified such that every character has at least 1 equal adjacent character. 
// The first and last characters of a string only have a single adjacent character, 
// in order for the first character to have an equal adjacent character,
// it must be the same as the second character. Similarly for the last character.

// For example, "aaabb" and "aaccdd" are good, but "abaaa" and "abcdef" are not.
// Calculate the minimum number of moves required to modify the string to a good form.



#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>

using namespace std;
int cost(const string& s, int l, int r, char ch) {
    int cost = 0;
    for (int i = l; i <= r; ++i) {
        cost += abs(s[i] - ch);
    }
    return cost;
}
int minMoves(const string& s) {
    int n = s.length();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 2; i <= n; ++i) {
        for (int len = 2; len <= i; ++len) {
            int l = i - len;
            int r = i - 1;

            int minCost = INT_MAX;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                int c = cost(s, l, r, ch);
                minCost = min(minCost, c);
            }

            if (dp[l] != INT_MAX) {
                dp[i] = min(dp[i], dp[l] + minCost);
            }
        }
    }
    return dp[n];
}

int main() {
    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << minMoves(s) << endl;

    return 0;
}
