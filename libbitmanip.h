/**
 * @file 
 * Header only bit manipulation implementation
 * @copyright
 * Copyright (c) 2019 Joshua Scoggins 
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */
#ifndef LIB_BITMANIP_H__
#define LIB_BITMANIP_H__
namespace bitmanip 
{
    template<typename R, typename T, T mask, T shift>
    constexpr R decode(T value) noexcept {
        // if we had access to c++17 I could use constexpr if
        return static_cast<R>((value & mask) >> shift);
    }
    template<typename T, typename R>
    constexpr R decode(T value, T mask, T shift) noexcept {
        return static_cast<R>((value & mask) >> shift);
    }
    template<typename T>
    constexpr T decode(T value, T mask, T shift) noexcept {
        return (value & mask) >> shift;
    }
    template<typename T, typename V, T mask, T shift>
    constexpr T encode(T value, V toInsert) noexcept {
        return ((value & (~mask)) | ((static_cast<T>(toInsert) << shift) & (mask)));
    }
    template<typename T, typename V>
    constexpr T encode(T value, V toInsert, T mask, T shift) noexcept {
        return ((value & (~mask)) | ((static_cast<T>(toInsert) << shift) & (mask)));
    }
    template<typename T>
    constexpr bool isEven(T value) noexcept {
        return (value & 0x1) == 0;
    }
    template<typename T>
    constexpr bool isOdd(T value) noexcept {
        return (value & 0x1) != 0;
    }
    // sanity checks
    static_assert(encode<int, int, 0x1, 0>(0, 1) == 1, "Sanity check for encode operation failed!");

} // end bitmanip
#endif // end LIB_BITMANIP_H__
