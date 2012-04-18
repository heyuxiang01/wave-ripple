#include <GL/glut.h>
#include "box.h"
#include "lights.h"
#include "wave.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WINDOW_TITLE_PREFIX "wave-ripple"

/**************************************************
 * 程序的运行状态，负数为暂停，正数为运行
 *************************************************/
static int state = -1;

/**************************************************
 * 生成wave的方法，负数为nurbsSurface,正数为glMapGrid
 *************************************************/
static int calcu = 1;

/**************************************************
 * 程序初始的观察角度，
 * rotate[0]表示x轴旋转度数，
 * rotate[1]表示y轴旋转度数，
 * rotate[2]表示z轴旋转度数，
 * rotate[3]表示各轴每次旋转过的度数
 **************************************************/
static GLfloat rotate[] = {
  -50.0f, 0.0f, -30.0f, 2.0f
};

/***************************************************
 * 程序的帧数
 ***************************************************/
static int countFrame = 0;

/****************************************************
 * 程序初始化
 ***************************************************/
static void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glEnable(GL_DEPTH_TEST);
  glFrontFace(GL_CCW);
  lightInit();
  waveInit();
}

/****************************************************
 * 渲染画面
 ***************************************************/
void display(void)
{
  countFrame++;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glRotatef(rotate[0], 1.0, 0.0, 0.0);
  glRotatef(rotate[1], 0.0, 1.0, 0.0);
  glRotatef(rotate[2], 0.0, 0.0, 1.0);
  if (showPoint > 0) {
    drawClr();
  }
  if (calcu > 0) {
    drawWave1();
  } else {
    drawWave();
  }
  drawLight();
  drawBox();
  glPopMatrix();
  glutSwapBuffers();
}

/*****************************************************
 * 重置窗口
 ****************************************************/
void reshape(GLsizei w, GLsizei h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(50.0, 1.0, 1.0, 100.0);
  gluLookAt(0.0, 0.0, 40.0,
	    0.0, 0.0, 0.0,
	    0.0, 1.0, 0.0);
}

/******************************************************
 * 动态效果时渲染画面
 *****************************************************/
void render(void)
{
  moveLight();
  moveWave();
  display();
}

/******************************************************
 * 计时器，定时计算帧数，并将帧数输出到控制台
 *****************************************************/
void timer(int v)
{
  if (0 != v) {
    char* tem = (char*) malloc(512 + strlen(WINDOW_TITLE_PREFIX));
    sprintf(tem, "%s: %d Frames Per Second", 
	    WINDOW_TITLE_PREFIX, 
	    countFrame * 4);
    glutSetWindowTitle(tem);
    free(tem);
    countFrame = 0;
  }
  glutTimerFunc(250, timer, 1);
}

/********************************************************
 * 响应键盘事件
 *******************************************************/
void keyboard(unsigned char key, int x, int y)
{
  switch(key) {
  case 27:    //27代表esc键
    exit(0);
    break;
  case 'a':   //绕x轴顺时针旋转
    rotate[0] -= rotate[3];
    glutPostRedisplay();
    break;
  case 'q':   //绕x轴逆时针旋转
    rotate[0] += rotate[3];
    glutPostRedisplay();
    break;
  case 's':   //绕y轴顺时针旋转
    rotate[1] -= rotate[3];
    glutPostRedisplay(); 
    break;
  case 'w':   //绕y轴逆时针旋转
    rotate[1] += rotate[3];
    glutPostRedisplay();
    break;
  case 'd':   //绕z轴顺时针旋转
    rotate[2] -= rotate[3];
    glutPostRedisplay();
    break;
  case 'e':   //绕z轴逆时针旋转
    rotate[2] += rotate[3];
    glutPostRedisplay();
    break;
  case 't':   //显示水波的控制点
    showPoint = -showPoint;
    glutPostRedisplay();
    break;
  case 'y':   //暂停程序和恢复程序
    state = -state;
    if (state > 0) {
      glutIdleFunc(render);      
    } else {
      glutIdleFunc(0);
    }
    break;
  case 'r':   //重置观察角度
    rotate[0] = -50.0f;
    rotate[1] = 0.0f;
    rotate[2] = -30.0f;
    glutPostRedisplay();
    break;
  case 'u':   //重置水波
    makeCtlPoints();
    break;
  case 'c':   //曲面算法选择
    calcu = -calcu;
    glutPostRedisplay();
    break;
  //开启0～7号灯
  case '0':
    showLight0 = -showLight0;
    if (showLight0 > 0) {
      glEnable(GL_LIGHT0);
    } else {
      glDisable(GL_LIGHT0);
    }
    glutPostRedisplay();
    break;
  case '1':
    showLight1 = -showLight1;
    if (showLight1 > 0) {
      glEnable(GL_LIGHT1);
    } else {
      glDisable(GL_LIGHT1);
    }
    glutPostRedisplay();
    break;
  case '2':
    showLight2 = -showLight2;
    if (showLight2 > 0) {
      glEnable(GL_LIGHT2);
    } else {
      glDisable(GL_LIGHT2);
    }
    glutPostRedisplay();
    break;
  case '3':
    showLight3 = -showLight3;
    if (showLight3 > 0) {
      glEnable(GL_LIGHT3);
    } else {
      glDisable(GL_LIGHT3);
    }
    glutPostRedisplay();
    break;
  case '4':
    showLight4 = -showLight4;
    if (showLight4 > 0) {
      glEnable(GL_LIGHT4);
    } else {
      glDisable(GL_LIGHT4);
    }
    glutPostRedisplay();
    break;
  case '5':
    showLight5 = -showLight5;
    if (showLight5 > 0) {
      glEnable(GL_LIGHT5);
    } else {
      glDisable(GL_LIGHT5);
    }
    glutPostRedisplay();
    break;
  case '6':
    showLight6 = -showLight6;
    if (showLight6 > 0) {
      glEnable(GL_LIGHT6);
    } else {
      glDisable(GL_LIGHT6);
    }
    glutPostRedisplay();
    break;
  case '7':
    showLight7 = -showLight7;
    if (showLight7 > 0) {
      glEnable(GL_LIGHT7);
    } else {
      glDisable(GL_LIGHT7);
    }
    glutPostRedisplay();
    break;
  case '8':
    showLight0 = -1;
    showLight1 = -1;
    showLight2 = -1;
    showLight3 = -1;
    showLight4 = -1;
    showLight5 = -1;
    showLight6 = -1;
    showLight7 = -1;
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);
    glDisable(GL_LIGHT5);
    glDisable(GL_LIGHT6);
    glDisable(GL_LIGHT7);
    glutPostRedisplay();
    break;
  }
}

/*************************************************
 * 程序入口函数
 ************************************************/
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 700);
  glutInitWindowPosition(380, 30);
  glutCreateWindow(WINDOW_TITLE_PREFIX);
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(250,timer,0);
  glutMainLoop();
  return 0;
}
