#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string_view>

std::vector<std::string_view> Split(const std::string& str, char delimiter) {
    std::vector<std::string_view> splits;
    
    for (size_t i = 0; i < str.size();) {
        if (str[i] == delimiter) {
            i++;
            continue;
        }
        
        // Not delimiter
        size_t end = std::min(str.size(), str.find(delimiter, i));
        splits.push_back(std::string_view(str.data() + i, end - i));
        i = end;
    }
    return splits;
}

constexpr char kLimit[] = "limit";
constexpr char kMarket[] = "market";
constexpr char kStop[] = "stop";
constexpr char kCancel[] = "cancel";
constexpr char kBuy[] = "buy";
constexpr char kSell[] = "sell";


class Exchange {
public:
    enum Side {
        BUY = 1,
        SELL = 2,
    };
    struct Order {
        int price;
        int quantity;
        Side side;
        long id;
    };
    void Market(const Order& order) {
        Order copy(order);
        if (order.side == BUY) {
            copy.price = INT_MAX;
        }
        if (order.side == SELL) {
            copy.price = INT_MIN;
        }
        Limit(copy);
    }
    void Limit(const Order& order) {
        if (order.side == BUY) {       
            buy_heap_.push_back(order);
            std::make_heap(buy_heap_.begin(), buy_heap_.end(), BuyHeapComp);
        }
        if (order.side == SELL) {
            sell_heap_.push_back(order);
            std::make_heap(sell_heap_.begin(), sell_heap_.end(), SellHeapComp);
        }
        // Match orders
        while (!buy_heap_.empty() && !sell_heap_.empty() &&
                buy_heap_.front().price >= sell_heap_.front().price) {
                Order& buy = buy_heap_.front();
                Order& sell = sell_heap_.front();
                
                int q = std::min(buy.quantity, sell.quantity);
                buy.quantity -= q;
                sell.quantity -= q;
                std::cout << "id " << buy.id << " id " << sell.id
                          << " quantity " << q << std::endl;
                
                if (buy.quantity == 0) {
                    std::pop_heap(buy_heap_.begin(), buy_heap_.end(), BuyHeapComp);
                    buy_heap_.pop_back();
                }
                if (sell.quantity == 0) {
                    std::pop_heap(sell_heap_.begin(), sell_heap_.end(), SellHeapComp);
                    sell_heap_.pop_back();
                }
                
                // for (const auto& o : buy_heap_) {
                //     std::cout << "p" << o.price << "q" << o.quantity << std::endl;
                // }
                // for (const auto& o : sell_heap_) {
                //     std::cout << "p" << o.price << "q" << o.quantity << std::endl;
                // }
            }
    }
private:

    static bool BuyHeapComp(const Order& o1, const Order& o2) {
        if (o1.price == o2.price) {
            return o1.id > o2.id;
        }
        return o1.price < o2.price;
    };
    static bool SellHeapComp(const Order& o1, const Order& o2) {
        if (o1.price == o2.price) {
            return o1.id > o2.id;
        }
        return o1.price > o2.price;
    };
    // Min heap sorted by sell price
    std::vector<Order> sell_heap_;
    
    // Max heap sorted by buy price
    std::vector<Order> buy_heap_;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    Exchange ex;
    std::string line;
    for (size_t i = 0; std::getline(std::cin, line); i++) {
        const auto& splits = Split(line, ' ');
        if (splits.size() < 4) {
            throw std::runtime_error("invalid input " + line);
        }
        
        std::string_view type = splits[0];
        
        Exchange::Order order;
        order.id = i;
        order.price = std::stoi(std::string(splits[2]));
        order.quantity = std::stoi(std::string(splits[3]));
        
        std::string_view side = splits[1];
        if (side == kBuy) {
            order.side = Exchange::BUY;  
        } else if (side == kSell) {
            order.side = Exchange::SELL;
        } else {
            throw std::runtime_error("invalid side " + std::string(side));
        }
        
        if (type == kLimit) {
            ex.Limit(order);
        } else if (type == kMarket) {
            ex.Market(order);
        } else {
            throw std::runtime_error("unknow type " + std::string(type));
        }
    }
    
    return 0;
}
