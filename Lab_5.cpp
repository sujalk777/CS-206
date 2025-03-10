#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// finding the majority element in the feast whihc wil be the king
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    for (int num : nums) {
        freq[num]++;
        if (freq[num] > n / 2) {
            return num;
        }
    }
    return -1; 
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


// Question -2

typedef long long ll;

int merge(vector<int>& nums, int left, int mid, int right) {
    int count = 0, j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (ll)nums[i] > 2LL * nums[j]) j++;
        count += (j - (mid + 1));
    }
    vector<int> temp;
    int i = left, k = mid + 1;
    while (i <= mid && k <= right) {
        if (nums[i] <= nums[k]) temp.push_back(nums[i++]);
        else temp.push_back(nums[k++]);
    }
    while (i <= mid) temp.push_back(nums[i++]);
    while (k <= right) temp.push_back(nums[k++]);
    for (int i = left; i <= right; i++) nums[i] = temp[i - left];
    return count;
}

int mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
    count += merge(nums, left, mid, right);
    return count;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << mergeSort(nums, 0, n - 1) << "\n";
    return 0;
}
