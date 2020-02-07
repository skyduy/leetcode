#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

string raw, res;
unordered_map<string, unordered_set<char>> mleft, mright;


void getRes(vector<string>& ans, string cur, int pos, string subs,
	unordered_map<char, int>& recordRaw, unordered_map<char, int>& recordRes) {
	if (pos == raw.length()) {
		ans.push_back(cur);
	} else {
		if (mleft.find(subs) == mleft.end()) return;

		char c = raw[pos];
		if (recordRaw[c] > recordRes[c]) {
			cur.push_back('d');
			recordRaw[c] -= 1;
			getRes(ans, cur, pos + 1, subs, recordRaw, recordRes);
			recordRaw[c] += 1;
		}
		if (mright[subs].find(c) != mright[subs].end()) {
			recordRaw[c] -= 1;
			recordRes[c] -= 1;
			getRes(ans, cur + 'r', pos + 1, subs + c, recordRaw, recordRes);
			recordRaw[c] += 1;
			recordRes[c] += 1;
		}
		if (mleft[subs].find(c) != mleft[subs].end()) {
			recordRaw[c] -= 1;
			recordRes[c] -= 1;
			getRes(ans, cur + 'l', pos + 1, c + subs, recordRaw, recordRes);
			recordRaw[c] += 1;
			recordRes[c] += 1;
		}

	}
}

vector<string> solve() {
	unordered_map<char, int> recordRaw;
	unordered_map<char, int> recordRes;
	for (char c : raw) {
		recordRaw[c] += 1;
	}
	for (char c : res) {
		recordRes[c] += 1;
	}

	for (auto it = recordRes.begin(); it != recordRes.end(); ++it) {
		char key = it->first;
		if (it->second > recordRaw[key]) {
			return { {} };
		}
	}
	mleft.clear(); mright.clear();
	mleft[""] = { res[res.size() - 1] };
	for (int begin = 0; begin < res.length(); begin++) {
		for (int end = begin; end <= res.length(); end++) {
			string key = res.substr(begin, end - begin);
			if (mleft.find(key) == mleft.end()) {
				unordered_set<char> tmp;
				mleft[key] = tmp;
			}
			if (begin - 1 >= 0) {
				mleft[key].insert(res[begin - 1]);
			}
			if (mright.find(key) == mright.end()) {
				unordered_set<char> tmp;
				mright[key] = tmp;
			}
			if (end < res.length()) {
				mright[key].insert(res[end]);
			}
		}
	}
	vector<string> ans;
	char left = '0', right = '0';
	string cur;
	string subs;
	mleft, mright;
	getRes(ans, cur, 0, subs, recordRaw, recordRes);
	return ans;
}

int main() {
	int round;
	while (cin >> round) {
		for (int i = 0; i < round; i++) {
			cin >> raw >> res;
			vector<string> ans = solve();
			cout << '{' << endl;
			for (auto a : ans) {
				cout << a << endl;
			}
			cout << '}' << endl;
		}
	}
}
