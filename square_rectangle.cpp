axis parallel
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point &other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

int countAxisAlignedSquares(vector<Point> &points) {
    set<pair<int, int>> s;
    for (auto &p : points) s.insert({p.x, p.y});

    int count = 0;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = points[i].x, y1 = points[i].y;
            int x2 = points[j].x, y2 = points[j].y;

            // Check if diagonal can form a square
            if (abs(x1 - x2) == abs(y1 - y2) && x1 != x2 && y1 != y2) {
                if (s.count({x1, y2}) && s.count({x2, y1})) {
                    count++;
                }
            }
        }
    }
    // each square counted twice (two diagonals)
    return count / 2;
}

int main() {
    vector<Point> points = {{0, 0}, {1, 0}, {0, 1}, {1, 1}, {2, 0}, {2, 1}, {1, 2}, {2, 2}};
    cout << "Axis aligned squares: " << countAxisAlignedSquares(points) << endl;
}



##############################################################



digonal based solution:


#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int countAllSquares(vector<Point> &points) {
    set<pair<int, int>> s;
    for (auto &p : points) s.insert({p.x, p.y});

    int count = 0;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = points[i].x, y1 = points[i].y;
            int x2 = points[j].x, y2 = points[j].y;

            // midpoint
            double cx = (x1 + x2) / 2.0;
            double cy = (y1 + y2) / 2.0;

            // vector from center to one corner
            double dx = (x1 - x2) / 2.0;
            double dy = (y1 - y2) / 2.0;

            // rotate by 90 deg
            double px1 = cx - dy, py1 = cy + dx;
            double px2 = cx + dy, py2 = cy - dx;

            // Check if both rotated points exist (must be integer)
            if (fabs(px1 - round(px1)) < 1e-9 && fabs(py1 - round(py1)) < 1e-9 &&
                    fabs(px2 - round(px2)) < 1e-9 && fabs(py2 - round(py2)) < 1e-9) {

                if (s.count({(int)round(px1), (int)round(py1)}) &&
                        s.count({(int)round(px2), (int)round(py2)})) {
                    count++;
                }
            }
        }
    }
    // Each square counted twice (two diagonals)
    return count / 2;
}


// round(x) = closed integers of x = return value is in float/double, typecast to int
// fabs = abs for floating values

int main() {
    vector<Point> points = {{0, 0}, {1, 1}, {1, 0}, {0, 1}, {2, 0}, {2, 2}, {0, 2}, {2, 0}};
    cout << "Squares (any orientation): " << countAllSquares(points) << endl;
}




A, B, C, D

A = (x1, y1)
    C = (x2, y2)

        midpoint, O (c_x, c_y) = (x1 + x2) / 2, (y1 + y2) / 2
                                 vector vec(OA) = v = (dx, dy) = vec(A) - vec(O) = x1 - x2 / 2, y1 - y2 / 2

                                         hence A = O + vector(OA)
                                                 hence C = O - vector(OA)

                                                         v_perp = (-dy, dx),

                                                         C = O + v_perp = (cx - dy , cy + dx)
                                                                 D = O - v_perp = (cx + dy, cy - dx)



################################################################################

                                                                         side based solution:


#include <bits/stdc++.h>
                                                                         using namespace std;

struct Point {
    int x, y;
};

int countSquares(vector<Point> &points) {
    set<pair<int, int>> s;
    for (auto &p : points) s.insert({p.x, p.y});

    int count = 0;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = points[i].x, y1 = points[i].y;
            int x2 = points[j].x, y2 = points[j].y;

            int dx = x2 - x1;
            int dy = y2 - y1;

            // First possible square (90° rotation one way)
            pair<int, int> p3 = {x1 - dy, y1 + dx};
            pair<int, int> p4 = {x2 - dy, y2 + dx};

            if (s.count(p3) && s.count(p4)) count++;

            // Second possible square (90° rotation the other way)
            p3 = {x1 + dy, y1 - dx};
            p4 = {x2 + dy, y2 - dx};

            if (s.count(p3) && s.count(p4)) count++;
        }
    }

    // each square counted 4 times (once per side)
    return count / 4;
}

int main() {
    vector<Point> points = {{0, 0}, {1, 1}, {1, 0}, {0, 1}, {2, 0}, {2, 2}, {0, 2}, {2, 0}};
    cout << "Squares (any orientation): " << countSquares(points) << endl;
}

################################################################################

A = (x1, y1), B = (x2, y2), is a side of square

                  vec(AB) = v = vec(B) - vec(A) = (x2 - x1, y2 - y1) = (dx, dy)
                                v_perp = (-dy, dx)

                                        BC = C + v_perp = (x2 - dy, y2 + dx)
                                                AD = A + v_perp = (x1 - dy, y1 + dx)

                                                        other v_perp = (dy, -dx)



################################################################################


                                                                1. https://leetcode.com/problems/minimum-area-rectangle-ii/description/

                                                                m[ {diagonal_length, mid_point_x, mid_point_y}].push_back({i, j})
                                                                all the points pair that belong to the same key create a rectangle.

                                                                canuse unordered_map, create a string using to_string of the above 3 values





                                                                2. https://leetcode.com/problems/minimum-area-rectangle/description/
                                                                check my submission


