/*	CFInternal.h
	Copyright (c) 1998-2018, Apple Inc. and the Swift project authors

	Portions Copyright (c) 2014-2018, Apple Inc. and the Swift project authors
	Licensed under Apache License v2.0 with Runtime Library Exception
	See http://swift.org/LICENSE.txt for license information
	See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
*/

/*
        NOT TO BE USED OUTSIDE CF!
*/

#if !defined(__COREFOUNDATION_CFLOCKING_H__)
#define __COREFOUNDATION_CFLOCKING_H__ 1

#include "TargetConditionals.h"

#if TARGET_OS_MAC

#include <pthread.h>

typedef pthread_mutex_t CFLock_t;

#define CFLockInit ((pthread_mutex_t)PTHREAD_ERRORCHECK_MUTEX_INITIALIZER)
#define CF_LOCK_INIT_FOR_STRUCTS(X) (X = CFLockInit)

#define __CFLock(LP) ({ (void)pthread_mutex_lock(LP); })

#define __CFUnlock(LP) ({ (void)pthread_mutex_unlock(LP); })

#define __CFLockTry(LP) ({ pthread_mutex_trylock(LP) == 0; })

// SPI to permit initialization of values in Swift
static inline CFLock_t __CFLockInit(void) { return CFLockInit; }

#elif TARGET_OS_WIN32

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define VCEXTRALEAN
#include <Windows.h>

typedef int32_t CFLock_t;
#define CFLockInit 0
#define CF_LOCK_INIT_FOR_STRUCTS(X) (X = CFLockInit)

CF_INLINE void __CFLock(volatile CFLock_t *lock) {
  while (InterlockedCompareExchange((LONG volatile *)lock, ~0, 0) != 0) {
    Sleep(0);
  }
}

CF_INLINE void __CFUnlock(volatile CFLock_t *lock) {
  MemoryBarrier();
  *lock = 0;
}

CF_INLINE Boolean __CFLockTry(volatile CFLock_t *lock) {
  return (InterlockedCompareExchange((LONG volatile *)lock, ~0, 0) == 0);
}

// SPI to permit initialization of values in Swift
static inline CFLock_t __CFLockInit(void) { return CFLockInit; }

#elif TARGET_OS_LINUX || TARGET_OS_BSD

#include <stdint.h>

typedef int32_t CFLock_t;
#define CFLockInit 0
#define CF_LOCK_INIT_FOR_STRUCTS(X) (X = CFLockInit)

CF_INLINE void __CFLock(volatile CFLock_t *lock) {
  while (__sync_val_compare_and_swap(lock, 0, ~0) != 0) {
    sleep(0);
  }
}

CF_INLINE void __CFUnlock(volatile CFLock_t *lock) {
  __sync_synchronize();
  *lock = 0;
}

CF_INLINE Boolean __CFLockTry(volatile CFLock_t *lock) {
  return (__sync_val_compare_and_swap(lock, 0, ~0) == 0);
}

// SPI to permit initialization of values in Swift
static inline CFLock_t __CFLockInit(void) { return CFLockInit; }

typedef CFLock_t OSSpinLock;
#define OS_SPINLOCK_INIT CFLockInit
#define OSSpinLockLock(lock) __CFLock(lock)
#define OSSpinLockUnlock(lock) __CFUnlock(lock)

#else

#warning CF locks not defined for this platform -- CF is not thread-safe
#define __CFLock(A)     do {} while (0)
#define __CFUnlock(A)   do {} while (0)

#endif

#endif

