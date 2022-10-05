#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_writer__testCase86(void) {
    napc_unmute();
    napc_puts("[writer/get_end_address.c] should work as expected ... ");
    napc_mute();
	unsigned char buffer[5];
	unsigned char *end = buffer + 4;

	napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Writer_getEndAddress(&writer) == end
	);
}
