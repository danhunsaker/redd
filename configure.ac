# rebuild: autoreconf -fvi 
# 
# Copyright (c) 2015 Pagoda Box Inc
# 
# This Source Code Form is subject to the terms of the Mozilla Public License, v.
# 2.0. If a copy of the MPL was not distributed with this file, You can obtain one
# at http://mozilla.org/MPL/2.0/.
# 

AC_PREREQ(2.61)

AC_INIT([redd], [0.0.2])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([src/redd.c])

AC_PROG_CC
AC_PROG_CC_STDC

AC_CHECK_LIB(pthread, pthread_mutexattr_init,
  [],
  [AC_MSG_ERROR([pthread libraries not found.])]
)

AC_CHECK_HEADERS(uv.h,
  [],
  [AC_MSG_ERROR([libuv header files not found.]); break]
)

AC_CHECK_LIB(uv, uv_run,
  [],
  [AC_MSG_ERROR([libuv libraries not found.])]
)

AC_CHECK_HEADERS(msgpack.h,
  [],
  [AC_MSG_ERROR([msgpack header files not found.]); break]
)

AC_CHECK_LIB(msgpack, msgpack_object_print,
  [],
  [AC_MSG_ERROR([msgpack libraries not found.])]
)

AC_CHECK_HEADERS(msgxchng.h,
  [],
  [AC_MSG_ERROR([msgxchng header files not found.]); break]
)

AC_CHECK_LIB(msgxchng, pack_msgxchng_request,
  [],
  [AC_MSG_ERROR([msgxchng libraries not found.])]
)

AC_CHECK_HEADERS(bframe.h,
  [],
  [AC_MSG_ERROR([bframe header files not found.]); break]
)

AC_CHECK_LIB(bframe, new_bframe,
  [],
  [AC_MSG_ERROR([bframe libraries not found.])]
)

AC_OUTPUT(Makefile src/Makefile)