#include "pch.h"
#include "parser_helpers.h"
#include "ansi_codes.h"

void test_combined_all_options(test_context& ctx)
{
    bool option1 = 0;
    bool option2 = 0;
    bool option3 = 0;
    int option4 = 0;
    int option5 = 0;
    int option6 = 0;
    unsigned int option7 = 0;
    unsigned int option8 = 0;
    unsigned int option9 = 0;
    double option10 = 0;
    double option11 = 0;
    double option12 = 0;
    string_type option13 = "";
    string_type option14 = "";
    string_type option15 = "";

    parser3000 parser;

    parser.add_bit_option('a', "aa", &option1, "ovo je bas lepo");
    parser.add_bit_option('b', "bb", &option2, "bas je ruznjikavo vise bre");
    parser.add_bit_option('c', "cc", &option3, "ma boje zemuna breeeee");
    parser.add_int_option('d', "dd", &option4, "bidza samo jako");
    parser.add_int_option('e', "ee", &option5, "cucanj tona bre");
    parser.add_int_option('f', "ff", &option6, "gas");
    parser.add_uint_option('g', "gg", &option7, "vodica bato");
    parser.add_uint_option('h', "hh", &option8, "sveta vodica");
    parser.add_uint_option('i', "ii", &option9, "ljuabv za kevu");
    parser.add_float_option('j', "jj", &option10, "ensako najjaci");
    parser.add_float_option('k', "kk", &option11, "britanski naglasak");
    parser.add_float_option('l', "ll", &option12, "slon je pao");
    parser.add_string_option('m', "mm", &option13, "sta ti treba");
    parser.add_string_option('n', "nn", &option14, "karte");
    parser.add_string_option('o', "oo", &option15, "samo teg jednu kilu nikako vise");

    string_type error;
    string_type option_str;

    ctx.tests++;
    option_str = "--aa -b  --cc -d 12 -e    55 --ff 7 -g 1 --hh 2 -i 4  --jj 5.9 -k 7 --ll 76  -m aaa --nn bbb --oo ccc";
    bool result = do_parse(option_str, parser, error);
    if (!result)
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str << ":\r\n"
            << error << "\r\n";
    }
    else if (!option1 || !option2 || !option3 || option4 != 12 || option5 != 55 || option6 != 7 || option7 != 1 || option8 != 2 || option9 != 4 || option10 != 5.9 || option11 != 7 || option12 != 76 || option13 != "aaa" || option14 != "bbb" || option15 != "ccc")
    {
        ctx.errors++;
        std::cout << ERROR_TEXT "Error parsing options " << option_str
            << " not all options are valid\r\n";
    }
    else
    {
        std::cout << "Option " << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << option_str << ANSI_COLOR_RESET << " " << OK_TEXT "\r\n";
    }
}

void test_combined_options(test_context& ctx)
{
    std::cout << "Testing combined options\r\n";
    test_combined_all_options(ctx);
    std::cout << "Testing combined options done!!!\r\n";

}