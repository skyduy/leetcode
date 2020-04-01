// https://leetcode.com/problems/heaters/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int result = 0;
        sort(heaters.begin(), heaters.end());
        int idx, dist;
        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            if (it == heaters.end()) {
                dist = house - heaters[heaters.size() - 1];
            } else if (it == heaters.begin()) {
                dist = heaters[0] - house;
            } else {
                idx = distance(heaters.begin(), it);
                dist = min(house - heaters[idx - 1], heaters[idx] - house);
            }
            result = max(result, dist);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> house{1, 2, 3, 4};
    vector<int> heater{1, 4};
    cout << s.findRadius(house, heater) << endl;
}
