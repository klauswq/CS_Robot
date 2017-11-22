/*
 * heartBeatTask.c
 *
 *  Created on: 9 Oct 2016
 *      Author: shailes
 */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* Board Header files */
#include "Sharp96x96.h"

/*
 *  heartBeatFxn
 */
Void heartBeatTaskFxn(UArg arg0, UArg arg1)
{
    while (1) {
    	// VCOM is an alternating signal that prevents a DC bias
    	// from being built up within the LCD panel.
    	//
    	// In general, for panels that require a 3 V power supply,
    	// the frequency is 60 Hz. For 5 V panels the frequency
    	// is slower and more lenient, 1-20 Hz. Higher frequency
    	// gives better contrast; lower frequency saves power.
    	//
    	Sharp96x96_SendToggleVCOMCommand();
        Task_sleep((UInt)arg0);
    }
}
