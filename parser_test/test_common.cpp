#include "pch.h"
#include "parser3000.h"
#include "test_common.h"

using namespace urke;

void test_help(parser::parser3000& whose)
{
	whose.print_help("name", std::cout);
}