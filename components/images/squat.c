#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_SQUAT
#define LV_ATTRIBUTE_IMG_SQUAT
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SQUAT uint8_t squat_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x49, 0x25, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0xff, 0xff, 0x49, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x92, 0xff, 0xff, 0xb6, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0xff, 0xdb, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0x49, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x6d, 0x6d, 0x6e, 0x6e, 0x6d, 0x92, 0x6d, 0x6e, 0x6d, 0x6e, 0xdb, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x6d, 0xff, 0xff, 0xdb, 0xb7, 0xb6, 0xb6, 0xb6, 0xb6, 0xb7, 0x49, 0xb6, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0xff, 0xff, 0xff, 0x6e, 0x49, 0x6e, 0x6d, 0x92, 0x6d, 0x6d, 0x92, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x6e, 0xff, 0xff, 0xff, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0xff, 0xff, 0xff, 0x92, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xb7, 0x6e, 0xff, 0xff, 0xff, 0x25, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x6d, 0xb7, 0xff, 0xff, 0xb7, 0x24, 0x49, 0x49, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x92, 0x6d, 0x92, 0x92, 0xb6, 0xb7, 0xff, 0xff, 0x6d, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x92, 0x92, 0x92, 0x24, 0xff, 0xdb, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x6d, 0xff, 0x6d, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0xdb, 0xff, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0xff, 0x49, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x92, 0xff, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0x24, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit*/
  0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0x84, 0xc7, 0x39, 0x24, 0x21, 0x31, 0x8c, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xf8, 0xc5, 0x08, 0x42, 0xbf, 0xff, 0x9e, 0xf7, 0xc7, 0x39, 0xd7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x72, 0x94, 0xf0, 0x83, 0xff, 0xff, 0xff, 0xff, 0x14, 0xa5, 0xef, 0x7b, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 
  0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0xc7, 0x39, 0xba, 0xd6, 0x39, 0xce, 0xc7, 0x39, 0xdb, 0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xb6, 0xb5, 0x29, 0x4a, 0xe8, 0x41, 0x55, 0xad, 0xbf, 0xff, 0x9e, 0xf7, 0xbe, 0xf7, 0x7e, 0xf7, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 
  0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x3c, 0xe7, 0xef, 0x7b, 0xaa, 0x52, 0xaa, 0x52, 0x2c, 0x63, 0x4d, 0x6b, 0x0c, 0x63, 0x8e, 0x73, 0xec, 0x62, 0x4d, 0x6b, 0xeb, 0x5a, 0x4d, 0x6b, 0x9a, 0xd6, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x30, 0x84, 0x0c, 0x63, 0xfb, 0xde, 0x3d, 0xef, 0x59, 0xce, 0x55, 0xad, 0xb3, 0x9c, 0xd3, 0x9c, 0xb3, 0x9c, 0xb3, 0x9c, 0x35, 0xad, 0xe7, 0x39, 0xb3, 0x9c, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0x3c, 0xe7, 0xa7, 0x39, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0x6e, 0x73, 0x08, 0x42, 0x6e, 0x73, 0x0c, 0x63, 0x8e, 0x73, 0x0c, 0x63, 0x0c, 0x63, 0x10, 0x84, 0x3d, 0xef, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0xff, 0x51, 0x8c, 0x8e, 0x73, 0xff, 0xff, 0xdf, 0xff, 0xbb, 0xde, 0x49, 0x4a, 0x7d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7d, 0xef, 0x6a, 0x52, 0xfb, 0xde, 0x9e, 0xf7, 0xff, 0xff, 0xcf, 0x7b, 0x72, 0x94, 0xff, 0xff, 0x3d, 0xef, 0xbe, 0xf7, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0x35, 0xad, 0x2c, 0x63, 0xff, 0xff, 0xff, 0xff, 0x5d, 0xef, 0x66, 0x31, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xcb, 0x5a, 0x75, 0xad, 0xdf, 0xff, 0xff, 0xff, 0x55, 0xad, 0xe4, 0x20, 0x8a, 0x52, 0x28, 0x42, 0x10, 0x84, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xbf, 0xff, 0x28, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xfc, 0xe6, 0xbe, 0xf7, 0x49, 0x4a, 0x96, 0xb5, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xbe, 0xf7, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xaf, 0x7b, 0xab, 0x5a, 0x92, 0x94, 0x72, 0x94, 0x92, 0x94, 0x55, 0xad, 0x3d, 0xef, 0xbe, 0xf7, 0xab, 0x5a, 0xf8, 0xc5, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xf4, 0xa4, 0x10, 0x84, 0xf0, 0x83, 0x10, 0x84, 0x82, 0x10, 0xbb, 0xde, 0x9a, 0xd6, 0x6a, 0x52, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0xc6, 0x0c, 0x63, 0xff, 0xff, 0xcb, 0x5a, 0x55, 0xad, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0x6a, 0x52, 0x38, 0xc6, 0x1c, 0xe7, 0x08, 0x42, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xf7, 0xbd, 0x08, 0x42, 0xff, 0xff, 0x8a, 0x52, 0xd3, 0x9c, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0x14, 0xa5, 0x92, 0x94, 0x7d, 0xef, 0x49, 0x4a, 0x9e, 0xf7, 0xff, 0xff, 0x7e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0xe8, 0x41, 0xa3, 0x18, 0x34, 0xa5, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit BUT the 2 bytes are swapped*/
  0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x84, 0x30, 0x39, 0xc7, 0x21, 0x24, 0x8c, 0x31, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xc5, 0xf8, 0x42, 0x08, 0xff, 0xbf, 0xf7, 0x9e, 0x39, 0xc7, 0xbd, 0xd7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x94, 0x72, 0x83, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xa5, 0x14, 0x7b, 0xef, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
  0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0x39, 0xc7, 0xd6, 0xba, 0xce, 0x39, 0x39, 0xc7, 0xde, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xf7, 0x9e, 0xb5, 0xb6, 0x4a, 0x29, 0x41, 0xe8, 0xad, 0x55, 0xff, 0xbf, 0xf7, 0x9e, 0xf7, 0xbe, 0xf7, 0x7e, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 
  0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xe7, 0x3c, 0x7b, 0xef, 0x52, 0xaa, 0x52, 0xaa, 0x63, 0x2c, 0x6b, 0x4d, 0x63, 0x0c, 0x73, 0x8e, 0x62, 0xec, 0x6b, 0x4d, 0x5a, 0xeb, 0x6b, 0x4d, 0xd6, 0x9a, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xff, 0x84, 0x30, 0x63, 0x0c, 0xde, 0xfb, 0xef, 0x3d, 0xce, 0x59, 0xad, 0x55, 0x9c, 0xb3, 0x9c, 0xd3, 0x9c, 0xb3, 0x9c, 0xb3, 0xad, 0x35, 0x39, 0xe7, 0x9c, 0xb3, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xe7, 0x3c, 0x39, 0xa7, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0x73, 0x6e, 0x42, 0x08, 0x73, 0x6e, 0x63, 0x0c, 0x73, 0x8e, 0x63, 0x0c, 0x63, 0x0c, 0x84, 0x10, 0xef, 0x3d, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0xff, 0x8c, 0x51, 0x73, 0x8e, 0xff, 0xff, 0xff, 0xdf, 0xde, 0xbb, 0x4a, 0x49, 0xef, 0x7d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x7d, 0x52, 0x6a, 0xde, 0xfb, 0xf7, 0x9e, 0xff, 0xff, 0x7b, 0xcf, 0x94, 0x72, 0xff, 0xff, 0xef, 0x3d, 0xf7, 0xbe, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xad, 0x35, 0x63, 0x2c, 0xff, 0xff, 0xff, 0xff, 0xef, 0x5d, 0x31, 0x66, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0x5a, 0xcb, 0xad, 0x75, 0xff, 0xdf, 0xff, 0xff, 0xad, 0x55, 0x20, 0xe4, 0x52, 0x8a, 0x42, 0x28, 0x84, 0x10, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xbf, 0x42, 0x28, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xe6, 0xfc, 0xf7, 0xbe, 0x4a, 0x49, 0xb5, 0x96, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf7, 0xbe, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0x7b, 0xaf, 0x5a, 0xab, 0x94, 0x92, 0x94, 0x72, 0x94, 0x92, 0xad, 0x55, 0xef, 0x3d, 0xf7, 0xbe, 0x5a, 0xab, 0xc5, 0xf8, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xa4, 0xf4, 0x84, 0x10, 0x83, 0xf0, 0x84, 0x10, 0x10, 0x82, 0xde, 0xbb, 0xd6, 0x9a, 0x52, 0x6a, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc6, 0x18, 0x63, 0x0c, 0xff, 0xff, 0x5a, 0xcb, 0xad, 0x55, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0x52, 0x6a, 0xc6, 0x38, 0xe7, 0x1c, 0x42, 0x08, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xbd, 0xf7, 0x42, 0x08, 0xff, 0xff, 0x52, 0x8a, 0x9c, 0xd3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xa5, 0x14, 0x94, 0x92, 0xef, 0x7d, 0x4a, 0x49, 0xf7, 0x9e, 0xff, 0xff, 0xf7, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0x41, 0xe8, 0x18, 0xa3, 0xa5, 0x34, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Blue: 8 bit, Green: 8 bit, Red: 8 bit, Fix 0xFF: 8 bit, */
  0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 0x83, 0x83, 0xff, 0x38, 0x38, 0x38, 0xff, 0x24, 0x24, 0x24, 0xff, 0x86, 0x86, 0x86, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0x42, 0x42, 0x42, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0x39, 0x39, 0x39, 0xff, 0xb7, 0xb7, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0x8e, 0x8e, 0x8e, 0xff, 0x7e, 0x7e, 0x7e, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa0, 0xa0, 0xa0, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd0, 0xd0, 0xd0, 0xff, 0x3a, 0x3a, 0x3a, 0xff, 0xd3, 0xd3, 0xd3, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0x39, 0x39, 0x39, 0xff, 0xda, 0xda, 0xda, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xf1, 0xf1, 0xff, 0xb3, 0xb3, 0xb3, 0xff, 0x46, 0x46, 0x46, 0xff, 0x3e, 0x3e, 0x3e, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0xf4, 0xf4, 0xf4, 0xff, 0xee, 0xee, 0xee, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xef, 0xef, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xe3, 0xe3, 0xe3, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x54, 0x54, 0x54, 0xff, 0x54, 0x54, 0x54, 0xff, 0x63, 0x63, 0x63, 0xff, 0x6a, 0x6a, 0x6a, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0x71, 0x71, 0x71, 0xff, 0x5e, 0x5e, 0x5e, 0xff, 0x68, 0x68, 0x68, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0x68, 0x68, 0x68, 0xff, 0xcf, 0xcf, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0x83, 0x83, 0x83, 0xff, 0x60, 0x60, 0x60, 0xff, 0xdc, 0xdc, 0xdc, 0xff, 0xe6, 0xe6, 0xe6, 0xff, 0xc9, 0xc9, 0xc9, 0xff, 0xa7, 0xa7, 0xa7, 0xff, 0x95, 0x95, 0x95, 0xff, 0x99, 0x99, 0x99, 0xff, 0x95, 0x95, 0x95, 0xff, 0x96, 0x96, 0x96, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0x3c, 0x3c, 0x3c, 0xff, 0x95, 0x95, 0x95, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xe3, 0xe3, 0xff, 0x35, 0x35, 0x35, 0xff, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0x6e, 0x6e, 0x6e, 0xff, 0x41, 0x41, 0x41, 0xff, 0x6d, 0x6d, 0x6d, 0xff, 0x60, 0x60, 0x60, 0xff, 0x72, 0x72, 0x72, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0x60, 0x60, 0x60, 0xff, 0x82, 0x82, 0x82, 0xff, 0xe5, 0xe5, 0xe5, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0x87, 0x87, 0xff, 0x6f, 0x6f, 0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xd6, 0xd6, 0xd6, 0xff, 0x48, 0x48, 0x48, 0xff, 0xec, 0xec, 0xec, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xeb, 0xeb, 0xeb, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0xdb, 0xdb, 0xdb, 0xff, 0xef, 0xef, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0x77, 0x77, 0xff, 0x8d, 0x8d, 0x8d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe6, 0xe6, 0xe6, 0xff, 0xf4, 0xf4, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xa5, 0xa5, 0xa5, 0xff, 0x64, 0x64, 0x64, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xe7, 0xe7, 0xff, 0x2e, 0x2e, 0x2e, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xf1, 0xf1, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5a, 0x5a, 0x5a, 0xff, 0xac, 0xac, 0xac, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0x1e, 0x1e, 0x1e, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x44, 0x44, 0x44, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xef, 0xef, 0xef, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0x44, 0x44, 0x44, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xdd, 0xdd, 0xdd, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0x49, 0x49, 0x49, 0xff, 0xaf, 0xaf, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf4, 0xf4, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0x76, 0x76, 0x76, 0xff, 0x55, 0x55, 0x55, 0xff, 0x8f, 0x8f, 0x8f, 0xff, 0x8e, 0x8e, 0x8e, 0xff, 0x91, 0x91, 0x91, 0xff, 0xa7, 0xa7, 0xa7, 0xff, 0xe5, 0xe5, 0xe5, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0x56, 0x56, 0x56, 0xff, 0xbd, 0xbd, 0xbd, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0x9e, 0x9e, 0xff, 0x81, 0x81, 0x81, 0xff, 0x7e, 0x7e, 0x7e, 0xff, 0x81, 0x81, 0x81, 0xff, 0x12, 0x12, 0x12, 0xff, 0xd6, 0xd6, 0xd6, 0xff, 0xcf, 0xcf, 0xcf, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xf1, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfd, 0xfd, 0xfd, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0x59, 0x59, 0x59, 0xff, 0xa7, 0xa7, 0xa7, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xf4, 0xf4, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xe2, 0xe2, 0xe2, 0xff, 0x42, 0x42, 0x42, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xbb, 0xbb, 0xbb, 0xff, 0x42, 0x42, 0x42, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0x50, 0x50, 0x50, 0xff, 0x9a, 0x9a, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0xa2, 0xa2, 0xa2, 0xff, 0x8f, 0x8f, 0x8f, 0xff, 0xec, 0xec, 0xec, 0xff, 0x49, 0x49, 0x49, 0xff, 0xef, 0xef, 0xef, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xee, 0xee, 0xee, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xcf, 0xcf, 0xff, 0x3e, 0x3e, 0x3e, 0xff, 0x15, 0x15, 0x15, 0xff, 0xa4, 0xa4, 0xa4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
};

const lv_img_dsc_t squat = {
  .header.always_zero = 0,
  .header.w = 20,
  .header.h = 20,
  .data_size = 400 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = squat_map,
};
