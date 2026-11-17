class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // length of the longest substring without duplicate characters
        int i = 0;
        int n = s.size();
        map<char,int>v;
        int mx = 0;
        for(int j = 0;j<n;j++){
            v[s[j]]++;
            while(i<j&&v[s[j]]>1){
                v[s[i]]--;
                i++;
            }
            mx = max(mx, j- i+1);
        }
        return mx;
    }
};
