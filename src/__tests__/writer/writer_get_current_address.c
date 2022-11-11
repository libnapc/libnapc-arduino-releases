/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_writer__testCase98(void) {
    napc_unmute();
    napc_puts("[writer/get_current_address.c] should work as expected ... ");
    napc_mute();
	unsigned char buffer[5];
	unsigned char *start = buffer;
	napc_u8 dummy_data[3] = {1,2,3};

	napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Writer_getCurrentAddress(&writer) == start
	);

	// Write 3 bytes
	NAPC_IGNORE_VALUE(
		napc_Writer_writeU8Array(&writer, 3, dummy_data)
	);

	TEST_ASSERT(
		napc_Writer_getCurrentAddress(&writer) == (start + 3)
	);
}
