//---------------------------------------------------------------------------
//CREATEUR DE CHEMIN DE FER
//(c) 2007 JOEL MOLL - VINCENT VILLAIN
//C++ Builder 6.0
//Form d'affichage
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------------

#include <fstream.h>
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.cpp"
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
//Variables Globales
//---------------------------------------------------------------------------

//Form
TForm2 *Form2;
//Booleens de couvertures
bool couv1,couv2,couv3,couv4=false;
//Memos Couvertures
TMemo *memoCouv1;
TMemo *memoCouv2;
TMemo *memoCouv3;
TMemo *memoCouv4;
//Labels Couvertures
TLabel *labelCouv1;
TLabel *labelCouv2;
TLabel *labelCouv3;
TLabel *labelCouv4;
//Tableau des pages
TMemo *tabMemos [1000];
//Tableau des labels
TLabel *tabLabels [1000];
//Compteur de pages inscrites
int cptPages;
//Fichier à lire
fstream ficCdf;
char ligne[255]="";
//Titre du projet
AnsiString titre="";
//Nombre de pages
int nbPages=0;

//---------------------------------------------------------------------------
//Création de la form
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
//Fonction Réinitialisation de l'écran
//---------------------------------------------------------------------------
void effaceEcran()
{
        effaceMemo(memoCouv1);
        effaceMemo(memoCouv2);
        effaceMemo(memoCouv3);
        effaceMemo(memoCouv4);
        effaceLabel(labelCouv1);
        effaceLabel(labelCouv2);
        effaceLabel(labelCouv3);
        effaceLabel(labelCouv4);

        int i=0;
        while(tabMemos[i]!=NULL)
        {
                effaceMemo(tabMemos[i]);
                effaceLabel(tabLabels[i]);
                i++;
        }
        cptPages=0;
}

//---------------------------------------------------------------------------
//Fonction Affichage du chemin de Fer
//---------------------------------------------------------------------------

void cheminDeFer(bool fromFile)
{
        //Activation du menu
        Form2->Enregistrer1->Enabled=true;
        Form2->Imprimer1->Enabled=true;
        Form2->Insrer1->Enabled=true;
        Form2->Couper1->Enabled=true;
        Form2->Options1->Enabled=true;

        //Première de couverture
        labelCouv1=creerLabel(135,155,"1ère de Couv",(TForm *) Form2);
        memoCouv1=creerMemoCouv(115,30,&couv1,&fromFile,&ficCdf,labelCouv1,(TForm *) Form2);

        //Deuxième de couverture (sommaire)
        labelCouv2=creerLabel(260,155,"2e de Couv",(TForm *) Form2);
        memoCouv2=creerMemoCouv(235,30,&couv2,&fromFile,&ficCdf,labelCouv2,(TForm *) Form2);

        //Reste pages pour couv3-couv4
        int reste;
        int nbLignesSup;

        //Affichage des pages : cas nbpages<=5 : une seule ligne
        if(nbPages<=5)
        {
                //Décalage de l'affichage
                for(int i=3;i<=nbPages+2;i++)
                {
                        //Affichage page
                        TMemo *m=creerMemo(15+i*100+(i/2)*20,30,(TForm *) Form2);
                        if(fromFile)
                                lireTexteMemo(m,&ficCdf);
                        //Ajout de la page au tableau
                        tabMemos[cptPages]=m;

                        //Affichage label
                        TLabel *l=creerLabel(15+i*100+(i/2)*20+45,155,IntToStr(i-2),(TForm *) Form2);
                        //Ajout du label au tableau
                        tabLabels[cptPages]=l;
                        cptPages++;
                }
                reste=nbPages+2;
                nbLignesSup=0;

        }else{

                //Affichage des lignes : cas nbpages>=5

                //Affichage de la première ligne
                for(int i=3;i<=7;i++)
                {
                        //Affichage page
                        TMemo *m=creerMemo(15+i*100+(i/2)*20,30,(TForm *) Form2);
                        if(fromFile)
                                lireTexteMemo(m,&ficCdf);
                        //Ajout de la page au tableau
                        tabMemos[cptPages]=m;

                        //Affichage label
                        TLabel *l=creerLabel(15+i*100+(i/2)*20+45,155,IntToStr(i-2),(TForm *) Form2);
                        //Ajout du label au tableau
                        tabLabels[cptPages]=l;
                        cptPages++;
                }

               //Calcul du nombre de lignes supplémentaires
                if(nbPages<=13)
                        nbLignesSup=1;
                else
                        nbLignesSup=(nbPages+3)/8;
                int iSuite=6;

//Affichage des lignes suivantes sauf la dernière
for(int j=1;j<nbLignesSup;j++)
{
        for(int i=0;i<=7;i++)
        {
                //Affichage page
                TMemo *m=creerMemo(15+i*100+(i/2)*20,30+j*120+j*30,(TForm *) Form2);
                if(fromFile)
                        lireTexteMemo(m,&ficCdf);
                //Ajout de la page au tableau
                tabMemos[cptPages]=m;

                //Affichage label
                TLabel *l=creerLabel(15+i*100+(i/2)*20+45,155+150*j,IntToStr(iSuite+i),(TForm *) Form2);
                //Ajout du label au tableau
                tabLabels[cptPages]=l;
                cptPages++;
        }
        iSuite=iSuite+8;
}

//Calcul des pages restantes
reste=nbPages-iSuite;

//Affichage de la dernière ligne
for(int i=0;i<=reste;i++)
{
        //Affichage page
        TMemo *m=creerMemo(15+i*100+(i/2)*20,30+nbLignesSup*120+nbLignesSup*30,(TForm *) Form2);
        if(fromFile)
                lireTexteMemo(m,&ficCdf);
        //Ajout de la page au tableau
        tabMemos[cptPages]=m;

        //Affichage label
        TLabel *l=creerLabel(15+i*100+(i/2)*20+45,155+150*nbLignesSup,IntToStr(iSuite+i),(TForm *) Form2);
        //Ajout du label au tableau
        tabLabels[cptPages]=l;
        cptPages++;
}
}
reste++;

if(reste>=8)
{
        nbLignesSup++;
        reste=0;
}

//3e de couverture de couverture
labelCouv3=creerLabel(reste*100+(reste/2)*20+45,155+150*nbLignesSup,"3e de Couv",(TForm *) Form2);
memoCouv3=creerMemoCouv(15+reste*100+(reste/2)*20,30+nbLignesSup*120+nbLignesSup*30,&couv3,&fromFile,&ficCdf,labelCouv3,(TForm *) Form2);

reste++;


if(reste>=8)
{
        nbLignesSup++;
        reste=0;
}

//4e de couverture de couverture
labelCouv4=creerLabel(reste*100+(reste/2)*20+45,155+150*nbLignesSup,"4e de Couv",(TForm *) Form2);
memoCouv4=creerMemoCouv(15+reste*100+(reste/2)*20,30+nbLignesSup*120+nbLignesSup*30,&couv4,&fromFile,&ficCdf,labelCouv4,(TForm *) Form2);
}

//---------------------------------------------------------------------------
//Fermature de la form par le menu
//---------------------------------------------------------------------------
void __fastcall TForm2::Quitter1Click(TObject *Sender)
{
        if(Application->MessageBox("Fermer l'application ?","CheminDeFer - Fermeture",MB_YESNO|MB_ICONQUESTION )==IDYES)
        {
                Application->Terminate();
        }
}

//---------------------------------------------------------------------------
//Fermeture de la form
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(Application->MessageBox("Fermer l'application ?","CheminDeFer - Fermeture",MB_YESNO|MB_ICONQUESTION )==IDYES)
        {
                Application->Terminate();
        }else{
                Application->Run();
        }
}

//---------------------------------------------------------------------------
//Nouveau
//---------------------------------------------------------------------------
void __fastcall TForm2::Nouveau1Click(TObject *Sender)
{
Application->CreateForm(__classid(TForm1), &Form1);
Form1->Visible=true;
}

//---------------------------------------------------------------------------
//Enregistrer
//---------------------------------------------------------------------------

void __fastcall TForm2::Enregistrer1Click(TObject *Sender)
{
if(SaveDialog1->Execute())
{
        FILE *f=fopen(SaveDialog1->FileName.c_str(),"rb");
        if(f!=NULL)
        {
                if(Application->MessageBox("Ecraser le fichier ?","CheminDeFer - Sauvegarde",MB_YESNO|MB_ICONEXCLAMATION )==IDNO)
                        return;
        }

        //Ouverture Fichier
        std::ofstream fic(SaveDialog1->FileName.c_str(),std::ios::trunc);

        //Sauvegarde du nom
        fic<<titre.c_str()<<"\n";

        //Sauvegarde des choix de couvertures
        ecrireBooleen(&fic,&couv1);
        ecrireBooleen(&fic,&couv2);
        ecrireBooleen(&fic,&couv3);
        ecrireBooleen(&fic,&couv4);

        //Sauvegarde nombre de pages
        fic<<nbPages<<"\n";

        //Sauvegardes couv
        if(couv1)
                ecrireMemo(&fic,memoCouv1);
        if(couv2)
                ecrireMemo(&fic,memoCouv2);

        //Parcours des Memos
        int i=0;
        while(tabMemos[i]!=NULL)
        {
                ecrireMemo(&fic,tabMemos[i]);
                i++;
        }

        if(couv3)
                ecrireMemo(&fic,memoCouv3);
        if(couv4)
                ecrireMemo(&fic,memoCouv4);

        fic.close();

        Form2->Caption="Créateur de Chemin De Fer v1.1 - <"+SaveDialog1->FileName+">";
        Application->MessageBox("Sauvegarde effectuée","CheminDeFer - Sauvegarde",MB_OK | MB_ICONINFORMATION);
}
}

//---------------------------------------------------------------------------
//Ouvrir
//---------------------------------------------------------------------------

void __fastcall TForm2::Ouvrir1Click(TObject *Sender)
{
if(OpenDialog1->Execute())
{
        //Init Projet
        effaceEcran();

        ficCdf.open(OpenDialog1->FileName.c_str());
        int choix;
        char ctitre[255];

        //Titre
        memset(ligne,0,255);
        ficCdf.getline(ligne,255);
        strcpy(ctitre,ligne);
        titre=ctitre;
        memset(ligne,0,255);
        //Premiere de couv
        ficCdf.getline(ligne,2);
        sscanf(ligne,"%d",&choix);
        if(choix==1)
                couv1=true;
        //Deuxieme de couv
        ficCdf.getline(ligne,2);
        sscanf(ligne,"%d",&choix);
        if(choix==1)
                couv2=true;
        //Troisieme de couv
        ficCdf.getline(ligne,2);
        sscanf(ligne,"%d",&choix);
        if(choix==1)
                couv3=true;
        //Quatrieme de couv
        ficCdf.getline(ligne,2);
        sscanf(ligne,"%d",&choix);
        if(choix==1)
                couv4=true;

        //Nombre de pages
        ficCdf.getline(ligne,5);
        sscanf(ligne,"%d",&nbPages);

        //Test nombre de pages
        if(nbPages<0 || nbPages>1000)
        {
                Application->MessageBox("Nombre de pages dans le fichier invalide","CheminDeFer - Erreur",MB_OK | MB_ICONERROR);
                ficCdf.close();
                return;
        }

        //Affichage de la form chemin de fer
        Form2->Caption="Créateur de Chemin De Fer v1.1 - <"+OpenDialog1->FileName+">";
        Form2->label_Titre->Caption=titre;
        cheminDeFer(true);

        ficCdf.close();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Imprimer1Click(TObject *Sender)
{
        PrintDialog1->Execute();
        Form2->Print();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Insrer1Click(TObject *Sender)
{
        Application->CreateForm(__classid(TForm3), &Form3);
        Form3->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Couper1Click(TObject *Sender)
{
        Application->CreateForm(__classid(TForm4), &Form4);
        Form4->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Options1Click(TObject *Sender)
{
        Application->CreateForm(__classid(TForm6), &Form6);
        Form6->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Apropos1Click(TObject *Sender)
{
        Form5->Visible=true;
}
//---------------------------------------------------------------------------



