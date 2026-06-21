class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMax = 0, maxSum = nums[0];
        int curMin = 0, minSum = nums[0];

        for (int num : nums) {
            // Kadane for maximum subarray
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);

            // Kadane for minimum subarray
            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);

            total += num;
        }

        // If all numbers are negative, maxSum is the answer
        if (maxSum < 0) return maxSum;

        // Otherwise, consider circular case
        return max(maxSum, total - minSum);
    }
};
