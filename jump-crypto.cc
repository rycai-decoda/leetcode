#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <unordered_set>


int urls(const std::string& str) {
    const static std::string kHttp("http");
    const static std::string kCom("com");
    
    if (str.find(kHttp) != 0) {
        return 0;
    }
    
    std::string_view uri_view(str.data() + kHttp.size());
    int http_num = 0;
    int https_num = 0;
    size_t pos = uri_view.find(kCom);
    while (pos != std::string_view::npos) {
        if (pos > 0) {
            http_num++;
        }
        if (pos > 1 && uri_view[0] == 's') {
            https_num++;
        }
        
        pos = uri_view.find(kCom, pos + kCom.size());
    }
    
    return http_num + https_num;
}

bool is_proud(char c) {
    const static std::unordered_set kProud({'m', 'i', 'k'});
    return kProud.count(c) != 0;
}

bool humble_string(const std::string& letter, int start, int* max_window, int* proud_chars) {
    int from = start + *max_window - 1;
    int current_proud = *proud_chars;
    bool found = false;
    
    for (int i = from; i < letter.size(); i++) {
        current_proud += is_proud(letter[i]);
        if (i == from) {
            *proud_chars = current_proud;
        }

        int window = i - start + 1;
        
        // is humble
        if (current_proud <= 2 * (window - current_proud)) {
            *max_window = window;
            *proud_chars = current_proud;
            found = true;
        }
    }
    
    return found;
}

std::string humble_string(const std::string& letter) {
    const static std::string kProudResponse("Very proud");
    if (letter.empty()) {
        return kProudResponse;
    }
    std::vector<int> humble_length;
    int start = 0;
    int max_window = 1;
    int proud_chars = 0;
    for (int start = 0; start + max_window <= letter.size(); start++) {
        
        bool found = humble_string(letter, start, &max_window, &proud_chars);
        if (found) {
            humble_length.push_back(max_window);
        }
        proud_chars -= is_proud(letter[start]);
    }
    
    if (humble_length.empty()) {
        return kProudResponse;
    }
    int num = 0;
    for (int i : humble_length) {
        num += (i == max_window);
    }
    return std::to_string(max_window) + " " + std::to_string(num);
}

int main() {
    std::vector<std::string> testcases({
        "mik", 
        "mmaamik",
        "aamikfffff"
        });
    for (const std::string& str : testcases) {
        std::cout << "str  " << str << "\nres " << humble_string(str) << std::endl;
    }
    return 0;
}

// int main() {
//     std::vector<std::string> url_testcases({
//         "httpscom", 
//         "httpacom",
//         "httpcom",
//         "ddd",
//         "httpsasdcomgdgcom",
//         });
//     for (const std::string& str : url_testcases) {
//         std::cout << "str  " << str << "\nres " << urls(str) << std::endl;
//     }
//     return 0;
// }
