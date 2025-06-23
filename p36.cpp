struct TreeNode {
  string name;
  vector<TreeNode*> children;
  TreeNode(string name) {
    this->name = name;
  }
};

struct TrieNode {
  TrieNode* child[26];
  bool stringEnd;
  TreeNode* treeNode;
};


class TreeTrie {
  TrieNode* trieRoot;
public:

  TreeTrie() {
    trieRoot = new TrieNode();
    trieRoot->treeRoot = new TreeNode("");
  }

  void insert(string& name) {
    TreeRoot* node = trieRoot;
    TreeNode* lastTreeNode = node->treeNode;
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
    node->treeNode = new TreeNode(name);
    lastTreeNode->children.push_back(node->treeNode);
  }

  TreeNode* findTreeRoot() {
    return trieRoot->treeNode;
  }
};



TreeNode* findTree(vector<string> names) {
  sort(names.begin(), names.end(), [&](const string & a, const string & b) {
    return a.size() < b.size();
  });
  TreeTrie* trie = new TreeTrie();
  for (string s : names) {
    trie.insert(s);
  }
  return trie->findTreeRoot();
}