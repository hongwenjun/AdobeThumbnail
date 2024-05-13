#include "AdobeThumbnail.h"
#include "atpch.h"
#include <regex>

#define MBsize 1024*1024

bool AdobeThumbnail(const char* adobe_filename , const char* savejpeg_filename)
{
    string file_ext(adobe_filename);
    string rs = "(.+)(\\.(?:ai|AI|indd|INDD|Indd|eps|EPS|Eps|pdf|PDF))";  // 正则字符串，exp开始的单词
    std::regex expression(rs);                   // 字符串传递给构造函数，建立正则表达式
    bool ret = std::regex_match(file_ext, expression);
    if (!ret) {
        //      cout << "文件格式不对!\n";
        return ret ;
    }

    if (!IsFileExist(adobe_filename))
        return false ;     // 文件不存在


    char* pch = NULL;
    const char* flag = "pGImg:image";  // AI 和 Indd 稍微不同

    /// ************* 获取 ID或者AI文档 的预览图 **************** ///
    FILE* adobe_file = fopen(adobe_filename, "rb");
    if(NULL == adobe_file){
    //    MessageBoxA(NULL, adobe_filename, "错误File", MB_OK);
        return false;
    }
    size_t file_size = get_fileSize(adobe_filename); // 获得文件大小

    size_t bufsize = 1 * MBsize;        // AI 和EPS 预览图在开头，INDD文件在末位
    char* filebuf = new char[bufsize];  // 文件读到缓冲

    //  文件小于2M 整个文件读，否则遍历读最后2M
    if (file_size < bufsize) {
        bufsize = file_size;
        fread(filebuf, 1, bufsize, adobe_file);
        if (0xF5ED0606 == *(DWORD*)filebuf) { // indd 文件开头好像都这样
            pch = memfind(filebuf, flag , bufsize);   // INDD 可能不只一个预览图
            if ((pch != NULL))
                while ((pch != NULL) && (strlen(pch) < 10 * 1024))
                    pch = memfind(pch + 1, flag , bufsize - (pch - filebuf));

        } else
            pch = memfind(filebuf, flag , bufsize);

    } else {
        fread(filebuf, 1, bufsize, adobe_file);
//        00000000h: 06 06 ED F5 D8 1D 46 E5 BD 31 EF E7 FE 74 B7 1D ; ..眭?F褰1镧?
//        00000010h: 44 4F 43 55 4D 45 4E 54 01 70 0F 00 00 05 00 00 ; DOCUMENT.p......
        if (0xF5ED0606 == *(DWORD*)filebuf) { // indd 文件开头好像都这样
            fseek(adobe_file, (file_size - bufsize), SEEK_SET);
            fread(filebuf, 1, bufsize, adobe_file);

            pch = memfind(filebuf, flag , bufsize);   // INDD 可能不只一个预览图
            if ((pch != NULL))
                while ((pch != NULL) && (strlen(pch) < 10 * 1024))
                    pch = memfind(pch + 1, flag , bufsize - (pch - filebuf));

        } else
            pch = memfind(filebuf, flag , bufsize);   // AI 应该只有一个预览信息，
    }
    // 读取文件结束，关闭
    fclose(adobe_file);

    if (pch == NULL) {
        flag = "%AI7_Thumbnail:";
        size_t width, height, bitCount, Hexsize;
        char AI7_Thumbnail[64]; char BeginData[64]; char Hex_Bytes[64];

        pch = memfind(filebuf, flag , bufsize);
        // 检测到AI低版本预览图标记
        if (pch != NULL) {
            sscanf(pch, "%s %d %d %d\n%s %d %s\n", AI7_Thumbnail, &width, &height, &bitCount , BeginData, &Hexsize , Hex_Bytes);

            pch = memfind(filebuf, "Hex Bytes" , bufsize);
        }

        if (pch != NULL) {  // 解码 AI7_Thumbnail 为 图片
            char savepng_filename[MAX_PATH]={0};    // 源图是 BMP，保存png 失真少一点
            strncpy(savepng_filename , savejpeg_filename, strlen(savejpeg_filename) - 4);
            strcat(savepng_filename, ".png");

            string AI7Thumb(pch + 10 , Hexsize + 1);
            decode_Ai7Thumb_toPng(AI7Thumb , width, height , savepng_filename);
            delete[] filebuf; // 释放文件缓冲
            return true;
        }
    };

    if (pch == NULL)   ret = false;
    if (!ret) {  // 没有找到，返回前
        delete[] filebuf; // 释放文件缓冲
        return ret;
    }


    strtok(pch, "\r\n");
    string Base64_str(pch);

    std::regex ex("pGImg:image>|<\\/x\\wpGImg:image>|pGImg:image=\"");
    std::regex en("&#xA;");
    // 正则删除 xmpGImg 标记和 转意换行替换回来
    Base64_str = std::regex_replace(Base64_str, ex, string(""));
    Base64_str = std::regex_replace(Base64_str, en, string("\n"));

#if(AITEST)
        printf( "pGImg:image标记偏移: %d 在文件%s\n" , pch - filebuf , adobe_filename);
#endif
/// =============================== 解码一个Base64 的JPEG文件 ==============================////

    int b64len = Base64_str.size();
    int jpglen = fromBase64_Decode(Base64_str.c_str() , b64len , filebuf , b64len);

    FILE* jpeg_file = fopen(savejpeg_filename, "wb");
    fwrite(filebuf, 1 , jpglen , jpeg_file);


    delete[] filebuf; // 释放文件缓冲

    fclose(jpeg_file);

    return true;
}

bool  AdobeThumbnail_W(const wchar_t* adobe_filename ,const wchar_t* savejpeg_filename ){

    char fromfile[MAX_PATH] = {0};
    char tofile[MAX_PATH] = {0};
    WCHARTochar(fromfile, adobe_filename);
    WCHARTochar(tofile, savejpeg_filename);

    bool ret = AdobeThumbnail(fromfile, tofile);

//  printf("%d\t%s\n",ret, fromfile);

    return ret;

}


int toBase64_Encode(const char* pSrc, int nLenSrc, char* pDst, int nLenDst)
{
    int nDestLen = nLenDst;
    BOOL fRet = Base64Encode((BYTE*) pSrc, nLenSrc, pDst, &nDestLen,  ATL_BASE64_FLAG_NONE); // 可以选择编码是否分行
    if (!fRet) nDestLen = 0;
    return (nDestLen);
}

int fromBase64_Decode(const char* pSrc, int nLenSrc, char* pDst, int nLenDst)
{
    int nDestLen = nLenDst;
    BOOL fRet = Base64Decode((LPCSTR)pSrc, nLenSrc, (BYTE*)pDst, &nDestLen);
    if (!fRet) nDestLen = 0;
    return (nDestLen);
}
