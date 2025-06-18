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
