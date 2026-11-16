class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string t = "";
        for(auto i:s){
            if(tolower(i)>='a'&&tolower(i)<='z'){
                t.push_back(tolower(i));
            }
            else if(i<='9'&&i>='0'){
                t.push_back(i);
            }
        }
        int i = 0;
        int j = t.size()-1;
        while(i<=j){
            if(t[i]==t[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
