class Solution {
public:
    string simplifyPath(string path) {
        std::vector<std::string> paths;
        
        std::string directive;
        for (char c : path) {
            if (c == '/') {
                if (directive.empty()) {
                    continue;
                }
                
                if (directive == "..") {
                    if (!paths.empty()) {
                        paths.pop_back();
                    }
                    
                } else if (directive != ".") {
                    paths.push_back(directive);
                }
                directive.clear();
                continue;
            }
            
            directive.push_back(c);
        }
        
        if (!directive.empty()) {
            if (directive == "..") {
                if (!paths.empty()) {
                        paths.pop_back();
                    }
            } else if (directive != ".") {
                paths.push_back(directive);
            }
        }
        
        std::string canonical("/");
        for (const std::string& s : paths) {
            canonical += s;
            canonical += "/";
        }
        
        if (canonical.size() > 1) {
            canonical.erase(canonical.size() - 1);
        }
        return canonical;
    }
};