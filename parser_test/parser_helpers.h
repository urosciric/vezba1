#pragma once
#include "parser3000.h"

#define ERROR_TEXT "****ERROR****"
#define OK_TEXT "SUCCESS"

using namespace urke;

using namespace parser;

struct test_context
{
	int tests = 0;
	int errors = 0;
};

bool do_parse(const string_type what, parser3000& parser, string_type& err);
