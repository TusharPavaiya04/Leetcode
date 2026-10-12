class Solution {
    private:
    int checkMin(vector<int>&nums,int m){
        int part=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sum<=m){
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
            if(checkMin(nums,mid)>k){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }

        return l;
    }
};