/*
 * Copyright (C) 2015 Eistec AB
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup cpp11-compat
 * @{
 *
 * @file
 * @brief C++ runtime support functions
 *
 * Tested with GCC-4.9.2 and Clang-3.6
 *
 * @author  Joakim Nohlgård <joakim.nohlgard@eistec.se>
 */

#include <new>
#include <cstddef>
#include <cstdlib>

extern "C" {
#include "panic.h"
}

/**
 * @brief Definition of a pure virtual function
 *
 * Calling this function is an error.
 */
extern "C" void __cxa_pure_virtual ()
{
    core_panic(PANIC_GENERAL_ERROR, "PURE VIRTUAL CALL");
}

/**
 * @brief Register a function to be called by exit or when a shared library is unloaded.
 *
 * Not really used on an embedded system where you pull the power to shut down
 * the program.
 *
 * This is only called by code automatically generated by the C++ compiler.
 *
 * @return 0 on success
 * @return non-zero on failure.
 */
extern "C" int __cxa_atexit (void (*) (void *), void *, void *)
{
    /* We just pretend everything is dandy. */
    return 0;
}

namespace __gnu_cxx {
/**
 * @brief Override the G++ verbose termination handler
 *
 * The default implementation of __gnu_cxx::__verbose_terminate_handler comes
 * with gcc and will print the name of unhandled exceptions to stderr before
 * terminating the program. However, in order to get the name of the exceptions
 * a large chunk of name demangling code is pulled in as well (several tens of
 * kBytes!).
 *
 * @note Depending on the version of the compiler and what settings were used
 * when building the toolchain __gnu_cxx::__verbose_terminate_handler may or may
 * not be pulled in. std::abort may be used instead by default in some
 * toolchains.
 *
 * @see http://www.webalice.it/fede.tft/cpp_on_microcontrollers_tricks/cpp_on_microcontrollers_tricks.html
 */
void __verbose_terminate_handler()
{
    core_panic(PANIC_GENERAL_ERROR, "UNHANDLED C++ EXCEPTION");
}
} /* namespace __gnu_cxx */

/* Implementations of new and delete operators taken from public domain code
 * at http://pastebin.com/7VKUuTJa (downloaded on Wed 24 Jun 2015 09:00:07 PM CEST)
 * Author: Eric Agan
 * The license text reads:
 * > "Public domain, use however you wish.
 * > "If you really need a license, consider it MIT."
 */

/* tinynew.cpp

   Overrides operators new and delete
   globally to reduce code size.

   Public domain, use however you wish.
   If you really need a license, consider it MIT:
   http://www.opensource.org/licenses/mit-license.php

   - Eric Agan
     Elegant Invention
 */

/* Optionally you can override the 'nothrow' versions as well.
   This is useful if you want to catch failed allocs with your
   own debug code, or keep track of heap usage for example,
   rather than just eliminate exceptions.
 */

void* operator new(std::size_t size, const std::nothrow_t&) noexcept {
    return std::malloc(size);
}

void* operator new[](std::size_t size, const std::nothrow_t&) noexcept {
    return std::malloc(size);
}

void operator delete(void* ptr, const std::nothrow_t&) noexcept {
    std::free(ptr);
}

void operator delete[](void* ptr, const std::nothrow_t&) noexcept {
    std::free(ptr);
}

/** @} */