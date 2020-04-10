#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        int count = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                ans.push_back(toupper(S[i]));
                if (++count == K) {
                    ans.push_back('-');
                    count = 0;
                };
            }
        }
        if(ans == ""){
            return ans;
        }
        if(ans[ans.length()-1] == '-'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.licenseKeyFormatting("--a-a-a-a--", 2) << endl;
}