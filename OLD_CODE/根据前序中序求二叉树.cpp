#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
TreeNode* reconstruct(vector<int>& pre, vector<int>& vin, int preBegin, int preEnd,
	int inBegin, int inEnd) {
	if (preBegin > preEnd) return NULL;
	int val = pre[preBegin];
	TreeNode* root = new TreeNode(val);
	int pos = inBegin;
	while (vin[pos] != val&&pos<=inEnd) pos++;
	root->left = reconstruct(pre, vin, preBegin + 1, preBegin + pos - inBegin,
		inBegin, pos - 1);
	root->right = reconstruct(pre, vin, preEnd-(inEnd-(pos+1)+1)+1, preEnd,
		pos + 1, inEnd);
	return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	return reconstruct(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
}
int main() {
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> in = { 4,7,2,1,5,3,8,6 };
	reConstructBinaryTree(pre, in);
	return 0;
}