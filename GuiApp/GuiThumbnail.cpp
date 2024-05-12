#include "GuiThumbnail.h"
#include <string.h>
#include <wchar.h>
#include <thread>

void processFile(const std::wstring& srcFile, const std::wstring& thumbFile)
{
    // AI EPS INDD 文件导出缩略图
    bool ret = AdobeThumbnail_W(srcFile.c_str(), thumbFile.c_str());
    // CorelDRAW CDR 文件导出缩略图
    if (!ret)
        ret = CorelThumbnail_W(srcFile.c_str(), thumbFile.c_str());

    // 可以在此处添加处理成功或失败的逻辑
    if (!ret){
      char bad_File[MAX_PATH] = "001_Bad_Filelist.txt";
      FILE * pf =  fopen(bad_File, "a+");
      WCHARTochar(bad_File, srcFile.c_str());
      fprintf(pf, "Name: %s\n", bad_File);
      fclose(pf);
    }
}

// 执行提取缩略图 主功能
bool GuiThumbnail(const wchar_t* keyWord, const wchar_t* savePath)
{
    wchar_t src_filename[MAX_PATH] = {0};
    wchar_t thumb_filename[MAX_PATH] = {0};

    Everything_SetSearch(keyWord);
    if (false == Everything_Query(TRUE))
        return false;

    std::vector<std::wstring> vec_files;
    std::vector<std::wstring> vec_names;
    const wchar_t* rs = L"(.+)(\\.(?:ai|AI|indd|INDD|Indd|eps|EPS|Eps|pdf|PDF|cdr|CDR|Cdr))";  // 正则字符串，exp开始的单词
    std::wregex expression(rs);                   // 字符串传递给构造函数，建立正则表达式

    for (int i = 0 ; i < Everything_GetNumResults(); i++) {
        bool ret = std::regex_match((wchar_t*)Everything_GetResultFileName(i), expression);
        if (ret) {
            Everything_GetResultFullPathNameW(i, src_filename, MAX_PATH);
            vec_files.push_back(src_filename);
            vec_names.push_back((wchar_t*)Everything_GetResultFileName(i));
        }
    }

    // 如果没有目录建立，进入目录
    _wmkdir(savePath);
    _wchdir(savePath);

//    // 文件导出缩略图
//    for (int i = 0 ; i != vec_files.size(); i++) {
//        wcscpy(src_filename, vec_files[i].c_str());
//        wcscpy(thumb_filename, vec_names[i].c_str());
//        wcscat(thumb_filename, L"_T.jpg");
//        // AI EPS INDD 文件导出缩略图
//        bool ret = AdobeThumbnail_W(src_filename, thumb_filename);
//        if (!ret)  // CorelDRAW CDR 文件导出缩略图
//            ret = CorelThumbnail_W(src_filename, thumb_filename);
//    }

    const int trn = 8;
    std::vector<std::thread> threads;

    while (vec_files.size() > trn) {
        for (int i = 0; i < trn; i++) {
            const std::wstring& srcFilename = vec_files[i];
            const std::wstring& thumbFilename = vec_names[i] + L"_T.jpg";
            threads.emplace_back(std::thread(processFile, srcFilename, thumbFilename));
        }
        // 等待所有线程执行完毕
        for (auto& trd : threads) trd.join();

        threads.clear();
        vec_files.erase(vec_files.begin(), vec_files.begin() + trn);
        vec_names.erase(vec_names.begin(), vec_names.begin() + trn);
    }

    for (int i = 0; i < vec_files.size(); i++) {
        const std::wstring& srcFilename = vec_files[i];
        const std::wstring& thumbFilename = vec_names[i] + L"_T.jpg";
        threads.emplace_back(std::thread(processFile, srcFilename, thumbFilename));
    }
    // 等待所有线程执行完毕
    for (auto& trd : threads) trd.join();

    return true;
}

// 临时PNG显示文件
bool Thumbnail_TempPng(const wchar_t* src_filename, const wchar_t* tmppng)
{
    bool ret = AdobeThumbnail_W(src_filename, tmppng);
    if (!ret)
        ret = CorelThumbnail_W(src_filename, tmppng);
    return ret;
}
