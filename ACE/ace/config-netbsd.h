/* -*- C++ -*- */
// $Id$

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H

#ifndef ACE_MT_SAFE
#define ACE_MT_SAFE 1
#endif

#if defined (__GNUG__)
# include "ace/config-g++-common.h"
#endif /* __GNUG__ */

#if defined(ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#  define ACE_HAS_THREADS 1
#  define ACE_HAS_PTHREADS 1
#  define ACE_HAS_PTHREADS_UNIX98_EXT 1
#  define ACE_HAS_PTHREAD_RESUME_NP 1
#  define ACE_HAS_PTHREAD_SUSPEND_NP 1
#  define ACE_LACKS_PTHREAD_THR_SIGSETMASK 1
#  define ACE_LACKS_PTHREAD_YIELD 1
#endif /* ACE_MT_SAFE */

#define ACE_HAS_CLOCK_SETTIME 1
#define ACE_HAS_CLOCK_GETTIME 1
#define ACE_HAS_SETTIMEOFDAY 1
#define ACE_HAS_GETTIMEOFDAY 1
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R 1
#define ACE_HAS_3_PARAM_WCSTOK 1
#define ACE_HAS_3_PARAM_READDIR_R 1
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG 1
#define ACE_HAS_ALT_CUSERID 1
#define ACE_HAS_AUTOMATIC_INIT_FINI 1
#define ACE_HAS_CLOCK_GETTIME 1
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES 1
#define ACE_HAS_DIRENT 1
#define ACE_HAS_EXCEPTIONS 1
#define ACE_HAS_GETIFADDRS 1
#define ACE_HAS_GETPAGESIZE 1
#define ACE_HAS_GETPROGNAME 1
#define ACE_HAS_GETRUSAGE 1
#define ACE_HAS_GETRUSAGE_PROTOTYPE 1
#define ACE_HAS_GPERF 1
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT 1
#define ACE_HAS_IP_MULTICAST 1
#define ACE_HAS_MSG 1
#define ACE_HAS_NEW_NO_H 1
#define ACE_HAS_NONCONST_SELECT_TIMEVAL 1
#define ACE_HAS_ONLY_SCHED_OTHER 1
#define ACE_HAS_POLL 1
#define ACE_HAS_POSITION_INDEPENDENT_POINTERS 1
#define ACE_HAS_POSIX_NONBLOCK 1
#define ACE_HAS_POSIX_TIME 1
#define ACE_HAS_P_READ_WRITE 1
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS 1
#define ACE_HAS_REENTRANT_FUNCTIONS 1
#define ACE_HAS_SCANDIR 1
#define ACE_HAS_SETPROGNAME 1
#define ACE_HAS_SIGACTION_CONSTP2 1
#define ACE_HAS_SIGINFO_T 1
#define ACE_HAS_SIGSUSPEND 1
#define ACE_HAS_SIGTIMEDWAIT 1
#define ACE_HAS_SIGWAIT 1
#define ACE_HAS_SIG_ATOMIC_T 1
#define ACE_HAS_SIG_C_FUNC 1
#define ACE_HAS_SOCKADDR_IN_SIN_LEN 1
#define ACE_HAS_SOCKADDR_IN6_SIN6_LEN 1
#define ACE_HAS_SOCKADDR_MSG_NAME 1
#define ACE_HAS_SOCKLEN_T 1
#define ACE_HAS_SSIZE_T 1
#define ACE_HAS_STANDARD_CPP_LIBRARY 1
#define ACE_HAS_STDEXCEPT_NO_H 1
#define ACE_HAS_STRINGS 1
#define ACE_HAS_STRING_CLASS 1
#define ACE_HAS_SVR4_DYNAMIC_LINKING 1
#define ACE_HAS_SYSV_IPC 1
#define ACE_HAS_SYS_FILIO_H 1
#define ACE_HAS_STRSIGNAL
#define ACE_HAS_SYS_SOCKIO_H 1
#define ACE_HAS_SYS_SYSCALL_H 1
#define ACE_HAS_SYSCTL
#define ACE_HAS_TERMIOS 1
#define ACE_HAS_THREAD_SPECIFIC_STORAGE 1
#define ACE_HAS_TIMEZONE 1
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY 1
#define ACE_HAS_UALARM 1
#define ACE_HAS_UCONTEXT_T 1
#define ACE_HAS_VOIDPTR_MMAP 1
#define ACE_HAS_VOIDPTR_SOCKOPT 1
#define ACE_HAS_WCHAR 1
#define ACE_HAS_XPG4_MULTIBYTE_CHAR 1
#define ACE_IOCTL_TYPE_ARG2 u_long
#define ACE_LACKS_CONDATTR_PSHARED 1
#define ACE_LACKS_GETHOSTENT 1
#define ACE_LACKS_GETIPNODEBYADDR 1
#define ACE_LACKS_GETIPNODEBYNAME 1
#define ACE_LACKS_IOSTREAM_FX 1
#define ACE_LACKS_ITOW 1
#define ACE_LACKS_LINEBUFFERED_STREAMBUF 1
#define ACE_LACKS_LOG2 1
#define ACE_LACKS_MSG_ACCRIGHTS 1
#define ACE_LACKS_MUTEXATTR_PSHARED 1
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS 1
#define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1
#define ACE_LACKS_PRI_T 1
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK 1
#define ACE_LACKS_PTHREAD_YIELD 1
#define ACE_LACKS_PWD_REENTRANT_FUNCTIONS 1
#define ACE_LACKS_RWLOCKATTR_PSHARED 1
#define ACE_LACKS_RWLOCK_T 1
#define ACE_LACKS_SETSCHED 1
#define ACE_LACKS_SIGINFO_H 1
#define ACE_LACKS_STROPTS_H 1
#define ACE_LACKS_STRRECVFD 1
#define ACE_LACKS_TIMEDWAIT_PROTOTYPES 1
#define ACE_LACKS_TIMESPEC_T 1
#define ACE_LACKS_UNBUFFERED_STREAMBUF 1
#define ACE_LACKS_WCSDUP 1
#define ACE_LACKS_WCSICMP 1
#define ACE_LACKS_WCSNICMP 1
#define ACE_SCANDIR_CMP_USES_CONST_VOIDPTR 1
#define ACE_LACKS_WSCANF
#define ACE_LACKS_ISCTYPE

#if defined(__x86_64__)
#define ACE_SIZEOF_DOUBLE 8
#define ACE_SIZEOF_FLOAT 4
#define ACE_SIZEOF_INT 4
#define ACE_SIZEOF_LONG 8
#define ACE_SIZEOF_LONG_DOUBLE 16
#define ACE_SIZEOF_LONG_LONG 8
#define ACE_SIZEOF_SHORT 2
#define ACE_SIZEOF_VOID_P 8
#define ACE_SIZEOF_WCHAR 4

typedef unsigned long ACE_UINT64;
typedef   signed long ACE_INT64;

#define ACE_SSIZE_T_FORMAT_SPECIFIER_ASCII  "%ld"
#define ACE_SIZE_T_FORMAT_SPECIFIER_ASCII "%lu"

#elif defined(__i386__)

#define ACE_SIZEOF_DOUBLE 8
#define ACE_SIZEOF_FLOAT 4
#define ACE_SIZEOF_INT 4
#define ACE_SIZEOF_LONG 4
#define ACE_SIZEOF_LONG_DOUBLE 12
#define ACE_SIZEOF_LONG_LONG 8
#define ACE_SIZEOF_SHORT 2
#define ACE_SIZEOF_VOID_P 4
#define ACE_SIZEOF_WCHAR 4

typedef unsigned long long ACE_UINT64;
typedef   signed long long ACE_INT64;

#else
# error unknown CPU architecture
#endif

#endif  /* ACE_CONFIG_H */

// Local Variables:
// mode:C++
// End:
