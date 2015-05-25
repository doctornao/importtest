//---------------------------------------------------------------------------

/* Unit1.cpp

        correlation panel

        2002-9-18       pre-release 0.9   changed sourceframebuf,destframebuf and rframe
                                          to dynamic dllocation array for variable size buffer
                                          ex. generic AVI file Test OK
                                          Poof sizeof(sourceframebuf) [y][x] -> [y*iw+x] was easy
                                          DispFrame implementation
        2002-9-19       0.91              Poof setdestroi diffx and diffy slipped
                                          should take account into frame speed in AVI case
        2002-9-20       0.95              Split forms into 3 parts. Now can display larger images.
                                          Source and target.
                                          to do list :  each image plane dump
                                                        spatial calibration
                                                        geometric calibration ( if any )
                                                        handling ROIs = multiple object tracking
                                                        cursor coloring
        2002-9-24       0.96              dynamic allocatin for wtime,posx... for frame length > 102
                                          icon setup don't ask why :-<
                                          Popup menu dump image selection
                                          bug fix for re-selection of input file NOT ALL (memory allocation)

                                          What to do next
                                              1) Multiple Roi tracking... most important
                                                 Roi loop!?

                                                   コンテナクラス利用しよう たとえばTList?
                                                   Iterator
                                                   Roi->Add Roi 管理はリストか配列
                                                   番号と色（トラッキングの）の区別
                                                   

                                              2) Color handling or Gray translation

        2002-9-26       0.97            複数ROIのハンドリング　クロストーク？
                                        Angle 絡み
        2002-9-27       0.971           all OK   ループロジック不明確だったから
                                        all data exportの場合はデータの送出だけ

                                        後は、

                                        Calibration for Space
                                        Perspective
        2002-10-3       0.975           AVI write implement using AVIWrite.cpp Unit

        2002-10-4       0.9751          make use of separate palette
                                        and set forms appropriate for any screen size
                                        RGB->YUV translation? how to decide sampling? testing mini program
                                        for a while

        2002-10-7       0.9752          added trace mode in AVIoutput  done
                                        and frame rate was reduced to 10fs/s ( it was 30fs/s ) in AVIWrite.cpp
                                        Linear and Spiral search results display in case of others

                                        Next->Sorted results? in case of testing algs linear or spiral
                                        Tlist->sort

        2002-10-8                       now should display proper frame after playback in case of small
                                        thresh correlation coeff. variable through edit text
                                        add priority number by NumberIt function

                                        Added Go! Linear and Sequential into mini Panel
                                        Fix playback login and rename it to Fast Forward

        2002-10-9       0.98            Added Spatial Calibration using ROI rectangle
                                        Added Manual measuerment
                                        to do list      : better visual feedback
                                                          data pushover to Igor (fullpath!)
                                        

        2002-10-10      0.981           minor bug fix
                                        Data export in case of manual tracking points per frame limited to 25 by now

                                        to do lit       : implement calculated parameter? distance between a and b
                                                                                          angle between a,b and c etc.
        2002-10-11      0.985           popupmenu selection base parameter add routine finish
                                        manual mode OK including degree angle and distance
                                        implement right-click for frame advance in manual measurement mode 

        2002-10-15      0.986           fix coordinate error
                                        added visual feedback when adding parms manual mode
                                        change atan -> atan2 for general case
                                        coordinate switch at parameter calc based on OriginLeftBottom->Checked
                                        data handling over 9 points done!!

                                        to do list : sum fix in case of r-value buffer display
                                                     automatic motion analysis visual feedback
                                                     use try catch

        2002-10-16      0.987           minor bug fix .... What doubled?
                                        Display last manual measurement position for assistance
                                        
        2002-10-18      0.988           still image support for source and dest
                                        buffer consistency OK
                                        still validating...
                                        

        2002-11-01      0.9881          fix write last session where start frame is not zero

        2002-11-05      0.98812         Manual avi writeout support
                                        prohibit size changing while manual measure -> add one parm?

                                        double switching should restore frame number

        2002-11-06      1.1             from now on files are handled by CVS

        

	 $Id: Unit1.cpp 47 2011-12-15 10:35:51Z nao $

        $Log: not supported by cvs2svn $
        Revision 1.12  2011/03/31 03:43:36  nao
        fix handling in 64bit systems
        Windows 7でIgor Excelともに動作　つまり　DDEも使える、OLEが使えるのは
        当然だろうけど。

        Revision 1.11  2008/03/14 06:47:53  nao
        fix interpretation of ROI from inclusize -> exclusive

        Revision 1.9  2008/01/07 03:54:38  nao
        fix so many old Exec

        Revision 1.8  2007/03/05 07:35:26  nao
        Bug fix in interpolate swap X axis handling
        & selectable ROI # display

        Revision 1.7  2005/04/22 05:12:59  nao
        gethostname and before calling that winsock init (poof)

        Revision 1.6  2005/04/21 07:17:12  nao
        time measurement for comparison using QueryPerformanceCounter
        and stats check box

        Revision 1.5  2005/03/30 05:33:52  nao
        implement load & save roisets

        Revision 1.4  2005/03/25 00:41:32  nao
        display ROI coord for test ( just uncomment )

        Revision 1.3  2005/03/24 05:31:24  nao
        allow numerical rect cord input through form7
        for test trace engine

        Revision 1.2  2005/03/08 04:54:18  nao
        caring windows xp copatibility in aviimage

        Revision 1.1.1.1  2003/12/09 04:38:26  nao
        new vmap w/o aviiimage pascal component

        Revision 1.22  2003/08/20 06:42:01  nao
        change メモ to Memo:
        for English presentation (IEA-TLM Sep 2003 in England)

        Revision 1.21  2003/08/01 06:20:55  nao
        HE can be done while playback
        fixed move to bug by displayed->true

        Revision 1.20  2003/08/01 05:02:05  nao
        variable dlimit using edit11
        no direction yet

        Revision 1.19  2003/07/31 06:24:06  nao
        fixing linear mode
        should fix delta limit for suitable value?

        Revision 1.18  2003/07/31 06:10:31  nao
        implementing linear mode both for ROI and Search
        in case of fringe expansion

        Revision 1.17  2003/07/22 02:30:47  nao
        colorize output avi tracer

        Revision 1.16  2003/07/21 02:34:28  nao
        set dispimage form uppermost level by Fomr2->Show()

        Revision 1.15  2003/07/18 04:11:34  nao
        bug fix excel handling
          range change -> one excel with another book
          open file -> another excel activation

          also init col when doitbyexcel

        Revision 1.14  2003/07/17 06:52:31  nao
        excel multiple graph handling bug fixed

        Revision 1.13  2003/07/16 08:47:20  nao
        variable step angle default is 0.5 unchanged

        Revision 1.12  2003/07/15 04:50:54  nao
        added MOVE button from Source to Dest

        Revision 1.11  2003/05/21 04:35:04  nao
        Implement histrogram equlization in case of Shimadzu native file
        can extend to other modes

        Revision 1.10  2003/05/19 02:06:32  nao
        Igor path set to default c:\program files\wavemetrics\igor pro folder\igor.exe
        Fix manual data exporting bug
        Variant excel to global

        Revision 1.9  2003/04/08 01:44:14  nao
        set default ext to "avi" in savedialog4 to prevent AVIOpenfile error

        Revision 1.8  2002/12/10 06:24:32  nao
        << and >> implemented and bug fix

        Revision 1.7  2002/11/18 06:41:16  nao
        set x-axis spacing to 5

        Revision 1.6  2002/11/18 05:45:45  nao
        エクセルでのグラフ表示OK

        Revision 1.5  2002/11/15 08:14:36  nao
        working excel graph ...

        Revision 1.4  2002/11/15 07:52:26  nao
        writing graph link in case of excel

        Revision 1.3  2002/11/15 07:44:31  nao
        adding excel handling just before graph draw

        Revision 1.2  2002/11/06 06:35:08  nao
        CVS introduced and keyword

        
*/



#include <vcl.h>

#pragma hdrstop
#include <jpeg.hpp>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"

#include <shellapi.h>
#include <fstream.h>
#include <math.h>
#include <memory>
#include <vector>
#include <algorithm>
#include <winsock2.h>

#include "aviimage.h"
#include "AVIWrite.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "AVIImage"
#pragma resource "*.dfm"

#define SRC 0
#define DEST 1
#define WSP(s) &(WideString(s))

using namespace std;

aviimage* work;

String  sfilename,dfilename;

Variant excel;

char    *charpos;
char    *stillbufs;
char    *stillbufd;


int     parmpoints;
int     newset=true;
int     parms=0;
int     still = false;
int     still2 = false;
int     canexcel = false;
int     horiz,vert;

int     colortable[] = { clRed,clNavy,clGreen,clBlack,clGray,clPurple,clNavy };

double  *ddset[50];

int     manual = false;
int     doubled = false;

struct aparm {
        char name[10];
};


struct apoint {
        int     x,y;
};

struct aframe {
        int     framenumber;
        TList* points;
};

double  spacefactor = 0.0;

int     col = 1;
struct rois {
        int     startx,starty;
        int     endx,endy;
        int     sizex,sizey;
        int     oldx,oldy;
        double  oldangle;
        double  *wtime,*posx,*posy,*cposx,*cposy,*angle;
        int     datacount;
};

struct resdata {
        int     posx,posy;
        double  corr;
};


TList* roiset;
TList* respointset;
TList* frames;
TList* currentpset;
TList* parmset;

int     igor;

int     laststart;
int     lastend;        // for restore last session
int     manualdata = false;
int     targetroi;
int     avimode = false;
int     other = false;

int     iw,ih;  // image width and height
int     endframe=102;

int     offf;
TImage* whichimage;
TImage* now;

//double wtime[102],posx[102],posy[102],cposx[102],cposy[102],angle[102];
double  *wtime,*posx,*posy,*cposx,*cposy,*angle;

//int     datacount = 0;

int     shiftval = 0;
int     nottarget = 1;
int     dlimit = 400;
int     flip = 1;
int     oldoldx=0,oldoldy=0;
double  oldangle = 0.0;

double  initangle = 0.0;
TImage *currbit;
int     writelength;
double  corrthresh = 0.85;


FILE    *refp;

//Word    sourceframebuf[260][312];
//Word    destframebuf[260][312];
//Word    rframe[260][312];

Word *sourceframebuf;
Word *destframebuf;
Word *rframe;
Byte *bsourceframebuf;
Byte *bdestframebuf;
Byte *brframe;

Word    *roi;
Word    *dest;
Word    *rdest;
int     fselected = 0;
//int     dx[100000],dy[100000];        260*312*4 必要　162240*2=324480 -> 312*312*4
int     dx[389378],dy[389378];
int     made = false;

//double   results[260][312];
double  *results;       //
//double  resarray[260][312];


double  roiave;
double  destave;
double  rdestave;
double  frameinterval=1.0e-3;           // 1kfps default

TPoint FClickPoint,FPrevPoint;

int     RoiStartx,RoiStarty,RoiEndx,RoiEndy;
int     RoiSizeX,RoiSizeY;

int     destframe = 0;
int     sourceframe = 0;
int     displayed = 0;
int     sdisplayed = 0;

LARGE_INTEGER   timerFrequency;

double  ox,oy;
double anglestep = 0.1;

int     spiral = true;

int     linearmode = false;

        Longint mymax,min;

struct dat_header {
        Word   year;
        Word   month;
        Word   day_of_the_week;
        Word   day;
        Word    hours;
        Word    minutes;
        Word    seconds;
        Word    millisecs;
        LongWord   dversion;
        LongWord        fill;
        char    memo[260];
        LongWord    playspeed;
        LongWord    unknown;
        LongWord    unknown2;
        LongWord    GSgain;
        LongWord    GSoffset;
        LongWord    unknown3;
        LongWord    cofreq;
        LongWord    pstandby;
        LongWord    u1;
        LongWord    u2;
        LongWord    recmode;
        LongWord    recspeed;
        LongWord    recdisplaynum;
        LongWord    trigpol;
        LongWord    trigdelay;
        LongWord    trigpoint;
        LongWord    progspeed;
        LongWord    progpoint;
        LongWord    u4;
        LongWord    u5;
        LongWord    u6;
        LongWord    illstop;
        LongWord    u7;
        LongWord    u8;
        LongWord    u9;
        LongWord    cofreq2;
        LongWord    pstandby2;
        LongWord    f1;
        LongWord    f2;

} hd;

char *recmodestr[5]={ "Internal","external","program","r-external","r-program"};
char *recspeedstr[15] = {"1μs","2μs", "5μs","10μs","20μs","50μs","100μs","200μs","500μs","1ms","2ms",
"5ms","10ms","20ms","33ms"};
double recspeed[]={1.0e-6,2.0e-6,5.0e-6,10e-6,20e-6,50e-6,100e-6,200e-6,500e-6,1e-3,2e-3,5e-3,10e-3,20e-3,33e-3};

unsigned        freq[1024];
unsigned        acc[1024];
int	playbackdelay;


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  ::DragAcceptFiles(Handle, true);
  Memo1->Lines->Clear();
  roiset = new TList();
  respointset = new TList();
  QueryPerformanceFrequency(&timerFrequency);

  WORD wVersionRequested;
WSADATA wsaData;
int err;
 
wVersionRequested = MAKEWORD( 2, 2 );
 
err = WSAStartup( wVersionRequested, &wsaData );
if ( err != 0 ) {
    /* Tell the user that we could not find a usable */
    /* WinSock DLL.                                  */
    ShowMessage("Can't init Winsock 2");
}
 
 	FilterWeight->Cells[0][0] = "-1";
	FilterWeight->Cells[0][1] = "-1";
	FilterWeight->Cells[0][2] = "-1";
	FilterWeight->Cells[1][0] = "-1";
	FilterWeight->Cells[1][1] = "8";
	FilterWeight->Cells[1][2] = "-1";
	FilterWeight->Cells[2][0] = "-1";
	FilterWeight->Cells[2][1] = "-1";
	FilterWeight->Cells[2][2] = "-1";

  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    ::DragAcceptFiles(Handle, false);
    delete roiset;
    
}
//---------------------------------------------------------------------------

void __fastcall getfreq(FILE *fp)
{

        unsigned short    linebuf[312];   // this is a line buffer
        int     i,j,k;

        for( i = 0 ; i < 1024 ; i++ )
                freq[i] = 0;

        for( i = 0; i < 103 ; i++ ){    // for all frames
                for( j = 0 ; j < 260 ; j++ ){ // for all lines
                        fread(linebuf,sizeof(linebuf),1,fp);
                        for( k = 0 ; k < 312 ; k++ ){
                                if( shiftval < 0 )
                                        linebuf[k] >>= (-shiftval);
                                else
                                        linebuf[k] <<= shiftval;


                                if( linebuf[k] > 1023 ){
                                        ShowMessage("error "+AnsiString(k)+" "+AnsiString(linebuf[k]));
                                        return;
                                }
                                freq[linebuf[k]]++;
                        }
                }
        }


}

void __fastcall TForm1::disprois(void)
{
        TImage* t;
        TRect   r;
        struct rois *p;

		if( other )
                t = Form2->Image1;
        else
                t = Image1;

        DispFrame(StrToInt(Edit1->Text));

        Form2->Canvas->Brush->Color = clRed;

        t->Canvas->Brush->Color = clRed;
        t->Canvas->Brush->Style = bsSolid;
        t->Canvas->Pen->Mode = pmCopy;    //描画時に色を反転するように指定
        t->Canvas->Pen->Color = clBlue;     //青色を指定

        //t->Canvas->Brush-> = pmCopy;

        for( int i = 0 ; i < roiset->Count ; i++ ){
                p = (rois *)roiset->Items[i];
                t->Canvas->FrameRect(TRect(p->startx,p->starty,p->endx,p->endy));
                if( CheckBox13->Checked )
                        t->Canvas->TextOutA(p->endx,p->starty-5,AnsiString(i));
        }
}



                


void __fastcall revertit(Word *frame)
{
        Word save;

        //ShowMessage("revertit called");

    if( flip ) {
        for( int lines = 0 ; lines < ih ; lines++ ){
                for( int pos = 0 ; pos < iw/2 ; pos++ ){
                        save = frame[lines*iw+pos];        // first save
                        frame[lines*iw+pos] = frame[lines*iw+311-pos];
                        frame[lines*iw+311-pos] = save;
                }
        }
    }
    else {

        for( int lines = 0 ; lines < ih/2 ; lines++ ){
                for( int pos = 0 ; pos < iw ; pos++ ){
                        save = frame[lines*iw+pos];        // first save
                        frame[lines*iw+pos] = frame[(259-lines)*iw+pos];
                        frame[(259-lines)*iw+pos] = save;
                }
        }
    }
}

void __fastcall TForm1::DeleteRoisIfany()
{
        struct rois *q;

        for( int i = 0 ; i < roiset->Count ; i++ ){
                q = (rois *)roiset->Items[i];
                free(q->wtime);
                free(q->posx);
                free(q->posy);
                free(q->cposx);
                free(q->cposy);
                free(q->angle);
                //roiset->Delete(targetroi);
                delete q;
        }
        //disprois();
        Edit7->Text = AnsiString(0);
        Form4->Edit7->Text = Edit7->Text;
        
        roiset->Clear();
        

}

#ifdef _DELPHI_STRING_UNICODE
void __fastcall TForm1::DecodeFile(wchar_t *filename)
#else
void __fastcall TForm1::DecodeFile(char *filename)
#endif
{
        int     i,maxi,mini;

        FILE    *fp;
        char    obuf[100];
        TRect   f;

        Memo1->Lines->Clear();
		RadioButton2->Checked = true;
		RadioButton1->Checked = false;
        spacefactor = 0.0;
        manual = false;
        still = false;
		still2 = false;

#ifdef _DELPHI_STRING_UNICODE
		char buf[200];
				wcstombs(buf,Edit10->Text.c_str(),200);
				anglestep = atof(buf);
#else

		anglestep = atof((const char *)Edit10->Text.c_str());
#endif
        
        // at first graph program availability checkedVariant

        try {
                        excel = CreateOleObject("Excel.Application");

		}
        catch ( EOleSysError& ){
                ShowMessage("Excelはありませんね？");
                excel = NULL;
        }


        if( !VarIsEmpty(excel) ){
                RadioButton3->Visible = true;
                canexcel = true;

        }


        prepareigor();  // igor = true or false

        if( igor ){     // igor 優先
                RadioButton4->Checked = true;
        }

        //ShowMessage(AnsiString(filename));
#ifdef _DELPHI_STRING_UNICODE
		if( wcsstr(filename,L".Avi") || wcsstr(filename,L".AVI") || wcsstr(filename,L".avi")){
#else
		if( strstr((const char *)filename,".Avi") || strstr((const char *)filename,".AVI") || strstr((const char *)filename,".avi")){
#endif
				avimode = true;
				Label11->Caption = filename;

				Memo1->Lines->Add("Avi file: no header");
				//AVIImage1->FileName = filename;
#ifdef _DELPHI_STRING_UNICODE
		char buf[200];
				wcstombs(buf,filename,200);
				work = new aviimage(buf);
#else
				work = new aviimage((char *)filename);
#endif
				//f = AVIImage1->Frame;
				f = work->getframerect();
                iw = f.Width();
				ih = f.Height();
				Memo1->Lines->Add("Avi file: "+AnsiString(iw)+"x"+AnsiString(ih));
                //ShowMessage(AnsiString(iw*ih));
                //Memo1->Lines->Add("width: "+AnsiString(iw)+"height: "+AnsiString(ih));
				if( iw > 312 || ih > 260 || avimode ){
                        int offset;

                        other = true;
                        Form2->Width = iw + 40;
                        Form2->Height = ih + 50;

                        Form2->Visible = true;
                        //Form2->Image1->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit
                        Form3->Width = iw + 40;
                        Form3->Height = ih + 50;
                        //Form3->Image1->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit

                        offset = Screen->Width - Form2->Width - Form3->Width;

                        if( offset > 0 ) {
                                Form2->Left = offset/3;
                                Form3->Left = Form2->Left + Form2->Width + offset/3;
                                Form4->Left = Form2->Left;        // was 100
                        }
                        else {
                                Form2->Left = 0;
                                Form3->Left = Form2->Width;
                                Form4->Left = Form2->Left;        // was 100
                        }

                        offset = Screen->Height - Form2->Height - Form4->Height;
                        if( offset > 0 ) {
                                Form2->Top = offset/3;
                                Form3->Top = Form2->Top;
                                Form4->Top = Form2->Top + Form2->Height + offset/3;

                        }
                        else {
                                Form2->Top = 0;
                                Form3->Top = Form2->Top;
                                Form4->Top = Form2->Height;
                        }


                        Form3->Visible = true;
                        Form4->Visible = true;

                        // you should decide each form's position here based on Screen->Width,Screen->Height

                 }
                else {
                        other = false;

                        Form2->Visible = false;

                        Form3->Visible = false;
                }


                bsourceframebuf = (Byte *)malloc(iw*ih);
                if( !bsourceframebuf ){
                        ShowMessage("not enough core for bsource frame buffer");
                        exit(1);
                }

                bdestframebuf = (Byte *)malloc(iw*ih);
                if( !bdestframebuf ){
                        ShowMessage("not enough core for source frame buffer");
                        exit(1);
                }

                brframe = (Byte *)malloc(iw*ih);
                if( !brframe ){
                        ShowMessage("not enough core for source frame buffer");
                        exit(1);
                }

                endframe = work->getlast();//AVIImage1->Length;

                results = (double *)malloc(iw*ih*sizeof(double));
                //ShowMessage("core for results buffer allocated");

                if( !results ){
                        ShowMessage("not enough core for results buffer");
                        exit(1);
                }





        }
        else {  // shimadzu data file size is 312X260

//                Word *soruceframebuf;
//Word *destframebuf;
//Word *rframe;
                avimode = false;
                other = false;
                endframe = 102;
                iw = 312;
                ih = 260;
                offf = 3;
                Form2->Visible = false;
                Form3->Visible = false;
                Form4->Visible = false;

                if( !sourceframebuf ){
                        sourceframebuf = (Word *)malloc(312*260*2);
                        if( !sourceframebuf ){
                                ShowMessage("not enough core for source frame buffer");
                                exit(1);
                        }
                }

                if( !destframebuf ){
                        destframebuf = (Word *)malloc(312*260*2);
                        if( !destframebuf ){
                                ShowMessage("not enough core for source frame buffer");
                                exit(1);
                        }
                }

                if(!rframe){
                        rframe = (Word *)malloc(312*260*2);
                        if( !rframe ){
                                ShowMessage("not enough core for source frame buffer");
                                exit(1);
                        }
                }

                if(!results){
                        results = (double *)malloc(iw*ih*sizeof(double));
                        //ShowMessage("core for results buffer allocated");

                        if( !results ){
                                ShowMessage("not enough core for results buffer");
                                exit(1);
                        }
                }

#ifdef _DELPHI_STRING_UNICODE
		char buf[200];
				wcstombs(buf,filename,200);
				fp = fopen(buf,"rb");

#else
		fp = fopen(filename,"rb");
#endif


                if( !fp ){
						Memo1->Lines->Add("file not found");
                }

                //sprintf(obuf,"size of int is %d",sizeof(int));
                //Memo1->Lines->Add(obuf);

				fread(&hd,sizeof(hd),1,fp);
                sprintf(obuf,"Filename: %s\n",filename);
                Label11->Caption = filename;

                Memo1->Lines->Add(obuf);
                sprintf(obuf,"%d %d/%d %d:%d:%d\n",hd.year,hd.month,hd.day,hd.hours,hd.minutes,hd.seconds);
                Memo1->Lines->Add(obuf);
                sprintf(obuf,"Memo: ");
                strcat(obuf,hd.memo);
                Memo1->Lines->Add(obuf);

                sprintf(obuf,"Recording mode [%s]",recmodestr[hd.recmode]);
                Memo1->Lines->Add(obuf);

                sprintf(obuf,"Recording speed [%s]",recspeedstr[hd.recspeed]);
                Memo1->Lines->Add(obuf);

                frameinterval = recspeed[hd.recspeed];
                Edit6->Text = AnsiString(frameinterval);

                sprintf(obuf,"frame interval is %g sec",frameinterval);
                Memo1->Lines->Add(obuf);

                getfreq(fp);
//        fclose(fp); polygon
                refp = fp;

                mymax = 0;

				for( i = 0 ; i < 1024 ; i++ ){
						if( freq[i] > mymax ) {
                                mymax = freq[i];
								maxi = i;
                        }
                }

                sprintf(obuf,"maximum freq. is %d at %d\n",mymax,maxi);
                Memo1->Lines->Add(obuf);

                PaintBox2->Canvas->Pen->Width = 1;
                TRect bound;

                bound = PaintBox2->BoundsRect;

                Canvas->MoveTo(bound.left-1,bound.top-1);
                Canvas->LineTo(bound.left-1,bound.bottom+1);
                Canvas->LineTo(bound.right+1,bound.bottom+1);
                Canvas->LineTo(bound.right+1,bound.top-1);
                Canvas->LineTo(bound.left-1,bound.top-1);
//        Canvas->FrameRect(bound);

                Canvas->MoveTo(bound.left+100,bound.bottom+1);  // draw 8 bit boundary
                Canvas->LineTo(bound.left+100,bound.top-1);

                PaintBox2->Canvas->Pen->Color = clRed;
                PaintBox2->Canvas->Pen->Mode = pmCopy;
                Label5->Caption = "Histogram";
                Label7->Caption = "1024";
                Label8->Caption = "Max";

                for( i = 0 ; i < 1024 ; i += 2 ){
                        PaintBox2->Canvas->MoveTo(400*i/1024+2,200);
                        PaintBox2->Canvas->LineTo(400*i/1024+2,200-200*freq[i]/mymax);
                }
                //Canvas->FrameRect(bound);
                PaintBox2->Canvas->Pen->Color = clBlack;
        }
        //Memo1->Lines->Add("width: "+AnsiString(iw)+"height: "+AnsiString(ih));

        DeleteRoisIfany();
		DispFrame(0);
		Button24->Enabled = true;
		RadioGroup5->Enabled = true;
		//RadioGroup5->ItemIndex = 1;
		RadioButton6->Checked = true;
		Divisor->Text = "8";
		Shift->Text = "128";
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{

   	if(OpenDialog1->Execute()){
				DecodeFile(OpenDialog1->FileName.c_str());
				fselected++;
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::WMDropFiles(TMessage &message)
{

	HANDLE	drop ;
	char	buffer[2048] ;

	drop = (HANDLE)message.WParam ;
	::DragQueryFile((HDROP__ *) drop, 0, &buffer[0], 2048 ) ;
	::DragFinish( (HDROP__ *) drop ) ;
#ifdef _DELPHI_STRING_UNICODE
	DecodeFile((wchar_t *)buffer);
#else
	DecodeFile((char *)buffer);
#endif
        fselected++;


}



void __fastcall TForm1::ReDraw(TObject *Sender)
{
//        int     i;

//        if(mymax == 0 )
//                return;

//         PaintBox2->Canvas->Pen->Width = 1;
//         PaintBox2->Canvas->Pen->Color = clRed;


//        for( i = 0 ; i < 1024 ; i += 2 ){
//                PaintBox2->Canvas->MoveTo(i/2,199);
//                PaintBox2->Canvas->LineTo(i/2,199-200*freq[i]/mymax);
//        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DispFrame(int lframenum)
{

		int     henkan[1024],hist[1024],ruikei,jc;
		int		hsize,vsize;
		unsigned	long	avihenkan[256],avihist[256],aviruikei,avijc;

		Word *pp = (Word *)sourceframebuf;
		Word *alt = (Word *)sourceframebuf;
		Byte *bpp = bsourceframebuf;
		BYTE modval;

		TMemoryStream* temp = new TMemoryStream();
        TImage* targeti;
		Graphics::TBitmap *Bitmap = new Graphics::TBitmap();

		if( avimode ){
				 other = true;
                //AVIImage1->SetPosition(lframenum,false);
				//AVIImage1->SaveToStream(temp);
				work->saveaframe(lframenum,temp);
				temp->Position = 0;


        }
		else if( still ){
				Bitmap->LoadFromFile(sfilename);
 //               iw = Bitmap->Width;
 //               ih = Bitmap->Height;
 //
 //               if( iw > 312 || ih > 260 )
 //                       other = true;

		}
		else {
				other = false;
				rewind(refp);

				fseek(refp,sizeof(hd)+312*260*2*lframenum,SEEK_SET);

		//fread(sourceframebuf, sizeof(sourceframebuf),1,refp);
				fread(sourceframebuf,312*260*2,1,refp);
        // image read
				revertit(sourceframebuf);
		}

		if( other ){
				targeti = Form2->Image1;
				LargeSource1->Enabled = true;
		}
		else  {
				targeti = Image1;
				SmallSource1->Enabled = true;
		}

		targeti->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit
        targeti->Width = iw;
        targeti->Picture->Bitmap->Width = iw;
        targeti->Height=ih;
        targeti->Picture->Bitmap->Height = ih;

		if( doubled ){
                targeti->Width = iw*2;
                targeti->Picture->Bitmap->Width = iw*2;
                targeti->Height=ih*2;
                targeti->Picture->Bitmap->Height = ih*2;
        }

        //targeti->Canvas->Rectangle(0,0,targeti->Width,targeti->Height);

        if( avimode ){
                //targeti->Picture->Bitmap->LoadFromStream(temp);
                Bitmap->LoadFromStream(temp);
                int     depth = Bitmap->PixelFormat;

				 switch (depth ) {
						case pf8bit : offf = 1;
										break;
						case pf16bit : offf = 2;
                                        break;
                        case pf24bit : offf = 3;
										break;
                        case pf32bit : offf = 4;
                                        break;
                 }
				if(CheckBox10->Checked){ // we should do this in case of AVI too from now on
					for( int count = 0 ; count < 256 ; count++ ){
						avihenkan[count] = 0;
						avihist[count] = 0;
					}
				}

 /*
					for( int row = 0 ; row < targeti->Height; row++ ){
						for( int col = 0 ; col < targeti->Width ; col++ ){
								WORD val =  *alt++;
								hist[val]++;
						}
					}

					ruikei = 0;
					jc = 0;

					for( int c = 0 ; c < 1024 ; c++ ){
						ruikei += hist[c];
						jc += ruikei/80;        // 312*260/1024 = 79.2
						ruikei %= 80;
						henkan[c]=jc;
					}
				alt = pp;       // re-init
		  }
 */

				targeti->Canvas->CopyRect(Rect(0,0,targeti->Width-1,targeti->Height-1),Bitmap->Canvas,Rect(0,0,Bitmap->Width-1,Bitmap->Height-1));
				for( int row = 0 ; row < ih; row++ ){
				//      BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
					BYTE *scanPtr = (BYTE *)Bitmap->ScanLine[row];
					for( int col = 0 ; col < iw ; col++ ){
						BYTE* tempPtr = scanPtr+col*offf;    // 8bit avi
						//BYTE val = (frame[312*(260-row)+col]&0xff);
						*bpp++ = tempPtr[0];
						avihist[tempPtr[0]]++;
					}

				}
				if(CheckBox10->Checked){

					aviruikei = 0;
					avijc = 0;
					//hsize = targeti->Width;
					//vsize = targeti->Height;
					unsigned	long fact = ih*iw/256;

					for( int c = 0 ; c < 256 ; c++ ){
						aviruikei += avihist[c];
						avijc += aviruikei/fact;        // 312*260/1024 = 79.2  512
						aviruikei %= fact;
						if(avijc > 255 )
							avijc = 255;
						avihenkan[c]=avijc;
					}

					for( int row = 0 ; row < ih; row++ ){
					  BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
						//TE *scanPtr = (BYTE *)Bitmap->ScanLine[row];
						for( int col = 0 ; col < iw ; col++ ){
							BYTE* tempPtr = scanPtr+col*3;    // 8bit avi
							//BYTE val = (frame[312*(260-row)+col]&0xff);
						modval = (BYTE)avihenkan[tempPtr[0]];
						//tempPtr[0] = modval;
						tempPtr[0] = modval;
						tempPtr[1] = modval;
						tempPtr[2] = modval;
//                   	targeti->Refresh();

						}

					}
//					targeti->Refresh();
//					targeti->Invalidate();



				}


		}
        else if( still ) {

 //                          Bitmap->LoadFromStream(temp);
                int     depth = Bitmap->PixelFormat;

				 switch (depth ) {
                        case pf8bit : offf = 1;
                                        break;
                        case pf16bit : offf = 2;
                                        break;
                        case pf24bit : offf = 3;
                                        break;
						case pf32bit : offf = 4;
                                        break;
                 }

                 //ShowMessage("offf is "+AnsiString(offf));

                targeti->Canvas->CopyRect(Rect(0,0,targeti->Width-1,targeti->Height-1),Bitmap->Canvas,Rect(0,0,Bitmap->Width-1,Bitmap->Height-1));
				for( int row = 0 ; row < ih; row++ ){
                //      BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
					BYTE *scanPtr = (BYTE *)Bitmap->ScanLine[row];
					for( int col = 0 ; col < iw ; col++ ){
                        BYTE* tempPtr = scanPtr+col*offf;    // 8bit avi
						//BYTE val = (frame[312*(260-row)+col]&0xff);
						*bpp++ = tempPtr[0];

					}

                }

        }
		else {  // incase of shimadze raw format
		   if(CheckBox10->Checked){
                for( int count = 0 ; count < 1024 ; count++ ){
						henkan[count] = 0;
						hist[count] = 0;
				}


				for( int row = 0 ; row < targeti->Height; row++ ){
						for( int col = 0 ; col < targeti->Width ; col++ ){
								WORD val =  *alt++;
                                hist[val]++;
                        }
				}

                ruikei = 0;
                jc = 0;

                for( int c = 0 ; c < 1024 ; c++ ){
						ruikei += hist[c];
                        jc += ruikei/80;        // 312*260/1024 = 79.2
                        ruikei %= 80;
                        henkan[c]=jc;
                }
                alt = pp;       // re-init
		  }

                for( int row = 0 ; row < targeti->Height; row++ ){
                        BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
                        for( int col = 0 ; col < targeti->Width ; col++ ){
                                BYTE* tempPtr = scanPtr+col*3;
								//BYTE val = (frame[312*(260-row)+col]&0xff);
                                BYTE val =  *pp++&0xff;
                                WORD wval = *alt++;

                                if( shiftval < 0 )
                                        val >>= (-shiftval);
								else
                                        val <<= shiftval;

                                if( CheckBox10->Checked ){
                                        val = henkan[wval]/4;

								}
								tempPtr[0] = val;
								tempPtr[1] = val;
								tempPtr[2] = val;
						}
                }
		}

		targeti->Refresh();

        Edit1->Text = IntToStr(lframenum);
		Form4->Edit1->Text = Edit1->Text;
		delete temp;
		delete Bitmap;
}

void __fastcall TForm1::dumppoints(void)
{
		struct aframe *tempf;
		TList *temp;

		for( int i = 0 ; i < frames->Count ; i++ ){
				tempf = (struct aframe *)frames->Items[i];
				temp = tempf->points;
				Memo1->Lines->Add("frame "+AnsiString(tempf->framenumber));
				for( int k = 0 ; k < temp->Count ; k ++ ){
						struct apoint *t = (struct apoint *)temp->Items[k];
						Memo1->Lines->Add(" point "+AnsiString(k)+" x "+AnsiString(t->x)+" y "+AnsiString(t->y));
				}
		}



}


void __fastcall TForm1::DispFrame2(int lframenum)
{
		Word *pp = (Word *)destframebuf;
        Byte *bpp = bdestframebuf;
        TImage* targeti;
        Graphics::TBitmap *Bitmap = new Graphics::TBitmap();


        TMemoryStream* temp = new TMemoryStream();

        if( avimode ){

                //AVIImage1->SetPosition(lframenum,false);
                //AVIImage1->SaveToStream(temp);
                work->saveaframe(lframenum,temp);
                temp->Position = 0;


        }
        else if( still2 ){
                Bitmap->LoadFromFile(dfilename);

                if( Bitmap->Width != iw || Bitmap->Height != ih ){
                        ShowMessage("Size error");
                        return;
                }

        }

        else {
                rewind(refp);

                fseek(refp,sizeof(hd)+312*260*2*lframenum,SEEK_SET);

        //fread(sourceframebuf, sizeof(sourceframebuf),1,refp);
                fread(destframebuf,312*260*2,1,refp);
        // image read
                revertit(destframebuf);
        }

        if( other ){
                targeti = Form3->Image1;
                LargeDest1->Enabled = true;
        }
        else {
                targeti = Image2;
                SmallDest1->Enabled = true;
        }



        targeti->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit
        targeti->Width = iw;
        targeti->Picture->Bitmap->Width = iw;
        targeti->Height=ih;
        targeti->Picture->Bitmap->Height = ih;

        targeti->Canvas->Rectangle(0,0,targeti->Width,targeti->Height);

        if( avimode ){
                targeti->Picture->Bitmap->LoadFromStream(temp);
                for( int row = 0 ; row < targeti->Height; row++ ){
                BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
                for( int col = 0 ; col < targeti->Width ; col++ ){
                        BYTE* tempPtr = scanPtr+col*offf;
                        //BYTE val = (frame[312*(260-row)+col]&0xff);
                        *bpp++ = tempPtr[0];
                }

                }
        }
        else if( still ) {
                        int     depth = Bitmap->PixelFormat;

                 switch (depth ) {
                        case pf8bit : offf = 1;
                                        break;
                        case pf16bit : offf = 2;
                                        break;
                        case pf24bit : offf = 3;
                                        break;
                        case pf32bit : offf = 4;
                                        break;
                 }


              targeti->Canvas->CopyRect(Rect(0,0,targeti->Width-1,targeti->Height-1),Bitmap->Canvas,Rect(0,0,Bitmap->Width-1,Bitmap->Height-1));

                        //targeti->Picture->Bitmap->LoadFromStream(temp);
                for( int row = 0 ; row < targeti->Height; row++ ){
                //BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
                BYTE *scanPtr = (BYTE *)Bitmap->ScanLine[row];

                for( int col = 0 ; col < targeti->Width ; col++ ){
                        BYTE* tempPtr = scanPtr+col*offf;
                        //BYTE val = (frame[312*(260-row)+col]&0xff);
                        *bpp++ = tempPtr[0];
                }

                }


        }
        else {
        for( int row = 0 ; row < targeti->Height; row++ ){
                BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
                for( int col = 0 ; col < targeti->Width ; col++ ){
                        BYTE* tempPtr = scanPtr+col*3;
                        //BYTE val = (frame[312*(260-row)+col]&0xff);
                        BYTE val =  *pp++&0xff;

                        if( shiftval < 0 )
                                val >>= (-shiftval);
                        else
                                val <<= shiftval;

                        tempPtr[0] = val;
                        tempPtr[1] = val;
                        tempPtr[2] = val;
                }
        }
        }


        Edit4->Text = IntToStr(lframenum);
        Button3->Enabled = true;
        Button9->Enabled = true;
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        int     lastindex;

        if(!fselected)
                return;

/*        if(!sdisplayed) {
                sourceframe = 0;
                DispFrame(sourceframe);
                sdisplayed = 1;
        }
        else {
*/

                if( manual ){
                        if( sourceframe != destframe ){
                                struct aframe* currentframe = new struct aframe;
                                currentpset = new TList();
                                currentframe->framenumber = sourceframe+1;
                                currentframe->points = currentpset;
                                frames->Add(currentframe);
                                lastindex = frames->Count;
                        }
                        else {
                                manual = false;
                                Manual->Caption = "Manual";
                                Form4->Button2->Caption = "Manual";
                                dumppoints();
                                manualdata = true;
                                struct aframe *ttt = (struct aframe *)frames->Items[0];

                                parmpoints = ttt->points->Count;

                                if( igor || !VarIsEmpty(excel) )
                                        Button14->Visible = true;
                                AddParms->Visible = true;
                                tp->Visible = true;
                                DelParms->Visible = true;
                                lastindex = 0;


                        }
                }
                ++sourceframe;
                if( sourceframe > endframe )
                        sourceframe = endframe;
                DispFrame(sourceframe);
                if(manual && lastindex > 1){     // display old points
                        TImage* c;
                        int     cback;

                        if(other)
                                c = Form2->Image1;
                        else
                                c = Image1;

                        cback = c->Canvas->Brush->Color;


                        c->Canvas->Brush->Color = clYellow;
                        //c->Canvas->Brush->Mode = pmCopy;  // ??

                        struct apoint *pp;
                        struct aframe *cc;

                        cc = (struct aframe *)frames->Items[lastindex-2];
                        for( int i = 0 ; i < cc->points->Count ; i++ ){
                                pp = (struct apoint *)cc->points->Items[i];
                                c->Canvas->TextOutA(pp->x,pp->y,AnsiString(i+1));
                        }
                        c->Canvas->Brush->Color = cback;

                }


//        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
		long    k;

        if(!fselected)
                return;
        if( !avimode )
                rewind(refp);
        sdisplayed = 1;
        Image1->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit
        Image1->Picture->Bitmap->Width = Image1->Width;
        Image1->Picture->Bitmap->Height = Image1->Height;


        //Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
//        fff = sourceframe;
		if( avimode )
			Timer1->Interval = 50;
		else
			Timer1->Interval = 100;
			
        Timer1->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        if( SaveDialog1->Execute()) {
                whichimage->Picture->Bitmap->SaveToFile(SaveDialog1->FileName);

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

        shiftval++;

        Edit2->Text = IntToStr(shiftval);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{

        shiftval--;

        Edit2->Text = IntToStr(shiftval);


}
//---------------------------------------------------------------------------




void __fastcall TForm1::ImageMouseUp(TObject *Sender, TMouseButton Button,
                                    TShiftState Shift, int X, int Y)
{
     char obuf[100];

    if(Button == mbLeft){    //左ボタンが離された場合のみ処理する
        //現在のカーソルの位置を記録しておく
        FPrevPoint.x = X;
        FPrevPoint.y = Y;
        //Close();  //  do not close Form1 now!!
        sprintf(obuf,"(%d,%d) -> (%d,%d)\n",FClickPoint.x,FClickPoint.y,X,Y);
        Memo1->Lines->Add(obuf);        // ROI display
        RoiStartx = FClickPoint.x;
        RoiStarty = FClickPoint.y;
        RoiEndx = X;
        RoiEndy = Y;
        //Button9->Caption = obuf;
        Button12->Enabled = true;
        Button12->Visible = true;
        //Form4->Button12->Visible = true;

		RoiSizeX = RoiEndx - RoiStartx -1; // changed interpretation inclusive->exclusive 2008-3-14
		RoiSizeY = RoiEndy - RoiStarty -1;
    }
}

void __fastcall TForm1::ImageMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

     if(Button==mbLeft){      //左ボタンのみ処理
        if(manual){
                struct  apoint *data = new struct apoint;
        Image1->Canvas->Pen->Mode = pmNotXor;    //描画時に色を反転するように指定
        Image1->Canvas->Pen->Color = clBlue;     //青色を指定
        Image1->Canvas->Brush->Style = bsClear;  //塗り潰しはしない

                data->x = X;

                //if(OriginLeftBottom->Checked )
                //        data->y = ih-Y;
                //else
                        data->y = Y;
                currentpset->Add(data);
                Image1->Canvas->Ellipse(X-2,Y-2,X+2,Y+2); // for visual feedback
        }

        FClickPoint.x = X;   //クリックされた位置を記録
        FClickPoint.y = Y;
        FPrevPoint = FClickPoint; //前回のカーソル位置=クリックされた位置
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImageMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    if (Shift.Contains(ssLeft)) { // ボタンが押された場合 
        Image1->Canvas->Pen->Mode = pmNotXor;    //描画時に色を反転するように指定
        Image1->Canvas->Pen->Color = clBlue;     //青色を指定
        Image1->Canvas->Brush->Style = bsClear;  //塗り潰しはしない

        //前回描いた四角を消す
        Image1->Canvas->Rectangle(FClickPoint.x,FClickPoint.y,FPrevPoint.x,FPrevPoint.y);
        //新しく四角を描く
        Image1->Canvas->Rectangle(FClickPoint.x,FClickPoint.y,X,Y);

        //現在のカーソルの位置を記録しておく
        FPrevPoint.x = X; 
        FPrevPoint.y = Y;
    }
} 


void __fastcall TForm1::Button8Click(TObject *Sender)
{
        if(!fselected)
                return;

         if(!sdisplayed) {
                sourceframe = 0;
                DispFrame(sourceframe);
                sdisplayed = 1;
        }
        else {
                --sourceframe;
                if( sourceframe < 0 )
                        sourceframe = 0;
                DispFrame(sourceframe);
        }

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button9Click(TObject *Sender)
{
        //ShowMessage("Motion Analysis going from here!");
        if( spiral )
                SpiralAnalysis();
        else
                LinearAnalysis();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::maketable(void)
{
        int     oldx=-1;
        int     oldy=1;

        dx[0] = dy[0] = 0;

        int     j,i=1;
        int     span=1;

        for( ;; ){
                for( j = 0 ; j < span ; j++ ){
                        dx[i] = -oldx;
                        dy[i] = 0;
                        i++;
                        if( i > 389376 )
                                goto end;
                }
                oldx *= -1;
                for( j = 0 ; j < span ; j++ ){
                        dx[i] = 0;
                        dy[i] = -oldy;
                        i++;
                        if( i > 389376 )
                                goto end;
                }
                oldy *= -1;
                span++;
        }
 end:
        
        //for( i = 389370 ; i < 389376 ; i++ )
        //        Memo1->Lines->Add(IntToStr(i)+":"+IntToStr(dx[i])+","+IntToStr(dy[i]));

}

void __fastcall setroibuf(void)
{
        Word *ptr;


		roi = (Word *)malloc(sizeof(Word)*RoiSizeX*RoiSizeY);
        if( !roi ){
                ShowMessage("not enough memory");
        }

        ptr = roi;
        roiave = 0.0;

		for( int y = RoiStarty+1 ; y < RoiEndy ; y++ )
				for( int x = RoiStartx+1 ; x < RoiEndx ; x++ ) {
                        if( avimode || still ){
                          *ptr++ = (Word)bsourceframebuf[y*iw+x];
                          roiave += (double)bsourceframebuf[y*iw+x];

                        }
                        else {
                         *ptr++ = sourceframebuf[y*iw+x];
                         roiave += (double)sourceframebuf[y*iw+x];
                        }
                }

        roiave /=   RoiSizeX*RoiSizeY;
}

void __fastcall setdestbuf(int diffx, int diffy)
{
        Word *ptr;


        //ShoeMessage("iw ih "+AnsiString(iw)+" "+AnsiString(ih));

        dest = (Word *)malloc(sizeof(Word)*RoiSizeX*RoiSizeY);
        if( !dest ){
                ShowMessage("not enough memory for dest buffer");
        }

        ptr = dest;
        destave = 0.0;

		for( int y = RoiStarty+1 ; y < RoiEndy ; y++ )
                for( int x = RoiStartx+1 ; x < RoiEndx ; x++ ) {
						if( avimode || still ){
                          *ptr++ = (Word)bdestframebuf[(y+diffy)*iw+x+diffx];
                          destave += (double)bdestframebuf[(y+diffy)*iw+diffx+x];

                        }
                        else {


                         *ptr++ = destframebuf[(y+diffy)*iw+x+diffx];
                         destave += (double)destframebuf[(y+diffy)*iw+x+diffx];
                        }
                }

        
        destave /=   RoiSizeX*RoiSizeY;

}

void __fastcall interpolate(int x, int y)
{
        double  z3,z2,z1,a,b;

        z1 = results[y*iw+x-1];
        z2 = results[y*iw+x];
        z3 = results[y*iw+x+1];         // swapped on 3/5/2007

        a = z3-z2;
        b = z2-z1;

        ox = (b+a) / (2.0*(b-a));

        z3 = results[(y-1)*iw+x];
        z2 = results[y*iw+x];
        z1 = results[(y+1)*iw+x];

        a = z3-z2;
        b = z2-z1;

        oy = (b+a) / (2.0*(b-a));

}

void __fastcall showrotation(int ofx,int ofy,double angle,int flag)
{

        double  valsin,valcos;
        double dx1,dy1,dx,dy,dd;

        int     x1,y1,x2,y2;
        int     x,y;
        int     c0,c1,c2,c3;

        int     dstwidth,dstheight;
        int     srccx,srccy;
        int     dstcx,dstcy;
        int     int_cos,int_sin;
        Word    *d,*s;

        rdest = (Word *)malloc(sizeof(Word)*RoiSizeX*RoiSizeY);
        if( !rdest ){
                ShowMessage("not enough core for rotation buffer");
                return;
        }

        angle = 3.1415*angle/180.0;
        
        valsin = sin(angle);
        valcos = cos(angle);

        //dstwidth = (int)(fabs(srcwidth*valcos)+fabs(srcheight*valsin)+0.5);
        //dstheight = (int)(fabs(srcwidth*valsin)+fabs(srcheight*valcos)+0.5);

        dstwidth = RoiSizeX;
        dstheight = RoiSizeY;

        //srccx = srcwidth/2;
        //srccy = srcheight/2;
        srccx = dstcx = dstwidth/2;
        srccy = dstcy = dstheight/2;

        //int_cos = (int)(valcos*1024);
        //int_sin = (int)(valsin*1024);

        rdestave = 0.0;

        for( y2 = 0 ; y2 < dstheight ; y2++ ){
                for( x2 = 0 ; x2 < dstwidth ; x2++ ){
                        dx1 =((x2-dstcx)*valcos - (y2-dstcy)*valsin) +ofx;
                        dy1 =((x2-dstcx)*valsin + (y2-dstcy)*valcos) +ofy;

                        if( dx1  >= 0 && dx1 < iw && dy1 >= 0 && dy1 < ih ){
                                x = (int)dx1;
                                y = (int)dy1;

                                dx1 -= x;
                                dy1 -= y;

                                if( flag ){
                                     if( avimode || still ){
                                        c0 = bdestframebuf[y*iw+x];
                                        c1 = bdestframebuf[y*iw+x+1];
                                        c2 = bdestframebuf[(y+1)*iw+x];
                                        c3 = bdestframebuf[(y+1)*iw+x+1];


                                     }
                                     else {
                                        c0 = destframebuf[y*iw+x];
                                        c1 = destframebuf[y*iw+x+1];
                                        c2 = destframebuf[(y+1)*iw+x];
                                        c3 = destframebuf[(y+1)*iw+x+1];
                                     }
                                }
                                else {
                                     if( avimode || still ){
                                        c0 = bsourceframebuf[y*iw+x];
                                        c1 = bsourceframebuf[y*iw+x+1];
                                        c2 = bsourceframebuf[(y+1)*iw+x];
                                        c3 = bsourceframebuf[(y+1)*iw+x+1];

                                     }
                                     else {
                                        c0 = sourceframebuf[y*iw+x];
                                        c1 = sourceframebuf[y*iw+x+1];
                                        c2 = sourceframebuf[(y+1)*iw+x];
                                        c3 = sourceframebuf[(y+1)*iw+x+1];
                                     }
                                }

                                dd = (1-dy1)*((1-dx1)*c0 + dx1*c1) + dy1*((1-dx1)*c2+dx1*c3);

                                // rdest[y2][x2] = destframebuf[ofy+y1][ofx+x1]


                                d = rdest + RoiSizeX*y2 + x2;
                                *d = (Word)dd;

                                rdestave += (double)dd;
                        }
                }
        }
        rdestave /= RoiSizeX*RoiSizeY;
}

int  __fastcall corrcomp(void* i1, void* i2)
{
        struct resdata *p1,*p2;
        double  item1,item2;


        p1 = (struct resdata *)i1;
        p2 = (struct resdata *)i2;

        item1 = p1->corr;
        item2 = p2->corr;

        if( item1 < item2 )
                return 1;
        else if( item1 == item2 )
                return 0;
        else
                return -1;

}

#define BORDERH 3

void __fastcall NotchPoint(TImage* tar,int x ,int y )
{
        int     backup = tar->Canvas->Pen->Color;

        tar->Canvas->Pen->Color = clRed;
        tar->Canvas->Pen->Mode = pmCopy;        // huh?


        tar->Canvas->MoveTo(x -BORDERH,y);
        tar->Canvas->LineTo(x+BORDERH,y);
        tar->Canvas->MoveTo(x,y-BORDERH);
        tar->Canvas->LineTo(x,y+BORDERH);

        tar->Canvas->Pen->Color = backup;

}

void __fastcall NumberIt(TImage* tar,int x ,int y,int number )
{
        int     backup = tar->Canvas->Pen->Color;

        tar->Canvas->Pen->Color = clYellow;

        tar->Canvas->TextOutA(x,y,AnsiString(number));

        tar->Canvas->Pen->Color = backup;
        
}

void __fastcall TForm1::LinearAnalysis(void)
{
        int     offsetx=0,offsety=0;
        int     horpos;
        int     index,length;
        TImage* targs;
        TImage* targd;


        double   sum=0.0;
        double sumupper,sumdownleft,sumdownright,sumdown;
        double  p1,p2;
        double maxcorr = 0.0;
        int     maxposx,maxposy,currx,curry,maxofx,maxofy,maxindex;

        char obuf[100];
        int     centerx = (RoiStartx + RoiEndx )/2;
        int     centery = (RoiStarty + RoiEndy )/2;

        TRect area(0,0,311,259);
        Image2->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit
        Image2->Picture->Bitmap->Width = Image2->Width;
        Image2->Picture->Bitmap->Height = Image2->Height;
//
        Image2->Canvas->Pen->Mode = pmCopy;    //描画時に色を反転するように指定
        Image2->Canvas->Pen->Color = clYellow;     //青色を指定
        Image2->Canvas->Brush->Style = bsClear;  //塗り潰しはしない

        //前回描いた四角を消す
        //Image2->Canvas->Rectangle(FClickPoint.x,FClickPoint.y,FPrevPoint.x,FPrevPoint.y);
        //新しく四角を描く
        //Image2->Canvas->Rectangle(FClickPoint.x,FClickPoint.y,X,Y);

//

        Image2->Canvas->Rectangle(0,0,Image2->Width,Image2->Height);
        if( other )
                targd = Form3->Image1;
        else
                targd = Image2;

        if( other )
                targs = Form2->Image1;
        else
                targs = Image1;

        if( nottarget )
                return;

        //Form2->disparea(roi);

        Memo1->Lines->Add("Linear search results\r\n");
        
        disparea(0,0,roi);
        if( initangle != 0.0 ){
                showrotation(centerx,centery,initangle,0);    // rotated into rdest

                disparea(RoiSizeX,0,rdest);
                ShowMessage("source area and rotated area");
        }

        targs->Canvas->Pen->Mode = pmCopy;    //描画時に色を反転するように指定
        targs->Canvas->Pen->Color = clYellow;     //青色を指定
        targs->Canvas->Brush->Style = bsClear;  //塗り潰しはしない



                targs->Canvas->MoveTo(centerx-2,centery);
                targs->Canvas->LineTo(centerx+2,centery);
                targs->Canvas->MoveTo(centerx,centery-2);
                targs->Canvas->LineTo(centerx,centery+2);




        int     targeframe = StrToInt(Edit4->Text);

                PaintBox2->Canvas->Brush->Color = Form1->Color; // back ground is clBtnFace
                PaintBox2->Canvas->FillRect(Rect(0,0,399,199));

//                for( int deltaindex = 0 ; deltaindex < dlimit ; deltaindex++ ){

        length = (iw-RoiSizeX)*(ih-RoiSizeY);
        //Label7->Caption = IntToStr(length);
        Label7->Caption = AnsiString(length);
        Label7->Refresh();
        
        index = 0;
        for( offsety = 0 ; offsety < ih - RoiSizeY ; offsety++ ){
                for( offsetx = 0 ; offsetx < iw - RoiSizeX; offsetx++ ){

                        sum = 0.0;
                        //Image2->Canvas->Rectangle(RoiStartx+offsetx,RoiStarty+offsety,RoiEndx+offsetx,RoiEndy+offsety);
                        //Image2->Refresh();
                        setdestbuf(offsetx - RoiStartx,offsety - RoiStarty);
                        //Form2->disparea(RoiSizeX,0,dest);

                        //disparea(RoiSizeX,0,dest);
                        //Image3->Refresh();
                        //ShowMessage("am");

                        //ShowMessage("This is destination area");
                        //PaintBox2->Canvas->FillRect(area);

                        sumupper = 0.0;
                        sumdownleft = 0.0;
                        sumdownright = 0.0;
                        for(  int y = 0 ; y < RoiSizeY ; y++ ){
                                for( int x = 0 ; x < RoiSizeX ; x++ ){
                                        if( initangle == 0.0 ){
                                                p1 = (double)(roi[y*RoiSizeX+x]-roiave);
                                                p2 = (double)(dest[y*RoiSizeX+x]-destave);
                                        }
                                        else {
                                                p1 = (double)(rdest[y*RoiSizeX+x]-rdestave);
                                                p2 = (double)(dest[y*RoiSizeX+x]-destave);

                                        }

                                        sumupper += p1*p2;
                                        sumdownleft += p1*p1;
                                        sumdownright += p2*p2;

                                }
                        }
                        sumdown = sqrt(sumdownleft)*sqrt(sumdownright);
                        sum = sumupper/sumdown;

                        horpos = 400*index/length;
                        index++;
                        PaintBox2->Canvas->MoveTo(horpos,199);

                        PaintBox2->Canvas->LineTo(horpos,200-200*sum);
                         currx = RoiSizeX/2 + offsetx;
                         curry = RoiSizeY/2 + offsety;
                        if( sum > maxcorr ){
                                maxcorr = sum;
                                maxposx = currx;
                                maxposy = curry;
                                maxofx = offsetx-RoiStartx;
                                maxofy = offsety-RoiStarty;
                                maxindex = index-1;

                        }


                        results[curry*iw+currx] = sum;

                        if( sum > corrthresh ){        // should be recorded
                                struct resdata *temp = new struct resdata;
                                temp->posx = currx;
                                temp->posy = curry;
                                temp->corr = sum;

                                respointset->Add(temp);

                        }

                        if( sum < 0.0 )
                                sum *= -1.0;

                        if( avimode || still )
                                brframe[curry*iw+currx] = (Byte)(255*sum);
                        else
                                rframe[curry*iw+currx] = (Word)(255*sum);

                        //      save to value matrix
                        //      max and two more values -> offset calc
                        //
                        //sprintf(obuf,"%d %g\n",deltaindex,sum);
                        //Memo1->Lines->Add(obuf);
                        free(dest);

                }
        }

                interpolate(maxposx,maxposy);

                // results cursor  set at maxposx,maxposy in Image2

                targd->Canvas->MoveTo(maxposx-2,maxposy);
                targd->Canvas->LineTo(maxposx+2,maxposy);
                targd->Canvas->MoveTo(maxposx,maxposy-2);
                targd->Canvas->LineTo(maxposx,maxposy+2);


                sprintf(obuf,"max correlation is %g at %d,%d:%d with rotation %g\n\n",maxcorr,maxofx,maxofy,maxindex,initangle);
                Memo1->Lines->Add(obuf);
                sprintf(obuf,"offset comp. is %g,%g",ox,oy);
                Memo1->Lines->Add(obuf);
                //ShowMessage("kick outs");
                sprintf(obuf,"Object Motion is (%d,%d) -> (%g,%g)",centerx,centery,maxposx+ox,maxposy+oy);
                Memo1->Lines->Add(obuf) ;
                sprintf(obuf,"Object Displacement between fr %d->%d  is %g,%g\r\n",sourceframe,destframe,maxposx+ox-centerx,maxposy+oy-centery);
                Memo1->Lines->Add(obuf) ;

                setdestbuf(maxofx,maxofy);      // image in dest holds unrotated image
                disparea(RoiSizeX,0,dest);
                ShowMessage("source area and deteced area");

                int offset = 0;
                int     yoffset = 1;

                sprintf(obuf,"angle,sum,maxcorr");
                Memo1->Lines->Add(obuf);

                for( double angle = -30.0 ; angle < 30.5 ; angle += anglestep ,offset++ ){  // was 0.5
                        showrotation(maxposx,maxposy,angle,1);      // rotate 10.0 image at maxofx,maxofy in destbuf


                        if( RoiSizeX*offset > iw ){
                                offset = 0;
                                yoffset++;
                        }
                        disparea(RoiSizeX*offset,yoffset*RoiSizeY,rdest);

                        sumupper = 0.0;
                        sumdownleft = 0.0;
                        sumdownright = 0.0;

                        for(  int y = 0 ; y < RoiSizeY ; y++ ){
                                for( int x = 0 ; x < RoiSizeX ; x++ ){
                                        p1 = (double)(roi[y*RoiSizeX+x]-roiave);
                                        p2 = (double)(rdest[y*RoiSizeX+x]-rdestave);
                                        sumupper += p1*p2;
                                        sumdownleft += p1*p1;
                                        sumdownright += p2*p2;

                                }
                        }
                        sumdown = sqrt(sumdownleft)*sqrt(sumdownright);
                        sum = sumupper/sumdown;

                        sprintf(obuf,"%g,%g,%g",angle,sum,maxcorr);
                        Memo1->Lines->Add(obuf);


                  }
                //ShowMessage("don don");
        if(CorrDisplay->Checked){
                if( avimode || still )
                        dispwhole(brframe);
                else
                        dispwhole((Word *)rframe);
        }


        //}
        if( respointset ){
                respointset->Sort(corrcomp);
                for( int i = 0 ; i < respointset->Count ; i++ ){
                        struct resdata *temp;
                        TImage* tar;

                        temp = (struct resdata *)respointset->Items[i];

                        Memo1->Lines->Add(AnsiString(i+1)+" x "+AnsiString(temp->posx)+" y "+AnsiString(temp->posy)+" corr "+AnsiString(temp->corr));

                        if( other )
                                tar = Form3->Image1;
                        else
                                tar = Image2;

                        NotchPoint(tar,temp->posx,temp->posy);
                        NumberIt(tar,temp->posx,temp->posy,i+1);

                }
        }



}


void __fastcall TForm1::SpiralAnalysis(void)
{

#define FLIMIT 1
#define DLIMIT 10000

        int     offsetx=0,offsety=0;
        int     horpos;

        double   sum=0.0;
        double sumupper,sumdownleft,sumdownright,sumdown;
        double  p1,p2;
        double maxcorr = 0.0;
        int     maxposx,maxposy,currx,curry,maxofx,maxofy,maxindex;

        char obuf[100];
        TImage* targs;
        TImage* targd;


        TRect area(0,0,iw-1,ih-1);
        //TRect corr(0,0,400,200);


        if( dlimit > 389376 ){
                ShowMessage("delta limitは389376以下");
                return;
        }

        if( other )
                targd = Form3->Image1;
        else
                targd = Image2;

        if( other )
                targs = Form2->Image1;
        else
                targs = Image1;

        targd->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit
        targd->Picture->Bitmap->Width = targd->Width;
        targd->Picture->Bitmap->Height = targd->Height;
//
        targd->Canvas->Pen->Mode = pmCopy;    //描画時に色を反転するように指定
        targd->Canvas->Pen->Color = clRed;     //青色を指定
        targd->Canvas->Brush->Style = bsClear;  //塗り潰しはしない

        //前回描いた四角を消す
        //Image2->Canvas->Rectangle(FClickPoint.x,FClickPoint.y,FPrevPoint.x,FPrevPoint.y);
        //新しく四角を描く
        //Image2->Canvas->Rectangle(FClickPoint.x,FClickPoint.y,X,Y);

//

        //targd->Canvas->Rectangle(0,0,targd->Width,targd->Height);
        if( nottarget )
                return;

        //Form2->disparea(roi);

        disparea(0,0,roi);

        targs->Canvas->Pen->Mode = pmCopy;    //描画時に色を反転するように指定
        targs->Canvas->Pen->Color = clRed;     //青色を指定
        targs->Canvas->Brush->Style = bsClear;  //塗り潰しはしない

        int     centerx = (RoiStartx + RoiEndx )/2;
        int     centery = (RoiStarty + RoiEndy )/2;


                targs->Canvas->MoveTo(centerx-2,centery);
                targs->Canvas->LineTo(centerx+2,centery);
                targs->Canvas->MoveTo(centerx,centery-2);
                targs->Canvas->LineTo(centerx,centery+2);




        int     targeframe = StrToInt(Edit4->Text);

        //for( int targetframe = framenum ; targetframe < framenum + FLIMIT ; targetframe++ ){
                // source display then copy
                //if( targetframe != framenum ){
                //        DispFrame(targetframe);
                //        Image1->Refresh();
                //        Edit1->Text = IntToStr(targetframe);
                //}
                //Image2->Canvas->CopyRect(area,Image1->Canvas,area) ;
                //Image2->Refresh();
                //Edit3->Text = IntToStr(targetframe);

                //PaintBox2->Canvas->Brush->Color = clDkGray;
                //PaintBox2->Canvas->Brush->Color = clMedGray;
                PaintBox2->Canvas->Brush->Color = Form1->Color; // back ground is clBtnFace
                PaintBox2->Canvas->FillRect(Rect(0,0,399,199));

                for( int deltaindex = 0 ; deltaindex < dlimit ; deltaindex++ ){
                        if( linearmode ){
                                if( horiz )
                                        offsetx += 1;
                                else
                                        offsety += 1;

                        }
                        else {
                                offsetx += dx[deltaindex];
                                offsety += dy[deltaindex];
                        }

                        if( RoiStartx + offsetx < 0 || RoiEndx + offsetx > iw )
                                continue;
                        if( RoiStarty + offsety < 0 || RoiEndy + offsety > ih )
                                continue;

                        sum = 0.0;
                        //Image2->Canvas->Rectangle(RoiStartx+offsetx,RoiStarty+offsety,RoiEndx+offsetx,RoiEndy+offsety);
                        //Image2->Refresh();
                        setdestbuf(offsetx,offsety);
                        //Form2->disparea(dest);
                        //ShowMessage("This is destination area");
                        //PaintBox2->Canvas->FillRect(area);

                        sumupper = 0.0;
                        sumdownleft = 0.0;
                        sumdownright = 0.0;

                        for(  int y = 0 ; y < RoiSizeY ; y++ ){
                                for( int x = 0 ; x < RoiSizeX ; x++ ){
                                        p1 = (double)(roi[y*RoiSizeX+x]-roiave);
                                        p2 = (double)(dest[y*RoiSizeX+x]-destave);
                                        sumupper += p1*p2;
                                        sumdownleft += p1*p1;
                                        sumdownright += p2*p2;

                                }
                        }
                        sumdown = sqrt(sumdownleft)*sqrt(sumdownright);
                        sum = sumupper/sumdown;

                        horpos = 400*deltaindex/dlimit;

                        PaintBox2->Canvas->MoveTo(horpos,199);

                        PaintBox2->Canvas->LineTo(horpos,200-200*sum);
                         currx = (RoiStartx+RoiEndx)/2 + offsetx;
                         curry = (RoiStarty+RoiEndy)/2 + offsety;
                        if( sum > maxcorr ){
                                maxcorr = sum;
                                maxposx = currx;
                                maxposy = curry;
                                maxofx = offsetx;
                                maxofy = offsety;
                                maxindex = deltaindex;

                        }

                        results[curry*iw+currx] = sum;
                        if( sum < 0.0 )
                                sum *= -1.0;
                        if( avimode || still )
                              brframe[curry*iw+currx] = (Byte)(255*sum);
                        else
                                rframe[curry*iw+currx] = (Word)(255*sum);

                        //      save to value matrix
                        //      max and two more values -> offset calc
                        //
                        //sprintf(obuf,"%d %g\n",deltaindex,sum);
                        //Memo1->Lines->Add(obuf);
                        free(dest);

                }
                interpolate(maxposx,maxposy);

                // results cursor  set at maxposx,maxposy in Image2

                targd->Canvas->MoveTo(maxposx-2,maxposy);
                targd->Canvas->LineTo(maxposx+2,maxposy);
                targd->Canvas->MoveTo(maxposx,maxposy-2);
                targd->Canvas->LineTo(maxposx,maxposy+2);


                sprintf(obuf,"max correlation is %g at %d,%d:%d\n\n",maxcorr,maxofx,maxofy,maxindex);
                Memo1->Lines->Add(obuf);
                sprintf(obuf,"offset comp. is %g,%g",ox,oy);
                Memo1->Lines->Add(obuf);
                //ShowMessage("kick outs");
                sprintf(obuf,"Object Motion is (%d,%d) -> (%g,%g)",centerx,centery,maxposx+ox,maxposy+oy);
                Memo1->Lines->Add(obuf) ;
                sprintf(obuf,"Object Displacement between fr %d->%d  is %g,%g",sourceframe,destframe,maxposx+ox-centerx,maxposy+oy-centery);
                Memo1->Lines->Add(obuf) ;
                sprintf(obuf,"in real dimension %g,%g",(maxposx+ox-centerx)*spacefactor,(maxposy+oy-centery)*spacefactor);
                setdestbuf(maxofx,maxofy);      // image in dest holds unrotated image
                disparea(RoiSizeX,0,dest);
                ShowMessage("source area and deteced area");

                int offset = 0;
                int     yoffset = 1;

                for( double angle = -30.0 ; angle < 30.5 ; angle += anglestep ,offset++ ){
                        showrotation(maxposx,maxposy,angle,1);      // rotate 10.0 image at maxofx,maxofy in destbuf


                        if( RoiSizeX*offset > iw ){
                                offset = 0;
                                yoffset++;
                        }
                        disparea(RoiSizeX*offset,yoffset*RoiSizeY,rdest);

                        sumupper = 0.0;
                        sumdownleft = 0.0;
                        sumdownright = 0.0;

                        for(  int y = 0 ; y < RoiSizeY ; y++ ){
                                for( int x = 0 ; x < RoiSizeX ; x++ ){
                                        p1 = (double)(roi[y*RoiSizeX+x]-roiave);
                                        p2 = (double)(rdest[y*RoiSizeX+x]-rdestave);
                                        sumupper += p1*p2;
                                        sumdownleft += p1*p1;
                                        sumdownright += p2*p2;

                                }
                        }
                        sumdown = sqrt(sumdownleft)*sqrt(sumdownright);
                        sum = sumupper/sumdown;

                        sprintf(obuf,"%g\t%g\t%g",angle,sum,maxcorr);
                        Memo1->Lines->Add(obuf);


                  }

//                if( avimode )
//                        dispwhole(brframe);
//                else
//                        dispwhole((Word *)rframe);

        //}


}

void __fastcall TForm1::Button10Click(TObject *Sender)
{
         if(!fselected)
                return;

         if(!displayed) {
                destframe = 0;
                DispFrame2(destframe);
                displayed = 1;
        }
        else {
                --destframe;
                if( destframe < 0 )
                        destframe = 0;
                DispFrame2(destframe);
        }

        nottarget = 0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
         if(!fselected)
                return;

        if(!displayed) {
                destframe = 0;
                DispFrame2(destframe);
                displayed = 1;
        }
        else {
                ++destframe;
                if( destframe > endframe )
                        destframe = endframe;
                DispFrame2(destframe);

        }
        nottarget = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{

/*
struct rois {
        int     startx,starty;
        int     endx,endy;
        int     sizex,sizey;
        int     oldx,oldy;
        double  oldangle;
        double  *wtime,*posx,*posy,*cposx,*cposy,*angle;
};

TList* roiset;

*/

        if( CheckBox11->Checked )
                linearmode = true;
        else
                linearmode = false;

        if( !made ){
                maketable();
                made = true;
        }
        setroibuf();
        //Visible = true;
        Image3->Canvas->Brush->Color = Form1->Color; // back ground is clBtnFace
        Image3->Canvas->FillRect(Rect(0,0,311,259));


        disparea(0,0,roi);
        // first add new roi based on RoiStarx and etc.

        struct rois *ptr = new (struct rois);

        if( linearmode ){
                if( RoiEndx - RoiStartx > RoiEndy - RoiStarty ) {// horizontal draw
                        RoiEndy = RoiStarty;
                        horiz = true;
                        vert = false;
                }
                else {
                        RoiEndx = RoiStartx;
                        horiz = false;
                        vert = true;
                }

                Memo1->Lines->Add("width: "+AnsiString(RoiEndx-RoiStartx-1)+"height: "+AnsiString(RoiEndy-RoiStarty-1));
        }

        ptr->startx = RoiStartx;
        ptr->starty = RoiStarty;
        ptr->endx = RoiEndx;
        ptr->endy = RoiEndy;
		ptr->sizex = RoiEndx - RoiStartx -1;
        ptr->sizey = RoiEndy - RoiStarty -1;

        ptr->wtime = (double *)malloc(sizeof(double)*(endframe+1));
        ptr->posx =  (double *)malloc(sizeof(double)*(endframe+1));
        ptr->posy = (double *)malloc(sizeof(double)*(endframe+1));
        ptr->cposx = (double *)malloc(sizeof(double)*(endframe+1));
        ptr->cposy = (double *)malloc(sizeof(double)*(endframe+1));
        ptr->angle = (double *)malloc(sizeof(double)*(endframe+1));

        if( !ptr->wtime || !ptr->posx || !ptr->posy || !ptr->cposx || !ptr->cposy || !ptr->angle ){
                ShowMessage("not enough core for roi ");
                exit(1);
        }

        roiset->Add(ptr);


        //ShowMessage("This is selected ROI");
        //Button9->Enabled = true;

        if( roiset->Count == 1 ){
                Button9->Visible = true;
                Form4->Button9->Visible = true;

        //Button3->Enabled = true;
                Button3->Visible = true;

                Label7->Caption = AnsiString(dlimit);
                Label8->Caption = "1.0";
                Label5->Caption = "Correlation";
        }
        Edit7->Text = roiset->Count - 1;
        Form4->Edit7->Text = Edit7->Text;
        disprois();
        parmpoints = roiset->Count;


}

//---------------------------------------------------------------------------                                                                                                         i
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

		int     henkan[1024],hist[1024],ruikei,jc;
		unsigned long	avihenkan[256],avihist[256],aviruikei,avijc;

		Word *pp;
		Word *alt = (Word *)sourceframebuf;
		TMemoryStream* temp = new TMemoryStream();
		TImage* targeti;
		Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
		BYTE modval;
		int	offset;

		sourceframe++;
		if( sourceframe > endframe ) {
				Timer1->Enabled = false;
				sourceframe = endframe;
		}


		if( other )
				targeti = Form2->Image1;
		else
				targeti = Image1;

		if( avimode ) {

				//AVIImage1->SetPosition(sourceframe,false);
				//AVIImage1->SaveToStream(temp);
				work->saveaframe(sourceframe,temp);
				temp->Position = 0;

				if( !CheckBox10->Checked )
					targeti->Picture->Bitmap->LoadFromStream(temp);
				else {
					Bitmap->LoadFromStream(temp);

					for( int count = 0 ; count < 256 ; count++ ){
						avihenkan[count] = 0;
						avihist[count] = 0;
					}


 //				targeti->Canvas->CopyRect(Rect(0,0,targeti->Width-1,targeti->Height-1),Bitmap->Canvas,Rect(0,0,Bitmap->Width-1,Bitmap->Height-1));
				int	depth = Bitmap->PixelFormat;

				switch(depth){
					case pf8bit: offset = 1;
							break;
					case pf16bit: offset = 2;
							break;
					case pf24bit: offset = 3;
								break;
					case pf32bit: offset = 4;
								break;

				}
				for( int row = 0 ; row < ih; row++ ){
					  //BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
					BYTE *scanPtr = (BYTE *)Bitmap->ScanLine[row];
					for( int col = 0 ; col < iw ; col++ ){
						BYTE* tempPtr = scanPtr+col*offset;    // 8bit avi
						//BYTE val = (frame[312*(260-row)+col]&0xff);
						avihist[tempPtr[0]]++;
					}

				}

					aviruikei = 0;
					avijc = 0;
					//hsize = targeti->Width;
					//vsize = targeti->Height;
					unsigned	long fact = ih*iw/256;

					for( int c = 0 ; c < 256 ; c++ ){
						aviruikei += avihist[c];
						avijc += aviruikei/fact;        // 312*260/1024 = 79.2  512
						aviruikei %= fact;
						if(avijc > 255 )
							avijc = 255;
						avihenkan[c]=avijc;
					}

				depth = targeti->Picture->Bitmap->PixelFormat;

				switch(depth){
					case pf8bit: offset = 1;
							break;
					case pf16bit: offset = 2;
							break;
					case pf24bit: offset = 3;
								break;
					case pf32bit: offset = 4;
								break;

				}

					for( int row = 0 ; row < ih; row++ ){
					  BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
						//TE *scanPtr = (BYTE *)Bitmap->ScanLine[row];
						for( int col = 0 ; col < iw ; col++ ){
							BYTE* tempPtr = scanPtr+col*3;    // 8bit avi
							//BYTE val = (frame[312*(260-row)+col]&0xff);
						modval = (BYTE)avihenkan[tempPtr[0]];
						//tempPtr[0] = modval;
						tempPtr[0] = modval;
						if( depth > 1){
						tempPtr[1] = modval;
						tempPtr[2] = modval;
						}
					targeti->Refresh();

						}

					}

			}

		}
		else {
				fseek(refp,sizeof(hd)+312*260*2*sourceframe,SEEK_SET);
				fread(sourceframebuf, 312*260*2,1,refp);
				revertit(sourceframebuf);
				pp = (Word *)sourceframebuf;
				if(CheckBox10->Checked){
                        for( int count = 0 ; count < 1024 ; count++ ){
                                henkan[count] = 0;
								hist[count] = 0;
                        }


                        for( int row = 0 ; row < targeti->Height; row++ ){
                                for( int col = 0 ; col < targeti->Width ; col++ ){
                                        WORD val =  *alt++;
										hist[val]++;
                                }
                        }

						ruikei = 0;
                        jc = 0;

                        for( int c = 0 ; c < 1024 ; c++ ){
								ruikei += hist[c];
                                jc += ruikei/80;        // 312*260/1024 = 79.2
                                ruikei %= 80;
                                henkan[c]=jc;
						}
                        alt = pp;       // re-init
                }

				for( int row = 0 ; row < targeti->Height; row++ ){
                        BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
                        for( int col = 0 ; col < targeti->Width ; col++ ){
                                BYTE* tempPtr = scanPtr+col*3;
								//BYTE val = (frame[312*(260-row)+col]&0xff);
                                BYTE val = *pp++&0xff;
                                WORD wval = *alt++;

								if( shiftval < 0 )
                                        val >>= (-shiftval);
                                else
                                        val <<= shiftval;

								if( CheckBox10->Checked ){
										val = henkan[wval]/4;
								}

										tempPtr[0] = val;
                                        tempPtr[1] = val;
										tempPtr[2] = val;
                        }
                }
		}


        Edit1->Text = IntToStr(sourceframe);
		Form4->Edit1->Text = Edit1->Text;

        targeti->Refresh();


		delete temp;
		delete Bitmap;
        

}

//---------------------------------------------------------------------------




void __fastcall TForm1::Edit5Exit(TObject *Sender)
{
				 dlimit = StrToInt(Edit5->Text);
				Label7->Caption = Edit5->Text;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
        sourceframe = StrToInt(Edit1->Text);
        DispFrame(sourceframe);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Exit(TObject *Sender)
{
        destframe = StrToInt(Edit4->Text);
        DispFrame2(destframe);
        displayed = 1;
        nottarget = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
 //     automatic sequence activated by "Step by Step"

         int     offsetx=0,offsety=0;
        int     horpos;
        int     centerx,centery;

        double   sum=0.0;
        double sumupper,sumdownleft,sumdownright,sumdown;
        double  p1,p2;
        double maxcorr = 0.0;
        int     maxposx,maxposy,currx,curry,maxofx,maxofy,maxindex;

        char obuf[100];



        int     current = sourceframe;
        int     upperlimit = destframe;

        Image3->Canvas->Brush->Color = Form1->Color; // back ground is clBtnFace
        Image3->Canvas->FillRect(Rect(0,0,311,259));

        while( current < upperlimit ){
                // Roiset
                // Destset based on deltaindex

                DispFrame(current);
                sourceframe = current;
                setroibuf();
                disparea(0,0,roi);
                //Edit1->Text = IntToStr(current);

                DispFrame2(current+1);
                destframe = current+1;
                
                //Edit4->Text = IntToStr(current+1);

                Image1->Refresh();
                Image2->Refresh();

                Image3->Canvas->MoveTo((RoiStartx + RoiEndx )/2,(RoiStarty + RoiEndy )/2);
                offsetx = offsety = 0;  // poof!
                for( int deltaindex = 0 ; deltaindex < dlimit ; deltaindex++ ){
                        offsetx += dx[deltaindex];
                        offsety += dy[deltaindex];

                        if( RoiStartx + offsetx < 0 || RoiEndx + offsetx > iw )
                                continue;
                        if( RoiStarty + offsety < 0 || RoiEndy + offsety > ih )
                                continue;

                        sum = 0.0;
                        setdestbuf(offsetx,offsety);
                        centerx = (RoiStartx + RoiEndx )/2;
                        centery = (RoiStarty + RoiEndy )/2;
                        sumupper = 0.0;
                        sumdownleft = 0.0;
                        sumdownright = 0.0;

                        for(  int y = 0 ; y < RoiSizeY ; y++ ){
                                for( int x = 0 ; x < RoiSizeX ; x++ ){
                                        p1 = (double)(roi[y*RoiSizeX+x]-roiave);
                                        p2 = (double)(dest[y*RoiSizeX+x]-destave);
                                        sumupper += p1*p2;
                                        sumdownleft += p1*p1;
                                        sumdownright += p2*p2;

                                }
                        }
                        sumdown = sqrt(sumdownleft)*sqrt(sumdownright);
                        sum = sumupper/sumdown;

                        horpos = 400*deltaindex/dlimit;

                        PaintBox2->Canvas->MoveTo(horpos,199);

                        PaintBox2->Canvas->LineTo(horpos,200-200*sum);
                         currx = (RoiStartx+RoiEndx)/2 + offsetx;
                         curry = (RoiStarty+RoiEndy)/2 + offsety;
                        if( sum > maxcorr ){
                                maxcorr = sum;
                                maxposx = currx;
                                maxposy = curry;
                                maxofx = offsetx;
                                maxofy = offsety;
                                maxindex = deltaindex;

                        }

                        results[curry*iw+currx] = sum;
                        if( sum < 0.0 )
                                sum *= -1.0;

                        if( avimode )
                                brframe[curry*iw+currx] = (Byte)(255*sum);
                        else
                                rframe[curry*iw+currx] = (Word)(255*sum);

                        free(dest);

                }
                interpolate(maxposx,maxposy);
//                Image2->Canvas->MoveTo(maxposx-2,maxposy);
//                Image2->Canvas->LineTo(maxposx+2,maxposy);
//                Image2->Canvas->MoveTo(maxposx,maxposy-2);
//                Image2->Canvas->LineTo(maxposx,maxposy+2);


                //sprintf(obuf,"max correlation is %g at %d,%d:%d\n\n",maxcorr,maxofx,maxofy,maxindex);
                //Memo1->Lines->Add(obuf);
                //sprintf(obuf,"offset comp. is %g,%g",ox,oy);
                //Memo1->Lines->Add(obuf);
                //ShowMessage("kick outs");
                //sprintf(obuf,"Object Motion is (%d,%d) -> (%g,%g)",centerx,centery,maxposx+ox,maxposy+oy);
                //Memo1->Lines->Add(obuf) ;
                //sprintf(obuf,"Object Displacement between fr %d->%d  is %g,%g",current,current+1,maxposx+ox-centerx,maxposy+oy-centery);
                // Memo1->Lines->Add(obuf) ;

                setdestbuf(maxofx,maxofy);
                disparea(RoiSizeX,0,dest);
                //ShowMessage("source area and deteced area");

                //Form2->dispwhole((Word *)rframe);

                //ShowMessage("Update for next run");
                Image3->Canvas->LineTo(maxposx,maxposy);

                Image3->Refresh();

                current++;
                RoiStartx += maxofx;
                RoiEndx += maxofx;

                RoiStarty += maxofy;    // adjust for next frame
                RoiEndy += maxofy;

        }





}
//---------------------------------------------------------------------------

void __fastcall TForm1::SequentialClick(TObject *Sender)
{
          int     offsetx=0,offsety=0;
        int     horpos;
        int     centerx,centery;
        int     deltalimit = 1000;      // for non-linear analysis

        double   sum=0.0;
        double sumupper,sumdownleft,sumdownright,sumdown;
        double  p1,p2;
        double maxcorr = 0.0;
        int     maxposx,maxposy,currx,curry,maxofx,maxofy,maxindex;
        int     initx;
        int     inity;
        int     frameindex;

        LARGE_INTEGER   startTime,checkTime;

        char obuf[100];
        TImage* t;


        struct rois *roiptr;

        int     current = sourceframe;
        int     troi;

//        datacount = 0;
        if( igor || !VarIsEmpty(excel) )
                Button14->Visible = true;
        AddParms->Visible = true;
        tp->Visible = true;
        DelParms->Visible = true;

        
        if( other )
                t = Form2->Image1;
        else
                t = Image1;

        currbit = t;    // for avi write afterwards
        writelength = destframe - current + 1;

        Image3->Canvas->Brush->Color = Form1->Color; // back ground is clBtnFace
        Image3->Canvas->FillRect(Rect(0,0,359,259));


        // checking roi change now

		laststart = sourceframe;
        lastend = destframe;

        QueryPerformanceCounter(&startTime);

        while( current < destframe ){

           for( troi = 0 ; troi < roiset->Count ; troi++ ){

                roiptr = (rois *)roiset->Items[troi];

                // set globals

                RoiStartx = roiptr->startx;
                RoiEndx = roiptr->endx;
                RoiStarty = roiptr->starty;
                RoiEndy = roiptr->endy;
                RoiSizeX = roiptr->sizex;
                RoiSizeY = roiptr->sizey;



        initx = (RoiStartx + RoiEndx) /2;
        inity = (RoiStarty + RoiEndy) /2;


        if( current == sourceframe ){
                DispFrame(current);
                Edit1->Text = IntToStr(current);

                Memo1->Lines->Add("frameoffset,time,posx,posy,angle");
                Memo1->Lines->Add("0,0,0,0,0");
                oldoldx = oldoldy = 0;
                roiptr->oldx = 0;
                roiptr->oldy = 0;
                roiptr->oldangle = 0.0;
                roiptr->datacount = 0;
        }
        if( roiptr->oldangle == 0.0 ){
                  setroibuf();
                disparea(0,0,roi);
        }
        else {
                showrotation(initx,inity,roiptr->oldangle,SRC);
                if( CheckBox2->Checked == true ){
                        disparea(RoiSizeX*2,0,rdest);
                        Image3->Refresh();
                }

        }



               PaintBox2->Canvas->FillRect(Rect(0,0,399,199));

                DispFrame2(current+1);
                Edit4->Text = IntToStr(current);

                if( other ){
                        Form2->Image1->Refresh();
                        Form3->Image1->Refresh();
                }
                else {
                        Image1->Refresh();
                        Image2->Refresh();
                }
                
                maxcorr = 0.0;
                //offsetx = oldoldx;
                //offsety = oldoldy;  // poof!
                offsetx = roiptr->oldx;
                offsety = roiptr->oldy;
                oldangle = roiptr->oldangle;

                if( linearmode )
                        deltalimit = StrToInt(Edit11->Text);
                else
                        deltalimit = 1000;

                for( int deltaindex = 0 ; deltaindex < deltalimit ; deltaindex++ ){  // short search for one frame interval
                        if( linearmode ){
                                if( horiz )
                                        offsetx += 1;
                                else
                                        offsety += 1;

                        }
                        else {
                                offsetx += dx[deltaindex];
                                offsety += dy[deltaindex];
                        }

                        if( RoiStartx + offsetx < 0 || RoiEndx + offsetx > iw )
                                continue;
                        if( RoiStarty + offsety < 0 || RoiEndy + offsety > ih )
                                continue;

                        sum = 0.0;


                        setdestbuf(offsetx,offsety);


                        //centerx = (RoiStartx + RoiEndx )/2;
                        //centery = (RoiStarty + RoiEndy )/2;
                        sumupper = 0.0;
                        sumdownleft = 0.0;
                        sumdownright = 0.0;

                        for(  int y = 0 ; y < RoiSizeY ; y++ ){
                                for( int x = 0 ; x < RoiSizeX ; x++ ){

                                        if( roiptr->oldangle == 0.0 )
                                                p1 = (double)(roi[y*RoiSizeX+x]-roiave);
                                        else
                                                p1 =  (double)(rdest[y*RoiSizeX+x]-rdestave);

                                        p2 = (double)(dest[y*RoiSizeX+x]-destave);

                                        sumupper += p1*p2;
                                        sumdownleft += p1*p1;
                                        sumdownright += p2*p2;

                                }
                        }
						sumdown = sqrt(sumdownleft)*sqrt(sumdownright);
						if( sumdown == 0.0 )
							sum = 0.0;
						else
							sum = sumupper/sumdown;

                        horpos = 400*deltaindex/deltalimit;

                        PaintBox2->Canvas->MoveTo(horpos,199);

                        PaintBox2->Canvas->LineTo(horpos,200-200*sum);
                        
                        currx = (RoiStartx+RoiEndx)/2 + offsetx;
                        curry = (RoiStarty+RoiEndy)/2 + offsety;

                        if( sum > maxcorr ){
                                maxcorr = sum;
                                maxposx = currx;
                                maxposy = curry;
                                maxofx = offsetx;
                                maxofy = offsety;
                                maxindex = deltaindex;

                        }

                        results[curry*iw+currx] = sum;
                        if( sum < 0.0 )
                                sum *= -1.0;

                        if( avimode )
                                brframe[curry*iw+currx] = (Byte)(255*sum);
                        else
                                rframe[curry*iw+currx] = (Word)(255*sum);

                        free(dest);

                }

                //oldoldx = maxofx;
                //oldoldy = maxofy;
                roiptr->oldx = maxofx;
                roiptr->oldy = maxofy;


                setdestbuf(maxofx,maxofy);
                disparea(RoiSizeX,0,dest);

                interpolate(maxposx,maxposy);

                t->Canvas->MoveTo(maxposx-2,maxposy);
                t->Canvas->LineTo(maxposx+2,maxposy);
                t->Canvas->MoveTo(maxposx,maxposy-2);
                t->Canvas->LineTo(maxposx,maxposy+2);
                t->Canvas->Refresh();


                 if( CheckBox1->Checked == true && !linearmode ) {      // angle and not linear mode

                        double anglecorr = 0.0;

						for( double angle = roiptr->oldangle-20.0 ; angle < roiptr->oldangle+20.5 ; angle += anglestep ){

                                showrotation(initx,inity,angle,SRC);      // rotate 10.0 image at maxofx,maxofy in destbuf
                        // read rotated image into rdest
                           if( CheckBox2->Checked == true ){
                                disparea(0,0,rdest);
                                //Form2->disparea(RoiSizeX,0,dest);
                                Image3->Refresh();
                            }
                                sumupper = 0.0;
                                sumdownleft = 0.0;
                                sumdownright = 0.0;

                                for(  int y = 0 ; y < RoiSizeY ; y++ ){
                                        for( int x = 0 ; x < RoiSizeX ; x++ ){
                                                p1 = (double)(rdest[y*RoiSizeX+x]-rdestave);
                                                p2 = (double)(dest[y*RoiSizeX+x]-destave);
                                                sumupper += p1*p2;
                                                sumdownleft += p1*p1;
                                                sumdownright += p2*p2;

                                        }
                                }
								sumdown = sqrt(sumdownleft)*sqrt(sumdownright);
                                sum = sumupper/sumdown;

                                //sprintf(obuf,"%g\t%g\t%g",angle,sum,maxcorr);

                                //ShowMessage("hit");

                                if( sum > anglecorr ){
                                        //oldangle = angle;
                                        roiptr->oldangle = angle;
                                        anglecorr = sum;
                                }


                        }

                    //ShowMessage("hit");

                }
                 sprintf(obuf,"%d,%g,%g,%g,%g",current-sourceframe,(current-sourceframe)*frameinterval,maxposx+ox,maxposy+oy,roiptr->oldangle);
                 Memo1->Lines->Add(obuf);
                 roiptr->wtime[roiptr->datacount] = (current-sourceframe)*frameinterval;

                 if( spacefactor != 0.0 ){
                        maxposx *= spacefactor;
                        maxposy *= spacefactor;
                        ox *= spacefactor;
                        oy *= spacefactor;
                 }

                 //if(OriginLeftBottom->Checked){
                 //       maxposy = ih - maxposy;
                 //       oy = -1.0*oy;
                 //}
                 roiptr->posx[roiptr->datacount] = maxposx;
                 roiptr->posy[roiptr->datacount] = maxposy;
                 roiptr->cposx[roiptr->datacount] = maxposx+ox;
                 roiptr->cposy[roiptr->datacount] = maxposy+oy;
                 roiptr->angle[roiptr->datacount] = roiptr->oldangle;


                 roiptr->datacount++;
           }

           current++;

        }
        QueryPerformanceCounter(&checkTime);

// stats for distributed computation
        if( CheckBox12->Checked ){      // default for now

                 char hostname[80];
                double timeChange =  (double)(checkTime.QuadPart - startTime.QuadPart) / (double)timerFrequency.QuadPart;

               // float timeChange = ((unsigned long)checkTime.QuadPart - (unsigned long)startTime.QuadPart)*1000.0
 //    / ((unsigned long)timerFrequency.QuadPart);

               // timeChange /= 1000.0;
                gethostname(hostname,80);
	        sprintf(obuf,"[%s] elapsed time is %g\n",hostname,timeChange);
                Memo1->Lines->Add(obuf);

        struct rois *roiptr;

                sprintf(obuf,"number of roi is %d\n",roiset->Count );
                                Memo1->Lines->Add(obuf);
                for( int troi = 0 ; troi < roiset->Count ; troi++ ){

                        roiptr = (rois *)roiset->Items[troi];
                        sprintf(obuf,"%d,%d,%d,%d\n",roiptr->startx,roiptr->starty,roiptr->endx,roiptr->endy);
                        Memo1->Lines->Add(obuf);
                }

        }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
        spiral = true;
                
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
        spiral = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
		initangle = atof((const char *)Edit3->Text.c_str());
        //Memo1->Lines->Add("initangle set to"+AnsiString(initangle));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
        if( SaveDialog2->Execute()) {
                Memo1->Lines->SaveToFile(SaveDialog2->FileName);

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{
        if( RadioGroup2->ItemIndex == 0 )
                flip = false;
        else
                flip = true;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::disparea(int offsetx,int offsety,Word *p)
{
        TRect r1,r2;

        Image3->Picture->Bitmap->PixelFormat=pf24bit;
        Image3->Picture->Bitmap->Width = 312;
        Image3->Picture->Bitmap->Height = 260;

        //Image1->Canvas->Rectangle(0,0,RoiSizeX,RoiSizeY);

        //int     pattern = 0;

        Graphics::TBitmap *Bitmap1 = new Graphics::TBitmap();

        Bitmap1->PixelFormat = pf24bit;
        Bitmap1->Width = RoiSizeX;
        Bitmap1->Height = RoiSizeY;

        r1 = Rect(offsetx,offsety,offsetx+RoiSizeX,offsety+RoiSizeY);
        r2 = Rect(0,0,RoiSizeX,RoiSizeY);

        for( int row = 0 ; row < RoiSizeY ; row++ ){
                BYTE *scanPtr = (BYTE *)Bitmap1->ScanLine[row];
                for( int col = 0 ; col < RoiSizeX ; col++ ){
                        BYTE* tempPtr = scanPtr+col*3;
                        //BYTE val = (p[RoiSizeX*(RoiSizeY-row)+col]&0xff);
                        //BYTE val = (frame[312*(260-row)+col]&0xff);
                        //BYTE val = pattern++&0xff;
                        BYTE val = (BYTE)(*p++)&0xff;

                        if( shiftval < 0 )
                                val >>= (-shiftval);
                        else
                                val <<= shiftval;

                        tempPtr[0] = val;
                        tempPtr[1] = val;
                        tempPtr[2] = val;
                }
        }
        //Image1->Canvas->Draw(offsetx,offsety,Bitmap1);
        Image3->Canvas->CopyRect(r1,Bitmap1->Canvas,r2);

        Image3->Refresh();
        delete Bitmap1;
        
        // CopyRect
}

void __fastcall TForm1::dispwhole(void *p)
{

        Word *r;
        Byte *q;
        Byte val;
        TImage* out;


        if( other ){
                out = Form3->Image1;
        }
        else {
                out = Image3;
        }

        out->Picture->Bitmap->PixelFormat=pf24bit;
        out->Picture->Bitmap->Width = iw;
        out->Picture->Bitmap->Height = ih;

        if( avimode || still )
                q = (Byte *)p;
        else
                r = (Word *)p;

        //ShowMessage("offf is "+AnsiString(offf));

        for( int row = 0 ; row < ih ; row++ ){         // なんで固定だったん？（笑）
                BYTE *scanPtr = (BYTE *)out->Picture->Bitmap->ScanLine[row];
                for( int col = 0 ; col < iw ; col++ ){
                        BYTE* tempPtr = scanPtr+col*3;  // 24bit 固定
                        //BYTE val = (p[RoiSizeX*(RoiSizeY-row)+col]&0xff);
                        //BYTE val = (frame[312*(260-row)+col]&0xff);
                        //BYTE val = pattern++&0xff;
                        //BYTE val = (BYTE)(*p++)&0xff;

                        if( avimode || still )
                                val = *q++;
                        else
                                val = (Byte)(*r++)&0xff;
                        

                        if( shiftval < 0 )
                                val >>= (-shiftval);
                        else
                                val <<= shiftval;

                        tempPtr[0] = val;
                        tempPtr[1] = val;
                        tempPtr[2] = val;
                }
        }

        out->Refresh();

        // CopyRect
}

void __fastcall TForm1::setdata(char *name,double *p,int num)
{

		AnsiString senddata;
        AnsiString dname("WAVE:");

        char *r;
        char ooo[40];


        if( RadioButton3->Checked ){    //excel dtoa
                //ShowMessage("excel data porting "+AnsiString(name));
             //if( VarIsEmpty(WorkSheet)) {
			 //if( !VarIsEmpty(excel))
             //   WorkBooks  = excel.Exec( PropertyGet("Workbooks") );
             //   WorkBook  = WorkBooks.Exec( Function("Add"));
             //   WorkSheets = WorkBook.Exec( PropertyGet("WorkSheets") );
             //WorkSheet  = WorkSheets.Exec( PropertyGet("Item") << "Sheet1" );
             //   col = 1;

             //}
			 for( int row = 1 ; row < num+2 ; row++ ){
						//WorkCell  = WorkSheet.Exec( PropertyGet("Cells") << Variant(row)<< Variant(col) );
						WorkCell = WorkSheet.OlePropertyGet("Cells",Variant(row),Variant(col));
                        if( row == 1 ){
                                if( !stricmp(name,"wtime") )
										//WorkCell.Exec(PropertySet("Value")<< Variant(""));  // why not?
										WorkCell.OlePropertySet("Value",WSP(""));
                                else
										//WorkCell.Exec(PropertySet("Value")<< Variant(AnsiString(name)));
										WorkCell.OlePropertySet("Value",WSP(name));
                        }
						else {
                                sprintf(ooo,"%g",*p++);

								//WorkCell.Exec( PropertySet("Value") << Variant(AnsiString(ooo)) );
								WorkCell.OlePropertySet("Value",WSP(ooo));
                        }

             }
             col++;



        }
		else {
        for( int i = 0 ; i < num ; i++ ){
				senddata += AnsiString(*p++);
				//senddata += UnicodeString(*p++);
				senddata += "\r\n";
		}

		  //DdeClientConv1->PokeData

	   if( !DdeClientConv1->PokeData(dname+name,(char *)senddata.c_str())){
#ifdef _DELPHI_STRING_UNICODE
		Application->MessageBox( L"エラーwave set", L"確認", MB_ICONWARNING );
#else
			  Application->MessageBox( "エラーwave set", "確認", MB_ICONWARNING );
#endif

      }
      r = DdeClientConv1->RequestData("STATUS:LASTERROR");
      }


}

double  datagetx(int index, int fr)
{
        double  data;
        struct aframe *t;
        struct apoint *d;
        struct rois *r;



        if( manualdata ){
                t = (struct aframe *)frames->Items[fr];
                d = (struct apoint *)((t->points)->Items[index]);
                data = d->x;
        }
        else {
                r = (struct rois *)roiset->Items[index];
                data = r->cposx[fr];
        }

        //ShowMessage("fr "+AnsiString(fr)+" data "+AnsiString(index)+" = "+AnsiString(data));
        return data;



}

double  datagety(int index,int fr)
{

        double  data;
        struct aframe *t;
        struct apoint *d;
        struct rois *r;



        if( manualdata ){
                t = (struct aframe *)frames->Items[fr];
                d = (struct apoint *)((t->points)->Items[index]);
                data =  d->y;
        }
        else {
                r = (struct rois *)roiset->Items[index];
                data =  r->cposy[fr];
        }
        //ShowMessage("fr "+AnsiString(fr)+" data "+AnsiString(index)+" = "+AnsiString(data));

        if( Form1->OriginLeftBottom->Checked  )
                data = ih - data;

        return data;


}

int     __fastcall getindex()
{
        int     ret;

        if( *charpos == '#' ){
                ret = (*++charpos - '0');
                ret *= 10;
                ret += (*++charpos - '0');
        }
        else
                ret = (*charpos - '0');
        charpos++;
        ret--;
        //ShowMessage("ret value is "+AnsiString(ret));
        return ret;
}


double __fastcall calc(char *format,int pos)
{
        char    t;
        int     index;
        double  p1x,p2x,p3x;
        double  p1y,p2y,p3y;
        double  val,val1,val2;



        t = format[0];  // OK
        charpos = format+1;

        switch(t){
                case 'O' :
                        //index = format[1]-0x31;
                        index = getindex();
                        p1x = datagetx(index,pos);
                        p1y = datagety(index,pos);
                        val = p1x*p1x + p1y*p1y;
                        val = sqrt(val);
                        break;
                case 'D' :
                        //index = format[1]-0x31;
                        index = getindex();
                        p1x = datagetx(index,pos);
                        p1y = datagety(index,pos);
                        //index = format[2]-0x31;
                        index = getindex();
                        p2x = datagetx(index,pos);
                        p2y = datagety(index,pos);

                        val = (p1x-p2x)*(p1x-p2x);
                        val += (p1y-p2y)*(p1y-p2y);
                        val = sqrt(val);
                        break;
                case 'A' :
                        //index = format[1]-0x31;
                        index = getindex();
                        p1x = datagetx(index,pos);
                        p1y = datagety(index,pos);
                        //index = format[2]-0x31;
                        index = getindex();
                        p2x = datagetx(index,pos);
                        p2y = datagety(index,pos);

                        val = atan2(p2y-p1y,p2x-p1x);

                        val *= (360.0/6.28);    // radian to degree
                        break;
                case 'T' :
                        
                        //index = format[1]-0x31;
                        index = getindex();
                        p1x = datagetx(index,pos);
                        p1y = datagety(index,pos);
                        //index = format[2]-0x31;
                                                index = getindex();

                        p2x = datagetx(index,pos);
                        p2y = datagety(index,pos);
                        //index = format[3]-0x31;
                                                index = getindex();

                        p3x = datagetx(index,pos);
                        p3y = datagety(index,pos);

                        val2 = atan2(p1y-p2y,p1x-p2x);
                        val2 *= (360.0/6.28);    // radian to degree

                        val1 = atan2(p3y-p2y,p3x-p2x);
                        val1 *= (360.0/6.28);    // radian to degree

                        val = val1- val2;
                        break;
        }
        return val;



}

void __fastcall TForm1::prepareigor(void)
{
   String PathName; //="D:\\Ig4\\Igor.exe"; FileGetAttr
   String PathName2; // for 64
   String target;

   if( !getenv("igor")){         // windows 7 ではユーザ環境変数の場合OK.　
		PathName = "C:\\Program Files\\WaveMetrics\\Igor Pro Folder\\Igor.exe"; // was "D:\\Ig4\\Igor.exe";
		PathName2 = "C:\\Program Files (x86)\\WaveMetrics\\Igor Pro Folder\\Igor.exe";
   }
   else
        PathName = getenv("igor");      // how to set in Xp ???
   //ShowMessage("pathname is "+AnsiString(PathName));


   if( FileExists(PathName) ){
		igor = true;
		RadioButton4->Visible = true;
		target = PathName;

   }
   else if( FileExists(PathName2) ){
		igor = true;
		RadioButton4->Visible = true;
		target = PathName2;

   }
   else {
        igor = false;
   }

   Form1->DdeClientConv1->ServiceApplication = "\"" + target + "\" /DDE";
   
   //if( !Form1->DdeClientConv1->SetLink( "Igor", "Igor") ){
   //     ShowMessage("Link not established");
   //     igor = false;
   //
   //}
   //else {
   //     igor = true;
   //}

}


void __fastcall parmsexport(void)
{
/*
        manualdata
        roiset->
*/
        double  *data,*now;
        int     datacount;


        if( manualdata )
                datacount =  frames->Count;

        else {
            struct rois *rr = (struct rois *)roiset->Items[0];
            datacount = rr->datacount;
        }

        data = (double *)malloc(sizeof(double)*datacount);
        if( !data ){
                ShowMessage("not enough core for parmsexport");
                return;
        }


        Form1->prepareigor();

        if( Form1->RadioButton3->Checked )
				excel.OlePropertySet("Visible",true);

        for( int i = 0 ; i < parmset->Count ; i++ ){
                now = data;
                for( int j = 0 ; j < datacount ; j++ ){
                        *now++ = calc(((struct aparm *)parmset->Items[i])->name,j);
                }
                Form1->setdata(((struct aparm *)parmset->Items[i])->name,data,datacount);
        }






}

void __fastcall dumpmanualdata(void)
{

        char    oname[100];
        int     i,j;
        double  *curr;
        double  *x,*y;
        double  factor = 1.0;


        double  *key = (double *)malloc(sizeof(double)*frames->Count);    // time in abs?

		if( doubled )
                factor /= 2.0;

        if( spacefactor != 0.0 )
                factor *= spacefactor;
        

        
        struct aframe *tempf;

        // at first memory allocation for data

        tempf = (struct aframe *)frames->Items[0];       // sampling


        int     datacount = tempf->points->Count;

        //ShowMessage("data count is "+AnsiString(datacount)+" Frame count is "+AnsiString(frames->Count));


        for( j = 0 ; j < frames->Count ; j++ )
                key[j] = ((struct aframe *)frames->Items[j])->framenumber;

        for( j = 0 ; j < datacount*2 ; j++ ){
                curr = (double *)malloc(sizeof(double)*frames->Count);
                if( !curr ){
                        ShowMessage("core insufficient");
                        return;
                }
                ddset[j] = curr;
        }

        // assign elements value to allocated buffer
        // frame, data1-x data1-y data2-x data2-y .....

        for( i = 0 ; i < datacount ; i++ ) {
                x = ddset[i*2];
                y = ddset[i*2+1];
                for( j = 0 ; j < frames->Count ; j++ ) {
                        tempf = (struct aframe *)frames->Items[j];
                        *x++ = ((struct apoint *)tempf->points->Items[i])->x*factor;
                        *y++ = ((struct apoint *)tempf->points->Items[i])->y*factor;
                }
        }
  if( Form1->RadioButton4->Checked )  { // Igor selected
    if( Form1->DdeClientConv1->SetLink( "Igor", "Igor") ){
        Form1->setdata("wtime",key,frames->Count);
        for( i = 0 ; i < datacount ; i++ ) {
                x = ddset[i*2];
                y = ddset[i*2+1];

                sprintf(oname,"data%d.X",i);

                 Form1->setdata(oname,x,frames->Count);

                sprintf(oname,"data%d.Y",i);

                 Form1->setdata(oname,y,frames->Count);

        }
    }
  }
  else {


  }



/*
        for(  i = 0 ; i < frames->Count ; i++ ){
                tempf = (struct aframe *)frames->Items[i];
                temp = tempf->points;
                Form1->Memo1->Lines->Add("frame "+AnsiString(tempf->framenumber));
                for( int k = 0 ; k < temp->Count ; k ++ ){
                        struct apoint *t = (struct apoint *)temp->Items[k];
                        Form1->Memo1->Lines->Add(" point "+AnsiString(k)+" x "+AnsiString(t->x)+" y "+AnsiString(t->y));
                }
        }
*/


}

//      GetEnv



void __fastcall TForm1::DoItByExcel(void)
{
        String Cmd;
        int     datacount;
        struct rois *rr;
          char *r;
        int   leading = false;
        int   marker;
        char  temp[100];

      char      hparms[300]="";
      char     cbuf[300]="";
        char targetparms[200] = "[X Display ";
        char    modstr[200]="Legend;";


        col = 1;
  //              WorkBooks  = excel.Exec( PropertyGet("Workbooks") );
  //              WorkBook  = WorkBooks.Exec( Function("Add"));
  //              WorkSheets = WorkBook.Exec( PropertyGet("WorkSheets") );
  //              WorkSheet  = WorkSheets.Exec( PropertyGet("Item") << "Sheet1" );
					WorkBooks = excel.OlePropertyGet("Workbooks");
					WorkBook = WorkBooks.OleFunction("Add");
					WorkSheets = WorkBook.OlePropertyGet("WorkSheets");
					WorkSheet = WorkSheets.OlePropertyGet("Item",WSP("Sheet1"));

		if( parmset && parmset->Count > 0 ){
                parmsexport();
                return;
        }

        if( manualdata ){
                dumpmanualdata();
                return;
        }



    rr = (struct rois *)roiset->Items[StrToInt(Edit8->Text)];

    wtime = rr->wtime;
    posx = rr->posx;
    posy = rr->posy;
    cposx = rr->cposx;
    cposy = rr->cposy;
    angle = rr->angle;
    datacount = rr->datacount;



    if(CheckBox8->Checked)
        marker = true;
    else
        marker = false;




       if( CheckBox9->Checked ){ // all data should be exported but not display?


		setdata("WTime",wtime,datacount);

        if(CheckBox3->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"PositionX%d",i);
                        setdata(temp,rr->posx,rr->datacount);
                }

        }

        if(CheckBox4->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"PositionY%d",i);
                        setdata(temp,rr->posy,rr->datacount);
                }

        }

      if(CheckBox5->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"CompensatedX%d",i);
                        setdata(temp,rr->cposx,rr->datacount);
                }

      }


      if(CheckBox6->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"CompensatedY%d",i);
                        setdata(temp,rr->cposy,rr->datacount);
                }


      }

      if(CheckBox7->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"Angle%d",i);
                        setdata(temp,rr->angle,rr->datacount);
                }


      }

    //  time axis is just one
      }
      else {
      setdata("WTime",wtime,datacount);

      if(CheckBox3->Checked){
        setdata("PositionX",posx,datacount);
        strcat(targetparms,"PositionX");
        leading = true;

      }

      if(CheckBox4->Checked){
        setdata("PositionY",posy,datacount);
        if(leading)
                strcat(targetparms,",");
        else
                leading = true;

        strcat(targetparms,"PositionY");
        strcat(modstr,"ModifyGraph rgb(PositionY)=(0,0,52224);");


      }

      if(CheckBox5->Checked){
        setdata("CompensatedX",cposx,datacount);
        if(leading)
                strcat(targetparms,",");
        else
                leading = true;
        strcat(targetparms,"CompensatedX");
        strcat(modstr,"ModifyGraph rgb(CompensatedX)=(0,39168,0);");

      }


      if(CheckBox6->Checked){
        setdata("CompensatedY",cposy,datacount);
        if(leading)
                strcat(targetparms,",");
        else
                leading = true;
        strcat(targetparms,"CompensatedY");
        strcat(modstr,"ModifyGraph rgb(CompensatedY)=(39168,0,15616);");


      }

      if(CheckBox7->Checked){
        setdata("Angle",angle,datacount);
        if(leading)
                strcat(targetparms,",");
        else
                leading = true;
        strcat(targetparms,"Angle");
        strcat(modstr,"ModifyGraph rgb(Angle)=(13056,0,0);");

      }

      }

      switch(RadioGroup3->ItemIndex){
        case 0:
                strcat(hparms," vs WTime;Label bottom \"Time\"");
                break;
        case 1:
                strcat(hparms," vs PositionX;Label bottom \"Position X\"");
                setdata("PositionX",posx,datacount);
                break;
        case 2:
                strcat(hparms," vs PositionY;Label bottom \"Position Y\"");
                setdata("PositionY",posy,datacount);
                break;
      }

      strcat(targetparms,hparms);
      strcat(targetparms,";Label left \"Position\";");  // set other command here if you want to

  if(!CheckBox9->Checked) {     // PLOT IT!!!! if you can
        char    range[30];

		sprintf(range,"A1:%c%d",'A'+col-2,datacount+1);
        //Ranges =  WorkSheet.Exec(PropertyGet("Range")<<"A1:C5");        // should be fixed
		//Ranges =  WorkSheet.Exec(PropertyGet("Range")<<Variant(AnsiString(range)));        // should be fixed
		Ranges = WorkSheet.OlePropertyGet("Range",WSP(range));
		//Range = Ranges.Exec(Function("Select"));
		Range = Ranges.OleFunction("Select");
		//Charts = WorkBook.Exec(PropertyGet("Charts"));
		Charts = WorkBook.OlePropertyGet("Charts");
		//Chart = Charts.Exec(Function("Add"));
		Chart = Charts.OleFunction("Add");
                //Chart.Exec(PropertySet("ChartType")<<Variant(4));
		if(marker)
				//Chart.Exec(PropertySet("ChartType")<<Variant(65));       // poof xlLine marker
				Chart.OlePropertySet("ChartType",WSP("65"));
        else
				//Chart.Exec(PropertySet("ChartType")<<Variant(4));
				Chart.OlePropertySet("ChartType",WSP("4"));

		//Chart.Exec(PropertySet("HasTitle")<<(Variant)true);
		Chart.OlePropertySet("HasTitle",true);
		//((Chart.Exec(PropertyGet("ChartTitle")).Exec(PropertyGet("Characters")).Exec(PropertySet("Text")<<Variant("Position vs Time"))));
		(Chart.OlePropertyGet("ChartTitle").OlePropertyGet("Characters")).OlePropertySet("Text",WSP("Position vs Time"));
		//XAxis = Chart.Exec(PropertyGet("Axes")<<Variant(1)<<Variant(1));        // Category primary
		//YAxis = Chart.Exec(PropertyGet("Axes")<<Variant(2)<<Variant(1));        // Value primary
		XAxis = Chart.OlePropertyGet("Axes",WSP("1"),WSP("1"));
		YAxis = Chart.OlePropertyGet("Axes",WSP("2"),WSP("1"));

		//XAxis.Exec(PropertySet("HasTitle")<<(Variant)true );
		//YAxis.Exec(PropertySet("HasTitle")<<(Variant)true );
		XAxis.OlePropertySet("HasTitle",true);
		YAxis.OlePropertySet("HasTitle",true);
		//(XAxis.Exec(PropertyGet("AxisTitle"))).Exec(PropertyGet("Characters")).Exec(PropertySet("Text")<<Variant("Time"));
		//(YAxis.Exec(PropertyGet("AxisTitle"))).Exec(PropertyGet("Characters")).Exec(PropertySet("Text")<<Variant("Position"));
		//XAxis.Exec(PropertySet("TickLabelSpacing")<<Variant(5));
		//XAxis.Exec(PropertySet("TickMarkSpacing")<<Variant(5));
		(XAxis.OlePropertyGet("AxisTitle").OlePropertyGet("Characters")).OlePropertySet("Text",WSP("Time"));
		(YAxis.OlePropertyGet("AxisTitle").OlePropertyGet("Characters")).OlePropertySet("Text",WSP("Position"));
		XAxis.OlePropertySet("TickLabelSpacing",5);
		XAxis.OlePropertySet("TickMarkSpacing",5);

  }
  //excel.Exec(PropertySet("Visible")<<(Variant)true);
  excel.OlePropertySet("Visible",true);
/*

perl example

$range = $worksheet->Range("A1:D2");
$range->Select();
$chart = $workbook->Charts->Add;
# ワークブックをセーブして、閉じる。
$workbook->SaveAs("C:\\TEMP\\TEST.XLS");
$workbook->Close();
# アプリケーションを終了する。
$application->Quit();

               WorkBooks  = excel.Exec( PropertyGet("Workbooks") );
                WorkBook  = WorkBooks.Exec( Function("Add"));
                WorkSheets = WorkBook.Exec( PropertyGet("WorkSheets") );
                WorkSheet  = WorkSheets.Exec( PropertyGet("Item") << "Sheet1" );

*/


}


void __fastcall TForm1::Button14Click(TObject *Sender)
{
  String Cmd,Cmd2;
  String PathName; //="D:\\Ig4\\Igor.exe";
  char *r;
  int   leading = false;
  int   marker;
  char  temp[100];

      char      hparms[300]="";
      char     cbuf[300]="";
        char targetparms[200] = "[X Display ";
        char    modstr[200]="Legend;";
        int     datacount;
        struct rois *rr;



        if(  RadioButton3->Checked ){   // let execl draw graphs
                DoItByExcel();
                return;
        }
         //ShowMessage("Igor should be run");
// data selection based on Roi# Edit8->Text

        if( parmset && parmset->Count > 0 ){
                Form1->DdeClientConv1->SetLink( "Igor", "Igor");
                parmsexport();
                return;
        }

        if( manualdata ){
                dumpmanualdata();
                return;
        }


    rr = (struct rois *)roiset->Items[StrToInt(Edit8->Text)];

    wtime = rr->wtime;
    posx = rr->posx;
    posy = rr->posy;
    cposx = rr->cposx;
    cposy = rr->cposy;
    angle = rr->angle;
    datacount = rr->datacount;



    if(CheckBox8->Checked)
        marker = true;
    else
        marker = false;


    //if( !getenv("igor"))
    //    PathName = "D:\\Ig4\\Igor.exe";
    //else
    //    PathName = getenv("igor");      // how to set in Xp ???

    Cmd = "[X DoWindow/F Graph0;]";
    Cmd2 = "[X Display WX,WY vs WTime;Label left \"Vertical\";Label bottom \"Time\";Legend ;]";

    if(marker)
        strcat(modstr,"ModifyGraph mode=4;");


    //DdeClientConv1->ServiceApplication = "\"" + PathName + "\" /DDE";
    if( DdeClientConv1->SetLink( "Igor", "Igor") ){

       if( CheckBox9->Checked ){ // all data should be exported but not display?


        setdata("WTime",wtime,datacount);

        if(CheckBox3->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"PositionX%d",i);
                        setdata(temp,rr->posx,rr->datacount);
                }

        }

        if(CheckBox4->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"PositionY%d",i);
                        setdata(temp,rr->posy,rr->datacount);
                }

        }

      if(CheckBox5->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"CompensatedX%d",i);
                        setdata(temp,rr->cposx,rr->datacount);
                }

      }


      if(CheckBox6->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"CompensatedY%d",i);
                        setdata(temp,rr->cposy,rr->datacount);
                }


      }

      if(CheckBox7->Checked){
                for( int i = 0 ; i < roiset->Count ; i++ ){
                        rr = (struct rois *)roiset->Items[i];
                        sprintf(temp,"Angle%d",i);
                        setdata(temp,rr->angle,rr->datacount);
                }


      }






    //  time axis is just one
      }
      else {
      setdata("WTime",wtime,datacount);

      if(CheckBox3->Checked){
        setdata("PositionX",posx,datacount);
        strcat(targetparms,"PositionX");
        leading = true;

      }

      if(CheckBox4->Checked){
        setdata("PositionY",posy,datacount);
        if(leading)
                strcat(targetparms,",");
        else
                leading = true;

        strcat(targetparms,"PositionY");
        strcat(modstr,"ModifyGraph rgb(PositionY)=(0,0,52224);");


      }

      if(CheckBox5->Checked){
        setdata("CompensatedX",cposx,datacount);
        if(leading)
                strcat(targetparms,",");
        else
                leading = true;
        strcat(targetparms,"CompensatedX");
        strcat(modstr,"ModifyGraph rgb(CompensatedX)=(0,39168,0);");

      }


      if(CheckBox6->Checked){
        setdata("CompensatedY",cposy,datacount);
        if(leading)
                strcat(targetparms,",");
        else
                leading = true;
        strcat(targetparms,"CompensatedY");
        strcat(modstr,"ModifyGraph rgb(CompensatedY)=(39168,0,15616);");


      }

      if(CheckBox7->Checked){
        setdata("Angle",angle,datacount);
        if(leading)
                strcat(targetparms,",");
        else
                leading = true;
        strcat(targetparms,"Angle");
        strcat(modstr,"ModifyGraph rgb(Angle)=(13056,0,0);");

      }

      }

      switch(RadioGroup3->ItemIndex){
        case 0:
                strcat(hparms," vs WTime;Label bottom \"Time\"");
                break;
        case 1:
                strcat(hparms," vs PositionX;Label bottom \"Position X\"");
                setdata("PositionX",posx,datacount);
                break;
        case 2:
                strcat(hparms," vs PositionY;Label bottom \"Position Y\"");
				setdata("PositionY",posy,datacount);
                break;
      }

      strcat(targetparms,hparms);
      strcat(targetparms,";Label left \"Position\";");  // set other command here if you want to

  if(!CheckBox9->Checked) {
	  if( !DdeClientConv1->ExecuteMacro( (char *)Cmd.c_str(), false )){
#ifdef _DELPHI_STRING_UNICODE
		Application->MessageBox( L"エラー", L"確認", MB_ICONWARNING );
#else
		Application->MessageBox( "エラー", "確認", MB_ICONWARNING );
#endif

	  }
      r = DdeClientConv1->RequestData("STATUS:LASTERROR");

	  if( !DdeClientConv1->ExecuteMacro( targetparms, false )){
	  #ifdef _DELPHI_STRING_UNICODE
		Application->MessageBox( L"エラー", L"確認", MB_ICONWARNING );
#else
		Application->MessageBox( "エラー", "確認", MB_ICONWARNING );
#endif

	  }
      r = DdeClientConv1->RequestData("STATUS:LASTERROR");

	  if( !DdeClientConv1->ExecuteMacro( modstr, false )){
	  #ifdef _DELPHI_STRING_UNICODE
		Application->MessageBox( L"エラー", L"確認", MB_ICONWARNING );
#else
		Application->MessageBox( "エラー", "確認", MB_ICONWARNING );
#endif

	  }
      r = DdeClientConv1->RequestData("STATUS:LASTERROR");

        }

    }
    else
        ShowMessage("Can't find Igor.exe");

    //DdeClientConv1->CloseLink();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
        Graphics::TBitmap* Bitmap = new Graphics::TBitmap();

        if( SaveDialog3->Execute()) {
                //Image1->Picture->Bitmap->SaveToFile(SaveDialog3->FileName);



                Bitmap->Width = ClientWidth;
                Bitmap->Height = ClientHeight;

                Bitmap->Canvas->CopyRect(ClientRect,Canvas,ClientRect);

                TJPEGImage *JpegImage = new TJPEGImage();
                JpegImage->Assign(Bitmap);
                // JpegImage->CompressionQuality = 100;
                JpegImage->SaveToFile(SaveDialog3->FileName);


                delete JpegImage;
                delete Bitmap;
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Exit(TObject *Sender)
{
	frameinterval = atof((const char *)Edit6->Text.c_str());
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SmallSource1Click(TObject *Sender)
{
        Button6->Caption = "Small Source";
        whichimage = Image1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SmallDest1Click(TObject *Sender)
{
        Button6->Caption = "Small Dest.";
        whichimage = Image2;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::LargeSource1Click(TObject *Sender)
{
        Button6->Caption = "Large Source";
        whichimage = Form2->Image1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::LargeDest1Click(TObject *Sender)
{
        Button6->Caption = "Large Dest.";
        whichimage = Form3->Image1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit7Exit(TObject *Sender)
{
        targetroi = StrToInt(Edit7->Text);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
        struct rois *q;

        if( targetroi < roiset->Count ){
                q = (rois *)roiset->Items[targetroi];
                free(q->wtime);
                free(q->posx);
                free(q->posy);
                free(q->cposx);
                free(q->cposy);
                free(q->angle);
                roiset->Delete(targetroi);
                delete q;
                if( roiset->Count > 0 ){
                        Edit7->Text = AnsiString(roiset->Count -1 );
                        Form4->Edit7->Text = Edit7->Text;
                }
        }
        disprois();


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button17Click(TObject *Sender)
{

#define BORDER 3

		int     index = 0;
		int     start,end;
		int     backup;
		double  data;
		struct aframe *t,*temp;
		struct apoint *d;
		AnsiString kicks;


		start = laststart; //StrToInt(Edit1->Text);
		end = lastend;  //StrToInt(Edit4->Text);

		if( other )
				currbit = Form2->Image1;
		else
				currbit = Image1;

//        currbit = t;    // for avi write afterwards

		if( doubled ){
				ShowMessage("Please undouble screen size");
				return;
		}


		backup = currbit->Canvas->Pen->Color;

		currbit->Canvas->Pen->Color = clRed;

		if(SaveDialog4->Execute()){

				kicks = SaveDialog4->FileName; // for unicodestring handling

				AVIWritePrepare(currbit->Picture->Bitmap->Width,currbit->Picture->Bitmap->Height,writelength,kicks.c_str());
				if( other )
						Form2->Show();
				for( int fr = start ; fr < end ; fr++ ){
						DispFrame(fr+1);

						if( manualdata ){
								t = (struct aframe *)frames->Items[fr-start];

								if( Trace->Checked ){
										for( int tt = 0 ; tt <= fr -start ; tt++ ){
												temp = (struct aframe *)frames->Items[tt];
												for( int point = 0 ; point < temp->points->Count ; point++ ){
														d = (struct apoint *)((temp->points)->Items[point]);
														NotchPoint(currbit,d->x,d->y);
												}
										}
								}
								else
										for( int point = 0 ; point < t->points->Count ; point++ ){
												d = (struct apoint *)((t->points)->Items[point]);
												NotchPoint(currbit,d->x,d->y);
										}
						}
						else {

						for( int ir = 0 ; ir < roiset->Count ; ir++ ){
								struct rois *temproi;
								currbit->Canvas->Pen->Color = colortable[ir];       // suitable
								if( Trace->Checked ){
										for( int tt = 0 ; tt <= fr - start ; tt++ ){
												temproi = (struct rois *)roiset->Items[ir];
												currbit->Canvas->MoveTo(temproi->posx[tt]-BORDER,temproi->posy[tt]);
												currbit->Canvas->LineTo(temproi->posx[tt]+BORDER,temproi->posy[tt]);
												currbit->Canvas->MoveTo(temproi->posx[tt],temproi->posy[tt]-BORDER);
												currbit->Canvas->LineTo(temproi->posx[tt],temproi->posy[tt]+BORDER);
										}
								}
								else {
										temproi = (struct rois *)roiset->Items[ir];
										currbit->Canvas->MoveTo(temproi->posx[fr]-BORDER,temproi->posy[fr]);
										currbit->Canvas->LineTo(temproi->posx[fr]+BORDER,temproi->posy[fr]);
										currbit->Canvas->MoveTo(temproi->posx[fr],temproi->posy[fr]-BORDER);
										currbit->Canvas->LineTo(temproi->posx[fr],temproi->posy[fr]+BORDER);
								}
						}
						}
						currbit->Refresh();

						AVIWriteaFrame(index++,(char *)(currbit->Picture->Bitmap->ScanLine[currbit->Height-1]));
						//ShowMessage(" ");
				}
				AVIWriteFinish();
		}

		currbit->Canvas->Pen->Color = backup;

}


//---------------------------------------------------------------------------

void __fastcall TForm1::Edit9Exit(TObject *Sender)
{
		corrthresh = atof((const char *)Edit9->Text.c_str());
		//ShowMessage("corrthresh is now "+AnsiString(corrthresh));

}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopClick(TObject *Sender)
{
		if(Timer1->Enabled)
				Timer1->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CalibrationClick(TObject *Sender)
{
		double  hor = abs(RoiEndx - RoiStartx);
        double  ver = abs(RoiEndy - RoiStarty);
        double dist = sqrt(hor*hor+ver*ver);

        Form5->Label1->Caption = AnsiString(hor);   // abs?
        Form5->Label2->Caption = AnsiString(ver);
        Form5->Label3->Caption = AnsiString(dist);


        Form5->Visible = true;
        Form5->Enabled = true;
                
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ManualClick(TObject *Sender)
{
        if( !manual ){
                manual = true;
                Manual->Caption = "Auto";
                Form4->Button2->Caption = "Auto";       // means if you push it switches to Auto i.e. current mode is Manual
                frames = new TList();   // for new manual sessions
                struct aframe *current = new struct aframe;
                currentpset = new TList();
                current->points = currentpset;
                current->framenumber = sourceframe;
                
                laststart = sourceframe;
                lastend = destframe;

                frames->Add(current);
        }
        else {
                manual = false;
                Manual->Caption = "Manual";
                Form4->Button2->Caption = "Manual";
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddParmsClick(TObject *Sender)
{
        ParmDialog->Visible = true;

        if( other )
                now = Form2->Image1;
        else
                now = Image1;

        if( newset ){   // prepare for menu
                for( int i = 0 ; i < parmpoints ; i++ ){
                        TMenuItem* temp = new TMenuItem(ParmDialog->PopupMenu2);
                        temp->Caption = AnsiString(i+1);
                        temp->OnClick = ParmDialog->APMnClick;

                        ParmDialog->PopupMenu2->Items->Add(temp);
                        // Visual feed back
                        
                }

                if( manualdata ){
                        struct aframe *ttt;
                        ttt = (struct aframe *)frames->Items[0];
                        DispFrame(ttt->framenumber);

                        now->Canvas->Pen->Color = clRed;
                        now->Canvas->Pen->Mode = pmCopy;

                        for( int i = 0 ; i < ttt->points->Count ; i++ ){
                                struct apoint *q;
                                q = (struct apoint *)ttt->points->Items[i];

                                now->Canvas->TextOutA(q->x,q->y,AnsiString(i+1));
                        }

                }

                newset = false;
                parms = 0;
                parmset = new TList();
        }
        //parms++;
        tp->Text=AnsiString(parms);
        ParmDialog->Label1->Caption = AnsiString("parm# ")+AnsiString(parms+1);
        ListParms->Visible = true;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::DelParmsClick(TObject *Sender)
{
        int     targetnum = StrToInt(tp->Text);

        if( targetnum > 0 && targetnum < parmset->Count )
                parmset->Delete(targetnum);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListParmsClick(TObject *Sender)
{
        struct aparm *tt;

        for( int i = 0 ; i < parmset->Count ; i++ ){
                tt = (struct aparm *)parmset->Items[i];
                Memo1->Lines->Add(AnsiString(i)+" "+AnsiString(tt->name));
        }
        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LoadSourceClick(TObject *Sender)
{
		Graphics::TBitmap *Bitmap = new Graphics::TBitmap();

        if( OpenDialog2->Execute()){
                sfilename = OpenDialog2->FileName;
                still = true;
        }
        else
                return;

        Bitmap->LoadFromFile(sfilename);

        iw = Bitmap->Width;
        ih = Bitmap->Height;

		if( iw != 312 || ih != 260 ){
                int     offset;
                
                                other = true;
                        Form2->Width = iw + 40;
                        Form2->Height = ih + 50;

                        Form2->Visible = true;
                        //Form2->Image1->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit
                        Form3->Width = iw + 40;
                        Form3->Height = ih + 50;
                        //Form3->Image1->Picture->Bitmap->PixelFormat=pf24bit;   // should be 8bit

                        offset = Screen->Width - Form2->Width - Form3->Width;

                        if( offset > 0 ) {
                                Form2->Left = offset/3;
                                Form3->Left = Form2->Left + Form2->Width + offset/3;
                                Form4->Left = Form2->Left;        // ?
                        }
                        else {
                                Form2->Left = 0;
                                Form3->Left = Form2->Width;
                                Form4->Left = Form2->Left;        // ?
                        }

                        offset = Screen->Height - Form2->Height - Form4->Height;
                        if( offset > 0 ) {
                                Form2->Top = offset/3;
                                Form3->Top = Form2->Top;
                                Form4->Top = Form2->Top + Form2->Height + offset/3;

                        }
                        else {
                                Form2->Top = 0;
                                Form3->Top = Form2->Top;
                                Form4->Top = Form2->Height;
                        }


                        Form3->Visible = true;
                        Form4->Visible = true;
        }
        else {
                          other = false;

                            Form2->Visible = false;
                Form3->Visible = false;
                Form4->Visible = false;



        }


        bsourceframebuf = (Byte *)malloc(iw*ih);
        if( !bsourceframebuf ){
                ShowMessage("not enough core for bsource frame buffer");
                exit(1);
        }

        bdestframebuf = (Byte *)malloc(iw*ih);
        if( !bdestframebuf ){
                ShowMessage("not enough core for source frame buffer");
                exit(1);
        }

        brframe = (Byte *)malloc(iw*ih);
        if( !brframe ){
                ShowMessage("not enough core for source frame buffer");
                exit(1);
        }

		//endframe = AVIImage1->Length;  // I'm not sure about these now. 2008-2-22
		//endframe = work->getlast();
		//results = (double *)malloc(iw*ih*sizeof(double));
                //ShowMessage("core for results buffer allocated");

		//if( !results ){
		//        ShowMessage("not enough core for results buffer");
       //         exit(1);
		//}
 		Button24->Enabled = true;
		RadioGroup5->Enabled = true;
		RadioButton6->Checked = true;
		Divisor->Text = "8";
		Shift->Text = "128";

		nottarget = 0;
        
        DispFrame(0);   // frame number 0 is dummy


}
//---------------------------------------------------------------------------

void __fastcall TForm1::LoadDestClick(TObject *Sender)
{
        if( OpenDialog2->Execute()){
                dfilename = OpenDialog2->FileName;
                still2 = true;
        }
        DispFrame2(0);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button18Click(TObject *Sender)
{
        sourceframe = 0;
        DispFrame(sourceframe);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
        if( !manual){
                displayed = true;
                sourceframe = endframe;
                DispFrame(sourceframe);
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
        destframe = 0;
        DispFrame2(destframe);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
        displayed = true;
        destframe = endframe;
        DispFrame2(destframe);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
        destframe = sourceframe;
        DispFrame2(destframe);
        displayed = 1;
        //Edit4->Text = Edit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit10Exit(TObject *Sender)
{
		 anglestep = atof((const char *)Edit10->Text.c_str());
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button23Click(TObject *Sender)
{
        //Form7->Visible = true;
        Form7->ActiveControl = Form7->Button1;
        if( Form7->ShowModal() == mrOk )
                Button12Click(Sender);       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DumpRoiClick(TObject *Sender)
{
/*
struct rois {
        int     startx,starty;
        int     endx,endy;
        int     sizex,sizey;
        int     oldx,oldy;
        double  oldangle;
        double  *wtime,*posx,*posy,*cposx,*cposy,*angle;
};

TList* roiset;

*/
        FILE    *roiout;
        struct rois *roiptr;


        if( SaveRoiDialog->Execute()) {
                roiout = fopen((const char *)SaveRoiDialog->FileName.c_str(),"w");
                if( !roiout ){
                        ShowMessage("can't open roi save file");
                        return;
                }
                for( int troi = 0 ; troi < roiset->Count ; troi++ ){

                        roiptr = (rois *)roiset->Items[troi];
                        fprintf(roiout,"%d,%d,%d,%d\n",roiptr->startx,roiptr->starty,roiptr->endx,roiptr->endy);
                }
                fclose(roiout);

        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::LoadRoiClick(TObject *Sender)
{
        AnsiString sfilename;
        int     count;
		int     sx,sy,ex,ey;
		char	first;

        if( LoadRoiDialog->Execute()){
                sfilename = LoadRoiDialog->FileName;
        }
        else
                return;

        auto_ptr<TStrings> file(new TStringList);
        file->LoadFromFile(sfilename);
        count = file->Count;    // line count

        //ShowMessage("line count is "+AnsiString(count));
        auto_ptr<TStrings> line(new TStringList);

        for(int j = 0 ; j < count ; j++ ){

                line->CommaText = file->Strings[j];

                //first = *(line->Strings[0].c_str());
                //pp = line->Strings[0].c_str()+1;
				//second = *(line->Strings[0].c_str()+1);

				first = *(line->Strings[0].c_str());
				if( first == '/' || first == '#' )
					continue;

                sx = StrToInt(line->Strings[0]);
                sy = StrToInt(line->Strings[1]);
                ex = StrToInt(line->Strings[2]);
                ey = StrToInt(line->Strings[3]);
                        RoiStartx = sx;
        RoiEndx = ex;
        RoiStarty = sy;
        RoiEndy = ey;

		RoiSizeX = ex - sx -1; 	// interpretation changed 2008-3-14
		RoiSizeY = ey - sy -1;



        if( CheckBox11->Checked )
                linearmode = true;
        else
                linearmode = false;

        if( !made ){
                maketable();
                made = true;
        }
        setroibuf();
        //Visible = true;
        Image3->Canvas->Brush->Color = Form1->Color; // back ground is clBtnFace
        Image3->Canvas->FillRect(Rect(0,0,311,259));


        disparea(0,0,roi);
        // first add new roi based on RoiStarx and etc.

        struct rois *ptr = new (struct rois);

        if( linearmode ){
                if( RoiEndx - RoiStartx > RoiEndy - RoiStarty ) {// horizontal draw
                        RoiEndy = RoiStarty;
                        horiz = true;
                        vert = false;
                }
                else {
                        RoiEndx = RoiStartx;
                        horiz = false;
                        vert = true;
                }

                Memo1->Lines->Add("width: "+AnsiString(RoiEndx-RoiStartx+1)+"height: "+AnsiString(RoiEndy-RoiStarty+1));
        }

        ptr->startx = RoiStartx;
        ptr->starty = RoiStarty;
        ptr->endx = RoiEndx;
        ptr->endy = RoiEndy;
        ptr->sizex = RoiSizeX;
        ptr->sizey = RoiSizeY;

        ptr->wtime = (double *)malloc(sizeof(double)*(endframe+1));
        ptr->posx =  (double *)malloc(sizeof(double)*(endframe+1));
        ptr->posy = (double *)malloc(sizeof(double)*(endframe+1));
        ptr->cposx = (double *)malloc(sizeof(double)*(endframe+1));
        ptr->cposy = (double *)malloc(sizeof(double)*(endframe+1));
        ptr->angle = (double *)malloc(sizeof(double)*(endframe+1));

        if( !ptr->wtime || !ptr->posx || !ptr->posy || !ptr->cposx || !ptr->cposy || !ptr->angle ){
                ShowMessage("not enough core for roi ");
                exit(1);
        }

        roiset->Add(ptr);


        //ShowMessage("This is selected ROI");
        //Button9->Enabled = true;

        if( roiset->Count == 1 ){
                Button9->Visible = true;
                Form4->Button9->Visible = true;

        //Button3->Enabled = true;
                Button3->Visible = true;

                Label7->Caption = AnsiString(dlimit);
                Label8->Caption = "1.0";
                Label5->Caption = "Correlation";
        }
		Edit7->Text = roiset->Count - 1;
		Form4->Edit7->Text = Edit7->Text;
		disprois();
		parmpoints = roiset->Count;



		}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton8Click(TObject *Sender)
{
	FilterWeight->Options = FilterWeight->Options<<goEditing;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
	FilterWeight->Cells[0][0] = "0";
	FilterWeight->Cells[0][1] = "-1";
	FilterWeight->Cells[0][2] = "0";
	FilterWeight->Cells[1][0] = "-1";
	FilterWeight->Cells[1][1] = "4";
	FilterWeight->Cells[1][2] = "-1";
	FilterWeight->Cells[2][0] = "0";
	FilterWeight->Cells[2][1] = "-1";
	FilterWeight->Cells[2][2] = "0";
	FilterWeight->Options = FilterWeight->Options>>goEditing;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
	FilterWeight->Cells[0][0] = "-1";
	FilterWeight->Cells[0][1] = "-1";
	FilterWeight->Cells[0][2] = "-1";
	FilterWeight->Cells[1][0] = "-1";
	FilterWeight->Cells[1][1] = "8";
	FilterWeight->Cells[1][2] = "-1";
	FilterWeight->Cells[2][0] = "-1";
	FilterWeight->Cells[2][1] = "-1";
	FilterWeight->Cells[2][2] = "-1";
	FilterWeight->Options = FilterWeight->Options>>goEditing;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton7Click(TObject *Sender)
{
	FilterWeight->Cells[0][0] = "1";
	FilterWeight->Cells[0][1] = "-2";
	FilterWeight->Cells[0][2] = "1";
	FilterWeight->Cells[1][0] = "-2";
	FilterWeight->Cells[1][1] = "4";
	FilterWeight->Cells[1][2] = "-2";
	FilterWeight->Cells[2][0] = "1";
	FilterWeight->Cells[2][1] = "-2";
	FilterWeight->Cells[2][2] = "1";
	FilterWeight->Options = FilterWeight->Options>>goEditing;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button24Click(TObject *Sender)
{
	int	weights[3][3];

	weights[0][0] = FilterWeight->Cells[0][0].ToInt();
	weights[0][1] = FilterWeight->Cells[0][1].ToInt();
	weights[0][2] = FilterWeight->Cells[0][2].ToInt();
	weights[1][0] = FilterWeight->Cells[1][0].ToInt();
	weights[1][1] = FilterWeight->Cells[1][1].ToInt();
	weights[1][2] = FilterWeight->Cells[1][2].ToInt();
	weights[2][0] = FilterWeight->Cells[2][0].ToInt();
	weights[2][1] = FilterWeight->Cells[2][1].ToInt();
	weights[2][2] = FilterWeight->Cells[2][2].ToInt();




// convert loop for src->dest xy double loop


	TImage* targeti;
	BYTE	val;
	BYTE*	mainp;
	Word*	alt;
	int	div,shift;

	int	convsum;


	if( other ) {
		targeti = Form3->Image1;
		LargeDest1->Enabled = true;
		mainp = bsourceframebuf;
	}
	else {
		targeti = Image2;
		SmallDest1->Enabled = true;
		alt =(Word *)sourceframebuf;

	}

	targeti->Picture->Bitmap->PixelFormat = pf24bit;

	if( other ) {
		targeti->Picture->Bitmap->Height = ih;
		targeti->Picture->Bitmap->Width = iw;
	}
	else {
		targeti->Picture->Bitmap->Height = Image1->Height;
		targeti->Picture->Bitmap->Width = Image1->Width;
	}
	targeti->Width = iw;
	targeti->Height = ih;

	div = Divisor->Text.ToInt();
	shift = Shift->Text.ToInt();

	for( int row = 0; row < ih ; row++ ){
		BYTE *scanPtr = (BYTE *)targeti->Picture->Bitmap->ScanLine[row];
		for( int col = 0; col < iw ; col++ ){
			BYTE *tempPtr = scanPtr+col*3;
			if( row == 0 || col == 0 || col == iw-1 ){
				val = 0;
			}
			else {
				mainp = (BYTE *)(bsourceframebuf+(iw*(row-1)-(iw-col)-1));

				// revertit substitute
				alt = (Word *)(sourceframebuf+(iw*(row-1)-(iw-col)-1));
				convsum = 0;
				for( int i = 0 ; i < 3 ; i++ ){
					for( int j = 0 ; j < 3 ; j++ ){
						if( other )
							convsum += (weights[i][j]*(*mainp++));
						else 
							convsum += (weights[i][j]*(*alt++));
					}
					mainp += (iw-2);
					alt += (iw-2);
				}
				convsum /= div;	// fix?
				val = convsum;
				val += shift;
			}
			tempPtr[0] = val;
			tempPtr[1] = val;
			tempPtr[2] = val;
		}
	}

	targeti->Refresh();
						

				


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button26Click(TObject *Sender)
{
		int     index = 0;
		int     start,end;
		int     backup;
		double  data;
		struct aframe *t,*temp;
		struct apoint *d;


		start = sourceframe;
		end = destframe;

		if( other )
				currbit = Form2->Image1;
		else
				currbit = Image1;

//        currbit = t;    // for avi write afterwards

		if( doubled ){
				ShowMessage("Please undouble screen size");
				return;
		}


 //		backup = currbit->Canvas->Pen->Color;

 //		currbit->Canvas->Pen->Color = clRed;

		if(SaveDialog4->Execute()){
				AVIWritePrepare(currbit->Picture->Bitmap->Width,currbit->Picture->Bitmap->Height,writelength,(char *)SaveDialog4->FileName.c_str());
				if( other )
						Form2->Show();
				for( int fr = start ; fr < end ; fr++ ){
						DispFrame(fr+1);

						currbit->Refresh();

						AVIWriteaFrame(index++,(char *)(currbit->Picture->Bitmap->ScanLine[currbit->Height-1]));
						//ShowMessage(" ");
				}
				AVIWriteFinish();
		}

 //		currbit->Canvas->Pen->Color = backup;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
	int	start,end,backup;
	
		backup = start = sourceframe;
		end = destframe;

		if( other )
				currbit = Form2->Image1;
		else
				currbit = Image1;

//        currbit = t;    // for avi write afterwards

		if( doubled ){
				ShowMessage("Please undouble screen size");
				return;
		}


 //		backup = currbit->Canvas->Pen->Color;

 //		currbit->Canvas->Pen->Color = clRed;

				if( other )
						Form2->Show();
				for( int fr = start ; fr < end ; fr++ ){
						DispFrame(fr+1);
						Sleep(playbackdelay*10);

						currbit->Refresh();

						//ShowMessage(" ");
				}

 //		currbit->Canvas->Pen->Color = backup;
		sourceframe = backup;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::PlayspeedChange(TObject *Sender)
{
	playbackdelay = Playspeed->Position;

	if(playbackdelay == 0 )
		playbackdelay = 1;
		
}
//---------------------------------------------------------------------------


