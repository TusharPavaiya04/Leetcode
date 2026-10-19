class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>chelper(m,0);
        vector<int>rhelper(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    chelper[j]=1;
                      rhelper[i]=1;
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
          if(rhelper[i]==1||chelper[j]==1){
            matrix[i][j]=0;
          }
          
            }
         }
return ;
    }
};