// https://leetcode.com/discuss/post/5958167/interview-experience-with-google-l4-bang-37xu/

// You are given multiple rectangles, each represented by four integers (x1, y1, x2, y2). The task is to calculate the total area covered by the union of these rectangles.

#include <bits/stdc++.h>
using namespace std;

struct Event {
    int x, y1, y2, type; // type: +1 = start, -1 = end
    bool operator<(const Event& e) const {
        return x < e.x;
    }
};

class SegmentTree {
public:
    SegmentTree(int n) : count(4 * n), length(4 * n), ys() {}

    void build(const vector<int>& y_coords) {
        ys = y_coords;
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            count[node] += val;
        } else {
            int m = (l + r) / 2;
            update(2 * node, l, m, ql, qr, val);
            update(2 * node + 1, m, r, ql, qr, val);
        }
        if (count[node] > 0) {
            length[node] = ys[r] - ys[l];
        } else {
            if (r - l == 1) length[node] = 0;
            else length[node] = length[2 * node] + length[2 * node + 1];
        }
    }

    int total() {
        return length[1];
    }

private:
    vector<int> count, length, ys;
};

int main() {
    int n;
    cin >> n;

    vector<Event> events;
    vector<int> y_vals;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
        y_vals.push_back(y1);
        y_vals.push_back(y2);
    }

    // Coordinate compression
    sort(y_vals.begin(), y_vals.end());
    y_vals.erase(unique(y_vals.begin(), y_vals.end()), y_vals.end());

    // Map y to index
    auto getY = [&](int y) {
        return lower_bound(y_vals.begin(), y_vals.end(), y) - y_vals.begin();
    };

    for (auto& e : events) {
        e.y1 = getY(e.y1);
        e.y2 = getY(e.y2);
    }

    sort(events.begin(), events.end());

    SegmentTree st(y_vals.size());
    st.build(y_vals);

    long long area = 0;
    int prev_x = events[0].x;

    for (const auto& e : events) {
        int dx = e.x - prev_x;
        area += 1LL * st.total() * dx;
        st.update(1, 0, y_vals.size() - 1, e.y1, e.y2, e.type);
        prev_x = e.x;
    }

    cout << area << "\n";
    return 0;
}
