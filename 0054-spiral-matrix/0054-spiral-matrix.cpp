class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int>spiral;
        int top_row = 0;
        int last_col = n-1;
        int bottom_row = m-1;
        int first_col = 0;
        while(top_row < bottom_row && first_col < last_col)
        {
            for(int i=first_col; i<=last_col; i++) 
                spiral.push_back(matrix[top_row][i]);
            top_row ++; 
           
            for(int i=top_row; i<=bottom_row; i++)
                spiral.push_back(matrix[i][last_col]);
            last_col --;
            
            for(int i=last_col; i>=first_col; i--)
                spiral.push_back(matrix[bottom_row][i]);
            bottom_row--;
            
            for(int i=bottom_row; i>=top_row; i--)
                spiral.push_back(matrix[i][first_col]);
            first_col ++; 

        }

        if(top_row == bottom_row && first_col <= last_col) {
            for(int i=first_col; i<=last_col; i++)
            spiral.push_back(matrix[top_row][i]);
        }

        else if(first_col == last_col && top_row <= bottom_row) {
            for(int i=top_row; i<=bottom_row; i++)
                spiral.push_back(matrix[i][first_col]);
        }
        return spiral;
    }
};