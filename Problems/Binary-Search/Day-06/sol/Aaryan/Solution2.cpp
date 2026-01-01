// link : https://codeforces.com/contest/1846/submission/356025360

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <algorithm>

using namespace std;

bool check(long long k, int m, long long n) {
    __int128 sum = 1;
    __int128 cur = 1;

    for (int i = 1; i <= m; i++) {
        cur *= k;
        sum += cur;
        if (sum > n) return false;
    }
    return sum == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        bool possible = false;

        for (int m = 2; m <= 60 && !possible; m++) {
            long long low = 2, high = 1e9;

            while (low <= high) {
                long long mid = (low + high) / 2;

                if (check(mid, m, n)) {
                    possible = true;
                    break;
                }

                __int128 sum = 1, cur = 1;
                for (int i = 1; i <= m; i++) {
                    cur *= mid;
                    sum += cur;
                    if (sum > n) break;
                }

                if (sum < n)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}


/*
Explaination:
Try to represent n as a geometric series:
    n = 1 + k + k^2 + ... + k^m , where k >= 2 and m >= 2.
Since powers grow fast, we only need to check m up to 60.
For each m, try different values of k using binary search.
For every (k, m), compute the sum iteratively and stop early if it exceeds n.
If any sum equals n, output "YES"; otherwise, output "NO".

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

