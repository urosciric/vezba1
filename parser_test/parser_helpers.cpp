#include "pch.h"
#include "parser_helpers.h"
#include "test_common.h"

bool do_parse(const string_type what, parser3000& parser, string_type& err)
{
	std::ostringstream serr;
	std::istringstream ss(what);
	if (parser.parse(ss, serr))
	{
		std::cout << "Testing help:\r\n";
		test_help(parser);
		std::cout << "\r\n";
		return true;
	}
	else
	{
		err = serr.str();
		return false;
	}
}