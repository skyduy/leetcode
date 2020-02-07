#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

void print(vector<int>& A, vector<int>& B) {
	if (A.size() == 1) {
		cout << A[0] << endl;
	} 
	else if (A.size() == 2) {
		if (A[0] >= A[1]) {
			int max[3] = { 0x80000000 };
			for (int e : B) {
				if (e > max[0]) {
					max[2] = max[1];
					max[1] = max[0];
					max[0] = e;
				}
			}
			for (int i = 0; i < 3; i++) {
				int ele = max[i];
				if (ele <= A[0] && ele >= A[1]) {
					continue;
				} else if (ele > A[0]) {
					A[1] = ele;
				} else {
					A[0] = ele;
				}
			}
		}
		for (int i : A) {
			cout << i << ' ';
		}
		cout << endl;
	}
}

int main() {
	int t;
	string line;
	vector<int> A;
	vector<int> B;
	while (getline(cin, line)) {
		A.clear(); B.clear();

		istringstream issa(line);
		while (issa >> t) { A.push_back(t); }

		getline(cin, line);
		istringstream issb(line);
		while (issb >> t) { B.push_back(t); }
		print(A, B);
	}
}