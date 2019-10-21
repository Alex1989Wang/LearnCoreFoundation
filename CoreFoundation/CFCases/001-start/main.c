//
//  main.c
//  Cases
//
//  Created by JiangWang on 2019/10/21.
//  Copyright © 2019 Apple. All rights reserved.
//

#include <stdio.h>
#include "CoreFoundation.h"

int main(int argc, const char * argv[]) {
    int total = 1000;
    CFMutableArrayRef mutaArray = CFArrayCreateMutable(kCFAllocatorSystemDefault, total, NULL);
    for (int index = 0; index < total; index++) {
        int *temp = (int *)malloc(sizeof(int));
        *temp = index;
        CFArrayAppendValue(mutaArray, temp);
    }
    CFArrayRef copy = CFArrayCreateCopy(kCFAllocatorSystemDefault, mutaArray);
    CFRelease(mutaArray);
    for (int index = 0; index < total; index++) {
        int *value = (int *)CFArrayGetValueAtIndex(copy, index);
        printf("at index(%d) value: %d\n", index, *value);
    }
    CFRelease(copy);
    return 0;
}
