class TicTacToe {
public:
    TicTacToe(int n) : n_(n) {
        
    }
    
    int move(int row, int col, int player) {
        if (board_.count(player) == 0) {
            Board b;
            std::vector<int> empty(n_, 0);
            b.rows = empty;
            b.cols = empty;
            b.diag1 = 0;
            b.diag2 = 0;
            board_[player] = std::move(b);
        }
        
        Board& b = board_[player];
        b.rows[row]++;
        if (b.rows[row] == n_) {
            return player;
        }
        b.cols[col]++;
        if (b.cols[col] == n_) {
            return player;
        }
        if (row == col) {
            b.diag1++;
            if (b.diag1 == n_) {
                return player;
            }
        }
        if (row == n_ - 1 - col) {
            b.diag2++;
            if (b.diag2 == n_) {
                return player;
            }
        }
        
        return 0;
    }
    
private:
    int n_;
    
    struct Board {
        std::vector<int> rows;
        std::vector<int> cols;
        int diag1;
        int diag2;
    };
    
    // rows_[player][row] is the # of marks placed by player on row.
    std::unordered_map<int, Board> board_;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */