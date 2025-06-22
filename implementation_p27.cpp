#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<pair<int, int>> events;

    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, 0});
    }

    sort(events.begin(), events.end());

    int active = 0;
    int left = 0;
    vector<pair<int, int>> ans;
    for (auto& e : events) {
        if (e.second == 1) {
            if (++active == P) {
                left = e.first;
            }
        } else {
            if (--active == P - 1) {
                ans.push_back({left, e.first - 1});
            }
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}




void dfs(TreeNode* root, int cnt, bool isParentIsland) {
    if (!root) return;

    if (root->val == 0) {
        dfs(root->left, cnt, false);
        dfs(root->right, cnt, false);
    }
}




class MovieRater {
    int n;
public:
    MovieRater(int n) {
        this->n = n;
    }
    void insertMovie(int id, int rating) {

    }
    void addSimilarMovie(int id, int )
};



