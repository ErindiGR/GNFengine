#version 150
in vec3 position;
in vec3 normal;
in vec2 texcoord;

out vec2 texcoord0;

uniform mat4 pv;
uniform mat4 mm;

void main()
{
    gl_Position =  pv * mm * vec4(position, 1.0);
    texcoord0 = position.xy;
} 


#split#


#version 150
in vec2 texcoord0;
out vec4 color;
uniform sampler2D texture0;

void main()
{    
    color = vec4(texture(texture0,texcoord0).rgb,1);
}