#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
vector<float> grades;
vector<int> idx;

int cmp(int a, int b) {
	return grades[a] < grades[b];
}

void compute() {
	int total = idx.size();
	int now = 0;
	vector<int> same;
	while (now < total) {
		same.clear();
		same.push_back(idx[now]);
		now++;
		while (now < total && grades[idx[now]] == grades[idx[now - 1]]) {
			same.push_back(idx[now]);
			now++;
		}
		float p = 100.0 * (now - 1) / total;
		for (int i : same) {
			grades[i] = p;
		}
	}
}

int main() {
	int n;
	int k;
	float grade;
	while (cin >> n) {
		grades.clear();
		idx.clear();
		for (int i = 0; i < n; i++) {
			cin >> grade;
			grades.push_back(grade);
			idx.push_back(i);
		}
		sort(idx.begin(), idx.end(), cmp);
		compute();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> k;
			cout << round(grades[k - 1]) << endl;
		}
	}
}
