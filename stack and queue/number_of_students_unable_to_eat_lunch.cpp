/*
Problem: LeetCode 1700 – Number of Students Unable to Eat Lunch

Approach:
1. Put all students into a queue.
2. Maintain:
   - count → index of current sandwich.
3. Simulate the process:
   - Take student from front.
   - Compare with current sandwich.
4. If preference matches:
   - Student takes sandwich.
   - Move to next sandwich.
5. Otherwise:
   - Student goes to the back of queue.
6. Run simulation for at most n*n iterations:
   - Prevent infinite rotation when no student
     wants the current sandwich.
7. Remaining students in queue cannot eat.
8. Return:
   - n - count

Key Idea:
- Simulate exactly as described using a queue.
- If students keep rotating without taking a sandwich,
  the process stops.

Time Complexity: O(N²)
Space Complexity: O(N)
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for(int i : students){
            q.push(i);
        }

        int count = 0;
        int n = students.size();

        for(int i = 0; i < n * n && !q.empty(); i++){
            int stud = q.front();
            q.pop();

            int sand = sandwiches[count];

            if(stud == sand){
                count++;
            }else{
                q.push(stud);
            }
        }

        return n - count;
    }
};
