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


                            space complexity: O(log(N) + K)




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

                            //  this solution will take O(K * Log(N)) time
                            // space = O(1 + K)




                            2. https://leetcode.com/problems/separate-squares-i/solutions/

                            In a x-y cartesian plane , squares are made with axes paralled to x-axis and y- axis, their topleft corner x,y is given and edge length a is given for each,,
                            we have to tell a horizontal axis that divides the area of all squares in 2 equal halves.
                            l=[(1,2),(2,4)] //topleft coordinates
                            sizes=[5,10] //edge lengths

                            one question => if there are multiple horizontal axis, then what to do? find the minimum ?


                            double L = min(y), R = max(Y + L)

                            while (R - L > 1e-9) {
                            A = findAreAbove(mid)
                            if (Total > A * 2) {
                            L = mid;
                        } else {
                            R = mid;
                        }
                        }

                            return (L + R) / 2;


                            3. https://leetcode.com/discuss/post/4102630/google-interview-question-by-anonymous_u-ffbi/


                            vector<int> v = {1, 2, .., n}

                            while (v.size() > 2) {
                            vector<int> v1, v2;
                            for (int i = 0; i < v.size() / 2; i++) v1.push_back(v[i]);
                            for (int i = v.size() / 2 + 1; i < v.size(); i++) v1.push_back(v[i]);

                            if (query(v1) == fail) {
                            v = v1;
                        } else if (query(v2) == fail) {
                            v = v2;
                        } else {
                            v1_1, v1_2, v2_1, v2_1 (partion v1, v2 into two parts)
                            if (query(v1_1 + v2_1) == fail) {
                            v = v1_1 + v2_1;
                        } else if (query(v1_2 + v2_1) == fail) {
                            v = v1_2 + v2_1;
                        } else if (query(v1_1 + v2_2) == fail) {
                            v = v1_1 + v2_2;
                        } else {
                            v = v1_2 + v2_2;
                        }
                        }
                        }

                            T(n) = T(n / 2) + N => O(2 * N)
