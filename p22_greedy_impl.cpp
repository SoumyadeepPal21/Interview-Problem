// https://leetcode.com/discuss/post/5499901/google-l3-chancesexperience-by-anonymous-xbyw/

// Find max length subarray which has all the element equal to key.(Two pointer question)
// Example : Given array a = [1,2,2,1,3,4,5,2,3,2,2,2] and key 2 then max length of subarray containing only 2 is 3(last three element).

// Now we are given key as querries, we need to give max length of subarray for each query.
// Example : Given array a = [1,2,2,1,3,4,5,2,3,2,2,2] and keys [1,2,3] , we have return [1,3,1]

// Now we need to find max length of subarray if you are allowed at most k different element apart from key.
// Example : Given array a = [1,2,2,1,3,4,5,2,3,2,2,2] and key 2 and k = 2 that means we need to find a max subarray with at most 2 elements differing from key 2. Output = 6





for (int i = 0; i < n; i++) {
	idxMap[nums[i]].push_back(i);
}

for (auto [x , vec] : indMap) {
	for (int r = 0, l = 0, op = 0; r < vec.size(); r++) {
		// operation needed to merge to consecutive segments with val = x
		if (r > 0) op += vec[r] - vec[r - 1] - 1;
		while (op > k) {
			op -= (vec[l + 1] - vec[l] - 1);
			l--;
		}
		ans = max(ans, min((vec[r] - vec[l] + 1) + (k - op), n));
	}
}

