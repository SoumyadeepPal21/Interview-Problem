#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<vector<int>> houses = {{8, 2, 9}, {4, 6, 4}, {4, 5, 1}};
	vector<vector<char>> colors = {{'x', 'r', 'b'}, {'z', 'r', 'q'}, {'c', 'x', 'a'}};

	vector<pair<int, char>> allHouses;
	int n = houses.size();
	int m = houses[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			allHouses.push_back({houses[i][j], colors[i][j]});
		}
	}

	sort(allHouses.begin(), allHouses.end());

	vector<vector<string>> result(n, vector<string>(m));

	vector<int> idx(n, m - 1);
	int lastHouse = n - 1;
	for (int i = n * m - 1, j = i; i >= 0; i = j) {
		while (j >= 0 && allHouses[j].first == allHouses[i].first) j--;
		while (idx[lastHouse] < 0) lastHouse--;
		for (int k = i; k > j; k--) {
			int houseNum = lastHouse - (i - k);
			result[houseNum][idx[houseNum]] = to_string(allHouses[k].first) + allHouses[k].second;
			idx[houseNum]--;
		}
	}

	// Step 4: Print result
	for (const auto& row : result) {
		for (const auto& val : row) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}




bat, batt, batter

root
b
a
t -> stringExist = true
                   t -> stringExist = true
                                      e
                                      r -> stringExist = true

struct TreeNode {
	string name;
	vector<TreeNode*> children;
};

struct TrieNode {
	TrieNode* child[26];
	bool stringEnd;
	TreeNode* treeNode;
};


TreeTrie {
	TreeNode* treeRoot;
	TrieNode* trieRoot;
public:

	TreeTrie() {
		trieRoot = new TrieNode();
		trieRoot->treeRoot = new TreeNode();
	}

	void insert(string & name) {
		TreeRoot* node = trieRoot;
		lastTreeNode = node->treeNode;
		for (int i = 0; i < name.size(); i++) {
			int ch = name[i] - 'a';
			if (!node->child[ch]) {
				node->child[ch] = new TrieNode();
			}
			node = node->child[ch];
			if (node->stringEnd) {
				lastTreeNode = node->treeNode;
			}
		}
		node->stringEnd = true;
		las
	}
};