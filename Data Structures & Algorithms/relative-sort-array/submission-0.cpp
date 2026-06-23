class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        vector<int>lft;
        for(auto i:arr2){
            bool ok = false;
            for(int j = 0;j<arr1.size();j++){
                if(arr1[j]==i){
                    ans.push_back(i);
                    ok = true;
                }
            }
            if(!ok){
                lft.push_back(i);
            }
        }
        for(auto i:arr1){
            bool ok = false;
            for(auto j:ans){
                if(i==j)ok = true;
            }
            if(!ok)lft.push_back(i);
        }
        sort(lft.begin(), lft.end());
        for(auto i:lft){
            ans.push_back(i);
        }
        return ans;
        
    }
};