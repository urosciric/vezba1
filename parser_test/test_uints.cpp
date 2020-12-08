#include "pch.h"
#include "parser_helpers.h"
#include "test_common.h"

void test_uint_short_options(test_context& ctx)
{

    unsigned int option1 = 0;
    unsigned int option2 = 0;
    unsigned int option3 = 0;

    parser3000 parser;

    parser.add_uint_option('j', &option1);
    parser.add_uint_option('k', &option2);
    parser.add_uint_option('l', &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "-j 123 ";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 0 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "-j 123    -k 99";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 99 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "-j  ";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 0 || option2 != 0 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "-j 123 -l 55      -k 66";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 66 || option3 != 55)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
}

void test_uint_long_options(test_context& ctx)
{
    unsigned int option1 = 0;
    unsigned int option2 = 0;
    unsigned int option3 = 0;

    parser3000 parser;

    parser.add_uint_option("jj", &option1);
    parser.add_uint_option("kk", &option2);
    parser.add_uint_option("ll", &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "--jj 123 ";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 0 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--jj 123  --kk 32";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 32 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--ll";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 0 || option2 != 0 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--jj 123  --kk 32      --ll 77";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 32 || option3 != 77)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--jj 123  --jj 32";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 0 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
}

void test_uint_combined_options(test_context& ctx)
{
    unsigned int option1 = 0;
    unsigned int option2 = 0;
    unsigned int option3 = 0;

    parser3000 parser;

    parser.add_uint_option('j', "jj", &option1);
    parser.add_uint_option('k', "kk", &option2);
    parser.add_uint_option('l', "ll", &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "--jj 123 -k 99 --ll 100";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 99 || option3 != 100)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--jj 123 -k    99 --ll   100 -j 80";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 99 || option3 != 100)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
}

void test_uint_options(test_context& ctx)
{
    std::cout << "Testing uint options\r\n";
    test_uint_short_options(ctx);
    test_uint_long_options(ctx);
    test_uint_combined_options(ctx);
    std::cout << "Testing uint options done!!!\r\n";

}

