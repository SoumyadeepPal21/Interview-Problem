// 1. https://leetcode.com/discuss/post/5720580/google-swe-2-l3-bangalorehyd-aug-24-by-a-7kr8/
// you are given maximum initial energy k (k<1000) and array A of length n denoting wind speed on n days. he is stuck on a boat and each day he can either choose to move or stay put.. each day he decides to travel he will move ahead A[i] Dist and his energy decreases by 1 and if he decides to stay put his energy increases by 1.
// What is the maximum distance he can travel without dropping his energy to negative after n days.
//Clarification questions i asked- what if energy is k and he decides to rest only- would energy go beyond maximum? answer=No, it will remain k


vector<int> dp(k + 1, -1);
dp[k] = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
        if (j == k) {
            ndp[j] = dp[j];
        } else if (j == 0) {
            ndp[j] = dp[j + 1] + a[i];
            else {
                ndp[j] = max(dp[j + 1] + a[i], dp[j - 1]);
            }
        }
    }
}


2. https://leetcode.com/problems/dungeon-game/submissions/1633888190/
good dp problem


3. https://leetcode.com/problems/race-car/description/
