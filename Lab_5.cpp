#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    for (int num : nums) {
        freq[num]++;
        if (freq[num] > n / 2) {
            return num;
        }
    }
    return -1; // This should never be reached as per problem constraints.
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << majorityElement(nums) << endl;
    return 0;
}
