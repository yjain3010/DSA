#include <iostream>
#include <vector>
#include <algorithm> // For swap

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // If it's a 0, move it to the 'low' section
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // If it's a 1, it's already in the correct 'mid' section
                mid++;
            } 
            else { // nums[mid] == 2
                // If it's a 2, move it to the 'high' section
                // Note: We don't increment mid here because the swapped 
                // element from high hasn't been processed yet.
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    sol.sortColors(nums);

    cout << "Sorted:   ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    return 0;
}