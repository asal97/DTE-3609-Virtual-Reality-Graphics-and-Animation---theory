#include "../include/Landscape.hpp"

Landscape::Landscape()
{
}

Landscape::~Landscape()
{
}

void Landscape::privateInit()
{
  // Create vertex arrays

    float size = 50.0f;
    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,2*size));
    vertexArray_.push_back(glm::vec3(2*size,-53.0f,2*size));
    vertexArray_.push_back(glm::vec3(2*size,-53.0f,-2*size));
    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,-2*size));

    vertexArray_.push_back(glm::vec3(-6*size,-53.0f,2*size));
    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,2*size));
    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,-2*size));
    vertexArray_.push_back(glm::vec3(-6*size,-53.0f,-2*size));

    vertexArray_.push_back(glm::vec3(2*size,-53.0f,2*size));
    vertexArray_.push_back(glm::vec3(6*size,-53.0f,2*size));
    vertexArray_.push_back(glm::vec3(6*size,-53.0f,-2*size));
    vertexArray_.push_back(glm::vec3(2*size,-53.0f,-2*size));

}

void Landscape::privateRender()
{
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonOffset(1.0f, 1.0f);


    glEnable(GL_COLOR_MATERIAL);
    glColor3f( 0.0f, 1.0f, 0.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
    glDrawArrays(GL_QUADS,0,4);
    glDisableClientState(GL_VERTEX_ARRAY);


    glColor3f( 0.0f, 1.0f, 0.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
    glDrawArrays(GL_QUADS,4,4);
    glDisableClientState(GL_VERTEX_ARRAY);



glColor3f( 0.0f, 1.0f, 0.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
    glDrawArrays(GL_QUADS,8,4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_COLOR_MATERIAL);
    glColor3f( 1.0f, 1.0f, 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
    glDrawArrays(GL_QUADS,0,4);
    glDisableClientState(GL_VERTEX_ARRAY);


    glColor3f( 1.0f, 1.0f, 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
    glDrawArrays(GL_QUADS,4,4);
    glDisableClientState(GL_VERTEX_ARRAY);



    glColor3f( 1.0f, 1.0f, 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
    glDrawArrays(GL_QUADS,8,4);
    glDisableClientState(GL_VERTEX_ARRAY);


    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_POLYGON_OFFSET_FILL);


  // Render the Landscape
}

void Landscape::privateUpdate()
{
}

