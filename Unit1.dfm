object Form1: TForm1
  Left = 104
  Top = 174
  Caption = 'Correlation'
  ClientHeight = 876
  ClientWidth = 1042
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnPaint = ReDraw
  PixelsPerInch = 96
  TextHeight = 12
  object Image1: TImage
    Left = 320
    Top = 40
    Width = 312
    Height = 260
    OnMouseDown = ImageMouseDown
    OnMouseMove = ImageMouseMove
    OnMouseUp = ImageMouseUp
  end
  object Image2: TImage
    Left = 680
    Top = 40
    Width = 312
    Height = 260
    OnMouseDown = ImageMouseDown
    OnMouseMove = ImageMouseMove
    OnMouseUp = ImageMouseUp
  end
  object PaintBox2: TPaintBox
    Left = 264
    Top = 496
    Width = 400
    Height = 200
  end
  object Label5: TLabel
    Left = 416
    Top = 712
    Width = 5
    Height = 16
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 256
    Top = 700
    Width = 6
    Height = 12
    Caption = '0'
  end
  object Label7: TLabel
    Left = 656
    Top = 704
    Width = 18
    Height = 12
    Alignment = taCenter
    Caption = '400'
  end
  object Label8: TLabel
    Left = 240
    Top = 488
    Width = 14
    Height = 12
    Caption = '1.0'
  end
  object Label9: TLabel
    Left = 920
    Top = 440
    Width = 53
    Height = 12
    Caption = 'Delta limit'
  end
  object Label10: TLabel
    Left = 848
    Top = 440
    Width = 29
    Height = 12
    Caption = 'Angle'
  end
  object Label11: TLabel
    Left = 328
    Top = 0
    Width = 53
    Height = 12
    Caption = 'Target file'
    Layout = tlCenter
  end
  object Image3: TImage
    Left = 680
    Top = 496
    Width = 312
    Height = 260
  end
  object Label1: TLabel
    Left = 29
    Top = 508
    Width = 20
    Height = 12
    Caption = 'Plot'
  end
  object Label2: TLabel
    Left = 130
    Top = 740
    Width = 89
    Height = 12
    Caption = 'Dataset for Roi #'
    Transparent = True
  end
  object Label3: TLabel
    Left = 680
    Top = 400
    Width = 56
    Height = 12
    Caption = 'Correlation'
  end
  object Label4: TLabel
    Left = 681
    Top = 363
    Width = 56
    Height = 12
    Caption = 'Target ROI'
  end
  object Panel2: TPanel
    Left = 1
    Top = 463
    Width = 233
    Height = 305
    BorderWidth = 2
    BorderStyle = bsSingle
    TabOrder = 34
    object CheckBox8: TCheckBox
      Left = 159
      Top = 280
      Width = 57
      Height = 17
      Caption = 'marker'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
  end
  object RadioGroup4: TRadioGroup
    Left = 104
    Top = 472
    Width = 129
    Height = 49
    Caption = 'Program'
    TabOrder = 55
  end
  object Panel1: TPanel
    Left = 21
    Top = 523
    Width = 97
    Height = 201
    TabOrder = 32
    object CheckBox7: TCheckBox
      Left = 11
      Top = 153
      Width = 83
      Height = 17
      Caption = 'Angle'
      TabOrder = 0
    end
  end
  object Memo1: TMemo
    Left = 8
    Top = 48
    Width = 273
    Height = 361
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 113
    Height = 33
    Caption = 'Open'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 512
    Top = 368
    Width = 41
    Height = 41
    Caption = 'X2'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button4: TButton
    Left = 309
    Top = 369
    Width = 73
    Height = 33
    Caption = 'Fast Forward'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 430
    Top = 312
    Width = 41
    Height = 49
    Caption = '>'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 390
    Top = 325
    Width = 33
    Height = 20
    TabOrder = 5
    Text = 'frame'
    OnExit = Edit1Exit
  end
  object Button6: TButton
    Left = 511
    Top = 314
    Width = 138
    Height = 33
    Caption = 'File Writeout'
    PopupMenu = PopupMenu1
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 592
    Top = 368
    Width = 41
    Height = 41
    Caption = '/2'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Edit2: TEdit
    Left = 565
    Top = 377
    Width = 17
    Height = 20
    TabOrder = 8
    Text = '0'
  end
  object Button8: TButton
    Left = 344
    Top = 312
    Width = 41
    Height = 49
    Caption = '<'
    TabOrder = 9
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 784
    Top = 376
    Width = 57
    Height = 49
    Caption = 'Go!'
    Enabled = False
    TabOrder = 10
    Visible = False
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 704
    Top = 312
    Width = 33
    Height = 41
    Caption = '<'
    TabOrder = 11
    OnClick = Button10Click
  end
  object Edit4: TEdit
    Left = 744
    Top = 320
    Width = 33
    Height = 20
    TabOrder = 12
    Text = 'frame'
    OnExit = Edit4Exit
  end
  object Button11: TButton
    Left = 784
    Top = 312
    Width = 33
    Height = 41
    Caption = '>'
    TabOrder = 13
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 320
    Top = 408
    Width = 57
    Height = 49
    Caption = 'Add Roi'
    TabOrder = 14
    Visible = False
    OnClick = Button12Click
  end
  object Edit5: TEdit
    Left = 975
    Top = 436
    Width = 42
    Height = 20
    TabOrder = 15
    Text = '400'
    OnExit = Edit5Exit
  end
  object Button3: TButton
    Left = 936
    Top = 312
    Width = 57
    Height = 41
    Caption = 'Step'
    Enabled = False
    TabOrder = 16
    Visible = False
    OnClick = Button3Click
  end
  object Sequential: TButton
    Left = 936
    Top = 376
    Width = 57
    Height = 41
    Caption = 'Sequential'
    TabOrder = 17
    OnClick = SequentialClick
  end
  object RadioGroup1: TRadioGroup
    Left = 856
    Top = 320
    Width = 73
    Height = 105
    Caption = 'Mode'
    TabOrder = 18
  end
  object RadioButton1: TRadioButton
    Left = 864
    Top = 344
    Width = 57
    Height = 17
    Caption = 'Linear'
    TabOrder = 19
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 864
    Top = 392
    Width = 57
    Height = 17
    Caption = 'Spiral'
    TabOrder = 20
    OnClick = RadioButton2Click
  end
  object Edit3: TEdit
    Left = 880
    Top = 437
    Width = 33
    Height = 20
    TabOrder = 21
    Text = '0'
    OnExit = Edit3Exit
  end
  object Button13: TButton
    Left = 16
    Top = 424
    Width = 113
    Height = 33
    Caption = 'Memo Writeout'
    TabOrder = 22
    OnClick = Button13Click
  end
  object RadioGroup2: TRadioGroup
    Left = 144
    Top = 0
    Width = 137
    Height = 49
    Caption = 'Flip'
    Columns = 2
    ItemIndex = 1
    Items.Strings = (
      'normal'
      'flip')
    TabOrder = 23
    OnClick = RadioGroup2Click
  end
  object CheckBox1: TCheckBox
    Left = 624
    Top = 7
    Width = 65
    Height = 17
    Caption = 'Angle'
    Checked = True
    State = cbChecked
    TabOrder = 24
  end
  object CheckBox2: TCheckBox
    Left = 776
    Top = 440
    Width = 65
    Height = 17
    Caption = 'Debug'
    TabOrder = 25
  end
  object Button14: TButton
    Left = 17
    Top = 477
    Width = 80
    Height = 33
    Caption = 'Graph'
    TabOrder = 26
    Visible = False
    OnClick = Button14Click
  end
  object RadioGroup3: TRadioGroup
    Left = 143
    Top = 520
    Width = 89
    Height = 209
    Caption = 'Versus'
    ItemIndex = 0
    Items.Strings = (
      'Time'
      'Position X'
      'Position Y')
    TabOrder = 27
  end
  object CheckBox3: TCheckBox
    Left = 32
    Top = 544
    Width = 81
    Height = 17
    Caption = 'Position X'
    Checked = True
    State = cbChecked
    TabOrder = 28
  end
  object CheckBox4: TCheckBox
    Left = 32
    Top = 576
    Width = 73
    Height = 17
    Caption = 'Position Y'
    TabOrder = 29
  end
  object CheckBox5: TCheckBox
    Left = 32
    Top = 609
    Width = 73
    Height = 17
    Caption = 'C X'
    TabOrder = 30
  end
  object CheckBox6: TCheckBox
    Left = 32
    Top = 642
    Width = 73
    Height = 17
    Caption = 'C Y'
    TabOrder = 31
  end
  object Button15: TButton
    Left = 152
    Top = 424
    Width = 81
    Height = 33
    Caption = 'Dump It!'
    TabOrder = 33
    OnClick = Button15Click
  end
  object Edit6: TEdit
    Left = 320
    Top = 16
    Width = 81
    Height = 20
    TabOrder = 35
    Text = 'Time interval in sec'
    OnExit = Edit6Exit
  end
  object Edit7: TEdit
    Left = 398
    Top = 424
    Width = 26
    Height = 20
    TabOrder = 36
    Text = 'NA'
    OnExit = Edit7Exit
  end
  object Button16: TButton
    Left = 440
    Top = 408
    Width = 57
    Height = 49
    Caption = 'Del Roi'
    TabOrder = 37
    OnClick = Button16Click
  end
  object TargetRoi: TEdit
    Left = 752
    Top = 360
    Width = 17
    Height = 20
    TabOrder = 38
    Text = '0'
  end
  object Edit8: TEdit
    Left = 107
    Top = 737
    Width = 17
    Height = 20
    TabOrder = 39
    Text = '0'
  end
  object CheckBox9: TCheckBox
    Left = 24
    Top = 737
    Width = 73
    Height = 17
    Caption = 'all data exp.'
    TabOrder = 40
  end
  object Button17: TButton
    Left = 512
    Top = 416
    Width = 97
    Height = 41
    Caption = 'Write Last Session'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 41
    OnClick = Button17Click
  end
  object Trace: TCheckBox
    Left = 536
    Top = 464
    Width = 65
    Height = 17
    Caption = 'Trace'
    Checked = True
    State = cbChecked
    TabOrder = 42
  end
  object CorrDisplay: TCheckBox
    Left = 680
    Top = 440
    Width = 89
    Height = 17
    Caption = 'CorrDisplay'
    TabOrder = 43
  end
  object Edit9: TEdit
    Left = 744
    Top = 398
    Width = 33
    Height = 20
    TabOrder = 44
    Text = '0.85'
    OnExit = Edit9Exit
  end
  object Stop: TButton
    Left = 391
    Top = 367
    Width = 41
    Height = 33
    Caption = 'Stop'
    TabOrder = 45
    OnClick = StopClick
  end
  object Calibration: TButton
    Left = 536
    Top = 8
    Width = 65
    Height = 25
    Caption = 'Calibration'
    TabOrder = 46
    OnClick = CalibrationClick
  end
  object Manual: TButton
    Left = 688
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Manual'
    TabOrder = 47
    OnClick = ManualClick
  end
  object AddParms: TButton
    Left = 288
    Top = 736
    Width = 57
    Height = 33
    Caption = 'AddParms'
    TabOrder = 48
    Visible = False
    OnClick = AddParmsClick
  end
  object tp: TEdit
    Left = 358
    Top = 743
    Width = 24
    Height = 20
    TabOrder = 49
    Text = 'tp'
    Visible = False
  end
  object DelParms: TButton
    Left = 400
    Top = 736
    Width = 57
    Height = 33
    Caption = 'DelParms'
    TabOrder = 50
    Visible = False
    OnClick = DelParmsClick
  end
  object ListParms: TButton
    Left = 472
    Top = 736
    Width = 65
    Height = 33
    Caption = 'ListParms'
    TabOrder = 51
    Visible = False
    OnClick = ListParmsClick
  end
  object OriginLeftBottom: TCheckBox
    Left = 392
    Top = 464
    Width = 129
    Height = 17
    Caption = 'OriginLeftBottom'
    Checked = True
    State = cbChecked
    TabOrder = 52
  end
  object LoadSource: TButton
    Left = 424
    Top = 8
    Width = 81
    Height = 25
    Caption = 'LoadSource'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 53
    OnClick = LoadSourceClick
  end
  object LoadDest: TButton
    Left = 800
    Top = 8
    Width = 81
    Height = 25
    Caption = 'LoadDest'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 54
    OnClick = LoadDestClick
  end
  object RadioButton3: TRadioButton
    Left = 120
    Top = 488
    Width = 49
    Height = 17
    Caption = 'Excel'
    TabOrder = 56
    Visible = False
  end
  object RadioButton4: TRadioButton
    Left = 176
    Top = 488
    Width = 49
    Height = 17
    Caption = 'Igor'
    TabOrder = 57
    Visible = False
  end
  object Button18: TButton
    Left = 312
    Top = 312
    Width = 25
    Height = 49
    Caption = '<<'
    TabOrder = 58
    OnClick = Button18Click
  end
  object Button19: TButton
    Left = 480
    Top = 312
    Width = 25
    Height = 49
    Caption = '>>'
    TabOrder = 59
    OnClick = Button19Click
  end
  object Button20: TButton
    Left = 672
    Top = 312
    Width = 25
    Height = 41
    Caption = '<<'
    TabOrder = 60
    OnClick = Button20Click
  end
  object Button21: TButton
    Left = 824
    Top = 312
    Width = 25
    Height = 41
    Caption = '>>'
    TabOrder = 61
    OnClick = Button21Click
  end
  object CheckBox10: TCheckBox
    Left = 285
    Top = 162
    Width = 32
    Height = 17
    Caption = 'HE'
    TabOrder = 62
  end
  object Button22: TButton
    Left = 640
    Top = 160
    Width = 33
    Height = 33
    Caption = '->'
    TabOrder = 63
    OnClick = Button22Click
  end
  object Edit10: TEdit
    Left = 642
    Top = 24
    Width = 25
    Height = 20
    TabOrder = 64
    Text = '0.5'
    OnExit = Edit10Exit
  end
  object CheckBox11: TCheckBox
    Left = 272
    Top = 456
    Width = 105
    Height = 25
    Caption = 'Linear mode'
    TabOrder = 65
  end
  object Edit11: TEdit
    Left = 272
    Top = 432
    Width = 33
    Height = 20
    TabOrder = 66
    Text = '30'
  end
  object Button23: TButton
    Left = 288
    Top = 56
    Width = 25
    Height = 25
    Caption = 'Roi'
    TabOrder = 67
    OnClick = Button23Click
  end
  object DumpRoi: TButton
    Left = 285
    Top = 200
    Width = 33
    Height = 25
    Caption = 'DRoi'
    TabOrder = 68
    OnClick = DumpRoiClick
  end
  object LoadRoi: TButton
    Left = 286
    Top = 241
    Width = 33
    Height = 25
    Caption = 'LRoi'
    TabOrder = 69
    OnClick = LoadRoiClick
  end
  object CheckBox12: TCheckBox
    Left = 592
    Top = 744
    Width = 57
    Height = 17
    Caption = 'Stats'
    Checked = True
    State = cbChecked
    TabOrder = 70
  end
  object CheckBox13: TCheckBox
    Left = 285
    Top = 280
    Width = 33
    Height = 17
    Caption = 'Roi #'
    Checked = True
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 71
  end
  object Button24: TButton
    Left = 288
    Top = 816
    Width = 75
    Height = 25
    Caption = 'Filtering'
    Enabled = False
    TabOrder = 72
    OnClick = Button24Click
  end
  object RadioGroup5: TRadioGroup
    Left = 386
    Top = 800
    Width = 247
    Height = 57
    Caption = 'Filter'
    Enabled = False
    TabOrder = 73
  end
  object RadioButton5: TRadioButton
    Left = 390
    Top = 820
    Width = 43
    Height = 17
    Caption = 'lap1'
    TabOrder = 74
    OnClick = RadioButton5Click
  end
  object RadioButton6: TRadioButton
    Left = 454
    Top = 820
    Width = 43
    Height = 17
    Caption = 'lap2'
    Checked = True
    TabOrder = 75
    TabStop = True
    OnClick = RadioButton6Click
  end
  object RadioButton7: TRadioButton
    Left = 512
    Top = 820
    Width = 43
    Height = 17
    Caption = 'lap3'
    TabOrder = 76
    OnClick = RadioButton7Click
  end
  object RadioButton8: TRadioButton
    Left = 561
    Top = 820
    Width = 64
    Height = 17
    Caption = 'custom'
    TabOrder = 77
    OnClick = RadioButton8Click
  end
  object FilterWeight: TStringGrid
    Left = 672
    Top = 789
    Width = 96
    Height = 79
    ColCount = 3
    DefaultColWidth = 30
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    ScrollBars = ssNone
    TabOrder = 78
  end
  object Divisor: TLabeledEdit
    Left = 808
    Top = 800
    Width = 73
    Height = 20
    EditLabel.Width = 36
    EditLabel.Height = 12
    EditLabel.Caption = 'Divisor'
    TabOrder = 79
  end
  object Shift: TLabeledEdit
    Left = 808
    Top = 837
    Width = 73
    Height = 20
    EditLabel.Width = 24
    EditLabel.Height = 12
    EditLabel.Caption = 'Shift'
    TabOrder = 80
  end
  object rectbase: TCheckBox
    Left = 29
    Top = 820
    Width = 121
    Height = 17
    Caption = 'Rectbase filtering'
    TabOrder = 81
  end
  object Button25: TButton
    Left = 447
    Top = 367
    Width = 50
    Height = 35
    Caption = 'Auto play'
    TabOrder = 82
    OnClick = Button25Click
  end
  object Button26: TButton
    Left = 625
    Top = 415
    Width = 49
    Height = 41
    Caption = 'avi dump'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 83
    OnClick = Button26Click
  end
  object Playspeed: TTrackBar
    Left = 607
    Top = 462
    Width = 129
    Height = 26
    TabOrder = 84
    OnChange = PlayspeedChange
  end
  object OpenDialog1: TOpenDialog
    Filter = #23798#27941'Dat '#12501#12449#12452#12523',AVI '#12501#12449#12452#12523'(*.dat,*.avi)|*.DAT;*.AVI'
    Left = 992
    Top = 192
  end
  object SaveDialog1: TSaveDialog
    Filter = #12499#12483#12488#12510#12483#12503'(*.bmp)|*.bmp'
    Left = 992
    Top = 152
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 90
    OnTimer = Timer1Timer
    Left = 992
    Top = 112
  end
  object SaveDialog2: TSaveDialog
    Filter = #12486#12461#12473#12488#12501#12449#12452#12523'(*.txt)|*.txt'
    Left = 992
    Top = 72
  end
  object DdeClientConv1: TDdeClientConv
    Left = 992
    Top = 16
  end
  object SaveDialog3: TSaveDialog
    Filter = 'JPEG(*.jpg)|*.jpg'
    Left = 992
    Top = 240
  end
  object PopupMenu1: TPopupMenu
    Left = 1000
    Top = 280
    object SmallSource1: TMenuItem
      Caption = 'Small Source'
      Enabled = False
      OnClick = SmallSource1Click
    end
    object SmallDest1: TMenuItem
      Caption = 'Small Dest.'
      Enabled = False
      OnClick = SmallDest1Click
    end
    object LargeSource1: TMenuItem
      Caption = 'Large Source'
      Enabled = False
      OnClick = LargeSource1Click
    end
    object LargeDest1: TMenuItem
      Caption = 'Large Dest.'
      Enabled = False
      OnClick = LargeDest1Click
    end
  end
  object SaveDialog4: TSaveDialog
    DefaultExt = 'avi'
    Filter = 'AVI '#12501#12449#12452#12523'(*.avi)|*.avi'
    Left = 992
    Top = 312
  end
  object OpenDialog2: TOpenDialog
    Filter = 'BMP(*.bmp)|*.bmp;*.BMP;*.Bmp'
    Left = 992
    Top = 352
  end
  object SaveRoiDialog: TSaveDialog
    Filter = 'ROI'#12501#12449#12452#12523'(*.roi)|*.roi'
    Left = 1008
    Top = 384
  end
  object LoadRoiDialog: TOpenDialog
    Filter = 'ROI'#12501#12449#12452#12523'(*.roi)|*.roi'
    Left = 1008
    Top = 472
  end
end
