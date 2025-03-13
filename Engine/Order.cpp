#include "Order.h"



Order::~Order()
{

}

void Order::setUserID(const std::string& userID)
{
    this->userID = userID;
}

void Order::setOrderID(const std::string& orderID)
{
    this->orderID = orderID;
}

void Order::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Order::setPrice(double price)
{
    this->price = price;
}

void Order::setSymbol(const std::string& symbol)
{
    this->symbol = symbol;
}

void Order:: setOrderType(const std::string& orderType)
{
    this->orderType = orderType;
}

void Order::setPlacedTime(const std::string& placedTime)
{
    this->placedTime = placedTime;
}

void Order::setSide(Side& side)
{
    this->side = side;
}
std::string Order::getUserID() const
{
    return userID;
}

std::string Order::getOrderID() const
{
    return orderID;
}

int Order:: getQuantity() const
{
    return quantity;
}

double Order::getPrice() const
{
    return price;
}

std::string Order::getSymbol() const
{
    return symbol;
}

std::string Order::getOrderType() const
{
    return orderType;
}

std::string Order::getPlacedTime() const
{
    return placedTime;
}

Order::Side Order:: getSide() const
{
    return side;
}
