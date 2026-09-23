class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
         long long ans=0;

        while(i<s.size()&&s[i]==' '){
            i++;
        }
        while(i<s.size()&&(s[i]=='+'||s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
            if(!isdigit(s[i])){
             return 0;
            }
        }

         while(i<s.size()&&isdigit(s[i])){
            int digit=s[i]-'0';
            i++;
         ans=ans*10+digit;
         if(ans*sign>INT_MAX){
            return INT_MAX;
         }
         if(ans*sign<INT_MIN)return INT_MIN;
         }
         ans=ans*sign;
return ans;


    }
};