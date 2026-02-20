/*
Problem: SFJ(Average Waiting Time )(Greedy)


Approach:
1. Sort execution times in ascending order.
2. Maintain current elapsed time (t).
3. For each process, waiting time is equal to elapsed time so far.
4. Add waiting time to total wait.
5. Update elapsed time by adding current process time.
6. Return average waiting time.

Time Complexity: O(N log N)
Space Complexity: O(1)
*/


long long solve(vector<int>& a){
    sort(a.begin(), a.end());
    long long wait = 0, t = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
        wait += t;
        t += a[i];
    }
    return (wait / n);
}
