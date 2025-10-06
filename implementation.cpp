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





// https://leetcode.com/discuss/post/5367360/google-l3-offer-bangalore-by-anonymous_u-pxk5/



// We are given an array of integer, and a number k. We have to find the maximum consequtive occurance of number k in the array.
// There were many follow up questions around the same concepts.

// Instead of k we are given an array, for each array element find the max consequtive occurance.
// If we can modify c elements then what will be the max consequtive occurance.

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    unordered_map<int, vector<int>> rangeMap;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        rangeMap[a[i]].push_back(i);
    }
    int answer = 0;
    for (auto x : rangeMap) {
        vector<int> ranges = x.second;
        int l = 0;
        int op = 0;
        for (int r = 0; r < ranges.size(); r++) {
            if (r > l) {
                op += ranges[r] - ranges[r - 1] - 1;
            }
            while (op > k) {
                op -= ranges[l + 1] - ranges[l] - 1;
                l++;
            }
            answer = max(answer, min(n, ranges[r] - ranges[l] + 1 - (k - op)));
        }
    }
    cout << answer << endl;
}


