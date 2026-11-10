class Solution {
public:
    // void dfs(int i,int j,vector<vector<int>>& grid,int n,int m){
    //     if(i < 0||j < 0||i >=n||j >= m||grid[i][j] == 0||grid[i][j] == 2){
    //         return;
    //     }
    //     grid[i][j] = 2;
    //     dfs(i-1,j,grid,n,m);
    //     dfs(i,j+1,grid,n,m);
    //     dfs(i+1,j,grid,n,m);
    //     dfs(i,j-1,grid,n,m);
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int >>q;
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }
        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int temp = q.front().second;
            q.pop();
            time = max(time,temp);
            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1){
                vis[i-1][j] = true;
                q.push({{i-1,j},temp+1});
            }
            if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1){
                vis[i][j+1] = true;
                q.push({{i,j+1},temp+1});
            }
            if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1){
                vis[i+1][j] = true;
                q.push({{i+1,j},temp+1});
            }
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1){
                vis[i][j-1] = true;
                q.push({{i,j-1},temp+1});
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1 && !vis[i][j] ){
                    return -1;
                }
            }
        }
        return time;
    }
};