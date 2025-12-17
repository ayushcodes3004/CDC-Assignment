class Solution {
private:
    bool isSafe(int r, int c,int n,vector<string>& board){
        //check row
        for(int i=0;i<n;i++){
            if(board[r][i]=='Q')    return false;
            // if(board[i][c]=='Q')    return false;
        }
        //upper left diagonal
        for(int i=r,j=c;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q')    return false;
        }
        //lower left diagonal
        for(int i=r,j=c;i<n && j>=0;i++,j--){
            if(board[i][j]=='Q')    return false;
        }
        return true;
    }
    void rec(int c,int n,vector<string>& board,vector<vector<string>>& ans){
        //placing column wise 
        if(c==n){
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++){
            if(isSafe(r,c,n,board)){
                board[r][c]='Q';
                rec(c+1,n,board,ans);
                board[r][c]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        rec(0,n,board,ans);
        return ans;
    }
};