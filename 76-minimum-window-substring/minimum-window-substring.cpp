class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        unordered_map<char,int>mpp;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }

        int start=0;
        int left=0;
        int count=t.size();
        int minLen=INT_MAX;
        for(int right=0;right<s.size();right++){
            if(mpp[s[right]]>0){
                count--;
            }
            mpp[s[right]]--;
            while(count==0){
                if(minLen>right-left+1){
                    minLen=min(minLen,right-left+1);
                    start=left;
                }
                mpp[s[left]]++;;
                if(mpp[s[left]]>0){
                    count++;
                }
                left++;
            }
        }
          if(minLen==INT_MAX){
            return "";
          }else{
            return s.substr(start,minLen);
          }
    }
};