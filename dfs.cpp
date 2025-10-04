// https://leetcode.com/discuss/post/6084864/google-l4-interview-expereince-by-anonym-b142/


// We define an organic molecule by a list of atoms, and a list of bonds between any two of them. For example, the following formaldehyde molecule:

// H
// |
// H-C=O
// is represented as:

// atoms: {1: 'C', 2: 'H', 3: 'H', 4: 'O'}
// bonds: [[1, 2], [1, 3], [1, 4], [1, 4]]
// The input does not have to be strictly in this format, as long as it delivers the information.

// Given an input representing a molecule consisting only of Carbon, Oxygen and Hydrogen atoms, determine if it's valid.

// A molecule is valid if every atom has the required number of bonds:

// C atoms require exactly 4 bonds
// O atoms require exactly 2 bonds
// H atoms require exactly 1 bond

// FOLLOW UP QUESTION:

// We assume that each input represents one molecule. Multiple, disconnected molecules are considered invalid. Consider the following example:

// O=C=O H-H

// which would represented as
// atoms: {1: 'C', 2: 'O', 3: 'O', 4: 'H', 5: 'H'}
// bonds: [[1, 2], [1, 2], [1, 3], [1, 3], [4, 5]]
// This input is invalid because it consists of 2 separate molecules. How would you modify your program to detect this situation?

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

// Function to perform DFS to check connectivity
void dfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
    stack<int> s;
    s.push(node);
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        if (visited.count(current)) continue;
        visited.insert(current);
        for (int neighbor : adj[current]) {
            if (!visited.count(neighbor)) {
                s.push(neighbor);
            }
        }
    }
}

// Function to validate the molecule
bool isValidMolecule(const unordered_map<int, char>& atoms, const vector<vector<int>>& bonds) {
    unordered_map<int, int> bondCount;
    unordered_map<int, vector<int>> adj;

    // Build bond count and adjacency list
    for (const auto& bond : bonds) {
        if (bond.size() != 2) continue;
        int a = bond[0], b = bond[1];
        bondCount[a]++;
        bondCount[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Check bond validity
    for (const auto& [id, atom] : atoms) {
        int count = bondCount[id];
        if ((atom == 'C' && count != 4) ||
                (atom == 'O' && count != 2) ||
                (atom == 'H' && count != 1)) {
            return false;
        }
    }

    // Check connectivity
    if (atoms.empty()) return false;
    unordered_set<int> visited;
    dfs(atoms.begin()->first, adj, visited);
    if (visited.size() != atoms.size()) {
        return false; // Not all atoms are connected
    }

    return true;
}

int main() {
    // Invalid example: O=C=O and H-H (disconnected)
    unordered_map<int, char> atoms = {
        {1, 'C'},
        {2, 'O'},
        {3, 'O'},
        {4, 'H'},
        {5, 'H'}
    };

    vector<vector<int>> bonds = {
        {1, 2}, {1, 2},  // C=O
        {1, 3}, {1, 3},  // C=O
        {4, 5}           // H-H (separate molecule)
    };

    cout << (isValidMolecule(atoms, bonds) ? "Valid" : "Invalid") << endl;

    return 0;
}
