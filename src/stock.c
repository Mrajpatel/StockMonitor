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

/*  ptr:
        pointer to the incoming data from libcurl (chunk of HTML).
    size and nmemb:
        size of a single element and number of elements (total bytes = size * nmemb).
    userp:
        user pointer we passed to libcurl (we use it to pass our Memory struct).
*/
static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userp)
{
    size_t total = size * nmemb;
    struct Memory *mem = (struct Memory *)userp;

    char *temp = realloc(mem->data, mem->size + total + 1);
    if (!temp)
        return 0;

    mem->data = temp;
    memcpy(&(mem->data[mem->size]), ptr, total);
    mem->size += total;
    mem->data[mem->size] = 0;

    return total;
}

// Fetch price from Yahoo Finance
int fetch_stock_price(Stock *s)
{
    return 0;
}