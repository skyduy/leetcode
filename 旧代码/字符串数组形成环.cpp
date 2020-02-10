#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

int counter[128] = { 0 };

string satisfy(vector<string>& arr) {
	// �ж��ַ����ִ����ǲ���ż��
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
	// �ٽ����жϻ᲻���γɶ������
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