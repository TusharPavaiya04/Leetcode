class Solution {
    private:
    int checkMinSum(vector<int>&nums,int m,int k){
        int sum=0;
        int part=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=m){
                sum+=nums[i];
            }else{
                part++;
                sum=nums[i];
            }
        } 
        return part;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        while(l<=h){
            int mid=l+(h-l)/2;
            int ans=checkMinSum(nums,mid,k);
            if(ans>k){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return l;
    }
};