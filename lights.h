#ifndef __LIGHTS_H__
#define __LIGHTS_H__

#include <GL/gl.h>

/************************************
 * 光源的位置
 ***********************************/
extern GLfloat light0Pos[];
extern GLfloat light1Pos[];
extern GLfloat light2Pos[];
extern GLfloat light3Pos[];
extern GLfloat light4Pos[];
extern GLfloat light5Pos[];
extern GLfloat light6Pos[];
extern GLfloat light7Pos[];

/************************************
 * 光源的散射光
 ***********************************/
extern GLfloat light0Diff[];
extern GLfloat light1Diff[];
extern GLfloat light2Diff[];
extern GLfloat light3Diff[];
extern GLfloat light4Diff[];
extern GLfloat light5Diff[];
extern GLfloat light6Diff[];
extern GLfloat light7Diff[];

/************************************
 * 光源的环境光
 ***********************************/
extern GLfloat light0Amb[];
extern GLfloat light1Amb[];
extern GLfloat light2Amb[];
extern GLfloat light3Amb[];
extern GLfloat light4Amb[];
extern GLfloat light5Amb[];
extern GLfloat light6Amb[];
extern GLfloat light7Amb[];

/************************************
 * 光源的绕z轴旋转位置
 ***********************************/
extern GLfloat light0Cir;
extern GLfloat light1Cir;
extern GLfloat light2Cir;
extern GLfloat light3Cir;
extern GLfloat light4Cir;
extern GLfloat light5Cir;
extern GLfloat light6Cir;
extern GLfloat light7Cir;

/************************************
 * 光源是否显示
 ***********************************/
extern int showLight0;
extern int showLight1;
extern int showLight2;
extern int showLight3;
extern int showLight4;
extern int showLight5;
extern int showLight6;
extern int showLight7;

/************************************
 * 光源初始化
 ***********************************/
void lightInit(void);

/************************************
 * 渲染光源
 ***********************************/
void drawLight(void);

/************************************
 * 移动光源
 ***********************************/
void moveLight(void);

#endif

