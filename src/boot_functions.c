/**
 * Warning: this file was auto generated.
 */
void napc_puts(const char *str);
void HAL_napc_initSerial(void);
void PV_napc_initLogHandler(void);
void HAL_napc_initTime(void);
void HAL_napc_initRandomBitSources(void);
void PV_napc_random_initPool(void);
void HAL_napc_initFileSystem(void);
void HAL_napc_initFileSystemHandlesPool(void);
void HAL_napc_initEthernet(void);
void HAL_napc_UDP_initSocketPool(void);
void HAL_napc_determineLoopYieldCPUDelay(void);

void libnapc_callBootFunctions(void) {
    HAL_napc_initSerial();
    napc_puts("[boot] called HAL_napc_initSerial (pri=0)\n");

    PV_napc_initLogHandler();
    napc_puts("[boot] called PV_napc_initLogHandler (pri=2)\n");

    HAL_napc_initTime();
    napc_puts("[boot] called HAL_napc_initTime (pri=20)\n");

    HAL_napc_initRandomBitSources();
    napc_puts("[boot] called HAL_napc_initRandomBitSources (pri=30)\n");

    PV_napc_random_initPool();
    napc_puts("[boot] called PV_napc_random_initPool (pri=31)\n");

    HAL_napc_initFileSystem();
    napc_puts("[boot] called HAL_napc_initFileSystem (pri=50)\n");

    HAL_napc_initFileSystemHandlesPool();
    napc_puts("[boot] called HAL_napc_initFileSystemHandlesPool (pri=51)\n");

    HAL_napc_initEthernet();
    napc_puts("[boot] called HAL_napc_initEthernet (pri=60)\n");

    HAL_napc_UDP_initSocketPool();
    napc_puts("[boot] called HAL_napc_UDP_initSocketPool (pri=61)\n");

    HAL_napc_determineLoopYieldCPUDelay();
    napc_puts("[boot] called HAL_napc_determineLoopYieldCPUDelay (pri=99)\n");

    napc_puts("[boot] calling into napc_main() now.\n");
}
