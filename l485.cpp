#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        for(int num: nums){
            if(num){
                cur++;
            } else {
                ans = max(ans, cur);
                cur = 0;
            }
        }
        ans = max(ans, cur);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> n{1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(n) << endl;
}