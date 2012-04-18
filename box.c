#include "box.h"
#include "global.h"
#include <GL/glut.h>

/*************************************************
 * 盒子的材质
 ************************************************/
GLfloat box_ambient_and_diffuse[] = {
  0.7, 0.2, 0.7, 0.4
};

/*************************************************
 * 盒子有5个面，每个面4个点
 ************************************************/
int faces[5][4] = {
  {4, 5, 6, 7},
  {0, 1, 5, 4},
  {3, 2, 6, 7},
  {1, 5, 6, 2},
  {0, 3, 7, 4}
};

/*************************************************
 * 里层每个点的坐标
 ************************************************/
GLfloat points[] = {
  -ORDER, ORDER -1.0, 2.0,
  -ORDER, -ORDER, 2.0,
  ORDER - 1.0, -ORDER, 2.0,
  ORDER - 1.0, ORDER - 1.0, 2.0,
  -ORDER, ORDER - 1.0, -ORDER,
  -ORDER, -ORDER, -ORDER,
  ORDER - 1.0, -ORDER, -ORDER,
  ORDER - 1.0, ORDER - 1.0, -ORDER
};

/*************************************************
 * 外层每个点的坐标
 ************************************************/
#define WIDTH 0.3
GLfloat points1[] = {
  -ORDER - WIDTH, ORDER -1.0 + WIDTH, 2.0,
  -ORDER - WIDTH, -ORDER - WIDTH, 2.0,
  ORDER - 1.0 + WIDTH, -ORDER - WIDTH, 2.0,
  ORDER - 1.0 + WIDTH, ORDER - 1.0 + WIDTH, 2.0,
  -ORDER - WIDTH, ORDER - 1.0 + WIDTH, -ORDER - WIDTH,
  -ORDER - WIDTH, -ORDER - WIDTH, -ORDER - WIDTH,
  ORDER - 1.0 + WIDTH, -ORDER - WIDTH, -ORDER -WIDTH,
  ORDER - 1.0 + WIDTH, ORDER - 1.0 + WIDTH, -ORDER - WIDTH
};
#undef WIDTH

/*************************************************
 * 渲染盒子
 ************************************************/
void drawBox(void)
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glMaterialfv(GL_FRONT_AND_BACK, 
	       GL_AMBIENT_AND_DIFFUSE, 
	       box_ambient_and_diffuse);
  int i;
  glPushAttrib(GL_COLOR_BUFFER_BIT);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDepthMask(GL_FALSE);
  glBegin(GL_QUADS);
  for (i = 0; i < 5; i++) {
    glVertex3fv(&points[faces[i][0] * 3]);
    glVertex3fv(&points[faces[i][1] * 3]);
    glVertex3fv(&points[faces[i][2] * 3]);
    glVertex3fv(&points[faces[i][3] * 3]);
    glVertex3fv(&points1[faces[i][0] * 3]);
    glVertex3fv(&points1[faces[i][1] * 3]);
    glVertex3fv(&points1[faces[i][2] * 3]);
    glVertex3fv(&points1[faces[i][3] * 3]);
  }
  glEnd();
  glDepthMask(GL_TRUE);
  glPopAttrib();
  glPopMatrix();
}
