// https://leetcode.com/discuss/post/5720580/google-swe-2-l3-bangalorehyd-aug-24-by-a-7kr8/

// Given a set of points find 4 points which form a rectangle and has largest area of any such rectangle. // consider axes of rectangle parallel to x and y axis
// In part 2- axis of rectangle is not parallel to x and y axis
#include <bits/stdc++.h>
using namespace std;

int maxAxisAlignedRectangleArea(vector<pair<int, int>>& points) {
    unordered_set<string> pointSet;
    for (auto& p : points) {
        pointSet.insert(to_string(p.first) + "," + to_string(p.second));
    }

    int maxArea = 0;
    int n = points.size();

    for (int i = 0; i < n; ++i) {
        auto [x1, y1] = points[i];
        for (int j = i + 1; j < n; ++j) {
            auto [x2, y2] = points[j];
            if (x1 != x2 && y1 != y2) {
                // Check for existence of the other two corners
                string p3 = to_string(x1) + "," + to_string(y2);
                string p4 = to_string(x2) + "," + to_string(y1);
                if (pointSet.count(p3) && pointSet.count(p4)) {
                    int area = abs(x2 - x1) * abs(y2 - y1);
                    maxArea = max(maxArea, area);
                }
            }
        }
    }

    return maxArea;
}



#include <bits/stdc++.h>
using namespace std;

using Point = pair<int, int>;
using ll = long long;

ll distSq(Point& a, Point& b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}

double maxRotatedRectangleArea(vector<Point>& points) {
    unordered_map<string, vector<pair<Point, Point>>> mp;
    int n = points.size();
    double maxArea = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto [x1, y1] = points[i];
            auto [x2, y2] = points[j];
            double mx = (x1 + x2) / 2.0;
            double my = (y1 + y2) / 2.0;
            double d = distSq(points[i], points[j]);

            string key = to_string(mx) + "," + to_string(my) + "," + to_string(d);
            mp[key].emplace_back(points[i], points[j]);
        }
    }

    for (auto& [_, vec] : mp) {
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = i + 1; j < vec.size(); ++j) {
                auto [a, b] = vec[i];
                auto [c, d] = vec[j];
                double side1 = sqrt(distSq(a, c));
                double side2 = sqrt(distSq(a, d));
                double area = side1 * side2;
                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}
