#include "../include/Landscape.hpp"
#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/glm.hpp"
#include "../../glm-master/glm/gtc/type_ptr.hpp"
//#include"../include/Basic.shader"

Landscape::Landscape()
{
}

Landscape::~Landscape()
{
}

void Landscape::privateInit()
{
  // Create vertex arrays



    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Basic.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color",0.2f,0.3f,0.8f,1.0f);



    texture.Bind(texSlot);
    shader.SetUniform1i("u_Texture", texSlot);
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 30000.0f);

    texture.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

}

void Landscape::privateRender()
{


       shader.Bind();
       texture.Bind(texSlot);


       shader.SetUniformMat4f("u_MVP",projectionMatrix_ * viewMatrix_* matrix_);

       vb.Bind();
       va.Bind();
       ib.Bind();
       GLCall(glDrawElements(GL_QUADS, ib.GetCount(), GL_UNSIGNED_INT, nullptr));




    shader.Unbind();
    va.Unbind();
    ib.Unbind();
    vb.Unbind();
    texture.Unbind();

  // Render the Landscape
}

void Landscape::privateUpdate()
{
}

