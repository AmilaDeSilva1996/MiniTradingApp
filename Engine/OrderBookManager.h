#pragma once
#include <unordered_map>
#include "OrderBook.h"

class OrderBookManager
{
private:
    std::unordered_map<std::string, OrderBook> order_books;

public:
    void addOrder(const Order& order);
    void deleteOrder(const std::string& orderID, const std::string& symbol);
    void printOrderBook(const std::string& symbol);



};
