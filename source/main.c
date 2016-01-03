#include <3ds.h>

#include <stdio.h>

#include "memchunkhax2.h"
#include "khax.h"
#include "khaxdemo.h"

int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    execute_memchunkhax2();

	printf("Press A to attempt khaxInitWithSVC!\n");
	printf("Press B to attempt the khax demo!\n");
    printf("Press START to exit.\n");

    while(aptMainLoop()) {
        hidScanInput();
        if(hidKeysDown() & KEY_START) {
            break;
        }
		
		if(hidKeysDown() & KEY_A) {
			printf("Result: %08X\n", (int) khaxInitWithSVC());
		}

		if(hidKeysDown() & KEY_B) {
			printf("Result: %08X\n", (int) khaxDemoMain());
		}
		
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
