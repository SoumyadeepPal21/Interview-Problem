// https://leetcode.com/discuss/post/5535080/l3-interview-round-1-by-anonymous_user-e11w/

// Question - Given a formula of letters with parentheses, remove all parentheses from the formula.
// Examples:
// a-(b + c) -> a - b - c
// a-(a - b) -> b


#include <bits/stdc++.h>


using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    stack<int> stk;
    map<char, int> freq;
    int lastSign = 1;
    int neg = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            lastSign = 1;
        } else if (s[i] == '-') {
            lastSign = -1;
        } else if (s[i] == '(') {
            if (lastSign == -1) {
                neg++;
                stk.push(1);
            } else {
                stk.push(0);
            }
            lastSign = 1;
        } else if (s[i] == ')') {
            neg -= stk.top();
            stk.pop();
            lastSign = 1;
        } else {
            freq[s[i]] += (lastSign * ((neg % 2) ? -1 : 1));
        }
    }
    string ans = "expression: ";
    for (auto [ch, cnt] : freq) {
        if (cnt > 0) {
            ans += "+";
            if (cnt > 1)
                ans += to_string(cnt);
            ans.push_back(ch);
        } else if (cnt < 0) {
            ans += "-";
            if (cnt < -1)
                ans += to_string(cnt);
            ans.push_back(ch);
        }
    }
    cout << ans;

}

















// https://leetcode.com/discuss/post/6033289/google-l3-interview-experience-oct-2024-0xzt8/

// Compute: add(sub(-5,10),mul(5,pow(2,5)))


// try to handle to invalid expression case too
// https://leetcode.com/discuss/post/2402978/google-interview-question-data-structure-28sb/


#include <bits/stdc++.h>
using namespace std;

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}



char findOperator(string opr) {
    if (opr == "add") return '+';
    if (opr == "div") return '/';
    if (opr == "sub") return '-';
    if (opr == "mul") return '*';
    return 'x';
}

int recursion(string s, int l, int r) {
    if (isDigit(s[l]) || s[l] == '-') {
        int mul = 1;
        if (s[l] == '-') mul = -1;
        int num = 0;
        for (int i = l + (s[l] == '-'); i <= r; i++) {
            if (s[l] == '-' || !isDigit(s[i])) return -1;
            num = num * 10 + (s[i] - '0');
        }
        return mul * num;
    }

    if (s[r] != -1) return -1;
    // substring s[l....openBracketPos) will be a valid operator
    // openBracketPos is the leftmost positon of (
    int openBracketPos = -1;
    for (int i = l; i < r; i++) {
        if (s[i] == ')') return -1;
        if (s[i] == '(') {
            openBracketPos = i;
            break;
        }
    }
    if (openBracketPos == -1) return -1;
    char op = findOperator(s.substr(l, openBracketPos - l));
    if (op == 'x') return -1;

    // the '(' and ')' should create a valid expression
    int x = 0;
    int commaPos = -1;
    for (int i = openBracketPos + 1; i < r; i++) {
        if (s[i] == '(')  x++;
        else if (s[i] == ')') x--;
        if (x < 0) return -1;
        if (x == 0 && commaPos == -1) commaPos = -1;
    }
    if (x != 0 || commaPos == -1) return -1;

    // cout << "op l, r " << op << " " << l << " " << r << " " << s.substr(l, bracketPos - l) << " " << commaPos <<  endl;

    int exp1 = recursion(s, openBracketPos + 1, commaPos - 1);
    int exp2 = recursion(s, commaPos + 1, r - 1);
    if (exp1 == -1 || exp2 == -1) return -1;
    // cout << "exp = " << exp1 << " " << exp2 << endl;
    if (op == '+') {
        return exp1 + exp2;
    } else if (op == '-') {
        return exp1 - exp2;
    } else if (op == '*') {
        return exp1 * exp2;
    } else if (op == '/') {
        return exp1 / exp2;
    }
    return 0;
}

int main() {
    string s;
    cin >> s;
    cout << recursion(s, 0, s.size() - 1);
}










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
