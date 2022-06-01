#shader vertex
#version 330 core


layout(location = 0) in vec4 position;
layout (location = 1) in vec3 aNormal;
layout(location = 2) in vec2 texCoord;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec4 lightPos;


out vec3 Normal;
out vec3 LightPos;
out vec3 FragPos;
out vec2 v_TexCoord;


//uniform vec4 lightPos;


void main()
{
        gl_Position = projection * view * model * position;
        Normal = mat3(transpose(inverse(model))) * aNormal;
        v_TexCoord = texCoord;
        LightPos = vec3(view * lightPos);
        FragPos = vec3(view * model * position);
};


#shader fragment
#version 330 core
layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

//uniform vec4 u_Color;
uniform sampler2D u_Texture;
uniform sampler2D u_Texture2;
uniform sampler2D material_diffuse;
uniform vec3 camera;

in vec3 FragPos;
in vec3 LightPos;
in vec3 Normal;


void main()
{
       vec4 texColor = mix(texture(u_Texture, v_TexCoord),texture(u_Texture2, v_TexCoord),0.5);


       vec3 light_ambient = vec3(0.2f,0.2f,0.2f);
       vec3 ambient = light_ambient * texture(material_diffuse, v_TexCoord).rgb;

       // diffuse
       vec3 norm = normalize(Normal);
       vec3 lightDir = normalize(LightPos - FragPos);
       float diff = max(dot(norm, lightDir), 0.0);
       vec3 light_diffuse = vec3(0.5f,0.5f,0.5f);
       vec3 diffuse = light_diffuse * diff * texture(material_diffuse, v_TexCoord).rgb;

       // specular
       vec3 viewDir = normalize(camera - FragPos);
       vec3 reflectDir = reflect(-lightDir, norm);
       float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64.0f);
       vec3 material_specular = vec3(0.5f,0.5f,0.5f);
       vec3 light_specular = vec3(1.0f,1.0f,1.0f);
       vec3 specular = light_specular * (spec * material_specular);

       vec3 result = ambient + diffuse + specular;


       color = mix(texColor, vec4(result, 1.0), 0.5);

};


