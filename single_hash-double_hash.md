## single_hash

In C++, hashing a string (made of lowercase characters) is a common technique in string algorithms like Rabin-Karp, rolling hash, etc.

Here’s how you can do single hash and double hash cleanly:
p = 31 or 53 (prime number, depends on charset)
M = large prime modulus (like 10^9+7, 10^9+9)

C++ Code (Single Hash):

```
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll compute_single_hash(const string& s) {
    const int p = 31; // prime base
    const int M = 1e9 + 9; // prime modulus
    ll hash_value = 0;
    ll p_pow = 1;
    
    for (char c : s) {
        int val = c - 'a' + 1; // map 'a' to 1, 'b' to 2, etc.
        hash_value = (hash_value + val * p_pow) % M;
        p_pow = (p_pow * p) % M;
    }
    return hash_value;
}

int main() {
    string s = "example";
    cout << "Single Hash: " << compute_single_hash(s) << endl;
}

```





## Double Hash (To Avoid Collisions)
You compute two hashes with two different primes and moduli.

C++ Code (Double Hash):

```
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

pair<ll, ll> compute_double_hash(const string& s) {
    const int p1 = 31, p2 = 53;
    const int M1 = 1e9 + 7, M2 = 1e9 + 9;
    ll hash1 = 0, hash2 = 0;
    ll p_pow1 = 1, p_pow2 = 1;

    for (char c : s) {
        int val = c - 'a' + 1;
        hash1 = (hash1 + val * p_pow1) % M1;
        hash2 = (hash2 + val * p_pow2) % M2;
        p_pow1 = (p_pow1 * p1) % M1;
        p_pow2 = (p_pow2 * p2) % M2;
    }
    return {hash1, hash2};
}

int main() {
    string s = "example";
    auto [h1, h2] = compute_double_hash(s);
    cout << "Double Hash: (" << h1 << ", " << h2 << ")" << endl;
}

```


✅ Notes:
Use double hashing if you want to reduce hash collision chances (for example, in unordered_map keys for strings).

Prime bases like 31, 53, 101 are popular for lowercase/uppercase strings.

Modulo primes like 1e9+7, 1e9+9, 998244353 are commonly used to prevent overflow.

If you want rolling hashes (for substring search) or custom hash functions for unordered_map, I can guide you too.



######################################

submask :
for (int m = 0; m < (1 << n); ++m)
for (int s = m; s; s = (s - 1)&m)
... s and m ...
Let's prove that the inner loop will execute a total of O(3 ^ n) iterations.



First proof : Consider the i - th bit. There are exactly three options for it :

it is not included in the mask
m ( and therefore not included in submask s),
    it is included in m, but not included in s, or
    it is included in both m and s.


########################################################

Custom comparator:

struct CustomCompare {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();  // sort by string length
    }
};

int main() {
    std::set<std::string, CustomCompare> s;

    priority queue<int, vector<int>, CustomCompare> pq;
    s.insert("apple");
    s.insert("kiwi");
    s.insert("banana");

    for (const auto& str : s)
        std::cout << str << " ";

    std::vector<std::string> v = {"apple", "kiwi", "banana"};
    std::sort(v.begin(), v.end(), CustomCompare());

    for (const auto& s : v)
        std::cout << s << " ";
}