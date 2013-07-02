attribute vec4 position;

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

attribute float		pointSize;
attribute  float	angle;
varying  float		rotAngle;

void main()
{
	rotAngle = angle;
	
	vec4 eyeCoord = modelViewMatrix * position;
	gl_Position = projectionMatrix * eyeCoord;
	
	float dist = sqrt(eyeCoord.x*eyeCoord.x + eyeCoord.y*eyeCoord.y + eyeCoord.z*eyeCoord.z);
	float att	 = 1200.0 / dist;
	gl_PointSize = pointSize * att;

}
