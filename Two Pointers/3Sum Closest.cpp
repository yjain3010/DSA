#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Initialize with a sum from the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];

                // If we found the exact target, return immediately
                if (currSum == target) return currSum;

                // Update closestSum if the current one is closer to target
                if (abs(target - currSum) < abs(target - closestSum)) {
                    closestSum = currSum;
                }

                // Move pointers based on sum comparison to target
                if (currSum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return closestSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = sol.threeSumClosest(nums, target);

    cout << "The triplet sum closest to " << target << " is: " << result << endl;

    return 0;
}