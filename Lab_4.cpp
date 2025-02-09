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
#include <iostream>
#include <vector>
using namespace std;

int trapRainWater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            leftMax=max(leftMax,height[left]);
            water+= leftMax - height[left];
            
            left++;
        } 
        else {
            rightMax=max(rightMax,height[right]);
            water+= rightMax - height[right];
            right--;
        }
    }
    return water;
}
int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    cout << trapRainWater(height) << endl;
    return 0;
}

//3.Tree from postorder and inorder traversal 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

unordered_map<int, int> inorderIndexMap;
int postIndex;

Node* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;
    
    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);
    
    int inIndex = inorderIndexMap[rootVal];
    
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1);
    
    return root;
}

void preorderTraversal(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        inorderIndexMap[inorder[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    
    postIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n - 1);
    preorderTraversal(root);
    cout << endl;
    
    return 0;
}
