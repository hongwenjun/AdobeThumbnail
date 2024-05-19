#ifndef DWG_THUMBNAIL_H_INCLUDED
#define DWG_THUMBNAIL_H_INCLUDED

#include "otherapi.h"


bool DWGThumbnail(const char* dwg_filename, const char* png_filename);
bool DWGThumbnail_W(const wchar_t* dwg_filename, const wchar_t* png_filename);

#endif // DWG_THUMBNAIL_H_INCLUDED
