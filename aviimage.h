#ifndef AVIIMAGEH
#define AVIIMAGEH

#include <vcl.h>
#include <stdio.h>
#include <tchar.h>
#include <vfw.h>


class aviimage
{
	AVIFILEINFO fi;
    AVISTREAMINFO si;
    CHAR szFile[MAX_PATH];
    DWORD dwStream;
    TRect frect;
    LONG i,lStart,lEnd;
    LPBITMAPINFOHEADER pbmih;
    PAVIFILE pavi;
    PAVISTREAM pstm,ptmp;
    PGETFRAME pfrm;
    WORD wVideo;

public:
	aviimage();
	aviimage(char* filename);
	TRect getframerect() { return frect; }
	long	getfirst() { return lStart ; }
	long	getlast() { return lEnd; }
	void saveaframe(long framenum, TMemoryStream* mem);
	void finish();
};

#endif

 