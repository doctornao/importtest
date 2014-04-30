object ParmDialog: TParmDialog
  Left = 816
  Top = 267
  Width = 335
  Height = 129
  Caption = 'ParmDialog'
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 8
    Top = 24
    Width = 32
    Height = 12
    Caption = 'Parm#'
  end
  object Attribute: TButton
    Left = 56
    Top = 16
    Width = 97
    Height = 25
    Caption = 'Attribute'
    PopupMenu = PopupMenu1
    TabOrder = 0
  end
  object P1: TButton
    Left = 160
    Top = 16
    Width = 33
    Height = 25
    Caption = 'P1'
    PopupMenu = PopupMenu2
    TabOrder = 1
  end
  object P2: TButton
    Left = 216
    Top = 16
    Width = 33
    Height = 25
    Caption = 'P2'
    PopupMenu = PopupMenu2
    TabOrder = 2
  end
  object P3: TButton
    Left = 272
    Top = 16
    Width = 33
    Height = 25
    Caption = 'P3'
    PopupMenu = PopupMenu2
    TabOrder = 3
  end
  object OK: TButton
    Left = 184
    Top = 56
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 4
    OnClick = OKClick
  end
  object Cancel: TButton
    Left = 72
    Top = 57
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 5
    OnClick = CancelClick
  end
  object PopupMenu1: TPopupMenu
    AutoHotkeys = maManual
    OnPopup = PopupMenu1Popup
    Left = 24
    Top = 48
    object DistfromOrigin1: TMenuItem
      Caption = 'Dist from Origin'
      OnClick = PMnClick
    end
    object Distance: TMenuItem
      Caption = 'Distance'
      OnClick = PMnClick
    end
    object Anglebw2p1: TMenuItem
      Caption = 'Angle bw 2p'
      OnClick = PMnClick
    end
    object Angle: TMenuItem
      Caption = 'Angle bw 3p'
      OnClick = PMnClick
    end
  end
  object PopupMenu2: TPopupMenu
    AutoHotkeys = maManual
    Left = 280
    Top = 56
  end
end
