class Solution {
public:
    int findMin(vector<int>& nums) {
     int l=0;
     int h=nums.size()-1;
     int ans=INT_MAX;
     while(l<=h){
        int mid=h-(h-l)/2;
        if(nums[l]<=nums[mid]){
        ans=min(nums[l],ans);
            l=mid+1;
        }else{
            ans=min(nums[mid],ans);
            h=mid-1;
        }
     }   
     return ans;
    }
};