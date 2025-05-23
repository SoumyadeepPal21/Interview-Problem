// https://leetcode.com/discuss/post/5367360/google-l3-offer-bangalore-by-anonymous_u-pxk5/


// You are given a tree node (Root) at start. Write two methods
// a. addNode(TreeNode *parent, int val) == => Create a new node and add it to its parent. Parent pointer was given as argument for this function.
// b. getRandomNode() == > Gives a random node from the tree

// Follow up : getRandomLeafNode() => Give a random leaf node.

//     All the methods must be in O(1).

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>  // rand()
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int v) : val(v) {}
};

class RandomTree {
private:
    TreeNode* root;
    vector<TreeNode*> allNodes;
    vector<TreeNode*> leafNodes;

    unordered_map<TreeNode*, int> leafIndex;  // To update leafNodes efficiently

public:
    RandomTree(int rootVal) {
        root = new TreeNode(rootVal);
        allNodes.push_back(root);
        leafNodes.push_back(root);
        leafIndex[root] = 0;
    }

    void addNode(TreeNode* parent, int val) {
        TreeNode* newNode = new TreeNode(val);
        parent->children.push_back(newNode);
        allNodes.push_back(newNode);

        // New node is a leaf
        leafNodes.push_back(newNode);
        leafIndex[newNode] = leafNodes.size() - 1;

        // Parent may no longer be a leaf
        if (leafIndex.find(parent) != leafIndex.end()) {
            int idx = leafIndex[parent];
            leafNodes[idx] = leafNodes.back();
            leafIndex[leafNodes[idx]] = idx;
            leafNodes.pop_back();
            leafIndex.erase(parent);
        }
    }

    TreeNode* getRandomNode() {
        int idx = rand() % allNodes.size();
        return allNodes[idx];
    }

    TreeNode* getRandomLeafNode() {
        int idx = rand() % leafNodes.size();
        return leafNodes[idx];
    }
};


// Given an array of size n and an integer k where k << n. Also for each element,
// the absolute difference b/w its current position and sorted position is <= k.
// We have to sort the array.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sortKSortedArray(vector<int>& arr, int k) {
    int n = arr.size();
    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Step 1: Push first k+1 elements into the heap
    for (int i = 0; i <= k && i < n; ++i) {
        minHeap.push(arr[i]);
    }

    int index = 0;
    // Step 2: For the rest of the elements, push into heap and pop the smallest
    for (int i = k + 1; i < n; ++i) {
        arr[index++] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]);
    }

    // Step 3: Pop remaining elements
    while (!minHeap.empty()) {
        arr[index++] = minHeap.top();
        minHeap.pop();
    }
}

// Example usage
int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    sortKSortedArray(arr, k);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
