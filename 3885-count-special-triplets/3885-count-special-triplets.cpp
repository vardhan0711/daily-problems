#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;  // Modulo value
        unordered_map<int, int> suffixCount, prefixCount;
        int n = nums.size();

        // Count all elements in suffixCount initially
        for (int num : nums) {
            suffixCount[num]++;
        }

        long long total = 0; // Use long long to prevent overflow before taking mod

        for (int i = 0; i < n; i++) {
            suffixCount[nums[i]]--;  // Current number removed from suffix

            int target = nums[i] * 2;
            long long leftCount = prefixCount[target];
            long long rightCount = suffixCount[target];

            // Add current contribution, take mod to prevent overflow
            total = (total + (leftCount * rightCount) % MOD) % MOD;

            prefixCount[nums[i]]++;  // Add current number to prefix for next iterations
        }

        return total;
    }
};
