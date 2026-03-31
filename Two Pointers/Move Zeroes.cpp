#include <iostream>
#include <vector>
#include <algorithm> // For swap

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; // Pointer for the next non-zero element position

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                // Swap the current non-zero element with the element at the i-th position
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

int main() {
    Solution sol;
    
    // Example Test Case
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    sol.moveZeroes(nums);

    cout << "After:  ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}