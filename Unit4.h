//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// Composants g�r�s par l'EDI
        TLabel *Label1;
        TEdit *E_pgDebut;
        TUpDown *UpDown1;
        TButton *Button1;
        TButton *Button2;
        TEdit *E_pgFin;
        TUpDown *UpDown2;
        TLabel *Label2;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
private:	// D�clarations de l'utilisateur
public:		// D�clarations de l'utilisateur
        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
