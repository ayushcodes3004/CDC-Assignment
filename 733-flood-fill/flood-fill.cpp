class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& image,vector<vector<int>>& ans, int initial, int color){
        int m=image.size();
        int n=image[0].size();
        ans[sr][sc]=color;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int r=sr+delr[i];
            int c=sc+delc[i];
            if(r>=0 && r<m && c>=0 && c<n && image[r][c]==initial && ans[r][c]!=color){
                dfs(r,c,image,ans,initial,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>ans=image;
        int initial=image[sr][sc];
        if (initial == color) return image;
        dfs(sr,sc,image,ans,initial,color);
        return ans;
    }
};