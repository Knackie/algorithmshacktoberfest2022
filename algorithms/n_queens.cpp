// driver function for N-queens

class Solution{
public:

    bool isSafe(vector<vector<int>> &board, int row, int col){
        for(int i=row-1, j = col; i>=0; i--){
            if(board[i][j] == 1){
                return false;
            }
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 1)
            return false;
        }
        
        for(int i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++){
            if(board[i][j] == 1)
            return false;
        }
        return true;
    }
    
    void solve(int row, vector<vector<int>> &ans, vector<vector<int>> &board, vector<int> &ds, int n){
        if(row == n){
            ans.push_back(ds);
            return;
        }
        for(int col=0; col<n; col++){
            if(isSafe(board, row, col)){
                board[row][col]= 1;
                ds.push_back(col+1);
                solve(row+1, ans, board, ds, n);
                board[row][col] = 0;
                ds.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int> (n,0));
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(0,ans,board,ds,n);
        return ans;
        
    }
};
