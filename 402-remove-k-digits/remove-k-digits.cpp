class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty()&&k>0&&num[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty()&&k>0){
            k--;
            st.pop();
        }
        if(st.empty())return "0";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        } 

        while(ans.size()!=0&&ans.back()=='0'){
            ans.pop_back();
        }
          if(ans.empty())return "0";

        reverse(ans.begin(),ans.end());
        return ans;
    }
};