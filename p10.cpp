// https://leetcode.com/discuss/post/4978447/google-coding-interview-experience-by-an-b57i/


// Given an array of non - negative integers, the goal is to travel from the first index to the last index with maximum possible score with as many jumps allowed. Score of a jump is defined as the number of index jumped multiplied by the value on the jumped index.
// e.g. [3, 7, 9, 10]

// if the jump is from index0 to index2, the score is (2 - 0) * 9 = 18

//         Sample input: [3, 12, 9, 10]
// 	        Sample output: 32
//         Explanation: jump from index0 to index1 and then to index3 = (1 - 0) * 12 + (3 - 1) * 10 = 12 + 20 = 32


#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> dp(n), a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	deque<int> dq;
	for (int i = 1; i < n; i++) {
		while (!dq.empty() && a[i] > a[dq.back()]) {
			dq.pop_back();
		}
		if (dq.empty()) dp[i] = i * a[i];
		else dp[i] = dp[dq.back()] + (i - dq.back()) * a[i];
		dq.push_back(i);
	}
	cout << dp.back() << endl;
}


