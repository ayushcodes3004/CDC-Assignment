class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        if(flowerbed.size()==1){
            cnt=!flowerbed[0];
            return cnt>=n;
        } 
        
        for(int i=0;i<flowerbed.size();i++){
            if(i==0){
                if(flowerbed[i+1]==0 && flowerbed[i]==0){
                    flowerbed[i]=1;
                    cnt+=1; 
                }
            }
            else if(i==flowerbed.size()-1){
                if(flowerbed[i-1]==0 && flowerbed[i]==0){
                    cnt+=1;
                }
            }
            else if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0){
                cnt+=1;
                flowerbed[i]=1;
            }
        }
        return cnt>=n;
    }
};