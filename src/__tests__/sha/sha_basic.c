#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_sha__testCase81(void) {
    napc_unmute();
    napc_puts("[sha/basic.c] It should work properly ... ");
    napc_mute();
	char out[65];
	const char *str = "secret_string";

	NAPC_ASSERT(
		napc_sha_calculate(str, napc_strlen(str), out, sizeof(out))
	);

	NAPC_ASSERT(
		memcmp(
			out,
			"850f9c6966cc780194218689986e2f8635764196f5a78b8021566a7a3bddbbcc\x00",
			65
		) == 0
	);
}

void PV_napc_sha__testCase82(void) {
    napc_unmute();
    napc_puts("[sha/basic.c] It should work with empty string ... ");
    napc_mute();
	char out[65];
	const char *str = "";

	NAPC_ASSERT(
		napc_sha_calculate(str, napc_strlen(str), out, sizeof(out))
	);

	NAPC_ASSERT(
		memcmp(
			out,
			"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\x00",
			65
		) == 0
	);
}

void PV_napc_sha__testCase83(void) {
    napc_unmute();
    napc_puts("[sha/basic.c] It should fail with a too small output buffer ... ");
    napc_mute();
	char out[64];
	const char *str = "";

	NAPC_ASSERT(
		!napc_sha_calculate(str, napc_strlen(str), out, sizeof(out))
	);
}
