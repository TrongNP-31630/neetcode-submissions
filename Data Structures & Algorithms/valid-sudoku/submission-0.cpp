class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,int> mprow[9];
        map<int,int> mpcol[9];
        
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
        {
            if (isdigit(board[i][j]))
            {
                char x = board[i][j];
                mprow[i][x-'0']++;
                mpcol[j][x-'0']++;
                if (mprow[i][x-'0'] >1 || mpcol[j][x-'0']>1) return false;
            }
        }
        
        for (int i=1;i<9;i+=3)
            for (int j=1;j<9;j+=3)
        {
            map<int,int> mp;
            for (int u=i-1;u<=i+1;u++)
                for (int o=j-1;o<=j+1;o++)
            {
                if (isdigit(board[u][o]))
                {
                    char x = board[u][o];
                    mp[x-'0'] ++;
                    if (mp[x-'0'] >1) return false;
                }
            }
        }
        return true;
    }
};
