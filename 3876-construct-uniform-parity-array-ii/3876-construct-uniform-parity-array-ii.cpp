class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 != 0) {
                minOdd = min(minOdd, x);
            }
        }

        // If there is no odd number, all numbers are already even
        if (minOdd == INT_MAX) {
            return true;
        }

        // We can always make the final array all odd
        // if every even number has a smaller odd number.
        for (int x : nums1) {
            if (x % 2 == 0 && minOdd >= x) {
                return false;
            }
        }

        return true;
    }
};