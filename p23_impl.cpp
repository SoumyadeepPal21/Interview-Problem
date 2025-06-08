// https://leetcode.com/discuss/post/5535080/l3-interview-round-1-by-anonymous_user-e11w/

// Question - Given a formula of letters with parentheses, remove all parentheses from the formula.
// Examples:
// a-(b + c) -> a - b - c
// a-(a - b) -> b


#include <bits/stdc++.h>
using namespace std;

pair<string, string> findFirstWord(string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			return {s.substr(0, i), s.substr(i + 1)};
		}
	}
	return {"", ""};
}
void solve(vector<vector<string>> &dictionary) {
	unordered_map<string, int> adjWordCount;
	unordered_map<string, pair<string, int>> maxNextWord;
	for (vector<string> &sentence : dictionary) {
		for (int i = 0; i < sentence.size() - 1; i++) {
			string key = sentence[i] + "," + sentence[i + 1];
			adjWordCount[key]++;
		}
	}
	for (auto [str, count] : adjWordCount) {
		string key = findFirstWord(str).first;
		string ans = findFirstWord(str).first;
		if (!maxNextWord[key].count() || count > maxNextWord[key].second) {
			maxNextWord[key] = {ans, count};
		}
	}
}