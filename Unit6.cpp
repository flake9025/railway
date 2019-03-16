//---------------------------------------------------------------------------
//CREATEUR DE CHEMIN DE FER
//(c) 2007 JOEL MOLL - VINCENT VILLAIN
//C++ Builder 6.0
//Form d'options
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit6.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
//Variables Globales
//---------------------------------------------------------------------------

//Form
TForm6 *Form6;
//Booleens de couvertures
extern bool couv1,couv2,couv3,couv4;
//Nombre de pages du chemin de fer
extern int nbPages;
//Tableau des pages
extern TMemo *tabMemos [1000];
//Memos Couvertures
extern TMemo *memoCouv1;
extern TMemo *memoCouv2;
extern TMemo *memoCouv3;
extern TMemo *memoCouv4;
//Labels Couvertures
extern TLabel *labelCouv1;
extern TLabel *labelCouv2;
extern TLabel *labelCouv3;
extern TLabel *labelCouv4;
extern AnsiString titre;
//Fonctions
extern void effaceEcran();
extern void cheminDeFer(bool fromFile);

//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
        if(couv1)
        {
                CB_couv1->Checked=true;
                Button4->Enabled=true;
        }
        if(couv2)
        {
                CB_couv2->Checked=true;
                Button5->Enabled=true;
        }
        if(couv3)
        {
                CB_couv3->Checked=true;
                Button6->Enabled=true;
        }
        if(couv4)
        {
                CB_couv4->Checked=true;
                Button7->Enabled=true;
        }

        E_Titre->Text=titre;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::CB_couv1Click(TObject *Sender)
{
        if(Button4->Enabled==true)
                Button4->Enabled=false;
        else
                Button4->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::CB_couv2Click(TObject *Sender)
{
        if(Button5->Enabled==true)
                Button5->Enabled=false;
        else
                Button5->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::CB_couv3Click(TObject *Sender)
{
        if(Button6->Enabled==true)
                Button6->Enabled=false;
        else
                Button6->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::CB_couv4Click(TObject *Sender)
{
        if(Button7->Enabled==true)
                Button7->Enabled=false;
        else
                Button7->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
        //Test champ titre vide
        if(E_Titre->Text=="")
        {
                Application->MessageBox("Veuillez préciser un titre","CheminDeFer - Information",MB_OK | MB_ICONINFORMATION );
                return;
        }
        //Copie du titre
        titre=E_Titre->Text;
        Form2->label_Titre->Caption=titre;

        //Effacement des couvertures
        if(couv1 && CB_couv1->Checked==false)
        {
                memoCouv1->Visible=false;
                labelCouv1->Visible=false;
                couv1=false;
        }
        if(couv2 && CB_couv2->Checked==false)
        {
                memoCouv2->Visible=false;
                labelCouv2->Visible=false;
                couv2=false;
        }
        if(couv3 && CB_couv3->Checked==false)
        {
                memoCouv3->Visible=false;
                labelCouv3->Visible=false;
                couv3=false;
        }
        if(couv4 && CB_couv4->Checked==false)
        {
                memoCouv4->Visible=false;
                labelCouv4->Visible=false;
                couv4=false;
        }

        //Affichage des couvertures
        if(!couv1 && CB_couv1->Checked==true)
        {
                memoCouv1->Visible=true;
                labelCouv1->Visible=true;
                couv1=true;
        }
        if(!couv2 && CB_couv2->Checked==true)
        {
                memoCouv2->Visible=true;
                labelCouv2->Visible=true;
                couv2=true;
        }
        if(!couv3 && CB_couv3->Checked==true)
        {
                memoCouv3->Visible=true;
                labelCouv3->Visible=true;
                couv3=true;
        }
        if(!couv4 && CB_couv4->Checked==true)
        {
                memoCouv4->Visible=true;
                labelCouv4->Visible=true;
                couv4=true;
        }

        Form6->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender)
{
        Form6->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender)
{
        TFontDialog *dlgFont = new TFontDialog(Form2);
	if(dlgFont->Execute())
	{
                int i=0;
                while(tabMemos[i]!=NULL)
                {
	                tabMemos[i]->Font->Name  = dlgFont->Font->Name;
		        tabMemos[i]->Font->Size  = dlgFont->Font->Size;
		        tabMemos[i]->Font->Color = dlgFont->Font->Color;
		        tabMemos[i]->Font->Style = dlgFont->Font->Style;
                        i++;
                }
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button4Click(TObject *Sender)
{
        TFontDialog *dlgFont = new TFontDialog(Form2);
	if(dlgFont->Execute())
	{
                memoCouv1->Font->Name  = dlgFont->Font->Name;
                memoCouv1->Font->Size  = dlgFont->Font->Size;
                memoCouv1->Font->Color = dlgFont->Font->Color;
                memoCouv1->Font->Style = dlgFont->Font->Style;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button5Click(TObject *Sender)
{
        TFontDialog *dlgFont = new TFontDialog(Form2);
	if(dlgFont->Execute())
	{
                memoCouv2->Font->Name  = dlgFont->Font->Name;
                memoCouv2->Font->Size  = dlgFont->Font->Size;
                memoCouv2->Font->Color = dlgFont->Font->Color;
                memoCouv2->Font->Style = dlgFont->Font->Style;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button6Click(TObject *Sender)
{
        TFontDialog *dlgFont = new TFontDialog(Form2);
	if(dlgFont->Execute())
	{
                memoCouv3->Font->Name  = dlgFont->Font->Name;
                memoCouv3->Font->Size  = dlgFont->Font->Size;
                memoCouv3->Font->Color = dlgFont->Font->Color;
                memoCouv3->Font->Style = dlgFont->Font->Style;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button7Click(TObject *Sender)
{
        TFontDialog *dlgFont = new TFontDialog(Form2);
	if(dlgFont->Execute())
	{
                memoCouv4->Font->Name  = dlgFont->Font->Name;
                memoCouv4->Font->Size  = dlgFont->Font->Size;
                memoCouv4->Font->Color = dlgFont->Font->Color;
                memoCouv4->Font->Style = dlgFont->Font->Style;
	}
}
//---------------------------------------------------------------------------


