#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../main.h"

static int failures = 0;

static void assert_string_equal(const char* name, const char* actual, const char* expected)
{
    if (strcmp(actual, expected) != 0) {
        fprintf(stderr, "FAIL: %s\n  expected: %s\n  actual:   %s\n", name, expected, actual);
        failures++;
    }
}

static void assert_int_equal(const char* name, int actual, int expected)
{
    if (actual != expected) {
        fprintf(stderr, "FAIL: %s\n  expected: %d\n  actual:   %d\n", name, expected, actual);
        failures++;
    }
}

static void test_dec_to_bin(void)
{
    char* result = DecToBin(0);
    assert_string_equal("DecToBin handles zero", result, "00000000");
    free(result);

    result = DecToBin(5);
    assert_string_equal("DecToBin pads small numbers to one octet", result, "00000101");
    free(result);

    result = DecToBin(255);
    assert_string_equal("DecToBin keeps full octet values", result, "11111111");
    free(result);

    result = DecToBin(256);
    assert_string_equal("DecToBin inserts spaces between octets", result, "00000001 00000000");
    free(result);

    result = DecToBin(INT_MAX);
    assert_string_equal(
        "DecToBin handles max signed 32-bit integer",
        result,
        "01111111 11111111 11111111 11111111"
    );
    free(result);
}

static void test_bin_to_dec(void)
{
    assert_int_equal("BinToDec handles zero", BinToDec("0"), 0);
    assert_int_equal("BinToDec handles a simple value", BinToDec("101"), 5);
    assert_int_equal("BinToDec handles spaced octets", BinToDec("00000001 00000000"), 256);
    assert_int_equal("BinToDec ignores non-binary separators", BinToDec("1010-1010"), 170);
    assert_int_equal(
        "BinToDec handles max signed 32-bit binary",
        BinToDec("1111111111111111111111111111111"),
        INT_MAX
    );
}

int main(void)
{
    test_dec_to_bin();
    test_bin_to_dec();

    if (failures > 0) {
        fprintf(stderr, "\n%d test(s) failed.\n", failures);
        return 1;
    }

    printf("All converter tests passed.\n");
    return 0;
}
