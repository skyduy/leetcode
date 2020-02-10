#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

int counter[128] = { 0 };

string satisfy(vector<string>& arr) {
	// 判断字符出现次数是不是偶数
	for (string s : arr) {
		counter[s[0]]++;
		counter[s[s.length() - 1]]++;
	}
	for (int i = 0; i < 128; i++) {
		if (counter[i] % 2 == 1) {
			cout << char(i);
			return "false";
		}
	}
	// 再进行判断会不会形成多个环？
	// TODO
	return "true";
}

int main() {
	string s;
	string line;
	vector<string> arr;
	while (getline(cin, line)) {
		arr.clear();
		for (int i = 0; i < 128; i++) { counter[i] = 0; }
		istringstream iss(line);
		while (iss >> s) { arr.push_back(s); }
		cout << satisfy(arr) << endl;
	}
}