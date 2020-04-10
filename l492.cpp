#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = sqrt(area);
        while (area % width != 0) {
            width--;
        }
        return {area / width, width};
    }
};

int main() {
    Solution s;
    for (int i : s.constructRectangle(4)) cout << i << ' ';
}