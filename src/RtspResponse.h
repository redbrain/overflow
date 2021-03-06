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

#ifndef __RTSP_RESPONSE_H__
#define __RTSP_RESPONSE_H__

#include "Response.h"

#include <map>
#include <string>


namespace Overflow
{
    class RtspResponse
    {
    public:
        RtspResponse(const Response* resp);

        RtspResponse(const unsigned char *buffer, const size_t length);

        RtspResponse(int code, std::string body);

        virtual ~RtspResponse();

        const int getCode() const { return mCode; }

        const std::string getBodyString() const { return mBody; }

        const unsigned char *getBody() const { return (unsigned char*)mBody.c_str(); }

        size_t getBodyLength() const { return getBodyString().length(); }

        const std::map<std::string, std::string> getHeaders() const { return mHeaders; }

        virtual const bool ok() const { return getCode() == 200; }

        const std::string headerValueForKey(const std::string& key);
        
    private:
        int mCode;
        std::string mBody;
        std::map<std::string, std::string> mHeaders;
    };
};

#endif //__RTSP_RESPONSE_H__
