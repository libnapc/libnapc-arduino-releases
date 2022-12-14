/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_writer__testCase106(void) {
    napc_unmute();
    napc_puts("[writer/u8.c] should write u8 correctly ... ");
    napc_mute();
	napc_u8 data[4] = {0, 0, 0, 0xa};
	napc__Writer ctx;

	napc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(napc_Writer_writeU8(&ctx, 0x1));
	TEST_ASSERT(napc_Writer_writeU8(&ctx, 0x2));
	TEST_ASSERT(napc_Writer_writeU8(&ctx, 0x3));
	TEST_ASSERT(napc_Writer_writeU8(&ctx, 0xff));
	TEST_ASSERT(!napc_Writer_writeU8(&ctx, 0xaa));
	TEST_ASSERT(memcmp(data, "\x1\x2\x3\xff", 4) == 0);
}
