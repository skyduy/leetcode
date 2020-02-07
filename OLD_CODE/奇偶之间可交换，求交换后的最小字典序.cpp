#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void asort(vector<int>& A) {
	bool odd = false, even = false;
	for (int i : A) {
		if (i % 2 == 0) odd = true;
		else even = true;
		if (odd && even) break;
	}
	if (odd && even) {
		sort(A.begin(), A.end());
	}
}

int main() {
	int n, a;
	vector<int> A;
	while (cin >> n) {
		A.clear();
		for (int i = 0; i < n; i++) {
			cin >> a;
			A.push_back(a);
		}
		asort(A);
		for (int i : A) {
			cout << i << ' ';
		}
		cout << endl;
	}
}
