class Solution {
	static const string INVALID_INPUT = "Invalid input";
public:
	string applySubstitutions(vector<vector<string>>& replacements, string text) {
		unordered_map<string, string> placeholderMap, cache;
		for (const auto& replacement : replacements) {
			placeholderMap[replacement[0]] = replacement[1];
		}

		map<string, int> color;
		function<string(const string&)> processText = [&](const string & str) -> string {
			if (str.length() == 0) return "";
			if (cache.find(str) != cache.end()) return cache[str];
			if (color[str] == 1) {
				return INVALID_INPUT;
			}
			color[str] = 1;
			size_t startPos = str.find('%');
			// no '%' in the string
			if (startPos == string::npos) {
				return str;
			}

			size_t endPos = str.find('%', startPos + 1);
			// for a starting '%' we don't find an ending '%'
			if (endPos == string::npos) {
				return INVALID_INPUT;
			}

			// Extract the placeholder key between the two '%' characters
			string placeholderKey = str.substr(startPos + 1, endPos - startPos - 1);

			// Recursively process the replacement value for nested placeholders
			if (placeholderKey.size() > 0 && !placeholderMap.count(placeholderKey)) {
				return INVALID_INPUT;
			}
			string replacementValue = processText(placeholderMap[placeholderKey]);

			// Construct the result: prefix + processed replacement + recursively process suffix
			if (replacementValue == INVALID_INPUT) return replacementValue;
			if (processText(str.substr(endPos + 1)) == INVALID_INPUT) return INVALID_INPUT;
			cache[str] = str.substr(0, startPos) + replacementValue + processText(str.substr(endPos + 1));
			color[str] = 2;
			return cache[str];
		};

		// Start processing from the input text
		for (auto [key, val] : dictionary)
			if (processText(val) == INVALID_INPUT)
				return INVALID_INPUT;

		return processText(text);
	}
};

assumption => the key does not have any %


ask the question if a cycle like a->b->c->a exists, but any of a, b, c is used not in process of replacement process,
    then just skip the lines from 50->52




    keys a->b->c->d->e->........

    text is dependent on a, then worst case the the


	    time and space complexity->


	    text = gakfhgdks % a % aslgkfvddslhggajgbkjs


	           a -> L =>  8L     => 1 => 8L => N * L
	           b      c     => 4L    => 2 => 8L
	           d     e   f   g   => 2L   => 4 => 8L
	           ...     ... ... ....  => L    => 8 => 8L


	           N * L * LOG(N)

		           N * L =>
		           A => xy % B % z
		           B => ab % A % B