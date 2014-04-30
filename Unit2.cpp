//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>

#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern TPoint FClickPoint,FPrevPoint;
extern int     RoiStartx,RoiStarty,RoiEndx,RoiEndy;
extern int     RoiSizeX,RoiSizeY,manual;
extern int      ih;

extern TList* currentpset;

struct apoint {
        int     x,y;
};

struct aframe {
        int     framenumber;
        TList* points;
};


TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
     char obuf[100];

    if(Button == mbLeft){    //���{�^���������ꂽ�ꍇ�̂ݏ�������
        //���݂̃J�[�\���̈ʒu���L�^���Ă���
        FPrevPoint.x = X;
        FPrevPoint.y = Y;
        //Close();  //  do not close Form1 now!!
        sprintf(obuf,"(%d,%d) -> (%d,%d)\n",FClickPoint.x,FClickPoint.y,X,Y);
        Form1->Memo1->Lines->Add(obuf);        // ROI display
        RoiStartx = FClickPoint.x;
        RoiStarty = FClickPoint.y;
        RoiEndx = X;
        RoiEndy = Y;
        //Button9->Caption = obuf;
        Form1->Button12->Enabled = true;
        Form1->Button12->Visible = true;

        RoiSizeX = RoiEndx - RoiStartx +1;
        RoiSizeY = RoiEndy - RoiStarty +1;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    if (Shift.Contains(ssLeft)) { // �{�^���������ꂽ�ꍇ
        Image1->Canvas->Pen->Mode = pmNotXor;    //�`�掞�ɐF�𔽓]����悤�Ɏw��
        Image1->Canvas->Pen->Color = clBlue;     //�F���w��
        Image1->Canvas->Brush->Style = bsClear;  //�h��ׂ��͂��Ȃ�

        //�O��`�����l�p������
        Image1->Canvas->Rectangle(FClickPoint.x,FClickPoint.y,FPrevPoint.x,FPrevPoint.y);
        //�V�����l�p��`��
        Image1->Canvas->Rectangle(FClickPoint.x,FClickPoint.y,X,Y);

        //���݂̃J�[�\���̈ʒu���L�^���Ă���
        FPrevPoint.x = X;
        FPrevPoint.y = Y;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
     if(Button==mbLeft){      //���{�^���̂ݏ���
             if(manual){
                struct  apoint *data = new struct apoint;
                Image1->Canvas->Pen->Mode = pmNotXor;    //�`�掞�ɐF�𔽓]����悤�Ɏw��
                Image1->Canvas->Pen->Color = clWhite;     //�F���w��
                Image1->Canvas->Brush->Style = bsClear;  //�h��ׂ��͂��Ȃ�

                Image1->Canvas->TextOutA(X,Y,currentpset->Count+1);

                data->x = X;

                //if(Form1->OriginLeftBottom->Checked)
               //         data->y = ih - Y;
                //else
                        data->y = Y;
                currentpset->Add(data);
                Image1->Canvas->Ellipse(X-2,Y-2,X+2,Y+2); // for visual feedback
        }

        FClickPoint.x = X;   //�N���b�N���ꂽ�ʒu���L�^
        FClickPoint.y = Y;
        FPrevPoint = FClickPoint; //�O��̃J�[�\���ʒu=�N���b�N���ꂽ�ʒu
    }
    else if( Button == mbRight )
        Form4->Button5Click(Sender);

}
//---------------------------------------------------------------------------
