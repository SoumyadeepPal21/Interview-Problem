https://leetcode.com/discuss/post/6789894/l4-google-question-by-anonymous_user-pork/

int solve(const vector<int>& balls, const int k) {
    vector<int> cnt(k);
    for (const auto& b : balls)
        ++cnt[b];
    int used = 0;
    vector<int> left;
    for (const auto& c : cnt) {
        used += c / k;
        if (c % k != 0)
            left.push_back(c % k);
    }
    sort(left.begin(), left.end(), greater());
    int r = (int) left.size(), opt = r;
    for (int i = 0; i < r; i++) {
        opt = min(opt, i + max(left[i], sum(left[i] + left[i + 1] + .. + left[r - 1]) / k);
    }
          return used + opt;
}

