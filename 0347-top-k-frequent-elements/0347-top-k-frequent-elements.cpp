class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        vector<int>ans;
        int max = 0;
        for(int i = 0;i < n;i++){
            m[nums[i]]++;
        }
        for(int i = 0;i < k;i++){
            int idx;
            for(auto j : m){
                if(max < j.second){
                    max = j.second;
                    idx = j.first;
                }
            }
            ans.push_back(idx);
            m[idx] = 0;
            max = 0;
        }
        return ans;
    }
};