#pragma once
#include <string>
#include <iostream>

class Order
{
private:
    
    std::string userID;
    std::string orderID;
    int quantity;
    double price;
    std::string symbol;
    std::string orderType;
    std::string placedTime;

public:
    enum class Side {BUY, SELL};
    Side side;
    Order();

    Order(const std::string& userID, const std::string& orderID, int quantity, double price, const std::string& symbol, const std::string& orderType, const std::string& placedTime, Side side) : userID(userID), orderID(orderID), quantity(quantity), price(price), symbol(symbol), orderType(orderType), placedTime(placedTime), side(side){}
    virtual ~Order();
    
    std::string getUserID() const;
    std::string getOrderID() const;
    int getQuantity() const;
    double getPrice() const;
    std::string getSymbol() const;
    std::string getOrderType() const;
    std::string getPlacedTime() const;
    Side getSide()const;
    
    void setUserID(const std::string& userID);
    void setOrderID(const std::string& orderID);
    void setQuantity(int quantity);
    void setPrice(double price);
    void setSymbol(const std::string& symbol);
    void setOrderType(const std::string& orderType);
    void setPlacedTime(const std::string& placedTime);
    void setSide(Side& side);

};