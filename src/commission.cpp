#include <stdexcept>

double calculateCommission(int locks, int stocks, int barrels)
{
    const double lockPrice = 45.0;
    const double stockPrice = 30.0;
    const double barrelPrice = 25.0;
    int totalLocks = 0;
    int totalStocks = 0;
    int totalBarrels = 0;

    // Validation of inputs
    if (locks < 0 || stocks < 0 || barrels < 0)
    {
        throw std::invalid_argument("Negative values are not allowed");
    }

    totalLocks += locks;
    totalStocks += stocks;
    totalBarrels += barrels;

    double lockSales = lockPrice * totalLocks;
    double stockSales = stockPrice * totalStocks;
    double barrelSales = barrelPrice * totalBarrels;
    double sales = lockSales + stockSales + barrelSales;
    double commission;

    if (sales > 1800.0)
    {
        commission = 0.10 * 1000.0;
        commission += 0.15 * 800.0;
        commission += 0.20 * (sales - 1800.0);
    }
    else if (sales > 1000.0)
    {
        commission = 0.10 * 1000.0;
        commission += 0.15 * (sales - 1000.0);
    }
    else
    {
        commission = 0.10 * sales;
    }

    return commission;
}
