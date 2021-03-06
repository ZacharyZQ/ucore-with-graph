
/* 图形容器绘图 */
#ifndef _KGC_CONTAINER_DRAW_H
#define _KGC_CONTAINER_DRAW_H

#include <defs.h>

#include <font/font.h>
#include <container/container.h>

/* 读写需要提高效率，所以携程内联函数 */
static inline void KGC_ContainerReadPixel(KGC_Container_t *container, int x, int y, uint32_t *color)
{
	if (x < 0 || x < 0 || x >= container->width || \
		y >= container->height)
		return;
	
    /* 从缓冲区读取颜色 */
	*color = *(uint32_t *)(container->buffer + (y * container->width + x));
}

static inline void KGC_ContainerWritePixel(KGC_Container_t *container, int x, int y, uint32_t color)
{
	if (x < 0 || x < 0 || x >= container->width || \
		y >= container->height)
		return;
	
    /* 写入颜色到缓冲区 */
	*(uint32_t *)(container->buffer + (y * container->width + x)) = color;
}

void KGC_ContainerDrawRectangle(KGC_Container_t *container,
    int x, int y, int width, int height, uint32_t color);

void KGC_ContainerDrawBitmap(KGC_Container_t *container, 
    int x, int y, int width, int height, uint32_t *bitmap);

void KGC_ContainerDrawLine(KGC_Container_t *container,
    int x0, int y0, int x1, int y1, uint32_t color);

void KGC_ContainerDrawChar(KGC_Container_t *container,
    int x, int y, char ch, uint32_t color);

void KGC_ContainerDrawString(KGC_Container_t *container,
    int x, int y, char *str, uint32_t color);

void KGC_ContainerDrawCharWithFont(KGC_Container_t *container,
    int x, int y, char ch, uint32_t color, KGC_Font_t *font);

void KGC_ContainerDrawStringWithFont(KGC_Container_t *container,
    int x, int y, char *str, uint32_t color, KGC_Font_t *font);

void KGC_ContainerDrawRectanglePlus(KGC_Container_t *container,
    int x, int y, int width, int height, uint32_t color);
void KGC_ContainerDrawCharWithFontPlus(KGC_Container_t *container,
    int x, int y, char ch, uint32_t color, KGC_Font_t *font);
void KGC_ContainerDrawStringWithFontPlus(KGC_Container_t *container,
    int x, int y, char *str, uint32_t color, KGC_Font_t *font);
void KGC_ContainerDrawCharPlus(KGC_Container_t *container,
    int x, int y, char ch, uint32_t color);
void KGC_ContainerDrawStringPlus(KGC_Container_t *container,
    int x, int y, char *str, uint32_t color);
void KGC_ContainerDrawLinePlus(KGC_Container_t *container,
    int x0, int y0, int x1, int y1, uint32_t color);
void KGC_ContainerDrawBitmapPlus(KGC_Container_t *container, 
    int x, int y, int width, int height, uint32_t *bitmap);

#endif   /* _KGC_CONTAINER_DRAW_H */
