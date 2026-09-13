class Solution {
    private:
    int maxcol(vector<vector<int>>&mat,int n,int mid){
        int maxVal=-1;
        int ind=-1;
        for(int i=0;i<n;i++){
           if(mat[i][mid]>maxVal){
            maxVal=mat[i][mid];
            ind=i;
           }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int maxColVal=maxcol(mat,n,mid);
            int left=mid-1>=0?mat[maxColVal][mid-1]:-1;
            int right=mid+1<=m-1?mat[maxColVal][mid+1]:-1;
            if(left<mat[maxColVal][mid]&&mat[maxColVal][mid]>right)return {maxColVal,mid};
            else if(left>mat[maxColVal][mid])h=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
    }
};