#include <iostream>
#include <vector>
#include <algorithm> // For min and max
#include <climits>   // For INT_MIN

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int max_area = 0; // Area cannot be negative, so 0 is a safer init

        while (i < j) {
            // Calculate current area
            // Area = width * height_of_shorter_line
            int width = j - i;
            int currentHeight = min(height[i], height[j]);
            int area = width * currentHeight;
            
            max_area = max(max_area, area);

            // Move the pointer pointing to the shorter line
            // because keeping the shorter line can never produce a larger area
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max_area;
    }
};

int main() {
    Solution sol;

    // Example Test Case
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    int result = sol.maxArea(height);

    cout << "Maximum area of water the container can contain: " << result << endl;

    return 0;
}