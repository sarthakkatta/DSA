/*
Problem: LeetCode 1207 – Unique Number of Occurrences

Approach:
1. Use an unordered_map to count the frequency
   of every element in the array.
2. Traverse the frequency map.
3. Store every frequency in an unordered_set.
4. If two different numbers have the same frequency,
   the set size will be smaller than the map size.
5. Compare:
      mpp.size() == s.size()
   - Equal → all frequencies are unique.
   - Not equal → duplicate frequency exists.

Key Idea:
- Map stores:
      number → frequency
- Set stores only unique frequencies.
- If the number of frequencies is equal to the
  number of unique frequencies, every occurrence
  count is different.

Example:

arr = [1, 2, 2, 1, 1, 3]

Frequencies:
1 → 3
2 → 2
3 → 1

Set:
{3, 2, 1}

Map size = 3
Set size = 3

Answer:
true

Time Complexity: O(N)

Space Complexity: O(N)
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]]++;
        }
        unordered_set<int>s;
        for(auto x: mpp){
          s.insert(x.second);
        }
        return mpp.size()==s.size();
    }
};
