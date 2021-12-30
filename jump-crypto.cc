#include <iostream>
#include <string_view>
#include <string>
#include <vector>


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

int main() {
    std::vector<std::string> url_testcases({
        "httpscom", 
        "httpacom",
        "httpcom",
        "ddd",
        "httpsasdcomgdgcom",
        });
    for (const std::string& str : url_testcases) {
        std::cout << "str  " << str << "\nres " << urls(str) << std::endl;
    }
    return 0;
}
