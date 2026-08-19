class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int maxGroups = n * 2; 
        int m = reservedSeats.size();
        int i = 0;
        
        while (i < m) {
            int currentRow = reservedSeats[i][0];
            bool leftBlocked = false;
            bool rightBlocked = false;
            bool middleBlocked = false;
            
            while (i < m && reservedSeats[i][0] == currentRow) {
                int seat = reservedSeats[i][1];
                
                if (seat >= 2 && seat <= 5) leftBlocked = true;
                if (seat >= 6 && seat <= 9) rightBlocked = true;
                if (seat >= 4 && seat <= 7) middleBlocked = true;
                
                i++;
            }
            
            maxGroups -= 2;
            if (!leftBlocked && !rightBlocked) {
                maxGroups += 2; 
            } else if (!leftBlocked || !rightBlocked || !middleBlocked) {
                maxGroups += 1; 
            }
        }
        
        return maxGroups;
    }
};