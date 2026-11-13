class Solution {
public:
    void dfs(int i ,int j ,vector<vector<int>>& image,int color ,int tar){
        if( i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != tar || color == tar){
            return;
        }
        image[i][j] = color;
        dfs(i-1,j,image,color,tar);
        dfs(i,j+1,image,color,tar);
        dfs(i+1,j,image,color,tar);
        dfs(i,j-1,image,color,tar);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int tar = image[sr][sc];
        dfs(sr,sc,image,color,tar);
        return image;
    }
};