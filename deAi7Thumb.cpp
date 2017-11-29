#include "deAi7Thumb.h"
#include <atlimage.h>


//! Utility function to convert the argument of any type to a string
template<typename T>
std::string toString(const T& arg)
{
    std::ostringstream os;
    os << arg;
    return os.str();
}

// Decode a Hex string.
string decodeHex(const byte* src, long srcSize)
{
//    00000030h: 00 01 02 03 04 05 06 07 08 09 10 10 10 10 10 10 ;
//    00000040h: 10 0D 0A 0B 0C 0D 0E 0F 10 10 10 10 10 10 10 10 ;
//    00000050h: 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 ;
//    00000060h: 10 10 0D 0A 0B 0C 0D 0E 0F 10 10 10 10 10 10 10 ;
    // create decoding table
    byte invalid = 16;
    byte decodeHexTable[256];
    for (long i = 0; i < 256; i++) decodeHexTable[i] = invalid;
    for (byte i = 0; i < 10; i++) decodeHexTable[static_cast<byte>('0') + i] = i;
    for (byte i = 0; i < 6; i++) decodeHexTable[static_cast<byte>('A') + i] = i + 10;
    for (byte i = 0; i < 6; i++) decodeHexTable[static_cast<byte>('a') + i] = i + 10;

    // calculate dest size
    long validSrcSize = 0;
    for (long srcPos = 0; srcPos < srcSize; srcPos++) {
        if (decodeHexTable[src[srcPos]] != invalid) validSrcSize++;
    }
    const long destSize = validSrcSize / 2;

    // allocate dest buffer
    string dest(destSize, '\0');

    // decode
    for (long srcPos = 0, destPos = 0; destPos < destSize; destPos++) {
        byte buffer = 0;
        for (int bufferPos = 1; bufferPos >= 0 && srcPos < srcSize; srcPos++) {
            byte srcValue = decodeHexTable[src[srcPos]];
            if (srcValue == invalid) continue;
            buffer |= srcValue << (bufferPos * 4);
            bufferPos--;
        }
        dest[destPos] = buffer;
    }

    return dest;
}


// Decode an Illustrator thumbnail that follows after %AI7_Thumbnail.
string decodeAi7Thumbnail(const string& src)
{
    const byte* colorTable = (BYTE*)src.c_str();
    const long colorTableSize = 256 * 3;
    if (src.size() < colorTableSize) {
//  Invalid size of AI7 thumbnail:  src.size()
        return string();
    }
    const byte* imageData = (BYTE*)src.c_str() + colorTableSize;
    const long imageDataSize = src.size() - colorTableSize;
    const bool rle = (imageDataSize >= 3 && imageData[0] == 'R' && imageData[1] == 'L' && imageData[2] == 'E');
    std::string dest;
    for (long i = rle ? 3 : 0; i < imageDataSize;) {
        byte num = 1;
        byte value = imageData[i++];
        if (rle && value == 0xFD) {
            if (i >= imageDataSize) {
//  Unexpected end of image data at AI7 thumbnail.
                return string();
            }
            value = imageData[i++];
            if (value != 0xFD) {
                if (i >= imageDataSize) {

//  Unexpected end of image data at AI7 thumbnail

                    return string();
                }
                num = value;
                value = imageData[i++];
            }
        }
        for (; num != 0; num--) {
            dest.append(reinterpret_cast<const char*>(colorTable + (3 * value)), 3);
        }
    }
    return string(reinterpret_cast<const char*>(dest.data()), static_cast<long>(dest.size()));
}


// Create a PNM image from raw RGB data.
string makeBmp(size_t width, size_t height, const string& rgb)
{
    const long expectedSize = static_cast<long>(width * height * 3);
    if (rgb.size() != expectedSize) {
        return string();
    }

    const std::string header = "P6\n" + toString(width) + " " + toString(height) + "\n255\n";
    const char* headerBytes = header.data();

    string dest(static_cast<long>(header.size() + rgb.size()) , '\0');
    std::copy(headerBytes, headerBytes + header.size(), dest.begin());
    std::copy(rgb.data(), rgb.data() + rgb.size(), dest.begin() + header.size());
    return dest;
}

bool rgb_makeBmp_tofile(string& rgb, size_t width, size_t height, const char* bmpfilename)
{
    const long expectedSize = static_cast<long>(width * height * 3);
    FILE* bmpfile = fopen(bmpfilename , "wb");
    if ((rgb.size() != expectedSize) || (bmpfile == NULL)) {
        fclose(bmpfile);
        return false;
    }

    // BMP格式文件头
    BITMAPFILEHEADER bmph = {0x4D42, 54 , 0, 0, 54 };   // 14字节 'BM' 文件头
    BITMAPINFOHEADER bmpinf = {40, width, height, 1, 24, 0 , 0, 0, 0, 0, 0    }; // 40字节
    bmph.bfSize += rgb.size();

    fwrite(&bmph , 1, sizeof(bmph), bmpfile);
    fwrite(&bmpinf , 1, sizeof(bmpinf), bmpfile);

    // 由于前面解码的数据是RGB标准数据，而BMP存储为BGR顺序
    // 由于BMP写文件最下面先读写，要翻转
    for (size_t i = 0 ; i <= rgb.size() -2 ; i += 3) {
        std::swap(rgb[i] , rgb[i + 2]);
    }
    const char* px = rgb.c_str();
    for (size_t i = height  ; i > 0 ; i--) {
        fwrite(px + 3 * i * width  , 1 , 3 * width, bmpfile);
    }
    fclose(bmpfile);
    return true;
}

bool decode_Ai7Thumb_toPng(string& AI7Thumb, size_t width, size_t height, const char* pngfilename)
{

//        %AI7_Thumbnail: 76 128 8
//        %%BeginData: 14580 Hex Bytes
//        "%0000330000660000990000CC0033000033330033660033990033CC0033FF\n\r"
//        "%0066000066330066660066990066CC0066FF009900009933009966009999\n\r"
//        /*****  14580  Hex Bytes  *****/
//        "%82A783A8A7FDFCFFFDFCFFFDFCFFFDFCFFFDFCFFFD8EFFFF\n\r";

    string hexbin = decodeHex((BYTE*)AI7Thumb.c_str() , AI7Thumb.size());
    string srgb = decodeAi7Thumbnail(hexbin);

    const char* tmpBmpFile = "tmpBmp.bmp";
    // RGB 数据写bmp文件
    rgb_makeBmp_tofile(srgb, width, height, tmpBmpFile);

    CImage image;  //  bmp 转换 png ，需要CImage类，头文件  atlimage.h
    image.Load(tmpBmpFile);
    image.Save(pngfilename);

    if (remove(tmpBmpFile) != 0)
        perror("Error deleting file");

    return true;
}
