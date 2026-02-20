/*
Problem: Maximum Meetings in One Room (Greedy)


Approach:
1. Store meetings as pair of (end, start).
2. Sort meetings by end time.
3. Always select meeting that ends earliest.
4. If next meeting start time is greater than last selected meeting end time,
   select it and update last end time.
5. Count total selected meetings.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/


int maximumMeetings(vector<int> &start, vector<int> &end){
    int n = start.size();
    vector<pair<int,int>> meetings;
    for(int i = 0; i < n; i++){
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());
    int count = 1;
    int lastend = meetings[0].first;
    for(int i = 0; i < n; i++){
        if(meetings[i].second > lastend){
            count++;
            lastend = meetings[i].first;
        }
    }

    return count;
}
