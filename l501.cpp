// https://leetcode.com/problems/find-mode-in-binary-search-tree/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 结构体只是一种声明，告诉使用到的如何来创建对象，C++中，结构体和Class一样
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这里类只是一种声明，其内部实现的函数为都是内联函数
class Solution {
public:
    vector<int> modes;

    void getMaxFreq(TreeNode* r, int& maxFreq, int& preVal, int& count) {
        if (!r) return;
        getMaxFreq(r->left, maxFreq, preVal, count);
        if (r->val == preVal) {
            count++;
        } else {
            preVal = r->val;
            count = 1;
        }
        maxFreq = max(maxFreq, count);
        getMaxFreq(r->right, maxFreq, preVal, count);
    }

    void getMode(TreeNode* r, const int& maxFreq, int& preVal, int& count) {
        if (!r) return;
        getMode(r->left, maxFreq, preVal, count);
        if (r->val == preVal) {
            count++;
        } else {
            preVal = r->val;
            count = 1;
        }
        if (count == maxFreq) {
            modes.push_back(preVal);
        }
        getMode(r->right, maxFreq, preVal, count);
    }

    vector<int> findMode(TreeNode* root) {
        int maxFreq = 0;
        int preVal = INT32_MIN;
        int count = 0;
        getMaxFreq(root, maxFreq, preVal, count);

        preVal = INT32_MIN, count = 0;
        getMode(root, maxFreq, preVal, count);
        return modes;
    }
};

int main() {
    Solution s;
    std::cout << "Hello World!\n";
    return 0;
}
