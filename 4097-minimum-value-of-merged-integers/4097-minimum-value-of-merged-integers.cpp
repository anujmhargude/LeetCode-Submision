class Solution {
public:
    int merg(int a,int b){
        string s = to_string(a)+to_string(b);
        return stoll(s);
    }
    int minMergedInteger(vector<int>& nums) {
        int i = 0;
        int j = 1;
        vector<int>v;
        while(i < nums.size()||j < nums.size()){
            int temp = merg(nums[i],nums[j]);
            v.push_back(temp);
            i = i+2;
            j = j+2;
        }
        int ans = v[0];
        for(int i = 1;i < v.size();i++){
            ans = min(ans,v[i]);
        }
        return ans;
    }
};