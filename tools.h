#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <GL/gl.h>
#include "global.h"

/****************************************************
 * 计算水波值
 ***************************************************/
void calculate(GLfloat in[ORDER * 2][ORDER * 2][3],
	       GLfloat out[ORDER * 2][ORDER * 2][3]);
#endif
