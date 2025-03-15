#pragma once
#include <string>
#include <map>
#include <vector>
#include "Order.h"


class OrderBook 
{
public:
	// OrderBook();
	// virtual ~OrderBook();
	void matchOrders();
	void printOrders(const std::string& symbol);
	void addOrder(const Order& order);
	void deleteOrder(const std::string& orderID);
	void updateOrder(const std::string& orderID);
	
private:
	std::map<double,std::vector<Order>> buy_orders;
	std::map<double, std::vector<Order>> sell_orders;
};
