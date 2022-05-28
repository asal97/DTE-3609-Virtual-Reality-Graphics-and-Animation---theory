#shader vertex
#version 330 core
layout(location = 0) in vec4 position;
layout (location = 1) in vec3 aNormal;
layout(location = 2) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 Normal;
out vec3 LightPos;
out vec3 FragPos;

out vec2 v_TexCoord;

uniform vec4 lightPos;

void main()
{
        gl_Position = projection * view * model * position;
        v_TexCoord = texCoord;
        Normal = aNormal;
        LightPos = vec3(view * vec4(vec3(lightPos), 1.0));
        FragPos = vec3(view * model * position);
};


#shader fragment
#version 330 core
layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform sampler2D u_Texture;
uniform vec4 u_Color;




//Adding lights
in vec3 Normal;
in vec3 LightPos;
in vec3 FragPos;

void main()
{
        vec4 texColor = texture(u_Texture, v_TexCoord);
//        color = texColor;

        vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

        float ambientStrength = 0.1;
        vec3 ambient = ambientStrength * lightColor;

        //Diffuse
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(LightPos - FragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lightColor;

        //Specular
        float specularStrength = 0.5;
        vec3 viewDir = normalize(-FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 2);
        vec3 specular = specularStrength * spec * lightColor;

        vec3 result = (ambient + diffuse + specular);

        color = mix(texColor, vec4(result, 1.0), 0.3);

};


