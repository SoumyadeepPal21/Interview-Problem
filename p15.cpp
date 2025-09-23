// https://leetcode.com/discuss/post/6033289/google-l3-interview-experience-oct-2024-0xzt8/


// Compute: add(sub(-5,10),mul(5,pow(2,5)))
// (Used stack)
// No follow up ques as this coding only took time.

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

bool mark(char ch) {
    return (ch == '-' || ch == '+');
}

int recursion(string s, int l, int r) {
    if (isDigit(s[l]) || mark(s[l])) {
        int mul = 1;
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == '-') {
                mul = -1;
                continue;
            }
            num = num * 10 + (s[i] - '0');
        }
        return mul * num;
    }

    // find the operator, expression 1 and 2
    // add(5,mul(3, 5))
    // operator = '+'
    // exp1 = 5
    // exp2 = mul(3, 5)
    // first bracket's pos, first comma
    int bracketPos = -1, commaPos = -1;
    int x = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(' && bracketPos == -1) {
            bracketPos = i;
        } else if (bracketPos != -1) {
            if (s[i] == '(') x++;
            else if (s[i] == ')')
                x--;
            else if (s[i] == ',' && x == 0) {
                commaPos = i;
                break;
            }
        }
    }
    // cout << bracketPos << " " << commaPos << endl;
    char op = findOperator(s.substr(l, bracketPos - l));
    // cout << "op l, r " << op << " " << l << " " << r << " " << s.substr(l, bracketPos - l) << " " << commaPos <<  endl;
    int exp1 = recursion(s, bracketPos + 1, commaPos - 1);
    int exp2 = recursion(s, commaPos + 1, r - 1);
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