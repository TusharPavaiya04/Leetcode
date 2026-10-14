class Solution {
    private:
    int largHist(vector<int>arr){
     stack<int>st;
     int maxi=0;
     for(int i=0;i<arr.size();i++){
        while(!st.empty()&&arr[st.top()]>arr[i]){
            int el=arr[st.top()];
            st.pop();
            int nse=i;
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi,el*(nse-pse-1));
        }
        st.push(i);
     }
     while(!st.empty()){
        int el=arr[st.top()];
        st.pop();
        int nse=arr.size();
        int pse=st.empty()?-1:st.top();
        maxi=max(maxi,el*(nse-pse-1));
     }
     return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            maxi=max(maxi,largHist(height));
        }
        return maxi;
    }
};