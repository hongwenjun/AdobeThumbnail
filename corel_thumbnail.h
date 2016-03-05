/*
** Copyright (C) http://srgb.googlecode.com  All rights reserved.
*/


#ifndef COREL_THUMBNAIL_H_INCLUDED
#define COREL_THUMBNAIL_H_INCLUDED

#include <windows.h>

#include "coreldraw_riffinfo.h"
#include "otherapi.h"
#include "ZLib/zip.h"
#include "ZLib/unzip.h"

// 从zip文件 zip_filename 里，抽取一个文件filename，另存为 save_filename
bool zip_extract_onefile(const char* zip_filename, const char* filename , const char* save_filename);


// CorelDRAW 文件 cdr_filename  展开缩略图 bmp_filename
bool cdr_extract_bmp(const char* cdr_filename, const char* bmp_filename);

// CorelDRAW文件 cdr_filename  的缩略图 ，转换成 PNG文件 png_filename
// 如果 png_filename 为 NULL， 转换的PNG文件，基本名同 cdr_filename
bool CorelThumbnail(const char* cdr_filename, const char* png_filename);
bool CorelThumbnail_W(const wchar_t* cdr_filename, const wchar_t* png_filename);


#endif // COREL_THUMBNAIL_H_INCLUDED
