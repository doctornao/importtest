//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TButton *Button4;
        TButton *Button5;
        TEdit *Edit1;
        TButton *Button8;
        TButton *Button12;
        TEdit *Edit7;
        TButton *Button16;
        TButton *Button10;
        TEdit *Edit4;
        TButton *Button11;
        TButton *Sequential;
        TRadioGroup *RadioGroup1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TButton *Button9;
        TButton *Stop;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button6;
        TButton *Button7;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Edit1Exit(TObject *Sender);
        void __fastcall Edit4Exit(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Edit7Exit(TObject *Sender);
        void __fastcall SequentialClick(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall StopClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
