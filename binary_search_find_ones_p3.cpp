// Given a sparse bit array A of size M stored in a database. The database provides an API query(L, R) which returns 1 if there is at least one bit equal to one in A[L..R] and 0 otherwise.
//     You want to find all the 1 bits in a reasonable number of queries. E.g. for array 01100000001, positions of 1 bits are {1, 2, 10} . Return the array of all the positions of 1's.


#include <vector>
using namespace std;

// Provided API (you'll replace this with real database query)
int query(int L, int R);  // Assume implemented elsewhere

void findOnes(int L, int R, vector<int>& result) {
    if (L > R) return;

    int res = query(L, R);
    if (res == 0) return;  // No 1s in this interval

    if (L == R) {
        result.push_back(L);  // Found a 1 at position L
        return;
    }

    int mid = L + (R - L) / 2;
    findOnes(L, mid, result);      // Search in left half
    findOnes(mid + 1, R, result);  // Search in right half
}

vector<int> getAllOnes(int M) {
    vector<int> result;
    findOnes(1, M, result);
    return result;
}

in case of sparse array(less number of 1's) we do K * Log(N) operations.
                            in case of dense array we do 2 * N operations.

                            N leaf node + N / 2 + N / 4 + ... + 1 queries (each node in binary tree, 1 query)
                            (2 ^ log(N + 1) - 1) / (2 - 1) = 2 * N + 1




                            // iterative solution

                            int start = 0;
                            while(start < N) {
                            int pos = -1;
                            int lft = start;
                            int end = N - 1;
                            while (lft <= end) {
                            int mid = (lft + end) / 2;
                            if (query(start, mid)) {
                            pos = mid;
                            end = mid - 1;
                        } else {
                            lft = mid + 1;
                        }
                        }
                            if (pos != -1) {
                            ans.push_back(pos);
                        } else {
                            break;
                        }
                            start = pos + 1;
                        }

