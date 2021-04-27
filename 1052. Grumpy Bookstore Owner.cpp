class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int s = 0, additional = 0, maxadditional = 0;
        
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i]) {
                additional += customers[i];
            } else {
                s += customers[i];
            }
            
            if (i >= X && grumpy[i-X]) {
                additional -= customers[i-X];
            }
            
            maxadditional = std::max(additional, maxadditional);
        }
        
        return s+maxadditional;
    }
};
