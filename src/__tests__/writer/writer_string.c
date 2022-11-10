/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_writer__testCase100(void) {
    napc_unmute();
    napc_puts("[writer/string.c] should write strings correctly ... ");
    napc_mute();
	char data[6] = {1, 2, 3, 4, 5, 6};
	napc__Writer ctx;

	napc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(
		napc_Writer_writeString(&ctx, "hello")
	);
	TEST_ASSERT(!napc_Writer_writeString(&ctx, "ab"));
	TEST_ASSERT(
		memcmp(data, "hello\x6", 6) == 0
	);
}
