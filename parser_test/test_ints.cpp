#include "pch.h"
#include "parser_helpers.h"
#include "ansi_codes.h"

void test_int_short_options(test_context& ctx)
{

    int option1 = 0;
    int option2 = 0;
    int option3 = 0;

    parser3000 parser;

    parser.add_int_option('d', &option1, "mama voli bebu najvise na svetu");
    parser.add_int_option('e', &option2, "tata pusi pljugu");
    parser.add_int_option('f', &option3, "seka me nervira");

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "-d 123 -e 34";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1!=123 || option2!=34 || option3!=0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "-d 123 -e 34 -f 479";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 34 || option3 != 479)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "-d 123 -d 5454";
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
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
}

void test_int_long_options(test_context& ctx)
{

    int option1 = 0;
    int option2 = 0;
    int option3 = 0;

    parser3000 parser;

    parser.add_int_option("dd", &option1);
    parser.add_int_option("ee", &option2);
    parser.add_int_option("ff", &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "--dd 123 --ee 128";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 128 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--dd 123 --ee 128 --ff 45546";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 128 || option3 != 45546)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--dd 123 --ee";
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
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
}

void test_int_combined_options(test_context& ctx)
{

    int option1 = 0;
    int option2 = 0;
    int option3 = 0;

    parser3000 parser;

    parser.add_int_option('d', "dd", &option1);
    parser.add_int_option('e', "ee", &option2);
    parser.add_int_option('f', "ff", &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "--dd 123 -e 564 -f 90";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 564 || option3 != 90)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--dd 123 --ee 675 -f 21";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 675 || option3 != 21)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "-d 76 --dd 123 -e 64 --ee 978 --ff 4223 -f 12";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 76 || option2 != 0 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
}

void test_int_options(test_context& ctx)
{
    std::cout << "Testing int options\r\n";
    test_int_short_options(ctx);
    test_int_long_options(ctx);
    test_int_combined_options(ctx);
    std::cout << "Testing int options done!!!\r\n";

}