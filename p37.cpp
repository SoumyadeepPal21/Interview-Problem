// https://leetcode.com/discuss/post/6661269/google-l3-interview-questions-bangalore-xg7t9/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

typedef pair<int, int> Point2D; // A 2D Point
typedef pair<int, int> Cell;    // A Grid Cell

// Hash function for unordered_map key (cell)
struct CellHash {
    size_t operator()(const Cell& c) const {
        return hash<long long>()(((long long)c.first) << 32 | (unsigned int)c.second);
    }
};

// Compute Euclidean Distance between two points
double distance(const Point2D& a, const Point2D& b) {
    return hypot(a.first - b.first, a.second - b.second);
}

// Get the cell in which this point falls
Cell getCell(const Point2D& p, double d) {
    int i = floor(p.first / d);
    int j = floor(p.second / d);
    return {i, j};
}

vector<vector<Point2D>> processStream2D(const vector<Point2D>& stream, double d) {
    unordered_map<Cell, vector<Point2D>, CellHash> grid;
    vector<vector<Point2D>> result;

    for (const auto& point : stream) {
        Cell cell = getCell(point, d);
        vector<pair<Cell, Point2D>> candidates;

        // Check 9 neighboring cells
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                Cell neighbor = {cell.first + dx, cell.second + dy};
                if (grid.count(neighbor)) {
                    for (const auto& other : grid[neighbor]) {
                        if (distance(point, other) <= d)
                            candidates.emplace_back(neighbor, other);
                    }
                }
            }
        }

        // Try to find 2 valid neighbors to form a triplet
        bool tripletFormed = false;
        for (int i = 0; i < candidates.size(); i++) {
            for (int j = i + 1; j < candidates.size(); j++) {
                auto [cell1, p1] = candidates[i];
                auto [cell2, p2] = candidates[j];
                if (distance(p1, p2) <= d) {
                    // Found valid triplet
                    result.push_back({point, p1, p2});

                    // Remove p1 and p2 from their respective cells
                    auto& vec1 = grid[cell1];
                    vec1.erase(remove(vec1.begin(), vec1.end(), p1), vec1.end());

                    auto& vec2 = grid[cell2];
                    vec2.erase(remove(vec2.begin(), vec2.end(), p2), vec2.end());

                    tripletFormed = true;
                    break;
                }
            }
            if (tripletFormed) break;
        }

        if (!tripletFormed) {
            // Store this point for future triplets
            grid[cell].push_back(point);
        }
    }

    return result;
}

int main() {
    vector<Point2D> stream = { {1, 1}, {11, 11}, {12, 12}, {13, 13}, {2, 2}, {3, 3} };
    double d = 3.0;

    auto triplets = processStream2D(stream, d);

    cout << "Triplets formed:\n";
    for (const auto& triplet : triplets) {
        cout << "[ ";
        for (const auto& p : triplet)
            cout << "(" << p.first << "," << p.second << ") ";
        cout << "]\n";
    }

    return 0;
}
