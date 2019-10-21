//
//  main.c
//  Cases
//
//  Created by JiangWang on 2019/10/18.
//  Copyright © 2019 JiangWang. All rights reserved.
//

#include <stdio.h>
#include "CoreFoundation/CFArray.h"
#include <limits.h>

int main(int argc, const char * argv[]) {
    int total = 100;
    CFMutableArrayRef mutaArray = CFArrayCreateMutable(kCFAllocatorDefault, LONG_MAX, NULL);
    for (int index = 0; index < total; index++) {
        CFArrayAppendValue(mutaArray, &index);
    }
    CFArrayRef array = CFArrayCreateCopy(kCFAllocatorDefault, mutaArray);
    for (int index = 0; index < CFArrayGetCount(array); index++) {
        int *value = (int *)CFArrayGetValueAtIndex(array, index);
        printf("array's content: %d\n", *value);
    }
    return 0;
}
