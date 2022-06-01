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

//minimap code

/*

float vertices[4 * 3 * 2] = {
    -1.0f,  1.0f,  0.0f, 1.0f,
    -1.0f, 0.5f,  0.0f, 0.0f,
    -0.5f, 0.5f,  1.0f, 0.0f,

    -1.0f,  1.0f,  0.0f, 1.0f,
    -0.5f, 0.5f,  1.0f, 0.0f,
    -0.5f,  1.0f,  1.0f, 1.0f
};

unsigned int indices[6] = {
        0, 1, 2,
        3, 4, 5
};

unsigned int fbo;
unsigned int rbo;
unsigned int texture;
std::shared_ptr<VertexBuffer> vbo;
std::shared_ptr<VertexBufferLayout> layout;
std::shared_ptr<VertexArray> vao;
std::shared_ptr<IndexBuffer> ibo;
std::shared_ptr<Shader> shader;

*/

void init() {
      glewInit();

      GLCall(glClearColor(1.0, 1.0, 1.0, 0.0));
      glShadeModel(GL_SMOOTH);
      glEnable(GL_DEPTH_TEST);

      counter.start();

      gm.reset(new GameManager());
      gm->init();
      //Minimap code
/*

     GLCall(glEnable(GL_BLEND));
   GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));


      vbo.reset(new VertexBuffer(vertices, 4 * 3 * 2 * sizeof(float)));
      layout.reset(new VertexBufferLayout());
      vao.reset(new VertexArray());
      ibo.reset(new IndexBuffer(indices, 6));
      shader.reset(new Shader());
      shader->initShader(("D:/UIT/VG-3609/start_code/include/Minimap.shader"));




      GLCall(glGenFramebuffers(1, &fbo));
      GLCall(glBindFramebuffer(GL_FRAMEBUFFER, fbo));

      // Create a texture for the framebuffer
      GLCall(glGenTextures(1, &texture));
      GLCall(glBindTexture(GL_TEXTURE_2D, texture));
      GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 900, 700, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL));
      GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
      GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

      // Attach to frambuffer
      GLCall(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0));
      GLCall(glBindTexture(GL_TEXTURE_2D, 0));

      // Renderbuffer stuff
      GLCall(glGenRenderbuffers(1, &rbo));
      GLCall(glBindRenderbuffer(GL_RENDERBUFFER, rbo));
      GLCall(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 900, 700));
      glBindRenderbuffer(GL_RENDERBUFFER, 0);
      GLCall(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo));

      if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
          std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
      glBindFramebuffer(GL_FRAMEBUFFER, 0);

      layout->Push<float>(2);
      layout->Push<float>(2);

      vao->AddBuffer(*vbo,*layout);

      shader->Bind();
      shader->SetUniform1i("u_Texture", 0);
        vao->Unbind();
      vbo->Unbind();
      ibo->Unbind();
      shader->Unbind();


    GLCall(glDisable(GL_BLEND));
    */

      for (int i = 0; i < 30; i++)
        keyPressed[i] = false;
}

void display() {

    GLCall(glEnable(GL_DEPTH_TEST));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gm->update(counter.fps());
    gm->render();

    //Minimap code
    /*

  // Render fbo to texture
    GLCall(glBindFramebuffer(GL_FRAMEBUFFER, fbo)); //fbo stuff
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    gm->render();

    GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));

    shader->Bind();
    vao->Bind();
    ibo->Bind();
    GLCall(glBindTexture(GL_TEXTURE_2D, texture));

    GLCall(glDrawElements(GL_TRIANGLES, ibo->GetCount(), GL_UNSIGNED_INT, nullptr));

    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
    ibo->Unbind();
    vao->Unbind();
    shader->Unbind();
    */

//    GLCall(glDisable(GL_DEPTH_TEST));

      gm->update(counter.fps());
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
//  if (keyPressed[KEY_ID_G] == true)
//    gm->getCam()->rotateLeft();
//  if (keyPressed[KEY_ID_H] == true)
//    gm->getCam()->rotateRight();
  if (keyPressed[KEY_ID_UP] == true)
    gm->getCharacter()->moveUpward();

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
//  case 'g':
//    keyPressed[KEY_ID_G] = true;
//    break;
//  case 'h':
//    keyPressed[KEY_ID_H] = true;
//    break;
  case 'j':
    keyPressed[KEY_ID_UP] = true;
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

  case 'j':
    keyPressed[KEY_ID_UP] = false;
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

  gluPerspective(60.0f, float(w) / float(h), 1.0f, 30000.0f);

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
