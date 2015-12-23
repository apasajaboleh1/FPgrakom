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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glScaled(3.6,1,12);
    glTranslatef(-2,-3.65,-1);
    glRotated(90,1,0,0);
    //glScaled(2.8,1.2,1);


    glBegin(GL_QUADS);
        glTexCoord2d(0.0f, 0.0f);glVertex3f(-0.5f, 0.0f, -1.1f);
        glTexCoord2d(0.0f, 5.0f);glVertex3f(-0.5f, 2.5f, -1.1f);
        glTexCoord2d(5.0f, 5.0f);glVertex3f(2.5f, 2.5f, -1.1f);
        glTexCoord2d(5.0f, 0.0f);glVertex3f(2.5f, 0.0f, -1.1f);
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
        lookat[1]=0.3;
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
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //blend warna untuk texture dan warna
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}
void gambar_jalan()
{

    if (!sample) {
    sample = glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\testok.obj");
    if (!sample) exit(0); //gagal = exit
    glmUnitize(sample);
    glmFacetNormals(sample);
    glmVertexNormals(sample,90.0,GL_TRUE);
    }
    //GLfloat mat_ambient[]={0.0f, 2.0f, 2.0f, 2.0f}; // gray
    //GLfloat mat_diffuse[]={1.0f, 1.0f, 0.0f, 0.0f};
    //GLfloat mat_specular[]={1.0f, 1.0f, 0.0f, 0.0f};
    //GLfloat mat_shininess[]={100.2f};
    //glMaterialfv(GL_FRONT, GL_AMBIENT,  mat_ambient);
    glTranslated(-3.5,-2.5,1);
    glScaled(5.1,1,1);
    glmDraw(sample, GLM_TEXTURE | GLM_SMOOTH);
}
void gambar_lain()
{

    if(!sample1)
    {
        sample1=glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\testok.obj");
        if(!sample1)exit(0);
        glmUnitize(sample1);
        glmFacetNormals(sample1);
        glmVertexNormals(sample1,90.0,GL_TRUE);

    }
    glTranslated(0,0,-2);
    glmDraw(sample1,GLM_TEXTURE|GLM_SMOOTH);

}
void mobil()
{
    if(!sample2)
    {
        sample2=glmReadOBJ("C:\\Users\\Freddy\\Documents\\hahahha\\data\\SCI_FRS_13_HD.obj");
        if(!sample2)exit(0);
        glmUnitize(sample2);
        glmFacetNormals(sample2);
        glmVertexNormals(sample2,90.0,GL_TRUE);

    }
    glmDraw(sample1,GLM_TEXTURE|GLM_SMOOTH);
}
void gedung()
{

}
void display() {
    //mode buffer warna dan 3 dimensi
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //warna latar
    glClearColor(0.8, 0.8, 0.8, 0.0);

    //inisialisasi identity
    glLoadIdentity();
    GLfloat pos[4]={1.5,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    gluLookAt(lookat[0],lookat[1],lookat[2],lookat[3],lookat[4],lookat[5],lookat[6],lookat[7],lookat[8]);
    //push matrix object
    Draw();
    glPushMatrix();

        //load object jika belum di load

        gambar_jalan();
        gambar_lain();

        glPushMatrix();
            //mobil();
        glPopMatrix();
        glPushMatrix();

        glPopMatrix();

        //jika ingin rotasi, translate, scale bisa di aplikasikan sebelum glmDraw();
        //glTranslatef(0,1,-5);
        //glScalef(2,2,2);
        //glRotatef(XRot,1,0,0);
        //glRotatef(YRot,0,1,0);
        //glRotatef(ZRot,0,0,1);
        //draw object
        glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
        glColor3ub(0,0,0);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glmDraw(sample, GLM_SMOOTH | GLM_TEXTURE|GLM_MATERIAL);
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
    glutCreateWindow("TestObject");
    glutDisplayFunc(display);
    glutKeyboardFunc(gerak);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    hTexture.loadTextureInfo("C:\\Users\\Freddy\\Documents\\hahahha\\data\\st.bmp", 1);
    hTexture.SetActive(1);
    Init(); //init
    glutMainLoop();
    return 0;
}
