#include <stdio.h>
#include "stock.h"

int main(void)
{
    printf("Stock Monitor starting...\n\n");

    Stock aaple = create_stock("AAPL", 273.35, 0.54);
    Stock tsla = create_stock("TSLA", 481.20, -0.45);

    print_stock(&aaple);
    print_stock(&tsla);

    return 0;
}
