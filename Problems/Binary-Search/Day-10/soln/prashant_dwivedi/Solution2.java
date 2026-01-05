/*
What this program does:

For each test case, two arrays A and B are given.
At every index i, we may choose either A[i] or B[i] to form a new array C.

A subarray [L, R] is considered valid if it is possible to pick values
from each position such that the chosen sequence is strictly increasing.


How the solution works:

At every index i, there are two possible states:
- ending at i by choosing A[i]
- ending at i by choosing B[i]

For each state, we compute how far to the right the sequence can be
extended while keeping it strictly increasing.

This is done using dynamic programming from right to left:
- reachA[i] stores the farthest index reachable if we pick A[i]
- reachB[i] stores the farthest index reachable if we pick B[i]

Transitions depend only on comparisons with the next position.


Counting valid ranges:

For a fixed starting index i, the subarray can extend up to
max(reachA[i], reachB[i]).

So the number of valid subarrays starting at i is:
(maxReach - i + 1)

Summing this over all i gives the final answer.


Complexity:

Time:  O(N) per test case  
Space: O(N)


//---------SUBMISSION LINK
https://www.codechef.com/viewsolution/1223502836
*/

import java.io.*;
import java.util.*;

public class Solution2 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());

            int[] a = new int[n];
            int[] b = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) a[i] = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) b[i] = Integer.parseInt(st.nextToken());

            int[] reachA = new int[n];
            int[] reachB = new int[n];

            for (int i = n - 1; i >= 0; i--) {
                reachA[i] = i;
                reachB[i] = i;

                if (i + 1 < n) {
                    int ra = i;
                    int rb = i;

                    if (a[i + 1] > a[i]) ra = Math.max(ra, reachA[i + 1]);
                    if (b[i + 1] > a[i]) ra = Math.max(ra, reachB[i + 1]);

                    if (a[i + 1] > b[i]) rb = Math.max(rb, reachA[i + 1]);
                    if (b[i + 1] > b[i]) rb = Math.max(rb, reachB[i + 1]);

                    reachA[i] = ra;
                    reachB[i] = rb;
                }
            }

            long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += Math.max(reachA[i], reachB[i]) - i + 1;
            }

            out.append(ans).append('\n');
        }

        System.out.print(out.toString());
    }
}
