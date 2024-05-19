#include "GuiThumbnail.h"
#include "GuiMain.h"
#include <wchar.h>
#include <regex>
#include "xcgui.h"

// 全局变量
char ConfigFile[MAX_PATH] = {0};
WCHAR keyFile[MAX_PATH] =  L"";
WCHAR savePath[MAX_PATH] = L"D:\\Thumbs缩略图";

// 全局句柄
HWINDOW hWindow;
HELE  keyEdit, pathEdit, hList, hStatic;
HELE hPic1, hPic2, hPic3;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    Everything_Start();
    XInitXCGUI(); // 初始化

    extern char ConfigFile[MAX_PATH];
    GetAppDir(ConfigFile);
    strcat(ConfigFile, "/ACThumbs.ini");
    if (IsFileExist(ConfigFile))
        LoadConfigFile();

    hWindow = XWnd_CreateWindow(0, 0, 960, 600, L"Adobe AI EPS INDD PDF和CorelDRAW DWG 缩略图工具  版权所有 2013-2024 Hongwenjun (蘭雅)"); // 创建窗口
    if (hWindow) {
        // 设置图标
        HICON logo_hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_ICON1);
        XWnd_SetIcon(hWindow, logo_hIcon, false);
        InitXC_Window(hWindow); // 窗口布局

        XWnd_ShowWindow(hWindow, SW_SHOW); //显示窗口
        XRunXCGUI(); //运行
    }
    return 0;
}

// 读取和保存配置
void LoadConfigFile()
{
    wfstream wFile(ConfigFile, fstream::in);
    wFile.imbue(locale("chs"));
    wFile.getline(keyFile, MAX_PATH);
    wFile.getline(savePath, MAX_PATH);
    wFile.close();
}
void SaveConfigFile()
{
    wfstream wFile(ConfigFile, fstream::out);
    wFile.imbue(locale("chs"));
    wFile << keyFile << endl << savePath << endl;
    wFile.close();
}

// 文本框回写配置
bool edit_text(void)
{
    XEdit_GetText(keyEdit, keyFile, MAX_PATH);
    XEdit_GetText(pathEdit, savePath, MAX_PATH);
    return true;
}

// 窗口布局
void InitXC_Window(HWINDOW& hWindow)
{
//   XWnd_SetImage(hWindow, XImage_LoadFile(L"GuiBG.dll")); // 设置窗口背景图片

    // 创建编辑框
    keyEdit = XEdit_Create(1, 2, 300, 22, hWindow);
    pathEdit = XEdit_Create(410, 2, 241, 22, hWindow);

    // 读取配置到文本框
    XEdit_SetText(keyEdit, keyFile);
    XEdit_SetText(pathEdit, savePath);

    // 工具提示按钮
    HELE keyButton = XBtn_Create(306, 2, 98, 22,  L"关键字 --> 搜索", hWindow);
    XEle_EnableToolTips(keyButton, true);
    XEle_SetToolTips(keyButton, L"请输入关键字,用空格隔开");

    HELE pathButton = XBtn_Create(656, 2, 90, 32, L"选择目录", hWindow);
    XEle_EnableToolTips(pathButton, true);
    XEle_SetToolTips(pathButton, L"选择缩略图保存的目录");

    HELE runButton = XBtn_Create(656, 40, 90, 40, L"开始执行", hWindow);
    XEle_EnableToolTips(runButton, true);
    XEle_SetToolTips(runButton, L"开始执行提取缩略图");

    HELE closeButton = XBtn_Create(656, 88, 90, 32, L"保存关闭", hWindow);
    HELE removeButton = XBtn_Create(656, 128, 90, 32, L"清理缩略图", hWindow);



//    // 注册文本框输入事件
//    XEle_RegisterEvent(keyEdit, XE_EDIT_CHANGE, keyEditChange);

    // 注册按钮事件
    XEle_RegisterEvent(keyButton, XE_BNCLICK, keyBtnClick);
    XEle_RegisterEvent(pathButton, XE_BNCLICK, pathBtnClick);
    XEle_RegisterEvent(runButton, XE_BNCLICK, runBtnClick);
    XEle_RegisterEvent(closeButton, XE_BNCLICK, closeBtnClick);
    XEle_RegisterEvent(removeButton, XE_BNCLICK, removeBtnClick);

    //创建列表元素
    hList = XList_Create(1, 25, 650, 518, hWindow);

    //添加列表头
    XList_AddColumn(hList, 260, L"名称", 2);
    XList_AddColumn(hList, 260, L"路径", 2);
    XList_AddColumn(hList, 100, L"文件版本", 2);

    // 创建静态文本
    hStatic = XStatic_Create(1, 545, 650, 22, L"Adobe AI EPS INDD PDF和CorelDRAW DWG 缩略图工具  版权所有 2013-2024 Hongwenjun (蘭雅)", hWindow);

    XStatic_Create(760, 165, 160, 18, L"兰雅VBA代码分享 lyvba.com", hWindow);

    //创建图片元素
    hPic1 = XPic_Create(656, 225, 290, 315, hWindow);
    XPic_SetImage(hPic1, XImage_LoadFile(L"ACThumbs.png")); //设置显示图片

    hPic2 = XPic_Create(760, 5, 150, 150, hWindow);
    XPic_SetImage(hPic2, XImage_LoadFile(L"logo.jpg")); //设置显示图片

//    hPic3 = XPic_Create(654, 416, 128, 128, hWindow);
//    XPic_SetImage(hPic3, XImage_LoadFile(L"Thumbnail.dat")); //设置显示图片

    //注册列表元素项选择事件
    XEle_RegisterEvent(hList, XE_LIST_SELECT, MyEventListSelect);
    XEle_RegisterMessage(hList, XM_MOUSEDBCLICK, MyEventList_MouseDBClick);
    XEle_RegisterMessage(hList, XM_RBUTTONUP, MyEventList_RButtonUp);


    XEle_SetFocus(keyEdit, true);
}

// 事件响应

//bool CALLBACK keyEditChange(HELE hEle, HELE hEventEle)
//{
//    return true;
//}

bool CALLBACK keyBtnClick(HELE hEle, HELE hEventEle)
{
    wchar_t keyWord[MAX_PATH] = {0};
    XEdit_GetText(keyEdit, keyWord, MAX_PATH);

    Everything_SetSearch(keyWord);
    bool EQRet =  Everything_Query(TRUE);
    if (EQRet == false) {
        return false;
    }

    // 删除所有项目
    XList_DeleteAllItems(hList);

    const wchar_t* rs = L"(.+)(\\.(?:ai|AI|indd|INDD|Indd|eps|EPS|Eps|pdf|PDF|cdr|CDR|Cdr|dwg|DWG|Dwg|DWg|dWG))";  // 正则字符串，exp开始的单词
    std::wregex expression(rs);                   // 字符串传递给构造函数，建立正则表达式

    //添加列表项      // Display results.
    int id = 0;
    for (int i = 0 ; i < Everything_GetNumResults(); i++) {
        bool ret = std::regex_match((wchar_t*)Everything_GetResultFileName(i), expression);
        if (!ret) continue;
        //添加项
        XList_AddItem(hList, (wchar_t*)Everything_GetResultFileName(i), 0);
        //设置子项内容
        XList_SetItemText(hList, id++, 1, (wchar_t*)Everything_GetResultPath(i), 1);
//        XList_SetItemText(hList, i, 2, keyWord, 2);

    }

    wchar_t pText[MAX_PATH] = {0};
    wsprintfW(pText, L"匹配: %d 个文档(AI CDR EPS INDD PDF DWG格式), 鼠标双击: 打开文件，右键: 打开路径", id);
    XStatic_SetText(hStatic, pText);
    XWnd_RedrawWnd(hWindow, true);
    return true;

}

bool CALLBACK pathBtnClick(HELE hEle, HELE hEventEle)
{
    char buf[MAX_PATH];
    if (GetPath(NULL, buf))
        charToWCHAR(savePath, buf);
    XEdit_SetText(pathEdit, savePath);
    return true;
}

bool CALLBACK runBtnClick(HELE hEle, HELE hEventEle)
{
    // 从文本框获得参数
    edit_text();
    // // 执行提取缩略图 主功能
    bool ret = GuiThumbnail(keyFile, savePath);
    if (ret == false)
        return ret;

    // 打开文件夹
    ShellExecuteW(NULL, L"open", savePath, NULL, NULL, SW_SHOW);
    return ret;
}

bool CALLBACK closeBtnClick(HELE hEle, HELE hEventEle)
{
    // 文本框回写配置
    edit_text();

    SaveConfigFile();
    ExitProcess(0); // 退出程序
    return true;
}

// 清理缩略图目录下图片索引文件
bool CALLBACK removeBtnClick(HELE hEle, HELE hEventEle)
{
    int ret = MessageBoxW(NULL, savePath, L"目前只能手工清理", MB_OK);
    ShellExecuteW(NULL, L"open", savePath, NULL, NULL, SW_SHOW);

    return true;
}

// 选择的文件全名 和路径
wstring select_filename, select_filepath;

BOOL CALLBACK MyEventListSelect(HELE hEle, HELE hEventEle, int id)
{
    if (id < 0)
        return false;
    //hEle:列表元素句柄   //id:当前选择项索引
    select_filename = wstring(XList_GetItemText(hEle,  id, 1)) + L"\\" + XList_GetItemText(hEle,  id, 0);
    select_filepath = wstring(XList_GetItemText(hEle,  id, 1));


    XPic_SetImage(hPic1, XImage_LoadFile(L"")); //设置图片为空，释放图片文件

    wchar_t tmppng[MAX_PATH] = L"Thumbnail.png";
    bool flag = Thumbnail_TempPng(select_filename.c_str(), tmppng); // 生成新的临时预览图

    if (flag) {
        XPic_SetImage(hPic1, XImage_LoadFile(tmppng, true)); //设置显示图片
    }

    XWnd_RedrawWnd(hWindow, true);

    return true;
}

BOOL CALLBACK MyEventList_RButtonUp(HELE hEle, UINT flags, POINT* pPt)
{
    ShellExecuteW(NULL, L"open", select_filepath.c_str(), NULL, NULL, SW_SHOW);
    return false;
}


BOOL CALLBACK MyEventList_MouseDBClick(HELE hEle, POINT* pPt)
{

    ShellExecuteW(NULL, L"open", select_filename.c_str(), NULL, NULL, SW_SHOW);
    return false;
}


// 选择一个目录
int   GetPath(HWND hWnd, char* pBuffer)
{
    BROWSEINFO   bf;
    LPITEMIDLIST   lpitem;
    memset(&bf, 0, sizeof(BROWSEINFO));
    bf.hwndOwner = hWnd;
    bf.lpszTitle = L"选择路径 ";
    bf.ulFlags = BIF_RETURNONLYFSDIRS;   //属性你可自己选择
    lpitem = SHBrowseForFolder(&bf);
    if (lpitem == NULL)  //如果没有选择路径则返回   0
        return  0;

    //如果选择了路径则复制路径,返回路径长度

    SHGetPathFromIDListA(lpitem, pBuffer);
    return   lstrlen(pBuffer);
}

bool Everything_Start(void)
{
    Everything_SetSearch(L"Everything.exe");
    bool EQRet =  Everything_Query(TRUE);
    if (EQRet == false) {
      MessageBoxA(NULL, "请先运行Everything软件!\n本软件全盘搜索功能需要Everything SDK.", "Everything SDK", MB_OK);
      return EQRet;
    }

//    if (EQRet == false) {
//
//        STARTUPINFO si;
//        PROCESS_INFORMATION pi;
//        ZeroMemory(&si, sizeof(si));
//        si.cb = sizeof(si);
//        // 后台隐藏
//        si.dwFlags   =   STARTF_USESHOWWINDOW;
//        si.wShowWindow   =   SW_HIDE;
//        ZeroMemory(&pi, sizeof(pi));
//        // Start the child process.
//        CreateProcess(NULL, "Everything.exe", NULL, NULL, FALSE, 0,
//                      NULL, NULL, &si, &pi);
//    }

    return true;
}
