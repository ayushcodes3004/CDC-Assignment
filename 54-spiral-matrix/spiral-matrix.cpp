class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int sRow=0;
        int eCol=col-1;
        int eRow=row-1;
        int sCol=0;
        int cnt=0;
        while(cnt<total){
            //top row
            for(int i=sCol;i<=eCol && cnt<total ;i++){
                ans.push_back(matrix[sRow][i]);
                cnt++;
            }
            sRow++;
            //row col
            for(int i=sRow;i<=eRow && cnt<total;i++){
                ans.push_back(matrix[i][eCol]);
                cnt++;
            }
            eCol--;

            // 3. bottom row  <-- add safety check
            if(sRow <= eRow){
                for(int i=eCol; i>=sCol && cnt<total; i--){
                    ans.push_back(matrix[eRow][i]);
                    cnt++;
                }
            }
            eRow--;

            // 4. left column  <-- add safety check
            if(sCol <= eCol){
                for(int i=eRow; i>=sRow && cnt<total; i--){
                    ans.push_back(matrix[i][sCol]);
                    cnt++;
                }
            }
            sCol++;
        }
        return ans;

    }
};