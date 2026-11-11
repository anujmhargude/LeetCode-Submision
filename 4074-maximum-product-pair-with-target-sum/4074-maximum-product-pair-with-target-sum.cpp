class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int p = INT_MIN;
        vector<int> ans = {-1, -1};

        for (int i = 0; i < nums.size(); i++) {
            int rmg = target - nums[i];

            for (int j = 0; j < nums.size(); j++) {

                if (i != j &&
                    nums[j] == rmg &&
                    nums[i] > nums[j] &&
                    nums[i] * nums[j] > p) {

                    p = nums[i] * nums[j];

                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }
};