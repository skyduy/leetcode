#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int m, n, k;

int ans(vector<vector<bool>>& map) {
	if (map[0][0] == false) return 0;
	queue<tuple<int, int>> q;
	q.push(make_tuple(0, 0));
	map[0][0] = false;
	int count = 0;
	int x, y;
	int len = q.size();
	while (len != 0) {
		count++;
		for (int i = 0; i < len; i++) {
			tie(x, y) = q.front();
			q.pop();
			if (x + 1 < m) {
				if (x + 1 == m - 1 && y == n - 1) {
					return count;
				} else {
					if (map[x + 1][y]) {
						map[x + 1][y] = false;
						q.push(make_tuple(x + 1, y));
					}
				}
			}
			if (y + 1 < n) {
				if (x == m - 1 && y + 1 == n - 1) {
					return count;
				} else {
					if (map[x][y + 1]) {
						map[x][y + 1] = false;
						q.push(make_tuple(x, y + 1));
					}
				}
			}
		}
		len = q.size();
	}
	return 0;
}

int main() {
	int x, y;
	while (cin >> m >> n >> k) {
		vector<vector<bool>> map(m, vector<bool>(n, true));
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[x][y] = false;
		}
		cout << ans(map) << endl;
	}
}
