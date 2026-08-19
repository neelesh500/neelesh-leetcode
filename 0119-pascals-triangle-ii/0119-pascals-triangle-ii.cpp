class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); 
        long long current_val = 1; 
        for (int i = 1; i < rowIndex; i++) {
            current_val = current_val * (rowIndex - i + 1) / i;
            row[i] = current_val;
        }
        
        return row;
    }
};