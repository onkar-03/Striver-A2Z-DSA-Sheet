#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force using Ordered Set
 * - Use a `set` to store unique elements from both arrays.
 *   - Insert all elements from array `a` into the `set`.
 *   - Insert all elements from array `b` into the `set`.
 * - A `set` automatically maintains sorted order and ensures uniqueness of elements.
 * - Convert the elements of the `set` into a `vector` and return it as the result.
 * ----------------------------
 * T.C: O((m + n) * log(m + n))
 * - Insertion into a `set` takes O(log(size of set)) per element
 * Inserting in worst case is (m + n) elements back to the res vector
 * - For a total of (m + n) elements, this results in O((m + n) * log(m + n)).
 * ----------------------------
 * S.C: O(m + n)
 * - The `set` stores all unique elements from the input arrays, which can be at most (m + n).
 * - The resulting `vector` also stores these unique elements, resulting in O(m + n) additional space.
 */
class Solution
{
public:
  vector<int> findUnion(vector<int> &a, vector<int> &b)
  {
    // Create an unordered_set to store unique elements
    set<int> s;

    // Insert all elements from array 'a' into the set
    for (int i = 0; i < a.size(); i++)
    {
      s.insert(a[i]);
    }

    // Insert all elements from array 'b' into the set
    for (int i = 0; i < b.size(); i++)
    {
      s.insert(b[i]);
    }

    // Create a vector to store the elements of the set
    vector<int> res(s.begin(), s.end());

    return res; // Return the sorted union
  }
};

/*
 * Approach-2: Brute Force using Ordered Map
 * - Use a `map<int, int>` to store the frequency of elements from both arrays.
 * - Traverse array `a` and insert its elements into the map.
 * - Traverse array `b` and insert its elements into the map.
 * - The keys of the map represent the unique elements in sorted order.
 * - Traverse the map and collect the keys into a result vector `Union`.
 * ----------------------------
 * T.C: O((n + m) * log(n + m))
 * - Insertion of `n + m` elements into the map takes O((n + m) * log(n + m)) due to the logarithmic time complexity of `map` insertions.
 * ----------------------------
 * S.C: O(n + m)
 * - The map stores all unique elements from both arrays.
 * - The result vector `Union` also stores the unique elements.
 */

class Solution
{
public:
  vector<int> findUnion(vector<int> &a, vector<int> &b)
  {
    map<int, int> freq; // Map to store the frequency of elements
    vector<int> Union;  // Vector to store the union result

    // Insert all elements from array `a` into the map
    for (int i = 0; i < a.size(); i++)
    {
      freq[a[i]]++;
    }

    // Insert all elements from array `b` into the map
    for (int i = 0; i < b.size(); i++)
    {
      freq[b[i]]++;
    }

    // Extract the keys (unique elements) from the map into the result vector
    for (auto &it : freq)
    {
      Union.push_back(it.first);
    }

    return Union; // Return the resulting union vector
  }
};

/*
 * Approach-3: Optimal Solution 2 Pointer Approach
 * - Use two pointers `i` and `j` to traverse the two sorted arrays `a` and `b`.
 * - Compare the elements at `a[i]` and `b[j]`:
 *   - If `a[i]` is smaller or equal to `b[j]`, add `a[i]` to the union if it's not a duplicate.
 *   - If `b[j]` is smaller, add `b[j]` to the union if it's not a duplicate.
 *   - Increment the respective pointer.
 * - After traversal, process any remaining elements in `a` or `b` while checking for duplicates.
 * ----------------------------
 * T.C: O(n + m)
 * - Traversing through both arrays takes linear time.
 * ----------------------------
 * S.C: O(n + m)
 * - The union vector can store at most all elements from both arrays, i.e., O(n + m).
 */
class Solution
{
public:
  vector<int> findUnion(vector<int> &a, vector<int> &b)
  {
    int m = a.size();  // Size of array a
    int n = b.size();  // Size of array b
    int i = 0, j = 0;  // Pointers for traversing a and b
    vector<int> Union; // Vector to store the union result

    // Traverse both arrays
    while (i < m && j < n)
    {
      // Case 1: a[i] is smaller or equal to b[j]
      if (a[i] <= b[j])
      {
        // Add a[i] to Union if it's not a duplicate
        if (Union.empty() || Union.back() != a[i])
        {
          Union.push_back(a[i]);
        }
        i++; // Increment pointer for a
      }
      // Case 2: b[j] is smaller
      else
      {
        // Add b[j] to Union if it's not a duplicate
        if (Union.empty() || Union.back() != b[j])
        {
          Union.push_back(b[j]);
        }
        j++; // Increment pointer for b
      }
    }

    // Process remaining elements in a
    while (i < m)
    {
      // Add remaining elements from a if not duplicates
      if (Union.empty() || Union.back() != a[i])
      {
        Union.push_back(a[i]);
      }
      i++;
    }

    // Process remaining elements in b
    while (j < n)
    {
      // Add remaining elements from b if not duplicates
      if (Union.empty() || Union.back() != b[j])
      {
        Union.push_back(b[j]);
      }
      j++;
    }

    return Union; // Return the resulting union vector
  }
};
