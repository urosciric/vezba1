#include "pch.h"
#include "parser3000.h"
#include "parser_helpers.h"

using namespace parser;

void test_bit_options(test_context& ctx);
void test_int_options(test_context& ctx);
void test_uint_options(test_context& ctx);
void test_float_options(test_context& ctx);
void test_string_options(test_context& ctx);
void test_combined_options(test_context& ctx);

int main()
{
    std::cout << "Testing parser30000\r\n" 
        << "=======================\r\n";

    test_context ctx;

    test_bit_options(ctx);
    test_int_options(ctx);
    test_uint_options(ctx);
    test_float_options(ctx);
    test_string_options(ctx);
    test_combined_options(ctx);

    std::cout << "Testing done.\r\n";
    std::cout << "Total tests: " << ctx.tests << "\r\n";
    if (ctx.errors == 0)
        std::cout << OK_TEXT "\r\n";
    else
        std::cout << ERROR_TEXT "Errors count: " << ctx.errors << "\r\n";
}

