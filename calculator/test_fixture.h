#ifndef TESTFIXTURE_H
#define TESTFIXTURE_H

#include <iostream>

template <typename N>
class TestFixture {
public:
    TestFixture();
    void start();
    void test(N result, N expected);
    void finish();
private:
    int test_index = 1;
    int tests_failed = 0;
};

template <typename N>
TestFixture<N>::TestFixture()
{

}

template <typename N>
void TestFixture<N>::start()
{
    std::cout << "Running tests..." << std::endl;
}

template <typename N>
void TestFixture<N>::test(N result, N expected)
{
    std::cout << "[" << test_index++ << "] ";

    if (result == expected) {
        std::cout << "✅";
    } else {
        std::cout << "❌ (" << expected << " != " << result << ")";
        tests_failed++;
    }

    std::cout << std::endl;
}

template <typename N>
void TestFixture<N>::finish()
{
    if (tests_failed > 0) {
        std::cout << tests_failed << " test" << (tests_failed == 1 ? "" : "s") << " failed.";
    } else {
        std::cout << "All tests passed.";
    }

    std::cout << std::endl;
}

#endif // TESTFIXTURE_H
