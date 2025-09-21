// Given array of strings group strings
// which are buddies to each other 2 strings are
// buddy if they have equal length and and each
// character has same distance
// for e.g. : aab and bbc are buddy


class Solution {
private:
	int findDis(char a, char b) {
		if (a >= b) {
			return (int)(a - 'a') - (int)(b - 'a');
		}
		return (26 + (int)(a - 'a') - (int)(b - 'a'));
	}

	string createHash(const string& word) {
		string hash = "";
		for (int i = 1; i < word.size(); i++) {
			int dis = findDis(word[i], word[i - 1]);
			hash += toString(dis) + ",";
		}
		return hash;
	}
public:
	long long countBuddyString(vector<string> &words) {
		int n = words.size();
		int oneLengthWord = 0;
		unordered_map<string, int> hashMap;

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (words[i].size() == 1) {
				ans += oneLengthWord;
				oneLengthWord++;
			} else {
				string hash = createHash(words[i]);
				ans += hashMap[hash];
				hashMap[hash]++;
			}
		}
		return ans;
	}
};