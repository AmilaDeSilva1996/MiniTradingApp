
#include "engine.h"
#include "OrderBookManager.h"
#include <iostream>

int main() {
    // engine eng;
    // eng.startServer();
    OrderBookManager orderBookManager;

    // Simulate adding some orders (order creation)
    Order order1("user1", "orderID1", 1, 50000.0, "BTC/USD", "limit", "2023-03-01 12:00:00", Order::Side::BUY);
    Order order2("user2", "orderID2", 1, 51000.0, "BTC/USD", "limit", "2023-03-01 12:01:00", Order::Side::SELL);
    Order order3("user3", "orderID3", 100, 150.0, "AAPL", "limit", "2023-03-01 12:02:00", Order::Side::BUY);
    Order order4("user4", "orderID4", 50, 155.0, "AAPL", "limit", "2023-03-01 12:03:00", Order::Side::SELL);
    Order order5("user5", "orderID5", 1, 50000.0, "BTC/USD", "limit", "2023-03-01 12:00:00", Order::Side::SELL);
    Order order6("user6", "orderID6", 1, 51000.0, "BTC/USD", "limit", "2023-03-01 12:01:00", Order::Side::BUY);
    Order order7("user7", "orderID7", 100, 150.0, "AAPL", "limit", "2023-03-01 12:02:00", Order::Side::SELL);
    Order order8("user8", "orderID8", 50, 155.0, "AAPL", "limit", "2023-03-01 12:03:00", Order::Side::BUY);


    // Add orders to the order book through the OrderBookManager
    orderBookManager.addOrder(order1); // Buy order for BTC/USD
    orderBookManager.addOrder(order2); // Sell order for BTC/USD
    orderBookManager.addOrder(order3); // Buy order for AAPL
    orderBookManager.addOrder(order4); // Sell order for AAPL
    orderBookManager.addOrder(order5); // Buy order for BTC/USD
    orderBookManager.addOrder(order6); // Sell order for BTC/USD
    orderBookManager.addOrder(order7); // Buy order for AAPL
    orderBookManager.addOrder(order8); // Sell order for AAPL

    // Display orders for BTC/USD symbol to verify matching and trades (if any)
    std::cout << "Orders for BTC/USD:" << std::endl;
    orderBookManager.printOrderBook("BTC/USD");

    // Display orders for AAPL symbol
    std::cout << "\nOrders for AAPL:" << std::endl;
    orderBookManager.printOrderBook("AAPL");
    return 0;
}
