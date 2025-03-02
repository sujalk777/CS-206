#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
// Question-1
// Postfix Expression Evaluation
// representing a amthematical expression written in reverse polish Notation.
int evaluate(vector<string> token) {
    stack<int> st;
    for (const string t : token) {
        if (t== "+"|| t== "-" ||t== "*" ||t== "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (t== "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t== "*") st.push(a * b);
            else if (t== "/") st.push(a / b); 
        } else {
            int token=stoi(t);
            st.push(token);
        }
    }
    return st.top();
}

int main() {
    int n;
    cin >> n;
    vector<string>token(n);
    for (int i = 0; i < n; i++) {
        cin >> token[i];
    }
    cout << evaluate(token) << endl;
    return 0;
}

// 
int Mystrypairs(const vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> f;
    int total = (n * (n - 1)) / 2; 
    for (int i = 0; i < n; i++) {
        f[nums[i] - i]++;
    }
    int valid = 0;
    for (const auto& pair : f) {
        int c = pair.second;
        if (c > 1) {
             valid += (c * (c- 1)) / 2; 
        }
    }
    return total -valid; 
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Mystrypairs(nums) << endl;
    return 0;
}
