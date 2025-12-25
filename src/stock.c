#include <stdio.h>
#include "stock.h"
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>

Stock create_stock(const char *ticker, double price, double change)
{
    Stock s;
    strncpy(s.ticker, ticker, sizeof(s.ticker) - 1);
    s.ticker[sizeof(s.ticker) - 1] = '\0';
    s.price = price;
    s.change = change;
    return s;
}

void print_stock(const Stock *s)
{
    // printf("%s: $%.2f (%.2f%%)\n", s->ticker, s->price, s->change);
    printf("%s: $%.2f (%.2f%%)\n", s->ticker, s->price, s->change);
}

// CURL write callback
struct Memory
{
    char *data;
    size_t size;
};
