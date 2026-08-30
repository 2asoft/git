#include "unit-test.h"
#include "parse.h"

void test_parse__duration(void)
{
	struct {
		const char *value;
		timestamp_t expected;
	} cases[] = {
		{ "0", 0 },
		{ "30", 30 },
		{ "30s", 30 },
		{ "30m", 30 * 60 },
		{ "2h", 2 * 60 * 60 },
		{ "2d", 2 * 24 * 60 * 60 },
		{ "2w", 2 * 7 * 24 * 60 * 60 },
	};

	for (size_t i = 0; i < ARRAY_SIZE(cases); i++) {
		timestamp_t actual;

		cl_assert(git_parse_duration(cases[i].value, &actual));
		cl_assert_equal_u(actual, cases[i].expected);
	}
}

void test_parse__invalid_duration(void)
{
	const char *cases[] = {
		NULL,
		"",
		"-1",
		"1M",
		"1ms",
		"1h30m",
		"18446744073709551615m",
	};

	for (size_t i = 0; i < ARRAY_SIZE(cases); i++) {
		timestamp_t actual;

		cl_assert(!git_parse_duration(cases[i], &actual));
	}
}
