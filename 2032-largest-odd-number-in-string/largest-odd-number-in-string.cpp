class Solution {
public:
    string largestOddNumber(string num) {
        int lastIndex=num.size()-1;
        string ans="";
        while(lastIndex>=0){
            int lastNum=num[lastIndex]-'0';
            if(lastNum%2==0){
                lastIndex--;
            }else{
             for(int i=0;i<=lastIndex;i++){
                ans+=num[i];
             }
             return ans;
            }
        }
        return ans;
    }
};