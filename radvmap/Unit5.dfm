object Form5: TForm5
  Left = 108
  Top = 130
  Width = 343
  Height = 219
  Caption = 'Calibration'
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object H: TLabel
    Left = 16
    Top = 16
    Width = 10
    Height = 16
    Caption = 'H'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object V: TLabel
    Left = 16
    Top = 56
    Width = 10
    Height = 16
    Caption = 'V'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object D: TLabel
    Left = 16
    Top = 96
    Width = 10
    Height = 16
    Caption = 'D'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 56
    Top = 16
    Width = 97
    Height = 25
    Caption = 'this is filled'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 56
    Top = 56
    Width = 74
    Height = 16
    Caption = 'this is filled'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 56
    Top = 96
    Width = 74
    Height = 16
    Caption = 'this is filled'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 176
    Top = 16
    Width = 121
    Height = 24
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 176
    Top = 56
    Width = 121
    Height = 24
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 176
    Top = 96
    Width = 121
    Height = 24
    TabOrder = 2
  end
  object Cancel: TButton
    Left = 48
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = CancelClick
  end
  object OK: TButton
    Left = 184
    Top = 136
    Width = 89
    Height = 25
    Caption = 'OK'
    TabOrder = 4
    OnClick = OKClick
  end
end
