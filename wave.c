#include "wave.h"
#include "tools.h"
#include "global.h"
#include <GL/glut.h>

/***************************************************
 * 水波的各种参数
 **************************************************/
GLfloat wave_diffuse[] = {
  0.6, 0.9, 1.0, 1.0
};
GLfloat wave_specular[] = {
  0.7, 0.7, 0.7, 1.0
};
GLfloat wave_shininess[] = {80.0};
GLfloat ctlPoints[ORDER * 2][ORDER * 2][3];
GLfloat ctlPoints1[ORDER * 2][ORDER * 2][3];
int du = 0;           //判断渲染ctlPoints还是ctlPoints1
GLUnurbs* waveSur = 0;
GLfloat knots[ORDER * 4];
int showPoint = -1;

/***************************************************
 * 设置控制点
 **************************************************/
void makeCtlPoints(void)
{
  int i, j;
  for (j = -ORDER; j < ORDER; j++) {
    for (i = -ORDER; i < ORDER; i++) {
      ctlPoints[j + ORDER][i + ORDER][0] = j;
      ctlPoints[j + ORDER][i + ORDER][1] = i;
      if ((i > -ORDER / 8 && i < ORDER / 8) 
	  && (j > -ORDER /8 && j < ORDER / 8)) {
	ctlPoints[j + ORDER][i + ORDER][2] = -32;
      } else {
	ctlPoints[j + ORDER][i + ORDER][2] = 0;
      }
      ctlPoints1[j + ORDER][i + ORDER][0] = j;
      ctlPoints1[j + ORDER][i + ORDER][1] = i;
      ctlPoints1[j + ORDER][i + ORDER][2] = 0;
    }
  }
}

/***************************************************
 * 设置关键点的uv值
 **************************************************/
void makeKnots(void)
{
  int i;
  for (i = 0; i < ORDER * 4; i++) {
    if (i < ORDER * 2) {
      knots[i] = 0;
    } else {
      knots[i] = 1;
    }
  }
}

/***************************************************
 * 水波纹初始化
 **************************************************/
void waveInit(void)
{
  makeCtlPoints();
  makeKnots();
  waveSur = gluNewNurbsRenderer();
}

/***************************************************
 * 渲染水波纹的控制点
 **************************************************/
void drawClr(void)
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  int i, j;
  glPointSize(5.0);
  glBegin(GL_POINTS);
  if (du % 2 == 0) {
    for (i = 0; i < ORDER * 2; i++) {
      for (j = 0; j < ORDER * 2; j++) {
	glVertex3fv(&ctlPoints[i][j][0]);
      }
    }
  } else {
    for (i = 0; i < ORDER * 2; i++) {
      for (j = 0; j < ORDER * 2; j++) {
	glVertex3fv(&ctlPoints1[i][j][0]);
      }
    }
  }
  glEnd();
  glPopMatrix();
}

/***************************************************
 * 用NURBS工具渲染水波纹
 **************************************************/
void drawWave(void)
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glMaterialfv(GL_FRONT, GL_DIFFUSE, wave_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, wave_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, wave_shininess);
  gluBeginSurface(waveSur);
  if (du % 2 == 0) {
    gluNurbsSurface(waveSur,
		    ORDER * 4,
		    knots,
		    ORDER * 4,
		    knots,
		    ORDER * 2 * 3,
		    3,
		    &ctlPoints[0][0][0],
		    ORDER * 2,
		    ORDER * 2,
		    GL_MAP2_VERTEX_3);
  } else {
    gluNurbsSurface(waveSur,
		    ORDER * 4,
		    knots,
		    ORDER * 4,
		    knots,
		    ORDER * 2 * 3,
		    3,
		    &ctlPoints1[0][0][0],
		    ORDER * 2,
		    ORDER * 2,
		    GL_MAP2_VERTEX_3);
  }
  gluEndSurface(waveSur);
  glPopMatrix();
}

/***************************************************
 * 用求值器的方式渲染水波纹
 **************************************************/
void drawWave1(void)
{
  int i, j, k;
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      for (k = 0; k < 90; k++) {
      }
    }
  }
   
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glMaterialfv(GL_FRONT, GL_DIFFUSE, wave_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, wave_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, wave_shininess);

  glEnable(GL_MAP2_VERTEX_3);
  if (du % 2 == 0) {
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3 * ORDER * 2, 2 * ORDER,
	    0, 1, 3, 2 * ORDER, &ctlPoints[0][0][0]);
  } else {
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3 * ORDER * 2, 2 * ORDER,
	    0, 1, 3, 2 * ORDER, &ctlPoints1[0][0][0]);
  }
  glMapGrid2f(20, 0, 1, 20, 0, 1);
  glEvalMesh2(GL_FILL, 0, 20, 0, 20);
  glPopMatrix();
}

/***************************************************
 * 水波纹抖动
 **************************************************/
void moveWave(void)
{
  if (du % 2 == 0) {
    calculate(ctlPoints, ctlPoints1);
  } else {
    calculate(ctlPoints1, ctlPoints);
  }
  du++;
}
