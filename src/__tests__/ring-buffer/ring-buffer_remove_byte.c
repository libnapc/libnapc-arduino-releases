/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_ringbuffer__testCase88(void) {
    napc_unmute();
    napc_puts("[ring-buffer/remove_byte.c] should work as expected ... ");
    napc_mute();
	napc__RingBuffer rbuffer;
	napc_u8 buffer[6] = {0,0,0,0,0,0xff};
	napc_u8 tmp = 0;

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	napc_RingBuffer_insertByte(&rbuffer, 1);
	napc_RingBuffer_insertByte(&rbuffer, 2);
	napc_RingBuffer_insertByte(&rbuffer, 3);
	napc_RingBuffer_insertByte(&rbuffer, 4);
	napc_RingBuffer_insertByte(&rbuffer, 5);

	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_removeByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 1);

	TEST_ASSERT(napc_RingBuffer_removeByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 2);

	TEST_ASSERT(napc_RingBuffer_removeByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 3);

	TEST_ASSERT(napc_RingBuffer_removeByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 4);

	TEST_ASSERT(napc_RingBuffer_removeByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 5);

	TEST_ASSERT(!napc_RingBuffer_removeByte(&rbuffer, &tmp));
}
