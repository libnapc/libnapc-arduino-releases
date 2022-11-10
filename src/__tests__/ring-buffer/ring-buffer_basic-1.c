/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_ringbuffer__testCase82(void) {
    napc_unmute();
    napc_puts("[ring-buffer/basic-1.c] should work as expected ... ");
    napc_mute();
	napc__RingBuffer rbuffer;
	napc_u8 buffer[6] = {0,0,0,0,0,0xff};
	napc_u8 tmp = 0;

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	// insert 3 values
	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 1));
	TEST_ASSERT(memcmp(buffer, "\x01\x00\x00\x00\x00\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 2));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x00\x00\x00\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 3));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);
	//

	// pop 3 values
	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 3);

	TEST_ASSERT(napc_RingBuffer_removeByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 1);

	TEST_ASSERT(napc_RingBuffer_removeByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 2);

	TEST_ASSERT(napc_RingBuffer_removeByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 3);

	TEST_ASSERT(!napc_RingBuffer_removeByte(&rbuffer, &tmp));

	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 0);

	// insert 5 values
	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 4));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x00\xff", 6) == 0);
	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 1);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 5));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);
	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 2);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 6));
	TEST_ASSERT(memcmp(buffer, "\x06\x02\x03\x04\x05\xff", 6) == 0);
	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 3);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 7));
	TEST_ASSERT(memcmp(buffer, "\x06\x07\x03\x04\x05\xff", 6) == 0);
	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 4);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 8));
	TEST_ASSERT(memcmp(buffer, "\x06\x07\x08\x04\x05\xff", 6) == 0);
	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 5);

	// should not work (buffer full)
	TEST_ASSERT(!napc_RingBuffer_insertByte(&rbuffer, 9));
	TEST_ASSERT(memcmp(buffer, "\x06\x07\x08\x04\x05\xff", 6) == 0);
	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 5);
}
