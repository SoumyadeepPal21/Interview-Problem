// You’re given an endless stream of integers and a non - negative threshold d; your job is
// to pull off three numbers as soon as they “fit together, ” meaning the difference between the smallest
// nd largest of the three is at most d, discard those three so they can’t be reused, and continue until the stream ends, returning the list of all triplets in the order they were completed


// ask clarifying questions:
// all input integers are distinct,
// if we can create multiple tuples, which to be deleted

class IntegerStream {
	multiset<int> stream;
	int diff;

public:
	IntegerStream(int diff) {
		this->diff = diff;
	}

	void addInteger(int x) {
		steam.insert(x);
		auto curElement = stream.find(x);
		vector<int> elements = { -1, -1, x, -1, -1};

		if (curElement != stream.begin()) {
			elements[1] = *prev(curElement);
			if (prev(curElement) != stream.begin())
				elements[0] = *prev(prev(curElement));
		}

		if (next(curElement) != stream.end()) {
			elements[3] = *next(curElement);
			if (next(next(curElement)) != stream.end()) {
				elements[4] = *next(next(curElement));
			}
		}

		for (int i = 0; i < 3; i++) {
			if (elements[i] != -1 && elements[i + 2] != -1) {
				for (int j = i; j < i + 3; j++) {
					stream.erase(elements[j]);
				}
				return;
			}
		}
	}
};