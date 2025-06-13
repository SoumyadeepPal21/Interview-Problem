// https://leetcode.com/discuss/post/6734621/google-l4-bangalore-reject-by-anonymous_-kftq/

// round 1

############# recursion

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent an expression and its evaluated result
struct Expr {
    int val;
    string exp;
};

// Recursively generate all expressions between nums[l...r]
vector<Expr> generate(int l, int r, const vector<int>& nums) {
    vector<Expr> result;

    // Base case: only one number (handle negative numbers properly)
    if (l == r) {
        result.push_back({nums[l], to_string(nums[l])});
        return result;
    }

    // Try every possible split between l and r
    for (int i = l; i < r; ++i) {
        vector<Expr> left = generate(l, i, nums);
        vector<Expr> right = generate(i + 1, r, nums);

        // Combine all possible left and right expressions
        for (const auto& le : left) {
            for (const auto& ri : right) {
                // Addition
                result.push_back({le.val + ri.val, "(" + le.exp + " + " + ri.exp + ")"});
                // Multiplication
                result.push_back({le.val * ri.val, "(" + le.exp + " * " + ri.exp + ")"});
            }
        }
    }
    return result;
}

// Find all expressions that evaluate to the target
vector<string> findExpressions(const vector<int>& nums, int target) {
    vector<string> answers;
    vector<Expr> expressions = generate(0, nums.size() - 1, nums);

    for (const auto& e : expressions) {
        if (e.val == target) {
            answers.push_back(e.exp);
        }
    }
    return answers;
}

int main() {
    // Example with negative number
    vector<int> nums = {2, -3, 4};  // Now handles negative numbers
    int target = -2;

    vector<string> expressions = findExpressions(nums, target);
    cout << "Expressions that evaluate to " << target << ":\n";
    for (const auto& expr : expressions) {
        cout << expr << endl;
    }

    return 0;
}


################# dp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Expr struct to hold value and expression string
struct Expr {
    int val;
    string exp;
};

vector<string> findExpressions(vector<int>& nums, int target) {
    int n = nums.size();
    // DP table: dp[l][r] holds all possible {val, expr} for subarray nums[l..r]
    vector<vector<vector<Expr>>> dp(n, vector<vector<Expr>>(n));

    // Base case: single number
    for (int i = 0; i < n; i++) {
        dp[i][i].push_back({nums[i], to_string(nums[i])});
    }

    // Build DP for all lengths > 1
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l <= n - len; l++) {
            int r = l + len - 1;
            // Split at every possible k
            for (int k = l; k < r; k++) {
                for (const auto& le : dp[l][k]) {
                    for (const auto& ri : dp[k + 1][r]) {
                        // Addition
                        dp[l][r].push_back({le.val + ri.val, "(" + le.exp + " + " + ri.exp + ")"});
                        // Subtraction
                        dp[l][r].push_back({le.val - ri.val, "(" + le.exp + " - " + ri.exp + ")"});
                        // Multiplication
                        dp[l][r].push_back({le.val * ri.val, "(" + le.exp + " * " + ri.exp + ")"});
                    }
                }
            }
        }
    }

    // Collect expressions matching target
    vector<string> result;
    for (const auto& e : dp[0][n - 1]) {
        if (e.val == target) {
            result.push_back(e.exp);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {2, -3, 4, 5}; // Example with 4 numbers
    int target = 7;

    vector<string> expressions = findExpressions(nums, target);
    cout << "Expressions that evaluate to " << target << ":\n";
    for (const auto& expr : expressions) {
        cout << expr << endl;
    }

    return 0;
}
