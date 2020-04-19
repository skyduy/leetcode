#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(make_pair(nums[i], i));
        }
        vector<string> ans(nums.size(), "");
        for (int i = 0; i < nums.size(); i++) {
            auto p = pq.top();
            pq.pop();
            if (i == 0) {
                ans[p.second] = "Gold Medal";
            } else if (i == 1) {
                ans[p.second] = "Silver Medal";
            } else if (i == 2) {
                ans[p.second] = "Bronze Medal";
            } else {
                ans[p.second] = to_string(i + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{5, 4, 3, 2, 1};
    for (string i : s.findRelativeRanks(nums)) {
        cout << i << ' ';
    }
    cout << endl;
}