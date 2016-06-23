#include<stdlib.h>
#include<stdio.h>
#include<glut.h>

static GLfloat theta[]={270.0,0.0,0.0};
static GLint axis=1;
int oddeven;
float size=1;
void cyllinder(float angle,int x,int y,int z,float radius,float height)
{
	glRotatef(angle,x,y,z);
	glColor3f(0.2929,0.0578,0.0078);
	GLUquadricObj *quadratic;
	quadratic=gluNewQuadric();
	gluCylinder(quadratic,radius,radius*0.7,height,30,1);
	glTranslatef(0.0,0.0,height);
	if(height>0.0){
		if(oddeven==0){
			oddeven=1;
			cyllinder(30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
			cyllinder(-30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
		}
		else if(oddeven==1){
			oddeven=0;
			cyllinder(40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
			cyllinder(-40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
		}
	}
	glTranslatef(0.0,0.0,0.0-height);
	glRotatef(0.0-angle,x,y,z);
	

}
void terrain()
{
	int i,j;
	glColor3f(0.9539,0.8359,0.64843);
	
	for(i=-90;i<90;i+=10)
		for(j=-50;j<70;j+=10)
		{
			glBegin(GL_POLYGON);
			glVertex3f(i,0,j);
			glVertex3f(i+10,0,j);
			glVertex3f(i+10,0,j+10);
			glVertex3f(i,0,j+10);
			glEnd();
		}
	

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5273,0.8047,0.9766,1.0);
	glLoadIdentity();
	glRotatef(90,1,0,0);
	glRotatef(35.0,1,0,0);
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	glRotatef(35.0,0,1,0);
	oddeven=0;
	terrain();
	size=18;
	cyllinder(270.0,1.0,0.0,0.0,size/4.5,size);
	glFlush();
	glutSwapBuffers();
}
void spintree()
{
	theta[axis]+=3.0;
	if(theta[axis]>360.0)
		theta[axis]-=360;
	glutPostRedisplay();
}
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
		axis=0;
	if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
		axis=1;
	if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
		axis=2;

}
void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-70.0,70.0,-50.0*(GLfloat)h/(GLfloat)w,100.0*(GLfloat)h/(GLfloat)w,-100.0,100.0);
	else
		glOrtho(-70.0*(GLfloat)w/(GLfloat)h,70.0*(GLfloat)w/(GLfloat)h,-50.0,100.0,-100.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}
void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rotating cube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutIdleFunc(spintree);
	
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}