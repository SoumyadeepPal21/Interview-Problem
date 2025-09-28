// Android phone patterns : Given n, m which are a set of points, we have to find the total possible unique patterns that can be drawn, min len of a pattern is 1, n, m >= 1
// https://leetcode.com/discuss/post/6245697/google-l4-phone-screen-by-anonymous_user-ymt7/
// onsite 1

#include <bits/stdc++.h>
using namespace std;

int n, m;
int totalPoints;
vector<vector<vector<int>>> skipList;  // skipList[u][v] = list of required visited points
vector<bool> visited;

int idx(int r, int c) {
    return r * m + c;
}

// Compute all intermediate points between (r1,c1) and (r2,c2) if they are collinear
vector<int> getIntermediatePoints(int r1, int c1, int r2, int c2) {
    vector<int> res;
    int stepR = 1;
    int stepC = 1;
    if (r1 == r2) stepR = 0;
    else if (r1 > r2) stepR = -1;
    if (c1 == c2) stepC = 0;
    else if (c1 > c2) stepC = -1;

    int cr = r1 + stepR, cc = c1 + stepC;
    while (cr != r2 || cc != c2) {
        res.push_back(idx(cr, cc));
        cr += stepR;
        cc += stepC;
    }
    return res;
}

// Build skipList for all pairs
void buildSkip() {
    skipList.assign(totalPoints, vector<vector<int>>(totalPoints));
    for (int r1 = 0; r1 < n; r1++) {
        for (int c1 = 0; c1 < m; c1++) {
            for (int r2 = 0; r2 < n; r2++) {
                for (int c2 = 0; c2 < m; c2++) {
                    if (r1 == r2 && c1 == c2) continue;
                    int u = idx(r1, c1);
                    int v = idx(r2, c2);
                    skipList[u][v] = getIntermediatePoints(r1, c1, r2, c2);
                }
            }
        }
    }
}

// DFS with generalized skip check
long long dfs(int u, int depth) {
    visited[u] = true;
    long long count = 1;

    for (int v = 0; v < totalPoints; v++) {
        if (!visited[v]) {
            bool ok = true;
            for (int mid : skipList[u][v]) {
                if (!visited[mid]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                count += dfs(v, depth + 1);
            }
        }
    }

    visited[u] = false;
    return count;
}

long long countPatterns(int N, int M) {
    n = N; m = M;
    totalPoints = n * m;
    buildSkip();
    visited.assign(totalPoints, false);

    long long total = 0;
    for (int i = 0; i < totalPoints; i++) {
        total += dfs(i, 1);
    }
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n <= 5 && m <= 5 && n * m <= 12) {
        cout << countPatterns(n, m) << "\n";
    } else {
        cout << "Constraints violated\n";
    }
    return 0;
}


// skip[x][y] -> contains all the intermediate points that needs to be visited from x to y
