#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }

        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur * 2 == sum - nums[i]) {
                return i;
            }
            cur += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 7, 3, 6, 5, 6};
    cout << s.pivotIndex(nums) << endl;
}