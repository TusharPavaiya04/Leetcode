class Solution {
    private:
    int divisor(vector<int>&nums,int threshold,int mid){
      int cnt=0;
      for(int i=0;i<nums.size();i++){
       cnt+=ceil((double)nums[i]/mid);
      } 
      return cnt;
         }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int l=1;
       int h=*max_element(nums.begin(),nums.end());
       while(l<=h){
        int mid=l+(h-l)/2;
       int ans=divisor(nums,threshold,mid);
         if(ans<=threshold){
            h=mid-1;
     }else{
        l=mid+1;
     }
       }  
       return l;
    }
};