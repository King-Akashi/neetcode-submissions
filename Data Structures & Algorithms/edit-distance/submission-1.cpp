class Solution {
    int dfs(string s1, string s2, int i, int j, vector<vector<int>>&dp){
        if(j==s2.size()&&i==s1.size()){
            return 0;
        }
        if(i==s1.size()){
            return (s2.size()-j);
        }
        if(j==s2.size()){
            return s1.size()-(i);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int a = 1e9, b=1e9, c=1e9, d=1e9;
        if(s1[i]==s2[j]){
            a = dfs(s1, s2, i+1, j+1, dp);// equal
            b = 1+dfs(s1, s2, i+1, j, dp); // delete
            c = 1+dfs(s1, s2, i, j+1,dp);// insert
        }
        else{
            b = 1+dfs(s1, s2, i+1, j, dp);// delete
            c = 1+dfs(s1, s2, i, j+1, dp);// insert
            d = 1+dfs(s1, s2, i+1, j+1, dp);// replace
        }
        return dp[i][j] = min({a, b,c, d});

    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return dfs(word1, word2, 0, 0, dp);
    }
};
