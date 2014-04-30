//---------------------------------------------------------------------------
#include <math.h>
#include <tchar.h>
#include <windows.h>
#include <vfw.h>

#pragma hdrstop

#include "AVIWrite.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#define LENG 10
#define PIXELS 100
#define WIDTH 160
#define HEIGHT 120
#define LINE ((((WIDTH)*24+31)&~31)/8)
#define SIZEIMAGE (LINE*(HEIGHT))

AVISTREAMINFO si={streamtypeVIDEO,comptypeDIB,0,0,0,0,
            1,10,0,LENG,0,0,(DWORD)-1,0,{0,0,WIDTH,HEIGHT},0,0,_T("Video #1")};
BITMAPINFOHEADER bmih={sizeof(BITMAPINFOHEADER),WIDTH,HEIGHT,1,24,BI_RGB,
                                                            SIZEIMAGE,0,0,0,0};
//BYTE bBit[SIZEIMAGE];
PAVIFILE pavi;
PAVISTREAM pstm;
int line,sizeimage;

int AVIWritePrepare(int width,int height,int length, char* filename)
{
    //memset(bBit,0,SIZEIMAGE);
    //AVIFileInit();

    si.dwLength = length;

    si.rcFrame.left = 0; //{ 0,0,width,height};
    si.rcFrame.top = 0;
    si.rcFrame.right = width;
    si.rcFrame.bottom = height;

    bmih.biWidth = width;
    bmih.biHeight = height;
    line =  ((width*24+31)&~31)/8;
    sizeimage = line*height;
    bmih.biSizeImage = sizeimage; // can be zero?

    //AVIFileInit();

    if (AVIFileOpen(&pavi,filename,
                            OF_CREATE | OF_WRITE | OF_SHARE_DENY_NONE,NULL)!=0)
        return 1;
    if (AVIFileCreateStream(pavi,&pstm,&si)!=0)
        return 1;
    if (AVIStreamSetFormat(pstm,0,&bmih,sizeof(BITMAPINFOHEADER))!=0)
        return 1;
    return 0;
}

int     AVIWriteaFrame(int i,char *buffer)
{
        if( !buffer ){
                //ShowMessage("buffer is invalid");
                return 1;
        }
        if( AVIStreamWrite(pstm,i,1,buffer,sizeimage,
                                                AVIIF_KEYFRAME,NULL,NULL)!=0)
                return 1;
        return 0;
        
}


int AVIWriteFinish(void)
{
    AVIStreamRelease(pstm);
    AVIFileRelease(pavi);
    //AVIFileExit();
    return 0;
}




