//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// Composants gérés par l'EDI
        TMainMenu *MainMenu1;
        TMenuItem *Fichier1;
        TMenuItem *Edition1;
        TMenuItem *Nouveau1;
        TMenuItem *Enregistrer1;
        TMenuItem *Imprimer1;
        TMenuItem *Quitter1;
        TMenuItem *Insrer1;
        TPrintDialog *PrintDialog1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *Ouvrir1;
        TStatusBar *StatusBar1;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TMenuItem *Couper1;
        TMenuItem *N1;
        TMenuItem *Apropos1;
        TMenuItem *Outils1;
        TMenuItem *Options1;
        TLabel *label_Titre;
        void __fastcall Quitter1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Nouveau1Click(TObject *Sender);
        void __fastcall Enregistrer1Click(TObject *Sender);
        void __fastcall Ouvrir1Click(TObject *Sender);
        void __fastcall Imprimer1Click(TObject *Sender);
        void __fastcall Insrer1Click(TObject *Sender);
        void __fastcall Couper1Click(TObject *Sender);
        void __fastcall Apropos1Click(TObject *Sender);
        void __fastcall Options1Click(TObject *Sender);
private:	// Déclarations de l'utilisateur
public:		// Déclarations de l'utilisateur
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
