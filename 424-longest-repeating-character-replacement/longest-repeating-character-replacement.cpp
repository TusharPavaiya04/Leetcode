class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int left=0;
        int maxi=0;
        int maxiFreq=0;
        int maxLen=0;
        for(int right=0;right<s.size();right++){
         hash[s[right]-'A']++;
          maxiFreq=max(maxiFreq,hash[s[right]-'A']);
         int changes=right-left+1-maxiFreq;
         if(changes>k){
            hash[s[left]-'A']--;
            left++;
         }
        maxLen=max(maxLen,right-left+1);

        }
        return maxLen;
    }
};