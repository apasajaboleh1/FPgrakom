#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <IL/il.h>
#include "glm.h"
#include "glmint.h"
#include "glTexture.h"
glTexture hTexture;
GLMmodel *sample,*sample1,*sample2,*sample3,*sample4,*sample5,*sample6;
float ratio;
double lookat[9]={4.5,3,0,0,0,0,0,1,0};
void Draw()
{
    glPushMatrix();
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glScaled(5,1,15);
    glTranslatef(-2,-3.65,-1.33);
    glRotated(90,1,0,0);
    GLfloat mat_ambient[]={0.0f, 1.0f, 0.0f, 0.0f}; // gray
    glMaterialfv(GL_FRONT, GL_AMBIENT,  mat_ambient);
    glBegin(GL_QUADS);
        glTexCoord2d(0.0f, 0.0f);glVertex3f(-0.5f, 0.0f, -1.1f);
        glTexCoord2d(0.0f, 15.0f);glVertex3f(-0.5f, 2.5f, -1.1f);
        glTexCoord2d(15.0f, 15.0f);glVertex3f(2.5f, 2.5f, -1.1f);
        glTexCoord2d(15.0f, 0.0f);glVertex3f(2.5f, 0.0f, -1.1f);
    glEnd();
    glPopMatrix();
}
void gerak(unsigned char key, int x, int y)
{
    if(key=='r')
    {
        lookat[0]=4.5;
        lookat[1]=3;
        lookat[2]=0;
        lookat[3]=0;
        lookat[4]=0;
        lookat[5]=0;
        lookat[6]=0;
        lookat[7]=1;
        lookat[8]=0;
    }
    else if(key=='a')
    {
        lookat[1]=0.1;
        lookat[0]=5;
        lookat[2]=0;
    }

    else{
        lookat[0]=0;
        lookat[1]=5;
        lookat[2]=1;
    }
    glutPostRedisplay();
}
void Init() {
    //inisialisasi mode smoot dan texture dari gambar
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_DONT_CARE);
    //Perspektif View
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glShadeModel(GL_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //blend warna untuk texture dan warna
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}
void gambar_jalan()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    if (!sample) {
    sample = glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\testok.obj");
    if (!sample) exit(0); //gagal = exit
    glmUnitize(sample);
    glmFacetNormals(sample);
    glmVertexNormals(sample,90.0,GL_TRUE);
    }
    glTranslated(-3.5,-2.5,1);
    glScaled(6,1,1);
    glmDraw(sample, GLM_SMOOTH | GLM_TEXTURE|GLM_MATERIAL);
}
void gambar_lain()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    if(!sample1)
    {
        sample1=glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\testok.obj");
        if(!sample1)exit(0);
        glmUnitize(sample1);
        glmFacetNormals(sample1);
        glmVertexNormals(sample1,90.0,GL_TRUE);

    }
    glTranslated(0,0,-2);
    glmDraw(sample1, GLM_SMOOTH | GLM_TEXTURE|GLM_MATERIAL);
}
void mobil()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    if(!sample2)
    {
        sample2=glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\SCI_FRS_13_HD.obj"); //??????? errr ini gambar
        if(!sample2)exit(0);
        glmUnitize(sample2);
        glmFacetNormals(sample2);
        glmVertexNormals(sample2,90.0,GL_TRUE);
    }
    glmDraw(sample2, GLM_SMOOTH | GLM_TEXTURE|GLM_MATERIAL);
}
void gedung()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
     if(!sample3)
        {
            sample3=glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\4.obj");
            if(!sample3)exit(0);
            glmUnitize(sample3);
            glmFacetNormals(sample3);
            glmVertexNormals(sample3,90.0,GL_TRUE);
        }
        glScalef(0.8,1,1);
        glTranslatef(.65,0.5,-2);
        glRotated(-90,0,1,0);
        glmDraw(sample3, GLM_SMOOTH | GLM_TEXTURE|GLM_MATERIAL);
}
void gedung1()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
     if(!sample4)
        {
            sample4=glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\4.obj");
            if(!sample4)exit(0);
            glmUnitize(sample4);
            glmFacetNormals(sample4);
            glmVertexNormals(sample4,90.0,GL_TRUE);
        }
        glTranslatef(0,0,.6);
        glmDraw(sample4, GLM_SMOOTH | GLM_TEXTURE|GLM_MATERIAL);
}
void gedungki()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
     if(!sample5)
        {
            sample5=glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\al.obj");
            if(!sample5)exit(0);
            glmUnitize(sample5);
            glmFacetNormals(sample5);
            glmVertexNormals(sample5,90.0,GL_TRUE);
        }

        glTranslatef(0,2,0);
        glmDraw(sample5, GLM_SMOOTH | GLM_TEXTURE|GLM_MATERIAL);
}
void gedungki2()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
     if(!sample6)
        {
            sample6=glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\al.obj");
            if(!sample6)exit(0);
            glmUnitize(sample6);
            glmFacetNormals(sample6);
            glmVertexNormals(sample6,90.0,GL_TRUE);
        }

        glTranslatef(0,2,0);
        glmDraw(sample6, GLM_SMOOTH | GLM_TEXTURE|GLM_MATERIAL);
}
void display() {
    //mode buffer warna dan 3 dimensi
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //warna latar
    glClearColor(0.8, 0.8, 0.8, 0.0);

    //inisialisasi identity
    glLoadIdentity();
    GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_position[] = { 3.0, 3.0, 1.0, 1.0 };
    GLfloat spot_direction[] = { 3.0, 3.0, 0.0 };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
    glEnable(GL_LIGHT1);
    GLfloat pos[4]={0.1,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    gluLookAt(lookat[0],lookat[1],lookat[2],lookat[3],lookat[4],lookat[5],lookat[6],lookat[7],lookat[8]);
    //push matrix object
    Draw();
    glPushMatrix();
        gambar_jalan();//jalan no 1
        gambar_lain();// jalan no 2

        glPushMatrix();
            //mobil();
        glPopMatrix();

        glPushMatrix();//gedung kanan
            gedung(); //gedung kanan bawah
            gedung1();//gedung kanan atas
        glPopMatrix();

        glPushMatrix(); //gedung kiri
            //gedungki();
            //gedungki2();
        glPopMatrix();
    //pop matrix object
    glPopMatrix();
    //kirim ke display dan swap buffer
    glFlush();
    glutSwapBuffers();
}
//yang ini biar object porposional walaupun window di lebarin atau dikecilin
void reshape(int w, int h){
    if(h==0) h=1;
    ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);
    gluPerspective(80,ratio,1,300);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); //inisialisasi mode detail, 3 dimensi dan RGB
    glutInitWindowPosition(300,1);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("FP Grafkom");
    glutDisplayFunc(display);
    glutKeyboardFunc(gerak);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    hTexture.loadTextureInfo("C:\\Users\\Freddy\\Documents\\hahahha\\data\\st.bmp", 1);
    hTexture.SetActive(1);
    Init();
    glutMainLoop();
    return 0;
}
