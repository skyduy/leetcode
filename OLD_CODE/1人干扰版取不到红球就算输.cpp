#include<iostream>
#include<vector>
using namespace std;


double solve(int red, int blue) {
	vector<vector<double>> dp(red + 1, vector<double>(blue + 1, 0));
	double r1, coef, value;
	for (int i = 1; i <= red; i++) dp[i][0] = 1;
	for (int i = 1; i <= red; i++) {
		for (int j = 1; j <= blue; j++) {
			double iv = double(i), jv = double(j);
			r1 = iv / (iv + jv);
			if (j - 1 == 0) {
				dp[i][j] = r1;
			} else {
				coef = jv / (iv + jv) * (jv - 1) / (iv + jv - 1);  // B,B
				if (j - 2 == 0) {
					value = dp[i - 1][j - 2];  // B B R
				} else {
					value = iv / (iv + jv - 2) * dp[i - 1][j - 2] +   // BBR
						(jv - 2) / (iv + jv - 2) * dp[i][j - 3];  // BBB
				}
				dp[i][j] = r1 + coef * value;
			}
		}
	}

	//for (int i = 0; i <= red; i++) {
	//	for (int j = 0; j <= blue; j++) {
	//		cout << dp[i][j] << '\t';
	//	}
	//	cout << endl;
	//}
	return dp[red][blue];
}

int main() {
	int n, m;
	cout.precision(5);
	while (cin >> n >> m) {
		cout << solve(n, m) << endl;
	}
}