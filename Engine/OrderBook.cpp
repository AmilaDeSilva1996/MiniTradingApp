#include "OrderBook.h"
#include <algorithm>
using namespace std;

// OrderBook::OrderBook()
// {

// }

// OrderBook::~OrderBook()
// {

// }
void OrderBook::matchOrders()
{
    // Match buy orders with sell orders
    std::cout<<"Matching orders\n";
    for (auto buyIt = buy_orders.rbegin(); buyIt != buy_orders.rend(); ++buyIt) {
        for (auto sellIt = sell_orders.begin(); sellIt != sell_orders.end(); ++sellIt) {
            if (buyIt->first >= sellIt->first) {  // If buy price >= sell price
                // Check the quantity match
                while (!buyIt->second.empty() && !sellIt->second.empty()) {
                    Order& buyOrder = buyIt->second.back();
                    Order& sellOrder = sellIt->second.back();

                    int matchedQuantity = std::min(buyOrder.getQuantity(), sellOrder.getQuantity());

                    // Execute the trade (assuming trade happens at the sell price)
                    std::cout << "Executing trade: " 
                              << matchedQuantity << " units at price: " 
                              << sellOrder.getPrice() << std::endl;

                    // Update quantities of the matched orders
                    buyOrder.setQuantity(buyOrder.getQuantity() - matchedQuantity);
                    sellOrder.setQuantity(sellOrder.getQuantity() - matchedQuantity);

                    // If the buy order is fully filled, remove it
                    if (buyOrder.getQuantity() == 0) {
                        buyIt->second.pop_back();
                    }

                    // If the sell order is fully filled, remove it
                    if (sellOrder.getQuantity() == 0) {
                        sellIt->second.pop_back();
                    }

                    // If both orders are fully matched, stop further matching
                    if (buyIt->second.empty() || sellIt->second.empty()) {
                        break;
                    }
                }
            }
        }
    }
}

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
    matchOrders();
}

void OrderBook::deleteOrder(const std::string& orderID)
{
	for(auto it = buy_orders.begin(); it!= buy_orders.end(); it++)
    {
        auto& orders = it->second;

        orders.erase(std::remove_if(orders.begin(), orders.end(),[orderID](const Order& order) {return order.getOrderID() == orderID;}), orders.end());
    }
	
}
void OrderBook::printOrders(const std::string& symbol)
{
    std::cout << "Buy Orders for " << symbol << ":\n";
    for(const auto& order : buy_orders)
    {
        for(const Order& o : order.second)
        {
            std::cout << "Order ID: " << o.getOrderID() 
                      << ", Price: " << o.getPrice()
                      << ", Quantity: " << o.getQuantity() << std::endl;
        }
    }

    std::cout << "Sell Orders for " << symbol << ":\n";
    for (const auto& order : sell_orders)
    {
        for(const Order& o : order.second)
        {
            std::cout << "Order ID: " << o.getOrderID() 
                      << ", Price: " << o.getPrice()
                      << ", Quantity: " << o.getQuantity() << std::endl;
        }
    }
    
}

