object Form1: TForm1
  Left = 195
  Top = 103
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Chemin De Fer - Options de cr'#233'ation'
  ClientHeight = 217
  ClientWidth = 285
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
    Left = 24
    Top = 112
    Width = 166
    Height = 16
    Caption = 'Nombre de pages int'#233'rieures'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 152
    Width = 33
    Height = 16
    Caption = 'Titre :'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object E_nbpages: TEdit
    Left = 216
    Top = 104
    Width = 49
    Height = 21
    TabOrder = 0
  end
  object CB_couv1: TCheckBox
    Left = 24
    Top = 8
    Width = 145
    Height = 17
    Caption = '1'#232're de couverture'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object CB_couv3: TCheckBox
    Left = 24
    Top = 56
    Width = 137
    Height = 17
    Caption = '3e de couverture'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object CB_couv4: TCheckBox
    Left = 24
    Top = 80
    Width = 137
    Height = 17
    Caption = '4e de couverture'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object CB_couv2: TCheckBox
    Left = 24
    Top = 32
    Width = 137
    Height = 17
    Caption = '2e de couverture'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object E_Titre: TEdit
    Left = 72
    Top = 144
    Width = 193
    Height = 21
    TabOrder = 5
  end
  object Button1: TButton
    Left = 72
    Top = 184
    Width = 75
    Height = 25
    Caption = '&Cr'#233'er'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 152
    Top = 184
    Width = 75
    Height = 25
    Caption = '&Annuler'
    TabOrder = 7
    OnClick = Button2Click
  end
end
