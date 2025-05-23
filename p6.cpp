// https://leetcode.com/discuss/post/5367360/google-l3-offer-bangalore-by-anonymous_u-pxk5/



// We are given an array of integer, and a number k. We have to find the maximum consequtive occurance of number k in the array.
// There were many follow up questions around the same concepts.

// Instead of k we are given an array, for each array element find the max consequtive occurance.
// If we can modify c elements then what will be the max consequtive occurance.

#include <bits/stdc++.h>
using namespace std;


int main() {
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n);
	unordered_map<int, vector<int>> rangeMap;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		rangeMap[a[i]].push_back(i);
	}
	int answer = 0;
	for (auto x : rangeMap) {
		vector<int> ranges = x.second;
		int l = 0;
		int op = 0;
		for (int r = 0; r < ranges.size(); r++) {
			if (r > l) {
				op += ranges[r] - ranges[r - 1] - 1;
			}
			while (op > k) {
				op -= ranges[l + 1] - ranges[l] - 1;
				l++;
			}
			answer = max(answer, min(n, ranges[r] - ranges[l] + 1 - (k - op)));
		}
	}
	cout << answer << endl;
}



