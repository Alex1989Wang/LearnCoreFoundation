/*	CoreFoundation.h
	Copyright (c) 1998-2018, Apple Inc. and the Swift project authors
 
	Portions Copyright (c) 2014-2018, Apple Inc. and the Swift project authors
	Licensed under Apache License v2.0 with Runtime Library Exception
	See http://swift.org/LICENSE.txt for license information
	See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
*/

#if !defined(__COREFOUNDATION_COREFOUNDATION__)
#define __COREFOUNDATION_COREFOUNDATION__ 1
#define __COREFOUNDATION__ 1

#if !defined(CF_EXCLUDE_CSTD_HEADERS)

#include <sys/types.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(__STDC_VERSION__) && (199901L <= __STDC_VERSION__)

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>

#endif

#endif

#include "CFBase.h"
#include "CFArray.h"
#include "CFBag.h"
#include "CFBinaryHeap.h"
#include "CFBitVector.h"
#include "CFByteOrder.h"
#include "CFCalendar.h"
#include "CFCharacterSet.h"
#include "CFData.h"
#include "CFDate.h"
#include "CFDateFormatter.h"
#include "CFDictionary.h"
#include "CFError.h"
#include "CFLocale.h"
#include "CFNumber.h"
#include "CFNumberFormatter.h"
#include "CFPreferences.h"
#include "CFPropertyList.h"
#include "CFSet.h"
#include "CFString.h"
#include "CFStringEncodingExt.h"
#include "CFTimeZone.h"
#include "CFTree.h"
#include "CFURL.h"
#include "CFURLAccess.h"
#include "CFUUID.h"
#include "CFUtilities.h"
#include "CFBundle.h"

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || (TARGET_OS_EMBEDDED || TARGET_OS_IPHONE) || TARGET_OS_WIN32
#include "CFMessagePort.h"
#include "CFPlugIn.h"
#include "CFRunLoop.h"
#include "CFStream.h"
#include "CFSocket.h"
#include "CFMachPort.h"

#include "CFAttributedString.h"
#include "CFNotificationCenter.h"

#endif

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || (TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)
#endif

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
#include "CFUserNotification.h"
#include "CFXMLNode.h"
#include "CFXMLParser.h"
#endif


#endif /* ! __COREFOUNDATION_COREFOUNDATION__ */

