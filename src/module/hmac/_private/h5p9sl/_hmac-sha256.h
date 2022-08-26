/*
* MIT License
* 
* Copyright (c) 2022 nap.software
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
/*
    hmac_sha256.h
    Originally written by https://github.com/h5p9sl
*/

#ifndef H5P9SL_HMAC_SHA256_H
#define H5P9SL_HMAC_SHA256_H

#include <stddef.h>

size_t  // Returns the number of bytes written to `out`
H5P9SL_hmac_sha256(
    // [in]: The key and its length.
    //      Should be at least 32 bytes long for optimal security.
    const void* key,
    const size_t keylen,

    // [in]: The data to hash alongside the key.
    const void* data,
    const size_t datalen,

    // [out]: The output hash.
    //      Should be 32 bytes long. If it's less than 32 bytes,
    //      the resulting hash will be truncated to the specified length.
    void* out,
    const size_t outlen);

#endif
