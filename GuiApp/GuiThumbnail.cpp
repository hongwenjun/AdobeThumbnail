#include "GuiThumbnail.h"
#include <string.h>
#include <wchar.h>

#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>

std::mutex mtx;

void processResult(int i)
{
    wchar_t src_filename[MAX_PATH] = {0};
    wchar_t thumb_filename[MAX_PATH] = {0};

    Everything_GetResultFullPathNameW(i, src_filename, MAX_PATH);

    // AI EPS INDD 文件导出缩略图
    wcscpy(thumb_filename, Everything_GetResultFileName(i));
    wcscat(thumb_filename, L"_T.jpg");
    bool ret = AdobeThumbnail_W(src_filename, thumb_filename);

    if (!ret) { // CorelDRAW CDR 文件导出缩略图
        wcscpy(thumb_filename, Everything_GetResultFileName(i));
        wcscat(thumb_filename, L"_T.png");
        ret = CorelThumbnail_W(src_filename, thumb_filename);
    }

    std::lock_guard<std::mutex> lock(mtx);
    // 在这里可以对处理结果进行进一步的处理或记录
}

// 执行提取缩略图 主功能
bool GuiThumbnail(const wchar_t *keyWord, const wchar_t *savePath)
{
    //    wchar_t src_filename[MAX_PATH] = {0};
    //    wchar_t thumb_filename[MAX_PATH] = {0};
    wchar_t wbuf[MAX_PATH] = {0};

    Everything_SetSearch(keyWord);
    bool EQRet = Everything_Query(TRUE);

    if (EQRet == false) {
        return false;
    }

    // 如果没有目录建立，进入目录
    _wmkdir(savePath);
    _wchdir(savePath);

    //    // 文件导出缩略图   改成多线程
    //    for (int i = 0 ; i < Everything_GetNumResults(); i++) {
    //
    //        Everything_GetResultFullPathNameW(i, src_filename , MAX_PATH);
    //
    //        // AI EPS INDD 文件导出缩略图
    //        wcscpy(thumb_filename, Everything_GetResultFileName(i));
    //        wcscat(thumb_filename, L"_T.jpg");
    //        bool ret = AdobeThumbnail_W(src_filename , thumb_filename);
    //
    //        if (!ret) { // CorelDRAW CDR 文件导出缩略图
    //            wcscpy(thumb_filename, Everything_GetResultFileName(i));
    //            wcscat(thumb_filename, L"_T.png");
    //            ret = CorelThumbnail_W(src_filename, thumb_filename);
    //        }
    //    }

    int numResults = Everything_GetNumResults();
    std::vector<std::thread> threads;

    for (int i = 0; i < numResults; i++) {
        threads.emplace_back(std::thread(processResult, i));
    }

    // 等待所有线程执行完毕
    std::for_each(threads.begin(), threads.end(), [](std::thread& t) {
        t.join();
    });

    return true;
}

// 临时PNG显示文件
bool Thumbnail_TempPng(const wchar_t *src_filename, const wchar_t *tmppng)
{
    bool ret = AdobeThumbnail_W(src_filename, tmppng);

    if (!ret) {
        ret = CorelThumbnail_W(src_filename, tmppng);
    }

    return ret;
}
