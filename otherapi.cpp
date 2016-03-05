
#include "otherapi.h"


// 检查一个文件是否存在
BOOL IsFileExist(LPCTSTR lpFileName)
{
    WIN32_FIND_DATA fd = {0};
    HANDLE hFind = FindFirstFile(lpFileName, &fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        FindClose(hFind);
    }
    return ((hFind != INVALID_HANDLE_VALUE) && !(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}

// 获得文件大小
size_t get_fileSize(const char* filename)
{
    FILE* pfile = fopen(filename, "rb");
    fseek(pfile, 0 , SEEK_END);
    size_t size = ftell(pfile);
    fclose(pfile);
    return size;

}

// 功能 获得当前路径
char* GetAppDir(char* szPath)
{
    char* ret = szPath;
    GetModuleFileName(NULL, szPath, MAX_PATH); // 得到当前执行文件的文件名（包含路径）
    *(strrchr(szPath , '\\')) = '\0';   // 删除文件名，只留下目录
    return ret;
}

// 得到全路径文件的文件名
const char* GetFileBaseName(const char* szPath)
{
    const char* ret = szPath + strlen(szPath);
    while ((*ret != '\\') && (ret != (szPath - 1))) // 得到文件名
        ret--;
    ret++;
    return ret;
}


// 内存匹配函数memfind
char* memfind(const char* buf, const char* tofind, size_t len)
{
    size_t findlen = strlen(tofind);
    if (findlen > len) {
        return ((char*)NULL);
    }
    if (len < 1) {
        return ((char*)buf);
    }

    {
        const char* bufend = &buf[len - findlen + 1];
        const char* c = buf;
        for (; c < bufend; c++) {
            if (*c == *tofind) { // first letter matches
                if (!memcmp(c + 1, tofind + 1, findlen - 1)) { // found
                    return ((char*)c);
                }
            }
        }
    }

    return ((char*)NULL);
}


// 路径转宽字节
wchar_t* charToWCHAR(wchar_t* wch, const char* czs)
{
    MultiByteToWideChar(CP_ACP, 0, czs, -1, wch, MAX_PATH); // czs 转换到宽字节wch
    return wch;
}
char* WCHARTochar(char* czs , const wchar_t* wch)
{
    WideCharToMultiByte(CP_ACP, 0, wch, -1, czs, MAX_PATH , NULL, NULL);
    return czs;
}
