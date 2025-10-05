// r3: https://leetcode.com/discuss/post/5117851/google-l4-hyderabad-apr-2024-reject-by-a-gxup/
// https://leetcode.com/discuss/post/4173795/maang-interview-question-by-anonymous_us-y7gg/
// A kid found out that his uncle loves him so much that he would do anything to buy him as many gifts as he possibly can. For this reason, the nephew prepares a list of gifts that he wants and gives it to his uncle. Each item in the list contains 2 integers: the day on which he wants the gift (today is day 0), and the cost of it. The uncle, knowing that his nephew is preparing such a list, saves 1perdayforthegifts, andinitially(onday0)hehas0. Calculate the maximum number of gifts the uncle can buy to his nephew.

// Input: The first line contains a single integer N - the number of gifts. Then N lines follow. Each line contains two integers separated by space: d_i (the day that present i should be bought) and c_i (the cost of gift i).

// Output: A single integer which is the maximum number of gifts the uncle can buy.

// First Test Case:

// 	Input

// 	3

// 	3 2

// 	5 4

// 	6 3


// 	Output

// 	2
// 	In this test case, there are 3 gifts on the list. On the 3rd day the uncle has 3andcanbuythegiftthatcosts2. Uncle is left with 1, andonday5shehastwomoredollars, atotalof3. On the 5th day he can't buy the gift that costs 4.Thenextday(6th)shehas4 and he can now buy the gift that costs $3. There is no way to buy all gifts in the list.

// 	Second Test Case:

// 	Input

// 	5

// 	1 2

// 	3 2

// 	5 3

// 	6 2

// 	7 2


// 	Output

// 	3
// 	Third test case:

// 	4

// 	1 1

// 	50 40

// 	51 20

// 	52 20

// 	Output : 3 (better to buy on day 1, 51 and 52 (NOTE: greedy solution would be to buy on day 1 and day 50, that is incorrect)


#include <bits/stdc++.h>
using namespace std;


int main() {
	int n; cin >> n;
	int totalCost = 0;
	int gifts = 0;
	priority_queue<int> costOfTakenGifts;
	for (int i = 0; i < n; i++) {
		int day, cost;
		cin >> day >> cost;
		// day-th day I have total day money
		if (day >= cost + totalCost) {
			// we can take the gift on 'day'-th day with cost 'cost'
			gifts++;
			totalCost += cost;
			costOfTakenGifts.push(cost);
		} else {
			// can't take the gift, so we should check if some earlier taken gift
			// was costlier or not, if yes, remove from the giftlist and take today's gift
			if (!costOfTakenGifts.empty() && cost < costOfTakenGifts.top()) {
				int mxCostGift = costOfTakenGifts.top();
				costOfTakenGifts.pop();
				totalCost -= (mxCostGift - cost);
				costOfTakenGifts.push(cost);
			}
		}
	}
	cout << gifts << endl;
}








// Technical 3:

// https://leetcode.com/discuss/post/6647864/another-google-l3-post-not-what-i-expect-wq86/

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
		int nextPos = -1;
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


