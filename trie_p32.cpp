// https://leetcode.com/discuss/post/6851754/google-phone-screening-l4-by-anonymous_u-nmt2/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

// Tree Node for decoding tree
struct TreeNode {
	unordered_map<char, TreeNode*> children;
	string decodedString; // Non-empty if this node ends a decoded string

	TreeNode() : decodedString("") {}
};

class DecoderIterator {
	TreeNode* root;
	string encodedString;
	int index; // current index in encoded string
	queue<char> outputBuffer; // buffer for decoded characters yet to be returned

public:
	// Constructor: takes the decoding tree root and the encoded string
	DecoderIterator(TreeNode* _root, const string& _encodedString)
		: root(_root), encodedString(_encodedString), index(0) {}

	bool fun() {
		TreeNode* curr = root;
		while (index < encodedString.size()) {
			char c = encodedString[index++];
			if (curr->children.count(c)) {
				curr = curr->children[c];
				if (!curr->decodedString.empty()) {
					for (char dc : curr->decodedString) {
						outputBuffer.push(dc);
					}
					return true;
				}
			} else {
				break;
			}
		}
		return false;
	}
	char next() {
		if (!hasNext()) throw runtime_error("No more characters!");
		char ch = outputBuffer.front();
		outputBuffer.pop();
		return ch;
	}

	// Returns true if there are more decoded characters
	bool hasNext() {
		if (!outputBuffer.empty()) return true;
		if (index == encodedString.size()) return false;
		return fun() ;
	}
};

// Helper to insert a decoding path into the tree
void insert(TreeNode* root, const string& path, const string& decodedString) {
	TreeNode* curr = root;
	for (char c : path) {
		if (!curr->children.count(c)) {
			curr->children[c] = new TreeNode();
		}
		curr = curr->children[c];
	}
	curr->decodedString = decodedString;
}

int main() {
	// Build the decoding tree
	TreeNode* root = new TreeNode();
	insert(root, "ABGH", "Hello");
	insert(root, "BCD", " ");
	insert(root, "DE", "there");

	// Encoded string
	string encodedString = "ABGHBCDDE";

	// Create the iterator
	DecoderIterator decoder(root, encodedString);

	// Decode and print
	while (decoder.hasNext()) {
		cout << decoder.next();
	}
	cout << endl;

	// Clean up memory (optional here, but good practice)
	// ... (can be added using recursion to delete all nodes if needed)

	return 0;
}


class Solution {
public:
	int minTime(int n, vector<vector<int>>& edges) {
		vector<vector<tuple<int, int, int>>> g(n);
		for (auto&e : edges)g[e[0]].emplace_back(e[1], e[2], e[3]);
		const long long INF = LLONG_MAX;
		vector<long long> dist(n, INF);
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
		dist[0] = 0;
		pq.emplace(0, 0);
		while (!pq.empty()) {
			auto [t, u] = pq.top(); pq.pop();
			if (t > dist[u])continue;
			if (u == n - 1)break;
			for (auto&[v, s, e] : g[u]) {
				long long nt;
				if (t > e)continue;
				nt = (t < s ? s : t) + 1;
				if (nt < dist[v]) {
					dist[v] = nt;
					pq.emplace(nt, v);
				}
			}
		}
		return dist[n - 1] == INF ? -1 : dist[n - 1];
	}
};