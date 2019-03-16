object Form4: TForm4
  Left = 748
  Top = 102
  Width = 231
  Height = 150
  BorderIcons = [biSystemMenu]
  Caption = 'Chemin De Fer - Effacer'
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 16
    Width = 101
    Height = 13
    Caption = 'Supprimer les pages :'
  end
  object Label2: TLabel
    Left = 112
    Top = 56
    Width = 6
    Height = 13
    Caption = #224
  end
  object E_pgDebut: TEdit
    Left = 48
    Top = 48
    Width = 33
    Height = 21
    TabOrder = 0
    Text = '1'
  end
  object UpDown1: TUpDown
    Left = 81
    Top = 48
    Width = 15
    Height = 21
    Associate = E_pgDebut
    Min = 1
    Max = 500
    Position = 1
    TabOrder = 1
    Wrap = False
    OnClick = UpDown1Click
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
  object E_pgFin: TEdit
    Left = 136
    Top = 48
    Width = 33
    Height = 21
    TabOrder = 4
    Text = '1'
  end
  object UpDown2: TUpDown
    Left = 169
    Top = 48
    Width = 15
    Height = 21
    Associate = E_pgFin
    Min = 1
    Max = 500
    Position = 1
    TabOrder = 5
    Wrap = False
  end
end
