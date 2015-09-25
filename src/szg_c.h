#ifndef SZG_C_H
#define SZG_C_H

#include <string>

#ifdef AR_USE_WIN_32
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif

#define PRINT_ERROR(x)


#include "util.h"
#include "client.h"
#include "config.h"

#endif
