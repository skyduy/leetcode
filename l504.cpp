// TODO https://leetcode.com/problems/base-7/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) return "0";
		string ans;
		bool neg = false;
		if (num < 0) {
			neg = true;
			num = -num;
		}
		while (num > 0) {
			ans.push_back(num % 7 + '0');
			num /= 7;
		}
		if (neg) {
			ans.push_back('-');
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	Solution s;
	cout << s.convertToBase7(100) << ' ' << s.convertToBase7(-7) << endl;
	return 0;
}