#pragma once
// https://leetcode.com/problems/find-mode-in-binary-search-tree/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 类声明中实现的函数为内联函数，调用任务交给编译器执行：将调用处的代码替换
class Solution {
public:
	vector<int> modes;

	void getMaxFreq(TreeNode* r, int& maxFreq, int& preVal, int& count) {
		if (!r) return;
		getMaxFreq(r->left, maxFreq, preVal, count);
		if (r->val == preVal) {
			count++;
		}
		else {
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
		}
		else {
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
		int preVal = INT_MIN;
		int count = 0;
		getMaxFreq(root, maxFreq, preVal, count);

		preVal = INT_MIN, count = 0;
		getMode(root, maxFreq, preVal, count);
		return modes;
	}
};