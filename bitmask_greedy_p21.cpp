// https://leetcode.com/discuss/post/5220080/chances-google-l4-banglore-by-anonymous_-zoo0/





for (char ch = 'a'; ch <= 'z'; ch++) {
	bool ok[n];
	for (int i = 0; i < n; i++) {
		ok[i] = {true if ch does not exist in s[i]}
	}
unordered_map<int, int> hasMask;
for (int i = 0; i < n; i++) {
		if (!ok[i]) continue;
		for (int j = i + 1; j < n; i++) {
			// make all the pair mask
			if (!ok[j]) continue;
			if (mask[i] & mask[j]) continue;
			hasMask[mask[i] | mask[j]]++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!ok[i]) continue;
		// first removed all the pair with i-th string
		for (int j = i + 1; j < n; i++) {
			if (!ok[j]) continue;
			if (mask[i] & mask[j]) continue;
			hasMask[mask[i] | mask[j]]--;
		}
		for (int j = i - 1; j >= 0; j--) {
			if (!ok[j]) continue;
			if (mask[i] & mask[j]) continue;
			int remMask = (1 << 26) - (1 << (ch - 'a')) - (mask[i] | mask[j]);
			if (hasMask[remMask]) {
				return true;
			}
		}
	}
}