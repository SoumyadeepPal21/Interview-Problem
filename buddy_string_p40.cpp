// Given array of strings group strings
// which are buddies to each other 2 strings are
// buddy if they have equal length and and each
// character has same distance
// for e.g. : aab and bbc are buddy


class Solution {
private:
	int findDis(char a, char b) {
		if (a >= b) {
			return (int)(a - 'a') - (int)(b - 'a');
		}
		return (26 + (int)(a - 'a') - (int)(b - 'a'));
	}

	string createStringHash(const string& word) {
		string hash = "";
		for (int i = 1; i < word.size(); i++) {
			int dis = findDis(word[i], word[i - 1]);
			hash += toString(dis) + ",";
		}
		return hash;
	}

	string createIntHash(const string word, int radix, int mod) {
		int hash = 0;
		for (int i = 1; i < word.size(); i++) {
			int dis = findDis(word[i], word[i - 1]);
			hash = (1LL * hash * radix + dis) % mod;
		}
		return to_string(hash);
	}
public:
	long long countBuddyString(vector<string> &words) {
		int n = words.size();
		int oneLengthWord = 0;
		unordered_map<string, int> hashMap;

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (words[i].size() == 1) {
				ans += oneLengthWord;
				oneLengthWord++;
			} else {
				string hash = createStringHash(words[i]);
				// string hash1 = createIntHash(word[i], 11, 1e9 + 7);
				// string hash2 = createIntHash(word[i], 13, 1e9 + 33);
				// string hash = hash1 + "_" + hash2;
				ans += hashMap[hash];
				hashMap[hash]++;
			}
		}
		return ans;
	}
};


space complexity: O(N * L) => string hash, O(N) => integer hashing

// 0 based node (0 .... N - 1)
// parent[i] = the parent of node i
// parent[root] = -1



// for each node, we will calculate how many children they have
// if no children, => leaf node


// if par[i] = x, then children[x]++;


// say node y is a leaf node, then if we remove y, then we can children[par[y]]--;
// in this process, par[y] can become a leaf node, if

vector<vector<int>> removeLeafNodesInOrder(vector<int> &parent) {
	int n = parent.size();
	vector<int> children(n);
	for (int i = 0; i < n; i++) {
		if (parent[i] != -1) {
			children[parent[i]]++;
		}
	}

	queue<int> leaves;
	for (int i = 0; i < n; i++) {
		if (children[i] == 0) {
			leaves.push_back(i);
		}
	}
	vector<vector<int>> leavesInOrder;
	while (!leaves.empty()) {
		int Sz = leaves.size();
		vector<int> curLeaves;
		for (int i = 0; i < Sz; i++) {
			int leaf = leaves[i];
			curLeaves.push_back(leaf);
			if (parent[leaf] != -1 && --children[parent[leaf]] == 0) {
				leaves.push(parent[leaf]);
			}
		}
		leavesInOrder.push_back(curLeaves);
	}
	return leavesInOrder;
}