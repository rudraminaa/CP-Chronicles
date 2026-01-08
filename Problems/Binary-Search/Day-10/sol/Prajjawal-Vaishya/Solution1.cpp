/*
 * Problem: D1. Removal of a Sequence (Easy Version)
 * * Short Statement:
 * Given a sequence 1 to 10^12. Perform 'x' operations where every y-th element is removed.
 * Find the k-th element in the remaining sequence.
 * * Approach: Binary Search on Answer
 * Instead of calculating the position backwards, we guess the answer 'ans' using Binary Search.
 * - The answer represents an index in the original sequence [1, 2, 3...].
 * - We define a monotonic function check(v): "How many numbers remain from the range [1, v] after x operations?"
 * - If check(mid) >= k, then the k-th number is <= mid. We try a smaller range.
 * - If check(mid) < k, we need a larger range.
 * * The check(v) function simulates the process:
 * In each step, if the current size is 's', we remove floor(s/y) elements.
 * New size = s - s/y. We repeat this x times.
 * * Time Complexity: O(T * x * log(10^12)).
 * With x=10^5, this is roughly 4*10^7 operations, which fits within the 2s limit.
 * Space Complexity: O(1).
 * * Submission Link: https://codeforces.com/contest/2169/problem/D1
 */

#include <iostream>

using namespace std;

// Function to calculate how many numbers remain from the range [1, initial_size]
// after performing the removal operation 'x' times.
long long survivors_after_x(long long initial_size, int x, long long y) {
    long long s = initial_size;
    for (int i = 0; i < x; i++) {
        // If s < y, s/y is 0, so no more elements are removed in subsequent steps.
        if (s < y) break;
        
        // Remove every y-th element. The count of removed elements is s/y.
        s -= (s / y);
    }
    return s;
}

void solve() {
    int x;
    long long y, k;
    if (!(cin >> x >> y >> k)) return;

    // Maximum possible answer is 10^12 (based on problem constraints)
    const long long NMAX = 1000000000000LL;

    // Edge case: If y=1, all elements are removed in the first step.
    if (y == 1) {
        cout << -1 << "\n";
        return;
    }

    // Optimization: Check if even the maximum possible range is enough
    if (survivors_after_x(NMAX, x, y) < k) {
        cout << -1 << "\n";
        return;
    }

    long long lo = 1, hi = NMAX;
    long long ans = -1;

    // Binary Search for the smallest index 'mid' such that
    // the number of survivors from [1...mid] is >= k.
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (survivors_after_x(mid, x, y) >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}