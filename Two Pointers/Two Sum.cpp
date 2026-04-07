#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> original = nums; // Keep original to find indices later

        sort(nums.begin(), nums.end());

        int i = 0, j = n - 1;
        int u = -1, v = -1;

        // Find the two values that sum to target
        while (i < j) {
            long currentSum = (long)nums[i] + nums[j];
            if (currentSum == target) {
                u = nums[i];
                v = nums[j];
                break;
            } else if (currentSum > target) {
                j--;
            } else {
                i++;
            }
        }

        vector<int> ans;
        // Find original indices of u and v
        for (int k = 0; k < n; k++) {
            if (original[k] == u || original[k] == v) {
                ans.push_back(k);
                // If u and v are the same value (e.g., 3 + 3 = 6), 
                // we need to make sure we don't accidentally pick the same index twice
                // or pick a third index if there's another '3' in the array.
                if (ans.size() == 2) break; 
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> result = sol.twoSum(nums, target);

    cout << "Original Indices: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}