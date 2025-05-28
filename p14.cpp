// https://leetcode.com/discuss/post/2001716/google-l4-reject-l3-offer-bangalore-marc-b7ew/

// We are given rules in the form of
// For example:

// P1 is in North of P2
// P2 is in North of P3
// P3 is in North of P1

// Output: False (since P3 will be in South of P1)

// Directions can be N, S, W, E, NW, NE, SW, etc.


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <string>
#include <queue>
using namespace std;

// Structure for Bellman-Ford edge
struct Edge {
    string from, to;
    int weight;
};

unordered_map<string, pair<int, int>> directionMap = {
    {"N", {0, 1}}, {"S", {0, -1}}, {"E", {1, 0}}, {"W", { -1, 0}},
    {"NE", {1, 1}}, {"NW", { -1, 1}}, {"SE", {1, -1}}, {"SW", { -1, -1}}
};

// ---------------------- TOPOLOGICAL SORT METHOD ----------------------
unordered_map<string, vector<string>> buildTopoGraph(
const vector<tuple<string, string, string>>& constraints, bool isX) {

    unordered_map<string, vector<string>> graph;

    for (const auto& [a, dir, b] : constraints) {
        auto [dx, dy] = directionMap[dir];

        if (isX && dx != 0) {
            if (dx > 0) graph[b].push_back(a); // x[a] > x[b]
            else        graph[a].push_back(b); // x[a] < x[b]
        }

        if (!isX && dy != 0) {
            if (dy > 0) graph[b].push_back(a); // y[a] > y[b]
            else        graph[a].push_back(b); // y[a] < y[b]
        }
    }

    return graph;
}

bool dfs(const string& node, unordered_map<string, vector<string>>& graph,
         unordered_set<string>& visiting, unordered_set<string>& visited) {
    visiting.insert(node);
    for (const auto& neighbor : graph[node]) {
        if (visited.count(neighbor)) continue;
        if (visiting.count(neighbor)) return true; // cycle
        if (dfs(neighbor, graph, visiting, visited)) return true;
    }
    visiting.erase(node);
    visited.insert(node);
    return false;
}

bool hasTopoCycle(unordered_map<string, vector<string>>& graph) {
    unordered_set<string> visited, visiting;
    for (const auto& [node, _] : graph) {
        if (!visited.count(node)) {
            if (dfs(node, graph, visiting, visited)) return true;
        }
    }
    return false;
}

// ---------------------- BELLMAN-FORD METHOD ----------------------
unordered_map<string, vector<Edge>> buildBellmanGraph(
const vector<tuple<string, string, string>>& constraints, bool isX) {

    unordered_map<string, vector<Edge>> graph;

    for (const auto& [a, dir, b] : constraints) {
        auto [dx, dy] = directionMap[dir];

        if (isX && dx != 0) {
            if (dx > 0) graph[b].push_back({b, a, 1}); // x[a] ≥ x[b] + 1
            else        graph[a].push_back({a, b, 1}); // x[b] ≥ x[a] + 1
        }

        if (!isX && dy != 0) {
            if (dy > 0) graph[b].push_back({b, a, 1}); // y[a] ≥ y[b] + 1
            else        graph[a].push_back({a, b, 1}); // y[b] ≥ y[a] + 1
        }
    }

    return graph;
}

bool bellmanFord(unordered_map<string, vector<Edge>>& graph) {
    unordered_map<string, int> dist;
    unordered_set<string> nodes;

    for (const auto& [u, edges] : graph) {
        nodes.insert(u);
        for (const auto& e : edges) {
            nodes.insert(e.to);
        }
    }

    for (int i = 0; i < nodes.size(); ++i) {
        bool updated = false;
        for (const auto& [u, edges] : graph) {
            for (const auto& e : edges) {
                if (dist[e.to] < dist[e.from] + e.weight) {
                    dist[e.to] = dist[e.from] + e.weight;
                    updated = true;
                }
            }
        }
        if (!updated) return true; // No cycles
    }

    return false; // Cycle detected
}

// ---------------------- WRAPPER ----------------------

bool checkWithTopoSort(const vector<tuple<string, string, string>>& constraints) {
    auto gx = buildTopoGraph(constraints, true);
    auto gy = buildTopoGraph(constraints, false);
    return !hasTopoCycle(gx) && !hasTopoCycle(gy);
}

bool checkWithBellmanFord(const vector<tuple<string, string, string>>& constraints) {
    auto gx = buildBellmanGraph(constraints, true);
    auto gy = buildBellmanGraph(constraints, false);
    return bellmanFord(gx) && bellmanFord(gy);
}

// ---------------------- MAIN ----------------------

int main() {
    vector<tuple<string, string, string>> constraints = {
        {"P1", "N", "P2"},
        {"P2", "N", "P3"},
        {"P3", "N", "P1"} // Contradiction
    };

    cout << "Topo Sort Check: " << (checkWithTopoSort(constraints) ? "True" : "False") << endl;
    cout << "Bellman-Ford Check: " << (checkWithBellmanFord(constraints) ? "True" : "False") << endl;

    return 0;
}
