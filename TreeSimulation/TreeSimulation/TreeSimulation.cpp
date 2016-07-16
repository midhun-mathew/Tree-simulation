#include<stdlib.h>
#include<stdio.h>
#include<glut.h>
#include<math.h>
static GLfloat theta[]={270.0,0.0,0.0};
static GLint axis=1;
int oddeven;
float size=1;
void leaf()
{
	glTranslatef(0.0,2.5,0.0);
	glRotatef(-40.0,1.0,0.0,0.0);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.4,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(1.0,0.8,0.0);
	glVertex3f(1.8,2.0,0.0);
	glVertex3f(2.0,3.0,0.0);
	glVertex3f(2.1,4.0,0.0);
	glVertex3f(2.0,4.5,0.0);
	glVertex3f(1.8,5.0,0.0);
	glVertex3f(1.4,6.0,0.0);
	glVertex3f(1.0,6.5,0.0);
	glVertex3f(0.4,7.0,0.0);
	glVertex3f(0.0,7.4,0.0);
	glVertex3f(-0.5,7.8,0.0);
	glVertex3f(-1.2,8.8,0.0);
	glVertex3f(-1.1,8.25,0.0);
	glVertex3f(-1.15,8.0,0.0);
	glVertex3f(-1.2,7.5,0.0);
	glVertex3f(-1.4,7.0,0.0);
	glVertex3f(-1.6,6.5,0.0);
	glVertex3f(-1.8,6.0,0.0);
	glVertex3f(-1.9,5.5,0.0);
	glVertex3f(-2.0,5.0,0.0);
	glVertex3f(-2.0,4.0,0.0);
	glVertex3f(-1.9,3.5,0.0);
	glVertex3f(-1.7,3.0,0.0);
	glVertex3f(-1.5,2.5,0.0);
	glVertex3f(-1.2,2.0,0.0);
	glVertex3f(-1.0,1.5,0.0);
	glVertex3f(-0.7,1.0,0.0);
	glVertex3f(-0.4,0.5,0.0);
	glVertex3f(-0.2,0.0,0.0);
	glEnd();
	glRotatef(40.0,1.0,0.0,0.0);
	glColor3f(0.0,01.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1,0.0,0.0);
	glVertex3f(-0.1,-2.5,0.0);
	glVertex3f(0.0,-2.5,0.0);
	glVertex3f(0.0,0.0,0.0);
	glEnd();
	glFlush();
	glTranslatef(0.0,-2.5,0.0);
}
void twig(float angle,int x,int y,int z,float radius,float height)
{
	glRotatef(angle,x,y,z);
	glColor3f(0.2929,0.0578,0.0078);

	GLUquadricObj *quadratic;
	quadratic=gluNewQuadric();
	gluCylinder(quadratic,radius,radius*0.7,height,30,1);

	glScalef(height/20.0,height/20.0,height/20.0);
	for(int i=0;i<4;i++){
		glTranslatef(0.0,0.0,5.0);
		glRotatef(60.0,1.0,0.0,0.0);
		leaf();
		glRotatef(-60.0,1.0,0.0,0.0);
		glRotatef(180.0,0.0,0.0,1.0);
		glRotatef(60.0,1.0,0.0,0.0);
		leaf();
		glRotatef(-60.0,1.0,0.0,0.0);
		glRotatef(-180.0,0.0,0.0,1.0);
		glRotatef(70.0,0.0,0.0,1.0);	
}
	glRotatef(-280.0,0.0,0.0,1.0);
	
	glScalef(20.0/height,20.0/height,20.0/height);
	if(height>0.0){
		if(oddeven==0){
			oddeven=1;
			twig(30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
			twig(-30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
		}
		else if(oddeven==1){
			oddeven=0;
			twig(40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
			twig(-40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
		}
	}
	glTranslatef(0.0,0.0,0.0-height);
	glRotatef(0.0-angle,x,y,z);
}
void tree(float angle,int x,int y,int z,float radius,float height)
{
	glRotatef(angle,x,y,z);
	glColor3f(0.2929,0.0578,0.0078);
	GLUquadricObj *quadratic;
	quadratic=gluNewQuadric();
	gluCylinder(quadratic,radius,radius*0.7,height,30,1);
	glTranslatef(0.0,0.0,height);
	if(height>10.0){
		if(oddeven==0){
			oddeven=1;
			tree(30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
			tree(-30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
		}
		else if(oddeven==1){
			oddeven=0;
			tree(40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
			tree(-40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
		}
	}
	else if(height >0.0)
	{
		if(oddeven==0){
			oddeven=1;
			twig(30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
			twig(-30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
		}
		else if(oddeven==1){
			oddeven=0;
			twig(40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
			twig(-40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
		}
	}
	
	glTranslatef(0.0,0.0,0.0-height);
	glRotatef(0.0-angle,x,y,z);
	

}
void terrain()
{
	int i,j;
	glColor3f(0.9539,0.8359,0.64843);
	glBegin(GL_QUADS);
	for(i=-120;i<120;i+=10)
		for(j=-50;j<70;j+=10)
		{
			glVertex3d(i,0,j);
			glVertex3d(i+10,0,j);
			glVertex3d(i+10,0,j+10);
			glVertex3d(i,0,j+10);
			
		}
	glEnd();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5273,0.8047,0.9700,1.0);
	glLoadIdentity();
	glRotatef(35.0,1,0,0);
	
	
	terrain();
	glRotatef(35.0,0,1,0);
	//glRotatef(theta[0],1.0,0.0,0.0);
	//glRotatef(theta[1],0.0,1.0,0.0);
	//glRotatef(theta[2],0.0,0.0,1.0);
	
	oddeven=0;
	tree(270.0,1.0,0.0,0.0,size/4.5,size);
	if(size<18.0)
		size+=0.05;
	glFlush();
	glutSwapBuffers();
}
void spincube()
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
	glutInitWindowSize(1430,900);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rotating cube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutIdleFunc(spincube);
	
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
