precision highp float;

uniform sampler2D tex;

varying vec4 colorVarying;

		
void main(){
	gl_FragColor = texture2D(tex, gl_PointCoord)*colorVarying;	
}