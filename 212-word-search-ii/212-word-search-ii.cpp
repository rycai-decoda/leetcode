
struct TrieNode {
    TrieNode() {} 
    std::unordered_map<char, TrieNode*> children;
    std::string word;
};

class Trie {
public:
    Trie() {}
    void Insert(const string& word) {
        TrieNode* node = &root_;

        for (auto c : word) {
            if (!node->children.count(c)) {
                nodes_.emplace_back();
                node->children[c] = &nodes_.back();
            }
            node = node->children[c];
        }

        node->word = word;
    }
    TrieNode* root() {return &root_;}
    
private:
    std::list<TrieNode> nodes_;
    TrieNode root_;
};



class Solution {
public:
    

    // Returns true iff finds a word.
    void DfsWords(const vector<vector<char>>& board, int y, int x, vector<vector<bool>>* visited, TrieNode* root, std::set<string>* unique_words) {
        
        const static std::vector<std::vector<int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        if (y < 0 || y >= board.size() || x < 0 || x >= board[y].size()) {
            return;
        }
        
        if ((*visited)[y][x]) {
            return;
        }

        char c = board[y][x];   
     
        // Not found.
        if (root->children.count(c) == 0) {
            return;
        }

        TrieNode* child = root->children[c];
        
        // Finds a valid word.
        if (child->word.size() > 0) {
            unique_words->insert(child->word);
            
            // Invalidates the word, to avoid duplicate
            child->word = "";
        }
        
        if (!child->children.empty()) {
            (*visited)[y][x] = true;
            for (const auto& dir : dirs) {
                int next_y = y + dir[0];
                int next_x = x + dir[1];
                
                DfsWords(board, next_y, next_x, visited, child, unique_words);
   
            }
            (*visited)[y][x] = false;
        }
 
        
        return;      
    }

    vector<string> findWords(const vector<vector<char>> & board, vector<string> & words) {
        Trie trie;
        std::set<string> unique_words;
        

        for (const auto & word: words) {
            trie.Insert(word);
        }
        for (int y = 0; y < board.size(); y++) {
            vector<vector<bool>> visited(board.size(), std::vector<bool>(board[y].size(), false));
            for(int x = 0; x < board[0].size(); x++) {
                DfsWords(board, y, x, &visited, trie.root(), &unique_words);
            }
        }        
        std::vector<std::string> output({unique_words.begin(), unique_words.end()});
   
        
        return output;        
    }
};
