#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Event {
    int x;    // x-coordinate (point in sweep line)
    int type; // 0 = add, 1 = remove
    int val;  // for add/remove: value of interval; for query: query index

    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return type < other.type; // process add before query before remove
    }
};

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
