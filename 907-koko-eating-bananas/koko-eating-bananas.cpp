class Solution {
    private:
    long long checkHours(vector<int>&piles,int mid,int h){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=ceil((double)piles[i]/(double)mid);
        }
            return ans;
        }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ans=checkHours(piles,mid,h);
            if(ans>h){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};