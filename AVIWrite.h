//---------------------------------------------------------------------------

#ifndef AVIWriteH
#define AVIWriteH
//---------------------------------------------------------------------------
#endif

int AVIWritePrepare(int width,int height,int length, char* filename);
int     AVIWriteaFrame(int frame,char *buffer);
int AVIWriteFinish(void);

