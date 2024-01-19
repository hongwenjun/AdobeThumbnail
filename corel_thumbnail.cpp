/*
** Copyright (C) http://srgb.googlecode.com  All rights reserved.
*/

#include "corel_thumbnail.h"
#include <regex>
#include <string>
#include <atlimage.h>
#define CASESENSITIVITY (0)
#define WRITEBUFFERSIZE (8192)

using std::string;

bool zip_extract_currentfile(unzFile uf, LPCTSTR save_filename)
{
    char szFilePathA[MAX_PATH];

    // 对于每个内部文件，可用 unzGetCurrentFileInfo64 来查内部文件名
    unz_file_info64 FileInfo;
    if (unzGetCurrentFileInfo64(uf, &FileInfo, szFilePathA, sizeof(szFilePathA), NULL, 0, NULL, 0) != UNZ_OK) {
        return false;
    }

//    printf("%s", szFilePathA);  // 在压缩文件中的 文件名

    // 对于非目录的内部文件，用 unzOpenCurrentFile打开
    if (unzOpenCurrentFile(uf) != UNZ_OK) {
        return false;
    }

    HANDLE hFile = CreateFile(save_filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        return false;
    }


    // 然后 unzReadCurrentFile 读取文件内容，写入到真实文件中。
    // unzReadCurrentFile 返回 0 表示文件读取结束然后 unzReadCurrentFile 读取文件内容，写入到真实文件中。
    // unzReadCurrentFile 返回 0 表示文件读取结束

    char byBuffer[WRITEBUFFERSIZE];
    while (true) {
        int err = unzReadCurrentFile(uf, byBuffer, WRITEBUFFERSIZE);

        if (err < 0) {
            return false;
        } else if (err == 0) {
            break;
        } else {
            DWORD dwWritten = 0;

            if (!WriteFile(hFile, byBuffer, (DWORD)err, &dwWritten, NULL) || dwWritten != (DWORD)err) {
                return false;
            }
        }
    }

    CloseHandle(hFile);
    return true;
}



bool zip_extract_onefile(const char* zip_filename, const char* filename , const char* save_filename)
{
    // 解压先使用 zipOpen64 来打开一个 ZIP 文件
    unzFile uf = unzOpen64(zip_filename);

//    // 需要先使用 unzGetGlobalInfo64 来取得该文件的一些信息，来了解这个压缩包里一共包含了多少个文件，等等。
//    unz_global_info64 gi;
//
//    if (unzGetGlobalInfo64(uf, &gi) != UNZ_OK) {
//        return false;
//    }

    // 尝试zip文件中找到该文件szFileName。
    int err = UNZ_OK;
    if (unzLocateFile(uf, filename, CASESENSITIVITY) != UNZ_OK) {
//       printf("file %s not found in the zipfile\n", filename);
        return false;
    }

    if (!zip_extract_currentfile(uf, save_filename)) {
        return false;
    }

    unzClose(uf);
    return true;
}


// 查阅: http://www.cppblog.com/Streamlet/archive/2013/05/12/127368.html

/*  相关 API
 * 压缩相关：
 * zipOpen64   zipClose    zipOpenNewFileInZip zipCloseFileInZip   zipWriteInFileInZip
 *
 * 解压相关：
 * unzOpen64   unzClose    unzGetGlobalInfo64  unzGoToNextFile
 * unzGetCurrentFileInfo64 unzOpenCurrentFile  unzCloseCurrentFile unzReadCurrentFile
 *
 * 首先是压缩操作。使用 zipOpen64 来打开/创建一个 ZIP 文件，然后开始遍历要被放到压缩包中去的文件。
 * 针对每个文件，先调用一次 zipOpenNewFileInZip，然后开始读原始文件数据，使用 zipWriteInFileInZip 来写入到 ZIP 文件中去。
 * zipOpenNewFileInZip 的第三个参数是一个 zip_fileinfo 结构，该结构数据可全部置零，其中 dosDate 可用于填入一个时间（LastModificationTime）。
 * 它的第二个参数是 ZIP 中的文件名，若要保持目录结构，该参数中可以保留路径，如 foo/bar.txt。
 *
 * 解压操作稍微复杂一点点。打开一个 ZIP 文件后，需要先使用 unzGetGlobalInfo64 来取得该文件的一些信息，来了解这个压缩包里一共包含了多少个文件，等等。
 * 目前我们用得着的就是这个文件数目。然后开始遍历 ZIP 中的文件，初始时自动会定位在第一个文件，以后处理完一个后用 unzGoToNextFile 来跳到下一个文件。
 * 对于每个内部文件，可用 unzGetCurrentFileInfo64 来查内部文件名。这个文件名和刚才 zipOpenNewFileInZip 的第二个参数是一样的形式，所以有可能包含路径。
 * 也有可能会以路径分隔符（/）结尾，表明这是个目录项（其实压缩操作的时候也可以针对目录写入这样的内部文件，上面没有做）。所以接下来要根据情况创建（多级）目录。
 * unzGetCurrentFileInfo64 的第三个参数是 unz_file_info64 结构，其中也有一项包含了 dosDate 信息，可以还原文件时间。
 * 对于非目录的内部文件，用 unzOpenCurrentFile，打开，然后 unzReadCurrentFile 读取文件内容，写入到真实文件中。unzReadCurrentFile 返回 0 表示文件读取结束。
 *
 */






bool cdr_extract_bmp(const char* cdr_filename, const char* bmp_filename)
{
    if (! IsFileExist(cdr_filename))
        return false ;

    bool ret = false;

    int version = get_cdrfile_version(cdr_filename);

//   printf("\n%d\n", version);

    if (version >= 1400 ){
        ret = zip_extract_onefile(cdr_filename, "metadata/thumbnails/thumbnail.bmp", bmp_filename);
        if (!ret)  ret = zip_extract_onefile(cdr_filename, "previews/thumbnail.png", bmp_filename);
        }

    if (version <= 1300)
        ret = cdr_riff_disp2bmp(cdr_filename, bmp_filename);

    return ret;

}

bool CorelThumbnail(const char* cdr_filename, const char* png_filename)
{

    string file_ext(cdr_filename);
    string rs = "(.+)(\\.(?:cdr|CDR|Cdr|CDr|cdR))";  // 正则字符串，exp开始的单词
    std::regex expression(rs);                   // 字符串传递给构造函数，建立正则表达式
    bool ret = regex_match(file_ext, expression);
    if (!ret) {
        //      cout << "文件格式不对!\n";
        return ret ;
    }

    char bmp_filename[MAX_PATH] = {0};

    if (png_filename == NULL) {
        char tmp_filename[MAX_PATH] = {0};
        png_filename = tmp_filename;
        strcpy(tmp_filename , cdr_filename);
        strcpy(strrchr(tmp_filename, '.') , ".png");
    }

    strcpy(bmp_filename , png_filename);
    strcpy(strrchr(bmp_filename, '.') , ".bmp");

//    printf("%s\t\%s\n", bmp_filename , png_filename);
    ret =  cdr_extract_bmp(cdr_filename , bmp_filename);

    if (!ret)
        return false ;

    CImage image;  //  bmp 转换 png ，需要CImage类，头文件  atlimage.h
    image.Load(bmp_filename);
    image.Save(png_filename);

    if (remove(bmp_filename) != 0)
        perror("Error deleting file");

    return ret;
}

bool CorelThumbnail_W(const wchar_t* cdr_filename, const wchar_t* png_filename)
{
    char fromfile[MAX_PATH] = {0};
    char tofile[MAX_PATH] = {0};
    WCHARTochar(fromfile, cdr_filename);
    WCHARTochar(tofile, png_filename);
    bool ret = CorelThumbnail(fromfile, tofile);
    return ret;
}


