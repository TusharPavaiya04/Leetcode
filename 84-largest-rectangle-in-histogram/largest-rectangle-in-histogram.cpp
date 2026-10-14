class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int el=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi,el*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
        int nse=heights.size();
        int el=heights[st.top()];
        st.pop();
        int pse=st.empty()?-1:st.top();
        maxi=max(maxi,el*(nse-pse-1));
        }
        return maxi;
    }
};