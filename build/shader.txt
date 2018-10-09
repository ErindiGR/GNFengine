#version 150
in vec4 vertex;
out vec2 TexCoords;


void main()
{
    gl_Position = vec4(vertex.xy, 1.0, 1.0);
    TexCoords = vertex.zw;
} 


#split#


#version 150
in vec2 TexCoords;
out vec4 color;
uniform sampler2D text;
uniform vec3 textColor;

void main()
{    
    color = vec4(textColor, texture(text, TexCoords).r);
}