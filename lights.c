#include "lights.h"
#include "global.h"
#include <GL/glut.h>

/*************************************************
 * 光源的位置
 ************************************************/
GLfloat light0Pos[] = {2.0, 0.0, 15.0, 0.0};
GLfloat light1Pos[] = {4.0, 0.0, 15.0, 0.0};
GLfloat light2Pos[] = {6.0, 0.0, 15.0, 0.0};
GLfloat light3Pos[] = {8.0, 0.0, 15.0, 0.0};
GLfloat light4Pos[] = {10.0, 0.0, 15.0, 0.0};
GLfloat light5Pos[] = {12.0, 0.0, 15.0, 0.0};
GLfloat light6Pos[] = {14.0, 0.0, 15.0, 0.0};
GLfloat light7Pos[] = {16.0, 0.0, 15.0, 0.0};

/*************************************************
 * 光源的散射光
 ************************************************/
GLfloat light0Diff[] = {0.8, 0.8, 0.8, 1.0};
GLfloat light1Diff[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light2Diff[] = {0.0, 1.0, 0.0, 1.0};
GLfloat light3Diff[] = {0.0, 0.0, 1.0, 1.0};
GLfloat light4Diff[] = {0.5, 0.0, 0.0, 1.0};
GLfloat light5Diff[] = {0.0, 0.5, 1.0, 1.0};
GLfloat light6Diff[] = {0.0, 0.0, 0.5, 1.0};
GLfloat light7Diff[] = {0.3, 0.3, 0.3, 1.0};

/*************************************************
 * 光源的环境光
 ************************************************/
GLfloat light0Amb[] = {0.2, 0.2, 0.2, 1.0};
GLfloat light1Amb[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light2Amb[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light3Amb[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light4Amb[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light5Amb[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light6Amb[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light7Amb[] = {0.0, 0.0, 0.0, 1.0};

/*************************************************
 * 光源绕z轴旋转的角度
 ************************************************/
GLfloat light0Cir = 0;
GLfloat light1Cir = 35;
GLfloat light2Cir = 70;
GLfloat light3Cir = 105;
GLfloat light4Cir = 140;
GLfloat light5Cir = 175;
GLfloat light6Cir = 210;
GLfloat light7Cir = 245;

/*************************************************
 * 光源是否显示
 ************************************************/
int showLight0 = -1;
int showLight1 = -1;
int showLight2 = -1;
int showLight3 = -1;
int showLight4 = -1;
int showLight5 = -1;
int showLight6 = -1;
int showLight7 = -1;

/*************************************************
 * 光源初始化
 ************************************************/
void lightInit(void)
{
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diff);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diff);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, light2Diff);
  glLightfv(GL_LIGHT3, GL_DIFFUSE, light3Diff);
  glLightfv(GL_LIGHT4, GL_DIFFUSE, light4Diff);
  glLightfv(GL_LIGHT5, GL_DIFFUSE, light5Diff);
  glLightfv(GL_LIGHT6, GL_DIFFUSE, light6Diff);
  glLightfv(GL_LIGHT7, GL_DIFFUSE, light7Diff);

  glLightfv(GL_LIGHT0, GL_AMBIENT, light0Amb);
  glLightfv(GL_LIGHT1, GL_AMBIENT, light1Amb);
  glLightfv(GL_LIGHT2, GL_AMBIENT, light2Amb);
  glLightfv(GL_LIGHT3, GL_AMBIENT, light3Amb);
  glLightfv(GL_LIGHT4, GL_AMBIENT, light4Amb);
  glLightfv(GL_LIGHT5, GL_AMBIENT, light5Amb);
  glLightfv(GL_LIGHT6, GL_AMBIENT, light6Amb);
  glLightfv(GL_LIGHT7, GL_AMBIENT, light7Amb);

  glEnable(GL_LIGHTING);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
}

/*************************************************
 * 渲染光源
 ************************************************/
void drawLight(void)
{
  if (showLight0 > 0) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(light0Cir, 0.0, 0.0, 1.0);
    glTranslatef(light0Pos[0], light0Pos[1], light0Pos[2]);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
  }
  if (showLight1 > 0) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(light1Cir, 0.0, 0.0, 1.0);
    glTranslatef(light1Pos[0], light1Pos[1], light1Pos[2]);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
  }
  if (showLight2 > 0) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(light2Cir, 0.0, 0.0, 1.0);
    glTranslatef(light2Pos[0], light2Pos[1], light2Pos[2]);
    glLightfv(GL_LIGHT2, GL_POSITION, light2Pos);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
  }
  if (showLight3 > 0) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(light3Cir, 0.0, 0.0, 1.0);
    glTranslatef(light3Pos[0], light3Pos[1], light3Pos[2]);
    glLightfv(GL_LIGHT3, GL_POSITION, light3Pos);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
  }
  if (showLight4 > 0) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(light4Cir, 0.0, 0.0, 1.0);
    glTranslatef(light4Pos[0], light4Pos[1], light4Pos[2]);
    glLightfv(GL_LIGHT4, GL_POSITION, light4Pos);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
  }
  if (showLight5 > 0) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(light5Cir, 0.0, 0.0, 1.0);
    glTranslatef(light5Pos[0], light5Pos[1], light5Pos[2]);
    glLightfv(GL_LIGHT5, GL_POSITION, light5Pos);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
  }
  if (showLight6 > 0) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(light6Cir, 0.0, 0.0, 1.0);
    glTranslatef(light6Pos[0], light6Pos[1], light6Pos[2]);
    glLightfv(GL_LIGHT6, GL_POSITION, light6Pos);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
  }
  if (showLight7 > 0) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(light7Cir, 0.0, 0.0, 1.0);
    glTranslatef(light7Pos[0], light7Pos[1], light7Pos[2]);
    glLightfv(GL_LIGHT7, GL_POSITION, light7Pos);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
  }
}

/*************************************************
 * 移动光源
 ************************************************/
void moveLight(void)
{
  light0Cir += 0.2;
  light1Cir += 0.2;
  light2Cir += 0.2;
  light3Cir += 0.2;
  light4Cir += 0.2;
  light5Cir += 0.2;
  light6Cir += 0.2;
  light7Cir += 0.2;
}
