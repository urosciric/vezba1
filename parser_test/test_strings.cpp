#include "pch.h"
#include "parser_helpers.h"

void test_string_short_options(test_context& ctx)
{

    string_type option1 = "";
    string_type option2 = "";
    string_type option3 = "";

    parser3000 parser;

    parser.add_string_option('g', &option1);
    parser.add_string_option('h', &option2);
    parser.add_string_option('i', &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = " -g ihfjru";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1!="ihfjru")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = " -g ihfjru -h sdfd";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ihfjru" || option2!= "sdfd")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = " -g ihfjru        -h sdfd";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ihfjru" || option2 != "sdfd")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = " -g ihfjru -i";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ihfjru")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = " -g ihfjru -h sdfd     -i qqq";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ihfjru" || option2 != "sdfd" || option3 != "qqq")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = " -g gk -g kk";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "gk")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = " -g gk -i     qq -h jh -g kk";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "gk" || option2!="jh" || option3!="qq")
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
}

void test_string_long_options(test_context& ctx)
{

    string_type option1 = "";
    string_type option2 = "";
    string_type option3 = "";

    parser3000 parser;

    parser.add_string_option("gg", &option1);
    parser.add_string_option("hh", &option2);
    parser.add_string_option("ii", &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = " --gg ww";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ww")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = "   --gg  ww   ";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ww")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = "--gg ww  --hh jjj";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ww" || option2 != "jjj")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = "--gg ww --ii mm --hh qq";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ww" || option2 != "qq" || option3 != "mm")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = "   --gg ww --ii zz";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ww" || option3 != "zz")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = "   --gg  ";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "")
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
}

void test_string_combined_options(test_context& ctx)
{

    string_type option1 = "";
    string_type option2 = "";
    string_type option3 = "";

    parser3000 parser;

    parser.add_string_option('g', "gg", &option1);
    parser.add_string_option('h', "hh", &option2);
    parser.add_string_option('i', "ii", &option3);

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "-g ww --hh oo -i pp";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ww" || option2 != "oo" || option3 != "pp")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = "-g ww --hh oo -i pp";
    result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ww" || option2 != "oo" || option3 != "pp")
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

    option1 = "";
    option2 = "";
    option3 = "";

    ctx.tests++;
    option_str = "-g ww --hh oo -i pp --gg gg";
    result = do_parse(option_str, parser, error);
    if (result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (option1 != "ww" || option2 != "oo" || option3 != "pp")
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
}

void test_string_options(test_context & ctx)
{
    std::cout << "Testing string options\r\n";

    test_string_short_options(ctx);
    test_string_long_options(ctx);
    test_string_combined_options(ctx);

    std::cout << "Testing string options done!!!\r\n";

}