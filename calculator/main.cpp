#include <iostream>
#include <cassert>

#include "calculator.h"
#include "test_fixture.h"

using namespace std;

int main()
{
    TestFixture<int> fixture;
    Calculator<int> calculator;

    fixture.start();

    fixture.test(calculator.parse("5+5"), 10);
    fixture.test(calculator.parse("5-5"), 0);
    fixture.test(calculator.parse("5*5"), 25);
    fixture.test(calculator.parse("5/5"), 1);
    fixture.test(calculator.parse("5*5+1"), 26);
    fixture.test(calculator.parse("5*(5+1)"), 30);

    fixture.test(calculator.parse("5 * (5 + 1)"), 30);
    fixture.test(calculator.parse("     5"), 5);
    fixture.test(calculator.parse("   25*  5"), 125);

    fixture.finish();

    return 0;
}
