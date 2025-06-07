// https://leetcode.com/discuss/post/5741664/google-l4-backened-bangalore-or-hyderaba-dard/

// Algorithm question : Find peak in mountain array but the array can contain duplicates (With duplicates it becomes difficult. I was not able to come up with fully correct code if anyone knows please leave comments)

while (high - low > 3) {
    int lMid = low + (high - low) / 3;
    int rMid = lMid + (high - low) / 3;

    if (nums[lMid] > nums[rMid]) {
        // peak will not exist from index [rMid, n - 1]
        high = rmid - 1;
    } else if (nums[rMid] > nums[lMid]) {
        // peak will not exist from index [0, lMid]
        low = lMid + 1;
    } else {
        // in case of there is exactly one peak point
        low = lMid + 1;
        high = rMid - 1;
    }
}

for (int i = max(1, low); i <= min(n - 2, high); i++) {
    if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
        return i;
    }
}

return -1;
