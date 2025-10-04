1. https://leetcode.com/problems/range-module/submissions/1780443806/


2. https://leetcode.com/discuss/post/2199510/google-l4-india-june-2022-accepted-by-an-qmyr/
same as https://leetcode.com/problems/amount-of-new-area-painted-each-day/description/
https://algo.monster/liteproblems/2158



set<pair<int, int>> S;

auto itL = s.upper_bound(L);
int itR = s.upper_bound(R);

if (itL != s.begin() && prev(itL)->second >= L) {
	itL--;
}
int ans = 0;
if (itL == itR) {
	s.insert({L, R});
	ans = R - L;
} else {
	if (L < itL->first) ans += (itL->first - L);
	else L = itL->first;
	if (R > prev(itR)->second) ans += (R - prev(itR)->second);
	else R = itR->second;
	while (next(itL) != itR) {
		ans += (next(itL)->first - itL->second);
		itL++;
	}
	s.erase(itL, itR);
	s.insert({L, R});
}
return ans;


3. https://leetcode.com/discuss/post/2483532/google-onsite-tcp-stream-by-anonymous_us-fgar/

takePackets(3, [31, 242, 15])
Stream: _ _ _ [31, 242, 15]
0 1 2  3   4   5

stream.takePackets(0, [9, 1])
Index:   0   1   2   3   4   5
Data:   [9,  1,  _, 31, 242, 15]

read(10) returns [9, 1]
next unread byte starts at read_ptr = 2.


                                      this can be a variation of merge interval problem in case of overlap.
	                                      say we will place the numbers only in the empty places of stream.







// 4. https://leetcode.com/discuss/post/6084864/google-l4-interview-expereince-by-anonym-b142/
// We have a file with the following format each line: startIP, endIP, cityName.
// Question: Write a function that takes as input an IP address and outputs its associated cityName.
// Example:
// File format:
// startIP, endIP, cityName
// 1.0.1.1, 1.0.1.10, NYC
// 1.0.1.20, 1.0.1.30, SF
// ...
// If the input is 1.0.1.9, the output should be NYC.
// Write code for the function.


	                                      make startIP, endIP to some integer (L, R) -> insert in some set
	                                      for each L, store the cityName in some unordered map


