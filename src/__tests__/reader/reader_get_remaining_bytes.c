/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase65(void) {
    napc_unmute();
    napc_puts("[reader/get_remaining_bytes.c] should work as expected ... ");
    napc_mute();
	unsigned char buffer[5];

	napc__Reader reader;

	napc_Reader_init(&reader, buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Reader_getRemainingBytes(&reader) == 5
	);

	// Advance by 3 bytes
	NAPC_IGNORE_VALUE(
		napc_Reader_readU8Array(&reader, 3, NULL)
	);

	TEST_ASSERT(
		napc_Reader_getRemainingBytes(&reader) == 2
	);

	// Advance by 2 bytes
	NAPC_IGNORE_VALUE(
		napc_Reader_readU8Array(&reader, 2, NULL)
	);

	TEST_ASSERT(
		napc_Reader_getRemainingBytes(&reader) == 0
	);
}
