class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int i = 0;
        int j = n-1;
        int mx = 0;
        while(i<j){
            mx = max(mx, (j-i)*min(v[i], v[j]));
            if(v[i]<v[j]){
                i++;
            }
            else {j--;}
        }
        return mx;
    }
};
