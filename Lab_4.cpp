// 1. You need to reverse an array by k from back
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; //for the case when k>n
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    rotateArray(nums, k);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

// 2. Rainwater trapped between the houses
