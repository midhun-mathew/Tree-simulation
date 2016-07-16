#include<stdlib.h>
#include<stdio.h>
#include<glut.h>
#include<math.h>
static GLfloat theta[]={270.0,0.0,0.0};
GLdouble tree_positions[20][3]={0};
float size1[10]={2,2,2,2,2,2,2,2,2,2};
static GLint axis=1;
int oddeven;
GLint count=0;
float size=1;
GLdouble ox=0.0,oy=0.0,oz=0.0;
void leaf()
{
	glTranslatef(0.0,2.5,0.0);
	glRotatef(-40.0,1.0,0.0,0.0);
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
	for(i=-1000;i<1000;i+=10)
		for(j=-1000;j<1000;j+=10)
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
	glRotatef(270.0,1.0,0.0,0.0);
	oddeven=0;
	glPushMatrix();
	for(int i=0;i<count;i++)
	{
	
		if(count>0)
			glTranslatef(tree_positions[i][0],tree_positions[i][1],tree_positions[i][2]);
		//glTranslatef(ox,oy,oz);
		//printf("%d ",count);
		if(size1[i]>5.0)
			tree(0.0,1.0,0.0,0.0,size1[i]/4.5,size1[i]);
		else
			twig(0.0,1.0,0.0,0.0,size1[i]/4.5,size1[i]);
		if(size1[i]<13.0)
			size1[i]+=1.0;
		glPopMatrix();

	}
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
	GLint viewport[4];
	GLdouble modelview[16],projection[16];
	GLfloat wx=x,wy,wz;
	glGetIntegerv(GL_VIEWPORT,viewport);
	y=viewport[3]-y;
	wy=y;
	glGetDoublev(GL_MODELVIEW_MATRIX,modelview);
	glGetDoublev(GL_PROJECTION_MATRIX,projection);
	glReadPixels(x,y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&wz);
	gluUnProject(wx,wy,wz,modelview,projection,viewport,&ox,&oy,&oz);
	tree_positions[count][0]=ox;
	tree_positions[count][1]=oy;
	tree_positions[count][2]=oz;
	printf("%lf %lf %lf\n%lf %lf %lf\n\n",ox,oy,oz,tree_positions[count-1][0],tree_positions[count-1][1],tree_positions[count-1][2]);
	glutPostRedisplay();
	

	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
		count++;
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
