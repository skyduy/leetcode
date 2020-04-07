#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while ((num & mask) != 0) {
            mask <<= 1;
        }
        return ~mask & ~num;
    }

    int findComplementOld(int num) {
        int notNum = ~num;
        int zeroCount = -1;
        while ((num & 0x80000000) == 0) {
            zeroCount++;
            num <<= 1;
        }
        return notNum & (0x7FFFFFFF >> zeroCount);
    }
};

int main() {
    Solution s;
    cout << s.findComplement(5) << ' ' << s.findComplement(1) << endl;
    cout << s.findComplementOld(5) << ' ' << s.findComplementOld(1) << endl;
}