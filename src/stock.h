// stock.h
#ifndef STOCK_H
#define STOCK_H

typedef struct
{
    /* data */
    char ticker[8];
    double price;
    double change;
} Stock;

// Create Stock
Stock create_stock(const char *ticker, double price, double change);

// Print Statement
void print_stock(const Stock *s);

// Fetch stock price from Yahoo Finance
int fetch_stock_price(Stock *s);

#endif