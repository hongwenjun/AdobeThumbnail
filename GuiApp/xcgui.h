/**************************************************************************\
*
* Copyright (c)  炫彩界面库. All Rights Reserved.
*
* 炫彩界面库 - 官方网站 : http://www.xcgui.com
*
\**************************************************************************/

//v1.5.3

#include <docobj.h> //当DLL文件使用该头文件时,需取消注释
#include <exdispid.h>

#ifndef XCGUI_HEADER_FILE_
#define XCGUI_HEADER_FILE_

// 用户自定义消息范围     WM_USER -  0x7000
// 炫彩内部自定义消息范围 0x7001  -  0x7FFF


#define XC_API

//接口类型

/// @defgroup groupObjectType 接口句柄类型
/// @ingroup macroDefine
/// @{
//窗口:
#define  XC_WINDOW         1   ///<窗口
#define  XC_MODALWINDOW    2   ///<模态窗口
#define  XC_FRAMEWND       3   ///<框架窗口
#define  XC_FLOATWND       4   ///<浮动窗口

//元素 :
#define  XC_ELE            20  ///<元素
#define  XC_BUTTON         21  ///<按钮
#define  XC_RADIO          22  ///<单选按钮
#define  XC_CHECK          23  ///<复选按钮元素
#define  XC_EDIT           24  ///<编辑框元素
#define  XC_RICHEDIT       25  ///<富文本编辑框
#define  XC_COMBOBOX       26  ///<下拉组合框元素
#define  XC_SCROLLBAR      27  ///<滚动条元素
#define  XC_SCROLLVIEW     28  ///<滚动视图元素
#define  XC_LIST           29  ///<列表元素
#define  XC_LISTBOX        30  ///<列表框元素
#define  XC_TREE           31  ///<树元素
#define  XC_MENUBAR        32  ///<菜单条
#define  XC_PROPERTYPAGE   33  ///<属性页
#define  XC_SLIDERBAR      34  ///<滑动条
#define  XC_PROGRESSBAR    35  ///<进度条
#define  XC_TOOLBAR        36  ///<工具条
#define  XC_STATIC         37  ///<静态文本元素
#define  XC_GROUPBOX       38  ///<组框
#define  XC_PICTURE        39  ///<图片元素
#define  XC_MONTHCAL       40  ///<月历元素
#define  XC_DATETIME       41  ///<时间元素
#define  XC_PROPERTYGRID   42  ///<属性网格
#define  XC_CHOOSECOLOR    43  ///<颜色选择元素
#define  XC_OUTLOOK        44  ///<测试内容
#define  XC_TEXTLINK       45  ///<链接文本
#define  XC_TABBAR         46  ///<TabBar
#define  XC_GIF            47  ///<GIF动画
#define  XC_EDITFILE       48  ///<文件选择编辑框
#define  XC_LISTVIEW       49  ///<列表视图,大图标
#define  XC_PANE           50  ///<布局窗格
#define  XC_DRAGBAR        51  ///<布局窗格拖动分割条

#define  XC_SCROLLVIEW_VIEW     52  ///<滚动视图元素的视


#define  XC_MENUBAR_BUTTON        60  ///<菜单条上的按钮
#define  XC_TOOLBAR_BUTTON        61  ///<工具条上按钮
#define  XC_PROPERTYPAGE_LABEL    62  ///<属性页标签按钮


#define  XC_ARRAY          70  ///<数组操作
#define  XC_STRING         71  ///<字符串操作
#define  XC_IMAGELIST      72  ///<图片列表
#define  XC_MENU           73  ///<弹出菜单
#define  XC_IMAGE          74  ///<图片操作
#define  XC_HDRAW          75  ///<绘图操作
#define  XC_FONT           76  ///<炫彩字体

#define  XC_PIER           102  ///<窗格停靠码头
#define  XC_PANE_CELL      103  

///@}



//特殊按钮:
#define XC_BUTTON_MIN     201  //最小化窗口按钮
#define XC_BUTTON_MAX     202  //最大化窗口按钮
#define XC_BUTTON_CLOSE   203  //关闭窗口按钮

//#define XC_BUTTON_HSCROLLBAR_SLIDER   104  //水平滚动条,滑块按钮
//#define XC_BUTTON_VSCROLLBAR_SLIDER   105  //垂直滚动条,滑块按钮
//#define XC_BUTTON_HSCROLLBAR_LEFT     106  //水平滚动条,左滚动按钮
//#define XC_BUTTON_HSCROLLBAR_RIGHT    107  //水平滚动条,右滚动按钮
//#define XC_BUTTON_VSCROLLBAR_TOP      108  //垂直滚动条,上滚动按钮
//#define XC_BUTTON_VSCROLLBAR_BOTTOM   109  //垂直滚动条,下滚动按钮
#define XC_BUTTON_SLIDERBAR_SLIDER    210  //滑动条,滑块按钮
//#define XC_BUTTON_COMBOBOX_POP        111  //组合框下拉列表弹出按钮
//#define XC_BUTTON_PROPERTYPAGE_LEFT   112  //属性页,左滚动按钮
//#define XC_BUTTON_PROPERTYPAGE_RIGHT  113  //属性页,右滚动按钮
//#define XC_BUTTON_PROPERTYPAGE_LABEL  114  //属性页,标签按钮
//#define XC_BUTTON_DATETIME_POP        115  //日期时间元素,弹出选择卡片按钮



///输入输出///////////////////
#define in_
#define out_
#define in_out_


#ifdef _DEBUG
#define DECLARE_HANDLEX(name) struct name##__ { int unused; }; typedef struct name##__ *name
#else
#define	DECLARE_HANDLEX(name) typedef void* name
#endif


//接口句柄类型

/// @defgroup groupHandle 句柄列表
/// @ingroup macroDefine
/// @{
typedef void*  HXCGUI;    ///<资源句柄
DECLARE_HANDLEX(HWINDOW); ///<窗口资源句柄
DECLARE_HANDLEX(HELE);    ///<元素资源句柄
DECLARE_HANDLEX(HMENUX);  ///<菜单资源句柄
DECLARE_HANDLEX(HSTRING); ///<字符串资源句柄
DECLARE_HANDLEX(HDRAW);   ///<图形绘制资源句柄
DECLARE_HANDLEX(HARRAY);  ///<数组资源句柄
DECLARE_HANDLEX(HIMAGE);  ///<图片资源句柄
DECLARE_HANDLEX(HXMLRES); ///<XML资源句柄
DECLARE_HANDLEX(HARRAY_ITERATOR); ///<数组迭代器
DECLARE_HANDLEX(HFONTX);    ///<炫彩字体句柄

DECLARE_HANDLEX(HPANE_GROUP); ///<窗格组句柄
///@}


/// @defgroup groupImageDrawType 图片绘制类型
/// @ingroup macroDefine
/// @{
#define XC_IMAGE_DEFAULT  0  ///<默认
#define XC_IMAGE_STRETCH  1  ///<拉伸
#define XC_IMAGE_ADAPTIVE 2  ///<自适应
#define XC_IMAGE_TILE     3  ///<平铺

///@}

//状态--------------------------------------
/// @defgroup groupButtonState 按钮状态
/// @ingroup macroDefine
/// @{
#define  STATE_LEAVE   0   ///<离开
#define  STATE_DOWN    1   ///<按下
#define  STATE_STAY    2   ///<停留
#define  STATE_SELECT  3   ///<选择,保留

///@}


//窗口样式----------------------------

/// @defgroup groupWindowStyle 炫彩窗口样式
/// @ingroup macroDefine
/// @{
#define  XC_SY_MINIMIZE   0x00000001  ///<最小化窗口按钮
#define  XC_SY_MAXIMIZE   0x00000002  ///<最大化窗口按钮
#define  XC_SY_CLOSE      0x00000004  ///<关闭窗口按钮
#define  XC_SY_CAPTION    0x00000008  ///<标题栏
#define  XC_SY_BORDER     0x00000010  ///<边框
#define  XC_SY_ROUND      0x00000020  ///<圆角窗口
#define  XC_SY_CENTER     0x00000040  ///<窗口居中

#define  XC_SY_DRAG_BORDER 0x00000080  ///<拖动窗口边框
#define  XC_SY_DRAG_WINDOW 0x00000100  ///<拖动窗口
#define  XC_SY_DRAW_CAPTION_ICON  0x00000200 ///<绘制窗口标题栏图标
#define  XC_SY_DRAW_CAPTION_TITLE 0x00000400 ///<绘制窗口标题栏文本

///窗口默认样式 1791
#define  XC_SY_DEFAULT (XC_SY_MINIMIZE | \
	XC_SY_MAXIMIZE | \
	XC_SY_CLOSE | \
	XC_SY_CAPTION | \
	XC_SY_BORDER | \
	XC_SY_ROUND | \
	XC_SY_CENTER | \
	XC_SY_DRAG_BORDER | \
	XC_SY_DRAW_CAPTION_ICON | \
	XC_SY_DRAW_CAPTION_TITLE)

///模态窗口
#define  XC_SY_MODAL_WINDOW (XC_SY_CLOSE | \
	XC_SY_CAPTION | \
	XC_SY_BORDER | \
	XC_SY_ROUND | \
	XC_SY_DRAW_CAPTION_ICON | \
	XC_SY_DRAW_CAPTION_TITLE)

///@}

//透明窗口
/// @defgroup groupWindowTransparent 炫彩窗口透明标识
/// @ingroup macroDefine
/// @{
#define XC_WIND_TRANSPARENT_NO       0 ///<默认窗口,不透明
#define XC_WIND_TRANSPARENT_SHAPED   1 ///<透明窗口,带透明通道,异型.
#define XC_WIND_TRANSPARENT_SHADOW   2 ///<阴影窗口,带透明通道,边框阴影,窗口透明或半透明.
#define XC_WIND_TRANSPARENT_SIMPLE   4 ///<透明窗口,不带透明通道,指定半透明度,指定透明色.
#define XC_WIND_TRANSPARENT_WIN7     8 ///<WIN7玻璃窗口,需要WIN7开启特效,当前未启用.

///@}

//弹出消息框类型
/// @defgroup groupMessageBox 弹出消息框
/// @ingroup macroDefine
/// @{
#define  XMB_OK       1  ///<确定按钮
#define  XMB_CANCEL   2  ///<取消按钮

///@}

//增加元素------------------------------------------------
/// @defgroup groupAddElement 添加元素
/// @ingroup macroDefine
/// @{
#define  XC_ADDELE_END      0    ///<增加到末尾
#define  XC_ADDELE_FRIST    1    ///<增加到第一位置
#define  XC_ADDELE_BEFORE   2    ///<增加到指定元素前面
#define  XC_ADDELE_AFTER    3    ///<增加到指定元素后面
#define  XC_ADDELE_INDEX    4    ///<增加到指定位置索引

///@}

//设置元素Z序-----------------------
/// @defgroup groupSetZOrder 元素Z序
/// @ingroup macroDefine
/// @{
#define XC_ZORDER_TOP     0  ///<最上面
#define XC_ZORDER_BOTTOM  1  ///<最下面
#define XC_ZORDER_BEFORE  2  ///<指定元素在目标元素下面
#define XC_ZORDER_AFTER   3  ///<指定元素在目标元素上面
#define XC_ZORDER_INDEX   4  ///<指定索引位置

///@}

//按钮图标对齐方式
/// @defgroup groupIconAlign 按钮图标对齐方式
/// @ingroup macroDefine
/// @{
#define XC_ICON_ALIGN_LEFT     0  ///<图标在左边
#define XC_ICON_ALIGN_TOP      1  ///<图标在顶部
#define XC_ICON_ALIGN_RIGHT    2  ///<图标在右边
#define XC_ICON_ALIGN_BOTTOM   3  ///<图标在底部

///@}

//滚动条
/// @defgroup groupScrollBar 滚动条
/// @ingroup macroDefine
/// @{
#define  SY_HSCROLL     TRUE   ///<水平滚动条
#define  SY_VSCROLL     FALSE  ///<垂直滚动条

///@}

//树元素
/// @defgroup groupTree 列表树元素
/// @ingroup macroDefine
/// @{
#define  XTREE_INSERT_BEGIN  -2  ///<插入当前层开始
#define  XTREE_INSERT_LAST   -1  ///<插入当前层末尾

#define  XTREE_ROOT  0       ///<根节点

///@}

//基于二叉树的多叉树根节点ID
#define  XMTREE_ROOT   -1            //根节点ID
//弹出菜单根节点ID
#define  XMENU_ROOT    XMTREE_ROOT   //根节点ID

/// @defgroup groupMenu 弹出菜单
/// @ingroup macroDefine
/// @{

//弹出菜单项标识
///@name 弹出菜单项标识
///@{
#define  XM_SELECT      1   ///<选择
#define  XM_DISABLED    2   ///<禁用
#define  XM_CHECK       4   ///<勾选
#define  XM_POPUP       8   ///<弹出
#define  XM_SEPARATOR   16  ///<分隔栏 ID号任意,ID号被忽略

///@}

//弹出菜单方向
///@name 弹出菜单方向
///@{
#define  XM_LEFT_TOP       0   ///<左上角
#define  XM_LEFT_BOTTOM    1   ///<左下角
#define  XM_RIGHT_TOP      2   ///<右上角
#define  XM_RIGHT_BOTTOM   3   ///<右下角
#define  XM_CENTER_LEFT    4   ///<左居中
#define  XM_CENTER_TOP     5   ///<上居中
#define  XM_CENTER_RIGHT   6   ///<右居中
#define  XM_CENTER_BOTTOM  7   ///<下居中

///@}

//菜单ID--------------------------------------
///@name 菜单ID
///@{
#define  IDM_CLIP          1000000000    ///<剪切
#define  IDM_COPY          1000000001    ///<复制
#define  IDM_PASTE         1000000002    ///<粘贴
#define  IDM_DELETE        1000000003    ///<删除
#define  IDM_SELECTALL     1000000004    ///<全选
#define  IDM_DELETEALL     1000000005    ///<清空

///@}

//窗格菜单
///@name 窗格菜单
///@{
#define  IDM_LOCK          1000000006    ///<锁定
#define  IDM_DOCK          1000000007    ///<停靠
#define  IDM_FLOAT         1000000008    ///<浮动
#define  IDM_HIDE          1000000009    ///<隐藏

///@}


///@}

//属性网格元素,项类型
/// @defgroup groupPropertyGrid 属性网格元素
/// @ingroup macroDefine
/// @{

///@name 项类型
///@{
#define  PGRID_STRING       0  ///<默认,字符串类型
#define  PGRID_EDIT         1  ///<编辑框
#define  PGRID_COMBOBOX     2  ///<组合框
#define  PGRID_CHOOSECOLOR  3  ///<颜色选择元素
#define  PGRID_EDIT_FILE    4  ///<文件选择编辑框
///@}

///@}

enum align_type_
{
	align_any=1,
	align_left,
	align_top,
	align_right,
	align_bottom,
	align_group_member, //组成员
};

//窗格状态
enum pane_state_
{
	pane_state_any=0,
	pane_state_lock,
	pane_state_dock,
	pane_state_float,
	pane_state_hide,
};

//窗口消息
/**
@addtogroup wndMSG

<hr>
<h2>Windows 标准消息</h2>
- @ref WM_PAINT 窗口绘制消息
- @ref WM_CLOSE 窗口关闭消息.
- @ref WM_DESTROY 窗口销毁消息.
- @ref WM_NCDESTROY 窗口非客户区销毁消息.
- @ref WM_MOUSEMOVE 窗口鼠标移动消息.
- @ref WM_LBUTTONDOWN 窗口鼠标左键按下消息
- @ref WM_LBUTTONUP 窗口鼠标左键弹起消息.
- @ref WM_RBUTTONDOWN 窗口鼠标右键按下消息.
- @ref WM_RBUTTONUP 窗口鼠标右键弹起消息.
- @ref WM_MOUSEWHEEL 窗口鼠标滚轮滚动消息.
- @ref WM_EXITSIZEMOVE 窗口退出移动或调整大小模式循环改，详情参加MSDN.
- @ref WM_MOUSELEAVE 窗口鼠标离开消息.
- @ref WM_SIZE 窗口大小改变消息.
- @ref WM_TIMER 窗口定时器消息.
- @ref WM_SETFOCUS 窗口获得焦点.
- @ref WM_KILLFOCUS 窗口失去焦点.
- @ref WM_KEYDOWN 窗口键盘按键消息.
- @ref WM_CAPTURECHANGED 窗口鼠标捕获改变消息.
- @ref other 其他Windows系统消息,包含你自定义的Windows消息.

<hr>
@anchor WM_PAINT WM_PAINT 窗口绘制消息
@code   BOOL CALLBACK WndDrawWindow(HWINDOW hWindow,HDRAW hDraw); @endcode
@param  hWindow 窗口句柄.
@param  hDraw   图形绘制句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_CLOSE WM_CLOSE 窗口关闭消息.
@code   BOOL CALLBACK WndClose(HWINDOW hWindow); @endcode
@param  hWindow 窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_DESTROY WM_DESTROY 窗口销毁消息.
@code   BOOL CALLBACK WndDestroy(HWINDOW hWindow);  @endcode
@param  hWindow 窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_NCDESTROY WM_NCDESTROY 窗口非客户区销毁消息.
@code   BOOL CALLBACK WndNCDestroy(HWINDOW hWindow); @endcode
@param  hWindow 窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_MOUSEMOVE WM_MOUSEMOVE 窗口鼠标移动消息.
@code   BOOL CALLBACK WndMouseMove(HWINDOW hWindow,UINT flags,POINT *pPt);  @endcode
@param  hWindow 窗口句柄.
@param  flags   请参见MSDN WM_MOUSEMOVE wParam参数.
@param  pPt     鼠标坐标点.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_LBUTTONDOWN WM_LBUTTONDOWN 窗口鼠标左键按下消息
@code   BOOL CALLBACK WndLButtonDown(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow 窗口句柄.
@param  flags   请参见MSDN WM_LBUTTONDOWN.
@param  pPt     鼠标坐标点.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_LBUTTONUP WM_LBUTTONUP 窗口鼠标左键弹起消息.
@code   BOOL CALLBACK WndLButtonUp(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow 窗口句柄.
@param  flags   请参见MSDN WM_LBUTTONUP.
@param  pPt     鼠标坐标点.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_RBUTTONDOWN WM_RBUTTONDOWN 窗口鼠标右键按下消息.
@code   BOOL CALLBACK WndRButtonDown(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow 窗口句柄.
@param  flags   请参见MSDN WM_RBUTTONDOWN.
@param  pPt     鼠标坐标点.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_RBUTTONUP WM_RBUTTONUP 窗口鼠标右键弹起消息.
@code   BOOL CALLBACK WndRButtonUp(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow 窗口句柄.
@param  flags   请参见MSDN WM_RBUTTONUP.
@param  pPt     鼠标坐标点.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_MOUSEWHEEL WM_MOUSEWHEEL 窗口鼠标滚轮滚动消息.
@code   BOOL CALLBACK WndMouseWheel(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
@param  hWindow 窗口句柄.
@param  flags   请参见MSDN WM_MOUSEWHEEL消息wParam参数.
@param  pPt     鼠标坐标点.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_EXITSIZEMOVE WM_EXITSIZEMOVE 窗口退出移动或调整大小模式循环改，详情参加MSDN.
@code   BOOL CALLBACK WndExitSizeMove(HWINDOW hWindow); @endcode
@param  hWindow 窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_MOUSELEAVE WM_MOUSELEAVE 窗口鼠标离开消息.
@code   BOOL CALLBACK WndMouseLeave(HWINDOW hWindow); @endcode
@param  hWindow 窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_SIZE WM_SIZE 窗口大小改变消息.
@code   BOOL CALLBACK WndSize(HWINDOW hWindow,UINT flags,SIZE *pSize); @endcode
@param  hWindow 窗口句柄.
@param  flags   请参见MSDN WM_SIZE消息wParam参数.
@param  pSize   窗口大小.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_TIMER WM_TIMER 窗口定时器消息.
@code   BOOL CALLBACK WndTimer(HWINDOW hWindow,UINT_PTR nIDEvent,UINT uElapse); @endcode
@param  hWindow  窗口句柄.
@param  nIDEnent 定时器标示符.
@param  uElapse  指定所经过的系统启动以来的毫秒数,这是由GetTickCount函数的返回值.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_SETFOCUS WM_SETFOCUS 窗口获得焦点.
@code   BOOL CALLBACK WndSetFocus(HWINDOW hWindow); @endcode
@param  hWindow 窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_KILLFOCUS WM_KILLFOCUS 窗口失去焦点.
@code   BOOL CALLBACK WndKillFocus(HWINDOW hWindow); @endcode
@param  hWindow 窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor WM_KEYDOWN WM_KEYDOWN 窗口键盘按键消息.
@code   BOOL CALLBACK WndKeyDown(HWINDOW hWindow,WPARAM wParam,LPARAM lParam); @endcode
@param  hWindow 窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.
@note   wParam,lParam:请参见MSDN WM_KEYDOWN.

<hr>
@anchor WM_CAPTURECHANGED WM_CAPTURECHANGED 窗口鼠标捕获改变消息.
@code   BOOL CALLBACK WndCaptureChanged(HWINDOW hWindow,HWND hWnd); @endcode
@param  hWindow 窗口句柄.
@param  hWnd    获得鼠标捕获的窗口句柄.
@return 默认返回FALSE,如果终止消息传递返回TRUE.

<hr>
@anchor other 其他Windows系统消息,包含你自定义的Windows消息.
@code   BOOL CALLBACK WndOther(HWINDOW hWindow,WPARAM wParam,LPARAM lParam); @endcode
@param  hWindow 窗口句柄.
@param  wParam  消息参数.
@param  lParam  消息参数.
@return 默认返回FALSE,如果终止消息传递返回TRUE.
@note   参数信息请参见MSDN.
@{
*/

///@brief 鼠标单击窗口
///@code  BOOL CALLBACK WndMouseClick(HWINDOW hWindow,POINT *pPt); @endcode
#define  XWM_MOUSECLICK       0x7000+1 //wParam:x坐标, lParam:y坐标

///@brief 鼠标双击窗口
///@code  BOOL CALLBACK WndMouseDBClick(HWINDOW hWindow,POINT *pPt) @endcode
///@param hWindow 窗口句柄
///@param pPt     鼠标位置
#define  XWM_MOUSEDBCLICK     0x7000+2 //wParam:x坐标, lParam:y坐标

///@brief 重绘元素
///@code BOOL CALLBACK WndRedrawEle(HWINDOW hWindow,HELE hEle,RECT *pRect);  @endcode
#define  XWM_REDRAW_ELE       0x7000+3 //重绘元素 wParam:元素句柄, lParam:*

///@brief 菜单选择
///@code  BOOL CALLBACK WndMenuSelect(HWINDOW hWindow,int id); @endcode
#define  XWM_MENUSELECT       0x7000+4 //菜单选择 wParam:菜单项ID, lParam:0

///@brief 菜单退出
///@code  BOOL CALLBACK WndMenuExit(HWINDOW hWindow); @endcode
#define  XWM_MENUEXIT         0x7000+5 //菜单退出 wParam:0, lParam:0

///@brief 窗口字体改变
///@code  BOOL CALLBACK WndSetFont(HWINDOW hWindow);  @endcode
#define  XWM_SETFONT          0x7000+6 //窗口字体改变

//炫彩定时器
///@code  BOOL CALLBACK WndTimer2(HWINDOW hWindow,int timerID,int userData);  @endcode
#define  XWM_TIMER            0x7000+8 //wParam:, lParam:


#define  XWM_DRAW_T           0x7000+9  //窗口绘制,内部使用, wParam:0, lParam:0


///@}



//窗口非客户区消息-逻辑上的非客户区
/// @addtogroup wndNCMSG
/// 窗口非客户区消息-逻辑上的非客户区
/// @{

/// @brief 窗口非客户区绘制消息
/// @code  BOOL CALLBACK WndNCDrawWindow(HWINDOW hWindow,HDRAW hDraw); @endcode
/// @param hWindow 窗口句柄
/// @param hDraw   图形绘制句柄.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCPAINT         0  //wParam:HDC lParam:0

/// @brief 窗口绘制完成消息,在显示之前
/// @code  BOOL CALLBACK WndNCEndDrawWindow(HWINDOW hWindow,HDRAW hDraw); @endcode
/// @param hWindow 窗口句柄
/// @param hDraw   图形绘制句柄.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCENDPAINT      1  //wParam:HDC lParam:0       窗口绘制完成后调用,便于特效合成

/// @brief 窗口非客户区鼠标移动消息.
/// @code  BOOL CALLBACK WndNCMouseMove(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow 窗口句柄
/// @param flags   请参见msdn WM_MOUSEMOVE.
/// @param pPt     鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCMOUSEMOVE     2  //wParam:对应系统wParam lParam:坐标点

/// @brief 窗口非客户区鼠标左键按下消息.
/// @code  BOOL CALLBACK WndNCLButtonDown(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow 窗口句柄
/// @param flags   请参见msdn WM_LBUTTONDOWN.
/// @param pPt     鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCLBUTTONDOWN   3  //wParam:对应系统wParam lParam:坐标点

/// @brief 窗口非客户区鼠标左键弹起消息.
/// @code  BOOL CALLBACK WndNCLButtonUp(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow 窗口句柄
/// @param flags   请参见msdn MSDN WM_LBUTTONUP.
/// @param pPt     鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCLBUTTONUP     4  //wParam:对应系统wParam lParam:坐标点

/// @brief 窗口非客户区鼠标右键按下消息.
/// @code  BOOL CALLBACK WndNCRButtonDown(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow 窗口句柄
/// @param flags   请参见msdn MSDN WM_RBUTTONDOWN.
/// @param pPt     鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCRBUTTONDOWN   5  //wParam:对应系统wParam lParam:坐标点

/// @brief 窗口非客户区鼠标右键弹起消息.
/// @code  BOOL CALLBACK WndNCRButtonUp(HWINDOW hWindow,UINT flags,POINT *pPt); @endcode
/// @param hWindow 窗口句柄
/// @param flags   请参见msdn MSDN WM_RBUTTONUP.
/// @param pPt     鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCRBUTTONUP     6  //wParam:对应系统wParam lParam:坐标点

/// @brief 窗口非客户区鼠标左键点击消息.
/// @code  BOOL CALLBACK WndNCMouseClick(HWINDOW hWindow,POINT *pPt); @endcode
/// @param hWindow 窗口句柄
/// @param pPt     鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCMOUSECLICK    7  //wParam:坐标点 lParam:0    鼠标单击      非客户区

/// @brief 窗口非客户区鼠标左键双击消息.
/// @code  BOOL CALLBACK WndNCMouseDBClick(HWINDOW hWindow,POINT *pPt); @endcode
/// @param hWindow 窗口句柄
/// @param pPt     鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XWM_NCMOUSEDBCLICK  8  //wParam:坐标点 lParam:0    鼠标双击窗口  非客户区

///@}

//元素消息
/// @addtogroup eleMSG
/// @{

/// @brief 元素绘制消息.
/// @code  BOOL CALLBACK EleDraw(HELE hEle,HDRAW hDraw); @endcode
/// @param hEle 元素句柄.
/// @param hDraw 图形绘制句柄.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XM_PAINT          100   //wParam:hDraw,lParam:0

/// @brief 元素鼠标左键点击消息.
/// @code  BOOL CALLBACK EleMouseClick(HELE hEle,POINT *pPt); @endcode
/// @param hEle 元素句柄.
/// @param pPt  鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XM_MOUSECLICK     101   //鼠标单击  wParam:POINT坐标,lParam:0

/// @brief 元素鼠标左键双击消息.
/// @code  BOOL CALLBACK EleMouseDBClick(HELE hEle,POINT *pPt); @endcode
/// @param hEle 元素句柄.
/// @param pPt  鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XM_MOUSEDBCLICK   102   //鼠标双击  wParam:POINT坐标,lParam:0

/// @brief 元素鼠标移动消息.
/// @code  BOOL CALLBACK EleMouseMove(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle 元素句柄.
/// @param flags 请参见MSDN WM_MOUSEMOVE.
/// @param pPt   鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XM_MOUSEMOVE      103   //鼠标移动  wParam:标识, lParam:POINT坐标

/// @brief 元素鼠标左键按下消息.
/// @code  BOOL CALLBACK EleLButtonDown(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle 元素句柄.
/// @param flags 请参见MSDN WM_LBUTTONDOWN.
/// @param pPt   鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XM_LBUTTONDOWN    104   //wParam:标识, lParam:POINT坐标

/// @brief 元素鼠标左键弹起消息.
/// @code  BOOL CALLBACK EleLButtonUp(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle 元素句柄.
/// @param flags 请参见MSDN WM_LBUTTONUP.
/// @param pPt   鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XM_LBUTTONUP      105   //wParam:标识, lParam:POINT坐标

/// @brief 元素鼠标右键按下消息.
/// @code  BOOL CALLBACK EleRButtonDown(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle 元素句柄.
/// @param flags 请参见MSDN WM_RBUTTONDOWN.
/// @param pPt   鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XM_RBUTTONDOWN    106   //wParam:标识, lParam:POINT坐标

/// @brief 元素鼠标右键弹起消息.
/// @code  BOOL CALLBACK EleRButtonUp(HELE hEle,UINT flags,POINT *pPt); @endcode
/// @param hEle 元素句柄.
/// @param flags 请参见MSDN WM_RBUTTONUP.
/// @param pPt   鼠标坐标点.
/// @return 默认返回FALSE,如果终止消息传递返回TRUE.
#define  XM_RBUTTONUP      107   //wParam:标识, lParam:POINT坐标

//炫彩定时器
// BOOL (CALLBACK *pFunEleTimerEx)(HELE hEle,UINT timerID,int userData); //定时器消息 XWM_TIMER
#define  XM_TIMER          108


///@}

//元素事件
/// @addtogroup eleEvents
/// @{

/// @brief 元素销毁事件.
/// @code  void CALLBACK EventDestroy(HELE hEle); @endcode
/// @param hEle  元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_DESTROY        -1  //元素销毁 特殊事件

/// @brief 按钮元素点击事件.
/// @code  BOOL CALLBACK EventBtnClick(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_BNCLICK        0   //按钮点击事件,没有时间间隔 wParam:0, lParam:0

/// @brief 元素鼠标停留事件.
/// @code  BOOL CALLBACK EventMouseStay(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_MOUSESTAY      1   //鼠标停留  wParam:0,lParam:0

/// @brief 元素鼠标离开事件.
/// @code  BOOL CALLBACK EventMouseLeave(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_MOUSELEAVE     2   //鼠标离开  wParam:0,lParam:0

/// @brief 元素鼠标滚轮滚动事件.
/// @code  BOOL CALLBACK EventMouseWheel(HELE hEle,HELE hEventEle,UINT flags,POINT *pPt); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_MOUSEWHEEL     3   //鼠标滚轮  wParam:标识,lParam:POINT坐标

/// @brief 元素获得焦点事件.
/// @code  BOOL CALLBACK EventSetFocus(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_SETFOCUS       4   //获得焦点  wParam:0,lParam:0

/// @brief 元素失去焦点事件.
/// @code  BOOL CALLBACK EventKillFocus(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_KILLFOCUS      5   //失去焦点  wParam:0,lParam:0

/// @brief 元素按键事件.
/// @code  BOOL CALLBACK EventKeyDown(HELE hEle,HELE hEventEle,WPARAM wParam,LPARAM lParam); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
/// @note   wParam,lParam:请参见MSDN WM_KEYDOWN. 
#define  XE_KEYDOWN        6   //wParam和lParam参数与标准消息相同

/// @brief 通过TranslateMessage函数翻译的字符事件.
/// @code  BOOL CALLBACK EventChar(HELE hEle,HELE hEventEle,WPARAM wParam,LPARAM lParam); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
/// @note   wParam,lParam:请参见MSDN WM_KEYDOWN. 
#define  XE_CHAR           7   //wParam和lParam参见MSDN

/// @brief 水平滚动条元素滚动事件,滚动条触发.
/// @code  BOOL CALLBACK EventHScroll(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param pos         当前滚动点.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_HSCROLL        8   //水平滚动条滚动事件 wParam:滚动点,lParam:0 (滚动条触发)

/// @brief 垂直滚动条元素滚动事件,滚动条触发.
/// @code  BOOL CALLBACK EventVScroll(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param pos         当前滚动点.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_VSCROLL        9   //垂直滚动条滚动事件 wParam:滚动点,lParam:0 (滚动条触发)

/// @brief 滚动视图元素水平滚动事件,滚动视图触发.
/// @code  BOOL CALLBACK EventHScrollView(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param pos         当前滚动点.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_HSCROLLVIEW    10  //滚动视图 滚动事件 wParam:滚动点,lParam:0 (滚动视图触发,表明滚动视图已滚动完成)

/// @brief 滚动视图元素垂直滚动事件,滚动视图触发.
/// @code  BOOL CALLBACK EventVScrollView(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param pos         当前滚动点.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_VSCROLLVIEW    11  //滚动视图 滚动事件 wParam:滚动点,lParam:0 (滚动视图触发,表明滚动视图已滚动完成)

/// @brief 元素设置鼠标捕获事件.
/// @code  BOOL CALLBACK EventSetCapture(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_SETCAPTURE     12  //设置鼠标捕获  wParam:0,lParam:0

/// @brief 元素失去鼠标捕获事件.
/// @code  BOOL CALLBACK EventKillCapture(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_KILLCAPTURE    13  //失去鼠标捕获  wParam:0,lParam:0

/// @brief 弹出菜单项选择事件.
/// @code  BOOL CALLBACK EventMenuSelect(HELE hEle,HELE hEventEle,int id); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param id          菜单项id.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_MENUSELECT     14  //菜单项选择 wParam:菜单ID,lParam:0

/// @brief 弹出菜单退出事件.
/// @code  BOOL CALLBACK EventMenuExit(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_MENUEXIT       15  //菜单退出

/// @brief 元素大小改变事件.
/// @code  BOOL CALLBACK EventSize(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_SIZE           16  //元素大小位置改变,wParam:0,lParam:0

/// @brief 元素字体改变事件.
/// @code  BOOL CALLBACK EventSetFont(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_SETFONT        17  //元素字体改变事件,wParam:0,lParam:0

/// @brief 元素显示或隐藏事件.
/// @code  BOOL CALLBACK EventShow(HELE hEle,HELE hEventEle,BOOL bShow); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param bShow       如果元素显示TRUE,隐藏FALSE.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_SHOW            18   //wParam:TRUE或FALSE, lParam:0


/// @brief 列表元素,项选择事件.
/// @code  BOOL CALLBACK EventListSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index       选择项索引,如果是-1没有选择项.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_LIST_SELECT          50   //列表项选择, wParam:项index,如果是-1没有选择项, lParam:0

/// @brief 列表元素,列表头项点击事件.
/// @code  BOOL CALLBACK EventListHeaderClick(HELE hEle,HELE hEventEle,int id); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index          项索引.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_LIST_HEADER_CLICK    51   //列表头项点击,wParam:项index,   lParam:0

/// @brief 列表元素,列表头项宽度改变事件.
/// @code  BOOL CALLBACK EventListHeaderChange(HELE hEle,HELE hEventEle,int index,int width); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index       列表头项索引.
/// @param width       项宽度.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_LIST_HEADER_CHANGE   52   //列表头项宽度改变,wParam:项index, lParam:项宽度

/// @brief 树元素,项选择事件.
/// @code  BOOL CALLBACK EventTreeSelect(HELE hEle,HELE hEventEle,int id); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param id          选择项id,如果是-1没有选择项.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_TREE_SELECT          53   //树项选择,  wParam:选择项id,如果是-1没有选择项, lParam:0

/// @brief 树元素,项展开或收缩事件.
/// @code  BOOL CALLBACK EventTreeExpand(HELE hEle,HELE hEventEle,int id,BOOL bExpand); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param id          树项id.
/// @param bExpand     TRUE展开,FALSE收缩.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_TREE_EXPAND          54   //树项展开或收缩, wParam:项id; lParam:展开TRUE,收缩FALSE

/// @brief 组合框元素,组合框弹出下拉列表项选择事件.
/// @code  BOOL CALLBACK EventComboBoxSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index       选中项索引,如果-1没有选中项
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_COMBOBOX_SELECT      55   //下拉组合框选择事件,wParam:选择项索引,如果-1没有选择项, lParam:0

/// @brief 组合框元素,组合框下拉列表弹出事件.
/// @code  BOOL CALLBACK EventComboBoxPopupList(HELE hEle,HELE hEventEle,HWINDOW hWindow,HELE hListBox); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param hWindow     弹出窗口句柄.
/// @param hListBox    下拉列表句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define XE_COMBOBOX_POPUP_LIST   56 //组合框下拉列表弹出事件,wParam:弹出窗口句柄, lParam:listBox句柄

/// @brief 组合框元素,组合框弹出下拉列表退出事件.
/// @code  BOOL CALLBACK EventComboBoxExitList(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define XE_COMBOBOX_EXIT_LIST   57 //组合框弹出下拉列表关闭事件,wParam:0, lParam:0

/// @brief 属性页元素,标签项选择事件.
/// @code  BOOL CALLBACK EventPPageSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index       选择标签索引,如果-1没有选择标签.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_PPAGE_SELECT         58   //属性页标签选择,wParam:标签索引,如果-1没有选择标签, lParam:0

/// @brief TabBar元素,标签项选择事件.
/// @code  BOOL CALLBACK EventTabBarSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index       选择标签索引,如果-1没有选择标签.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_TABBAR_SELECT         58   //TabBar标签选择,wParam:标签索引,如果-1没有选择标签, lParam:0


/// @brief 滑动条元素,滑块位置改变事件.
/// @code  BOOL CALLBACK EventSliderChange(HELE hEle,HELE hEventEle,int pos); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param pos         滑块当前滑动位置点.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_SLIDER_CHANGE        59   //滑动条位置改变,wParam:滑块当前滑动位置点, lParam:0

//wParam:TRUE日期发生改变; FALSE:日期未改变,与先前日期一样, 
//lParam:在月历的第一视图,通过鼠标点击日期号(1-31)选择,为TRUE; 否则在月选择视图,或年选择视图都是FALSE;
/// @brief 月历元素,日期改变事件.
/// @code  BOOL CALLBACK EventMonthChange(HELE hEle,HELE hEventEle,BOOL bChange,BOOL bDownDayNum); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param bChange     TRUE日期发生改变; FALSE日期未改变,与先前日期一样.
/// @param bDownDayNum 在月历的第一视图,通过鼠标点击日期号(1-31)选择,为TRUE; 否则在月选择视图,或年选择视图都是FALSE;
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_MONTHCAL_CHANGE      60   //月历元素,日期改变事件,

/// @brief 日期编辑框元素,日期改变事件,日期格式为:年-月-日.
/// @code  BOOL CALLBACK EventDateTimeChange(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_DATETIME_CHANGE          61   //日期元素,日期改变事件,wParam:0,lParam:0

/// @brief 日期编辑框元素,弹出日期选择窗口事件.
/// @code  BOOL CALLBACK EventDateTimePopupMonthCal(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_DATETIME_POPUP_MONTHCAL  62  //日期元素 弹出日期选择窗口事件,wParam:0,lParam:0

/// @brief 日期编辑框元素,弹出日期选择窗口退出事件.
/// @code  BOOL CALLBACK EventDateTimeExitMonthCal(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_DATETIME_EXIT_MONTHCAL   63  //日期元素 弹出日期选择窗口退出事件,wParam:0,lParam:0

/// @brief 列表框元素,项选择事件.
/// @code  BOOL CALLBACK EventListBoxSelect(HELE hEle,HELE hEventEle,int index); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index       选择项的索引,如果是-1没有选择任何项.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_LISTBOX_SELECT       64   //列表框元素项选择,wParam:选择项索引,如果是-1没有选择项; lParam:0

/// @brief 属性网格元素,项选择改变事件.
/// @code  BOOL CALLBACK EventPGridSelChange(HELE hEle,HELE hEventEle,int prevID,int id); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param prevID      先前选择项id,如果是-1没有选择项.
/// @param id          当前选择项id,如果是-1没有选择项.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_PGRID_SELCHANGE      65   //属性网格 项选择改变, wParam:先前选择项id,如果是-1没有选择项; lParam:当前选择项id,如果是-1没有选择项

/// @brief 属性网格元素,项值改变事件.
/// @code  BOOL CALLBACK EventPGridValueChange(HELE hEle,HELE hEventEle,int id); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param id          项ID.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_PGRID_VALUECHANGE    66   //属性网格 项值改变事件, wParam:值改变的项id; lPara:0

/// @brief 列表视图元素,项选择事件.
/// @code  BOOL CALLBACK EventListViewSelect(HELE hEle,HELE hEventEle,int groupIndex,int itemIndex); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param id          项ID.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_LISTVIEW_SELECT      67 //列表视图元素,项选择事件, wParam:组索引,如果-1没有选择组, lParam:项索引，如果-1没有选择项

/// @brief 列表视图元素,组展开收缩事件
/// @code  BOOL CALLBACK EventListViewExpand(HELE hEle,HELE hEventEle,int groupIndex,BOOL bExpand); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param id          组ID.
/// @param bExpand     TRUE展开,FALSE收缩.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_LISTVIEW_EXPAND      68 //列表视图元素,组展开收缩事件, wParam:组索引; lParam:展开TRUE,收缩FALSE

/// @brief 列表视图元素,用户拖动项插入事件
/// @code  BOOL CALLBACK EventListViewDragInsert(HELE hEle,HELE hEventEle,listView_dragInsert_ *pInfo); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param pInfo       信息结构体.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_LISTVIEW_DRAG_INSERT 69  //wParam:listView_dragInsert_*; lParam:0

/// @brief 窗格锁定事件
/// @code  BOOL CALLBACK EventPaneLock(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define XE_PANE_LOACK     70   //wParam:0; lParam:0

/// @brief 窗格停靠到码头事件
/// @code  BOOL CALLBACK EventPaneDock(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_PANE_DOCK     80  //wParam:0; lParam:0

/// @brief 窗格浮动事件
/// @code  BOOL CALLBACK EventPaneFloat(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_PANE_FLOAT    81  //wParam:0; lParam:0


/// @brief 编辑框内容改变事件
/// @code  BOOL CALLBACK EventEditChange(HELE hEle,HELE hEventEle); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_EDIT_CHANGE 82  //wParam:0; lParam:0

/// @brief 下拉组合框元素,选择项正在改变.
/// @code  BOOL CALLBACK EventComboBoxSelecting(HELE hEle,HELE hEventEle,int index,BOOL *pBOOL); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index       选择项的索引,如果是-1没有选择任何项.
/// @param pBOOL       是否终止改变,TRUE终止.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_COMBOBOX_SELECT_ING  83  //wParam:index; lParam:pBOOL


/// @brief 列表框元素,项选择正在改变.
/// @code  BOOL CALLBACK EventListBoxSelecting(HELE hEle,HELE hEventEle,int index,BOOL *pBOOL); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param index       选择项的索引,如果是-1没有选择任何项.
/// @param pBOOL       是否终止改变,TRUE终止.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_LISTBOX_SELECT_ING       84   //列表框元素项选择,wParam:选择项索引,如果是-1没有选择项; lParam:pBOOL


/// @brief 树元素,项选择正在改变.
/// @code  BOOL CALLBACK EventTreeSelecting(HELE hEle,HELE hEventEle,int id,BOOL *pBOOL); @endcode
/// @param hEle        当前处理事件的元素句柄.
/// @param hEventEle   触发事件的元素句柄.
/// @param id          选择项id,如果是-1没有选择项.
/// @param pBOOL       是否终止改变,TRUE终止.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  XE_TREE_SELECT_ING         85   //树项选择,  wParam:选择项id,如果是-1没有选择项, lParam:pBOOL

///@}


#ifdef _DEBUG
#define XTRACE   xtrace
#define XTRACEW  xtracew
#define XERROR   XTRACE 
#define XERRORW  XTRACEW
#else
#define XTRACE
#define XTRACEW
#define XERROR 
#define XERRORW
#endif

#ifndef  GET_X_LPARAM
#define  GET_X_LPARAM(lp)   ((int)(short)LOWORD(lp))
#endif
#ifndef  GET_Y_LPARAM
#define  GET_Y_LPARAM(lp)   ((int)(short)HIWORD(lp))
#endif


///////////////////IE begin///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//IE事件:
///@defgroup IE_Event IE事件
///@details  注册IE事件,DWebBrowserEvents2接口事件,注册API: XWeb_RegEvent().
///@ingroup  msgAndEvents
///@{

/// @brief 在导航操作之前.
/// @code  BOOL CALLBACK IE_BeforeNavigate2(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl,in_ int Flags,in_ wchar_t *pTargetFrameName,in_ wchar_t *pPostData,in_ wchar_t *pHeaders,in_out_ VARIANT_BOOL *bCancel); @endcode
/// @param hWebBrowser 浏览器控件句柄.
/// @param pDisp   请参见MSDN.
/// @param pUrl    请参见MSDN.
/// @param Flags   请参见MSDN.
/// @param pTargetFrameName 请参见MSDN.
/// @param pPostData 请参见MSDN.
/// @param pHeaders 请参见MSDN.
/// @param bCancel TRUE取消导航操作，或FALSE允许进行导航操作。
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_BEFORENAVIGATE2     DISPID_BEFORENAVIGATE2    //BeforeNavigate2

/// @brief 请求操作,客户区窗口大小转换到宿主窗口大小.
/// @code  BOOL CALLBACK IE_ClientToHostWindow(HXCGUI hWebBrowser,in_out_ long *pCx,in_out_ long *pCy); @endcode
/// @param hWebBrowser 浏览器控件句柄.
/// @param pCx 接收和指定的客户端窗口的宽度.
/// @param pCy 接收和指定的客户端窗口的高度.
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_CLIENTTOHOSTWINDOW  DISPID_CLIENTTOHOSTWINDOW //ClientToHostWindow

/// @brief 启用状态的命令更改.
/// @code BOOL CALLBACK IE_CommandStateChange(HXCGUI hWebBrowser,in_ long command,in_ VARIANT_BOOL enable); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_COMMANDSTATECHANGE  DISPID_COMMANDSTATECHANGE //CommandStateChange  

/// @brief 一个文档完全加载和初始化.
/// @code BOOL CALLBACK IE_DocumentComplete(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_DOCUMENTCOMPLETE    DISPID_DOCUMENTCOMPLETE   //DocumentComplete

/// @brief 开始导航操作.
/// @code  BOOL CALLBACK IE_DownloadBegin(HXCGUI hWebBrowser); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_DOWNLOADBEGIN       DISPID_DOWNLOADBEGIN      //DownloadBegin 

/// @brief 导航操作完成时，停止或失败.
/// @code BOOL CALLBACK IE_DownloadComplete(HXCGUI hWebBrowser); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_DOWNLOADCOMPLETE    DISPID_DOWNLOADCOMPLETE   //DownloadComplete 

/// @brief 下载文件是即将发生.
/// @code BOOL CALLBACK IE_FileDownload(HXCGUI hWebBrowser,in_ VARIANT_BOOL ActiveDocument,in_out_ VARIANT_BOOL *Cancel); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_FILEDOWNLOAD        DISPID_FILEDOWNLOAD       //FileDownload

/// @brief 导航到一个链接,一个窗口元素或一个框架元素完成.
/// @code BOOL CALLBACK IE_NavigateComplete2(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_NAVIGATECOMPLETE2   DISPID_NAVIGATECOMPLETE2 //NavigateComplete2

/// @brief 在导航过程中发生错误时触发.
/// @code BOOL CALLBACK IE_NavigateError(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl,in_ wchar_t *pTargetFrameName,in_ int statusCode,in_out_ VARIANT_BOOL *bCancel); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_NAVIGATEERROR       DISPID_NAVIGATEERROR     //NavigateError

//       IE_NEWPROCESS          DISPID_NEWPROCESS        //NewProcess 找不到

/// @brief 创建一个新的窗口时触发.
/// @code BOOL CALLBACK IE_NewWindow2(HXCGUI hWebBrowser,in_out_ IDispatch **pDisp,in_out_ VARIANT_BOOL *bCancel); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_NEWWINDOW2          DISPID_NEWWINDOW2        //NewWindow2

/// @brief 创建一个新窗口时触发.
/// @code BOOL (CALLBACK *pFunIE_NewWindow3)(HXCGUI hWebBrowser,in_out_ IDispatch **pDisp,in_out_ VARIANT_BOOL *bCancel,in_ DWORD dwFlags,in_ wchar_t *pUrlContext,in_ wchar_t *pUrl); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_NEWWINDOW3          DISPID_NEWWINDOW3       //NewWindow3

/// @brief IWebBrowser2::FullScreen属性被改变时触发.
/// @code BOOL CALLBACK IE_OnFullScreen(HXCGUI hWebBrowser,in_ VARIANT_BOOL bFullScreen); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_ONFULLSCREEN        DISPID_ONFULLSCREEN     //OnFullScreen

/// @brief IWebBrowser2::MenuBar属性被改变时触发.
/// @code BOOL CALLBACK IE_OnMenuBar(HXCGUI hWebBrowser,in_ VARIANT_BOOL bMenuBar); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_ONMENUBAR           DISPID_ONMENUBAR        //OnMenuBar

/// @brief Internet Explorer的应用程序退出之前触发.
/// @code BOOL CALLBACK IE_OnQuit(HXCGUI hWebBrowser); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_ONQUIT              DISPID_ONQUIT           //OnQuit

/// @brief IWebBrowser2::StatusBar属性被改变时触发.
/// @code BOOL CALLBACK IE_OnStatusBar(HXCGUI hWebBrowser,in_ VARIANT_BOOL bStatusBar); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_ONSTATUSBAR         DISPID_ONSTATUSBAR      //OnStatusBar

/// @brief IWebBrowser2::TheaterMode属性被改变时触发.
/// @code BOOL CALLBACK IE_OnTheaterMode(HXCGUI hWebBrowser,in_ VARIANT_BOOL bTheaterMode); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_ONTHEATERMODE       DISPID_ONTHEATERMODE     //OnTheaterMode

/// @brief IWebBrowser2::ToolBar属性被改变时触发.
/// @code BOOL CALLBACK IE_OnToolBar(HXCGUI hWebBrowser,in_ VARIANT_BOOL bToolBar); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_ONTOOLBAR           DISPID_ONTOOLBAR         //OnToolBar

/// @brief IWebBrowser2::Visible属性被改变时触发.
/// @code BOOL CALLBACK IE_OnVisible(HXCGUI hWebBrowser,in_ VARIANT_BOOL bVisible); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_ONVISIBLE           DISPID_ONVISIBLE         //OnVisible

/// @brief 打印模板实例化时触发.
/// @code BOOL CALLBACK IE_PrintTemplateInstantiation(HXCGUI hWebBrowser,in_ IDispatch *pDisp); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_PRINTTEMPLATEINSTANTIATION DISPID_PRINTTEMPLATEINSTANTIATION //PrintTemplateInstantiation

/// @brief 打印模板被销毁时触发.
/// @code BOOL CALLBACK IE_PrintTemplateTeardown(HXCGUI hWebBrowser,in_ IDispatch *pDisp); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_PRINTTEMPLATETEARDOWN  DISPID_PRINTTEMPLATETEARDOWN  // PrintTemplateTeardown

/// @brief 当一个受影响的私有事件,或用户导航已经受影响的远程URL时发生.
/// @code  BOOL CALLBACK IE_PrivacyImpactedStateChange(HXCGUI hWebBrowser,in_ VARIANT_BOOL bPrivacyImpacted); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_PRIVACYIMPACTEDSTATECHANGE  DISPID_PRIVACYIMPACTEDSTATECHANGE //PrivacyImpactedStateChange

/// @brief 更新对象时触发的下载操作的进度.
/// @code  BOOL CALLBACK IE_ProgressChangee(HXCGUI hWebBrowser,in_ long Progress,in_ long ProgressMax); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_PROGRESSCHANGE       DISPID_PROGRESSCHANGE   //ProgressChange

/// @brief IWebBrowser2::PutProperty对象的方法改变属性值时触发.
/// @code  BOOL CALLBACK IE_PropertyChange(HXCGUI hWebBrowser,in_ wchar_t *pProperty); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_PROPERTYCHANGE       DISPID_PROPERTYCHANGE   //PropertyChange

//       IE_REDIRECTXDOMAINBLOCKED  DISPID_REDIRECTXDOMAINBLOCKED // RedirectXDomainBlocked 找不到

/// @brief 触发表明当前网页仿冒过滤分析微软的进度和状态。.
/// @code  BOOL CALLBACK IE_SetPhishingFilterStatus(HXCGUI hWebBrowser,in_ long phishingFilterStatus); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_SETPHISHINGFILTERSTATUS DISPID_SETPHISHINGFILTERSTATUS //SetPhishingFilterStatus

/// @brief 在加密级别的变化时触发.
/// @code  BOOL CALLBACK IE_SetSecureLockIcon(HXCGUI hWebBrowser,in_ signed int SecureLockIcon); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_SETSECURELOCKICON    DISPID_SETSECURELOCKICON  //SetSecureLockIcon

/// @brief 改变对象的状态栏文本时触发.
/// @code  BOOL CALLBACK IE_StatusTextChange(HXCGUI hWebBrowser,in_ wchar_t *pText); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_STATUSTEXTCHANGE     DISPID_STATUSTEXTCHANGE    //StatusTextChange

//       IE_THIRDPARTYURLBLOCKED DISPID_THIRDPARTYURLBLOCKED //ThirdPartyUrlBlocked 找不到

/// @brief 对象的文档的标题变为可用或改变时触发.
/// @code  BOOL CALLBACK IE_TitleChange(HXCGUI hWebBrowser,in_ wchar_t *pText); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_TITLECHANGE          DISPID_TITLECHANGE        //TitleChange

//UpdatePageStatus IE没有实现

/// @brief 该对象的窗口被关闭脚本时触发.
/// @code  BOOL CALLBACK IE_WindowClosing(HXCGUI hWebBrowser,in_ VARIANT_BOOL IsChildWindow,in_out_ VARIANT_BOOL *bCancel); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_WINDOWCLOSING       DISPID_WINDOWCLOSING      //WindowClosing

/// @brief 当对象改变其高度的触发.
/// @code  BOOL CALLBACK IE_WindowSetHeight(HXCGUI hWebBrowser,in_ long height); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_WINDOWSETHEIGHT     DISPID_WINDOWSETHEIGHT    //WindowSetHeight

/// @brief 当对象改变其左侧位置时触发.
/// @code  BOOL CALLBACK IE_WindowSetLeft(HXCGUI hWebBrowser,in_ long left); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_WINDOWSETLEFT       DISPID_WINDOWSETLEFT      //WindowSetLeft

/// @brief 发生指示宿主窗口是否应该允许调整对象.
/// @code  BOOL CALLBACK IE_WindowSetResizable(HXCGUI hWebBrowser,in_ VARIANT_BOOL bResizable); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_WINDOWSETRESIZABLE  DISPID_WINDOWSETRESIZABLE   //WindowSetResizable

/// @brief 当对象改变其顶部位置的触发.
/// @code  BOOL CALLBACK IE_WindowSetTop(HXCGUI hWebBrowser,in_ long top); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_WINDOWSETTOP        DISPID_WINDOWSETTOP    //WindowSetTop

/// @brief 当对象改变其宽度的触发.
/// @code  BOOL CALLBACK IE_WindowSetWidth(HXCGUI hWebBrowser,in_ long width); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_WINDOWSETWIDTH      DISPID_WINDOWSETWIDTH   //WindowSetWidth

/// @brief  当窗口内容的可见性状态，如浏览器窗口或选项卡，更改时触发.
/// @code   BOOL CALLBACK IE_WindowStateChanged(HXCGUI hWebBrowser,in_ DWORD dwFlags,in_ DWORD dwValidFlagsMask); @endcode
/// @return 默认返回FALSE,如果终止事件传递返回TRUE.
#define  IE_WINDOWSTATECHANGED  DISPID_WINDOWSTATECHANGED  //WindowStateChanged

///@}

//定义IE外部函数类型
typedef BOOL (CALLBACK *pFunIE_External0)(HXCGUI hWebBrowser,HSTRING hResultVal);
typedef BOOL (CALLBACK *pFunIE_External1)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1);
typedef BOOL (CALLBACK *pFunIE_External2)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2);
typedef BOOL (CALLBACK *pFunIE_External3)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3);
typedef BOOL (CALLBACK *pFunIE_External4)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4);
typedef BOOL (CALLBACK *pFunIE_External5)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4,wchar_t *pParam5);
typedef BOOL (CALLBACK *pFunIE_External6)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4,wchar_t *pParam5,wchar_t *pParam6);
typedef BOOL (CALLBACK *pFunIE_External7)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4,wchar_t *pParam5,wchar_t *pParam6,wchar_t *pParam7);
typedef BOOL (CALLBACK *pFunIE_External8)(HXCGUI hWebBrowser,HSTRING hResultVal,wchar_t *pParam1,wchar_t *pParam2,wchar_t *pParam3,wchar_t *pParam4,wchar_t *pParam5,wchar_t *pParam6,wchar_t *pParam7,wchar_t *pParam8);


//定义IE事件回调函数类型
typedef BOOL (CALLBACK *pFunIE_BeforeNavigate2)(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl,in_ int Flags,in_ wchar_t *pTargetFrameName,in_ wchar_t *pPostData,in_ wchar_t *pHeaders,in_out_ VARIANT_BOOL *bCancel);
typedef BOOL (CALLBACK *pFunIE_ClientToHostWindow)(HXCGUI hWebBrowser,in_out_ long *pCx,in_out_ long *pCy);
typedef BOOL (CALLBACK *pFunIE_CommandStateChange)(HXCGUI hWebBrowser,in_ long command,in_ VARIANT_BOOL enable);
typedef BOOL (CALLBACK *pFunIE_DocumentComplete)(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl);
typedef BOOL (CALLBACK *pFunIE_DownloadBegin)(HXCGUI hWebBrowser);
typedef BOOL (CALLBACK *pFunIE_DownloadComplete)(HXCGUI hWebBrowser);
typedef BOOL (CALLBACK *pFunIE_FileDownload)(HXCGUI hWebBrowser,in_ VARIANT_BOOL ActiveDocument,in_out_ VARIANT_BOOL *Cancel);
typedef BOOL (CALLBACK *pFunIE_NavigateComplete2)(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl);
typedef BOOL (CALLBACK *pFunIE_NavigateError)(HXCGUI hWebBrowser,in_ IDispatch *pDisp,in_ wchar_t *pUrl,in_ wchar_t *pTargetFrameName,in_ int statusCode,in_out_ VARIANT_BOOL *bCancel);
typedef BOOL (CALLBACK *pFunIE_NewWindow2)(HXCGUI hWebBrowser,in_out_ IDispatch **pDisp,in_out_ VARIANT_BOOL *bCancel);
typedef BOOL (CALLBACK *pFunIE_NewWindow3)(HXCGUI hWebBrowser,in_out_ IDispatch **pDisp,in_out_ VARIANT_BOOL *bCancel,in_ DWORD dwFlags,in_ wchar_t *pUrlContext,in_ wchar_t *pUrl);
typedef BOOL (CALLBACK *pFunIE_OnFullScreen)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bFullScreen);
typedef BOOL (CALLBACK *pFunIE_OnMenuBar)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bMenuBar);
typedef BOOL (CALLBACK *pFunIE_OnQuit)(HXCGUI hWebBrowser);
typedef BOOL (CALLBACK *pFunIE_OnStatusBar)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bStatusBar);
typedef BOOL (CALLBACK *pFunIE_OnTheaterMode)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bTheaterMode);
typedef BOOL (CALLBACK *pFunIE_OnToolBar)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bToolBar);
typedef BOOL (CALLBACK *pFunIE_OnVisible)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bVisible);
typedef BOOL (CALLBACK *pFunIE_PrintTemplateInstantiation)(HXCGUI hWebBrowser,in_ IDispatch *pDisp);
typedef BOOL (CALLBACK *pFunIE_PrintTemplateTeardown)(HXCGUI hWebBrowser,in_ IDispatch *pDisp);
typedef BOOL (CALLBACK *pFunIE_PrivacyImpactedStateChange)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bPrivacyImpacted);
typedef BOOL (CALLBACK *pFunIE_ProgressChangee)(HXCGUI hWebBrowser,in_ long Progress,in_ long ProgressMax);
typedef BOOL (CALLBACK *pFunIE_PropertyChange)(HXCGUI hWebBrowser,in_ wchar_t *pProperty);
typedef BOOL (CALLBACK *pFunIE_SetPhishingFilterStatus)(HXCGUI hWebBrowser,in_ long phishingFilterStatus);
typedef BOOL (CALLBACK *pFunIE_SetSecureLockIcon)(HXCGUI hWebBrowser,in_ signed int SecureLockIcon);
typedef BOOL (CALLBACK *pFunIE_StatusTextChange)(HXCGUI hWebBrowser,in_ wchar_t *pText);
typedef BOOL (CALLBACK *pFunIE_TitleChange)(HXCGUI hWebBrowser,in_ wchar_t *pText);
typedef BOOL (CALLBACK *pFunIE_WindowClosing)(HXCGUI hWebBrowser,in_ VARIANT_BOOL IsChildWindow,in_out_ VARIANT_BOOL *bCancel);
typedef BOOL (CALLBACK *pFunIE_WindowSetHeight)(HXCGUI hWebBrowser,in_ long height);
typedef BOOL (CALLBACK *pFunIE_WindowSetLeft)(HXCGUI hWebBrowser,in_ long left);
typedef BOOL (CALLBACK *pFunIE_WindowSetResizable)(HXCGUI hWebBrowser,in_ VARIANT_BOOL bResizable);
typedef BOOL (CALLBACK *pFunIE_WindowSetTop)(HXCGUI hWebBrowser,in_ long top);
typedef BOOL (CALLBACK *pFunIE_WindowSetWidth)(HXCGUI hWebBrowser,in_ long width);
typedef BOOL (CALLBACK *pFunIE_WindowStateChanged)(HXCGUI hWebBrowser,in_ DWORD dwFlags,in_ DWORD dwValidFlagsMask);

////////////////IE end///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//窗口消息处理过程
typedef BOOL (CALLBACK *pFunWndMsgProc)(HWINDOW hWindow,UINT message, WPARAM wParam, LPARAM lParam);
//元素消息处理过程
typedef BOOL (CALLBACK *pFunEleMsgProc)(HELE hEle,UINT eleMessage,WPARAM wParam,LPARAM lParam);
//元素事件处理过程
typedef BOOL (CALLBACK *pFunEleEventProc)(HELE hEle,int type,WPARAM wParam,LPARAM lParam);
//绘制滚动视图
typedef BOOL (CALLBACK *pFunDrawScrollView)(HELE hEle,HDRAW hDraw);



//////////////////////////////////////////////////////////
//树元素自绘
///@addtogroup groupTree
///@{

///列表树元素,项自绘结构
struct tree_drewItem_
{
	HDRAW     hDraw;    ///<图形绘制句柄
	int      id;        ///<项ID
	int      imageId;   ///<图标ID
	int      state;     ///<状态
	BOOL     bExpand;   ///<是否展开结点
	wchar_t  *pText;    ///<文本内容

	RECT  rcButton; ///<按钮坐标
	RECT  rcImage;  ///<图片坐标
	RECT  rcText;   ///<文本坐标
};

///@}


///@defgroup groupList_draw 列表元素自绘
///@ingroup macroDefine
///@{

///列表元素,项自绘结构
struct list_drawItem_
{
	HDRAW hDraw;     ///<图形绘制句柄
	int   index;     ///<项索引
	int   subIndex;  ///<子项索引
	int   imageId;   ///<图标ID
	int   state;     ///<状态
	RECT  rect;      ///<项坐标
	RECT  rcCheck;   ///<复选框坐标,对subIndex索引为0的有效
	wchar_t *pText;  ///<文本内容
};

///列表元素,列表头项自绘结构
struct listHeader_drawItem_
{
	HDRAW hDraw;    ///<图形绘制句柄
	int   index;    ///<项索引
	int   imageId;  ///<图标ID
	int   state;    ///<状态 如果值为-1,那么为绘制背景
	RECT  rect;     ///<项坐标
	wchar_t *pText; ///<文本内容
};

///@}



///@defgroup groupListBox_draw 列表框元素自绘
///@ingroup macroDefine
///@{

///列表框元素,项自绘结构
struct listBox_drawItem_
{
	HDRAW hDraw;    ///<图形绘制句柄
	int   index;    ///<索引
	int   imageId;  ///<图标ID
	int   state;    ///<状态
	RECT  rcItem;   ///<项坐标
	RECT  rcCheck;  ///<复选框坐标,当复选框启用时有效
	wchar_t *pText; ///<文本内容
};
///@}


///@defgroup itemBindEle 项绑定元素信息结构
///@ingroup macroDefine
///@{

///项绑定元素信息结构.
struct itemBindEle_
{
	HELE hEle;   ///<绑定的元素,如果绑定到列表元素,那么它的父应该为列表元素.
	int left;    ///<相对于项.
	int top;     ///<相对于项.
	int width;   ///<宽度.
	int height;  ///<高度.
};

///@}

///@defgroup groupListView_draw 列表视图元素自绘
///@ingroup macroDefine
///@{

///列表视图元素,项自绘结构
struct listView_drawItem_	//绘制项
{
	HDRAW     hDraw;   ///<图形绘制句柄
	int       groupIndex; //组索引
	int       itemIndex;  //项索引
	int       imageID; ///<图片ID
	wchar_t   *pText;  ///<文本
	int       state;   ///<状态,是否选择
	
	HIMAGE hImage_stay;    //项停留图片
	HIMAGE hImage_select;  //项选择图标

	RECT  rcIcon; ///<图标坐标
	RECT  rcIconDraw; ///<图标实际绘制区域
	RECT  rcText; ///<文字坐标
	RECT  rect;   ///<整个区域,包含边框

	int userData;  ///<用户数据
};

///列表视图元素,组自绘结构
struct listView_drawGroup_ //绘制组
{
	HDRAW hDraw;        ///<图形绘制句柄
	BOOL  bExpand;      ///<是否展开

	wchar_t  *pText;    ///<文本
	RECT     rcText;    ///<文本坐标
	RECT     rcButton;  ///<展开按钮坐标
	RECT     rect;      ///<组区域坐标

	int userData;       ///<用户数据
};

///列表视图元素,用户拖动项插入
struct listView_dragInsert_
{
	int groupIndex;   ///<拖动项 - 组索引
	int itemIndex;    ///<拖动项 - 项索引

	int groupIndex_insert; ///<插入位置 - 组索引
	int itemIndex_insert;  ///<插入位置 - 项索引

	int groupIndex_new; //插入后位置 组索引
	int itemIndex_new; //插入后位置 项索引
};

///@}






///@defgroup groupMenu_draw 菜单自绘
///@ingroup macroDefine
///@{

///菜单项自绘结构
struct menu_drawItem_
{
	HWINDOW    hWindow;     ///<当前弹出菜单项的窗口句柄
	HDRAW      hDraw;       ///<图形绘制句柄
	int        id;          ///<ID
	int        state;	    ///<状态
	RECT       rcItem;      ///<坐标
	HIMAGE     hImage;      ///<图片
	wchar_t    *pText;      ///<文本
};

///菜单窗口背景自绘结构
struct menu_drawBG_
{
	HWINDOW    hWindow;       ///<当前弹出菜单项的窗口句柄
	HDRAW      hDraw;         ///<图形绘制句柄
	int        parentItemId;  ///<子菜单对应的父项菜单ID，-1没有父项
	HIMAGE     hImage;        ///<图片
};

///@}

//列表项自绘
typedef void (CALLBACK *pFunList_DrawItem)(HELE hEle,list_drawItem_ *pDrawItem);
//列表头项自绘
typedef void (CALLBACK *pFunListHeader_DrawItem)(HELE hEle,listHeader_drawItem_ *pDrawItem);

//列表框项自绘
typedef void (CALLBACK *pFunListBox_DrawItem)(HELE hEle,listBox_drawItem_ *pDrawItem);

//树项自绘
typedef void (CALLBACK *pFunTree_DrawItem)(HELE hEle,tree_drewItem_ *pDrawItem);

//列表视图项自绘
typedef void (CALLBACK *pFunListView_DrawItem)(HELE hEle,listView_drawItem_ *pDrawItem);

//列表视图组自绘
typedef void (CALLBACK *pFunListView_DrawGroup)(HELE hEle,listView_drawGroup_ *pDrawGroup);

//菜单项自绘
typedef void (CALLBACK *pFunMenu_DrawItem)(HMENUX hMenu,menu_drawItem_ *pDrawItem);

//菜单背景自绘
typedef void (CALLBACK *pFunMenu_DrawBG)(HMENUX hMenu,menu_drawBG_ *pDrawBG);

//菜单项更新UI
typedef void (CALLBACK *pFunMenu_UpdateUI)(HMENUX hMenu,int id);

//////////////////////////////////////////////////////////////////////////////////
//下面部分通常不需要改动//////////////////////////////////////////////////////////
#define XCGUI_PLUS  // C++类支持版 , C plus plus

#ifdef	XCGUI_PLUS  //C++类支持,对类成员函数注册的支持
struct eventOrMsg_  //元素消息事件回调信息,C++类支持
{
	union
	{
		HELE hEle;
		HWINDOW hWindow;
		HMENUX  hMenu;
	};
	union
	{
		HELE hEventEle;
		int  xint;
	};
	WPARAM wParam;
	LPARAM lParam;
	void   *pClass_fun;  //类成员函数指针
};

//格式 xc_fun_返回类型_参数类型表...
//b:BOOL, e:HELE, w:HWINDOW, x:HXCGUI, hwnd:HWND, hdraw:HDRAW, i:int, p:void*, pt:POINT*, size:SIZE*, v:void
//pb:BOOL*;
//menu:HMENUX.
enum xcgui_fun_type //函数类型
{
	xc_fun_b_e_e,
	xc_fun_b_e_e_b,
	xc_fun_b_e_e_b_b,
	xc_fun_b_e_e_w_e,
	xc_fun_b_e_e_pb,
	xc_fun_b_e_e_i,
	xc_fun_b_e_e_i_pt,
	xc_fun_b_e_e_i_b,
	xc_fun_b_e_e_i_pb,
	xc_fun_b_e_e_i_i,
	xc_fun_b_e_i_i,
	xc_fun_b_e_i_i_i,
	xc_fun_b_e_e_listView_dragInsert,

	xc_fun_v_e, //元素销毁
	xc_fun_b_e_pt,
	xc_fun_b_e_hdraw,
	xc_fun_b_e_i_pt,
	xc_fun_b_w,
	xc_fun_b_w_e,
	xc_fun_b_w_pt,
	xc_fun_b_w_i,
	xc_fun_b_w_i_pt,
	xc_fun_b_w_i_size,
	xc_fun_b_w_i_i,
	xc_fun_b_w_hdraw,
	xc_fun_b_w_hwnd,

	xc_fun_v_e_list_item,
	xc_fun_v_e_list_header,
	xc_fun_v_e_tree,
	xc_fun_v_e_listBox,
	xc_fun_v_e_listView_item,
	xc_fun_v_e_listView_group,
	xc_fun_v_x_menu_item,
	xc_fun_v_x_menu_bg,
	xc_fun_v_x_menu_i,
};

//事件回调类型
typedef BOOL (CALLBACK *pFunClassEventMsg)(eventOrMsg_ *pEvent,xcgui_fun_type funType);


//{
//以下API内部使用
extern XC_API void* WINAPI XC_Malloc(int size);
extern XC_API void WINAPI XEle_RegisterMessageEx(HELE hEle,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
extern XC_API void WINAPI XEle_RegisterEventEx(HELE hEle,int type,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
extern XC_API void WINAPI XEle_RegisterMsgProcEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);    //注册元素消息处理过程
extern XC_API void WINAPI XEle_RegisterEventProcEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);  //注册事件拦截过滤函数

extern XC_API void WINAPI XWnd_RegisterMessageEx(HWINDOW hWindow,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);  //注册消息回调函数
extern XC_API void WINAPI XWnd_RegisterNCMessageEx(HWINDOW hWindow,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //注册非客户区消息
extern XC_API void WINAPI XWnd_RegisterMsgProcEx(HWINDOW hWindow,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);	//注册窗口消息处理过程

extern XC_API void WINAPI XSView_SetDrawScrollViewEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
extern XC_API void WINAPI XList_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘列表项
extern XC_API void WINAPI XList_SetUserDrawItemHeaderEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘列表头项
extern XC_API void WINAPI XTree_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘项
extern XC_API void WINAPI XListBox_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘列表框项
extern XC_API void WINAPI XListView_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘项
extern XC_API void WINAPI XListView_SetUserDrawGroupEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘组
extern XC_API void WINAPI XMenu_SetUserDrawItemEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘菜单项
extern XC_API void WINAPI XMenu_SetUserDrawBGEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘菜背景
extern XC_API void WINAPI XMenu_SetUserUpdateUIEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);

//}

class CXEventMsg
{
public:
	virtual void CXEventMsg__(void){} //此函数不可删除

//注册元素事件
#define XCGUI_RegEleEvent(hEle,type,memberFunction) \
		RegisterAll(hEle,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_event)

//注册元素消息
#define XCGUI_RegEleMessage(hEle,type,memberFunction) \
		RegisterAll(hEle,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_msg)

//注册元素消息处理过程
#define XCGUI_RegEleMsgProc(hEle,type,memberFunction) \
		RegisterAll(hEle,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_msg_proc)

//注册元素事件处理过程
#define XCGUI_RegEleEventProc(hEle,type,memberFunction) \
		RegisterAll(hEle,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_event_proc)

//注册窗口消息
#define XCGUI_RegWndMessage(hWindow,type,memberFunction) \
		RegisterAll(hWindow,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),wnd_msg)

//注册窗口逻辑非客户区消息
#define XCGUI_RegWndNCMessage(hWindow,type,memberFunction) \
		RegisterAll(hWindow,type,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),wnd_msg_nc)

//注册窗口消息处理过程
#define XCGUI_RegWndMsgProc(hWindow,memberFunction) \
		RegisterAll(hWindow,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),wnd_msg_proc)

//注册滚动视图绘制
#define XCGUI_SView_SetDrawScrollView(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_scrollView_draw)

//注册列表项绘制
#define XCGUI_List_SetUserDrawItem(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_list_drawItem)

//列表头项绘制
#define XCGUI_List_SetUserDrawItemHeader(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_list_drawItemHeader)

//树项绘制
#define XCGUI_Tree_SetUserDrawItem(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_tree_drawItem)

//列表框项绘制
#define XCGUI_ListBox_SetUserDrawItem(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_listBox_drawItem)

//列表视图项绘制
#define XCGUI_ListView_SetUserDrawItem(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_listView_drawItem)

//列表视图组绘制
#define XCGUI_ListView_SetUserDrawGroup(hEle,memberFunction) \
		RegisterAll(hEle,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_listView_drawGroup)

//菜单项自绘
#define XCGUI_Menu_SetUserDrawItem(hMenu,memberFunction) \
	RegisterAll(hMenu,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_menu_drawItem)

//菜单背景自绘
#define XCGUI_Menu_SetUserDrawBG(hMenu,memberFunction) \
	RegisterAll(hMenu,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_menu_drawBG)

//更新菜单项
#define XCGUI_Menu_SetUserUpdateUI(hMenu,memberFunction) \
	RegisterAll(hMenu,0,reinterpret_cast<void (CXEventMsg::*)(void)>(memberFunction),ele_menu_updateUI)

	union xcgui_functions //函数指针
	{
		void (CXEventMsg::*fun_v_v)(void);
		BOOL (CXEventMsg::*fun_b_e_e_i_i)(HELE,HELE,int,int);
		BOOL (CXEventMsg::*fun_b_e_e_i)(HELE,HELE,int);
		BOOL (CXEventMsg::*fun_b_e_e)(HELE,HELE);
		BOOL (CXEventMsg::*fun_b_e_e_pb)(HELE,HELE,BOOL*);
		BOOL (CXEventMsg::*fun_b_e_e_i_pb)(HELE,HELE,int,BOOL*);
		BOOL (CXEventMsg::*fun_b_e_e_b)(HELE,HELE,BOOL);

		BOOL (CXEventMsg::*fun_b_e_e_i_p)(HELE,HELE,int,POINT*);
		BOOL (CXEventMsg::*fun_b_e_e_i_b)(HELE,HELE,int,BOOL);
		BOOL (CXEventMsg::*fun_b_e_e_b_b)(HELE,HELE,BOOL,BOOL);
		BOOL (CXEventMsg::*fun_b_e_i_i_i)(HELE,int,int,int);
		BOOL (CXEventMsg::*fun_b_e_i_i)(HELE,int,int);
		BOOL (CXEventMsg::*fun_b_e_e_w_e)(HELE,HELE,HWINDOW,HELE);
		BOOL (CXEventMsg::*fun_b_e_e_listViewDragInsert)(HELE,HELE,listView_dragInsert_*);

		void (CXEventMsg::*fun_v_e)(HELE);

		BOOL (CXEventMsg::*fun_b_e_i_p)(HELE,int,POINT*);
		BOOL (CXEventMsg::*fun_b_e_p)(HELE,POINT*);
		BOOL (CXEventMsg::*fun_b_e_hdraw)(HELE,HDRAW);

		BOOL (CXEventMsg::*fun_b_w_hdraw)(HWINDOW,HDRAW);
		BOOL (CXEventMsg::*fun_b_w)(HWINDOW);
		BOOL (CXEventMsg::*fun_b_w_i_p)(HWINDOW,int,POINT*);
		BOOL (CXEventMsg::*fun_b_w_i_size)(HWINDOW,int,SIZE*);
		BOOL (CXEventMsg::*fun_b_w_i_i)(HWINDOW,int,int);
		BOOL (CXEventMsg::*fun_b_w_p)(HWINDOW,POINT*);
		BOOL (CXEventMsg::*fun_b_w_e)(HWINDOW,HELE);
		BOOL (CXEventMsg::*fun_b_w_hwnd)(HWINDOW,HWND);
		BOOL (CXEventMsg::*fun_b_w_i)(HWINDOW,int);

		void (CXEventMsg::*fun_v_e_list)(HELE,list_drawItem_*);
		void (CXEventMsg::*fun_v_e_listHeader)(HELE,listHeader_drawItem_*);
		void (CXEventMsg::*fun_v_e_tree)(HELE,tree_drewItem_*);
		void (CXEventMsg::*fun_v_e_listBox)(HELE,listBox_drawItem_*);
		void (CXEventMsg::*fun_v_e_listView)(HELE,listView_drawItem_*);
		void (CXEventMsg::*fun_v_e_listViewGroup)(HELE,listView_drawGroup_*);
		void (CXEventMsg::*fun_v_x_menu_drawItem)(HMENUX,menu_drawItem_*);
		void (CXEventMsg::*fun_v_x_menu_drawBG)(HMENUX,menu_drawBG_*);
		void (CXEventMsg::*fun_v_x_menu_updateUI)(HMENUX,int);
	};
	enum xcgui_reg_type //注册类型
	{
		ele_event,        //元素事件
		ele_msg,          //元素消息
		ele_msg_proc,     //元素消息处理过程
		ele_event_proc,   //元素事件处理过程
		wnd_msg,          //窗口消息
		wnd_msg_nc,       //窗口逻辑非客户区消息
		wnd_msg_proc,     //窗口消息处理过程
		//---------------
		ele_scrollView_draw,     //滚动视图自绘
		ele_list_drawItem,       //列表项自绘
		ele_list_drawItemHeader, //列表头项自绘
		ele_tree_drawItem,       //树项自绘
		ele_listBox_drawItem,    //列表框项自绘
		ele_listView_drawItem,   //列表视图项绘制
		ele_listView_drawGroup,  //列表视图组绘制
		ele_menu_drawItem,       //绘制菜单项
		ele_menu_drawBG,         //绘制菜单背景
		ele_menu_updateUI,       //菜单项更新UI
	};

	struct  xcgui_info_
	{
		CXEventMsg  *theThis;
		xcgui_functions  funs;
	};

	void RegisterAll(HXCGUI hXCGUI,int type,void (CXEventMsg::*fun)(void),int T) //注册消息事件
	{
		xcgui_info_ *pInfo=(xcgui_info_*)XC_Malloc(sizeof(xcgui_info_));
		pInfo->theThis=this;
		pInfo->funs.fun_v_v=fun;

		switch(T)
		{
		case ele_event: //注册元素事件
			XEle_RegisterEventEx((HELE)hXCGUI,type,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_msg: //元素消息
			XEle_RegisterMessageEx((HELE)hXCGUI,type,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_msg_proc: //元素消息处理过程
			XEle_RegisterMsgProcEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_event_proc: //元素事件处理过程
			XEle_RegisterEventProcEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case wnd_msg: //注册窗口消息
			XWnd_RegisterMessageEx((HWINDOW)hXCGUI,type,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case wnd_msg_nc: //注册窗口逻辑上非客户区消息
			XWnd_RegisterNCMessageEx((HWINDOW)hXCGUI,type,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case wnd_msg_proc:
			XWnd_RegisterMsgProcEx((HWINDOW)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_scrollView_draw: //滚动视图绘制
			XSView_SetDrawScrollViewEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_list_drawItem: //列表项自绘
			XList_SetUserDrawItemEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_list_drawItemHeader: //列表头项绘制
			XList_SetUserDrawItemHeaderEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_tree_drawItem: //树项自绘
			XTree_SetUserDrawItemEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_listBox_drawItem://列表框项自绘
			XListBox_SetUserDrawItemEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_listView_drawItem: //列表视图项自绘
			XListView_SetUserDrawItemEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_listView_drawGroup: //列表视图组自绘
			XListView_SetUserDrawGroupEx((HELE)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_menu_drawItem: //菜单项自绘
			XMenu_SetUserDrawItemEx((HMENUX)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_menu_drawBG:
			XMenu_SetUserDrawBGEx((HMENUX)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		case ele_menu_updateUI:
			XMenu_SetUserUpdateUIEx((HMENUX)hXCGUI,CXEventMsg::OnEventAndMsg,pInfo);
			break;
		};
	}
	static BOOL CALLBACK OnEventAndMsg(eventOrMsg_ *pEvent,xcgui_fun_type funType)//事件回调
	{
		xcgui_info_ *info=(xcgui_info_*)pEvent->pClass_fun;
		BOOL bResult=FALSE;
		switch(funType)
		{
			//////////////////////////////////////////////////
		case xc_fun_b_e_e_i_i:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i_i)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam,pEvent->lParam);
			break;
		case xc_fun_b_e_e_i:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam);
			break;
		case xc_fun_b_e_e:
			bResult=(info->theThis->*info->funs.fun_b_e_e)(pEvent->hEle,pEvent->hEventEle);
			break;
		case xc_fun_b_e_e_pb:
			bResult=(info->theThis->*info->funs.fun_b_e_e_pb)(pEvent->hEle,pEvent->hEventEle,(BOOL*)&pEvent->wParam);
			break;
		case xc_fun_b_e_e_i_pb:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i_pb)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam,(BOOL*)pEvent->lParam);
			break;
		case xc_fun_b_e_e_b:
			bResult=(info->theThis->*info->funs.fun_b_e_e_b)(pEvent->hEle,pEvent->hEventEle,(BOOL)pEvent->wParam);
			break;
		case xc_fun_b_e_e_i_pt:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i_p)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam,(POINT*)pEvent->lParam);
			break;
		case xc_fun_b_e_e_i_b:
			bResult=(info->theThis->*info->funs.fun_b_e_e_i_b)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam,pEvent->lParam?TRUE:FALSE);
			break;
		case xc_fun_b_e_e_b_b:
			bResult=(info->theThis->*info->funs.fun_b_e_e_b_b)(pEvent->hEle,pEvent->hEventEle,pEvent->wParam?TRUE:FALSE,pEvent->lParam?TRUE:FALSE);
			break;
		case xc_fun_b_e_e_w_e:
			bResult=(info->theThis->*info->funs.fun_b_e_e_w_e)(pEvent->hEle,pEvent->hEventEle,(HWINDOW)pEvent->wParam,(HELE)pEvent->lParam);
			break;
		case xc_fun_b_e_e_listView_dragInsert:
			bResult=(info->theThis->*info->funs.fun_b_e_e_listViewDragInsert)(pEvent->hEle,pEvent->hEventEle,(listView_dragInsert_*)pEvent->wParam);
			break;
			/////////////////////////////////////////////////////////
		case xc_fun_v_e:
			(info->theThis->*info->funs.fun_v_e)(pEvent->hEle);
			break;
		case xc_fun_b_e_i_i_i:
			bResult=(info->theThis->*info->funs.fun_b_e_i_i_i)(pEvent->hEle,pEvent->xint,pEvent->wParam,pEvent->lParam);
			break;
		case xc_fun_b_e_i_i:
			bResult=(info->theThis->*info->funs.fun_b_e_i_i)(pEvent->hEle,pEvent->wParam,pEvent->lParam);
			break;
		case xc_fun_b_e_i_pt:
			bResult=(info->theThis->*info->funs.fun_b_e_i_p)(pEvent->hEle,pEvent->wParam,(POINT*)pEvent->lParam);
			break;
		case xc_fun_b_e_pt:
			bResult=(info->theThis->*info->funs.fun_b_e_p)(pEvent->hEle,(POINT*)pEvent->wParam);
			break;
		case xc_fun_b_e_hdraw:
			bResult=(info->theThis->*info->funs.fun_b_e_hdraw)(pEvent->hEle,(HDRAW)pEvent->wParam);
			break;
		case xc_fun_b_w_hdraw:
			bResult=(info->theThis->*info->funs.fun_b_w_hdraw)(pEvent->hWindow,(HDRAW)pEvent->wParam);
			break;
		case xc_fun_b_w:
			bResult=(info->theThis->*info->funs.fun_b_w)(pEvent->hWindow);
			break;
		case xc_fun_b_w_i_pt:
			bResult=(info->theThis->*info->funs.fun_b_w_i_p)(pEvent->hWindow,pEvent->wParam,(POINT*)pEvent->lParam);
			break;
		case xc_fun_b_w_i_size:
			bResult=(info->theThis->*info->funs.fun_b_w_i_size)(pEvent->hWindow,pEvent->wParam,(SIZE*)pEvent->lParam);
			break;
		case xc_fun_b_w_i_i:
			bResult=(info->theThis->*info->funs.fun_b_w_i_i)(pEvent->hWindow,pEvent->wParam,pEvent->lParam);
			break;
		case xc_fun_b_w_pt:
			bResult=(info->theThis->*info->funs.fun_b_w_p)(pEvent->hWindow,(POINT*)pEvent->wParam);
			break;
		case xc_fun_b_w_e:
			bResult=(info->theThis->*info->funs.fun_b_w_e)(pEvent->hWindow,(HELE)pEvent->wParam);
			break;
		case xc_fun_b_w_hwnd:
			bResult=(info->theThis->*info->funs.fun_b_w_hwnd)(pEvent->hWindow,(HWND)pEvent->wParam);
			break;
		case xc_fun_b_w_i:
			bResult=(info->theThis->*info->funs.fun_b_w_i)(pEvent->hWindow,pEvent->wParam);
			break;
			//////////////////////////////////////////////////////
		case xc_fun_v_e_list_item:
			(info->theThis->*info->funs.fun_v_e_list)(pEvent->hEle,(list_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_list_header:
			(info->theThis->*info->funs.fun_v_e_listHeader)(pEvent->hEle,(listHeader_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_tree:
			(info->theThis->*info->funs.fun_v_e_tree)(pEvent->hEle,(tree_drewItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_listBox:
			(info->theThis->*info->funs.fun_v_e_listBox)(pEvent->hEle,(listBox_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_listView_item:
			(info->theThis->*info->funs.fun_v_e_listView)(pEvent->hEle,(listView_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_e_listView_group:
			(info->theThis->*info->funs.fun_v_e_listViewGroup)(pEvent->hEle,(listView_drawGroup_*)pEvent->wParam);
			break;
		case xc_fun_v_x_menu_item:
			(info->theThis->*info->funs.fun_v_x_menu_drawItem)(pEvent->hMenu,(menu_drawItem_*)pEvent->wParam);
			break;
		case xc_fun_v_x_menu_bg:
			(info->theThis->*info->funs.fun_v_x_menu_drawBG)(pEvent->hMenu,(menu_drawBG_*)pEvent->wParam);
			break;
		case xc_fun_v_x_menu_i:
			(info->theThis->*info->funs.fun_v_x_menu_updateUI)(pEvent->hMenu,pEvent->wParam);
			break;
		}
		return bResult;
	}
};

#endif //XCGUI_PLUS


//这里添加导出API函数////////////////////////////////////////////////////////

XC_API HWINDOW WINAPI XC_LoadXML_Window(wchar_t *pFileName,HXMLRES hXmlRes=NULL,HWND hWndParent=NULL);
XC_API HWINDOW WINAPI XC_LoadXML_WindowRes(int resID,wchar_t *pType,HXMLRES hXmlRes=NULL,HWND hWndParent=NULL);
XC_API BOOL WINAPI XC_LoadXML_Page(HXCGUI hParent,wchar_t *pFileName,HXMLRES hXmlRes=NULL);
XC_API BOOL WINAPI XC_LoadXML_PageRes(HXCGUI hParent,int resID,wchar_t *pType,HXMLRES hXmlRes=NULL);
XC_API BOOL WINAPI XC_LoadXML_Style(HWINDOW hWindow,wchar_t *pFileName,HXMLRES hXmlRes=NULL);
XC_API BOOL WINAPI XC_LoadXML_StyleRes(HWINDOW hWindow,int resID,wchar_t *pType,HXMLRES hXmlRes=NULL); //从资源加载
XC_API HXMLRES WINAPI XXmlRes_Load(wchar_t *pFileName);
XC_API HXMLRES WINAPI XXmlRes_LoadRes(int resID,wchar_t *pType);//从VC资源文件中加载
XC_API void WINAPI XXmlRes_Destroy(HXMLRES hXmlRes);
XC_API int WINAPI XXmlRes_FindId(HXMLRES hXmlRes,wchar_t *pName);
XC_API void WINAPI XXmlRes_FindImage(HXMLRES hXmlRes,wchar_t *pName,out_ wchar_t *pOut,int outLen);
XC_API void WINAPI XXmlRes_FindString(HXMLRES hXmlRes,wchar_t *pName,out_ wchar_t *pOut,int outLen);
XC_API HIMAGE WINAPI XXmlRes_FildHIMAGE(HXMLRES hXmlRes,wchar_t *pName);
XC_API HARRAY WINAPI XArray_Create(); //创建
XC_API void WINAPI XArray_Destroy(HARRAY hArray); //销毁
XC_API int  WINAPI XArray_Add(HARRAY hArray,void *pElement);//增加元素到末尾
XC_API void WINAPI XArray_AddFirst(HARRAY hArray,void *pElement); //增加到开头
XC_API BOOL WINAPI XArray_insert(HARRAY hArray,void *pElement,int index); //插入到指定位置
XC_API void WINAPI XArray_DeleteIndex(HARRAY hArray,int index);
XC_API void WINAPI XArray_Delete(HARRAY hArray,void *pElement);
XC_API void WINAPI XArray_DeleteEnd(HARRAY hArray,int index); //删除末尾内容
XC_API void WINAPI XArray_DeleteRange(HARRAY hArray,int begin,int end);
XC_API void WINAPI XArray_DeleteAll(HARRAY hArray);
XC_API void WINAPI XArray_SetAt(HARRAY hArray,int index,void *pElement);
XC_API void* WINAPI XArray_GetAt(HARRAY hArray,int index);
XC_API int WINAPI XArray_GetCount(HARRAY hArray);
XC_API HARRAY_ITERATOR WINAPI XArrayIterator_Create(HARRAY hArray,BOOL bType=TRUE);  //创建迭代器
XC_API void* WINAPI XArrayIterator_GetAt(HARRAY_ITERATOR hArray_Iterator);
XC_API void  WINAPI XArrayIterator_Destroy(HARRAY_ITERATOR hArray_Iterator);
XC_API HELE WINAPI XBtn_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);  //创建按钮
XC_API wchar_t * WINAPI XBtn_GetText(HELE hEle);  //获取文本
XC_API void  WINAPI XBtn_SetText(HELE hEle,wchar_t *pText);
XC_API void WINAPI XBtn_SetCheck(HELE hEle,BOOL bCheck);
XC_API BOOL WINAPI XBtn_IsCheck(HELE hEle); //按钮是否被选中
XC_API int  WINAPI XBtn_GetState(HELE hEle);
XC_API void WINAPI XBtn_SetImageLeave(HELE hEle,HIMAGE hImage=NULL);  //鼠标离开时图片
XC_API void WINAPI XBtn_SetImageStay(HELE hEle,HIMAGE hImage=NULL);   //鼠标停留时图片
XC_API void WINAPI XBtn_SetImageDown(HELE hEle,HIMAGE hImage=NULL);   //鼠标按下时图片
XC_API void WINAPI XBtn_SetImageCheck(HELE hEle,HIMAGE hImage=NULL);  //选中时图片
XC_API void WINAPI XBtn_SetImageDisable(HELE hEle,HIMAGE hImage=NULL); //按钮禁用状态图片
XC_API void WINAPI XBtn_SetTextAlign(HELE hEle,int flag); //设置文本对齐
XC_API void WINAPI XBtn_SetIcon(HELE hEle,HIMAGE hImage); //设置图标
XC_API void WINAPI XBtn_SetIconAlign(HELE hEle,int align);
XC_API void WINAPI XBtn_EnableCursorHand(HELE hEle,BOOL bEnable); //鼠标停留,光标变为手型
XC_API void WINAPI XBtn_EnableAnimation(HELE hEle,BOOL bEnable,BOOL bLoopPlay=FALSE);
XC_API void WINAPI XBtn_AddAnimationFrame(HELE hEle,HIMAGE hImage,UINT uElapse);
XC_API void WINAPI XBtn_SetOffset(HELE hEle,int x,int y); //设置内容坐标偏移量
XC_API HELE WINAPI XCheck_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);
XC_API void WINAPI XCheck_SetImageLeave_UnCheck(HELE hEle,HIMAGE hImage);   //鼠标离开时图片  未选择
XC_API void WINAPI XCheck_SetImageStay_UnCheck(HELE hEle,HIMAGE hImage);    //鼠标停留时图片  未选择
XC_API void WINAPI XCheck_SetImageDown_UnCheck(HELE hEle,HIMAGE hImage);    //鼠标按下时图片  未选择
XC_API void WINAPI XCheck_SetImageDisable_UnCheck(HELE hEle,HIMAGE hImage); //按钮禁用状态图片  未选择
XC_API void WINAPI XCheck_SetImageLeave_Check(HELE hEle,HIMAGE hImage);   //鼠标离开时图片   选择
XC_API void WINAPI XCheck_SetImageStay_Check(HELE hEle,HIMAGE hImage);    //鼠标停留时图片   选择
XC_API void WINAPI XCheck_SetImageDown_Check(HELE hEle,HIMAGE hImage);    //鼠标按下时图片   选择
XC_API void WINAPI XCheck_SetImageDisable_Check(HELE hEle,HIMAGE hImage); //按钮禁用状态图片  选择
XC_API HELE WINAPI XCHColor_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API COLORREF WINAPI XCHColor_GetColor(HELE hEle); //获取颜色RGB值
XC_API void WINAPI XCHColor_SetColor(HELE hEle,COLORREF color);//设置颜色
XC_API HELE WINAPI XComboBox_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API BOOL WINAPI XComboBox_AddString(HELE hEle,wchar_t *pText,int data=0);  //增加一个字符串到组合框
XC_API void WINAPI XComboBox_DeleteItem(HELE hEle,int index);//删除项
XC_API void WINAPI XComboBox_DeleteItemAll(HELE hEle);  //删除所有项
XC_API void WINAPI XComboBox_EnableEdit(HELE hEle,BOOL bEdit);  //启动编辑内容
XC_API void WINAPI XComboBox_SetSelectItem(HELE hEle,int index);  //设置选择项
XC_API void WINAPI XComboBox_SetText(HELE hEle,wchar_t *pText);     //设置编辑框内容
XC_API void WINAPI XComboBox_SetItemHeight(HELE hEle,int height); //设置下拉列表项高
XC_API void WINAPI XComboBox_SetListHeight(HELE hEle,int height);   //设置下拉列表高度
XC_API void WINAPI XComboBox_SetButtonWidth(HELE hEle,int width); //设置下拉按钮宽度
XC_API void WINAPI XComboBox_SetItemData(HELE hEle,int index,int data);
XC_API int  WINAPI XComboBox_GetButtonWidth(HELE hEle); //获取下拉按钮宽度
XC_API void WINAPI XComboBox_GetText(HELE hEle,wchar_t *pOut,int len);  //获取编辑框文本
XC_API int  WINAPI XComboBox_GetItemHeight(HELE hEle);  //获取项高
XC_API int  WINAPI XComboBox_GetListHeight(HELE hEle); //获取下拉列表高度
XC_API wchar_t* WINAPI XComboBox_GetItemText(HELE hEle,int index); //获取下拉列表文本
XC_API int  WINAPI XComboBox_GetSelectItem(HELE hEle);  //获取当前选择项索引
XC_API int WINAPI XComboBox_GetItemData(HELE hEle,int index);
XC_API int WINAPI XComboBox_GetItemCount(HELE hEle); //获取项数量
XC_API void WINAPI XComboBox_SetImageLeave(HELE hEle,HIMAGE hImage=NULL); //鼠标离开
XC_API void WINAPI XComboBox_SetImageStay(HELE hEle,HIMAGE hImage=NULL); //鼠标停留
XC_API void WINAPI XComboBox_SetImageDown(HELE hEle,HIMAGE hImage=NULL); //鼠标按下
XC_API void WINAPI XDraw_FillSolidRect(HDC hdc,RECT *pRect,COLORREF clr);
XC_API BOOL WINAPI XDraw_GradientFill2(HDC hdc,COLORREF color1,COLORREF color2,RECT *pRect,int mode);
XC_API BOOL WINAPI XDraw_GradientFill4(HDC hdc,COLORREF color1,COLORREF color2,COLORREF colo3,COLORREF color4,RECT *pRect,int mode);
XC_API void WINAPI XDraw_Check(HDC hdc,int x,int y,COLORREF color,BOOL bCheck);
XC_API void WINAPI XDraw_HImage(HDC hdc,HIMAGE hImage,int x,int y);
XC_API void WINAPI XDraw_HImageStretch(HDC hdc,HIMAGE hImage,int x,int y,int width,int height);
XC_API void WINAPI XDraw_HImageSuper(HDC hdc,HIMAGE hImage,RECT *pRect);
XC_API void WINAPI XDraw_HImageEx(HDC hdc,HIMAGE hImage,int x,int y,int width,int height,int srcX,int srcY);
XC_API void WINAPI XDraw_HImageExTile(HDC hdc,HIMAGE hImage,RECT *pRect,int flag=0);
XC_API void WINAPI XDraw_HImageAdaptive(HDC hdc,HIMAGE hImage,RECT *pRect);
XC_API HDRAW WINAPI XDraw_Create_(HDC hdc); //创建
XC_API void  WINAPI XDraw_Destroy_(HDRAW hDraw); //销毁
XC_API void  WINAPI XDraw_SetOffset_(HDRAW hDraw,int x,int y); //设置坐标偏移量
XC_API void  WINAPI XDraw_RestoreGDIOBJ_(HDRAW hDraw);  //还原状态,释放用户绑定的GDI对象
XC_API HDC   WINAPI XDraw_GetHDC_(HDRAW hDraw);
XC_API void  WINAPI XDraw_GetOffset_(HDRAW hDraw,out_ int *pX,out_ int *pY); //获取坐标偏移量
XC_API COLORREF WINAPI XDraw_SetTextColor_(HDRAW hDraw,COLORREF crColor);
XC_API HBRUSH WINAPI XDraw_CreateSolidBrush_(HDRAW hDraw,COLORREF crColor);
XC_API HPEN WINAPI XDraw_CreatePen_(HDRAW hDraw,int fnPenStyle,int nWidth,COLORREF crColor);
XC_API HRGN WINAPI XDraw_CreateRoundRectRgn_(HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect,int nWidthEllipse,int nHeightEllipse);
XC_API HRGN WINAPI XDraw_CreatePolygonRgn_(HDRAW hDraw,POINT *pPt,int cPoints,int fnPolyFillMode);
XC_API HGDIOBJ WINAPI XDraw_SelectObject_(HDRAW hDraw,HGDIOBJ hObj);
XC_API int WINAPI XDraw_SelectClipRgn_(HDRAW hDraw,HRGN hRgn);
XC_API BOOL WINAPI XDraw_DeleteObject_(HDRAW hDraw,HGDIOBJ hObj);
XC_API int WINAPI XDraw_FillRect_(HDRAW hDraw,RECT *pRect,HBRUSH hbr);
XC_API BOOL WINAPI XDraw_FillRgn_(HDRAW hDraw,HRGN hrgn,HBRUSH hbr);
XC_API void WINAPI XDraw_FillSolidRect_(HDRAW hDraw,RECT *pRect,COLORREF clr);
XC_API BOOL WINAPI XDraw_GradientFill2_(HDRAW hDraw,COLORREF color1,COLORREF color2, RECT *pRect,int mode);
XC_API BOOL WINAPI XDraw_GradientFill4_(HDRAW hDraw,COLORREF color1,COLORREF color2,COLORREF color3,COLORREF color4,RECT *pRect,int mode);
XC_API BOOL WINAPI XDraw_FrameRgn_(HDRAW hDraw,HRGN hrgn,HBRUSH hbr,int nWidth,int nHeight);
XC_API int  WINAPI XDraw_FrameRect_(HDRAW hDraw,RECT *pRect,HBRUSH hbr);
XC_API BOOL WINAPI XDraw_FocusRect_(HDRAW hDraw,RECT *pRect);
XC_API BOOL WINAPI XDraw_Rectangle_(HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect);
XC_API BOOL WINAPI XDraw_MoveToEx_(HDRAW hDraw,int X,int Y,LPPOINT lpPoint=NULL);
XC_API BOOL WINAPI XDraw_LineTo_(HDRAW hDraw,int nXEnd,int nYEnd);
XC_API void WINAPI XDraw_Check_(HDRAW hDraw,int x,int y,COLORREF color,BOOL bCheck);
XC_API void WINAPI XDraw_Dottedline_(HDRAW hDraw,int x,int y,int length,COLORREF color,BOOL bHorizontal=TRUE);  //绘制虚线
XC_API COLORREF WINAPI XDraw_SetPixel_(HDRAW hDraw,int X,int Y,COLORREF crColor);
XC_API BOOL WINAPI XDraw_DrawIconEx_(HDRAW hDraw,int xLeft,int yTop,HICON hIcon,int cxWidth,int cyWidth,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw, UINT diFlags);
XC_API BOOL WINAPI XDraw_BitBlt_(HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,HDC hdcSrc,int nXSrc,int nYSrc,DWORD dwRop);
XC_API BOOL WINAPI XDraw_BitBlt2_(HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,HDRAW hDrawSrc,int nXSrc,int nYSrc,DWORD dwRop);
XC_API void WINAPI XDraw_TriangularArrow(HDRAW hDraw,HBRUSH hBrush,int align,int x,int y,int width,int height);
XC_API void WINAPI XDraw_HImage_(HDRAW hDraw,HIMAGE hImage,int x,int y);
XC_API void WINAPI XDraw_HImage2_(HDRAW hDraw,HIMAGE hImage,int x,int y,int width,int height);
XC_API void WINAPI XDraw_HImageStretch_(HDRAW hDraw,HIMAGE hImage,int x,int y,int width,int height);
XC_API void WINAPI XDraw_HImageAdaptive_(HDRAW hDraw,HIMAGE hImage,RECT *pRect);
XC_API void WINAPI XDraw_HImageExTile_(HDRAW hDraw,HIMAGE hImage,RECT *pRect,int flag=0);
XC_API void WINAPI XDraw_HImageSuper_(HDRAW hDraw,HIMAGE hImage,RECT *pRect);
XC_API void WINAPI XDraw_HImageSuper2_(HDRAW hDraw,HIMAGE hImage,RECT *pRcDest,RECT *pSrcRect);
XC_API int WINAPI XDraw_DrawText_(HDRAW hDraw,wchar_t * lpString,int nCount,RECT* lpRect,UINT uFormat);
XC_API BOOL WINAPI XDraw_TextOut_(HDRAW hDraw,int nXStart,int nYStart,wchar_t * lpString,int cbString);
XC_API HELE WINAPI XEdit_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XEdit_EnableMultiLine(HELE hEle,BOOL b);  //启用多行输入
XC_API void WINAPI XEdit_EnablePassBox(HELE hEle,BOOL bPass); //启用密码框
XC_API void WINAPI XEdit_EnableNumber(HELE hEle,BOOL bNumber); //只能输入数字
XC_API void WINAPI XEdit_EnablePopupMenu(HELE hEle,BOOL bEnable);  //启用鼠标右键菜单
XC_API void WINAPI XEdit_InsertText(HELE hEle,wchar_t *pText,int row=-1,int column=-1); //插入文本,row=-1末尾行,column=-1末尾列;
XC_API void WINAPI XEdit_DeleteSelectText(HELE hEle); //删除选择文本,当只读属性时,也可以删除文本
XC_API void WINAPI XEdit_SetText(HELE hEle,wchar_t *pText);  //设置文本
XC_API void WINAPI XEdit_SetInt(HELE hEle,int value);  //设置整形内容
XC_API void WINAPI XEdit_SetReadOnly(HELE hEle,BOOL bRead);  //设置只读文本
XC_API void WINAPI XEdit_SetTextSpacingLeft(HELE hEle,int spacing);  //设置字体左对齐间隔
XC_API void WINAPI XEdit_SetTextSpacingTop(HELE hEle,int spacing);  //设置字体上对齐间隔
XC_API void WINAPI XEdit_SetPos(HELE hEle,int line,int column); //设置插入符位置
XC_API void WINAPI XEdit_SetCaretWidth(HELE hEle,int width); //设置编辑框插入符宽度
XC_API void WINAPI XEdit_SetBackspace(HELE hEle);  //退格
XC_API void WINAPI XEdit_SetSelectTextBkColor(HELE hEle,COLORREF color);//设置选择文本背景颜色
XC_API void WINAPI XEdit_GetSelectText(HELE hEle,wchar_t *pOut,int len);  //获取选择内容
XC_API int  WINAPI XEdit_GetTextLength(HELE hEle); //获取内容长度
XC_API void WINAPI XEdit_GetText(HELE hEle,wchar_t *pOut,int len); //获取文本
XC_API int  WINAPI XEdit_GetInt(HELE hEle); //获取整形内容
XC_API int WINAPI XEdit_GetRowCount(HELE hEle);   //获取总行数
XC_API int WINAPI XEdit_GetColumnCount(HELE hEle,int row); //获取指定行字符数,row=-1末尾行;
XC_API int WINAPI XEdit_GetCurrentRow(HELE hEle);  //获取插入符位置当前行
XC_API int WINAPI XEdit_GetCurrentColumn(HELE hEle); //获取插入符位置当前列
XC_API BOOL WINAPI XEdit_IsEmpty(HELE hEle); //判断内容是否为空
XC_API void WINAPI XEdit_DeleteAll(HELE hEle);  //清空  删除所有文本
XC_API void WINAPI XEdit_Menu_Cut(HELE hEle);        //剪切  删除选择的文本,并将文本拷贝到剪切板中
XC_API void WINAPI XEdit_Menu_Copy(HELE hEle);       //复制  复制选择的文本到剪切板中
XC_API void WINAPI XEdit_Menu_Paste(HELE hEle);      //粘贴  将剪切板中的文本插入当前光标位置
XC_API void WINAPI XEdit_Menu_Clear(HELE hEle);      //删除  删除选择的文本,当只读属性时无法删除文本
XC_API void WINAPI XEdit_Menu_SelectAll(HELE hEle);  //全选  选择所有文本
XC_API void WINAPI XEdit_Menu_DeleteAll(HELE hEle);  //清空  删除所有文本
XC_API void WINAPI XEdit_SetImageLeave(HELE hEle,HIMAGE hImage=NULL); //鼠标离开
XC_API void WINAPI XEdit_SetImageStay(HELE hEle,HIMAGE hImage=NULL); //鼠标停留
XC_API HELE WINAPI XEditFile_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XEditFile_SetOpenFileType(HELE hEle,wchar_t *pType); //设置打开文件类型
XC_API void WINAPI XEditFile_SetDefaultFile(HELE hEle,wchar_t *pFile); //设置默认目录文件
XC_API void WINAPI XEditFile_SetRelativeDir(HELE hEle,wchar_t *pDir); //TODO:设置相对路径
XC_API void WINAPI XEle_RegisterEventEx(HELE hEle,int type,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
XC_API void WINAPI XEle_RegisterMessageEx(HELE hEle,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //注册消息
XC_API void WINAPI XEle_RegisterMsgProcEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);    //注册元素消息处理过程
XC_API void WINAPI XEle_RegisterEventProcEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);  //注册事件拦截过滤函数
XC_API HELE WINAPI XEle_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL); //创建
XC_API BOOL WINAPI XEle_Destroy(HELE hEle);  //销毁
XC_API void WINAPI XEle_RegisterMessage(HELE hEle,int message,void *pFun); 
XC_API void WINAPI XEle_RegisterEvent(HELE hEle,int type,void *pFun);
XC_API void WINAPI XEle_RegisterMsgProc(HELE hEle,pFunEleMsgProc pFun);    //注册元素消息处理过程
XC_API void WINAPI XEle_RegisterEventProc(HELE hEle,pFunEleEventProc pFun);  //注册元素事件处理过程
XC_API void WINAPI XEle_SetBkTransparent(HELE hEle,BOOL bTran);   //设置元素背景透明
XC_API void WINAPI XEle_SetFocus(HELE hEle,BOOL bFocus); //设置焦点
XC_API void WINAPI XEle_SetId(HELE hEle,int id);
XC_API void WINAPI XEle_SetFont(HELE hEle,HFONTX hFontX);
XC_API HFONTX WINAPI XEle_GetFont(HELE hEle); //获取字体
XC_API BOOL WINAPI XEle_SetZOrder(HELE hEle,HELE hDestEle=NULL,int flag=XC_ZORDER_TOP,int index=NULL);
XC_API void WINAPI XEle_SetBkColor(HELE hEle,COLORREF color); //设置背景颜色
XC_API COLORREF WINAPI XEle_GetBkColor(HELE hEle); //获取背景颜色
XC_API void WINAPI XEle_SetBorderColor(HELE hEle,COLORREF color); //设置边框颜色
XC_API void WINAPI XEle_SetToolTips(HELE hEle,wchar_t *pText); //设置工具提示内容
XC_API void WINAPI XEle_SetCapture(HELE hEle);   //设置元素鼠标捕获
XC_API wchar_t* WINAPI XEle_GetTooltips(HELE hEle);  //获取工具提示内容
XC_API HELE WINAPI XEle_GetParentEle(HELE hEle);  //获取父元素句柄
XC_API int  WINAPI XEle_GetChildCout(HELE hEle);  //获取子元素数量
XC_API HELE WINAPI XEle_GetChildByIndex(HELE hEle,int index);	//获取指定子元素
XC_API HWND WINAPI XEle_GetHWnd(HELE hEle);  //获取窗口句柄
XC_API HWINDOW WINAPI XEle_GetHWindow(HELE hEle); //获取窗口资源句柄
XC_API int  WINAPI XEle_GetUserData(HELE hEle);  //获取用户数据
XC_API int WINAPI XEle_GetId(HELE hEle);
XC_API void WINAPI XEle_ReleaseCapture(HELE hEle);   //释放元素鼠标捕获
XC_API void WINAPI XEle_EnableEle(HELE hEle,BOOL bEnable); //元素是否有效
XC_API void WINAPI XEle_EnableFocus(HELE hEle,BOOL bFocus); //开启焦点
XC_API void WINAPI XEle_EnableDrawFocus(HELE hEle,BOOL bFocus); //是否绘制焦点
XC_API void WINAPI XEle_EnableToolTips(HELE hEle,BOOL bTips);  //启用工具提示
XC_API void WINAPI XEle_EnableBorder(HELE hEle,BOOL bEnable); //绘制边框
XC_API void WINAPI XEle_EnableTransparentChannel(HELE hEle,BOOL bEnable);
XC_API BOOL WINAPI XEle_AddEle(HELE hEle,HELE hNewEle,int flag=XC_ADDELE_END,HELE hDestEle=0,int index=0); //添加元素
XC_API void WINAPI XEle_RemoveEle(HELE hEle);   //移除元素,但不销毁
XC_API void WINAPI XEle_RedrawEle(HELE hEle,BOOL bImmediately=FALSE); //重绘元素
XC_API void WINAPI XEle_RedrawRect(HELE hEle,RECT *pRect); //元素重绘指定区域
XC_API void WINAPI XEle_ShowEle(HELE hEle,BOOL bShow);
XC_API BOOL WINAPI XEle_IsBkTransparent(HELE hEle); //元素背景是否透明
XC_API BOOL WINAPI XEle_IsFocus(HELE hEle); //元素是否拥有焦点
XC_API BOOL WINAPI XEle_IsShowEle(HELE hEle); //元素是否显示
XC_API BOOL WINAPI XEle_IsHitChildEle(HELE hEle,POINT *pPt); //判断是否点击在子元素上
XC_API BOOL WINAPI XEle_IsChildEle(HELE hEle,HELE hChild);  //判断指定元素是否为子元素
XC_API void WINAPI XEle_SetUserData(HELE hEle,int data);  //设置用户数据
XC_API UINT WINAPI XEle_SetTimerEx(HELE hEle,UINT nIDEvent,UINT uElapse,int userData=0);
XC_API BOOL WINAPI XEle_KillTimerEx(HELE hEle,UINT nIDEvent);
XC_API void WINAPI XEle_SetRect(HELE hEle,in_ RECT *pRect,BOOL bRedraw=FALSE);
XC_API void WINAPI XEle_GetClientRect(HELE hEle,out_ RECT *pRect);   //元素客户区坐标 xy(0,0) ,如果元素有边框,包含边框区域
XC_API void WINAPI XEle_GetRect(HELE hEle,out_ RECT *pRect);         //基于父元素坐标
XC_API void WINAPI XEle_GetWndClientRect(HELE hEle,out_ RECT *pRect); //元素基于窗口客户区坐标(不包含非客户区)
XC_API void WINAPI XEle_GetNCWndRect(HELE hEle,out_ RECT *pRect); //基于窗口非客户区坐标(包含非客户区)
XC_API void WINAPI XEle_PointToParent(HELE hEle,in_out_ POINT *pPt); 
XC_API void WINAPI XEle_PointToWndClient(HELE hEle,in_out_ POINT *pPt);     //元素坐标点转换到窗口客户区坐标点(不包含非客户区)
XC_API void WINAPI XEle_PointToNCWnd(HELE hEle,in_out_ POINT *pPt);
XC_API void WINAPI XEle_PointNCWndToEle(HELE hEle,in_out_ POINT *pPt);
XC_API void WINAPI XEle_PointWndClientToEle(HELE hEle,in_out_ POINT *pPt);
XC_API void WINAPI XEle_RectToWndClient(HELE hEle,in_out_ RECT *pRect);
XC_API void WINAPI XEle_RectToNCWnd(HELE hEle,in_out_ RECT *pRect);
XC_API void WINAPI XEle_SetTextColor(HELE hEle,COLORREF color); //设置文本颜色
XC_API COLORREF WINAPI XEle_GetTextColor(HELE hEle); //获取文本颜色
XC_API void WINAPI XEle_EnableMouseThrough(HELE hEle,BOOL bEnable);  //启用鼠标穿透元素
XC_API void WINAPI XEle_SetAlpha(HELE hEle,int alpha);  //设置元素透明度 0-255
XC_API HXCGUI WINAPI XFlash_Create(HWINDOW hWindow);
XC_API void  WINAPI XFlash_OpenFlashFile(HXCGUI hFlash,wchar_t *pFlashFile);
XC_API void* WINAPI XFlash_GetControl(HXCGUI hFlash);//获取控件接口
XC_API void  WINAPI XFlash_Destroy(HXCGUI hFlash);
XC_API HFONTX WINAPI XFont_Create(int size);//创建字体
XC_API HFONTX WINAPI XFont_Create2(wchar_t *pName=L"宋体",int size=12,BOOL bBold=FALSE,BOOL bItalic=FALSE,BOOL bUnderline=FALSE,BOOL bStrikeOut=FALSE);
XC_API HFONTX WINAPI XFont_CreateEx(LOGFONTW *pFontInfo);
XC_API void  WINAPI XFont_Destroy(HFONTX hFontX);  //销毁字体
XC_API HFONT WINAPI XFont_GetHFONT(HFONTX hFontX);
XC_API HWINDOW WINAPI XFrameWnd_CreateWindow(int x,int y,int cx,int cy,wchar_t *pTitle,HWND hWndParent=NULL,int XCStyle=XC_SY_DEFAULT);
XC_API BOOL WINAPI XFrameWnd_AddPane(HWINDOW hWindow,HELE hPaneDest,HELE hPaneNew,align_type_ align=align_any,int scale=50);
XC_API HPANE_GROUP WINAPI XFrameWnd_MergePane(HWINDOW hWindow,HELE hPaneDest,HELE hPaneNew,int proportion=50);
XC_API BOOL WINAPI XFrameWnd_MergePaneToGroup(HWINDOW hWindow,HPANE_GROUP hGroup,HELE hPaneNew,int proportion=50); //窗格合并到组
XC_API void WINAPI XFrameWnd_AdjustLayout(HWINDOW hWindow,BOOL bFixedSize=FALSE);
XC_API void WINAPI XFrameWnd_GetLayoutAreaRect(HWINDOW hWindow,out_ RECT *pRect); //获取客户区布局区域坐标
XC_API HELE WINAPI XFrameWnd_GetActivatePane(HWINDOW hWindow);//获取框架窗口内激活的窗格,不包含浮动窗格
XC_API HELE WINAPI XGif_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XGif_SetImage(HELE hEle,wchar_t  *pImageName);
XC_API void WINAPI XGif_SetImageRes(HELE hEle,int id,wchar_t *pType);
XC_API void WINAPI XGif_SetImageZip(HELE hEle,wchar_t *pZipFileName,wchar_t *pImageName,wchar_t *pPassword=NULL);
XC_API HELE WINAPI XGBox_Create(int x, int y, int cx, int cy,wchar_t *pTitle,HXCGUI hParent=NULL); //创建
XC_API wchar_t* WINAPI XGBox_GetText(HELE hEle);
XC_API void WINAPI XGBox_SetText(HELE hEle,wchar_t *pText);
XC_API HIMAGE WINAPI XImage_LoadFile(wchar_t *pImageName,BOOL bStretch=FALSE);//从文件中加载图片
XC_API HIMAGE WINAPI XImage_LoadRes(int id,wchar_t *pType,BOOL bStretch=FALSE);//从资源中加载图片
XC_API HIMAGE WINAPI XImage_LoadZip(wchar_t *pZipFileName,wchar_t *pImageName,wchar_t *pPassword=NULL,BOOL bStretch=FALSE);//从ZIP中加载图片
XC_API HIMAGE WINAPI XImage_LoadFileAdaptive(wchar_t *pImageName,int x1,int x2,int y1,int y2);//从文件中加载图片
XC_API HIMAGE WINAPI XImage_LoadResAdaptive(int id,wchar_t *pType,int x1,int x2,int y1,int y2);//从资源中加载图片
XC_API HIMAGE WINAPI XImage_LoadZipAdaptive(wchar_t *pZipFileName,wchar_t *pImageName,wchar_t *pPassword,int x1,int x2,int y1,int y2);//从ZIP中加载图片
XC_API HIMAGE WINAPI XImage_LoadFileRect(wchar_t *pImageName,int x,int y,int cx,int cy);
XC_API HIMAGE WINAPI XImage_LoadFileFromExtractIcon(wchar_t *pImageName);
XC_API HIMAGE WINAPI XImage_LoadFileFromHICON(HICON hIcon);
XC_API HIMAGE WINAPI XImage_LoadFileFromHBITMAP(HBITMAP hBitmap);
XC_API BOOL WINAPI XImage_IsStretch(HIMAGE hImage);   //是否拉伸图片
XC_API BOOL WINAPI XImage_IsAdaptive(HIMAGE hImage);  //是否为自适应图片
XC_API BOOL WINAPI XImage_IsTile(HIMAGE hImage);      //是否为平铺图片
XC_API BOOL WINAPI XImage_SetDrawType(HIMAGE hImage,int type);//设置图片绘制类型
XC_API BOOL WINAPI XImage_SetDrawTypeAdaptive(HIMAGE hImage,int x1,int x2,int y1,int y2);//设置图片自适应
XC_API void WINAPI XImage_SetTranColor(HIMAGE hImage,COLORREF color); //设置透明色
XC_API void WINAPI XImage_SetTranColorEx(HIMAGE hImage,COLORREF color,byte tranColor); //设置透明色
XC_API void WINAPI XImage_EnableTranColor(HIMAGE hImage,BOOL bEnable); //启用透明色
XC_API void WINAPI XImage_EnableAutoDestroy(HIMAGE hImage,BOOL bEnable); //启用或关闭自动销毁,当与UI元素关联时有效
XC_API int WINAPI XImage_GetDrawType(HIMAGE hImage);
XC_API int WINAPI XImage_GetWidth(HIMAGE hImage);
XC_API int WINAPI XImage_GetHeight(HIMAGE hImage);
XC_API void WINAPI XImage_Destroy(HIMAGE hImage);
XC_API HXCGUI WINAPI XImageList_Create(int cx,int cy);
XC_API void WINAPI XImageList_Destroy(HXCGUI hImageList); //销毁
XC_API void WINAPI XImageList_AddImage(HXCGUI hImageList,HIMAGE hImage); //添加图片
XC_API int  WINAPI XImageList_GetWidth(HXCGUI hImageList);   //获取图片宽度
XC_API int  WINAPI XImageList_GetHeight(HXCGUI hImageList);  //获取图片高度
XC_API int  WINAPI XImageList_GetCount(HXCGUI hImageList);   //获取图片数量
XC_API HIMAGE WINAPI XImageList_GetImage(HXCGUI hImageList,int index); //获取图片
XC_API void WINAPI XImageList_DeleteIndex(HXCGUI hImageList,int index); //删除指定图片
XC_API void WINAPI XImageList_DeleteAll(HXCGUI hImageList);  //删除全部图片
XC_API void WINAPI XImageList_DrawImage(HXCGUI hImageList,HDRAW hDraw,int index, int x, int y);
XC_API void WINAPI XImageList_DrawImage2(HXCGUI hImageList,HDRAW hDraw,int index, RECT *pRect);
XC_API void WINAPI XImageList_EnableFixedSize(HXCGUI hImageList,BOOL bEnable); //绘制固定大小 Fixed-size
XC_API BOOL WINAPI XImageList_IsFixedSize(HXCGUI hImageList);
XC_API void WINAPI XList_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘列表项
XC_API void WINAPI XList_SetUserDrawItemHeaderEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘列表头项
XC_API HELE WINAPI XList_Create(int x,int y,int cx,int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XList_AddColumn(HELE hEle,int width,wchar_t *pText,int imageId=-1); //增加列
XC_API int WINAPI XList_AddItem(HELE hEle,wchar_t *pText, int imageId=-1);  //增加项
XC_API BOOL WINAPI XList_InsertColumn(HELE hEle,int index,int width,wchar_t *pText,int imageId=-1);  //插入列
XC_API BOOL WINAPI XList_InsertItem(HELE hEle,int index,wchar_t *pText,int imageId=-1);  //插入项
XC_API BOOL WINAPI XList_SetItemText(HELE hEle,int item,int subItem,wchar_t *pText,int imageId=-1); //设置子项
XC_API BOOL WINAPI XList_SetColumnWidth(HELE hEle,int index, int width);   //设置列宽
XC_API BOOL WINAPI XList_SetItemImage(HELE hEle,int item,int subItem,int imageId);   //设置子项图片
XC_API void WINAPI XList_SetImageList(HELE hEle,HXCGUI hImageList); //设置图片列表
XC_API void WINAPI XList_SetItemHeight(HELE hEle,int height);  //设置项高度
XC_API void WINAPI XList_SetHeaderHeight(HELE hEle,int height); //设置列表头高度
XC_API BOOL WINAPI XList_SetSelectItem(HELE hEle,int index);   //设置选择项
XC_API void WINAPI XList_SetSelectItemAll(HELE hEle);     //全选
XC_API void WINAPI XList_SetSpacingLeft(HELE hEle,int spacing);  //设置内容左间距
XC_API void WINAPI XList_SetSpacingRight(HELE hEle,int spacing); //设置内容右间距
XC_API void WINAPI XList_SetItemData(HELE hEle,int index,int data);   //设置用户数据
XC_API BOOL WINAPI XList_SetItemBindEle(HELE hEle,int item,int subItem,itemBindEle_ *pInfo); //绑定元素
XC_API void WINAPI XList_SetColumnMinWidth(HELE hEle,int index,int minWidth); //设置列最小宽度
XC_API int WINAPI XList_GetHeaderHeight(HELE hEle);        //获取列表头高度
XC_API wchar_t* WINAPI XList_GetHeaderItemText(HELE hEle,int index);  //获取列表头项文本
XC_API int WINAPI XList_GetColumnWidth(HELE hEle,int index);     //获取列宽
XC_API int WINAPI XList_GetSpacingLeft(HELE hEle);  //获取内容左间距
XC_API int WINAPI XList_GetSpacingRight(HELE hEle); //获取内容右间距
XC_API HXCGUI WINAPI XList_GetImageList(HELE hEle);     //获取图片列表
XC_API wchar_t* WINAPI XList_GetItemText(HELE hEle,int index, int subItem); //获取项文本
XC_API int WINAPI XList_GetItemImage(HELE hEle,int item,int subItem); //获取子项图片
XC_API int WINAPI XList_GetItemHeight(HELE hEle);       //获取项高
XC_API int WINAPI XList_GetItemData(HELE hEle,int index);   //设置用户数据
XC_API int WINAPI XList_GetSelectCount(HELE hEle);      //获取选择项数量
XC_API int WINAPI XList_GetSelectItem(HELE hEle);       //获取选择项
XC_API int WINAPI XList_GetSelectAllItem(HELE hEle,out_ int *pArray, int arrayLength);  //获取所有选择项
XC_API int WINAPI XList_GetItemCount(HELE hEle);        //获取项数量
XC_API BOOL WINAPI XList_GetHeaderItemRect(HELE hEle,int item,out_ RECT *pRect); //获取列表头项坐标
XC_API BOOL WINAPI XList_GetSubItemRect(HELE hEle,int item,int sub,out_ RECT *pRect);//获取子项坐标
XC_API BOOL WINAPI XList_GetItemCheckRect(HELE hEle,int item,out_ RECT *pRect); //获取复选按钮坐标
XC_API int  WINAPI XList_GetItemBindEleCount(HELE hEle,int item,int subItem);
XC_API BOOL WINAPI XList_GetItemBindEleInfo(HELE hEle,int item,int subItem,out_ itemBindEle_ *pInfo,int index);//获取绑定项信息
XC_API void WINAPI XList_CancelSelectAll(HELE hEle); //取消选择所有项
XC_API void WINAPI XList_CancelSelect(HELE hEle,int index); //取消选择指定项
XC_API BOOL WINAPI XList_DeleteItem(HELE hEle,int index);  //删除项
XC_API BOOL WINAPI XList_DeleteColumn(HELE hEle,int index);  //删除列
XC_API void WINAPI XList_DeleteAllItems(HELE hEle);  //删除所有项
XC_API void WINAPI XList_DeleteAllColumns(HELE hEle);   //删除所有列
XC_API void WINAPI XList_EnableGrid(HELE hEle,BOOL bGrid); //启用网格样式
XC_API int  WINAPI XList_HitTest(HELE hEle,POINT *pPt);  //测试鼠标点在哪个项上,-1没有在任何项上
XC_API BOOL WINAPI XList_HitTestEx(HELE hEle,POINT *pPt,out_ int *item,out_ int *sub); //测试鼠标点在哪个项上及子项,-1没有在任何项上
XC_API void WINAPI XList_ShowHeader(HELE hEle,BOOL bShow);//显示隐藏列表头
XC_API void WINAPI XList_SetUserDrawItem(HELE hEle,pFunList_DrawItem pFunDrawItem); //设置用户自绘列表项
XC_API void WINAPI XList_SetUserDrawItemHeader(HELE hEle,pFunListHeader_DrawItem pFunDrawItem); //设置用户自绘列表头项
XC_API void WINAPI XList_EnableCheckBox(HELE hEle,BOOL bEnable); //启用复选框
XC_API void WINAPI XList_EnableMultilineSelect(HELE hEle,BOOL bEnable);  //启用关闭多行选择 XEdit_EnableMultiLine
XC_API void WINAPI XLsit_EnableLineHighlight(HELE hEle,BOOL bEnable); //启用或关闭行高亮显示
XC_API BOOL WINAPI XList_IsItemCheck(HELE hEle,int index); //判断项的复选框是否勾选
XC_API void WINAPI XList_SetItemCheck(HELE hEle,int index, BOOL bCheck); //设置项的复选框
XC_API void WINAPI XListBox_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘列表框项
XC_API HELE WINAPI XListBox_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int  WINAPI XListBox_AddString(HELE hEle,wchar_t *pText,int imageId=-1);  //增加一个字符串到列表
XC_API BOOL WINAPI XListBox_InsertString(HELE hEle,int index,wchar_t *pText,int imageId=-1); //插入项
XC_API void WINAPI XListBox_EnableCheckBox(HELE hEle,BOOL bEnable); //启用复选框
XC_API void WINAPI XLsitBox_EnableLineHighlight(HELE hEle,BOOL bEnable);  //启用或关闭行高亮显示
XC_API wchar_t* WINAPI XListBox_GetItemText(HELE hEle,int index);   //获取指定行文本
XC_API int  WINAPI XListBox_GetItemHeight(HELE hEle);              //获取行高
XC_API int  WINAPI XListBox_GetSelectItem(HELE hEle);              //获取选择行
XC_API int  WINAPI XListBox_GetItemImage(HELE hEle,int index); //获取项图标ID
XC_API int  WINAPI XListBox_GetItemCount(HELE hEle); //获取项数量
XC_API HXCGUI WINAPI XListBox_GetImageList(HELE hEle); //获取图片列表
XC_API BOOL WINAPI XListBox_GetItemRect(HELE hEle,in_ int index,out_ RECT *pRect);  //获取项坐标...
XC_API int  WINAPI XListBox_HitTest(HELE hEle,POINT *pPt);  //测试鼠标点在哪个项上,-1没有在任何项上
XC_API int  WINAPI XListBox_GetItemData(HELE hEle,int index); //获取项绑定数据
XC_API void WINAPI XListBox_SetItemText(HELE hEle,int index, wchar_t *pText);  //设置指定行文本
XC_API void WINAPI XListBox_SetSelectItem(HELE hEle,int index);    //设置选择行
XC_API void WINAPI XListBox_SetItemHeight(HELE hEle,int height);   //设置行高
XC_API void WINAPI XListBox_SetImageList(HELE hEle,HXCGUI hImageList); //设置图标列表
XC_API void WINAPI XListBox_SetItemImage(HELE hEle,int index,int imageId); //设置项图标ID
XC_API void WINAPI XListBox_SetItemCheck(HELE hEle,int index, BOOL bCheck); //设置项的复选框
XC_API BOOL WINAPI XListBox_SetItemBindEle(HELE hEle,int index,itemBindEle_ *pInfo); //绑定元素
XC_API void WINAPI XListBox_SetItemData(HELE hEle,int index,int data); //设置项绑定数据
XC_API void WINAPI XListBox_SetSelectItemColor(HELE hEle,COLORREF color); //设置选择项颜色
XC_API void WINAPI XListBox_SetItemMouseStayColor(HELE hEle,COLORREF color);//设置鼠标停留高亮项颜色
XC_API void WINAPI XListBox_DeleteItem(HELE hEle,int index);  //删除行
XC_API void WINAPI XListBox_DeleteAll(HELE hEle);  //删除所有行
XC_API BOOL WINAPI XListBox_IsItemCheck(HELE hEle,int index);      //判断项的复选框是否勾选
XC_API void WINAPI XListBox_Adjust(HELE hEle);
XC_API void WINAPI XListBox_SetUserDrawItem(HELE hEle,pFunListBox_DrawItem pFunDrawItem); //设置用户自绘列表框项
XC_API void WINAPI XListView_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘项
XC_API void WINAPI XListView_SetUserDrawGroupEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘组
XC_API HELE WINAPI XListView_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int  WINAPI XListView_AddItem(HELE hEle,wchar_t *pName,int imageID=-1,int groupIndex=-1); //增加项
XC_API int  WINAPI XListView_AddGroup(HELE hEle,wchar_t *pName,BOOL bExpand=TRUE); //增加组
XC_API int  WINAPI XListView_InsertItem(HELE hEle,int groupIndex,int itemIndex,wchar_t *pName,int imageID=-1);  //插入项
XC_API int  WINAPI XListView_InsertGroup(HELE hEle,int groupIndex,wchar_t *pName,BOOL bExpand=TRUE);  //插入组
XC_API void WINAPI XListView_SetImageList(HELE hEle,HXCGUI hImageList);
XC_API BOOL WINAPI XListView_SetItemData(HELE hEle,int groupIndex, int itemIndex,int data); //设置项绑定数据
XC_API BOOL WINAPI XListView_SetGroupData(HELE hEle,int groupIndex,int data); //设置组绑定数据
XC_API BOOL WINAPI XListView_SetSelectItem(HELE hEle,int goupIndex,int itemIndex,BOOL bSelect);//设置选择项
XC_API BOOL WINAPI XListView_SetItemText(HELE hEle,int groupIndex,int itemIndex,wchar_t *pText);//设置项文本
XC_API BOOL WINAPI XListView_SetGroupText(HELE hEle,int groupIndex,wchar_t *pText);//设置组文本
XC_API BOOL WINAPI XListView_SetItemIcon(HELE hEle,int groupIndex,int itemIndex,int imageID);//设置项图标ID
XC_API void WINAPI XListView_SetIconSize(HELE hEle,int cx,int cy); //设置图标区域大小,并不是图标的大小.
XC_API void WINAPI XListView_SetItemBorderSpacing(HELE hEle,int left,int top,int right,int bottom); //设置项边间隔
XC_API void WINAPI XListView_SetColumnSpacing(HELE hEle,int width); //设置项列间隔
XC_API void WINAPI XListView_SetRowSpacing(HELE hEle,int height);  //设置项行间隔
XC_API void WINAPI XListView_SetItemIconTextSpacing(HELE hEle,int height);  //设置图标与文本间隔
XC_API void WINAPI XListView_SetViewLeftAlign(HELE hEle,int size);  //设置视图左对齐
XC_API void WINAPI XListView_SetViewTopAlign(HELE hEle,int size); //设置视图上对齐
XC_API void WINAPI XListView_SetGroupHeight(HELE hEle,int height); //设置组高度
XC_API void WINAPI XListView_GetIconSize(HELE hEle,out_ SIZE *pSize); //获取图标区域大小,并不是图标的大小.
XC_API int  WINAPI XListView_GetItemBorderLeft(HELE hEle); //获取项边间隔
XC_API int  WINAPI XListView_GetItemBorderTop(HELE hEle); 
XC_API int  WINAPI XListView_GetItemBorderRight(HELE hEle); 
XC_API int  WINAPI XListView_GetItemBorderBottom(HELE hEle); 
XC_API int  WINAPI XListView_GetColumnSpacing(HELE hEle); //获取项列间隔
XC_API int  WINAPI XListView_GetRowSpacing(HELE hEle);  //获取项行间隔
XC_API int  WINAPI XListView_GetItemIconTextSpacing(HELE hEle);  //获取图标与文本间隔
XC_API int  WINAPI XListView_GetViewLeftAlign(HELE hEle);  //获取视图左对齐
XC_API int  WINAPI XListView_GetViewTopAlign(HELE hEle); //获取视图上对齐
XC_API int  WINAPI XListView_GetGroupHeight(HELE hEle); //获取组高度
XC_API void  WINAPI XListView_GetSelectItem(HELE hEle,out_ int *pGroupIndex,out_ int *pItemIndex);    //获取选择项
XC_API int  WINAPI XListView_GetSelectCount(HELE hEle);  //获取选择项数量
XC_API int  WINAPI XListView_GetSelectAllItem(HELE hEle,int *pArrayGroupIndex,int *pArrayItemIndex,int arrayLength); //获取所有选择项
XC_API int  WINAPI XListView_GetGroupCount(HELE hEle); //获取组数量
XC_API int  WINAPI XListView_GetGroupMemberCount(HELE hEle,int groupIndex); //获取组成员数量
XC_API int  WINAPI XListView_GetUngroupMemberCount(HELE hEle);//获取未分组项数量
XC_API HXCGUI WINAPI XListView_GetImageList(HELE hEle); //获取图片列表
XC_API BOOL WINAPI XListView_GetItemRect(HELE hEle,int groupIndex,int itemIndex,out_ RECT *pRect); //获取项坐标
XC_API BOOL WINAPI XListView_GetItemIconRect(HELE hEle,int groupIndex,int itemIndex,out_ RECT *pRect);//获取项图标坐标
XC_API BOOL WINAPI XListView_GetItemTextRect(HELE hEle,int groupIndex,int itemIndex,out_ RECT *pRect); //获取项文本坐标
XC_API wchar_t* WINAPI XListView_GetItemText(HELE hEle,int groupIndex,int itemIndex);//获取项文本
XC_API int  WINAPI XListView_GetItemIcon(HELE hEle,int groupIndex,int itemIndex);//获取项图标ID
XC_API wchar_t* WINAPI XListView_GetGroupText(HELE hEle,int groupIndex);//获取组文本
XC_API BOOL WINAPI XListView_GetGroupRect(HELE hEle,int groupIndex,out_ RECT *pRect);//获取组坐标
XC_API int  WINAPI XListView_GetItemData(HELE hEle,int groupIndex,int itemIndex); //获取项绑定数据
XC_API int  WINAPI XListView_GetGroupData(HELE hEle,int groupIndex); //获取组绑定数据
XC_API BOOL WINAPI XListView_DeleteItem(HELE hEle,int groupIndex,int itemIndex); //删除项
XC_API BOOL WINAPI XListView_DeleteGroup(HELE hEle,int groupIndex); //删除组
XC_API void WINAPI XListView_DeleteAllGroups(HELE hEle); //删除所有组
XC_API void WINAPI XListView_DeleteAll(HELE hEle); //删除所有,清空数据
XC_API int WINAPI XListView_IsItemSelect(HELE hEle,int groupIndex,int itemIndex);//检查项是否被选择
XC_API BOOL WINAPI XListView_HitTest(HELE hEle,POINT *pPt,out_ int *pGroupIndex,out_ int *pItemIndex);//测试用户点击,组,项
XC_API int WINAPI XListView_IsGroupExpand(HELE hEle,int groupIndex);//判断组是否展开
XC_API BOOL WINAPI XListView_SetGroupExpand(HELE hEle,int groupIndex,BOOL bExpand); //展开指定组
XC_API void WINAPI XListView_EnableMultiSelect(HELE hEle,BOOL bEnable); //启用关闭多项选择
XC_API void WINAPI XListView_EnableExpandButton(HELE hEle,BOOL bEnable); //启用/关闭展开按钮
XC_API void WINAPI XListView_EnableDragItem(HELE hEle,BOOL bEnable);  //启用或关闭拖动项功能
XC_API void WINAPI XListView_CancelSelectItem(HELE hEle,int groupIndex,int itemIndex); //取消选择指定项
XC_API void WINAPI XListView_CancelSelectAll(HELE hEle); //取消选择所有项
XC_API void WINAPI XListView_SetUserDrawItem(HELE hEle,pFunListView_DrawItem pFunDrawItem); //设置用户自绘项
XC_API void WINAPI XListView_SetUserDrawGroup(HELE hEle,pFunListView_DrawGroup pFunDrawGroup); //设置用户自绘组
XC_API void WINAPI XListView_SetItemImageSelect(HELE hEle,int groupIndex,int itemIndex,HIMAGE hImage);
XC_API void WINAPI XListView_SetItemImageStay(HELE hEle,int groupIndex,int itemIndex,HIMAGE hImage);
XC_API void WINAPI XListView_Adjust(HELE hEle); //调整布局
XC_API void WINAPI XMenu_SetUserDrawItemEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘菜单项
XC_API void WINAPI XMenu_SetUserDrawBGEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘菜背景
XC_API void WINAPI XMenu_SetUserUpdateUIEx(HMENUX hMenu,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
XC_API HMENUX WINAPI XMenu_Create();
XC_API void WINAPI XMenu_AddItem(HMENUX hMenu,int id,wchar_t *pText,int parentId=XMENU_ROOT,int uFlags=0); //添加菜单项
XC_API void WINAPI XMenu_AddItemImage(HMENUX hMenu,int id,wchar_t *pText,int parentId,int uFlags,HIMAGE hImage);
XC_API void WINAPI XMenu_InsertItem(HMENUX hMenu,int id,wchar_t *pText,int uFlags,int insertID);
XC_API void WINAPI XMenu_InsertItemImage(HMENUX hMenu,int id,wchar_t *pText,int uFlags,int insertID,HIMAGE hImage);
XC_API void WINAPI XMenu_DeleteItem(HMENUX hMenu,int id);
XC_API void WINAPI XMenu_SetAutoDestroy(HMENUX hMenu,BOOL bAuto); //是否自动销毁对象,默认弹出菜单关闭后自动销毁
XC_API void WINAPI XMenu_SetItemHeight(HMENUX hMenu,int height); //设置菜单项高度
XC_API BOOL WINAPI XMenu_SetBGImage(HMENUX hMenu,HIMAGE hImage);//设置菜单背景图片
XC_API BOOL WINAPI XMenu_SetItemImage(HMENUX hMenu,int id,HIMAGE hImage); //设置项图标
XC_API BOOL WINAPI XMenu_SetItemText(HMENUX hMenu,int id,wchar_t *pText); //设置项文本
XC_API void WINAPI XMenu_SetItemFlags(HMENUX hMenu,int id,int uFlags);   //设置项属性
XC_API void WINAPI XMenu_SetItemCheck(HMENUX hMenu,int id,BOOL bCheck);
XC_API BOOL WINAPI XMenu_IsItemCheck(HMENUX hMenu,int id);
XC_API int  WINAPI XMenu_GetItemFlags(HMENUX hMenu,int id);   //获取项属性
XC_API int  WINAPI XMenu_GetItemHeight(HMENUX hMenu);  //获取菜单项高度
XC_API int  WINAPI XMenu_GetItemCount(HMENUX hMenu); //获取菜单项数量,包含子菜单项
XC_API wchar_t* WINAPI XMenu_GetItemText(HMENUX hMenu,int id); //获取菜单项文本
XC_API int  WINAPI XMenu_GetItemLeftWidth(HMENUX hMenu); //获取左侧宽度
XC_API int  WINAPI XMenu_GetItemLeftText(HMENUX hMenu);  //获取菜单项文本左间隔
XC_API BOOL WINAPI XMenu_Popup(HMENUX hMenu,HWND hParentWnd,int x,int y,HELE hParentEle=NULL,int uFlags=NULL); //弹出菜单
XC_API void WINAPI XMenu_Destroy(HMENUX hMenu);
XC_API void WINAPI XMenu_CloseMenu(HMENUX hMenu);
XC_API void WINAPI XMenu_SetUserDrawItem(HMENUX hMenu,pFunMenu_DrawItem pFunDrawItem); //设置用户自绘项
XC_API void WINAPI XMenu_SetUserDrawBG(HMENUX hMenu,pFunMenu_DrawBG pFunDrawBG); //设置用户自绘菜单背景
XC_API void WINAPI XMenu_SetUserUpdateUI(HMENUX hMenu,pFunMenu_UpdateUI pUpdateUI);
XC_API HELE WINAPI XMenuBar_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);  //创建按钮
XC_API int WINAPI XMenuBar_AddButton(HELE hEle,wchar_t *pText);     //增加弹出菜单按钮
XC_API int WINAPI XMenuBar_InsertButton(HELE hEle,wchar_t *pText,int index);     //插入弹出菜单按钮
XC_API void WINAPI XMenuBar_AddMenuItem(HELE hEle,int index,int id,wchar_t *pText,int parentId=XMENU_ROOT,int uFlags=0);
XC_API void WINAPI XMenuBar_AddMenuItemImage(HELE hEle,int index,int id,wchar_t *pText,int parentId,int uFlags,HIMAGE hImage); //增加菜单项
XC_API void WINAPI XMenuBar_InsertMenuItem(HELE hEle,int index,int id,wchar_t *pText,int uFlags,int insertID); //插入菜单项,插入到ID为insertID菜单项前面位置
XC_API void WINAPI XMenuBar_InsertMenuItemImage(HELE hEle,int index,int id,wchar_t *pText,int uFlags,int insertID,HIMAGE hImage); //增加菜单项
XC_API void WINAPI XMenuBar_DeleteMenuItem(HELE hEle,int index,int id); //删除菜单项
XC_API void WINAPI XMenuBar_SetButtonHeight(HELE hEle,int height); //设置弹出菜单按钮高度
XC_API HELE WINAPI XMenuBar_GetButton(HELE hEle,int index);  //获取弹出菜单按钮句柄
XC_API HMENUX WINAPI XMenuBar_GetMenu(HELE hEle,int index); //获取菜单句柄
XC_API void WINAPI XMenuBar_DeleteButton(HELE hEle,int index); //删除菜单项并且销毁,同时该按钮下的弹出菜单也被销毁
XC_API void WINAPI XMenuBar_SetImage(HELE hEle,HIMAGE hImage=NULL);
XC_API HWINDOW WINAPI XModalWnd_CreateWindow(int width,int height,wchar_t *pTitle,HWND hWndParent,int XCStyle=XC_SY_MODAL_WINDOW);//基于父窗口坐标
XC_API int WINAPI XModalWnd_DoModal(HWINDOW hWindow);     //启动模态窗口
XC_API void WINAPI XModalWnd_DoOk(HWINDOW hWindow);       //确定
XC_API void WINAPI XModalWnd_DoCancel(HWINDOW hWindow);   //取消
XC_API int WINAPI XMessageBox(HXCGUI hXCGUI, wchar_t *pText, wchar_t *pCaption=L"炫彩界面库-提示框",int type=XMB_OK);
XC_API HELE WINAPI XMonthCal_Create(int x, int y,int cx,int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XMonthCal_SetSpacingLeft(HELE hEle,int left); //左对齐间距
XC_API void WINAPI XMonthCal_SetSpacingTop(HELE hEle,int top); //上对齐间距
XC_API void WINAPI XMonthCal_SetDate(HELE hEle,int year,int month,int day);  //设置时间
XC_API int WINAPI XMonthCal_GetYear(HELE hEle);
XC_API int WINAPI XMonthCal_GetMonth(HELE hEle);
XC_API int WINAPI XMonthCal_GetDay(HELE hEle);
XC_API HELE WINAPI XDateTime_Create(int x, int y,int cx,int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XDateTime_SetDate(HELE hEle,int year,int month,int day);  //设置时间
XC_API int WINAPI XDateTime_GetYear(HELE hEle);
XC_API int WINAPI XDateTime_GetMonth(HELE hEle);
XC_API int WINAPI XDateTime_GetDay(HELE hEle);
XC_API HELE WINAPI XDateTime_GetButton(HELE hEle);  //获取下拉按钮
XC_API void WINAPI XDateTime_SetImage(HELE hEle,HIMAGE hImage);
XC_API HELE WINAPI XOutlook_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XOutlook_AddView(HELE hEle,HELE hView,wchar_t *pTitle);
XC_API void WINAPI XOutlook_Adjust(HELE hEle);
XC_API void WINAPI XOutlook_Expand(HELE hEle,int index);  //展开指定项
XC_API int WINAPI XOutlook_GetExpand(HELE hEle); //获取当前展开的项索引
XC_API HELE WINAPI XPane_Create(wchar_t *pTitle=NULL,HWINDOW hFrameWnd=NULL);  //创建按钮
XC_API wchar_t* WINAPI XPane_GetTitle(HELE hEle);
XC_API void WINAPI XPane_Hide(HELE hEle);      //隐藏窗格
XC_API void WINAPI XPane_Dock(HELE hEle);      //停靠窗格,自动隐藏
XC_API void WINAPI XPane_Lock(HELE hEle);      //锁定窗格
XC_API void WINAPI XPane_popup(HELE hEle);     //弹出窗格,当在码头上
XC_API void WINAPI XPane_Show(HELE hEle);     //隐藏-显示浮动窗格
XC_API HPANE_GROUP WINAPI XPane_GetGroup(HELE hEle); //获取窗格所属组,如果没有组返回空
XC_API BOOL WINAPI XPane_Destroy(HELE hEle); //销毁窗格 
XC_API pane_state_ WINAPI XPane_GetState(HELE hEle);  //获取状态
XC_API void WINAPI XPane_DragPane(HELE hEle,POINT *pPtDown); //拖动窗格
XC_API void WINAPI XPane_DragGroup(HELE hEle,POINT *pPtDown);//拖动窗格组
XC_API void WINAPI XPane_FloatPane(HELE hEle); //浮动窗格
XC_API void WINAPI XPane_SetView(HELE hEle,HELE hView);
XC_API void WINAPI XPane_SetToolBar(HELE hEle,HELE hToolBar); //设置工具条
XC_API void WINAPI XPane_SetMenuBar(HELE hEle,HELE hMenuBar); //设置菜单条
XC_API void WINAPI XPane_SetSpacing(HELE hEle,int left, int top, int right, int bottom);
XC_API void WINAPI XPane_SetFixedSize(HELE hEle,BOOL bFixedSize); //设置窗格固定大小,如果为FALSE非固定大小
XC_API void WINAPI XPane_SetTitle(HELE hEle,wchar_t *pTitle);
XC_API void WINAPI XPane_SetActivate(HELE hEle,BOOL bActivate); //激活窗格
XC_API BOOL WINAPI XPane_IsActivate(HELE hEle); //判断窗格是否激活,当窗格在框架内有效
XC_API void WINAPI XPane_SetCaptionHeight(HELE hEle,int height);//设置标题栏高度
XC_API int  WINAPI XPane_GetCaptionHeight(HELE hEle);//获取标题栏高度
XC_API HELE WINAPI XPane_GetButtonClose(HELE hEle); //获取关闭按钮
XC_API HELE WINAPI XPane_GetButtonLock(HELE hEle); //获取锁定按钮
XC_API HELE WINAPI XPane_GetButtonMenu(HELE hEle); //获取菜单按钮
XC_API void WINAPI XFloatWnd_EnableLock(HWINDOW hWindow,BOOL bEnable); //启用关闭锁定功能,当关闭锁定功能后,用户拖动浮动窗格不能锁定到框架窗口中
XC_API HELE WINAPI XPic_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XPic_SetImage(HELE hEle,HIMAGE hImage);  //设置图片
XC_API HELE WINAPI XProgBar_Create(int x, int y, int cx, int cy,BOOL bHorizon,HXCGUI hParent=NULL);
XC_API void WINAPI XProgBar_SetRange(HELE hEle,int range);  //设置范围
XC_API void WINAPI XProgBar_SetPos(HELE hEle,int pos);   //设置当前位置
XC_API int  WINAPI XProgBar_GetRange(HELE hEle);
XC_API int  WINAPI XProgBar_GetPos(HELE hEle);
XC_API void WINAPI XProgBar_SetHorizon(HELE hEle,BOOL bHorizon); //水平显示或垂直
XC_API void WINAPI XProgBar_EnablePercent(HELE hEle,BOOL bPercent); //显示百分比
XC_API void WINAPI XProgBar_SetImage(HELE hEle,HIMAGE hImage); //背景
XC_API void WINAPI XProgBar_SetImage2(HELE hEle,HIMAGE hImage); //显示当前进度图片
XC_API HELE WINAPI XPGrid_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XPGrid_AddGroup(HELE hEle,wchar_t *pName,BOOL bExpand=TRUE); //添加分组
XC_API int WINAPI XPGrid_AddItem(HELE hEle,wchar_t *pName,int type,int groupID=-1); //添加项
XC_API int WINAPI XPGrid_AddItemString(HELE hEle,wchar_t *pName,wchar_t *pValue,int groupID=-1); //添加项
XC_API HELE WINAPI XPGrid_GetItemHEle(HELE hEle,int itemID);
XC_API BOOL WINAPI XPGrid_SetItemString(HELE hEle,int itemID,wchar_t *pText);
XC_API BOOL WINAPI XPGrid_SetItemColor(HELE hEle,int itemID,COLORREF color);
XC_API void WINAPI XPGrid_GetItemValue(HELE hEle,int itemID,wchar_t *pOut,int len);
XC_API void WINAPI XPGrid_DeleteItem(HELE hEle,int itemID);   //删除项
XC_API void WINAPI XPGrid_DeleteGroup(HELE hEle,int groupID);  //删除组
XC_API void WINAPI XPGrid_DeleteAll(HELE hEle);  //删除所有
XC_API void WINAPI XPGrid_SetSpacePoint(HELE hEle,int point);//设置分隔线基于X坐标位置
XC_API int WINAPI XPGrid_GetSelectItem(HELE hEle); //获取当前选择项
XC_API void WINAPI XPGrid_Adjust(HELE hEle); //调整布局
XC_API HELE WINAPI XPPage_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XPPage_AddLabel(HELE hEle,wchar_t *pName,HELE hPage=NULL); //添加一个标签
XC_API int WINAPI XPPage_InsertLabel(HELE hEle,int index,wchar_t *pName,HELE hPage=NULL);
XC_API void WINAPI XPPage_Adjust(HELE hEle);
XC_API BOOL WINAPI XPPage_SetBindEle(HELE hEle,int index,HELE hPage); //绑定视图元素到标签
XC_API void WINAPI XPPage_SetLabelHeight(HELE hEle,int height);  //设置标签高度
XC_API void WINAPI XPPage_SetLabelWidth(HELE hEle,int index,int width);   //设置标签宽度
XC_API void WINAPI XPPage_SetSelect(HELE hEle,int index,BOOL reDraw=TRUE);   //设置选择标签
XC_API void WINAPI XPPage_SetLabelText(HELE hEle,int index,wchar_t *pText);  //设置标签文本
XC_API void WINAPI XPPage_SetLabelSpacing(HELE hEle,int spacing);//设置标签间距, 0没有间距
XC_API void WINAPI XPPage_SetUp(HELE hEle);    //左滚动
XC_API void WINAPI XPPage_SetDown(HELE hEle);  //右滚动
XC_API int  WINAPI XPPage_GetSelect(HELE hEle);  //获取选择的标签
XC_API int  WINAPI XPPage_GetLabelHeight(HELE hEle);  //获取标签高度
XC_API int  WINAPI XPPage_GetLabelWidth(HELE hEle,int index);  //获取标签宽度
XC_API int  WINAPI XPPage_GetLabelCount(HELE hEle); //获取标签项数量
XC_API wchar_t * WINAPI XPPage_GetLabelText(HELE hEle,int index);  //获取文本
XC_API HELE WINAPI XPPage_GetLabel(HELE hEle,int index);//获取标签按钮Button
XC_API HELE WINAPI XPPage_GetLabelPage(HELE hEle,int index);//获取标签对应的页
XC_API int WINAPI XPPage_GetPageIndex(HELE hEle,HELE hPage); //检索绑定页对应标签索引
XC_API int WINAPI XPPage_GetLabelIndex(HELE hEle,HELE hLabel); //获取属性页标签按钮元素位置索引值
XC_API int WINAPI XPPage_GetLabelSpacing(HELE hEle);//获取标签间距, 0没有间距
XC_API void WINAPI XPPage_DeleteLabel(HELE hEle,int index,BOOL deletePage=FALSE);  //删除
XC_API void WINAPI XPPage_DeleteLabelAll(HELE hEle,BOOL deletePage=FALSE);  //删除所有TAB
XC_API void WINAPI XPPage_EnableScrollButton(HELE hEle,BOOL bEnable); //是否显示滚动按钮
XC_API HELE WINAPI XRadio_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);  //创建按钮
XC_API void WINAPI XRadio_SetImageLeave_UnCheck(HELE hEle,HIMAGE hImage=NULL);  //鼠标离开时图片  未选择
XC_API void WINAPI XRadio_SetImageStay_UnCheck(HELE hEle,HIMAGE hImage=NULL);   //鼠标停留时图片  未选择
XC_API void WINAPI XRadio_SetImageDown_UnCheck(HELE hEle,HIMAGE hImage=NULL);   //鼠标按下时图片  未选择
XC_API void WINAPI XRadio_SetImageDisable_UnCheck(HELE hEle,HIMAGE hImage=NULL); //按钮禁用状态图片  未选择
XC_API void WINAPI XRadio_SetImageLeave_Check(HELE hEle,HIMAGE hImage=NULL);  //鼠标离开时图片  选择
XC_API void WINAPI XRadio_SetImageStay_Check(HELE hEle,HIMAGE hImage=NULL);   //鼠标停留时图片  选择
XC_API void WINAPI XRadio_SetImageDown_Check(HELE hEle,HIMAGE hImage=NULL);   //鼠标按下时图片  选择
XC_API void WINAPI XRadio_SetImageDisable_Check(HELE hEle,HIMAGE hImage=NULL); //按钮禁用状态图片  选择
XC_API void WINAPI XRadio_SetGroupID(HELE hEle,int groupID);  //设置组ID
XC_API int  WINAPI XRadio_GetGroupID(HELE hEle);  //获取组ID
XC_API void WINAPI XRadio_EnableButtonStyle(HELE hEle,BOOL bStyle); //启用按钮样式
XC_API void WINAPI XRadio_SetBindEle(HELE hEle,HELE bindEle);
XC_API HELE WINAPI XRichEdit_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API BOOL WINAPI XRichEdit_InsertText(HELE hEle,wchar_t *pText,int row,int column); //插入文本内容
XC_API BOOL WINAPI XRichEdit_InsertTextEx(HELE hEle,wchar_t *pText,int row,int column,LOGFONTW *pFont,BOOL bColor=FALSE,COLORREF color=0);
XC_API BOOL WINAPI XRichEdit_InsertData(HELE hEle,void *pData,int row,int column); 
XC_API BOOL WINAPI XRichEdit_InsertImage(HELE hEle,HIMAGE hImage,wchar_t *pImagePath,int row,int column); //插入图片,到当前位置
XC_API BOOL WINAPI XRichEdit_InsertImageGif(HELE hEle,wchar_t *pImageName,int row,int column);//插入GIF图片,到当前位置
XC_API void WINAPI XRichEdit_SetText(HELE hEle,wchar_t *pText);  //设置文本内容,会清空之前的内容
XC_API BOOL WINAPI XRichEdit_SetPos(HELE hEle,int row,int column); //设置插入符位置
XC_API BOOL WINAPI XRichEdit_SetItemFontEx(HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn,LOGFONTW *pFont);
XC_API BOOL WINAPI XRichEdit_SetItemColorEx(HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn,COLORREF color);
XC_API void WINAPI XRichEdit_SetRowHeight(HELE hEle,int height); //设置默认行高
XC_API void WINAPI XRichEdit_SetReadOnly(HELE hEle,BOOL bRead);  //设置只读内容
XC_API int WINAPI XRichEdit_GetItemCount(HELE hEle); //获取内容数量,包括图片
XC_API void WINAPI XRichEdit_GetText(HELE hEle,HSTRING hString); //获取文本内容
XC_API void WINAPI XRichEdit_GetHTMLFormat(HELE hEle,HSTRING hString);  //获取HTML格式内容
XC_API void* WINAPI XRichEdit_GetData(HELE hEle);
XC_API void WINAPI XRichEdit_GetCurrentPos(HELE hEle,out_ int *pRow,out_ int *pColumn);//获取插入符位置,当前行和列
XC_API BOOL WINAPI XRichEdit_GetSelectPos(HELE hEle,out_ int *pBeginRow,out_ int *pBeginColumn,out_ int *pEndRow,out_ int *pEndColumn);//获取选择内容位置
XC_API int  WINAPI XRichEdit_GetSelectText(HELE hEle,wchar_t *pOut,int len);//获取选择内容
XC_API int  WINAPI XRichEdit_GetRowCount(HELE hEle);   //获取总行数
XC_API int  WINAPI XRichEdit_GetRowItemCount(HELE hEle,int row);   //获取指定行内容数量
XC_API void WINAPI XRichEdit_GetVisibleRow(HELE hEle,out_ int *pBeginRow,out_ int *pEndRow); //获取可视行范围
XC_API int  WINAPI XRichEdit_GetRowHeight(HELE hEle); //获取默认行高
XC_API int  WINAPI XRichEdit_GetFontCount(HELE hEle);  //获取字体数量
XC_API BOOL WINAPI XRichEdit_IsEmpty(HELE hEle);  //判断内容是否为空
XC_API BOOL WINAPI XRichEdit_CancelSelect(HELE hEle); //取消选择
XC_API void WINAPI XRichEdit_SelectAll(HELE hEle);  //全选  选择所有文本
XC_API void WINAPI XRichEdit_ClearFontTable(HELE hEle); //清理字体表,清理未使用的字体
XC_API BOOL WINAPI XRichEdit_DeleteEx(HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn); //删除指定内容
XC_API BOOL WINAPI XRichEdit_DeleteSelect(HELE hEle); //删除选择内容
XC_API void WINAPI XRichEdit_DeleteAll(HELE hEle); //清空内容
XC_API BOOL WINAPI XRichEdit_Menu_Cut(HELE hEle);        //剪切  删除选择的文本,并将文本拷贝到剪切板中
XC_API BOOL WINAPI XRichEdit_Menu_Copy(HELE hEle);       //复制  复制选择的文本到剪切板中
XC_API BOOL WINAPI XRichEdit_Menu_Paste(HELE hEle);      //粘贴  将剪切板中的文本插入当前光标位置
XC_API void WINAPI XRichEdit_Adjust(HELE hEle,int startIndex=0); //调整
XC_API HELE WINAPI XSBar_Create(int x, int y, int cx, int cy,BOOL bHorizon,HXCGUI hParent=NULL);
XC_API BOOL WINAPI XSBar_ScrollUp(HELE hEle);       //向左滚动
XC_API BOOL WINAPI XSBar_ScrollDown(HELE hEle);     //向右滚动
XC_API BOOL WINAPI XSBar_ScrollTop(HELE hEle);      //滚动到顶部
XC_API BOOL WINAPI XSBar_ScrollBottom(HELE hEle);   //滚动到底部
XC_API BOOL WINAPI XSBar_ScrollPos(HELE hEle,int pos); //滚动到指定点
XC_API void WINAPI XSBar_SetScrollRange(HELE hEle,int range);
XC_API void WINAPI XSBar_SetSliderLength(HELE hEle,int length); //设置滑块长度
XC_API void WINAPI XSBar_SetHorizon(HELE hEle,BOOL bHorizon);  //水平显示或垂直
XC_API int WINAPI XSBar_GetScrollPos(HELE hEle); //获取当前滚动点
XC_API int WINAPI XSBar_GetButtonLength(HELE hEle); //按钮长度
XC_API int WINAPI XSBar_GetSliderLength(HELE hEle); //滑块长度
XC_API int WINAPI XSBar_GetScrollRange(HELE hEle);  //获取滚动范围
XC_API void WINAPI XSBar_EnableScrollButton2(HELE hEle,BOOL bEnable); //是否显示上下滚动按钮
XC_API void WINAPI XSBar_Adjust(HELE hEle);            //调整滚动条
XC_API void WINAPI XSBar_SetImage(HELE hEle,HIMAGE hImage);     //设置背景图片
XC_API void WINAPI XSBar_SetImageLeaveUp(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageStayUp(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageDownUp(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageLeaveDown(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageStayDown(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageDownDown(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageLeaveSlider(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageStaySlider(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSBar_SetImageDownSlider(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XSView_SetDrawScrollViewEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);
XC_API HELE WINAPI XSView_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API void WINAPI XSView_SetDrawScrollView(HELE hEle,pFunDrawScrollView pFun);
XC_API HELE WINAPI XSView_GetView(HELE hEle); //获取视元素
XC_API BOOL WINAPI XSView_AddEle(HELE hEle,HELE hNewEle); //添加元素到滚动视图
XC_API int WINAPI XSView_GetHViewPos(HELE hEle);   //获取视口原点X坐标
XC_API int WINAPI XSView_GetVViewPos(HELE hEle);   //获取视口原点Y坐标
XC_API int WINAPI XSView_GetSpacingLeft(HELE hEle);
XC_API int WINAPI XSView_GetSpacingTop(HELE hEle);
XC_API int WINAPI XSView_GetSpacingRight(HELE hEle);
XC_API int WINAPI XSView_GetSpacingBottom(HELE hEle);
XC_API int WINAPI XSView_GetScrollBarWidth(HELE hEle);  //获取滚动条宽度
XC_API int WINAPI XSView_GetViewWidth(HELE hEle);  //获取视口宽度(不含边框间隔及滚动条)
XC_API int WINAPI XSView_GetViewHeight(HELE hEle); //获取视口高度(不含边框间隔及滚动条)
XC_API int WINAPI XSView_GetHSizeTotalAccurate(HELE hEle); //获取内容总宽度,精确的(不含边框间隔及滚动条),当内容大小小于视口大小时,返回的是视口大小
XC_API int WINAPI XSView_GetVSizeTotalAccurate(HELE hEle); //获取内容总高度,精确的(不含边框间隔及滚动条),当内容大小小于视口大小时,返回的是视口大小
XC_API void WINAPI XSView_GetViewRect(HELE hEle,out_ RECT *pRect); //获取视口坐标(不含边框间隔),left为视口左间隔大小,top为视口上间隔大小,非(0,0).
XC_API void WINAPI XSView_GetSize(HELE hEle,SIZE *pSize);  //获取设置的内容大小
XC_API HELE WINAPI XSView_GetHScrollBar(HELE hEle); //获取水平滚动条
XC_API HELE WINAPI XSView_GetVScrollBar(HELE hEle); //获取垂直滚动条
XC_API void WINAPI XSView_SetSize(HELE hEle,int cx, int cy); //设置视图内容总大小(不包含边框间隔)
XC_API void WINAPI XSView_SetSpacing(HELE hEle,int left, int top, int right, int bottom);  
XC_API void WINAPI XSView_SetScrollSize(HELE hEle,int line,int column);  //设置滚动行和列大小
XC_API void WINAPI XSView_SetImage(HELE hEle,HIMAGE hImage);//设置贴图
XC_API void WINAPI XSView_EnableHScroll(HELE hEle,BOOL bEnable); //启用水平滚动条
XC_API void WINAPI XSView_EnableVScroll(HELE hEle,BOOL bEnable); //启用垂直滚动条
XC_API BOOL WINAPI XSView_IsHScrollBarVisible(HELE hEle); //水平滚动条当前是否可见
XC_API BOOL WINAPI XSView_IsVScrollBarVisible(HELE hEle); //垂直滚动条当前是否可见
XC_API void WINAPI XSView_Adjust(HELE hEle);
XC_API BOOL WINAPI XSView_ScrollHPos(HELE hEle,int pos); //滚动到指定点
XC_API BOOL WINAPI XSView_ScrollVPos(HELE hEle,int pos); //滚动到指定点
XC_API BOOL WINAPI XSView_ScrollHPosX(HELE hEle,int posX); //滚动到指定坐标
XC_API BOOL WINAPI XSView_ScrollVPosY(HELE hEle,int posY); //滚动到指定坐标
XC_API BOOL WINAPI XSView_ScrollLeftLine(HELE hEle);    //向左滚动
XC_API BOOL WINAPI XSView_ScrollRightLine(HELE hEle);   //向右滚动
XC_API BOOL WINAPI XSView_ScrollTopLine(HELE hEle);     //向上滚动
XC_API BOOL WINAPI XSView_ScrollDownLine(HELE hEle);    //向下滚动
XC_API BOOL WINAPI XSView_ScrollLeft(HELE hEle);    //水平滚动到左侧
XC_API BOOL WINAPI XSView_ScrollRight(HELE hEle);   //水平滚动到右侧
XC_API BOOL WINAPI XSView_ScrollTop(HELE hEle);     //滚动到顶部
XC_API BOOL WINAPI XSView_ScrollBottom(HELE hEle);  //滚动到底部
XC_API HELE WINAPI XSliderBar_Create(int x, int y, int cx, int cy,BOOL bHorizon,HXCGUI hParent=NULL);
XC_API void WINAPI XSliderBar_SetRange(HELE hEle,int range);  //设置滑动范围
XC_API void WINAPI XSliderBar_SetPos(HELE hEle,int pos);     //设置滑块位置
XC_API int  WINAPI XSliderBar_GetPos(HELE hEle);            //获取滑块位置
XC_API HELE WINAPI XSliderBar_GetButton(HELE hEle);        //获取滑块指针
XC_API int  WINAPI XSliderBar_GetButtonWidth(HELE hEle); //获取滑块宽度
XC_API void WINAPI XSliderBar_SetHorizon(HELE hEle,BOOL bHorizon);  //水平显示或垂直
XC_API void WINAPI XSliderBar_SetButtonWidth(HELE hEle,int width); //设置滑块宽度
XC_API void WINAPI XSliderBar_SetImage(HELE hEle,HIMAGE hImage); //背景
XC_API void WINAPI XSliderBar_SetImage2(HELE hEle,HIMAGE hImage); //显示当前进度图片
XC_API HELE WINAPI XStatic_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);
XC_API void WINAPI XStatic_SetText(HELE hEle,wchar_t *pText);
XC_API wchar_t* WINAPI XStatic_GetText(HELE hEle);
XC_API void WINAPI XStatic_AdjustSize(HELE hEle);  //根据文本内容,调整元素大小
XC_API void WINAPI XStatic_SetTextAlign(HELE hEle,int flag); //设置文本对齐
XC_API HSTRING WINAPI XStr_Create(wchar_t *pString=NULL);
XC_API void WINAPI XStr_Destroy(HSTRING hStr);
XC_API void WINAPI XStr_InsertChar(HSTRING hStr,int index,wchar_t ch);  //插入
XC_API void WINAPI XStr_InsertString(HSTRING hStr,int index,wchar_t *pStr);
XC_API void WINAPI XStr_SetString(HSTRING hStr, wchar_t *pStr); //设置文本
XC_API void WINAPI XStr_AddString(HSTRING hStr, wchar_t *pStr); //添加文本到末尾
XC_API void WINAPI XStr_AddStringLength(HSTRING hStr, wchar_t *pStr, int strLen); //添加文本到末尾
XC_API void WINAPI XStr_SetLength(HSTRING hStr,int length); //设置字符串长度,多余的字符去掉
XC_API void WINAPI XStr_Replace(HSTRING hStr,wchar_t *pStrOld,wchar_t *pStrNew); //字符串替换 Replace
XC_API wchar_t* WINAPI XStr_GetBuffer(HSTRING hStr);
XC_API int WINAPI XStr_GetLength(HSTRING hStr);
XC_API wchar_t*  WINAPI XStr_Find(HSTRING hStr,wchar_t ch, int strart=0); //查找字符
XC_API void WINAPI XStr_SetAt(HSTRING hStr,int index, wchar_t ch);//设置指定位置的一个字符
XC_API wchar_t WINAPI XStr_GetAt(HSTRING hStr,int index); //获取指定位置的一个字符
XC_API void WINAPI XStr_Empty(HSTRING hStr);    //清空
XC_API BOOL WINAPI XStr_IsEmpty(HSTRING hStr);  //判断是否为空
XC_API void WINAPI XStr_Delete(HSTRING hStr,wchar_t ch); //删除ch,全部ch删除
XC_API void WINAPI XStr_DeleteLength(HSTRING hStr,int index, int count=1); //从index位置删除count个字符
XC_API void WINAPI XStr_DeleteFront(HSTRING hStr, int index); //删除指定位置之后的字符串
XC_API void WINAPI XStr_DeleteBack(HSTRING hStr, int index);  //删除指定位置之前的字符串
XC_API HELE WINAPI XTabBar_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XTabBar_AddLabel(HELE hEle,wchar_t *pName,HELE hPage=NULL); //添加一个标签
XC_API int WINAPI XTabBar_InsertLabel(HELE hEle,int index,wchar_t *pName,HELE hPage=NULL);
XC_API void WINAPI XTabBar_DeleteLabel(HELE hEle,int index,BOOL deletePage=FALSE);  //删除
XC_API void WINAPI XTabBar_DeleteLabelAll(HELE hEle,BOOL deletePage=FALSE);  //删除所有TAB
XC_API HELE WINAPI XTabBar_GetLabel(HELE hEle,int index);//获取标签按钮Button
XC_API HELE WINAPI XTabBar_GetLabelPage(HELE hEle,int index); //获取标签对应的页
XC_API int  WINAPI XTabBar_GetPageIndex(HELE hEle,HELE hPage); //检索绑定页对应标签索引
XC_API int  WINAPI XTabBar_GetSelect(HELE hEle);  //获取选择的标签
XC_API int  WINAPI XTabBar_GetLabelSpacing(HELE hEle); //获取标签间距, 0没有间距
XC_API int  WINAPI XTabBar_GetLabelCount(HELE hEle); //获取标签项数量
XC_API void WINAPI XTabBar_SetLabelSpacing(HELE hEle,int spacing);//设置标签间距, 0没有间距
XC_API BOOL WINAPI XTabBar_SetBindEle(HELE hEle,int index,HELE hPage); //绑定视图元素到标签
XC_API void WINAPI XTabBar_SetSelect(HELE hEle,int index,BOOL reDraw=TRUE);   //设置选择标签
XC_API void WINAPI XTabBar_SetAlign(HELE hEle,align_type_ align);
XC_API void WINAPI XTabBar_SetUp(HELE hEle);    //左滚动
XC_API void WINAPI XTabBar_SetDown(HELE hEle);  //右滚动
XC_API void WINAPI XTabBar_EnableTile(HELE hEle,BOOL bTile);  //平铺标签,每个标签显示相同大小
XC_API HELE WINAPI XTextLink_Create(int x, int y, int cx, int cy,wchar_t *pTitle=NULL,HXCGUI hParent=NULL);
XC_API void WINAPI XTextLink_SetStayColor(HELE hEle,COLORREF color); //设置鼠标停留时文本颜色
XC_API COLORREF WINAPI XTextLink_GetStayColor(HELE hEle);  //获取鼠标停留时文本颜色
XC_API void WINAPI XTextLink_AdjustSize(HELE hEle);  //根据文本内容,调整元素大小
XC_API void WINAPI XTextLink_ShowUnderline(HELE hEle,BOOL bLeave,BOOL bStay);  //显示下划线
XC_API HELE WINAPI XToolBarBtn_Create(int cx,int cy,wchar_t *pTitle);
XC_API void WINAPI XToolBarBtn_Adjust(HELE hEle);  //调整到合适大小, 在添加到工具条上之后才可调用,因为需要知道工具条大小后才能做调整
XC_API HELE WINAPI XToolBar_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XToolBar_InsertEle(HELE hEle,HELE hNewEle,int index=-1); //添加元素到工具条, -1插入到末尾
XC_API int WINAPI XToolBar_InsertSeparator(HELE hEle,int index=-1); //添加分隔符, -1插入到末尾
XC_API HELE WINAPI XToolBar_GetHEle(HELE hEle,int index);  //获取工具条上元素句柄
XC_API HELE WINAPI XToolBar_GetButtonLeft(HELE hEle);   //获取工具条左滚动按钮Button
XC_API HELE WINAPI XToolBar_GetButtonRight(HELE hEle);  //获取工具条右滚动按钮Button
XC_API void WINAPI XToolBar_DeleteEle(HELE hEle,int index); //移除工具条上元素并销毁
XC_API void WINAPI XToolBar_Adjust(HELE hEle);          //调整布局
XC_API void WINAPI XToolBar_SetImage(HELE hEle,HIMAGE hImage);
XC_API void WINAPI XTree_SetUserDrawItemEx(HELE hEle,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //设置用户自绘项
XC_API HELE WINAPI XTree_Create(int x, int y, int cx, int cy,HXCGUI hParent=NULL);
XC_API int WINAPI XTree_InsertItem(HELE hEle,wchar_t *pText, int parentId=XTREE_ROOT,int imageId=-1, int selectImageId=-1,int insertAfter=XTREE_INSERT_LAST,BOOL bExpand=TRUE); //插入项
XC_API void WINAPI XTree_EnableButton(HELE hEle,BOOL bEnable);    //显示按钮
XC_API void WINAPI XTree_EnableLine(HELE hEle,BOOL bEnable);      //显示连接虚线
XC_API void WINAPI XTree_EnableRootLine(HELE hEle,BOOL bEnable);  //启用连接根部的线
XC_API BOOL WINAPI XTree_IsButton(HELE hEle);
XC_API BOOL WINAPI XTree_IsLine(HELE hEle);
XC_API BOOL WINAPI XTree_IsRootLine(HELE hEle);
XC_API BOOL WINAPI XTree_IsExpand(HELE hEle,int id); //判断指定项是否展开
XC_API void WINAPI XTree_SetSpacingLeft(HELE hEle,int left);   //设置左间隔
XC_API void WINAPI XTree_SetSpacingTop(HELE hEle,int top);     //设置上间隔
XC_API void WINAPI XTree_SetImageList(HELE hEle,HXCGUI hImageList); //设置图片列表
XC_API void WINAPI XTree_SetItemData(HELE hEle,int id, int data);   //设置用户数据
XC_API void WINAPI XTree_SetExpandButtonSize(HELE hEle,int size);   //设置展开按钮大小
XC_API void WINAPI XTree_SetIndentation(HELE hEle,int width);  //设置子项缩进宽度
XC_API void WINAPI XTree_SetSelectItem(HELE hEle,int id);     //设置选择项
XC_API void WINAPI XTree_SetItemText(HELE hEle,int id, wchar_t *pText);//设置项文本
XC_API void WINAPI XTree_SetItemImage(HELE hEle,int id, int imageId);  //设置项图片
XC_API void WINAPI XTree_SetItemHeight(HELE hEle,int height); //设置项高度
XC_API BOOL WINAPI XTree_SetItemBindEle(HELE hEle,int id,itemBindEle_ *pInfo); //绑定元素
XC_API int WINAPI XTree_GetItemData(HELE hEle,int id); //获取用户数据
XC_API int WINAPI XTree_GetItemHeight(HELE hEle);      //获取项高度
XC_API int WINAPI XTree_GetSelectItem(HELE hEle);   //获取当前选择的项
XC_API int WINAPI XTree_GetParentItem(HELE hEle,int id); //获取指定项的父项
XC_API int WINAPI XTree_GetChildItem(HELE hEle,int id);  //获取指定项的子项
XC_API int WINAPI XTree_GetNextSiblingItem(HELE hEle,int id); //获取指定项的下一个兄弟项
XC_API int WINAPI XTree_GetPrevSiblingItem(HELE hEle,int id); //获取指定项的上一个兄弟项
XC_API int WINAPI XTree_GetFirstItem(HELE hEle); //获取第一个节点
XC_API int WINAPI XTree_GetItemDepth(HELE hEle,int id);//获取节点深度
XC_API int WINAPI XTree_GetItemImage(HELE hEle,int id);  //获取项图片
XC_API wchar_t* WINAPI XTree_GetItemText(HELE hEle,int id); //获取项文本
XC_API HXCGUI WINAPI XTree_GetImageList(HELE hEle); //获取图片列表
XC_API void WINAPI XTree_Expand(HELE hEle,int id, BOOL bExpand); //展开收缩指定项
XC_API void WINAPI XTree_DeleteItem(HELE hEle,int id); //删除一个项
XC_API void WINAPI XTree_DeleteAllItems(HELE hEle); //清空树
XC_API int WINAPI XTree_HitTest(HELE hEle,POINT *pPt);  //测试点击位置,返回项ID
XC_API void WINAPI XTree_SetUserDrawItem(HELE hEle,pFunTree_DrawItem pFunDrawItem); //设置用户自绘项
XC_API void WINAPI XTree_EnableCheckBox(HELE hEle, BOOL bEnable);//启用复选框
XC_API BOOL WINAPI XTree_IsItemCheck(HELE hEle,int id); //判断项的复选框是否勾选
XC_API void WINAPI XTree_SetItemCheck(HELE hEle,int id, BOOL bCheck); //设置项的复选框
XC_API HXCGUI WINAPI XWeb_Create(HWINDOW hWindow,int x,int y,int cx,int cy);
XC_API BOOL WINAPI XWeb_OpenURL(HXCGUI hWebBrowser,wchar_t *pUrl);
XC_API void WINAPI XWeb_Show(HXCGUI hWebBrowser,BOOL bShow); //显示隐藏
XC_API HWND WINAPI XWeb_GetHWnd(HXCGUI hWebBrowser);       //获取浏览器控件容器(CAxWindow)HWND句柄
XC_API void* WINAPI XWeb_GetControl(HXCGUI hWebBrowser);   //获取控件接口IWebBrowser2*
XC_API void* WINAPI XWeb_GetCAxWindow(HXCGUI hWebBrowser); //获取容器对象指针CAxWindow*
XC_API void WINAPI XWeb_Destroy(HXCGUI hWebBrowser);
XC_API BOOL WINAPI XWeb_GetClientRect(HXCGUI hWebBrowser,out_ RECT *pRect); //获取坐标
XC_API BOOL WINAPI XWeb_SetRect(HXCGUI hWebBrowser,in_ RECT *pRect); //设置坐标
XC_API BOOL WINAPI XWeb_ExeJavascript(HXCGUI hWebBrowser,wchar_t *pFun,wchar_t* pParam[],int paramCount);
XC_API void WINAPI XWeb_RegEvent(HXCGUI hWebBrowser,int type,void *pFun);
XC_API void WINAPI XWeb_RegExternalFunction0(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External0 pFun);  //注册Js外部函数
XC_API void WINAPI XWeb_RegExternalFunction1(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External1 pFun);  //注册Js外部函数
XC_API void WINAPI XWeb_RegExternalFunction2(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External2 pFun);  //注册Js外部函数
XC_API void WINAPI XWeb_RegExternalFunction3(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External3 pFun);  //注册Js外部函数
XC_API void WINAPI XWeb_RegExternalFunction4(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External4 pFun);  //注册Js外部函数
XC_API void WINAPI XWeb_RegExternalFunction5(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External5 pFun);  //注册Js外部函数
XC_API void WINAPI XWeb_RegExternalFunction6(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External6 pFun);  //注册Js外部函数
XC_API void WINAPI XWeb_RegExternalFunction7(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External7 pFun);  //注册Js外部函数
XC_API void WINAPI XWeb_RegExternalFunction8(HXCGUI hWebBrowser,wchar_t *pFunName,pFunIE_External8 pFun);  //注册Js外部函数
XC_API HRESULT WINAPI XWeb_get_AddressBar(HXCGUI hWebBrowser,out_ BOOL *pbValue);
XC_API HRESULT WINAPI XWeb_put_AddressBar(HXCGUI hWebBrowser,BOOL bValue);
XC_API HRESULT WINAPI XWeb_get_Application(HXCGUI hWebBrowser,IDispatch **ppDisp);
XC_API HRESULT WINAPI XWeb_get_Busy(HXCGUI hWebBrowser,out_ BOOL *pbBool);
XC_API HRESULT WINAPI XWeb_ClientToWindow(HXCGUI hWebBrowser,in_out_ int *pcx,in_out_ int *pcy);
XC_API HRESULT WINAPI XWeb_get_Container(HXCGUI hWebBrowser,IDispatch **ppDisp);
XC_API HRESULT WINAPI XWeb_get_Document(HXCGUI hWebBrowser,IDispatch **ppDisp);
XC_API HRESULT WINAPI XWeb_ExecWB(HXCGUI hWebBrowser,in_ OLECMDID cmdID,in_ OLECMDEXECOPT cmdexecopt,in_ VARIANT *pvaIn,in_out_ VARIANT *pvaOut);
XC_API HRESULT WINAPI XWeb_get_FullName(HXCGUI hWebBrowser,out_ wchar_t *pOut,in_ int outLen);
XC_API HRESULT WINAPI XWeb_get_FullScreen(HXCGUI hWebBrowser,BOOL *pbFullScreen);
XC_API HRESULT WINAPI XWeb_put_FullScreen(HXCGUI hWebBrowser,BOOL bFullScreen);
XC_API HRESULT WINAPI XWeb_GetProperty(HXCGUI hWebBrowser,in_ wchar_t *pProperty,out_ VARIANT *pvtValue);
XC_API HRESULT WINAPI XWeb_GoBack(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_GoForward(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_GoHome(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_GoSearch(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_get_Height(HXCGUI hWebBrowser,out_ long *pl);
XC_API HRESULT WINAPI XWeb_put_Height(HXCGUI hWebBrowser,in_ long height);
XC_API HRESULT WINAPI XWeb_get_HWND(HXCGUI hWebBrowser,out_ long *pHWND);
XC_API HRESULT WINAPI XWeb_get_Left(HXCGUI hWebBrowser,out_ long *pl);
XC_API HRESULT WINAPI XWeb_put_Left(HXCGUI hWebBrowser,in_ long left);
XC_API HRESULT WINAPI XWeb_get_LocationName(HXCGUI hWebBrowser,out_ wchar_t *pLocationName,in_ int outLen);
XC_API HRESULT WINAPI XWeb_get_LocationURL(HXCGUI hWebBrowser,out_ wchar_t *pLocationURL,in_ int outLen);
XC_API HRESULT WINAPI XWeb_get_MenuBar(HXCGUI hWebBrowser,out_ BOOL *pbValue);
XC_API HRESULT WINAPI XWeb_put_MenuBar(HXCGUI hWebBrowser,in_ BOOL bValue);
XC_API HRESULT WINAPI XWeb_get_Name(HXCGUI hWebBrowser,out_ wchar_t *pName,in_ int outLen);
XC_API HRESULT WINAPI XWeb_Navigate(HXCGUI hWebBrowser,in_ wchar_t *pUrl,in_ VARIANT *Flags,in_ VARIANT *TargetFrameName,in_ VARIANT *PostData,in_ VARIANT *Headers);
XC_API HRESULT WINAPI XWeb_Navigate2(HXCGUI hWebBrowser,in_ VARIANT *URL,in_ VARIANT *Flags,in_ VARIANT *TargetFrameName,in_ VARIANT *PostData,in_ VARIANT *Headers);
XC_API HRESULT WINAPI XWeb_get_Offline(HXCGUI hWebBrowser,out_ BOOL *pbOffline);
XC_API HRESULT WINAPI XWeb_put_Offline(HXCGUI hWebBrowser,in_ BOOL bOffline);
XC_API HRESULT WINAPI XWeb_get_Parent(HXCGUI hWebBrowser,IDispatch **ppDisp);
XC_API HRESULT WINAPI XWeb_get_Path(HXCGUI hWebBrowser,out_ wchar_t *pPath,in_ int outLen);
XC_API HRESULT WINAPI XWeb_PutProperty(HXCGUI hWebBrowser,in_ wchar_t *pProperty,in_ VARIANT vtValue);
XC_API HRESULT WINAPI XWeb_QueryStatusWB(HXCGUI hWebBrowser,in_ OLECMDID cmdID,out_ OLECMDF *pcmdf);
XC_API HRESULT WINAPI XWeb_Quit(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_get_ReadyState(HXCGUI hWebBrowser,out_ READYSTATE *plReadyState);
XC_API HRESULT WINAPI XWeb_Refresh(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_Refresh2(HXCGUI hWebBrowser,in_ int level);
XC_API HRESULT WINAPI XWeb_get_RegisterAsBrowser(HXCGUI hWebBrowser,out_ BOOL *pbRegister);
XC_API HRESULT WINAPI XWeb_put_RegisterAsBrowser(HXCGUI hWebBrowser,in_ BOOL bRegister);
XC_API HRESULT WINAPI XWeb_get_RegisterAsDropTarget(HXCGUI hWebBrowser,out_ BOOL *pbRegister);
XC_API HRESULT WINAPI XWeb_put_RegisterAsDropTarget(HXCGUI hWebBrowser,in_ BOOL bRegister);
XC_API HRESULT WINAPI XWeb_get_Resizable(HXCGUI hWebBrowser,out_ BOOL *pbValue);
XC_API HRESULT WINAPI XWeb_put_Resizable(HXCGUI hWebBrowser,in_ BOOL bValue);
XC_API HRESULT WINAPI XWeb_ShowBrowserBar(HXCGUI hWebBrowser,in_ VARIANT *pvaClsid,in_ BOOL bShow);
XC_API HRESULT WINAPI XWeb_get_Silent(HXCGUI hWebBrowser,out_ BOOL *pbSilent);
XC_API HRESULT WINAPI XWeb_put_Silent(HXCGUI hWebBrowser,in_ BOOL bSilent);
XC_API HRESULT WINAPI XWeb_get_StatusBar(HXCGUI hWebBrowser,out_ BOOL *pbBool);
XC_API HRESULT WINAPI XWeb_put_StatusBar(HXCGUI hWebBrowser,in_ BOOL bValue);
XC_API HRESULT WINAPI XWeb_get_StatusText(HXCGUI hWebBrowser,out_ wchar_t *pOut,in_ int outLen);
XC_API HRESULT WINAPI XWeb_put_StatusText(HXCGUI hWebBrowser,in_ wchar_t *pStatusText);
XC_API HRESULT WINAPI XWeb_Stop(HXCGUI hWebBrowser);
XC_API HRESULT WINAPI XWeb_get_TheaterMode(HXCGUI hWebBrowser,out_ BOOL *pbRegister);
XC_API HRESULT WINAPI XWeb_put_TheaterMode(HXCGUI hWebBrowser,in_ BOOL bRegister);
XC_API HRESULT WINAPI XWeb_get_ToolBar(HXCGUI hWebBrowser,out_ int *pValue);
XC_API HRESULT WINAPI XWeb_put_ToolBar(HXCGUI hWebBrowser,in_ int value);
XC_API HRESULT WINAPI XWeb_get_Top(HXCGUI hWebBrowser,out_ long *pl);
XC_API HRESULT WINAPI XWeb_put_Top(HXCGUI hWebBrowser,in_ long top);
XC_API HRESULT WINAPI XWeb_get_TopLevelContainer(HXCGUI hWebBrowser,out_ BOOL *pbBool);
XC_API HRESULT WINAPI XWeb_get_Type(HXCGUI hWebBrowser,out_ wchar_t *pOut,in_ int outLen);
XC_API HRESULT WINAPI XWeb_get_Visible(HXCGUI hWebBrowser,out_ BOOL *pBool);
XC_API HRESULT WINAPI XWeb_put_Visible(HXCGUI hWebBrowser,in_ BOOL bValue);
XC_API HRESULT WINAPI XWeb_get_Width(HXCGUI hWebBrowser,out_ long *pl);
XC_API HRESULT WINAPI XWeb_put_Width(HXCGUI hWebBrowser,in_ long width);
XC_API void WINAPI XWnd_RegisterMessageEx(HWINDOW hWindow,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);  //注册消息回调函数
XC_API void WINAPI XWnd_RegisterNCMessageEx(HWINDOW hWindow,int message,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info); //注册非客户区消息
XC_API void WINAPI XWnd_RegisterMsgProcEx(HWINDOW hWindow,pFunClassEventMsg pCallBackFun,void *pClass_Fun_Info);	//注册窗口消息处理过程
XC_API HWINDOW WINAPI XWnd_CreateWindow(int x,int y,int cx,int cy,wchar_t *pTitle,HWND hWndParent=NULL,int XCStyle=XC_SY_DEFAULT);
XC_API HWINDOW WINAPI XWnd_CreateWindowEx(DWORD dwExStyle, wchar_t* lpClassName,wchar_t* lpWindowName,DWORD dwStyle, int x,int y,int cx,int cy,HWND hWndParent,int XCStyle=XC_SY_DEFAULT);
XC_API void WINAPI XWnd_RegisterMessage(HWINDOW hWindow,int message,void *pFun);  //注册消息回调函数
XC_API void WINAPI XWnd_RegisterNCMessage(HWINDOW hWindow,int message,void *pFun); //注册非客户区消息
XC_API void WINAPI XWnd_RegisterMsgProc(HWINDOW hWindow,pFunWndMsgProc pFun);	//注册窗口消息处理过程
XC_API void WINAPI XWnd_GetDrawRect(HWINDOW hWindow,out_ RECT *pRect);//获取当前绘制区域(包含非客户区)
XC_API HELE WINAPI XWnd_GetFocusEle(HWINDOW hWindow); //获取拥有焦点的元素
XC_API HWND WINAPI XWnd_GetHWnd(HWINDOW hWindow); //获取窗口句柄
XC_API HELE WINAPI XWnd_GetEle(HWINDOW hWindow,int eleID); //通过ID获取元素句柄
XC_API HICON WINAPI XWnd_GetIcon(HWINDOW hWindow,BOOL bBigIcon);//获取窗口图标
XC_API int WINAPI XWnd_GetWindowText(HWINDOW hWindow,wchar_t *pOut,int len);
XC_API BOOL WINAPI XWnd_SetWindowText(HWINDOW hWindow,wchar_t *pText);
XC_API void WINAPI XWnd_SetFont(HWINDOW hWindow,HFONTX hFontX);
XC_API DWORD WINAPI XWnd_SetIcon(HWINDOW hWindow,HICON hIcon,BOOL bBigIcon);
XC_API DWORD WINAPI XWnd_SetIcon2(HWINDOW hWindow,wchar_t *pFileName,BOOL bBigIcon);
XC_API void WINAPI XWnd_SetIconSize(HWINDOW hWindow,int width,int height);  //设置标题栏图标显示大小
XC_API void WINAPI XWnd_SetFontCaptionText(HWINDOW hWindow,HFONTX hFontX);//设置标题栏字体
XC_API void WINAPI XWnd_SetColorCaptionText(HWINDOW hWindow,COLORREF color);//设置标题栏文字颜色
XC_API UINT WINAPI XWnd_SetTimer(HWINDOW hWindow,UINT nIDEvent,UINT uElapse); //设置定时器
XC_API BOOL WINAPI XWnd_KillTimer(HWINDOW hWindow,UINT nIDEvent);
XC_API UINT WINAPI XWnd_SetTimerEx(HWINDOW hWindow,UINT nIDEvent,UINT uElapse,int userData=0);
XC_API BOOL WINAPI XWnd_KillTimerEx(HWINDOW hWindow,UINT nIDEvent);
XC_API void WINAPI XWnd_SetMinWidth(HWINDOW hWindow,int width);  //设置窗口最小宽度
XC_API void WINAPI XWnd_SetMinHeight(HWINDOW hWindow,int height); //设置窗口最小高度
XC_API void WINAPI XWnd_SetRoundSize(HWINDOW hWindow,int size);    //设置窗口圆角大小,对圆角窗口有效
XC_API void WINAPI XWnd_AddEle(HWINDOW hWindow,HELE hEle);
XC_API void WINAPI XWnd_AddEleNC(HWINDOW hWindow,HELE hEle); //添加到非客户区
XC_API void WINAPI XWnd_AddMenuBar(HWINDOW hWindow,HELE hEle); //添加工具条
XC_API void WINAPI XWnd_AddToolBar(HWINDOW hWindow,HELE hEle); //添加工具条
XC_API void WINAPI XWnd_Adjust(HWINDOW hWindow);  //调整窗口布局
XC_API void WINAPI XWnd_MaximizeWnd(HWINDOW hWindow,BOOL bMax); //最大化 还原窗口
XC_API BOOL WINAPI XWnd_IsMaximizeWnd(HWINDOW hWindow);  //窗口是否最大化
XC_API void WINAPI XWnd_RedrawWndRect(HWINDOW hWindow,RECT *pRect,BOOL bImmediately=FALSE); //重绘窗口指定区域
XC_API void WINAPI XWnd_RedrawWnd(HWINDOW hWindow,BOOL bImmediately=FALSE); //重绘窗口
XC_API void WINAPI XWnd_RedrawEleRectNC(HWINDOW hWindow,HELE hEle,RECT *pRect);
XC_API void WINAPI XWnd_EnableDragBorder(HWINDOW hWindow,BOOL bDrag);  //使用拖动边框
XC_API void WINAPI XWnd_EnableDragWindow(HWINDOW hWindow,BOOL bDrag);  //拖动窗口
XC_API HELE WINAPI XWnd_GetButtonMin(HWINDOW hWindow);   //最小化按钮
XC_API HELE WINAPI XWnd_GetButtonMax(HWINDOW hWindow);   //最大化按钮
XC_API HELE WINAPI XWnd_GetButtonClose(HWINDOW hWindow); //关闭按钮
XC_API void WINAPI XWnd_EnableMinButton(HWINDOW hWindow,BOOL bEnable,BOOL bRedraw=FALSE); //启用最小化按钮
XC_API void WINAPI XWnd_EnableMaxButton(HWINDOW hWindow,BOOL bEnable,BOOL bRedraw=FALSE); //启用最大化按钮
XC_API void WINAPI XWnd_EnableCloseButton(HWINDOW hWindow,BOOL bEnable,BOOL bRedraw=FALSE);  //启用关闭按钮
XC_API void WINAPI XWnd_EnableRound(HWINDOW hWindow,BOOL bEnable,BOOL bRedraw=FALSE); //圆角功能的启用与关闭
XC_API int  WINAPI XWnd_GetChildEleCount(HWINDOW hWindow);
XC_API int  WINAPI XWnd_GetChildEleCountNC(HWINDOW hWindow);
XC_API HELE WINAPI XWnd_GetChildEleByIndex(HWINDOW hWindow,int index);
XC_API HELE WINAPI XWnd_GetChildEleByIndexNC(HWINDOW hWindow,int index);
XC_API void WINAPI XWnd_SetTransparentFlag(HWINDOW hWindow,int flag);  //设置透明窗口
XC_API void WINAPI XWnd_SetTransparentAlpha(HWINDOW hWindow,BYTE alpha); //设置窗口透明度
XC_API void WINAPI XWnd_SetTransparentColor(HWINDOW hWindow,COLORREF color); //设置窗口透明色
XC_API void WINAPI XWnd_SetImage(HWINDOW hWindow,HIMAGE hImage=NULL);    //客户区图片
XC_API void WINAPI XWnd_SetImageNC(HWINDOW hWindow,HIMAGE hImage=NULL);  //非客户区窗口图片
XC_API void WINAPI XWnd_SetImageCaption(HWINDOW hWindow,HIMAGE hImage=NULL);   //标题栏图片
XC_API void WINAPI XWnd_SetImageBorderLeft(HWINDOW hWindow,HIMAGE hImage=NULL);    //边框图片
XC_API void WINAPI XWnd_SetImageBorderRight(HWINDOW hWindow,HIMAGE hImage=NULL);    //边框图片
XC_API void WINAPI XWnd_SetImageBorderBottom(HWINDOW hWindow,HIMAGE hImage=NULL);    //边框图片
XC_API void WINAPI XWnd_SetBkColor(HWINDOW hWindow,COLORREF color); //设置背景颜色
XC_API void WINAPI XWnd_EnableBorderStrokeInner(HWINDOW hWindow,BOOL bStroke); //启用绘制描边 内
XC_API void WINAPI XWnd_EnableBorderStrokeOuter(HWINDOW hWindow,BOOL bStroke); //启用绘制描边 外
XC_API void WINAPI XWnd_SetBorderStrokeInnerColor(HWINDOW hWindow,COLORREF color1,COLORREF color2); //设置描边颜色 内
XC_API void WINAPI XWnd_SetBorderStrokeOuterColor(HWINDOW hWindow,COLORREF color1,COLORREF color2); //设置描边颜色 外
XC_API void WINAPI XWnd_CloseWindow(HWINDOW hWindow);  //关闭窗口
XC_API void WINAPI XWnd_CreateCaret(HWINDOW hWindow,HELE hEle, int width, int height);//创建插入符
XC_API void WINAPI XWnd_SetCaretSize(HWINDOW hWindow,int width, int height); //设置插入符大小
XC_API void WINAPI XWnd_SetCaretPos(HWINDOW hWindow,int x,int y); //设置插入符位置
XC_API void WINAPI XWnd_SetCaretPosEx(HWINDOW hWindow,int x,int y,int width,int height); //设置插入符位置
XC_API void WINAPI XWnd_SetCaretColor(HWINDOW hWindow,COLORREF color); //设置插入符颜色
XC_API void WINAPI XWnd_ShowCaret(HWINDOW hWindow,BOOL bShow);  //显示插入符
XC_API void WINAPI XWnd_DestroyCaret(HWINDOW hWindow);    //销毁插入符
XC_API BOOL WINAPI XWnd_GetClientRect(HWINDOW hWindow,out_ RECT *pRect); //获取客户区坐标(左上角0,0)
XC_API void WINAPI XWnd_GetNCClientRect(HWINDOW hWindow,out_ RECT *pRect); //非客户区坐标,整个窗口坐标(左上角0,0)
XC_API int WINAPI XWnd_GetClientLeft(HWINDOW hWindow); //客户区左间距
XC_API int WINAPI XWnd_GetClientTop(HWINDOW hWindow);  //客户区上间距
XC_API int WINAPI XWnd_GetClientRight(HWINDOW hWindow); //客户区右间距
XC_API int WINAPI XWnd_GetClientBottom(HWINDOW hWindow); //客户区下间距
XC_API int WINAPI XWnd_GetCaptionHeight(HWINDOW hWindow); //获取标题栏高度
XC_API void WINAPI XWnd_SetBorderSize(HWINDOW hWindow,int left,int top,int right,int bottom); //设置窗口边框大小
XC_API void WINAPI XWnd_SetCaptionHeight(HWINDOW hWindow,int captionHeight); //设置标题栏高度
XC_API void WINAPI XWnd_WindowToClientRect(HWINDOW hWindow,in_out_ RECT *pRect); //窗口非客户区坐标转换到客户区坐标
XC_API void WINAPI XWnd_WindowToClientPt(HWINDOW hWindow,in_out_ POINT *pPt); //窗口非客户区点转换到客户区坐标点
XC_API void WINAPI XWnd_SetUserData(HWINDOW hWindow,int data);
XC_API int  WINAPI XWnd_GetUserData(HWINDOW hWindow);
XC_API BOOL WINAPI XWnd_ShowWindow(HWINDOW hWindow,int nCmdShow);
XC_API BOOL WINAPI XWnd_SetWindowPos(HWINDOW hWindow,HWND hWndInsertAfter,int x,int y,int cx,int cy,UINT uFlags);
XC_API BOOL WINAPI XWnd_SetWindowRect(HWINDOW hWindow,in_ RECT *pRect);
XC_API BOOL WINAPI XWnd_SetWindowSize(HWINDOW hWindow,int width,int height);
XC_API BOOL WINAPI XWnd_GetWindowRect(HWINDOW hWindow,out_ RECT *pRect);
XC_API BOOL WINAPI XWnd_IsWindowVisible(HWINDOW hWindow);
XC_API int WINAPI XC_GetObjectType(HXCGUI hXCGUI); //获取资源类型
XC_API BOOL WINAPI XC_IsHELE(HELE hEle); //检查句柄
XC_API BOOL WINAPI XC_IsHWINDOW(HWINDOW hWindow); //检查句柄
XC_API BOOL WINAPI XC_IsSViewExtend(HELE hEle);  //判断元素是否从滚动视图元素扩展的新元素,包含滚动视图元素
XC_API BOOL WINAPI XC_IsEditExtend(HELE hEle); //判断该元素是否从指定元素扩展而来
XC_API int WINAPI XC_UnicodeToAnsi(wchar_t *pIn,int inLen,char *pOut,int outLen);
XC_API int WINAPI XC_AnsiToUnicode(char *pIn,int inLen,wchar_t *pOut,int outLen);
XC_API int WINAPI XC_HexToDec(wchar_t *pHex);
XC_API void WINAPI XC_SetResourcesModule(HMODULE hModule);  //设置资源模块句柄
XC_API BOOL WINAPI XC_RectInRect(RECT *pRect1,RECT *pRect2);
XC_API void WINAPI XC_CombineRect(RECT *pDest,RECT *pSrc1,RECT *pSrc2);
XC_API HMODULE WINAPI XC_GetModuleHandle(wchar_t *pModuleName);
XC_API HMODULE WINAPI XC_GetModuleHandle2();
XC_API HANDLE WINAPI XC_LoadImage(HINSTANCE hinst,wchar_t * lpszName,UINT uType,int cxDesired,int cyDesired,UINT fuLoad);
XC_API HFONT WINAPI XC_CreateFont(wchar_t *pName=L"宋体",int size=12,BOOL bBold=FALSE,BOOL bItalic=FALSE,BOOL bUnderline=FALSE,BOOL bStrikeOut=FALSE);
XC_API void  WINAPI XC_InitFont(LOGFONTW *pFont,wchar_t *pName,int size,BOOL bBold=FALSE,BOOL bItalic=FALSE,BOOL bUnderline=FALSE,BOOL bStrikeOut=FALSE);
XC_API  void* WINAPI XC_Malloc(int size);
XC_API  void  WINAPI XC_Free(void *p);
XC_API BOOL WINAPI XML_Register(int type,void *pFun); //注册回调函数
XC_API BOOL WINAPI XC_RegisterWndClass(wchar_t *pClassName,HICON hIcon=NULL); //注册窗口类
XC_API BOOL WINAPI XInitXCGUI(wchar_t *pText=NULL);
XC_API void WINAPI XRunXCGUI();
XC_API void WINAPI XExitProcess(); //退出进程(相当析构函数)
XC_API void WINAPI xtrace(char *pszFormat, ...);
XC_API void WINAPI xtracew(wchar_t *pszFormat, ...);


#endif //XCGUI_HEADER_FILE_