#ifndef FACE_GLOBAL_H
#define FACE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FACE_LIBRARY)
#  define FACESHARED_EXPORT Q_DECL_EXPORT
#else
#  define FACESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // FACE_GLOBAL_H
