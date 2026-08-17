class Solution {
    private:
    int minWeights(vector<int>&weights,int days,int mid){
      int cnt=0;
      int day=1;
        for(int i=0;i<weights.size();i++){
        if(cnt+weights[i]>mid){
            day++;
            cnt=weights[i];
        }        else{
            cnt+=weights[i];
        }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        while(l<=h){
            int mid=l+(h-l)/2;
            int ans=minWeights(weights,days,mid);
            if(ans<=days){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};

