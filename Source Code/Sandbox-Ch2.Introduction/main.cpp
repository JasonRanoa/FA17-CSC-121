/*
 * This project contains all Chapter 2 related code.
 * For reference, listed below are all the classes grouped by activity.
 *
 *      -   Page 74. Qn. 4.
 *          Compute the tax and tip on a restaurant bill for a patron
 *          Classes:    RsBillCalculator
 *
 *      -   Page 74. Qn. 8
 *          Compute the number of square feet and square meters in
 *          a given measure of acres
 *          Classes:    AcreConverter
 *
 *      -   Page 74. Qn. 9
 *          Given cost of production, find selling price needed to
 *          make a given percent of profits.
 *          Classes:    SellingPriceFinder
 */

#include "RsBillCalculator.h"
#include "AcreConverter.h"
#include "SellingPriceFinder.h"

int main() {
    // RsBillCalculator r;
    // r.run();

    // AcreConverter a;
    // a.run();

    SellingPriceFinder p;
    p.run();

    return 0;
}