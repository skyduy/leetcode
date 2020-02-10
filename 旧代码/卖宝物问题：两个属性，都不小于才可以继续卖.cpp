#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


struct treasure {
	int x;
	int h;
	treasure(int x, int h) : x(x), h(h) {}
};
int n;

int maxCommon(const string& A, const string& B) {
	int len1 = A.length(), len2 = B.length();
	vector<vector<int>> dp(2, vector<int>(len2+1, 0));
	int curi, lasti;
	for (int i = 0; i < len1; i++) {
		curi = i % 2;
		lasti = 1 - curi;
		for (int j = 0; j < len2; j++) {
			if (A[i] == B[j]) {
				dp[curi][j+1] = dp[lasti][j] + 1;
			} else {
				dp[curi][j+1] = max(dp[lasti][j+1], dp[curi][j]);
			}
		}
	}
	return dp[curi][len2];
}

bool cmpx(treasure a, treasure b) {
	return a.x < b.x;
}

bool cmph(treasure a, treasure b) {
	return a.h < b.h;
}
int ans(vector<treasure>& c, vector<treasure>& d) {
	sort(c.begin(), c.end(), cmpx);
	sort(d.begin(), d.end(), cmph);
	string x_order, x_unorder, h_order, h_unorder;
	for (auto i : c) {
		x_order.push_back(i.x);
		h_unorder.push_back(i.h);
	}
	for (auto i : d) {
		h_order.push_back(i.h);
		x_unorder.push_back(i.x);
	}
	return max(maxCommon(x_order, x_unorder), maxCommon(h_order, h_unorder));
}


int main() {
	int x, h;
	while (cin >> n) {
		vector<treasure> c;
		vector<treasure> d;
		for (int i = 0; i < n; i++) {
			cin >> x >> h;
			treasure tmp(x, h);
			c.push_back(tmp);
			d.push_back(tmp);
		}
		cout << ans(c, d) << endl;
	}
}

/*
4
3 2
1 1
1 3
2 2
*/