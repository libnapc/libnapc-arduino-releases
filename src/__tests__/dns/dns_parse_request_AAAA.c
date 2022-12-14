/**
 * This file was automatically created by bin/libnapc/preprocess/steps/3.preprocessTestFiles.php
 */
#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_dns__testCase4(void) {
    napc_unmute();
    napc_puts("[dns/parse_request_AAAA.c] should work properly (AAAA record) ... ");
    napc_mute();
	napc_u8 payload[] = {
		0x14,0x60,0x01,0x20,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x0a,0x63,0x6c,0x6f,0x75,0x64,0x66,0x6c,0x61,0x72,0x65,0x03,0x63,0x6f,0x6d,0x00,0x00,0x1c,0x00,0x01,0x00,0x00,0x29,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	};
	napc__DNSRequest request;

	TEST_ASSERT(
		napc_DNS_parseRequest(&request, payload, sizeof(payload))
	);

	TEST_ASSERT(request.header.question_count == 1);
	TEST_ASSERT(request.header.answer_count == 0);
	TEST_ASSERT(
		request.header.request_identifier == NAPC_U16_LITERAL(0x1460)
	);
	TEST_ASSERT(request.header.response_code == 0);

	TEST_ASSERT(request.query.qtype == NAPC_DNS_QTYPE_AAAA);
	TEST_ASSERT(
		napc_streql("cloudflare.com", request.query.name)
	);
}
