#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums2) {
            while (!s.empty() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : nums1) {
            ans.push_back(m.count(n) ? m[n] : -1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> n1{2, 4};
    vector<int> n2{1, 2, 3, 4};
    for (int i : s.nextGreaterElement(n1, n2)) {
        cout << i << ' ';
    }
    cout << endl;
}
