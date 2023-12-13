#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int result = 0;

    int maxNum = *max_element(nums.begin(), nums.end());
    vector<int> freq(n, 0);
    
    int i = 0, j = 0;
    
    while (j < n) {
        if (nums[j] == maxNum) {
            freq[j]++;
            result += (n - j);
            j++;
        } else {
            freq[j] = freq[j - 1];
            j++;
        }

        while (i < j && freq[j - 1] >= k) {
            freq[i]--;
            i++;
        }
    }

    return result;
}

int main() {
    // Example usage
    vector<int> nums1 = {1, 3, 2, 3, 3};
    int k1 = 2;
    cout << "Output 1: " << countSubarrays(nums1, k1) << endl; // Output: 6

    vector<int> nums2 = {1, 4, 2, 1};
    int k2 = 3;
    cout << "Output 2: " << countSubarrays(nums2, k2) << endl; // Output: 0

    return 0;
}
