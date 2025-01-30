#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * We iterate through the array and for each element, we check if it is already in the result list.
 * If it's not, we count its frequency in the array, and if the frequency is greater than n/3, we add it to the result list. We stop once we have found two majority elements.
 * --------------------
 * Why at most two majority elements:
 * There can only be at most two majority elements because their combined frequency cannot exceed n.
 * If there were more than two elements appearing more than n/3 times, their combined frequency would exceed n, which is not possible.
 * Hence, the problem guarantees that at most two elements can meet the condition of appearing more than n/3 times.
 * --------------------
 * Time Complexity: O(n^2), because we are iterating over each element and for each element,
 * we are counting its occurrences, leading to a nested iteration.
 * --------------------
 * Space Complexity: O(n), for storing the result list of majority elements.
 */
class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int n = nums.size(); // size of the array
    vector<int> ls;      // list of answers

    for (int i = 0; i < n; i++)
    {
      // selected element is nums[i]:
      // Checking if nums[i] is not already in the result list:
      if (ls.size() == 0 || ls[0] != nums[i])
      {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
          // counting the frequency of nums[i]
          if (nums[j] == nums[i])
          {
            cnt++;
          }
        }

        // check if frequency is greater than n/3:
        if (cnt > (n / 3))
          ls.push_back(nums[i]);
      }

      // Stop once two majority elements are found
      if (ls.size() == 2)
        break;
    }

    return ls;
  }
};

/*
 * Approach-2: Using Hashing with a Map
 * 1. We will use a hashmap (unordered_map) to store the frequency of each element.
 * 2. The majority element is defined as an element that appears more than floor(n/3) times
 * 3. We iterate through the array, updating the frequency of each element in the map.
 * 4. After building the map, we check which elements appear more than floor(n/3) times and add them to the result list.
 * ----------------------------
 * T.C: O(n + k) where n is the size of the array and k is the size of map
 * - We iterate through the array once, which takes O(n) time.
 * - Inserting and accessing elements in the unordered_map take O(1) on average.
 * ----------------------------
 * S.C: O(n)
 * - The space complexity is O(n) due to storing elements and their frequencies in the map and the result list.
 */

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int n = nums.size(); // size of the array
    vector<int> result;  // list of majority elements

    // Create a map to store the frequency of each element
    unordered_map<int, int> freqMap;

    // Calculate the threshold (floor(n / 3) + 1)
    int threshold = n / 3 + 1;

    // Count the frequency of each element in the array
    for (int num : nums)
    {
      freqMap[num]++;
      if (freqMap[num] == threshold)
        result.push_back(num);
    }

    // Find the elements whose frequency is greater than the threshold
    for (auto &entry : freqMap)
    {
      if (entry.second > threshold)
      {
        result.push_back(entry.first);
      }
    }

    // Return the elements that appear more than floor(n/3) times
    return result;
  }
};

/*
 * Approach-3: Using Hashign with Map but Single Iteration
 * 1. We will use an unordered_map to count the frequency of elements while iterating over the array.
 * 2. Once an element's frequency reaches the threshold (floor(n / 3) + 1), we add it to the result list.
 * 3. We stop iterating as soon as we find two majority elements, ensuring a single-pass solution.
 * ----------------------------
 * T.C: O(n)
 * - We iterate through the array once, so the time complexity is O(n).
 * - Inserting and checking the frequency in the unordered_map takes O(1) on average.
 * ----------------------------
 * S.C: O(n)
 * - The space complexity is O(n) due to storing the elements and their frequencies in the map.
 */

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int n = nums.size(); // size of the array
    vector<int> result;  // list of majority elements

    // Create a map to store the frequency of each element
    unordered_map<int, int> freqMap;

    // Calculate the threshold (floor(n / 3) + 1)
    int threshold = n / 3 + 1;

    // Count the frequency of each element and add to result if it reaches the threshold
    for (int num : nums)
    {
      freqMap[num]++;
      if (freqMap[num] == threshold)
      {
        result.push_back(num);
      }
      // Stop early if we find two majority elements
      if (result.size() == 2)
        break;
    }

    return result;
  }
};

/*
 * Approach-3: Extrended Boyer-Moore Voting Algorithm
 * 1. We maintain two potential candidates (`el1` and `el2`) for the majority elements, and corresponding counters (`cnt1` and `cnt2`).
 * 2. We iterate through the array:
 *    - If either counter is zero, we update the corresponding element and counter.
 *    - If the element matches one of the candidates, we increment the respective counter.
 *    - If the element does not match either candidate, we decrement both counters.
 * 3. After finding potential candidates, we check if they actually meet the majority requirement by counting their occurrences in a second pass.
 * 4. We return the elements that meet the majority criteria.
 * ----------------------------
 * T.C: O(n)
 * - We make two passes through the array: one to find the candidates and another to verify them.
 * - Each pass takes O(n) time, so the overall time complexity is O(n).
 * ----------------------------
 * S.C: O(1)
 * - We only use a constant amount of space for counters and candidate elements, so the space complexity is O(1).
 */

class Solution
{
public:
  vector<int> majorityElement(vector<int> &v)
  {
    int n = v.size(); // size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN;      // element 1
    int el2 = INT_MIN;      // element 2

    // Applying the Extended Boyer Moore's Voting Algorithm
    for (int i = 0; i < n; i++)
    {
      if (cnt1 == 0 && el2 != v[i])
      {
        cnt1 = 1;
        el1 = v[i];
      }
      else if (cnt2 == 0 && el1 != v[i])
      {
        cnt2 = 1;
        el2 = v[i];
      }
      else if (v[i] == el1)
        cnt1++;
      else if (v[i] == el2)
        cnt2++;
      else
      {
        cnt1--, cnt2--;
      }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in el1 and el2 are the majority elements
    // Only required if the question does not say there will definately be elements greater than n/3
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
      if (v[i] == el1)
        cnt1++;
      if (v[i] == el2)
        cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini)
      ls.push_back(el1);
    if (cnt2 >= mini)
      ls.push_back(el2);

    // Uncomment the following line if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); // TC --> O(2*log2) ~ O(1);

    return ls;
  }
};
