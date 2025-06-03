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
    int num = 0;
    int flag = true;
    int mul = 1;
    for (int i = l; i <= r; i++) {
        if (!isDigit(s[i]) && !mark(s[i])) {
            flag = false;
            break;
        }
        if (s[i] == '-') {
            mul = -1;
        }
        if (mark(s[i])) continue;
        num = num * 10 + (s[i] - '0');
    }
    if (flag) return mul * num;
    cout << l << " " << r << endl;
    // find the operator, expression 1 and 2
    // add(5,mul(3, 5))
    // operator = '+'
    // exp1 = 5
    // exp2 = mul(3, 5)
    // first bracket's pos, first comma
    int bracketPos = -1, commaPos = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') {
            bracketPos = i;
        } else if (s[i] == ',') {
            commaPos = i;
            break;
        }
    }
    cout << bracketPos << " " << commaPos << endl;
    char op = findOperator(s.substr(l, bracketPos - l));
    cout << "op " << op << endl;
    int exp1 = recursion(s, bracketPos + 1, commaPos - 1);
    int exp2 = recursion(s, commaPos + 1, r - 1);
    cout << "exp = " << exp1 << " " << exp2 << endl;
    if (op == '+') {
        return exp1 + exp2;
    } else if (op == '-') {
        return exp1 - exp2;
    } else if (op == '*') {
        return exp1 * exp2;
    } else if (op == '/') {
        return exp1 / exp2;
    }
    // return power(exp1, exp2);
    return 0;
}

int main() {
    string s;
    cin >> s;
    cout << recursion(s, 0, s.size() - 1);
}