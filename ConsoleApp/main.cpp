#include "../atpch.h"
#include <string.h>

const char* version_info = "\nsRGB.googlecode.com   sRGB色彩联盟, 给你的工作增光添彩!\n\n"
                           "Adobe AI EPS INDD 缩略图收集工具  版权所有 2013.06 Hongwenjun (蘭公子)\n"
                           "CorelDRAW CDR文件 缩略图收集工具  版本代号：给力就能把思想转化成软件!\n\n"
                           ;

const char* srgb_zfb = "\n请捐赠sRGB色彩联盟开源项目，给力就能把思想转化成软件!\n"
                       "支付宝讨饭: http://me.alipay.com/srgb \n";

void helpinfo(const char* exefile)
{
    printf("%s\nUsage: %s  <Adobe文件.ai>   [SaveJpgFile]\n", version_info, exefile);
    printf("Usage: %s  <Corel文件.cdr>  [SavePngFile]\n", exefile);
}

// 全盘搜索模式导出缩略图
bool everything_thumbnail(const char* adobe_corel_filename , const char* save_thumbs_file);

int main(int argc , char* argv[])
{
    const char* adobe_corel_filename = "AICS5.ai";
    const char* save_thumbs_file = "save_thumbs.jpeg";
    char tmp_filename[MAX_PATH] = {0};

    if (argc >= 2) {
        adobe_corel_filename = argv [1];
        strcpy(tmp_filename , GetFileBaseName(adobe_corel_filename));
        strcat(tmp_filename , ".Thumb.jpg");
        save_thumbs_file = tmp_filename;
    }

    if (argc >= 3)
        strcpy(tmp_filename , argv [2]);

    // 没有参数，全盘搜索模式导出缩略图
    if (argc == 1) {
        everything_thumbnail(adobe_corel_filename , save_thumbs_file);
        return 88;
    }

    // AI EPS INDD 文件导出缩略图
    bool ret = AdobeThumbnail(adobe_corel_filename , save_thumbs_file);   // 执行
    if (!ret)   // CorelDRAW CDR 文件导出缩略图
        ret = CorelThumbnail(adobe_corel_filename, save_thumbs_file);

    if (!ret)
        helpinfo(argv[0]);
    return 0;
}


bool everything_thumbnail(const char* adobe_corel_filename , const char* save_thumbs_file)
{
    char tmp_filename[MAX_PATH] = {0};
    char app_path[MAX_PATH] = {0};
    GetAppDir(app_path);

    printf("%s\n", version_info);
    printf("全盘搜索模式开启: 请输入搜索信息关键字，调用Everything搜索文件.\n"
           "示例1:  2013  画册 \t"  "示例2:  VIP客户 设计\t"  "示例3:  C:\\印刷厂 \n\n"
           "输入您的关键字: ");

    string es_cmd;
    getline(std::cin , es_cmd);

    char es_exe_file[MAX_PATH] = {0};
    strcpy(es_exe_file, app_path);
    strcat(es_exe_file, "\\es.exe ");

    system("rd /s /q .\\Thumbs");
    system("md .\\Thumbs");

    es_cmd = string(es_exe_file) + " " + es_cmd + " > filelist.txt";

    int es_err = system(es_cmd.c_str());
    if (es_err == 0) {
        string filename_line;
        string filename_out;

        std::ifstream infile("filelist.txt");
        while (getline(infile, filename_line)) {
            adobe_corel_filename = filename_line.c_str();
            strcpy(tmp_filename , GetFileBaseName(adobe_corel_filename));
            filename_out = string("./Thumbs/") + tmp_filename + ".Thumb.jpg";
            save_thumbs_file = filename_out.c_str();

            // AI EPS INDD 文件导出缩略图
            bool ret = AdobeThumbnail(adobe_corel_filename , save_thumbs_file);

            if (!ret) { // CorelDRAW CDR 文件导出缩略图
                char savepng_filename[MAX_PATH] = {0};   // 源图是 BMP，保存png 失真少一点
                strncpy(savepng_filename , save_thumbs_file, strlen(save_thumbs_file) - 4);
                strcat(savepng_filename, ".png");
                ret = CorelThumbnail(adobe_corel_filename, savepng_filename);
            }

            if (ret)  putchar('.');
        }
    } else {
        printf("\a全盘搜索模式需要调用软件: Everything\n\n请看使用说明 第5行.\n\n");
        system("pause");
        return false;
    }

    printf("\n%s\n", srgb_zfb);
    system("pause");
    string start_Thumbs_path = string("%SystemRoot%\\explorer.exe ") + app_path + string("\\Thumbs");
    system(start_Thumbs_path.c_str());
    return true;
}
