//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <DdeMan.hpp>
#include <Menus.hpp>
#include <ComObj.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
        TMemo *Memo1;
        TButton *Button1;
        TButton *Button2;
        TOpenDialog *OpenDialog1;
        TImage *Image1;
        TButton *Button4;
        TButton *Button5;
        TEdit *Edit1;
        TButton *Button6;
        TSaveDialog *SaveDialog1;
        TButton *Button7;
        TEdit *Edit2;
        TButton *Button8;
        TButton *Button9;
        TImage *Image2;
        TPaintBox *PaintBox2;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TButton *Button10;
        TEdit *Edit4;
        TButton *Button11;
        TButton *Button12;
        TTimer *Timer1;
        TEdit *Edit5;
        TLabel *Label9;
        TButton *Button3;
        TButton *Sequential;
        TRadioGroup *RadioGroup1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TEdit *Edit3;
        TLabel *Label10;
        TButton *Button13;
        TSaveDialog *SaveDialog2;
        TRadioGroup *RadioGroup2;
        TLabel *Label11;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TButton *Button14;
        TImage *Image3;
        TRadioGroup *RadioGroup3;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TLabel *Label1;
        TPanel *Panel1;
        TDdeClientConv *DdeClientConv1;
        TButton *Button15;
        TSaveDialog *SaveDialog3;
        TCheckBox *CheckBox7;
        TPanel *Panel2;
        TCheckBox *CheckBox8;
        TEdit *Edit6;
        TPopupMenu *PopupMenu1;
        TMenuItem *SmallSource1;
        TMenuItem *SmallDest1;
        TMenuItem *LargeSource1;
        TMenuItem *LargeDest1;
        TEdit *Edit7;
        TButton *Button16;
        TEdit *TargetRoi;
        TEdit *Edit8;
        TLabel *Label2;
        TCheckBox *CheckBox9;
        TSaveDialog *SaveDialog4;
        TButton *Button17;
        TCheckBox *Trace;
        TCheckBox *CorrDisplay;
        TEdit *Edit9;
        TLabel *Label3;
        TButton *Stop;
        TLabel *Label4;
        TButton *Calibration;
        TButton *Manual;
        TButton *AddParms;
        TEdit *tp;
        TButton *DelParms;
        TButton *ListParms;
        TCheckBox *OriginLeftBottom;
        TButton *LoadSource;
        TButton *LoadDest;
        TOpenDialog *OpenDialog2;
        TRadioGroup *RadioGroup4;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TButton *Button18;
        TButton *Button19;
        TButton *Button20;
        TButton *Button21;
        TCheckBox *CheckBox10;
        TButton *Button22;
        TEdit *Edit10;
        TCheckBox *CheckBox11;
        TEdit *Edit11;
        TButton *Button23;
        TButton *DumpRoi;
        TButton *LoadRoi;
        TSaveDialog *SaveRoiDialog;
        TOpenDialog *LoadRoiDialog;
        TCheckBox *CheckBox12;
        TCheckBox *CheckBox13;
	TButton *Button24;
	TRadioGroup *RadioGroup5;
	TRadioButton *RadioButton5;
	TRadioButton *RadioButton6;
	TRadioButton *RadioButton7;
	TRadioButton *RadioButton8;
	TStringGrid *FilterWeight;
	TLabeledEdit *Divisor;
	TLabeledEdit *Shift;
	TCheckBox *rectbase;
	TButton *Button25;
	TButton *Button26;
	TTrackBar *Playspeed;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ReDraw(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall ImageMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ImageMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall ImageMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Button8Click(TObject *Sender);
        void  __fastcall DispFrame(int framenum);
         void  __fastcall DispFrame2(int framenum);
        void __fastcall SpiralAnalysis();
        void __fastcall LinearAnalysis();

        void __fastcall maketable();
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
//        void __fastcall Edit3Exit(TObject *Sender);
        void __fastcall Edit5Exit(TObject *Sender);
        void __fastcall Edit1Exit(TObject *Sender);
        void __fastcall Edit4Exit(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall SequentialClick(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall Edit3Exit(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall disparea(int offsetx,int offsety,Word *p);
        void __fastcall dispwhole(void *p);
        void __fastcall setdata(char *name,double *p,int num);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Edit6Exit(TObject *Sender);
        void __fastcall SmallSource1Click(TObject *Sender);
        void __fastcall SmallDest1Click(TObject *Sender);
        void __fastcall LargeSource1Click(TObject *Sender);
        void __fastcall LargeDest1Click(TObject *Sender);
        void __fastcall Edit7Exit(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall disprois(void);
        void __fastcall DeleteRoisIfany();
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Edit9Exit(TObject *Sender);
        void __fastcall StopClick(TObject *Sender);
        void __fastcall CalibrationClick(TObject *Sender);
        void __fastcall ManualClick(TObject *Sender);
        void __fastcall dumppoints(void);
        void __fastcall AddParmsClick(TObject *Sender);
        void __fastcall DelParmsClick(TObject *Sender);
        void __fastcall ListParmsClick(TObject *Sender);
        void __fastcall LoadSourceClick(TObject *Sender);
        void __fastcall LoadDestClick(TObject *Sender);
        void __fastcall prepareigor(void);
        void __fastcall DoItByExcel(void);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall Button19Click(TObject *Sender);
        void __fastcall Button20Click(TObject *Sender);
        void __fastcall Button21Click(TObject *Sender);
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall Edit10Exit(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall DumpRoiClick(TObject *Sender);
        void __fastcall LoadRoiClick(TObject *Sender);
	void __fastcall RadioButton8Click(TObject *Sender);
	void __fastcall RadioButton5Click(TObject *Sender);
	void __fastcall RadioButton6Click(TObject *Sender);
	void __fastcall RadioButton7Click(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall Button26Click(TObject *Sender);
	void __fastcall Button25Click(TObject *Sender);
	void __fastcall PlayspeedChange(TObject *Sender);
        //void __fastcall Memo1Change(TObject *Sender);
private:	// ユーザー宣言
//        Variant excel;  // for excel handling
        Variant WorkBooks;
        Variant WorkBook;
        Variant WorkSheets;
        Variant WorkSheet;
        Variant WorkCell;
        Variant Range;
        Variant Ranges;
        Variant Chart;
        Variant Charts;
        Variant XAxis;
        Variant YAxis;

protected:
	void __fastcall WMDropFiles(TMessage &message);
	BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER(WM_DROPFILES, TMessage, WMDropFiles)
	END_MESSAGE_MAP(TForm)


public:		// ユーザー宣言
		__fastcall TForm1(TComponent* Owner);
#ifdef _DELPHI_STRING_UNICODE
	void __fastcall DecodeFile(wchar_t* filename);
#else
	void __fastcall DecodeFile(char* filename);
#endif

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
