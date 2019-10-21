//
//  main.c
//  001-log
//
//  Created by JiangWang on 2019/10/21.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
#include "CFLogUtilities.h"

int main(int argc, const char * argv[]) {
    CFStringRef log = CFStringCreateWithCString(kCFAllocatorSystemDefault, "Hello World!", kCFStringEncodingUTF8);
    CFLog(kCFLogLevelError, log); //nothing happens
    return 0;
}
