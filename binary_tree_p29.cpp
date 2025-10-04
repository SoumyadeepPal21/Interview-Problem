// https://leetcode.com/discuss/post/6796476/google-india-software-engineer-l4-interv-ijaj/
void merge(TreeNode* A, TreeNode* B) {
    if (B != nullptr) {
        A->val = B->val;
        for (TreeNode* child : B->children) {
            bValMap[child->key] = child;
        }
    }
    for (TreeNode* child : A->children) {
        if (!bValMap.count(child->key)) {
            merge(child, bValMap);
        } else {
            merge(child, nullptr);
        }
        AValMap[child->key] = child;
    }
    if (B->children != nullptr) {
        for (TreeNode* child : B->children) {
            if (!AValMap.count(child->key)) {
                A->children.push_back(child);
                merge(child, nullptr);
            }
        }
    }
}





2. // https://leetcode.com/discuss/post/6033289/google-l3-interview-experience-oct-2024-0xzt8/
struct TreeNode {
    vector<TreeNode*> children;
    vector<int> weights;
};



long long delteLeafs(TreeNode* node) {
    long long res = 0;
    for (int i = 0; i < children.size(); i++) {
        res += min(weights[i], deleteLeafs(children[i]);
    }
           if (children.size() == 0) return INT_MAX;
    return res;
}

3.
// There are n number of routers connected to each other at some distances. A source router src will receive a message and broadcast it to all routers within specified distance d. Return True/False weather destination router des got the message or not. (Simple BFS algorithm).
// Given: router names and their distances, src, des and d.
// FollowUp: Message goes only to first nearest router. Return True/False for the same question.



O(N ^ 2) -> create graph
O(N * D) -> bfs


