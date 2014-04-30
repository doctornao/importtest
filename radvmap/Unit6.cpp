//---------------------------------------------------------------------------

#include <vcl.h>
//#include <stdio.h>    ‚ ‚Ü‚è‚É‚à‘å‚°‚³‚È‚Ì‚Å....
#pragma hdrstop
#include "Unit1.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

struct apoint {
        int     x,y;
};

char* pos;

struct aframe {
        int     framenumber;
        TList* points;
};

TList* points;
int     color = 1;

extern TList* frames;

extern TImage* now;
//extern TList* points;
extern TList* parmset;
extern int parms;
extern int manualdata;
extern int parmpoints;

struct aparm {
        char name[10];
};

int     notplotted = true;

TParmDialog *ParmDialog;
//---------------------------------------------------------------------------
__fastcall TParmDialog::TParmDialog(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------AnsiString------------------------------------------------------

void __fastcall TParmDialog::PMnClick(TObject *Sender)
{
     Attribute->Caption = ((TMenuItem*)Sender)->Caption;

     if( Attribute->Caption == AnsiString("Dist from Origin")){
        P2->Enabled = false;
        P3->Enabled = false;
     }
     else if( Attribute->Caption == AnsiString("Distance")){
        P3->Enabled = false;
     }
     else if( Attribute->Caption == AnsiString("Angle bw 2p")){
        P3->Enabled = false;
     }
     else if( Attribute->Caption == AnsiString("Angle bw 3p")){

     }

}

void __fastcall TParmDialog::APMnClick(TObject *Sender)
{
        int     index;
        int     x,y;

        TButton* last = dynamic_cast<TButton*>(PopupMenu2->PopupComponent);
        last->Caption = ((TMenuItem*)(Sender))->Caption;
        index = StrToInt(((TMenuItem*)(Sender))->Caption);
        PopupMenu2->Items->Items[index-1]->Enabled = false;

   if( manualdata ){
        if( notplotted ){
                struct apoint *pp;
                pp = (struct apoint *)points->Items[index-1];
                now->Canvas->MoveTo(pp->x,pp->y);
                notplotted = false;
        }
        else {
                struct apoint *pp;
                pp = (struct apoint *)points->Items[index-1];
                now->Canvas->LineTo(pp->x,pp->y);
        }

        now->Refresh();
   }

}


void __fastcall TParmDialog::PopupMenu1Popup(TObject *Sender)
{
        P1->Enabled = true;
        P1->Caption = "P1";
        P2->Enabled = true;
        P2->Caption = "P2";
        P3->Enabled = true;
        P3->Caption = "P3";

        // all menu item enabled
        notplotted = true;

        if( manualdata ){
                struct aframe *curr;

                curr = (struct aframe *)frames->Items[0];
                points = curr->points;
        }

        for( int i = 0 ; i < PopupMenu2->Items->Count ; i++ ){
                TMenuItem* temp = PopupMenu2->Items->Items[i];
                temp->Enabled = true;
                //ShowMessage("menuitem recovered"+AnsiString(temp->Caption));
        }

}
//---------------------------------------------------------------------------

void __fastcall encodeap(TButton* p)
{

        int     index;

        index = StrToInt(p->Caption);

        if( index > 9 ){
                *pos++ = '#';   // delimiter
                *pos++ = (char)((index/10)+0x30);
                *pos++ = (char)((index % 10 )+0x30);
        }
        else
                *pos++ = (char)(index+0x30);

}

void __fastcall TParmDialog::OKClick(TObject *Sender)
{
        struct aparm *t = new struct aparm;
        int     number;

     pos = t->name;

     if( Attribute->Caption == AnsiString("Dist from Origin")){
        *pos++ = 'O';
        encodeap(P1);
        *pos = '\0';

     }
     else if( Attribute->Caption == AnsiString("Distance")){
        //t->name[0] = 'D';
       // t->name[1] = P1->Caption[1];
        //t->name[2] = P2->Caption[1];
        //t->name[3] = '\0';
        *pos++ = 'D';
        encodeap(P1);
        encodeap(P2);
        *pos = '\0';


     }
     else if( Attribute->Caption == AnsiString("Angle bw 2p")){
        //t->name[0] = 'A';
       // t->name[1] = P1->Caption[1];
        //t->name[2] = P2->Caption[1];
        //t->name[3] = '\0';

        *pos++ = 'A';
        encodeap(P1);
        encodeap(P2);
        *pos = '\0';

     }
     else if( Attribute->Caption == AnsiString("Angle bw 3p")){
        //t->name[0] = 'T';
        //t->name[1] = P1->Caption[1];
        //t->name[2] = P2->Caption[1];
        //t->name[3] = P3->Caption[1];
        //t->name[4] = '\0';

        *pos++ = 'T';
        encodeap(P1);
        encodeap(P2);
        encodeap(P3);
        *pos = '\0';
     }

     parmset->Add(t);
     Form1->Memo1->Lines->Add("parms added ["+AnsiString(t->name)+"]");
     parms++;
     Form1->tp->Text=AnsiString(parms);
     ParmDialog->Label1->Caption = AnsiString("parm# ")+AnsiString(parms);

     if( manualdata ){
        struct aframe *ttt;
        ttt = (struct aframe *)frames->Items[0];
        Form1->DispFrame(ttt->framenumber);
        for( int i = 0 ; i < ttt->points->Count ; i++ ){
                struct apoint *q;
                q = (struct apoint *)ttt->points->Items[i];

                now->Canvas->TextOutA(q->x,q->y,AnsiString(i+1));
        }
     }



}
//---------------------------------------------------------------------------

void __fastcall TParmDialog::CancelClick(TObject *Sender)
{
        ParmDialog->Close();

}
//---------------------------------------------------------------------------

