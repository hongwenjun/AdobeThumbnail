#ifndef ADOBETHUMBNAIL_H_INCLUDED
#define ADOBETHUMBNAIL_H_INCLUDED

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <atlenc.h>


// Adobe 文件提取 缩略图
bool  AdobeThumbnail(const char* adobe_filename ,const char* savejpeg_filename );
bool  AdobeThumbnail_W(const wchar_t* adobe_filename ,const wchar_t* savejpeg_filename );


// 获得编码后的数据长度
#define getDecodeLength Base64EncodeGetRequiredLength

// 数据使用 Base64 编码, 返回编码后的长度，如果返回0，可能目标空间不够
int toBase64_Encode(const char* pSrc, int nLenSrc, char* pDst, int nLenDst);

// Base64 数据解码, 返回原来数据的长度，如果返回0，可能目标空间不够
int fromBase64_Decode(const char* pSrc, int nLenSrc, char* pDst, int nLenDst);


#endif // ADOBETHUMBNAIL_H_INCLUDED
