/*
Problem: Job Sequencing Problem (Greedy)


Approach:
1. Sort all jobs in descending order of profit.
2. Find maximum deadline to create time slots.
3. Create a slot array initialized with -1 (free slot).
4. For each job, try placing it in latest free slot before its deadline.
5. If slot is free, assign job and add its profit.
6. Return total jobs done and total profit.

Time Complexity: O(N log N + N * D)
Space Complexity: O(D)
*/


#include <vector>
#include <algorithm>
using namespace std;

vector<int> jobScheduling(vector<vector<int>> &jobs){
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b){
        return a[2] > b[2];
    });
  
    int maxDeadline = -1;
    for(int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }
  
    vector<int> hash(maxDeadline + 1, -1);
  
    int count = 0;
    int totalProfit = 0;
  
    for(int i = 0; i < n; i++){
        int id = jobs[i][0];
        int deadline = jobs[i][1];
        int profit = jobs[i][2];
        for(int j = deadline; j > 0; j--){
            if(hash[j] == -1){
                hash[j] = id;
                count++;
                totalProfit += profit;
                break;
            }
        }
    }
    return {count, totalProfit};
}
