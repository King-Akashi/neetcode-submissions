class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        int cnt = 1;
        int pre = *st.begin();
        int mx = 0;
        for(auto i:st){
            if(i == pre+1){
                cnt++;
                pre = i;
            }
            else{
                cnt = 1;
                pre = i;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};
