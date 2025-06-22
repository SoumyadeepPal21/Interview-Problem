// https://leetcode.com/discuss/post/6617221/google-l3-interview-experience-by-anonym-nt48/

vector<int> len(m);
deque<int> nextCharMap[26];
for (int i = 0; i < m; i++) {
	nextCharMap[words[i] - 'a'].push_back(i);
}

for (int i = 0; i < n; i++) {
	int ch = s[i] - 'a';
	int sz = nextCharMap[ch].size();
	while (sz--) {
		int index = nextCharMap[ch].front();
		len[index]++;
		if (len[index] == word[index].length()) {
			yesNoMap[word[index]] = true;
		} else {
			int nextCh = word[index][len[index]];
			nextCharMap[nextCh].push_back(index);
		}
	}
}

complexity = O(N + L * M)

