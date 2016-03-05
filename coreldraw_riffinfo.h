// coreldraw_riffinfo.h

#ifndef CORELDRAW_RIFFINFO_H_INCLUDED
#define CORELDRAW_RIFFINFO_H_INCLUDED

#include <windows.h>
#include <stdio.h>

#pragma warning(disable: 4996)

//  'ABCD' == FCC('DCBA')    数字(ch4)反序
#define FCC(ch4) ((((DWORD)(ch4) & 0xFF) << 24) |     \
                  (((DWORD)(ch4) & 0xFF00) << 8) |    \
                  (((DWORD)(ch4) & 0xFF0000) >> 8) |  \
                  (((DWORD)(ch4) & 0xFF000000) >> 24))

#define RIFF_HEADER FCC('RIFF')
#define CDr9_TYPE   FCC('CDr9')    // RIFF....CDr9vrsn   CorelDRAW 9 简体中文版

#define CDR8_TYPE   FCC('CDR8')
#define CDR9_TYPE   FCC('CDR9')
#define CDRA_TYPE   FCC('CDRA')    // CorelDRAW 10  文件类型
#define CDRB_TYPE   FCC('CDRB')
#define CDRC_TYPE   FCC('CDRC')
#define CDRD_TYPE   FCC('CDRD')    // CorelDRAW X3 (13) 文件类型

#define CDRE_TYPE   FCC('CDRE')    // CorelDRAW X4  文件类型 , 开始使用 PK文件头 zip打包
#define CDRF_TYPE   FCC('CDRF')    // CorelDRAW X5
#define CDRG_TYPE   FCC('CDRG')    // CorelDRAW X6



// 00000000h: 52 49 46 46 C4 AE 00 00 43 44 72 39 76 72 73 6E ; RIFF漠..CDr9vrsn
// 00000010h: 02 00 00 00 84 03 44 49 53 50 2C 28 00 00 08 00 ; ...._DISP__....
#pragma pack(2)
typedef struct coreldraw_riff_head {
    FOURCC  riff;       // 必须为 'RIFF'
    DWORD   cb;     // CorelDRAW 数据文件大小
    DWORD   file_type;  // 一般为 'CDR?'
/*----------------------------------------*/
    FOURCC  vrsn;  // 'vrsn'
    DWORD   ver_cb;
    WORD   version; // CorelDRAW  版本，一般 2字节
} RIFF_CDR_TYPE;

#pragma pack(pop)
typedef struct _riffchunk {
    FOURCC  fcc;
    DWORD   cb;
} RIFFCHUNK, * LPRIFFCHUNK;

// 获得 CorelDRAW X3文件 为止的版本号
int get_cdrfile_version(const char* cdr_filename);

// 获得 CorelDRAW X3文件 为止 cdr_filename  展开缩略图 bmp_filename
bool cdr_riff_disp2bmp(const char* cdr_filename, const char* bmp_filename);

#endif // CORELDRAW_RIFFINFO_H_INCLUDED
