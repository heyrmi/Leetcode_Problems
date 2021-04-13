class Solution{
public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> res;                             //result vector
        vector<string> nQueens(n, string(n,'.'));               //init all values of nQueen by .
        solveIt(res, nQueens, 0, n);                            //solveIt
        return res.size();                                             //this time return size of res
    }

    void solveIt(vector<vector<string>> &res, vector<string> &nQueens, int row, int &n){
        if(row == n){                                           //if final row is reached
            res.push_back(nQueens);                             //push the sequence of the queens in res
            return;                                             //return to main
        }

        for(int col = 0; col < n; col++){                       //traverse on each column
            if(isValid(nQueens, row, col, n)){                  //check if the given position is valid or not
                nQueens[row][col] = 'Q';                        //if valid put Q at given row and col 
                solveIt(res, nQueens, row+1, n);                //repeat for the next row
                nQueens[row][col] = '.';                        //fill up the rest with .
            }
        }
    }

    bool isValid(vector<string> &nQueens, int row, int col, int &n){
        for(int i = 0; i < row; i++)                            //check if the column had the queen before
            if(nQueens[i][col] == 'Q')
                return false;

        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)   //check if diagonal 45* has queen         
            if(nQueens[i][j] == 'Q')
                return false;
        
        for(int i = row-1, j = col+1; i>=0 && j>=0; i--, j++)   //check if diagonal 135* has queen 
            if(nQueens[i][j] == 'Q')
                return false;

        return true;                                            
    }

};