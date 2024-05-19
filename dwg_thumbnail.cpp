#include "dwg_thumbnail.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>
#include <string>
#include <atlimage.h>

using std::string;

bool dwg_getbmp(const char *dwgfile, const char *thumb_bmpfile) {
  FILE *fd = fopen(dwgfile, "rb");
  if (fd == NULL) {
//    fprintf(stderr, "无法打开文件\n");
    return false;
  }

  fseek(fd, 13, SEEK_SET);
  unsigned int sentinel_pos;
  fread(&sentinel_pos, sizeof(unsigned int), 1, fd);
  // printf("Hex: %X\n", sentinel_pos);

  const int SIZE_SN = 39;

  char buf[SIZE_SN] = {0};
  unsigned char SN[] = {0x1F, 0x25, 0x6D, 0x07, 0xD4, 0x36, 0x28, 0x28,
                        0x9D, 0x57, 0xCA, 0x3F, 0x9D, 0x44, 0x10, 0x2B};
  fseek(fd, sentinel_pos, SEEK_SET);
  fread(buf, SIZE_SN, 1, fd);

  bool isdwg = true;
  for (int i = 0; i != 16; i++) {
    isdwg &= ((unsigned char)buf[i] == SN[i]);
  }

//  if (isdwg && buf[20] == 2) {
//    for (int i = 0; i != sizeof(buf); i++)
//      printf("%0.2X ", buf[i] & 0xFF);
//  } else {
//    return false;
//  }

  if (!isdwg && buf[20] != 2)
    return false;

  int data_size;
  memcpy(&data_size, &buf[35], sizeof(int));

  int pos;
  memcpy(&pos, &buf[31], sizeof(int));

  // printf("\ndata_size: 0x%0.4X", data_size);
  // printf("\npos: 0x%0.4X\n", pos);

  char *bmp_buf = new char[data_size];
  memset(bmp_buf, 0, data_size);

  fseek(fd, pos, SEEK_SET);
  if (fread(bmp_buf, 1, data_size, fd) != data_size) {
//    fprintf(stderr, "读取失败\n");
    delete[] bmp_buf;
    fclose(fd);
    return false;
  }

  FILE *bmp_file = fopen(thumb_bmpfile, "wb");
  if (bmp_file == NULL) {
//    fprintf(stderr, "无法创建文件\n");
    delete[] bmp_buf;
    fclose(fd);
    return false;
  }
  struct _BITMAP_HEADER {
    char magic[2];
    int file_size;
    int reserved;
    int offset;
  } bmp_h;

  /* Write bmp file header */
  bmp_h.magic[0] = 'B';
  bmp_h.magic[1] = 'M';
  bmp_h.file_size = 14 + data_size; // file header + DIB data
  bmp_h.reserved = 0;
  bmp_h.offset = 14 + 40 + 4 * 256; // file header + DIB header + color table

  // 写 BMP 文件头
  fwrite(&bmp_h.magic[0], sizeof(char), 2, bmp_file);
  fwrite(&bmp_h.file_size, 4, 3, bmp_file);

  // 写bmp 图片数据
  fwrite(bmp_buf, 1, data_size, bmp_file);

  // printf ("Success. Written thumbnail image to '%s'\n", thumb_bmpfile);

  delete[] bmp_buf;
  fclose(fd);
  fclose(bmp_file);
  return true;
}

bool DWGThumbnail(const char* dwg_filename, const char* png_filename)
{
    string file_ext(dwg_filename);
    string rs = "(.+)(\\.(?:dwg|DWG|Dwg|DWg|dWG))";
    std::regex expression(rs);
    bool ret = regex_match(file_ext, expression);
    if (!ret) {
        return ret ;
    }

    FILE* pfile = fopen(dwg_filename, "rb");
    if(NULL == pfile){
   //   MessageBoxA(NULL, cdr_filename, "错误File", MB_OK);
      return false;
    }

    char temp_filename[128];
    const char* tmpBmpFile =  tmpnam(temp_filename);
    strcat(temp_filename,".bmp");

    ret =  dwg_getbmp(dwg_filename , tmpBmpFile);

    if (!ret)
        return false ;

    CImage image;  //  bmp 转换 png ，需要CImage类，头文件  atlimage.h
    image.Load(tmpBmpFile);
    image.Save(png_filename);

    if (remove(tmpBmpFile) != 0)
        perror("Error deleting file");

    return ret;
}

bool DWGThumbnail_W(const wchar_t* dwg_filename, const wchar_t* png_filename)
{
    char fromfile[MAX_PATH] = {0};
    char tofile[MAX_PATH] = {0};
    WCHARTochar(fromfile, dwg_filename);
    WCHARTochar(tofile, png_filename);
    bool ret = DWGThumbnail(fromfile, tofile);
    return ret;
}


