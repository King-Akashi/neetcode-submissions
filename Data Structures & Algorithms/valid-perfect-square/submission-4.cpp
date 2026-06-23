class Solution {
public:
    bool isPerfectSquare(int num) {
        // lets write binary search
        long long i = 0;
        long long j = 1e9;
        bool ans = false;
        while(i<=j){
            long long mid = j-(j-i)/2;
            cout << mid << endl;
            if(mid*mid>num){
                j = mid-1;
            }
            else if(mid*mid<num){
                i = mid+1;
            }
            else{
                ans = true;
                break;
            }
        }
        return ans;
    }
};