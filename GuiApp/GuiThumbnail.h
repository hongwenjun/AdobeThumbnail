#ifndef GUITHUMBNAIL_H_INCLUDED
#define GUITHUMBNAIL_H_INCLUDED

#include "../atpch.h"


extern "C" {
#define UNICODE 1
#include "Everything.h"

//    int EVERYTHINGAPI Everything_GetResultFullPathNameA(int nIndex,LPSTR buf,int bufsize);
//    int EVERYTHINGAPI Everything_GetResultFullPathNameW(int nIndex,LPWSTR wbuf,int wbuf_size_in_wchars);

}


// 执行提取缩略图 主功能
bool GuiThumbnail(const wchar_t* keyWord , const wchar_t* savePath);

// 临时PNG显示文件
bool Thumbnail_TempPng(const wchar_t* src_filename , const wchar_t* tmppng);

#endif // GUITHUMBNAIL_H_INCLUDED
