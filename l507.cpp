#include <cmath>
#include <iostream>

using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }

        int sum = 1;
        int mid = sqrt(num);
        for (int i = 2; i <= mid; i++) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
            }
        }
        if(mid * mid == num){
            sum -= mid;
        }

        return sum == num;
    }
};

int main() {
    Solution s;
    cout << s.checkPerfectNumber(6) << endl;
}