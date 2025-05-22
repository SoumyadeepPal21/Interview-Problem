// https://leetcode.com/discuss/post/5535080/l3-interview-round-1-by-anonymous_user-e11w/

// Question - Given a formula of letters with parentheses, remove all parentheses from the formula.
// Examples:
// a-(b + c) -> a - b - c
// a-(a - b) -> b


#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	stack<int> stk;
	map<char, int> freq;
	int lastSign = 1;
	int neg = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+') {
			lastSign = 1;
		} else if (s[i] == '-') {
			lastSign = -1;
		} else if (s[i] == '(') {
			if (lastSign == -1) {
				neg++;
				stk.push(1);
			} else {
				stk.push(0);
			}
		} else if (s[i] == ')') {
			neg -= stk.top();
			stk.pop();
		} else {
			freq[s[i]] += (lastSign * ((neg % 2) ? -1 : 1));
		}
	}
	string ans = "expression: ";
	for (auto [ch, cnt] : freq) {
		if (cnt > 0) {
			ans += "+";
			if (cnt > 1)
				ans += to_string(cnt);
			ans.push_back(ch);
		} else if (cnt < 0) {
			ans += "-";
			if (cnt > 1)
				ans += to_string(cnt);
			ans.push_back(ch);
		}
	}
	cout << ans;

}
