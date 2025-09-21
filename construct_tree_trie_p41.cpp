// https://leetcode.com/discuss/post/6647864/another-google-l3-post-not-what-i-expect-wq86/


// Design, Implement and Test a Tree, which is built on the following rules

// You are given a list of strings: ["apple", "app", "bat", "batter", "battle", "cat"]

// The root of the tree is an empty string.

// For any string in the list, if there exists another string that is a prefix of it, then the shorter string becomes the parent node of the longer string. If there are multiple possible parents, choose the longest prefix as the parent.

// For example, "app" is a prefix of "apple", so "app" becomes the parent of "apple".

// Your task is to build and represent this tree structure.

//            ""
//          / | \
//       app bat cat
//       /   /  \
//  apple  batter battle


class TrieNode {
public:
	TrieNode(char ch) {
		this->ch = ch;
	}
	~TrieNode() {
		for (int i = 0; i < 26; i++) {
			if (child[i] != nullptr) delete child[i];
		}
	}
	TreeNode* child[26];
	char ch;
}


Class Trie {
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode("");
	}

	~Trie() {
		if (root != nullptr) delete root;
	}

	void insert(string & word) {
		for (int i = 0; i < word.size(); i++) {
			char ch = word[i];
			if (node->child[ch - 'a'] == nullptr) {
				node->child[ch - 'a'] = new TrieNode(ch);
			}
			node = node->child[ch - 'a'];
		}
		node->isEnd = true;
	}


	string findLongestCommonPrefix(string & word) {
		string lcp = "";
		int last = -1;
		for (int i = 0; i < word.size(); i++) {
			char ch = word[i];
			if (node->child[ch - 'a'] == nullptr) {
				break;
			}
			node = node->child[ch - 'a'];
			if (node->isEnd) {
				for (int j = last + 1; j <= i; j++) {
					lcp.push_back(word[j]);
				}
				last = i;
			}
		}
		return lcp;
	}
};

class TreeNode {
	string name;
	vector<TreeNode*> children;
public:
	TreeNode(string word) {
		this->name = word;
	}
	void addChildren(TreeNode* node) {
		children.push_back(node);
	}
};

class TreeConstructor {
	map<string, TreeNode*> nodeMap;
	TreeNode* root;
public:
	TreeConstructor() {
		root = new TreeNode("");
	}

	TreeNode* constructTree(vector<string>& words) {
		sort(words.begin(), words.end(), [&](string word1, string word2) {
			return word1.size() < word2.size();
		});

		Trie T;
		for (string &word : words) {
			string lcp = T.findLongestCommonPrefix(word);
			TreeNode* parent = nodeMap[lcp];
			TreeNode* node = new TreeNode(word);
			parent.addChildren(node);
			nodeMap[word] = node;
			T.add(word);
		}

		return root;
	}

};