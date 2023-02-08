#include "Image.h"
#include "Pixel.h"

#include <string>
#include <iostream>
#include <cassert>

using namespace std;

Image::Image()
{
    dimx=0;
    dimy=0;
    tab = NULL;
}

Image::~Image()
{
    delete [] tab; tab = NULL;
    dimx=0;
    dimy=0;
}

Image::Image (int dimensionX, int dimensionY)
{	
	assert (dimensionX > 0 && dimensionY > 0);
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel [dimy*dimx];
}

// Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
// la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]

Pixel& Image::getPix (int x, int y)
{
    int indice = y*dimx+x;
	assert (dimx > 0);
    return tab[indice];
}

// Mutateur : modifie le pixel de coordonnées (x,y)

void Image::setPix(int x, int y, const Pixel& couleur)
{

   this->getPix(x,y).setRouge(couleur.getRouge());
   this->getPix(x,y).setVert(couleur.getVert());
   this->getPix(x,y).setBleu(couleur.getBleu());

   assert (this->getPix(x,y).getRouge() == couleur.getRouge() && this->getPix(x,y).getVert() == couleur.getVert() && this->getPix(x,y).getBleu() == couleur.getBleu());

}

void Image::dessinerRectangle (int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur)
{
    for (int x = Xmin; x <= Xmax; x++)
    {
        for (int y = Ymin; y <= Ymax; y++)
        {
            setPix(x, y, couleur);
			assert (this->getPix(x,y).getRouge() == couleur.getRouge() && this->getPix(x,y).getVert() == couleur.getVert() && this->getPix(x,y).getBleu() == couleur.getBleu());
        }
    }
}

void Image::effacer(Pixel couleur)
{
    dessinerRectangle(0, 0, dimx, dimy, couleur);

	for (int x = 0; x <= dimx; x++)
    {
        for (int y = 0; y <= dimy; y++)
        {
			assert (this->getPix(x,y).getRouge() == couleur.getRouge() && this->getPix(x,y).getVert() == couleur.getVert() && this->getPix(x,y).getBleu() == couleur.getBleu());
        }
    }

}


// Effectue une série de tests vérifiant que le module fonctionne et
   // que les données membres de l'objet sont conformes

void Image::testRegression ()
{
    /*
	Pixel pix;
	//cout<<pix.getRouge()<<","<<pix.getVert()<<","<<pix.getBleu()<<"devrait etre 0,0,0"<<endl;
	assert(pix.getRouge()==0);
	assert(pix.getVert()==0);
	assert(pix.getBleu()==0);
	
	Pixel pixm(11,22,33);
	//cout<<pixm.getRouge()<<","<<pixm.getVert()<<","<<pixm.getBleu()<<"devrait etre 11,22,33"<<endl;
	assert(pixm.getRouge()==11);
	assert(pixm.getVert()==22);
	assert(pixm.getBleu()==33);
	
	
	pixm.setRouge(44);
	pixm.setVert(55);
	pixm.setBleu(66);
	
	//cout<<"est couleurs"<<pixm.getRouge()<<","<<pixm.getVert()<<","<<pixm.getBleu()<<"devrait etre 44,55,66"<<endl;
	assert(pixm.getRouge()==44);
	assert(pixm.getVert()==55);
	assert(pixm.getBleu()==66);
	
	//image
	//cout<<"initialisation :---------------------------------------"<<endl;
	Image Image1(10,10);
	Image Image2(100,100);
	Image Image3(30,20);
	Pixel pixcouleur(100,100,100);
	Pixel pixcouleur_2(3,3,3);
	
	//cout<<"-------------------------------------------------------"<<endl;
	//cout<<Image1.getPix(2,2).getBleu()<<" : (ima 1) bleu du pixel 2,2 initialement"<<endl;
	assert(Image1.getPix(2,2).getBleu()==0);
	assert(Image1.getPix(2,2).getVert()==0);
	assert(Image1.getPix(2,2).getRouge()==0);
	
	//cout<<Image2.getPix(2,2).getBleu()<<" : (ima 2)bleu du pixel 2,2 initialement"<<endl;
	
	assert(Image2.getPix(2,2).getBleu()==0);
	assert(Image3.getPix(2,2).getBleu()==0);
	    
	//cout<<"-----------tous les couleurs des pixels a 100--------------------"<<endl;
	Image1.effacer(pixcouleur);
	Image2.effacer(pixcouleur);
	Image3.effacer(pixcouleur);
	assert(Image1.getPix(2,2).getBleu()==100);
	assert(Image2.getPix(2,2).getBleu()==100);
	assert(Image3.getPix(2,2).getBleu()==100);
	
	
	Image2.dessinerRectangle(1, 1, 10, 10, pixcouleur_2);
	assert(Image2.getPix(3,3).getBleu()==3);
	//assert(Image2.getPix(0,0).getBleu()==100);
	*/
}

/*
//
void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x++,y);
            fichier << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

//
void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	char r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> b >> g;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

//
void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}

//
void Image::afficher (){

}
*/

