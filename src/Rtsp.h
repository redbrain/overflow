// -*-c++-*-
// Copyright (c) 2017 Philip Herron.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#ifndef __RTSP_H__
#define __RTSP_H__

#include "ByteBuffer.h"

#include <string>
#include <map>


namespace Overflow
{
    class Rtsp
    {
    public:
        Rtsp(const std::string& method, const std::string& path, int seqNum);

        const ByteBuffer& getBuffer();

        void addAuth(const std::string& encoded);

        const std::string& getMethod() const;

        std::string toString();

    protected:
        void addHeader(const std::string& key, const std::string& value);

    private:
        std::map<std::string, std::string> mHeaders;
        std::string mMethod;
        std::string mPath;
        ByteBuffer mBuffer;
    };
    
};

#endif //__RTSP_H__
