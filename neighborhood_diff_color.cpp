#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> count;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		count[x]++;
	}

	int e = n / m;
	priority_queue<pair<int, int>> pq;
	for (auto [val, freq] : count) pq.push({freq, val});
	vector<vector<int>> ans(m);
	for (int i = 0; i < m; i++) {
		cout << "Box " << i + 1 << "-> ";
		vector<pair<int, int>> temp;
		for (int j = 0; j < n / m; j++) {
			pair<int, int> p = pq.top();
			pq.pop();
			cout << " " << p.second;
			ans[i].push_back(p.second);
			if (p.first > 1) temp.push_back({p.first - 1, p.second});
		}
		cout << endl;
		for (auto p : temp) pq.push(p);
	}


}
