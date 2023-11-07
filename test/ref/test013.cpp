
#if defined(__GNUC__) || defined(__clang__)
#  define BBL_ALIGN(x) __attribute__ ((aligned(x)))
#elif defined(_MSC_VER)
#  define BBL_ALIGN(x) __declspec(align(x))
#else
#  error "Unknown compiler; can't define ALIGN"
#endif

#include <stddef.h>
#include <exception>
#include <thread>
#include <string>

static thread_local std::string __bbl_error_message;

extern "C" {

using test013_Foo_t = Foo;

int test013_Foo_bar(test013_Foo_t* _this, float a, int* _result) {
    try {
        *_result = _this->bar(a);
        return 0;
    } catch (std::exception& e) {
        __bbl_error_message = e.what();
        return 1;
    }
}

int test013_Foo_dtor(test013_Foo_t* _this) {
    delete _this;
    return 0;
}

} // extern "C"
