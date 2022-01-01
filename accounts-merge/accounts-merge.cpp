class Solution {
public:
    class Account {
      public:
        Account (const std::string& name, const std::string& email) :
            name(name), email(email) {
            // parent_ = his;
        }
        Account* Root()  {
            Account* root = this;
            while (root->parent_ != nullptr) {
                root = root->parent_;
            }
            return root;
        }
        void Merge(Account* account) {
            Account* account_root = account->Root();
            Account* my_root = Root();
            if (account_root == my_root) {
                return;
            }
            account_root->parent_ = my_root;
        }
        
        std::string name;
        std::string email;
        
     private:
        Account* parent_ = nullptr;
    };
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        std::unordered_map<std::string, Account> accounts_pool;
        
        for (const auto& entry : accounts) {
            for (int i = 1; i < entry.size(); i++) {
                const std::string& email = entry[i];
                if (accounts_pool.count(email) != 0) {
                    continue;
                }
                accounts_pool.emplace(email, Account(entry[0], email));
            }
        }  
        
        for (const auto& entry: accounts) {
            Account* master = nullptr;
            for (int i = 1; i < entry.size(); i++) {
                const std::string& email = entry[i];
                if (i == 1) {
                    master = &accounts_pool.at(email);
                } else {
                    master->Merge(&accounts_pool.at(email));
                }
            }
        }
        
        
        std::unordered_map<Account*, std::vector<Account*>> unique_accounts;
        for ( auto& it : accounts_pool) {
            unique_accounts[it.second.Root()].push_back(&(it.second));
        }
        
        std::vector<std::vector<std::string>> output;
        for (auto& it : unique_accounts) {
            std::vector<std::string> entry;
            entry.push_back(it.first->name);
            for (const Account* account : it.second) {
                entry.push_back(account->email);
            }
            std::sort(entry.begin() + 1, entry.end());
            output.push_back(std::move(entry));
        }
        return output;
            
    }
};