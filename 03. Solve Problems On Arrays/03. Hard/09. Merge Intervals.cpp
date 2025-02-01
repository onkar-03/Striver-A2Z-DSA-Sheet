#include <bits/stdc++.h>
using namespace std;

/*
 * Approach1; Brute Force Simple Iteration
 * 1. First, we sort the intervals based on their starting points.
 * 2. Then, we loop through each interval and compare it with the previous ones.
 *    If there's an overlap (i.e., the current interval's start is less than or equal to the previous interval's end),
 *    we merge the intervals by updating the end time to the maximum of both.
 * 3. If there is no overlap, we push the current interval to the result.
 * ----------------------------
 * T.C: O(n * log(n) + 2 * n)
 * - Sorting the intervals takes O(n * log(n)) time.
 * - The nested loop checks and merges the intervals, which has a worst-case complexity of O(n).
 * Also for every Inteval we visit each interval kinda twice hence O(2 * n)
 * ----------------------------
 * S.C: O(n)
 * - We are using a result vector `ans` that stores the merged intervals, so space complexity is O(n) in the worst case.
 *   (In the worst case, no intervals overlap and we store all the intervals in the result.)
 */
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    // size of the array
    int n = intervals.size();

    // Sort the given intervals:
    sort(intervals.begin(), intervals.end());

    // a vector to store the result
    vector<vector<int>> ans;

    // Iterate throught the range of Itervals
    for (int i = 0; i < n; i++)
    {
      // Select an interval:
      int start = intervals[i][0];
      int end = intervals[i][1];

      // Skip all the merged intervals:
      if (!ans.empty() && end <= ans.back()[1])
      {
        continue;
      }

      // Check the rest of the intervals:
      for (int j = i + 1; j < n; j++)
      {
        if (intervals[j][0] <= end)
        {
          end = max(end, intervals[j][1]);
        }
        else
        {
          break;
        }
      }

      // Finally push the merged interval
      ans.push_back({start, end});
    }

    return ans;
  }
};

/*
 * Approach-2: Optimal using Single Iteration
 * 1. Sort the given intervals based on their start times.
 * 2. Traverse through the sorted intervals:
 *    - If the current interval doesn't overlap with the last interval in the result,
 *      simply add it to the result.
 *    - If the current interval overlaps with the last interval in the result,
 *      merge them by updating the end time of the last interval.
 * ----------------------------
 * T.C: O(n * log(n))
 * - Sorting the intervals takes O(n * log(n)) time.
 * - Traversing through the intervals to merge them takes O(n) time.
 *   So, the total time complexity is dominated by the sorting step, which is O(n * log(n)).
 * ----------------------------
 * S.C: O(n)
 * - The result vector stores the merged intervals, and in the worst case, it stores all the intervals.
 *   Hence, the space complexity is O(n).
 */
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    int n = intervals.size(); // size of the array

    // Sort the given intervals based on the start time:
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    // Loop through each interval and merge if needed
    for (int i = 0; i < n; i++)
    {
      // If the current interval doesn't overlap with the last interval in the result
      if (ans.empty() || intervals[i][0] > ans.back()[1])
      {
        ans.push_back(intervals[i]);
      }
      // If the current interval overlaps with the last interval in the result
      else
      {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }

    return ans; // Return the merged intervals
  }
};
