/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_ringbuffer__testCase85(void) {
    napc_unmute();
    napc_puts("[ring-buffer/get_buffer_size.c] should work as expected ... ");
    napc_mute();
	napc__RingBuffer rbuffer;
	napc_u8 buffer[512];

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_RingBuffer_getBufferSize(&rbuffer) == 512
	);
}
