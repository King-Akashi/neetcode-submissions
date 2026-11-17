class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int n = prices.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            mn = min(prices[i], mn);
            ans = max(ans, prices[i]-mn);
        }
        return ans;
    }
};
