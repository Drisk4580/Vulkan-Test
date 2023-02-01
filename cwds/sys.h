#ifdef CWDEBUG
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <libcwd/sys.h>
#endif

// Used when building with autotools; generated from config.h.in that in turn is generated by autoheader.
// This header automatically includes <submodule>/config.h for each submodule that generates one.
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

// Used when building with cmake, because cmake isn't using a project-root config.h for its definitions.
// Currently only the submodules utils and threadpool have a config.h (todo: automate this too).
#ifdef HAVE_UTILS_CONFIG_H
#include "utils/config.h"
#endif
#ifdef HAVE_THREADPOOL_CONFIG_H
#include "threadpool/config.h"
#endif

#define UNUSED_ARG(x)
