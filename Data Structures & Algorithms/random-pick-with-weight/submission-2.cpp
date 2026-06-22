class Solution {
public:
    vector<int> w;
    int total = 0;

    Solution(vector<int>& w) {
        this->w = w;
        for (int weight : w) {
            total += weight;
        }
    }

    int pickIndex() {
        double target = total * ((double) rand() / RAND_MAX);
        int curSum = 0;
        for (int i = 0; i < w.size(); i++) {
            curSum += w[i];
            if (curSum > target) {
                return i;
            }
        }
        return -1;
    }
};