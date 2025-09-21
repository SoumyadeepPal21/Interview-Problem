// You’re given an endless stream of integers and a non - negative threshold d; your job is
// to pull off three numbers as soon as they “fit together, ” meaning the difference between the smallest
// nd largest of the three is at most d, discard those three so they can’t be reused, and continue until the stream ends, returning the list of all triplets in the order they were completed


// ask clarifying questions:
// all input integers are distinct,
// if we can create multiple tuples, which to be deleted

class IntegerStream {
	multiset<int> stream;
	vector<vector<int>> deletedTuples;
	int diff;

	void deleteFromStream(vector<int>& v) {
		for (int x : v) stream.erase(stream.find(x));
	}
public:
	IntegerStream(int diff) {
		this->diff = diff;
	}
	void addInteger(int x) {
		steam.insert(x);
		auto curElement = stream.find(x);

		if (curElement != stream.begin()) {
			auto leftElement = prev(curElement);

			if (leftElement != stream.begin() && x - * (prev(leftElement)) <= diff) {
				deletedTuples.push_back({*prev(leftElement), *leftElement, x});
				deleteFromStream(deletedTuples.back());
				return;
			}
		}


		if (curElement != stream.begin() && next(curElement) != stream.end()) {
			auto leftElement = prev(curElement);
			auto rightElemet = next(curElement);

			if (*rightElemet - *leftElement <= diff) {
				deletedTuples.push_back({*leftElement, x, *rightElemet});
				deleteFromStream(deletedTuples.back());
				return;
			}
		}

		if (next(curElement) != stream.end() && next(next(curElement)) != stream.end()
		        && *next(next(curElement)) - x <= diff) {
			deletedTuples.push_back({x, *next(curElement), *next(next(curElement))});
			deleteFromStream(deletedTuples.back());
			return;
		}
	}
};