// https://leetcode.com/discuss/post/5387760/google-l4-offer-by-anonymous_user-zvsu/


//  Implement the word suggestion engine we see in querty keyboards on phone. This was in my opinion the best interview I had. In the keyboards on our phone if we want to type out a word, we can swipe over the letters and it will suggest the best matching word. The interviewer asked me to implement this algorithm.

// Was given list of strings as disctionary and a string input which this denotes all the characters falling under the swipe on the keyboard.

// Two main inputs

// User path
// E.g. "qwertyuiujhgcvghbnjk"
// List of dictionary words
// E.g [aardvark, angel, dog, quick, quickly, quickening, TikTok, zebra]
// Ans: qwertyuiujhgcvghbnjk
// quick

int next[n][26];

for (int i = n - 1; i >= 0; i--) {
	for (int j = 0; j < 26; j++) {
		next[i][j] = next[i + 1][j];
	}
	next[i][s[i] - 'a'] = i;
}

// insert all words in Trie

queue<pair<TrieNode*, int>> q;
// node, index in path
q.push({root, 0});

while (!q.empty()) {
	auto [node, index] = q.front();
	if (node.isEnd()) {
		string word = dict[node.isEnd()];
		if (word.length() > ans.length()) {
			ans = dict[node.isEnd()];
		}
	}
	q.pop();
	for (int ch = 0; ch < 26; ch++) {
		\
		if (node->children[ch] && next[index][ch] < n) {
			q.push({node->children[ch], next[index][ch] + 1});
		}
	}
}


space: O(N * L)
time: O(N * L) in worst case => all words are unique and all exist in S as a subsequence,
	      because all nodes in Trie structure can be explored once

	      if the words are identical, then the time will decrease.