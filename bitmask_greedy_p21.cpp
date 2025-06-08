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
			if (!ok[j]) continue;
			if (mask[i] & mask[j]) continue;
			for (int k = j + 1; j < n; j++) {
				if ((mask[i] & mask[j]) & mask[k]) continue;
				int curMask = (mask[i] | mask[j])  mask[k];
				int maskNeeded = (1 << 26) - (1 << (ch - 'a')) - curMask;
				if (hasMask[maskNeeded]) {

				}
			}
		}

		for (int j = i - 1; j >= 0; j--) {
			if (!ok[j] || (mask[i] | mask[j]) > 0) continue;
			hasMask[mask[i] | mask[j]]++;
		}
	}
}