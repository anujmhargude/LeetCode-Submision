class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        // nums and target must contain same elements
        vector<int> freq(100001, 0);

        for (int x : nums)
            freq[x]++;

        for (int x : target)
            freq[x]--;

        for (int x : freq) {
            if (x != 0)
                return 0;
        }

        // First position where nums and target are different
        int p = n;

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                p = i;
                break;
            }
        }

        // Start of the non-increasing suffix of target
        int q = 0;

        for (int i = n - 1; i > 0; i--) {
            if (target[i - 1] < target[i]) {
                q = i;
                break;
            }
        }

        return max(0, min(p, n - 1) - q + 1);
    }
};