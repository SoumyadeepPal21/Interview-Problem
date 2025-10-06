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




2.


findEqCells(int i, int j, vector<pair<int, int>>& cells, char ch) {
	if (i >= n || i < 0 || j < 0 || j >= m || grid[i][j] != ch && vis[i][j]) return;
	cells.push_back({i, j});
	for (int i = 0; i < 4; i++) {
		findEqCells(ni, nj, cells, ch);
	}
}

main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || grid[i][j] != '*') continue;
			findEqCells(i, j, cells, grid[i][j]);
			for (auto cell : cells) {
				par[cell] = cells[0];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || grid[i][j] != '.') continue;
			findEqCells(i, j, cells, grid[i][j]);
			for (auto cell : cells) {
				if (cell.first == 0 || cell.first == n - 1 || cell.second == 0 ||
				        cell.second == m - 1) {
					isLand = false;
				}
				if (grid[adjcell] == '*') {
					store that adj cell
				}
			}
			if (island) {
				int p = par[adjcell];
				count[p]++;
			}
		}
	}
	for (auto q : queries) {
		int p = par[q];
		cout << count[p] << endl;
	}
}