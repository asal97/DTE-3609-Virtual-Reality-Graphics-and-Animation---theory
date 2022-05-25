#include "../include/Texture.h"
#include "../include/glCall.h"

#include "../Include/stb_image.h"



Texture::Texture(const std::string& path)
    :m_RenderID(0),m_FilePath(path), m_LocalBuffer(nullptr),
    m_Width(0), m_Height(0), m_BPP(0)
{
    stbi_set_flip_vertically_on_load;
    m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);
    GLCall(glGenTextures(1, &m_RenderID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_RenderID));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GLCall(glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,m_Width
        ,m_Height,0,GL_RGBA,GL_UNSIGNED_BYTE,m_LocalBuffer));
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));

    if (m_LocalBuffer)
        stbi_image_free(m_LocalBuffer);
}

Texture::Texture(const std::vector<std::string> faces)
    :m_RenderID(0), m_LocalBuffer(nullptr),
    m_Width(0), m_Height(0), m_BPP(0)
{
    stbi_set_flip_vertically_on_load;
    GLCall(glGenTextures(1, &m_RenderID));
    GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, m_RenderID));


    for(unsigned int i=0;i<faces.size();i++){
        m_LocalBuffer = stbi_load(faces[i].c_str(), &m_Width, &m_Height, &m_BPP, 4);
        GLCall(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,0,GL_RGBA8,m_Width
            ,m_Height,0,GL_RGBA,GL_UNSIGNED_BYTE,m_LocalBuffer));
        if(!m_LocalBuffer)
            std::cout<<"error thing \n"<<faces[i]<<"\n"<<stbi_failure_reason()<<std::endl;
        if (m_LocalBuffer)
            stbi_image_free(m_LocalBuffer);
    }




    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE));

    GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, 0));
}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1,&m_RenderID));
}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_RenderID));

}
void Texture::BindCubeMap(unsigned int slot) const
{
    GLCall(glActiveTexture(GL_TEXTURE_CUBE_MAP + slot));
    GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, m_RenderID));
}

void Texture::Unbind() const
{
}
