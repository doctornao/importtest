//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TParmDialog : public TForm
{
__published:	// IDE 管理のコンポーネント
        TLabel *Label1;
        TPopupMenu *PopupMenu1;
        TButton *Attribute;
        TButton *P1;
        TButton *P2;
        TButton *P3;
        TMenuItem *Distance;
        TMenuItem *Angle;
        TPopupMenu *PopupMenu2;
        TButton *OK;
        TButton *Cancel;
        TMenuItem *DistfromOrigin1;
        TMenuItem *Anglebw2p1;
        void __fastcall PMnClick(TObject *Sender);
        void __fastcall APMnClick(TObject *Sender);
        void __fastcall PopupMenu1Popup(TObject *Sender);
        void __fastcall OKClick(TObject *Sender);
        void __fastcall CancelClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
        __fastcall TParmDialog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TParmDialog *ParmDialog;
//---------------------------------------------------------------------------
#endif
