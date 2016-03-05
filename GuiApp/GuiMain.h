#ifndef GUIMAIN_H_INCLUDED
#define GUIMAIN_H_INCLUDED

#include <windows.h>
#include  <shlobj.h>
#include <Setupapi.h>
#include "resource.h"
#include <fstream>

// 加载绚彩图形库，只放了头文件，库文件到 炫彩界面库 - 官方网站 : http://www.xcgui.com 下载
#include "xcgui.h"

#pragma warning(disable: 4996)


using namespace std;

// 读取和保存配置
void LoadConfigFile();
void SaveConfigFile();


// 选择一个文件
int   GetFilePath(HWND hWnd, char *szFile);
// 选择一个目录
int   GetPath(HWND hWnd, char *pBuffer);


// 事件响应
bool CALLBACK keyEditChange(HELE hEle, HELE hEventEle);
bool CALLBACK keyBtnClick(HELE hEle, HELE hEventEle);
bool CALLBACK pathBtnClick(HELE hEle, HELE hEventEle);
bool CALLBACK runBtnClick(HELE hEle, HELE hEventEle);
bool CALLBACK runBtnClick(HELE hEle, HELE hEventEle);
bool CALLBACK closeBtnClick(HELE hEle, HELE hEventEle);

BOOL CALLBACK MyEventListSelect(HELE hEle, HELE hEventEle, int id);

// 消息响应
BOOL CALLBACK MyEventList_RButtonUp(HELE hEle,UINT flags,POINT *pPt);
BOOL CALLBACK MyEventList_MouseDBClick(HELE hEle,POINT *pPt);




// 窗口布局
void InitXC_Window(HWINDOW& hWindow);

bool Everything_Start(void);
#endif // GUIMAIN_H_INCLUDED
