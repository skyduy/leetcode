// https://leetcode.com/problems/bitwise-and-of-numbers-range/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) {
            return 0;
        }
        int moveFactor = 1;
        while (m != n) { // 二者不同，说明肯定有位错开
            m >>= 1;
            n >>= 1;
            moveFactor <<= 1;
        }
        return m * moveFactor;
    }
};

int main() {
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << ' ' << s.rangeBitwiseAnd(0, 1) << endl;
    return 0;
}