// https://leetcode.com/discuss/interview-question/2199392/Google-or-Onsite-or-Generic-language-translator



int addWord(string word, string lang) {
	if (!wordToId.count(word)) {
		wordToId[word] = ++id;
		idToWord[id] = word;
		m[id][lang] = id;
		par[id] = id;
	}
	return wordToId[word];
}

int find(int u) {
	return (par[u] == u ? u : find(par[u]));
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (m[u].size() < m[v].sie()) swap(u, v);
	parent[v] = u;
	for (auto x : m[v]) m[u][x.fi] = x.se;
	m[v].clear();
}

void add(string word1, string lang1, string word2, string lang2) {
	int id1 = addWord(word1);
	int id2 = addWord(word2);

	merge(id1, id2);
}

string(string word, string lang1, string lang2) {
	if (!wordToId.count(word)) {
		return "";
	}
	int id = wordToId[word];
	id = find(id);
	if (m[id].count(lang2)) return idToWord[m[id][lang2]];
	return "";
}