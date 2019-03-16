object Form3: TForm3
  Left = 518
  Top = 103
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Chemin De Fer- Insertion'
  ClientHeight = 123
  ClientWidth = 223
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 133
    Height = 13
    Caption = 'Nombre de pages '#224' ins'#233'rer :'
  end
  object Label2: TLabel
    Left = 16
    Top = 56
    Width = 143
    Height = 13
    Caption = 'Ins'#233'rer apr'#232's la page num'#233'ro :'
  end
  object E_nbPages: TEdit
    Left = 168
    Top = 16
    Width = 33
    Height = 21
    TabOrder = 0
    Text = '1'
  end
  object E_nPage: TEdit
    Left = 168
    Top = 48
    Width = 33
    Height = 21
    TabOrder = 1
    Text = '0'
  end
  object Button1: TButton
    Left = 56
    Top = 88
    Width = 57
    Height = 25
    Caption = '&OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 120
    Top = 88
    Width = 57
    Height = 25
    Caption = '&Annuler'
    TabOrder = 3
    OnClick = Button2Click
  end
  object UpDown1: TUpDown
    Left = 201
    Top = 16
    Width = 15
    Height = 21
    Associate = E_nbPages
    Min = 1
    Max = 500
    Position = 1
    TabOrder = 4
    Wrap = False
  end
  object UpDown2: TUpDown
    Left = 201
    Top = 48
    Width = 15
    Height = 21
    Associate = E_nPage
    Min = 0
    Max = 500
    Position = 0
    TabOrder = 5
    Wrap = False
  end
end
