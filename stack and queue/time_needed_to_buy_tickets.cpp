/*
Problem: LeetCode 2073 – Time Needed to Buy Tickets

Approach:
1. Store indices of people in a queue.
2. Each second:
   - Person at front buys one ticket.
   - Decrease their remaining tickets.
   - Increase time counter.
3. If the person still needs tickets:
   - Push them back into the queue.
4. Continue until person k has bought all tickets:
   - tickets[k] becomes 0.
5. Return total time taken.

Key Idea:
- Simulate the ticket-buying process exactly
  as described using a queue of indices.

Time Complexity: O(T)
  where T = total tickets purchased

Space Complexity: O(N)
*/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       queue<int> q;

       for(int i = 0; i < tickets.size(); i++){
            q.push(i);
       }

       int count = 0;

       while(tickets[k] > 0){
            int p = q.front();
            q.pop();

            tickets[p]--;
            count++;

            if(tickets[p] != 0){
                q.push(p);
            }
       }

       return count;
    }
};
