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


