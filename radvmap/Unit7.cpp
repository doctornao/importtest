//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern int RoiStartx,RoiStarty,RoiEndx,RoiEndy,RoiSizeX,RoiSizeY;

TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm7::Button1Click(TObject *Sender)
{
        RoiStartx = StrToInt(Edit1->Text);
        RoiStarty = StrToInt(Edit2->Text);
        RoiEndx = StrToInt(Edit3->Text);
        RoiEndy = StrToInt(Edit4->Text);
        RoiSizeX = RoiEndx - RoiStartx +1;
        RoiSizeY = RoiEndy - RoiStarty +1;

        //Form7->Visible = false;
        ModalResult = mrOk;

}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button2Click(TObject *Sender)
{
        //Form7->Visible = false;
        ModalResult = mrCancel;

}
//---------------------------------------------------------------------------
