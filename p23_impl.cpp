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



string userHistory1 = to_string(senderId) + to_string(receiverId);
string userHistory2 = to_string(receiverId) + to_string(senderId);
if (conversationHistory.count(userHistory) || conversationHistory.count(userHistory2)) continue;
conversationCount[senderId]++;
conversationCount[receiverId]++;
conversationHistory.insert(userHistory);
unordered_set<string> conversationHistory;


int mxConversation = 0;
int mostActiveUser = -1;

for (auto [userId, count] : conversationCount) {
	if (count > mxConversation) {
		mxConversation = count;
		mostActiveUser = userId;
	}
}

return mostActiveUser;
