/*
Problem: Fractional Knapsack Problem (Greedy)


Approach:
1. Calculate value/weight ratio for each item.
2. Sort items in descending order of value/weight ratio.
3. Take whole item if capacity allows.
4. Otherwise, take fractional part of item.
5. Add value accordingly to maximize total value.

Time Complexity: O(N log N)
Space Complexity: O(1)
*/


struct Item {
    int value, weight;
};

// Comparator to sort items by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}


double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    double totalValue = 0.0;
    for(int i = 0; i < n; i++){
        if(W >= arr[i].weight){
            W -= arr[i].weight;
            totalValue += arr[i].value;
        }
        else{
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return totalValue;
}
