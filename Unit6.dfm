object Form6: TForm6
  Left = 521
  Top = 104
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'CheminDeFer - Options'
  ClientHeight = 228
  ClientWidth = 287
  Color = clTeal
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
  object Label2: TLabel
    Left = 24
    Top = 120
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
  object Label1: TLabel
    Left = 24
    Top = 152
    Width = 195
    Height = 16
    Caption = 'Police de caract'#232'res des pages: :'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object CB_couv1: TCheckBox
    Left = 24
    Top = 16
    Width = 145
    Height = 17
    Caption = '1'#232're de couverture'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = CB_couv1Click
  end
  object CB_couv2: TCheckBox
    Left = 24
    Top = 40
    Width = 137
    Height = 17
    Caption = '2e de couverture'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = CB_couv2Click
  end
  object CB_couv3: TCheckBox
    Left = 24
    Top = 64
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
    OnClick = CB_couv3Click
  end
  object CB_couv4: TCheckBox
    Left = 24
    Top = 88
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
    OnClick = CB_couv4Click
  end
  object Button1: TButton
    Left = 64
    Top = 192
    Width = 75
    Height = 25
    Caption = '&OK'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 192
    Width = 75
    Height = 25
    Caption = '&Annuler'
    TabOrder = 5
    OnClick = Button2Click
  end
  object E_Titre: TEdit
    Left = 64
    Top = 112
    Width = 201
    Height = 21
    TabOrder = 6
  end
  object Button3: TButton
    Left = 216
    Top = 144
    Width = 51
    Height = 25
    Caption = 'Choisir...'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 216
    Top = 16
    Width = 51
    Height = 17
    Caption = 'Police'
    Enabled = False
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 216
    Top = 40
    Width = 51
    Height = 17
    Caption = 'Police'
    Enabled = False
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 216
    Top = 64
    Width = 51
    Height = 17
    Caption = 'Police'
    Enabled = False
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 216
    Top = 88
    Width = 51
    Height = 17
    Caption = 'Police'
    Enabled = False
    TabOrder = 11
    OnClick = Button7Click
  end
end
