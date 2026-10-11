class Solution {
    private:
    vector<int>nextSmallest(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
     vector<int>previousSmallest(vector<int>&arr){
        int n=arr.size();
          vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=nextSmallest(arr);
        vector<int>psee=previousSmallest(arr);
        int sum=0;
        int MOD = 1e9 + 7;
        for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            long long ans=(left*right)%MOD;
            sum=(sum+ans*arr[i]*1ll)%MOD;
        }
        return sum;
    }
};