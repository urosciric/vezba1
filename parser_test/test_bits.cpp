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

    /////////////////////////////////////////////////////////////////////////////////////////////////////

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

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " -aac";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || option2 || option3)
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
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " -abca";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || option2 || option3)
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
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " -b -ac";
    result = do_parse(option_str, parser, error);
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
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " -bc -ac";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || !option2 || !option3)
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
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " -aa -aa";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || option2 || option3)
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

    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " -abc";
    result = do_parse(option_str, parser, error);
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
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = "        ";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 || option2 || option3)
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
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = "      ";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 || option2 || option3)
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
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = "-ab       -c";
    result = do_parse(option_str, parser, error);
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
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = "";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 || option2 || option3)
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

void test_bit_long_options(test_context& ctx)
{
    bool option1 = false;
    bool option2 = false;
    bool option3 = false;

    parser3000 parser;

    parser.add_bit_option("aa", &option1);
    parser.add_bit_option("bb", &option2);
    parser.add_bit_option("cc", &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = " --aa";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || option2 || option3)
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
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " --aa --bb";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || !option2 || option3)
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

    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = " --aa --bb --cc";
    result = do_parse(option_str, parser, error);
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
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////

}


void test_bit_combined_options(test_context& ctx)
{
    bool option1 = false;
    bool option2 = false;
    bool option3 = false;

    parser3000 parser;

    parser.add_bit_option('a', "aa", &option1);
    parser.add_bit_option('b', "bb", &option2);
    parser.add_bit_option('c', "cc", &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "-a --aa -b --bb";
    bool result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || option2 || option3)
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
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = "-ab    --cc";
    result = do_parse(option_str, parser, error);
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
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << option_str << OK_TEXT "\r\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    option1 = false;
    option2 = false;
    option3 = false;

    ctx.tests++;
    option_str = "--aa -bc --cc -a  --bb";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || !option2 || !option3)
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

void test_bit_options(test_context& ctx)
{
    std::cout << "Testing bit options\r\n";

    test_bit_short_options(ctx);
    test_bit_long_options(ctx);
    test_bit_combined_options(ctx);

    std::cout << "Testing bit options done!!!\r\n";
}