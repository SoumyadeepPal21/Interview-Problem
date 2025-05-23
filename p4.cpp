// https://leetcode.com/discuss/post/5367360/google-l3-offer-bangalore-by-anonymous_u-pxk5/
// Given an array, any subarray is special if it forms an AP with common difference of 1 or - 1. Give sum of all such subarrays.

// Ex: arr = [2, 3, 4, 5, 6, 5]

//           So ans should be sum of all the good subarrays which are:

//               [2], [3], [4], [5], [6], [5]

//               [2, 3], [3, 4], [4, 5], [5, 6], [6, 5]

//               [2, 3, 4], [3, 4, 5], [4, 5, 6]

//               [2, 3, 4, 5], [3, 4, 5, 6]

//               [2, 3, 4, 5, 6]

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // all 1 length subarrays are AP.
        ans += a[i];
    }
    for (int l = 0; l < n - 1;) {
        int r = l + 1;
        while (r + 1 < n && a[r + 1] - a[r] == a[l + 1] - a[l]) r++;

        for (int k = l; k <= r; k++) {
            // number of subarray of length 2 that goes over index k
            long long sub = 1LL * (k - l + 1) * (r - k + 1) - 1;
            ans += sub * a[k];
        }
        l = r;
    }
}