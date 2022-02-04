#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string_view>
#include <unordered_map>

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> splits;
    
    for (size_t i = 0; i < str.size();) {
        if (str[i] == delimiter) {
            i++;
            continue;
        }
        
        // Not delimiter
        size_t end = std::min(str.size(), str.find(delimiter, i));
        splits.push_back(str.substr(i, end - i));
        i = end;
    }
    return splits;
}

constexpr char kLimit[] = "limit";

void CountWords(const std::string& str, std::unordered_map<std::string, int>* count) {
    for (size_t i = 0; i < str.size();) {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        
        // Not delimiter
        size_t end = std::min(str.size(), str.find(' ', i));
        (*count)[str.substr(i, end - i)]++;
        i = end;
    }
}

struct Matched {
    uint id;
    int count;
};

void PrintMatches(std::vector<Matched>& matches) {
    std::sort(matches.begin(), matches.end(), [](const Matched& m1, const Matched& m2) {
       if (m1.count == m2.count) {
           return m1.id < m2.id;
       } 
       return m1.count > m2.count;
    });
    
    for (const auto& m : matches) {
        std::cout << m.id << " ";
    }
    std::cout << std::endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    std::string line;
    std::getline(std::cin, line);
    int documents_count = std::stoi(line);
    std::vector<std::string> documents(documents_count);
    std::vector<std::unordered_map<std::string, int>> word_count(documents_count);
    
    for (uint i = 0; i < documents_count; i++) {
        std::getline(std::cin, documents[i]);
        // documents[i] = line;
        CountWords(documents[i], &word_count[i]);
    }
    
    std::getline(std::cin, line);
    int query_count = std::stoi(line);
    
    for (uint n = 0; n < query_count; n++) {
        std::getline(std::cin, line);
        std::vector<std::string> splits = Split(line, ' ');
        std::vector<Matched> matches;
        if (splits.size() == 1) {
            std::string query = splits[0];
            for (uint i = 0; i < word_count.size(); i++) {
                if (word_count[i].count(query) == 0) {
                    continue;
                }
                Matched match;
                match.id = i;
                match.count = word_count[i][query];
                matches.push_back(match);
            }
            PrintMatches(matches);
            continue;    
        }
        for (uint i = 0; i < word_count.size(); i++) {
            std::string query1 = splits[0];
            std::string query2 = splits[2];
            if (splits[1] == "&") {
                
                
                if (word_count[i].count(query1) == 0 || word_count[i].count(query2) == 0) {
                    continue;
                }
            
            } else {
                if (word_count[i].count(query1) == 0 && word_count[i].count(query2) == 0) {
                    continue;
                }
            }
        
            int count1 = word_count[i].count(query1) ? word_count[i].at(query1) : 0;
            int count2 = word_count[i].count(query2) ? word_count[i].at(query2) : 0;
        
            Matched match;
            match.id = i;
            match.count = count1 + count2;
            matches.push_back(match);
        } 
        PrintMatches(matches);
    }
    
    return 0;
}
