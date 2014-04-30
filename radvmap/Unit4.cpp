//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern int      sourceframe,destframe,displayed,nottarget,targetroi,spiral;
extern int      doubled,manual;


TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button8Click(TObject *Sender)
{
        Form1->Button8Click(Sender);
        Edit1->Text = Form1->Edit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button5Click(TObject *Sender)
{
        Form1->Button5Click(Sender);
        Edit1->Text = Form1->Edit1->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button10Click(TObject *Sender)
{
        Form1->Button10Click(Sender);
        Edit4->Text = Form1->Edit4->Text;

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button11Click(TObject *Sender)
{
        Form1->Button11Click(Sender);
        Edit4->Text = Form1->Edit4->Text;

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit1Exit(TObject *Sender)
{
        sourceframe = StrToInt(Edit1->Text);
        Form1->DispFrame(sourceframe);

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit4Exit(TObject *Sender)
{
        destframe = StrToInt(Edit4->Text);
        Form1->DispFrame2(destframe);
        displayed = 1;
        nottarget = 0;

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button4Click(TObject *Sender)
{
        Form1->Button4Click(Sender);        
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button9Click(TObject *Sender)
{
        Form1->Button9Click(Sender);        
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button12Click(TObject *Sender)
{
        Form1->Button12Click(Sender);        
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button16Click(TObject *Sender)
{
        Form1->Button16Click(Sender);        
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit7Exit(TObject *Sender)
{
        targetroi = StrToInt(Edit7->Text);

}
//---------------------------------------------------------------------------
void __fastcall TForm4::SequentialClick(TObject *Sender)
{
        Form1->SequentialClick(Sender);
                
}
//---------------------------------------------------------------------------
void __fastcall TForm4::RadioButton1Click(TObject *Sender)
{
        spiral = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioButton2Click(TObject *Sender)
{
        spiral = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::StopClick(TObject *Sender)
{
        Form1->StopClick(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
        Form1->CalibrationClick(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
        Form1->ManualClick(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
        //ShowMessage("manual is "+AnsiString(manual));

        if( doubled ){
                doubled = false;
                Button3->Caption = "Doubled";
                return;
        }

       if( !doubled ){
                doubled = true;
                Button3->Caption = "Normal";
                //ShowMessage("doubled triggered");
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6Click(TObject *Sender)
{
        Form1->Button18Click(Sender);
        Edit1->Text = Form1->Edit1->Text;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button7Click(TObject *Sender)
{
        Form1->Button19Click(Sender);
        Edit1->Text = Form1->Edit1->Text;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button13Click(TObject *Sender)
{
        Form1->Button20Click(Sender);
        Edit4->Text = Form1->Edit4->Text;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button14Click(TObject *Sender)
{
        Form1->Button21Click(Sender);
        Edit4->Text = Form1->Edit4->Text;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button15Click(TObject *Sender)
{
        Form1->Button22Click(Sender);
        Edit4->Text = Form1->Edit4->Text;
}
//---------------------------------------------------------------------------

