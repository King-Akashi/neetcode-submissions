class Solution {
public:
    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0;i<strs.size();i++){
            int cnt = 0;
            string ans = "";
            ans.append(to_string(strs[i].size()));
            ans+='#';
            ans.append(strs[i]);
            s.append(ans);
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;

        while(i<s.size()){
            string cnt = "";
            while(s[i]!='#'){
                cnt.push_back(s[i]);
                i++;
            }
            int len = stoi(cnt);
            // now we are at #
            i++;
            string t = s.substr(i, len);
            ans.push_back(t);
            i+=len;
        }
        return ans;
    }
};
