/*
Problem: LeetCode 599 – Minimum Index Sum of Two Lists

Approach:
1. Store all restaurants from list1 in a hashmap:
   - restaurant name → index
2. Traverse list2.
3. For each restaurant:
   - Check if it exists in list1.
4. If found:
   - Compute index sum:
       current index in list2 +
       stored index in list1
5. Maintain:
   - minSum = smallest index sum found so far
   - ans = restaurants having minSum
6. Cases:
   a) sum < minSum
      - Update minSum
      - Clear previous answers
      - Add current restaurant
   b) sum == minSum
      - Add current restaurant
7. Return all restaurants with the
   minimum index sum.

Key Idea:
- HashMap allows O(1) lookup of indices
  from the first list.
- Keep only restaurants having the
  smallest combined index sum.

Example:
list1 = ["Shogun","Tapioca Express","Burger King","KFC"]
list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]

Shogun:
index sum = 0 + 3 = 3

Answer:
["Shogun"]

Time Complexity: O(N + M)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {

        unordered_map<string, int> mp;

        for(int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }

        vector<string> ans;
        int minSum = INT_MAX;

        for(int i = 0; i < list2.size(); i++) {

            if(mp.count(list2[i])) {

                int sum = i + mp[list2[i]];

                if(sum < minSum) {
                    minSum = sum;

                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if(sum == minSum) {
                    ans.push_back(list2[i]);
                }
            }
        }

        return ans;
    }
};
