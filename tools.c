#include "tools.h"
#include <GL/gl.h>

/****************************************************
 * 计算水波值
 ***************************************************/
void calculate(GLfloat in[ORDER * 2][ORDER * 2][3],
	       GLfloat out[ORDER * 2][ORDER * 2][3])
{
  int i, j;
  for (i = 1; i < ORDER * 2 - 1; i++) {
    for (j = 1; j < ORDER * 2 - 1; j++) {
      out[i][j][2] = 
	((in[i - 1][j][2] + in[i][j - 1][2] + 
	  in[i + 1][j][2] + in[i][j + 1][2])
	/ 2) - out[i][j][2];
      out[i][j][2] -= out[i][j][2] / 64.0;
    }
  }
}

