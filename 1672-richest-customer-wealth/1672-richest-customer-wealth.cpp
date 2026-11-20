class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            int maxi = 0;
            for(int j = 0;j < m;j++){
                maxi += accounts[i][j];
            }
            ans = max(ans,maxi);
        }
        return ans;
    }
};