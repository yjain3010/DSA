#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {
            int currentSum = numbers[i] + numbers[j];

            if (currentSum == target) {
                // Returns 1-based indices as per problem requirements
                return {i + 1, j + 1};
            } else if (currentSum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {}; // Return empty if no solution exists
    }
};

int main() {
    Solution sol;
    
    // Test Case: Sorted array
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(numbers, target);

    // Output the results
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}