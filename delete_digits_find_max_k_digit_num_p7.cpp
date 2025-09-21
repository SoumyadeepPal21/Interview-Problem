// Technical 3:

// Given a sequence of digits of size S, return the subsequence that represents the largest possible number of size K that could be formed from the sequence maintaining the input order.
// Follow-up : asked for a different approach with same time complexity and discussed both.
#include <bits/stdc++.h>
using namespace std;


int main() {
	string s; cin >> s;
	int k; cin >> k;
	int n = s.length();
	// pos[i] contains all the position of the digit 'i'
	deque<int> pos[10];
	for (int i = 0; i < n; i++) {
		pos[s[i] - '0'].push_back(i);
	}
	string ans;
	int curPos = -1;
	for (int i = 0; i < k; i++) {
		for (int dig = 0; dig < 10; dig++) {
			// removing all position which is less than the last taken position(=curPos)
			while (!pos[dig].empty() && pos[dig].front() <= curPos) {
				pos[dig].pop_front();
			}
		}
		int nextPos;
		for (int dig = 9; dig >= 0; dig--) {
			if (pos[dig].empty()) continue;
			int takenDigits = i;
			int maxCanBeTaken = (n - pos[dig].front());
			if (takenDigits + maxCanBeTaken >= k) {
				nextPos = pos[dig].front();
				ans.push_back('0' + dig);
				break;
			}
		}
		curPos = nextPos;
	}
	cout << ans << endl;
}




#include <iostream>
#include <vector>
#include <stack>

std::vector<int> maxSubsequence(const std::vector<int>& nums, int K) {
	int S = nums.size();
	std::vector<int> result;
	int toRemove = S - K;

	for (int num : nums) {
		while (!result.empty() && result.back() < num && toRemove > 0) {
			result.pop_back();
			toRemove--;
		}
		result.push_back(num);
	}

	// If we added more than K digits, truncate the excess
	result.resize(K);
	return result;
}

int main() {
	std::vector<int> sequence = {3, 5, 2, 6, 4, 9};
	int K = 3;

	std::vector<int> result = maxSubsequence(sequence, K);

	std::cout << "Largest subsequence of size " << K << ": ";
	for (int digit : result) {
		std::cout << digit;
	}
	std::cout << std::endl;

	return 0;
}



for