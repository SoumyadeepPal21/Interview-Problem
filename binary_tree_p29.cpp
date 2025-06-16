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
