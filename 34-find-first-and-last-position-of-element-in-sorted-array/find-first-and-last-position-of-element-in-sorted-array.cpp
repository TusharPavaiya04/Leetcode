class Solution {
public:
int lb(vector<int>&nums,int target){
    int l=0;
    int h=nums.size()-1;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]>=target){
            ans=mid;
            h=mid-1;
}else{
    l=mid+1;
}
    }
    return ans;
}
int ub(vector<int>&nums,int target){
    int l=0;
    int h=nums.size()-1;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]>target){
            h=mid-1;
}else{
            ans=mid;
    l=mid+1;
}
    }
    return  ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower=lb(nums,target);
        int upper=ub(nums,target);
        if(lower==-1||upper==-1)return {-1,-1};
        if(nums[lower]!=target)return {-1,-1};
        return {lower,upper};
    }
};
