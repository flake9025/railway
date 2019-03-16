//---------------------------------------------------------------------------
//CREATEUR DE CHEMIN DE FER
//(c) 2007 JOEL MOLL - VINCENT VILLAIN
//C++ Builder 6.0
//Form de suppression
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit4.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
//Variables Globales
//---------------------------------------------------------------------------

//Form
TForm4 *Form4;
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
//Fonctions
extern void effaceEcran();
extern void cheminDeFer(bool fromFile);

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
        UpDown1->Max=nbPages;
        UpDown2->Max=nbPages;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
        Form4->Visible=false;        
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
        int pageDebut=E_pgDebut->Text.ToInt();
        if(pageDebut==0 || pageDebut>nbPages)
        {
                Application->MessageBox("Saisie de départ invalide","CheminDeFer - Supprimer",MB_OK | MB_ICONERROR);
                return;
        }
        int pageFin=E_pgFin->Text.ToInt();
        if(pageFin<pageDebut || pageFin>nbPages)
        {
                Application->MessageBox("Saisie de fin invalide","CheminDeFer - Supprimer",MB_OK | MB_ICONERROR);
                return;
        }
        int pagesASupprimer=pageFin-pageDebut+1;

        TMemo *tabBackup [500];
        TMemo *memoCouv1backup=memoCouv1;
        TMemo *memoCouv2backup=memoCouv2;
        TMemo *memoCouv3backup=memoCouv3;
        TMemo *memoCouv4backup=memoCouv4;

        for(int i=0;i<500;i++)
                tabBackup[i]=tabMemos[i];

        effaceEcran();
        nbPages=nbPages-pagesASupprimer;
        cheminDeFer(false);

        int i=0;
        int index=pageDebut-1;

        while(i!=index)
        {
               tabMemos[i]->Text=tabBackup[i]->Text;
               i++;
        }

        int i2=pageFin;

        while(tabBackup[i2]!=NULL)
        {
               tabMemos[i]->Text=tabBackup[i2]->Text;
               i++;
               i2++;
        }

        if(couv1)
                memoCouv1->Text=memoCouv1backup->Text;
        if(couv2)
                memoCouv2->Text=memoCouv2backup->Text;
        if(couv3)
                memoCouv3->Text=memoCouv3backup->Text;
        if(couv4)
                memoCouv4->Text=memoCouv4backup->Text;

        Form4->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
        E_pgFin->Text=E_pgDebut->Text;
}
//---------------------------------------------------------------------------
