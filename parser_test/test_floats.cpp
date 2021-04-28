#include "pch.h"
#include "parser_helpers.h"
#include "ansi_codes.h"

void test_float_short_options(test_context& ctx)
{
    double option1 = 5;
    double option2 = 0;
    double option3 = 0;

    parser3000 parser;

    parser.add_float_option('m', &option1, "mama hocu kuci");
    parser.add_float_option('n', &option2, "samo jako");
    parser.add_float_option('o', &option3, "just do it");

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "-m 123 ";
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
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "-m123.73 ";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123.73 || option2 != 0 || option3 != 0)
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
    option_str = "-m 123.73 -n  4.9";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123.73 || option2 != 4.9 || option3 != 0)
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
    option_str = "-n 123.73 -o 12        -m 89 ";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 89 || option2 != 123.73 || option3 != 12)
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
    option_str = "-n ";
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
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

   /* option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "-n 123.73 -n 768 ";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 0 || option2 != 123.73 || option3 != 0)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }*/

    /////////////////////////////////////////////////////////////////////////////////////////////////////
}

void test_float_long_options(test_context& ctx)
{
    double option1 = 0;
    double option2 = 0;
    double option3 = 0;

    parser3000 parser;

    parser.add_float_option("mm", &option1, "tako je bre");
    parser.add_float_option("nn", &option2, "samo jako");
    parser.add_float_option("oo", &option3, "zato sto sam ti majka eto zasto");

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "--mm 123 ";
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
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--mm 123      --nn 32.9   ";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 32.9 || option3 != 0)
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
    option_str = "--mm";
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
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

  /*  option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--mm 123 --mm 99";
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
    }*/

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--mm 123 --nn 99 --oo 88 ";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 99 || option3 != 88)
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

void test_float_combined_options(test_context& ctx)
{
    double option1 = 0;
    double option2 = 0;
    double option3 = 0;

    parser3000 parser;

    parser.add_float_option('m', "mm", &option1, "lagano");
    parser.add_float_option('n', "nn", &option2, "vazi se samo na kratko");
    parser.add_float_option('o', "oo", &option3, "ocemo pare");

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "--mm 123  -n 45.6";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 45.6 || option3 != 0)
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
    option_str = "--mm 123  -n 45.6 --oo    12";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 45.6 || option3 != 12)
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

   /* option1 = 0;
    option2 = 0;
    option3 = 0;

    ctx.tests++;
    option_str = "--mm 123  -n 45.6 --oo    12 -m 9";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != 123 || option2 != 45.6 || option3 != 12)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }
    */
    /////////////////////////////////////////////////////////////////////////////////////////////////////
}

void test_float_options(test_context& ctx)
{
    std::cout << "Testing float options\r\n";
    test_float_short_options(ctx);
    test_float_long_options(ctx);
    test_float_combined_options(ctx);
    std::cout << "Testing float options done!!!\r\n";

}