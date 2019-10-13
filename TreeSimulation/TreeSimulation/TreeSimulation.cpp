#include<stdlib.h>
#include<stdio.h>
#include<glut.h>
#include<math.h>
static GLfloat theta[]={0.0,0.0,0.0};
static GLfloat translateDist[]={0.0,0.0,0.0};
static GLfloat viewer[]={0.0,30.0,180.0};
static GLfloat viewer2[]={0.0,30.0,0.0};
GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
GLfloat mat_shininess[]={100};
GLfloat mat_amb_diff[]={0.1,0.5,0.8,1.0};
GLfloat light_position[]={0,1000,20,0};
GLdouble tree_positions[20][3]={0};
float size1[10]={2,2,2,2,2,2,2,2,2,2};
GLint count=0;
static GLint axis=1;
int oddeven;
float size=1;
GLfloat x,y;
float angle=-90;
GLdouble ox=0.0,oy=0.0,oz=0.0;
//Creating a leaf manually
void leaf()
{
	
	glTranslatef(0.0,2.5,0.0);
	glRotatef(-40.0,1.0,0.0,0.0); //angle between stem of leaf and leaf
	//glColor3f(0.0,0.4,0.0);
	mat_amb_diff[0]=0.109375;
	mat_amb_diff[1]=0.3789065;
	mat_amb_diff[2]=0.0117;
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,mat_amb_diff);
	glScalef(2,2,2);
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
	glScalef(0.5,0.5,0.5);
	glFlush();
	glTranslatef(0.0,-2.5,0.0);
}
//Combines a set of leaves to form a twig
void twig(float angle,int x,int y,int z,float radius,float height)
{
	glRotatef(angle,x,y,z);
//	glColor3f(0.2929,0.0578,0.0078);
	mat_amb_diff[0]=0.2929;
	mat_amb_diff[1]=0.0578;
	mat_amb_diff[2]=0.0078;
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,mat_amb_diff);
	GLUquadricObj *quadratic;
	quadratic=gluNewQuadric();
	gluCylinder(quadratic,radius,radius*0.7,height,30,1);

	glScalef(height/20.0,height/20.0,height/20.0);
	for(int i=0;i<2;i++){
		glTranslatef(0.0,0.0,10.0);
		glRotatef(60.0,1.0,0.0,0.0); //angle between twig and stem of leaf
		leaf();
		glRotatef(-60.0,1.0,0.0,0.0);
		glRotatef(180.0,0.0,0.0,1.0); // for opposite leaves
		glRotatef(60.0,1.0,0.0,0.0);
		leaf();
		glRotatef(-60.0,1.0,0.0,0.0);
		glRotatef(-180.0,0.0,0.0,1.0);
		glRotatef(70.0,0.0,0.0,1.0);	 // for next pair of leaves
	}
	glRotatef(-140.0,0.0,0.0,1.0); // bring back to normal 4*70
	glScalef(20.0/height,20.0/height,20.0/height);

	height-=1.0;
	if(height>1.0){
		if(oddeven==0){
			oddeven=1;
			twig(30.0,1.0,0.0,0.0,radius*0.7,height);
			twig(-30.0,1.0,0.0,0.0,radius*0.7,height);
		}
		else if(oddeven==1){
			oddeven=0;
			twig(30.0,0.0,1.0,0.0,radius*0.7,height);
			twig(-30.0,0.0,1.0,0.0,radius*0.7,height);
		}
	}
	height+=1.0;
	glTranslatef(0.0,0.0,0.0-height);
	glRotatef(0.0-angle,x,y,z);
}

//Combines several twigs to form a tree
void tree(float angle,int x,int y,int z,float radius,float height)
{
	glRotatef(angle,x,y,z);
	//glColor3f(0.2929,0.0578,0.0078);
	mat_amb_diff[0]=0.2929;
	mat_amb_diff[1]=0.0578;
	mat_amb_diff[2]=0.0078;
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,mat_amb_diff);
	GLUquadricObj *quadratic;
	quadratic=gluNewQuadric();
	gluCylinder(quadratic,radius,radius*0.7,height,30,1);
	glTranslatef(0.0,0.0,height);
	height-=1.0;
	if(height>5.0){
		if(oddeven==0){
			oddeven=1;
			tree(30.0,1.0,0.0,0.0,radius*0.7,height);
			tree(-30.0,1.0,0.0,0.0,radius*0.7,height);
		}
		else if(oddeven==1){
			oddeven=0;
			tree(30.0,0.0,1.0,0.0,radius*0.7,height);
			tree(-30.0,0.0,1.0,0.0,radius*0.7,height);
		}
	}
	else if(height >0.0)
	{
		if(oddeven==0){
			oddeven=1;
			twig(30.0,1.0,0.0,0.0,radius*0.7,height);
			twig(-30.0,1.0,0.0,0.0,radius*0.7,height);
		}
		else if(oddeven==1){
			oddeven=0;
			twig(30.0,0.0,1.0,0.0,radius*0.7,height);
			twig(-30.0,0.0,1.0,0.0,radius*0.7,height);
		}
	}
	height+=1.0;
	glTranslatef(0.0,0.0,0.0-height);
	glRotatef(0.0-angle,x,y,z);
}
void terrain()
{
	int i,j;
	mat_amb_diff[0]=0.9539;
	mat_amb_diff[1]=0.8359;
	mat_amb_diff[2]=0.64843;
	mat_amb_diff[3]=1;
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,mat_amb_diff);
//	glColor3f(0.9539,0.8359,0.64843);
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
// Function to set the display properties
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5273,0.8047,0.9700,1.0);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],viewer2[0],viewer2[1],viewer2[2],0,1,0);
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);

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
	//theta[axis]+=3.0;
	//if(theta[axis]>360.0)
	//	theta[axis]-=360;
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
	else 
		axis=4;
	if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
		axis=1;
	if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
		axis=2;
	
}

void handleSpecialKeypress(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_LEFT :angle-=10.0;
							viewer2[0]=viewer[0]+180*cos(angle*3.1428/180.0); //180 is height
							viewer2[2]=viewer[2]+180*sin(angle*3.1428/180.0);
							break;
		case GLUT_KEY_RIGHT :angle+=10.0;
							viewer2[0]=viewer[0]+180*cos(angle*3.1428/180.0);
							viewer2[2]=viewer[2]+180*sin(angle*3.1428/180.0);
							break;
		case GLUT_KEY_UP :	viewer2[0]=viewer[0]+200*cos(angle*3.1428/180.0);
							viewer2[2]=viewer[2]+200*sin(angle*3.1428/180.0);
							viewer[0]=viewer[0]+20*cos(angle*3.1428/180.0);
							viewer[2]=viewer[2]+20*sin(angle*3.1428/180.0);
							break;
		case GLUT_KEY_DOWN :viewer2[0]=viewer[0]+160*cos(angle*3.1428/180.0);
							viewer2[2]=viewer[2]+160*sin(angle*3.1428/180.0);
							viewer[0]=viewer[0]-20*cos(angle*3.1428/180.0);
							viewer[2]=viewer[2]-20*sin(angle*3.1428/180.0);
	}
}

void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
		case '4'://viewer[0]-=10.0;
				//viewer2[0]-=10.0;
				viewer[0]=viewer[0]+10*cos((angle-90)*3.1428/180.0);
				viewer[2]=viewer[2]+10*sin((angle-90)*3.1428/180.0);
				viewer2[0]=viewer2[0]+10*cos((angle-90)*3.1428/180.0);
				viewer2[2]=viewer2[2]+10*sin((angle-90)*3.1428/180.0);
				break;
		case '6'://viewer[0]+=10.0;
				//viewer2[0]+=10.0;
				viewer[0]=viewer[0]-10*cos((angle-90)*3.1428/180.0);
				viewer[2]=viewer[2]-10*sin((angle-90)*3.1428/180.0);
				viewer2[0]=viewer2[0]-10*cos((angle-90)*3.1428/180.0);
				viewer2[2]=viewer2[2]-10*sin((angle-90)*3.1428/180.0);
				break;
		case '2':viewer[1]-=10.0;
				viewer2[1]-=10.0;
				break;
		case '8':viewer[1]+=10.0;
				viewer2[1]+=10.0;
	}
	display();
}

void myReshape(int w,int h)
{
	
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,mat_amb_diff);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	//glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glFrustum(-70.0,70.0,-10.0*(GLfloat)h/(GLfloat)w,100.0*(GLfloat)h/(GLfloat)w,10.0,2000.0);
	else
		glFrustum(-50.0*(GLfloat)w/(GLfloat)h,50.0*(GLfloat)w/(GLfloat)h,-30.0,70.0,80.0,10000.0);
	glMatrixMode(GL_MODELVIEW);
}
void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1400,900);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rotating cube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(handleSpecialKeypress);
	glutIdleFunc(spincube);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glutMainLoop();
}
