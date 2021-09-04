#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_UP
#define LV_ATTRIBUTE_IMG_UP
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_UP uint8_t up_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x6d, 0x24, 0x00, 0x24, 0x24, 0x6d, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xdb, 0x25, 0x49, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x6d, 0x25, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xdb, 0x24, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x24, 0xb7, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x25, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x24, 0xdb, 0xff, 0xff, 
  0xff, 0xff, 0x25, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0xff, 0xff, 
  0xff, 0xb7, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0xb7, 0xff, 
  0xff, 0x6d, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x00, 0x00, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x6d, 0xff, 
  0xff, 0x24, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x25, 0x6e, 0x6e, 0x25, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x24, 0xff, 
  0xff, 0x24, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0x92, 0x92, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0x24, 0xff, 
  0xff, 0x24, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 
  0xff, 0x24, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x24, 0xff, 
  0xff, 0x6d, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x6d, 0xff, 
  0xff, 0xb7, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0xb7, 0xff, 
  0xff, 0xff, 0x49, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x25, 0xff, 0xff, 
  0xff, 0xff, 0xdb, 0x25, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x24, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xdb, 0x24, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x24, 0xdb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xdb, 0x25, 0x6d, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x6d, 0x25, 0xdb, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x6d, 0x24, 0x24, 0x24, 0x24, 0x6d, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0x35, 0xad, 0xaa, 0x52, 0xa3, 0x18, 0x82, 0x10, 0xc3, 0x18, 0x82, 0x10, 0xcb, 0x5a, 0x34, 0xa5, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0x66, 0x31, 0x69, 0x4a, 0xb6, 0xb5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0x96, 0xb5, 0x8a, 0x52, 0x25, 0x29, 0x9a, 0xd6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xb6, 0xb5, 0xe4, 0x20, 0xd7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 0xe3, 0x18, 0x96, 0xb5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xdf, 0xff, 0x9a, 0xd6, 0x25, 0x29, 0xfb, 0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xde, 0xe4, 0x20, 0x7a, 0xd6, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x66, 0x31, 0xd7, 0xbd, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc5, 0xa7, 0x39, 0xff, 0xff, 0xdf, 0xff, 
  0xff, 0xff, 0x34, 0xa5, 0x6a, 0x52, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd7, 0xbd, 0xb7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x69, 0x4a, 0x75, 0xad, 0xff, 0xff, 
  0xff, 0xff, 0xcb, 0x5a, 0x96, 0xb5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd7, 0xbd, 0x41, 0x08, 0x21, 0x08, 0x96, 0xb5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x96, 0xb5, 0xcb, 0x5a, 0xff, 0xff, 
  0xff, 0xff, 0xa2, 0x10, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xbd, 0x04, 0x21, 0x0c, 0x63, 0x2d, 0x6b, 0x24, 0x21, 0x76, 0xb5, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xc3, 0x18, 0xff, 0xff, 
  0xdf, 0xff, 0xa2, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x31, 0x8c, 0xfb, 0xde, 0x51, 0x8c, 0x10, 0x84, 0xfc, 0xe6, 0x51, 0x8c, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x18, 0xff, 0xff, 
  0xdf, 0xff, 0xa2, 0x10, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x51, 0x8c, 0x71, 0x8c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x82, 0x10, 0xff, 0xff, 
  0xff, 0xff, 0xc3, 0x18, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x51, 0x8c, 0x10, 0x84, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7d, 0xef, 0xe4, 0x20, 0xff, 0xff, 
  0xff, 0xff, 0xab, 0x5a, 0x55, 0xad, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x51, 0x8c, 0x71, 0x8c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x96, 0xb5, 0xcb, 0x5a, 0xff, 0xff, 
  0xdf, 0xff, 0x75, 0xad, 0x6a, 0x52, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7d, 0xef, 0x9e, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6a, 0x52, 0x75, 0xad, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xa6, 0x31, 0xb6, 0xb5, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc5, 0x65, 0x29, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x59, 0xce, 0x24, 0x21, 0xdb, 0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xde, 0xe3, 0x18, 0xba, 0xd6, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb6, 0xb5, 0xc3, 0x18, 0x38, 0xc6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0xc6, 0xe4, 0x20, 0xb7, 0xbd, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x79, 0xce, 0x86, 0x31, 0x8a, 0x52, 0x76, 0xb5, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0x96, 0xb5, 0xaa, 0x52, 0x45, 0x29, 0x9a, 0xd6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x35, 0xad, 0xcb, 0x5a, 0xe3, 0x18, 0xa2, 0x10, 0xa2, 0x10, 0xa3, 0x18, 0xaa, 0x52, 0x14, 0xa5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit BUT the 2 bytes are swapped*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xad, 0x35, 0x52, 0xaa, 0x18, 0xa3, 0x10, 0x82, 0x18, 0xc3, 0x10, 0x82, 0x5a, 0xcb, 0xa5, 0x34, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0x31, 0x66, 0x4a, 0x69, 0xb5, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xb5, 0x96, 0x52, 0x8a, 0x29, 0x25, 0xd6, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xb5, 0xb6, 0x20, 0xe4, 0xbd, 0xd7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xf7, 0x18, 0xe3, 0xb5, 0x96, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xdf, 0xd6, 0x9a, 0x29, 0x25, 0xde, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xde, 0xfb, 0x20, 0xe4, 0xd6, 0x7a, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x31, 0x66, 0xbd, 0xd7, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc5, 0xf8, 0x39, 0xa7, 0xff, 0xff, 0xff, 0xdf, 
  0xff, 0xff, 0xa5, 0x34, 0x52, 0x6a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xd7, 0xbd, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4a, 0x69, 0xad, 0x75, 0xff, 0xff, 
  0xff, 0xff, 0x5a, 0xcb, 0xb5, 0x96, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xd7, 0x08, 0x41, 0x08, 0x21, 0xb5, 0x96, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb5, 0x96, 0x5a, 0xcb, 0xff, 0xff, 
  0xff, 0xff, 0x10, 0xa2, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xb7, 0x21, 0x04, 0x63, 0x0c, 0x6b, 0x2d, 0x21, 0x24, 0xb5, 0x76, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0x18, 0xc3, 0xff, 0xff, 
  0xff, 0xdf, 0x10, 0xa2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0x8c, 0x31, 0xde, 0xfb, 0x8c, 0x51, 0x84, 0x10, 0xe6, 0xfc, 0x8c, 0x51, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x18, 0xc3, 0xff, 0xff, 
  0xff, 0xdf, 0x10, 0xa2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x51, 0x8c, 0x71, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x10, 0x82, 0xff, 0xff, 
  0xff, 0xff, 0x18, 0xc3, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x51, 0x84, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x7d, 0x20, 0xe4, 0xff, 0xff, 
  0xff, 0xff, 0x5a, 0xab, 0xad, 0x55, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x51, 0x8c, 0x71, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb5, 0x96, 0x5a, 0xcb, 0xff, 0xff, 
  0xff, 0xdf, 0xad, 0x75, 0x52, 0x6a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x7d, 0xf7, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x52, 0x6a, 0xad, 0x75, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x31, 0xa6, 0xb5, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc5, 0xf8, 0x29, 0x65, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xce, 0x59, 0x21, 0x24, 0xde, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xde, 0xfb, 0x18, 0xe3, 0xd6, 0xba, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb5, 0xb6, 0x18, 0xc3, 0xc6, 0x38, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc6, 0x18, 0x20, 0xe4, 0xbd, 0xb7, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0x79, 0x31, 0x86, 0x52, 0x8a, 0xb5, 0x76, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xb5, 0x96, 0x52, 0xaa, 0x29, 0x45, 0xd6, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xad, 0x35, 0x5a, 0xcb, 0x18, 0xe3, 0x10, 0xa2, 0x10, 0xa2, 0x18, 0xa3, 0x52, 0xaa, 0xa5, 0x14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Blue: 8 bit, Green: 8 bit, Red: 8 bit, Fix 0xFF: 8 bit, */
  0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa5, 0xa5, 0xa5, 0xff, 0x53, 0x53, 0x53, 0xff, 0x15, 0x15, 0x15, 0xff, 0x0f, 0x0f, 0x0f, 0xff, 0x19, 0x19, 0x19, 0xff, 0x12, 0x12, 0x12, 0xff, 0x58, 0x58, 0x58, 0xff, 0xa3, 0xa3, 0xa3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xcf, 0xcf, 0xcf, 0xff, 0x2d, 0x2d, 0x2d, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0xb4, 0xb4, 0xb4, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xb0, 0xb0, 0xb0, 0xff, 0x51, 0x51, 0x51, 0xff, 0x26, 0x26, 0x26, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xb3, 0xb3, 0xb3, 0xff, 0x1d, 0x1d, 0x1d, 0xff, 0xb9, 0xb9, 0xb9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xbc, 0xbc, 0xbc, 0xff, 0x1c, 0x1c, 0x1c, 0xff, 0xaf, 0xaf, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfd, 0xfd, 0xfd, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0x25, 0x25, 0x25, 0xff, 0xdc, 0xdc, 0xdc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xdc, 0xdc, 0xdc, 0xff, 0x1d, 0x1d, 0x1d, 0xff, 0xcd, 0xcd, 0xcd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x2e, 0x2e, 0x2e, 0xff, 0xb8, 0xb8, 0xb8, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xbd, 0xbd, 0xff, 0x35, 0x35, 0x35, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xa3, 0xa3, 0xa3, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xb7, 0xb7, 0xff, 0xb6, 0xb6, 0xb6, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0xac, 0xac, 0xac, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 
  0xfc, 0xfc, 0xfc, 0xff, 0x58, 0x58, 0x58, 0xff, 0xb1, 0xb1, 0xb1, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xb7, 0xb7, 0xb7, 0xff, 0x09, 0x09, 0x09, 0xff, 0x05, 0x05, 0x05, 0xff, 0xaf, 0xaf, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xb0, 0xb0, 0xb0, 0xff, 0x57, 0x57, 0x57, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x14, 0x14, 0x14, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xb5, 0xb5, 0xb5, 0xff, 0x21, 0x21, 0x21, 0xff, 0x62, 0x62, 0x62, 0xff, 0x66, 0x66, 0x66, 0xff, 0x24, 0x24, 0x24, 0xff, 0xae, 0xae, 0xae, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xf2, 0xf2, 0xff, 0x1a, 0x1a, 0x1a, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf9, 0xf9, 0xf9, 0xff, 0x13, 0x13, 0x13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0x86, 0x86, 0x86, 0xff, 0xdc, 0xdc, 0xdc, 0xff, 0x88, 0x88, 0x88, 0xff, 0x82, 0x82, 0x82, 0xff, 0xde, 0xde, 0xde, 0xff, 0x89, 0x89, 0x89, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0x17, 0x17, 0x17, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 
  0xf9, 0xf9, 0xf9, 0xff, 0x14, 0x14, 0x14, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0x87, 0x87, 0x87, 0xff, 0x8b, 0x8b, 0x8b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x10, 0x10, 0x10, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 
  0xfb, 0xfb, 0xfb, 0xff, 0x1a, 0x1a, 0x1a, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x88, 0x88, 0x88, 0xff, 0x81, 0x81, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xec, 0xec, 0xec, 0xff, 0x1e, 0x1e, 0x1e, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x55, 0x55, 0x55, 0xff, 0xa8, 0xa8, 0xa8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0x8a, 0x8a, 0x8a, 0xff, 0x8b, 0x8b, 0x8b, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb0, 0xb0, 0xb0, 0xff, 0x5a, 0x5a, 0x5a, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 
  0xfa, 0xfa, 0xfa, 0xff, 0xac, 0xac, 0xac, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xec, 0xec, 0xec, 0xff, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0xab, 0xab, 0xab, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0x33, 0x33, 0x33, 0xff, 0xb3, 0xb3, 0xb3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xbd, 0xbd, 0xff, 0x2c, 0x2c, 0x2c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc9, 0xc9, 0xc9, 0xff, 0x23, 0x23, 0x23, 0xff, 0xd9, 0xd9, 0xd9, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xdc, 0xdc, 0xdc, 0xff, 0x1c, 0x1c, 0x1c, 0xff, 0xd3, 0xd3, 0xd3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb4, 0xb4, 0xb4, 0xff, 0x19, 0x19, 0x19, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0x1d, 0x1d, 0x1d, 0xff, 0xb5, 0xb5, 0xb5, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xcc, 0xcc, 0xcc, 0xff, 0x30, 0x30, 0x30, 0xff, 0x51, 0x51, 0x51, 0xff, 0xad, 0xad, 0xad, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xb1, 0xb1, 0xb1, 0xff, 0x53, 0x53, 0x53, 0xff, 0x27, 0x27, 0x27, 0xff, 0xcf, 0xcf, 0xcf, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfb, 0xfb, 0xfb, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xa5, 0xa5, 0xa5, 0xff, 0x57, 0x57, 0x57, 0xff, 0x1b, 0x1b, 0x1b, 0xff, 0x13, 0x13, 0x13, 0xff, 0x13, 0x13, 0x13, 0xff, 0x16, 0x16, 0x16, 0xff, 0x54, 0x54, 0x54, 0xff, 0xa2, 0xa2, 0xa2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
};

const lv_img_dsc_t up = {
  .header.always_zero = 0,
  .header.w = 20,
  .header.h = 20,
  .data_size = 400 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = up_map,
};
