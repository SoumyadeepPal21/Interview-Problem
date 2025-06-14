https://leetcode.com/discuss/post/6704429/google-interview-chances-by-anonymous_us-64v9/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Event {
    int x;    // x-coordinate (point in sweep line)
    int type; // 0 = add, 1 = remove, 2 = query
    int val;  // for add/remove: value of interval; for query: query index

    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return type < other.type; // process add before query before remove
    }
};

int main() {
    int N, Q;
    cin >> N;

    vector<Event> events;

    // Read intervals
    for (int i = 0; i < N; ++i) {
        int l, r, val;
        cin >> l >> r >> val;
        events.push_back({l, 0, val});       // add event
        events.push_back({r + 1, 1, val});   // remove event
    }

    cin >> Q;
    vector<int> queries(Q);
    vector<int> ans(Q);

    // Read queries
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
        events.push_back({queries[i], 2, i}); // query event
    }

    // Sort all events
    sort(events.begin(), events.end());

    multiset<int> active;

    // Process events
    for (auto& e : events) {
        if (e.type == 0) { // add interval
            active.insert(e.val);
        } else if (e.type == 1) { // remove interval
            active.erase(active.find(e.val));
        } else { // query
            if (!active.empty())
                ans[e.val] = *active.rbegin(); // max value
            else
                ans[e.val] = -1; // no interval covers this point
        }
    }

    // Output answers
    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}
