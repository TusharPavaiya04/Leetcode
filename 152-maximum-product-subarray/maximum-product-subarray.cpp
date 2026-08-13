class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suf=1;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){

           prefix=prefix*nums[i];
           suf=suf*nums[n-1-i];
           maxi=max(maxi,max(prefix,suf));
           if(prefix==0)prefix=1;
           if(suf==0)suf=1;
           }
        
        return maxi;
    }
};