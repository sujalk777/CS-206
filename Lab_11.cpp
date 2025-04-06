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

