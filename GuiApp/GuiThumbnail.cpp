#include "GuiThumbnail.h"
#include <string.h>
#include <wchar.h>

// 执行提取缩略图 主功能
bool GuiThumbnail(const wchar_t* keyWord , const wchar_t* savePath)
{
    wchar_t src_filename[MAX_PATH] = {0};
    wchar_t thumb_filename[MAX_PATH] = {0};
    wchar_t wbuf[MAX_PATH] = {0};

    Everything_SetSearch(keyWord);
    bool EQRet =  Everything_Query(TRUE);

     if (EQRet == false) {
      return false;
     }

    // 如果没有目录建立，进入目录
    _wmkdir(savePath);
    _wchdir(savePath);

    // Display results. // 文件导出缩略图
    for (int i = 0 ; i < Everything_GetNumResults(); i++) {

        Everything_GetResultFullPathNameW(i, src_filename , MAX_PATH);

        // AI EPS INDD 文件导出缩略图
        wcscpy(thumb_filename, Everything_GetResultFileName(i));
        wcscat(thumb_filename, L"_T.jpg");
        bool ret = AdobeThumbnail_W(src_filename , thumb_filename);

        if (!ret) { // CorelDRAW CDR 文件导出缩略图
            wcscpy(thumb_filename, Everything_GetResultFileName(i));
            wcscat(thumb_filename, L"_T.png");
            ret = CorelThumbnail_W(src_filename, thumb_filename);
        }
    }
    return true;
}



// 临时PNG显示文件
bool Thumbnail_TempPng(const wchar_t* src_filename , const wchar_t* tmppng)
{
        bool ret = AdobeThumbnail_W(src_filename , tmppng);

        if (!ret) {
            ret = CorelThumbnail_W(src_filename, tmppng);
        }

    return ret;
}
