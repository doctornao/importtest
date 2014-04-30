object Form4: TForm4
  Left = 87
  Top = 432
  Width = 383
  Height = 230
  Caption = 'Mini Panel'
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 12
  object Button4: TButton
    Left = 9
    Top = 70
    Width = 104
    Height = 27
    Caption = 'Fast Forward'
    TabOrder = 0
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 105
    Top = 14
    Width = 32
    Height = 49
    Caption = '>'
    TabOrder = 1
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 68
    Top = 27
    Width = 33
    Height = 20
    TabOrder = 2
    Text = 'frame'
    OnExit = Edit1Exit
  end
  object Button8: TButton
    Left = 40
    Top = 14
    Width = 25
    Height = 49
    Caption = '<'
    TabOrder = 3
    OnClick = Button8Click
  end
  object Button12: TButton
    Left = 8
    Top = 102
    Width = 57
    Height = 35
    Caption = 'Add Roi'
    TabOrder = 4
    OnClick = Button12Click
  end
  object Edit7: TEdit
    Left = 73
    Top = 107
    Width = 24
    Height = 20
    TabOrder = 5
    Text = 'NA'
    OnExit = Edit7Exit
  end
  object Button16: TButton
    Left = 105
    Top = 102
    Width = 57
    Height = 35
    Caption = 'Del Roi'
    TabOrder = 6
    OnClick = Button16Click
  end
  object Button10: TButton
    Left = 231
    Top = 14
    Width = 33
    Height = 49
    Caption = '<'
    TabOrder = 7
    OnClick = Button10Click
  end
  object Edit4: TEdit
    Left = 268
    Top = 32
    Width = 33
    Height = 20
    TabOrder = 8
    Text = 'frame'
    OnExit = Edit4Exit
  end
  object Button11: TButton
    Left = 307
    Top = 14
    Width = 29
    Height = 49
    Caption = '>'
    TabOrder = 9
    OnClick = Button11Click
  end
  object Sequential: TButton
    Left = 172
    Top = 93
    Width = 61
    Height = 41
    Caption = 'Sequential'
    TabOrder = 10
    OnClick = SequentialClick
  end
  object RadioGroup1: TRadioGroup
    Left = 285
    Top = 72
    Width = 73
    Height = 82
    Caption = 'Mode'
    TabOrder = 11
  end
  object RadioButton1: TRadioButton
    Left = 293
    Top = 97
    Width = 57
    Height = 17
    Caption = 'Linear'
    TabOrder = 12
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 293
    Top = 129
    Width = 57
    Height = 17
    Caption = 'Spiral'
    Checked = True
    TabOrder = 13
    TabStop = True
    OnClick = RadioButton2Click
  end
  object Button9: TButton
    Left = 245
    Top = 95
    Width = 36
    Height = 40
    Caption = 'Go!'
    TabOrder = 14
    Visible = False
    OnClick = Button9Click
  end
  object Stop: TButton
    Left = 122
    Top = 67
    Width = 41
    Height = 31
    Caption = 'Stop'
    TabOrder = 15
    OnClick = StopClick
  end
  object Button1: TButton
    Left = 208
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Calibration'
    TabOrder = 16
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 16
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Manual'
    TabOrder = 17
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 128
    Top = 152
    Width = 57
    Height = 25
    Caption = #65316#65359#65365#65346#65356#65349#65348
    TabOrder = 18
    OnClick = Button3Click
  end
  object Button6: TButton
    Left = 8
    Top = 15
    Width = 25
    Height = 49
    Caption = '<<'
    TabOrder = 19
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 146
    Top = 14
    Width = 21
    Height = 49
    Caption = '>>'
    TabOrder = 20
    OnClick = Button7Click
  end
  object Button13: TButton
    Left = 201
    Top = 14
    Width = 25
    Height = 49
    Caption = '<<'
    TabOrder = 21
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 342
    Top = 14
    Width = 25
    Height = 49
    Caption = '>>'
    TabOrder = 22
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 173
    Top = 26
    Width = 25
    Height = 25
    Caption = '->'
    TabOrder = 23
    OnClick = Button15Click
  end
end
