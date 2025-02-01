#include <bits/stdc++.h>
using namespace std;

/*
 * Approach1: Brute Force Simple Iteration
 * - We use two nested loops to generate all possible subarrays.
 * - The outer loop selects the starting index.
 * - The inner loop iterates over the end indices and calculates the XOR.
 * - If we find a subarray with XOR equal to B, we increase the count.
 *
 * T.C: O(N^2) -> Two nested loops to check all subarrays.
 * S.C: O(1) -> No extra space used apart from variables.
 * --------------------
 */

class Solution
{
public:
  int solve(int *A, int n1, int B)
  {
    int cnt = 0; // Stores count of subarrays with XOR B

    for (int i = 0; i < n1; i++)
    {
      // Initialize XOR for current subarray
      int xorr = 0;

      for (int j = i; j < n1; j++)
      {
        // Compute XOR from index i to j
        xorr = xorr ^ A[j];

        // Check if XOR is equal to B &  Increment count if its true
        if (xorr == B)
        {
          cnt++;
        }
      }
    }

    // Return the count of subarrays with XOR B
    return cnt;
  }
};

/*
 * Approach:
 * - We use a map to store the frequency of prefix XOR values.
 * - The key observation is that if we find a prefix XOR `x` such that:
 *   - `x ^ k = XR` (where `XR` is the current prefix XOR)
 *   - Then, `x = XR ^ k`
 * - This means there exists a previous prefix XOR (`x`) such that the subarray
 *   from that point to the current index `i` has an XOR of `k`.
 * - We count how many times `x = XR ^ k` has occurred using a hashmap.
 * - Finally, we update the map with the current prefix XOR.
 * --------------------
 * T.C: O(N) -> We traverse the array once, and each lookup in the map takes O(1).
 * --------------------
 * S.C: O(N) -> In the worst case, we store all prefix XOR values in the map.
 */

class Solution
{
public:
  int solve(int *A, int n1, int B)
  {
    int xr = 0;                  // Stores the running prefix XOR
    unordered_map<int, int> mpp; // Map to store prefix XOR frequencies
    mpp[xr]++;                   // Initialize with 0 to handle cases where prefix XOR is B
    int cnt = 0;                 // Stores count of subarrays with XOR B

    for (int i = 0; i < n1; i++)
    {
      xr = xr ^ A[i]; // Compute prefix XOR till index i

      int x = xr ^ B; // Find the required prefix XOR

      cnt += mpp[x]; // Add occurrences of (xr ^ B) to count

      mpp[xr]++; // Update the prefix XOR frequency in the map
    }

    return cnt; // Return the count of subarrays with XOR B
  }
};
