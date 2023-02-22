#include <iostream>
#include "Pixel.h"
#include "Image.h"
using namespace std;

int main(void)
{
    cout<<"initialisation :---------------------------------------"<<endl;
	Pixel zero;
    Image Ima(10,10);
    Pixel pixcouleur(100,100,100);
    Pixel pixcouleur_2(100,100,255);
  	cout<<"-------------------------------------------------------"<<endl;
	
	cout<<"-------------------------------------------------------"<<endl;
	cout<<Ima.getPix(2,2).getBleu()<<" : bleu du pixel 2,2 initialement"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
	
	cout<<"-------------------------------------------------------"<<endl;
	Ima.setPix(2,2,pixcouleur);
	cout<<Ima.getPix(2,2).getBleu()<<" : bleu du pixel 2,2 aprés 1er modif"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	
	cout<<"-----------modification du bleu du pixel 2,2 à 3-------"<<endl;
	Ima.setPix(2,2,pixcouleur_2);
	cout<<Ima.getPix(2,2).getBleu()<<" : bleu du pixel 2,2 aprés le mettre à 3"<<endl;
	cout<<"-------------------------------------------------------"<<endl;

	cout<<"IMAGE EFFACE"<<endl;
	Ima.effacer(zero);
	
	cout << "----------------------------------------------------------------" <<endl;

	Pixel rouge (120, 15, 10);
    Pixel vert (20, 202, 15);
    Pixel bleu (4, 58, 218);
	Pixel blanc (250,250,250);
 
    Image image1 (64,48);
    image1.effacer(bleu);
    image1.dessinerRectangle(5, 20, 30, 40, rouge);
    image1.setPix(51,4,vert);
    image1.setPix(20,30,vert);
	image1.effacer(blanc);
    image1.sauver("./data/image1.ppm");
 
    Image image2;
    image2.ouvrir("./data/image1.ppm");
    image2.dessinerRectangle(29, 10, 48, 15, rouge);
    image2.dessinerRectangle(25, 24, 40, 45, vert);
    image2.sauver("./data/image2.ppm");

    return 0;
}

