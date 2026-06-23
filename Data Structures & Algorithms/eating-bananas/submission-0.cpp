class Solution {
    int dfs(vector<int>&v, int k){
        int ans = 0;
        for(auto &i:v){
            ans+=(i+k-1)/k;
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int i = 1;
        int j = 1e9;
        int k;
        while(i<=j){
            int mid = j-(j-i)/2;
            int ans = dfs(v,mid);// time to eat
            if(ans>h){
                i = mid+1;
            }
            else{
                k = mid;
                j = mid-1;
            }
        }
        return k;
    }
};
