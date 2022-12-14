/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase74(void) {
    napc_unmute();
    napc_puts("[reader/u16be.c] should read u16be correctly ... ");
    napc_mute();
	napc_u8 data[5] = {0xa, 0xb, 0xc, 0xd, 0xe};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	napc_u16 tmp = 0;
	TEST_ASSERT(napc_Reader_readU16BE(&ctx, &tmp));
	TEST_ASSERT(tmp == NAPC_U16_LITERAL(0x0a0b));
	TEST_ASSERT(napc_Reader_readU16BE(&ctx, &tmp));
	TEST_ASSERT(tmp == NAPC_U16_LITERAL(0x0c0d));
	TEST_ASSERT(!napc_Reader_readU16BE(&ctx, &tmp));
}

void PV_napc_reader__testCase75(void) {
    napc_unmute();
    napc_puts("[reader/u16be.c] should read u16be correctly with out=NULL ... ");
    napc_mute();
	napc_u8 data[5] = {0xa, 0xb, 0xc, 0xd, 0xe};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	TEST_ASSERT(napc_Reader_readU16BE(&ctx, NULL));
	napc_u16 tmp = 0;
	TEST_ASSERT(napc_Reader_readU16BE(&ctx, &tmp));
	TEST_ASSERT(tmp == NAPC_U16_LITERAL(0x0c0d));
	TEST_ASSERT(!napc_Reader_readU16BE(&ctx, NULL));
}

/*
SKIP_TEST_CASE("should work correctly with a size of 0") {
	napc_u8 data[5] = {0xa, 0xb, 0xc, 0xd, 0xe};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, 0);

	TEST_ASSERT(!napc_Reader_readU16BE(&ctx, NULL));
}
*/
