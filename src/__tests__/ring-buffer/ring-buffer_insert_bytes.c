/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_ringbuffer__testCase87(void) {
    napc_unmute();
    napc_puts("[ring-buffer/insert_bytes.c] should work as expected ... ");
    napc_mute();
	napc__RingBuffer rbuffer;
	napc_u8 buffer[6] = {0,0,0,0,0,0xff};
	napc_u8 insert_array_1[3] = {1,2,3};
	napc_u8 insert_array_2[3] = {4,5,6};
	napc_u8 insert_array_3[2] = {4,5};

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	TEST_ASSERT(napc_RingBuffer_insertBytes(&rbuffer, insert_array_1, sizeof(insert_array_1)));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	TEST_ASSERT(!napc_RingBuffer_insertBytes(&rbuffer, insert_array_2, sizeof(insert_array_2)));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_insertBytes(&rbuffer, insert_array_3, sizeof(insert_array_3)));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);
}
