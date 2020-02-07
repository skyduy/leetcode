#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
int m, n;

int maxIslandArea(vector<vector<bool>>& grid) {
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == true) {
				queue<tuple<int, int>> q;
				q.push(make_tuple(i, j));
				grid[i][j] = false;
				int count = 0;
				int x, y;
				int len = q.size();
				while (len != 0) {
					count += len;
					for (int i = 0; i < len; i++) {
						tie(x, y) = q.front();
						q.pop();

						if (x - 1 >= 0) {
							if (grid[x - 1][y]) {
								edge++;
								grid[x - 1][y] = 0;
								q.push(make_tuple(x - 1, y));
							}
						}
						if (y - 1 >= 0) {
							if (grid[x][y - 1]) {
								edge++;
								grid[x][y - 1] = 0;
								q.push(make_tuple(x, y - 1));
							}
						}
						if (x + 1 < m) {
							if (grid[x + 1][y]) {
								grid[x + 1][y] = false;
								q.push(make_tuple(x + 1, y));
							}
						}
						if (y + 1 < n) {
							if (grid[x][y + 1]) {
								grid[x][y + 1] = false;
								q.push(make_tuple(x, y + 1));
							}
						}
					}
					len = q.size();
				}
				ans = max(ans, count);
			}
		}
	}
	return ans;
}

void commaInput() {
	string line;
	while (cin >> line) {
		stringstream ss(line);
		string tmp;
		getline(ss, tmp, ',');
		m = stoi(tmp);
		getline(ss, tmp, ',');
		n = stoi(tmp);

		vector<vector<bool>> lands(m, vector<bool>(n, 0));
		for (int i = 0; i < m; i++) {
			cin >> line;
			stringstream sss(line);
			for (int j = 0; j < n; j++) {
				getline(sss, tmp, ',');
				lands[i][j] = stoi(tmp);
			}
		}

		cout << maxIslandArea(lands) << endl;
	}
}

int main() {
	commaInput();
	//while (cin >> m >> n) {
	//	vector<vector<bool>> lands(m, vector<bool>(n, 0));
	//	bool tmp;
	//	for (int i = 0; i < m; i++) {
	//		for (int j = 0; j < n; j++) {
	//			cin >> tmp;
	//			lands[i][j] = tmp;
	//		}
	//	}

	//	cout << solve(lands) << endl;
	//}
}
/*
4 5
1 1 1 0 0
0 0 1 0 0
1 1 0 0 0
1 0 0 0 0

4,5

1,1,1,0,0

0,0,1,0,0

1,1,0,0,0

1,0,0,0,0
*/
