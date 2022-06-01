#shader vertex
#version 330 core
layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

void main()
{
    //setting position and sending texCoord to the fragment shader
        gl_Position = vec4(position.xy,0.0 ,1.0);
        v_TexCoord = texCoord;
};


#shader fragment
#version 330 core
layout(location = 0) out vec4 color;


in vec2 v_TexCoord;

uniform sampler2D u_Texture;

void main()
{
    //setting a texture
        vec4 texColor = texture(u_Texture, v_TexCoord);
        color = texColor;
};


