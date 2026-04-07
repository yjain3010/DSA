#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int leftMax = 0, rightMax = 0;
        int i = 0, j = n - 1;
        int res = 0;

        while (i <= j) {
            // We move the pointer with the smaller height because 
            // the water trapped is limited by the shorter wall.
            if (height[i] <= height[j]) {
                if (height[i] >= leftMax) {
                    leftMax = height[i]; // Update boundary
                } else {
                    res += leftMax - height[i]; // Trap water
                }
                i++;
            } else {
                if (height[j] >= rightMax) {
                    rightMax = height[j]; // Update boundary
                } else {
                    res += rightMax - height[j]; // Trap water
                }
                j--;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example test case: a classic "valley" shape
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    int result = sol.trap(height);
    
    cout << "Total water trapped: " << result << " units" << endl;

    return 0;
}