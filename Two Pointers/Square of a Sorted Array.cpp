#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int pos = n - 1; // Start filling from the end

        vector<int> ans(n, 0);

        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if (leftSq >= rightSq) {
                ans[pos] = leftSq;
                left++;
            } else {
                ans[pos] = rightSq;
                right--;
            }
            pos--; // Move to the next largest position
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = sol.sortedSquares(nums);

    cout << "Sorted Squares: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}