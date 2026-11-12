class Solution {
public:
    bool isCycleHelper(int curr,vector<bool>&vis,vector<bool>&rec, vector<vector<int>>& edg){
        vis[curr] = true;
        rec[curr] = true;
        for(int i = 0;i < edg.size();i++){
            int v = edg[i][0];
            int u = edg[i][1];
            if(u == curr){
                if(!vis[v]){
                    if(isCycleHelper(v,vis,rec,edg)) return true;
                }
                else if(rec[v]){
                    return true;
                }
            }
        }
        rec[curr] = false;
        return false;
    }
    bool isCycle(int n, vector<vector<int>>& pr){
        vector<bool>vis(n,false);
        vector<bool>rec(n,false);
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                if(isCycleHelper(i,vis,rec,pr)) return true;
            }
        }
        return false;
    }
    void dfs(int curr,vector<bool>&vis,stack<int>&s, vector<vector<int>>& pr){
        vis[curr] = true;
        for(int i = 0;i < pr.size();i++){
            int v = pr[i][0];
            int u = pr[i][1];
            if(u == curr){
                if(!vis[v]){
                    dfs(v,vis,s,pr);
                }
            }
        }
        s.push(curr);
    }
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        if(isCycle(n,pr)){
            return {};
        }
        vector<bool>vis(n,false);
        vector<int>ans;
        stack<int>s;
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                dfs(i,vis,s,pr);
            }
        }
        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};