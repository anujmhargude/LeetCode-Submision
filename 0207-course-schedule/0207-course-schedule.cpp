class Solution {
public:
    bool isCycle(int curr,vector<bool>&vis,vector<bool>&rec, vector<vector<int>>& edg){
        vis[curr] = true;
        rec[curr] = true;
        for(int i = 0;i < edg.size();i++){
            int v = edg[i][0];
            int u = edg[i][1];
            if(u == curr){
                if(!vis[v]){
                    if(isCycle(v,vis,rec,edg)) return true;
                }
                else if(rec[v]){
                    return true;
                }
            }
        }
        rec[curr] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool>vis(n,false);
        vector<bool>rec(n,false);
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                if(isCycle(i,vis,rec,prerequisites)) return false;
            }
        }
        return true;
    }
};