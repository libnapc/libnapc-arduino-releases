/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase78(void) {
    napc_unmute();
    napc_puts("[reader/u8.c] should read u8 correctly ... ");
    napc_mute();
	napc_u8 data[3] = {0xa, 0xb, 0xc};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	napc_u8 tmp = 0;
	TEST_ASSERT(napc_Reader_readU8(&ctx, &tmp));
	TEST_ASSERT(tmp == 0xa);
	TEST_ASSERT(napc_Reader_readU8(&ctx, &tmp));
	TEST_ASSERT(tmp == 0xb);
	TEST_ASSERT(napc_Reader_readU8(&ctx, &tmp));
	TEST_ASSERT(tmp == 0xc);
	TEST_ASSERT(!napc_Reader_readU8(&ctx, &tmp));
}

void PV_napc_reader__testCase79(void) {
    napc_unmute();
    napc_puts("[reader/u8.c] should read u8 correctly with out=NULL ... ");
    napc_mute();
	napc_u8 data[3] = {0xa, 0xb, 0xc};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	TEST_ASSERT(napc_Reader_readU8(&ctx, NULL));
	TEST_ASSERT(napc_Reader_readU8(&ctx, NULL));
	napc_u8 tmp = 0;
	TEST_ASSERT(napc_Reader_readU8(&ctx, &tmp));
	TEST_ASSERT(tmp == 0xc);
	TEST_ASSERT(!napc_Reader_readU8(&ctx, NULL));
}

/*
SKIP_TEST_CASE("should work correctly with a size of 0") {
	napc_u8 data[3] = {0xa, 0xb, 0xc};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, 0);

	TEST_ASSERT(!napc_Reader_readU8(&ctx, NULL));
}
*/
