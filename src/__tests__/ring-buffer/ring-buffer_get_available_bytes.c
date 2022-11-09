/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_ringbuffer__testCase84(void) {
    napc_unmute();
    napc_puts("[ring-buffer/get_available_bytes.c] should work as expected ... ");
    napc_mute();
	napc__RingBuffer rbuffer;
	napc_u8 buffer[512];

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer));

	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 0);

	for (int i = 0; i < 10; ++i) {
		napc_RingBuffer_insertByte(&rbuffer, i);
	}

	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 10);

	napc_RingBuffer_removeByte(&rbuffer, NULL);

	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 9);
}
