/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_dns__testCase6(void) {
    napc_unmute();
    napc_puts("[dns/parse_response_AAAA.c] should work properly (AAAA record) ... ");
    napc_mute();
	napc_u8 payload[] = {
		0x14,0x60,0x81,0xa0,0x00,0x01,0x00,0x02,0x00,0x00,0x00,0x01,0x0a,0x63,0x6c,0x6f,0x75,0x64,0x66,0x6c,0x61,0x72,0x65,0x03,0x63,0x6f,0x6d,0x00,0x00,0x1c,0x00,0x01,0xc0,0x0c,0x00,0x1c,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x10,0x26,0x06,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x68,0x10,0x84,0xe5,0xc0,0x0c,0x00,0x1c,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x10,0x26,0x06,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x68,0x10,0x85,0xe5,0x00,0x00,0x29,0x04,0xd0,0x00,0x00,0x00,0x00,0x00,0x0
	};
	napc__DNSResponse response;

	TEST_ASSERT(
		napc_DNS_parseResponse(&response, payload, sizeof(payload))
	);

	TEST_ASSERT(response.header.question_count == 1);
	TEST_ASSERT(response.header.answer_count == 2);
	TEST_ASSERT(
		response.header.request_identifier == NAPC_U16_LITERAL(0x1460)
	);
	TEST_ASSERT(response.header.response_code == 0);

	TEST_ASSERT(response.answers[0].ttl == 0);
	TEST_ASSERT(response.answers[0].rd_length == 16);
	TEST_ASSERT(
		napc_memeql("\x26\x06\x47\x00\x00\x00\x00\x00\x00\x00\x00\x00\x68\x10\x84\xe5", response.answers[0].rd_data, 16)
	);
}
