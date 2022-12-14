/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

/**
 * True values
 */
void PV_napc_parser__testCase13(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work properly (word true) ... ");
    napc_mute();
	bool out = false;

	TEST_ASSERT(napc_parser_parseBoolean("true", &out));
	TEST_ASSERT(out);
}

void PV_napc_parser__testCase14(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work properly (word trUe) ... ");
    napc_mute();
	bool out = false;

	TEST_ASSERT(napc_parser_parseBoolean("trUe", &out));
	TEST_ASSERT(out);
}

void PV_napc_parser__testCase15(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work properly (word yes) ... ");
    napc_mute();
	bool out = false;

	TEST_ASSERT(napc_parser_parseBoolean("yes", &out));
	TEST_ASSERT(out);
}

void PV_napc_parser__testCase16(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work properly (word 1) ... ");
    napc_mute();
	bool out = false;

	TEST_ASSERT(napc_parser_parseBoolean("1", &out));
	TEST_ASSERT(out);
}

/**
 * False values
 */
void PV_napc_parser__testCase17(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work properly (word false) ... ");
    napc_mute();
	bool out = true;

	TEST_ASSERT(napc_parser_parseBoolean("false", &out));
	TEST_ASSERT(!out);
}

void PV_napc_parser__testCase18(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work properly (word faLse) ... ");
    napc_mute();
	bool out = true;

	TEST_ASSERT(napc_parser_parseBoolean("faLse", &out));
	TEST_ASSERT(!out);
}

void PV_napc_parser__testCase19(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work properly (word no) ... ");
    napc_mute();
	bool out = true;

	TEST_ASSERT(napc_parser_parseBoolean("no", &out));
	TEST_ASSERT(!out);
}

void PV_napc_parser__testCase20(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work properly (word 0) ... ");
    napc_mute();
	bool out = true;

	TEST_ASSERT(napc_parser_parseBoolean("0", &out));
	TEST_ASSERT(!out);
}

void PV_napc_parser__testCase21(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should work without output ... ");
    napc_mute();
	TEST_ASSERT(napc_parser_parseBoolean("yes", NULL));
	TEST_ASSERT(napc_parser_parseBoolean("no", NULL));
	TEST_ASSERT(napc_parser_parseBoolean("0", NULL));
}

void PV_napc_parser__testCase22(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should return false given an empty string ... ");
    napc_mute();
	bool out;

	TEST_ASSERT(!napc_parser_parseBoolean("", &out));
}

void PV_napc_parser__testCase23(void) {
    napc_unmute();
    napc_puts("[parser/parse_boolean.c] It should return false given an invalid string ... ");
    napc_mute();
	bool out;

	TEST_ASSERT(!napc_parser_parseBoolean("trua", &out));
}
