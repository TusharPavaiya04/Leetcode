class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
         for(auto it:st){
            if(st.find(it-1)==st.end()){
                int el=it;
                int cnt=1;
                while(st.find(el+1)!=st.end()){
                    el=el+1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
         }
        return longest;
    }
};