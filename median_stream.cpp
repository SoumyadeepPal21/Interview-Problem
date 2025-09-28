1. // https://leetcode.com/discuss/post/2526280/google-onsite-london-by-anonymous_user-xkvd/



// Supposing that you have a stream of integer, implement the following two methods to return the median value (value of the middle. It's not the mean). The median value does not need to be exact. It can be within a range of 2^n-1 to 2^n+1.
// For example:
// addValue(1)
// addValue(6)
// addValue(10)
// getMedian() can return any value between 4 to 7.



void addNum(long long num) {
	cnt[log2(num)]++;
}

long long findMedian(int num) {
	if (totalNum == 0) return -1;
	long long medinan = 1;
	long long totalCnt = 0;
	for (int i = 0; i < 64; i++, median *= 2) {
		totalCnt += cnt[i];
		if (totalCnt >= (totalNum + 1) / 2) {
			return median;
		}
	}
	return -1;
}




2. https://leetcode.com/problems/find-median-from-data-stream/