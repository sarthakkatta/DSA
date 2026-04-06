/*
Problem: LeetCode 2469 – Convert the Temperature

Approach:
1. Given temperature in Celsius.
2. Convert to Kelvin using:
   - Kelvin = Celsius + 273.15
3. Convert to Fahrenheit using:
   - Fahrenheit = Celsius * 1.80 + 32.00
4. Return both values in a vector.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15,celsius * 1.80 + 32.00};
    }
};
