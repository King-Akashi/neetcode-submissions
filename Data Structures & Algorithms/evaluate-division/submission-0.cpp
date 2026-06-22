class Solution {
    map<string, vector<pair<string,double>>>mp;
    void dfs(string str, string target, double mul,map<string,bool>&vis, double& ans){
        if(target==str){
            ans = mul;
            return;
        }
        vis[str] = true;
        for(auto i:mp[str]){
            if(vis[i.first])continue;
            dfs(i.first, target, mul*i.second, vis, ans);
        }

    }
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& values, vector<vector<string>>& queries) {
        // e[i] = [Ai, Bi]
        int n = e.size();
        for(int i = 0;i<n;i++){
            mp[e[i][0]].push_back({e[i][1], values[i]});
            mp[e[i][1]].push_back({e[i][0], 1/values[i]});
        }
        // graph is constructed
        // for queries, we need to construct a dfs
        vector<double>actAns;
        for(auto i:queries){
            if(mp.find(i[0])==mp.end()||mp.find(i[1])==mp.end()){actAns.push_back(-1);continue;}
            map<string, bool>vis;
            double ans = -1;
            dfs(i[0], i[1], 1, vis, ans);
            actAns.push_back(ans);
        }
        return actAns;
    }
};