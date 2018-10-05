#pragma once
#define SAFE_DELETE(obj) \
    if (obj)             \
    {                    \
        delete obj;      \
        obj = NULL;      \
    }
#define SAFE_ARRAY_DELETE(obj) \
    if (arr)                   \
    {                          \
        delete arr;            \
        arr = NULL;            \
    }
#define NONCOPYABLE(class_name)             \
    class_name(const class_name &) = delete; \
    class_name &operator=(const class_name &) = delete
