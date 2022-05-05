#include <windows.h>
#include "GL/glew.h"
#include "../../glm-master/glm/glm.hpp"
#include "../include/FpsCounter.hpp"
#include "../include/GameManager.hpp"
#include "../include/Input.hpp"
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


#include <iostream>

std::shared_ptr<GameManager> gm;
siut::FpsCounter counter;

int window;

bool keyPressed[30];
int mousePosX, mousePosY;
float moveX, moveY;

void init() {
    glewInit();

  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);

  counter.start();

  gm.reset(new GameManager());
  gm->init();

  for (int i = 0; i < 30; i++)
    keyPressed[i] = false;




  GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
  glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  gm->update(counter.fps());
  gm->render();

//  GLenum err = glGetError();
//  if (err != GL_NO_ERROR)
//    std::cout<< "OpenGL error: " << gluErrorString(err) << std::endl;
//  std::cout.flush();

//  char *buff = (char*)glGetString(GL_VERSION);
//  std::cout<< buff << std::endl;

//  buff = (char*)glGetString(GL_VENDOR);
//  std::cout<< buff << std::endl;
//  buff = (char*)glGetString(GL_RENDERER);
//  std::cout<< buff<<std::endl;
//  char *buff = (char*)glGetString(GL_EXTENSIONS);
//  std::cout<< buff<<std::endl;

  if (keyPressed[KEY_ID_W] == true)
    gm->getCam()->moveForward();
  if (keyPressed[KEY_ID_A] == true)
    gm->getCam()->moveLeft();
  if (keyPressed[KEY_ID_D] == true)
    gm->getCam()->moveRight();
  if (keyPressed[KEY_ID_S] == true)
    gm->getCam()->moveBackward();
  if (keyPressed[KEY_ID_SPACE] == true)
    gm->getCam()->moveUp();
  if (keyPressed[KEY_ID_C] == true)
    gm->getCam()->moveDown();
  if (keyPressed[KEY_ID_G] == true)
    gm->getCam()->rotateLeft();
  if (keyPressed[KEY_ID_H] == true)
    gm->getCam()->rotateRight();
  if (keyPressed[KEY_ID_UP] == true)
    gm->getCharacter()->moveUpward();
  if (keyPressed[KEY_ID_DOWN] == true)
    gm->getCharacter()->moveDownward();

  glutSwapBuffers();
  glutPostRedisplay();
}

void keyDown(unsigned char key, int x, int y) {
  switch (key) {
  case 'q':
  case 27:
    glutDestroyWindow(window);
#ifndef _WIN32
    // Must use this with regular glut, since it never returns control to
    // main().
    exit(0);
#endif
    break;

  case 'w':
    keyPressed[KEY_ID_W] = true;
    break;
  case 'a':
    keyPressed[KEY_ID_A] = true;
    break;
  case 's':
    keyPressed[KEY_ID_S] = true;
    break;
  case 'd':
    keyPressed[KEY_ID_D] = true;
    break;
  case ' ':
    keyPressed[KEY_ID_SPACE] = true;
    break;
  case 'c':
    keyPressed[KEY_ID_C] = true;
    break;
  case 'g':
    keyPressed[KEY_ID_G] = true;
    break;
  case 'h':
    keyPressed[KEY_ID_H] = true;
    break;
  case 'o':
    keyPressed[KEY_ID_UP] = true;
    break;
  case 'p':
    keyPressed[KEY_ID_DOWN] = true;
    break;
  default:
    glutPostRedisplay();
  }
}

void keyUp(unsigned char key, int x, int y) {
  switch (key) {
  case 'w':
    keyPressed[KEY_ID_W] = false;
    break;
  case 'a':
    keyPressed[KEY_ID_A] = false;
    break;
  case 's':
    keyPressed[KEY_ID_S] = false;
    break;
  case 'd':
    keyPressed[KEY_ID_D] = false;
    break;
  case ' ':
    keyPressed[KEY_ID_SPACE] = false;
    break;
  case 'c':
    keyPressed[KEY_ID_C] = false;
    break;
  case 'g':
    keyPressed[KEY_ID_G] = false;
    break;
  case 'h':
    keyPressed[KEY_ID_H] = false;
    break;
  case 'o':
    keyPressed[KEY_ID_UP] = false;
    break;
  case 'p':
    keyPressed[KEY_ID_DOWN] = false;
    break;
  }
}

void mousePressed(int button, int state, int posX, int posY) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    mousePosX = posX;
    mousePosY = posY;
    keyPressed[MOUSE_LEFT_BUTTON_DOWN] = true;
  }
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    keyPressed[MOUSE_LEFT_BUTTON_DOWN] = false;
}

void mouseMoved(int posX, int posY) {
  if (keyPressed[MOUSE_LEFT_BUTTON_DOWN]) {
    int diffX = posX - mousePosX;
    mousePosX = posX;
    int diffY = posY - mousePosY;
    mousePosY = posY;

    // Implement quaternion based mouse move
  }
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(60.0f, float(w) / float(h), 1.0f, 3000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
  glutInitWindowSize(900, 700);
  glutInitWindowPosition(200, 10);
  window = glutCreateWindow("Game application");
  init();
  glutKeyboardFunc(keyDown);
  glutKeyboardUpFunc(keyUp);
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMouseFunc(mousePressed);
  glutMotionFunc(mouseMoved);

  // Add other callback functions here..

  glutMainLoop();
  return 0;
}
