//
//  main.c
//  Cases
//
//  Created by JiangWang on 2019/10/21.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
#include "CoreFoundation.h"
#include <limits.h>

int main(int argc, const char * argv[]) {
    CFRunLoopRef runloop = CFRunLoopGetMain();
    CFOptionFlags zero = (CFOptionFlags)0;
    CFRunLoopObserverRef newObserver = CFRunLoopObserverCreateWithHandler(kCFAllocatorSystemDefault, zero, true, 1000, ^(CFRunLoopObserverRef observer, CFRunLoopActivity activity) {
        printf("observer called???");
    });
    CFAbsoluteTime fiveLater = CFAbsoluteTimeGetCurrent() + 5;
    CFRunLoopTimerRef timer = CFRunLoopTimerCreateWithHandler(kCFAllocatorSystemDefault, fiveLater, 1000, zero, 1000, ^(CFRunLoopTimerRef timer) {
        printf("timer source called???\n");
//        CFRunLoopTimerSetNextFireDate(timer, CFAbsoluteTimeGetCurrent() + 1000);
    });
    CFRunLoopMode common = kCFRunLoopCommonModes;
    CFRunLoopAddObserver(runloop, newObserver, common);
    CFRunLoopAddTimer(runloop, timer, common);
    CFRunLoopRun();
    printf("CFRunLoopRun called after.");
    return 0;
}
