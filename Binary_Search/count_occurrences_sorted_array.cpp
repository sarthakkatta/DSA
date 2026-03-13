/*
Problem: Count Occurrences in a Sorted Array

Approach:
1. Use Binary Search to find the first occurrence of the target.
2. Again apply Binary Search to find the last occurrence.
3. If the element does not exist, return 0.
4. Otherwise the count is (last index - first index + 1).

Time Complexity: O(log N)
Space Complexity: O(1)
*/

int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);

    if (first == -1)
        return {-1, -1};

    int last = lastOccurrence(arr, n, k);

    return {first, last};
}

int count(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);

    if (ans.first == -1)
        return 0;

    return (ans.second - ans.first + 1);
}
