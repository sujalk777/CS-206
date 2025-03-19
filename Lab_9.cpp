#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

bool compare(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1 + s2 > s2 + s1;
}

string largest(vector<int>& n) {
    sort(n.begin(), n.end(), compare);
    
    if (n[0] == 0) {
        return "0";
    }
    
    string result;
    for (int num : n) {
        result += to_string(num);
    }
    
    return result;
}

int main() {
    vector<int> n;
    string input;
    
 
    getline(cin, input);
    
    stringstream ss(input);
    int num;
    while (ss >> num) {
        n.push_back(num); 
    }
    
    string res = largest(n);
    
    cout <<res<<endl;
    
    return 0;
}
