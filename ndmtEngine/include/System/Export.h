#pragma once

#ifdef NDMTENGINE_EXPORTS
#define NDMTENGINE_API __declspec(dllexport)
#else
#define NDMTENGINE_API __declspec(dllimport)
#endif

#ifdef _MSC_VER

#pragma warning(disable: 4251)

#endif