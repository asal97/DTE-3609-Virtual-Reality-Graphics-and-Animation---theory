#include "../include/Landscape.hpp"

Landscape::Landscape()
{
}

Landscape::~Landscape()
{
}

//void Landscape::texture(){
//    //Init texture
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

//    glGenTextures(1, &texName_);

//    glBindTexture(GL_TEXTURE_2D, texName_);

//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


//    //width of texture, height of texture and number of colour channels
//    int widthTex, heightTex, nrChannels;
//    unsigned char *data = stbi_load("D:/UIT/VG-3609/start_code/assets/Snowflake2.png",
//                                        &widthTex, &heightTex, &nrChannels, 0);
//    if(data){
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthTex, heightTex, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//    }
//    else{
//        std::cout << "Failed to load landscape texture" << std::endl;
//    }


//    glBindTexture(GL_TEXTURE_2D, 0);
//    stbi_image_free(data);

//}

void Landscape::privateInit()
{
  // Create vertex arrays

//    float size = 50.0f;
//    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(2*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(2*size,-53.0f,-2*size));
//    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,-2*size));

//    vertexArray_.push_back(glm::vec3(-6*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,-2*size));
//    vertexArray_.push_back(glm::vec3(-6*size,-53.0f,-2*size));

//    vertexArray_.push_back(glm::vec3(2*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(6*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(6*size,-53.0f,-2*size));
//    vertexArray_.push_back(glm::vec3(2*size,-53.0f,-2*size));




//    vb = VertexBuffer(vertexArray_.data(), 12* 3 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(3);
    va.AddBuffer(vb,layout);

//    ib = IndexBuffer(indices, 12);


    va.Unbind();
    vb.Unbind();
    ib.Unbind();

}

void Landscape::privateRender()
{

       va.Bind();
       ib.Bind();
       GLCall(glDrawElements(GL_QUADS, ib.GetCount(), GL_UNSIGNED_INT, nullptr));


//    glEnable(GL_POLYGON_OFFSET_FILL);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glPolygonOffset(1.0f, 1.0f);


//    glEnable(GL_COLOR_MATERIAL);
//    glColor3f( 0.0f, 1.0f, 0.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,0,4);
//    glDisableClientState(GL_VERTEX_ARRAY);


//    glColor3f( 0.0f, 1.0f, 0.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,4,4);
//    glDisableClientState(GL_VERTEX_ARRAY);



//glColor3f( 0.0f, 1.0f, 0.0f);

//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,8,4);
//    glDisableClientState(GL_VERTEX_ARRAY);

//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

//    glEnable(GL_COLOR_MATERIAL);
//    glColor3f( 1.0f, 1.0f, 1.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,0,4);
//    glDisableClientState(GL_VERTEX_ARRAY);


//    glColor3f( 1.0f, 1.0f, 1.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,4,4);
//    glDisableClientState(GL_VERTEX_ARRAY);



//    glColor3f( 1.0f, 1.0f, 1.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,8,4);
//    glDisableClientState(GL_VERTEX_ARRAY);


    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_POLYGON_OFFSET_FILL);


  // Render the Landscape
}

void Landscape::privateUpdate()
{
}

