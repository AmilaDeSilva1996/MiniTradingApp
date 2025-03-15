#include "OrderBookManager.h"

void OrderBookManager::addOrder(const Order& order)
{
    order_books[order.getSymbol()].addOrder(order);
}

void OrderBookManager::deleteOrder(const std::string& orderID, const std::string& symbol)
{
    if(order_books.find(symbol) != order_books.end())
    {
        order_books[symbol].deleteOrder(orderID);
    }
    else{
        throw std::runtime_error("OrderBookManager::deleteOrder: OrderBook not found for symbol: " + symbol);
    }
}

void OrderBookManager::printOrderBook(const std::string& symbol)
{
    if(order_books.find(symbol) != order_books.end())
    {
        order_books[symbol].printOrders(symbol);
    }
    else{
        throw std::runtime_error("OrderBookManager::printOrderBook: OrderBook not found for symbol: " + symbol);
    }
}


