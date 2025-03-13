#include "OrderBook.h"
#include <algorithm>
using namespace std;

// OrderBook::OrderBook()
// {

// }

// OrderBook::~OrderBook()
// {

// }

void OrderBook::addOrder(const Order& order)
{
    if(order.getSide() == Order::Side::BUY)
    {
        buy_orders[order.getPrice()].push_back(order);
    }
    else
    {
        sell_orders[order.getPrice()].push_back(order);
    }
}

void OrderBook::deleteOrder(const std::string& orderID)
{
	for(auto it = buy_orders.begin(); it!= buy_orders.end(); it++)
    {
        auto& orders = it->second;

        orders.erase(std::remove_if(orders.begin(), orders.end(),[orderID](const Order& order) {return order.getOrderID() == orderID;}), orders.end());
    }
	
}

