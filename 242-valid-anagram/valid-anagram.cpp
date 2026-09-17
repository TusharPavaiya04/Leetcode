class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mpp.find(t[i])==mpp.end())return false;
            mpp[t[i]]--;
        }
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]!=0)return false;
        }
        return true;
    }
};
