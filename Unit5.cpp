//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern int      RoiStartx,RoiEndx,RoiStarty,RoiEndy;
extern double   spacefactor;


TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::CancelClick(TObject *Sender)
{
        Form5->Close();

}
//---------------------------------------------------------------------------

void __fastcall TForm5::OKClick(TObject *Sender)
{
        double     left,right;

        if( !Edit1->Text.IsEmpty() && ( right = Edit1->Text.ToDouble()) != 0.0 && (left = Label1->Caption.ToDouble()) != 0.0 )
                spacefactor = right/left;
        else if ( !Edit2->Text.IsEmpty() && ( right = Edit2->Text.ToDouble()) != 0.0 && (left = Label2->Caption.ToDouble()) != 0.0 )
                spacefactor = right/left;
        else if ( !Edit3->Text.IsEmpty() && ( right = Edit3->Text.ToDouble()) != 0.0 && (left = Label3->Caption.ToDouble()) != 0.0 )
                spacefactor = right/left;
        else {
                ShowMessage("Illegal values");
                Form5->Close();
        }

        Form1->Memo1->Lines->Add("Space calibrated real dimension "+AnsiString(spacefactor)+" in one pixel");
        Form5->Close();
}
//---------------------------------------------------------------------------
