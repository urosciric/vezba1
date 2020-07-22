#include "pch.h"
#include "pch.h"
#include "parser_helpers.h"



void test_bit_short_options(test_context& ctx)
{

    bool option1 = false;
    bool option2 = false;
    bool option3 = false;

    parser3000 parser;

    parser.add_bit_option('a', &option1);
    parser.add_bit_option('b', &option2);
    parser.add_bit_option('c', &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = " -a -b -c";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || !option2 || !option3)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are true\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " -ac";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || option2 || !option3)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

}

void test_bit_long_options(test_context& ctx)
{
}


void test_bit_combined_options(test_context& ctx)
{

}

void test_bit_options(test_context& ctx)
{
    std::cout << "Testing bit options\r\n";

    test_bit_short_options(ctx);
    test_bit_long_options(ctx);
    test_bit_combined_options(ctx);

    std::cout << "Testing bit options done!!!\r\n";
}