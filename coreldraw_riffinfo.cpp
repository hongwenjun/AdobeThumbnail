 #include "coreldraw_riffinfo.h"



// 00000000h: 52 49 46 46 C4 AE 00 00 43 44 72 39 76 72 73 6E ; RIFF漠..CDr9vrsn
// 00000010h: 02 00 00 00 84 03 44 49 53 50 2C 28 00 00 08 00 ; ...._DISP__....

// 读RIFF_CDR_TYPE 文件头和软件版本号
RIFF_CDR_TYPE cdr_riff ;

// 获得 CorelDRAW X3文件 为止的版本号
int get_cdrfile_version(const char* cdr_filename)
{
    FILE* cdr_pfile = fopen(cdr_filename , "rb");
    if (cdr_pfile == NULL)
        return -1;     // 文件不能读 返回 -1

    fread(&cdr_riff , 1 , sizeof(cdr_riff) , cdr_pfile);

    if ('PK' == FCC(cdr_riff.riff << 16)){
       fseek(cdr_pfile,0,SEEK_END);
       cdr_riff.cb = ftell(cdr_pfile) -8;
       cdr_riff.version = 1400;

 //      printf("CDR文件版本X4或者以上，暂时没有去写区分程序，所以不能精确识别!\n\a");
        }

 //   printf("%d\t%d\t%d\n", sizeof(cdr_riff), cdr_riff.version, cdr_riff.cb);

    fclose(cdr_pfile);
    return cdr_riff.version;
}

// CorelDRAW 13版本之前文件 cdr_filename  展开缩略图 bmp_filename
bool cdr_riff_disp2bmp(const char* cdr_filename, const char* bmp_filename)
{

    FILE* cdr_pfile = fopen(cdr_filename , "rb");

    fread(&cdr_riff , 1 , sizeof(cdr_riff) , cdr_pfile);

    // 检索 DISP_chunk 的数据是bmp缩略图数据
    RIFFCHUNK disp_chunk;
    fread(&disp_chunk , 1 , sizeof(disp_chunk) , cdr_pfile);
    // 跳过非 DISP 数据区
    while (FCC('DISP') != disp_chunk.fcc && !feof(cdr_pfile)) {

        fseek(cdr_pfile, disp_chunk.cb, SEEK_CUR);
        fread(&disp_chunk , 1 , sizeof(disp_chunk) , cdr_pfile);
    }


    // DISP_chunk 的数据是bmp缩略图数据，前面加10字节放 用来放'BM'文件头
    size_t raw_size = disp_chunk.cb;
    if (FCC('DISP') == disp_chunk.fcc) {

        char* bmp_buf = new char[raw_size + 10];
        fread(bmp_buf + 10, 1, raw_size , cdr_pfile);
        for (int i = 0 ; i != 12 ; i++)
            bmp_buf[i] = '\0';

        *(WORD*)bmp_buf = MAKEWORD('B', 'M') ; // BMP 文件头

        WORD* pBitCount = (WORD*)(bmp_buf + 0x1C);
        if (*pBitCount == 8) {
            bmp_buf[10] = 0x36;   // 256色索引图像,位图数据在文件中的
            bmp_buf[11] = 0x04;   // 起始位置 0x3604

        } else if (*pBitCount == 4) {
            bmp_buf[10] = 0x76;   // 16色索引
        } else if (*pBitCount == 1) {
            bmp_buf[10] = 0x3E;   // 黑白颜色
        } else if (*pBitCount == 24) {
            bmp_buf[10] = 0x36;   // 24位 位图，碰不到
        }

        DWORD* bmpsize = (DWORD*)(bmp_buf + 2);
        *bmpsize = raw_size + 10;

        FILE* bmp_dispfile;
        bmp_dispfile = fopen(bmp_filename , "wb");
        fwrite(bmp_buf, 1, raw_size + 10, bmp_dispfile);
        fclose(bmp_dispfile);
        delete[] bmp_buf;

    } else
        return false;

    fclose(cdr_pfile);
    return true;
}


