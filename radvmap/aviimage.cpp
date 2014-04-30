//---------------------------------------------------------------------------

/*
        $Log: not supported by cvs2svn $
        Revision 1.3  2005/03/08 05:55:08  nao
        same strategy as aviimage using AVIStreamOpenFromFile instead of
        AVIFileOpen and AVIFileGetStream for suppress of FD access?


*/


#include <vcl.h>
#include <stdio.h>
#include <tchar.h>
#include <vfw.h>
#include "aviimage.h"

aviimage::aviimage()
{
	    AVIFileInit();
}

aviimage::aviimage(char* fname)
{
    wVideo=~0;
    AVIFileInit();
    AVIStreamOpenFromFile(&pstm,fname,streamtypeVIDEO,0,OF_READ,NULL);
//    AVIFileOpen(&pavi,fname,OF_READ | OF_SHARE_DENY_NONE,NULL);
//    AVIFileOpen(&pavi,fname,OF_READ ,NULL);
//    if (AVIFileInfo(pavi,&fi,sizeof(AVIFILEINFO))!=0)
//        ShowMessage("AVIFileInfo error");
//    for (dwStream=0;dwStream<fi.dwStreams;dwStream++) {
//        if (AVIFileGetStream(pavi,&ptmp,0,dwStream)!=0)
//            ShowMessage("");
//        if (AVIStreamInfo(ptmp,&si,sizeof(AVISTREAMINFO))!=0)
//            ShowMessage("");
//        switch (si.fccType) {
//            case streamtypeVIDEO:
//                if (pstm==NULL || si.wPriority<wVideo) {
//                    if (pstm!=NULL)
//                        AVIStreamRelease(pstm);
//                    pstm=ptmp;
//                    wVideo=si.wPriority;
//                }
//                continue;
//        }
//        AVIStreamRelease(ptmp);
//    }
//      above code will not function in Windows XP
//      it works in 95 and/or 98se mode only
//
//    if(AVIFileGetStream(pavi,&pstm,streamtypeVIDEO,0)!=0)
//        ShowMessage("AVIFileGetStream");

    if (pstm==NULL)
        ShowMessage("pstm NULL");
    if ((pfrm=AVIStreamGetFrameOpen(pstm,NULL))==NULL)
        ShowMessage("GetFrameOpen");
    lStart=AVIStreamStart(pstm);
    lEnd=AVIStreamLength(pstm)+lStart -1;     // oops
    if ((pbmih=(LPBITMAPINFOHEADER)AVIStreamGetFrame(pfrm,0))==NULL)
            ShowMessage("GetFrame error");
    frect.top = 0;
    frect.left = 0;
    frect.bottom = pbmih->biHeight-1;
    frect.right = pbmih->biWidth-1;


}

void aviimage::saveaframe(long fnum, TMemoryStream* out)
{
    BITMAPFILEHEADER bmfh;

    if ((pbmih=(LPBITMAPINFOHEADER)AVIStreamGetFrame(pfrm,fnum))==NULL)
            ShowMessage("GetFrame error");

    bmfh.bfType=0x4d42;
    bmfh.bfReserved1=bmfh.bfReserved2=0;
    if (pbmih->biClrUsed==0)
        switch (pbmih->biBitCount) {
            case  1:bmfh.bfOffBits=sizeof(RGBQUAD)*2;break;
            case  4:bmfh.bfOffBits=sizeof(RGBQUAD)*16;break;
            case  8:bmfh.bfOffBits=sizeof(RGBQUAD)*256;break;
            case 24:bmfh.bfOffBits=0;break;
            case 16:
            case 32:
                bmfh.bfOffBits=pbmih->biCompression==BI_RGB?0:sizeof(DWORD)*3;
        }
    else
        bmfh.bfOffBits=pbmih->biClrUsed*sizeof(RGBQUAD);
    bmfh.bfOffBits+=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
    bmfh.bfSize=bmfh.bfOffBits+(pbmih->biSizeImage==0
            ?((pbmih->biWidth*pbmih->biBitCount+31)&~31)/8*abs(pbmih->biHeight)
                                                        :pbmih->biSizeImage);
    out->Write(&bmfh,sizeof(BITMAPFILEHEADER));
    out->Write(pbmih,bmfh.bfSize-sizeof(BITMAPFILEHEADER));
    out->Seek(0,soFromBeginning);
}



//---------------------------------------------------------------------------

void aviimage::finish()
{
    if (AVIStreamGetFrameClose(pfrm)!=0)
        ShowMessage("");
    AVIStreamRelease(pstm);
    AVIFileRelease(pavi);
    AVIFileExit();
}





