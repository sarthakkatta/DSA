/*
Problem: Minimum Platforms Required for Railway Station (Greedy)


Approach:
1. Sort arrival and departure arrays.
2. Use two pointers:
   - i → arrival pointer
   - j → departure pointer
3. If next train arrives before or at departure, increase platform count.
4. Otherwise decrease platform count.
5. Track maximum platform count required at any time.

Time Complexity: O(N log N)
Space Complexity: O(1)
*/


class Solution {
public:

    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int i = 0, j = 0;
        int count = 0;
        int maxC = 0;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        while(i < n){
            if(arr[i] <= dep[j]){
                count++;
                maxC = max(maxC, count);
                i++;
            }
            else{
                count--;
                j++;
            }
        }
        return maxC;
    }
};
