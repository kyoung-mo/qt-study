#ifndef MYUTIL_GLOBAL_H
#define MYUTIL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYUTIL_LIBRARY)
#  define MYUTIL_EXPORT Q_DECL_EXPORT
#else
#  define MYUTIL_EXPORT Q_DECL_IMPORT
#endif

#endif // MYUTIL_GLOBAL_H
