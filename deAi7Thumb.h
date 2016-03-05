#ifndef DEAI7THUMB_H_INCLUDED
#define DEAI7THUMB_H_INCLUDED
#include <string>
#include <windows.h>>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>

using std::string;


// Decode a Hex string.
string decodeHex(const byte* src, long srcSize);

// Decode an Illustrator thumbnail that follows after %AI7_Thumbnail.
string decodeAi7Thumbnail(const string& src);

// Create a PNM image from raw RGB data.
string makeBmp(size_t width, size_t height, const string& rgb);

// 解码 %AI7_Thumbnail: 信息到PNG文件
bool decode_Ai7Thumb_toPng(string& AI7Thumb, size_t width, size_t height, const char* pngfilename);

bool rgb_makeBmp_tofile(string& rgb, size_t width, size_t height, FILE* bmpfilename);




#endif // DEAI7THUMB_H_INCLUDED
