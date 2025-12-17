class Solution {
private:
    bool issafe(int r,int c,int d,vector<vector<char>>& b){
        int n=b.size();
        for(int i=0;i<n;i++){
            if(b[r][i]==d)  return false;
            if(b[i][c]==d)  return false;
        }
        int sr=(r/3)*3;
        int sc=(c/3)*3;
        for(int i=sr;i<=sr+2;i++){
            for(int j=sc;j<=sc+2;j++){
                if(b[i][j]==d)  return false;
            }
        }
        return true;
    }
    bool ss(int r,int c,vector<vector<char>>& board){
        if(r==9)    return true;

        int nextr=r;
        int nextc=c+1;
        if(nextc==9){
            nextr=r+1;
            nextc=0;
        }
        if(board[r][c]!='.')    return ss(nextr,nextc,board);
        for(char d='1';d<='9';d++){
            if(issafe(r,c,d,board)){
                board[r][c]=d;
                if(ss(nextr,nextc,board)) return true;;
                board[r][c]='.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        ss(0,0,board);
    }
};