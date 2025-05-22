// https://leetcode.com/discuss/post/5092491/google-onsite-l3-bangalore-rejected-by-a-6ms9/
// Round 3:
// given a and b in int return their diff in string, a and b could be largeee values.


#include <bits/stdc++.h>
using namespace std;

string difference(string a, string b) {
    int lenDiff = a.length() - b.length();
    b = string(lenDiff, '0') + b;
    bool rem = false;
    string ans;
    cout << a << " " << b << endl;
    for (int i = a.length() - 1; i >= 0; i--) {
        int aDig = a[i] - '0';
        int bDig = b[i] - '0';
        if (rem) aDig--;
        if (aDig < bDig) {
            rem = true;
            aDig += 10;
        }
        ans.push_back('0' + (aDig - bDig));
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] > '0') {
            return ans.substr(i);
        }
    }
    return "0";
}

int main() {
    // your code goes here
    string a, b;
    cin >> a >> b;
    if (a.length() > b.length() || a >= b) {
        cout << difference(a, b);
    } else {
        cout << "-" + difference(b, a);
    }
}
