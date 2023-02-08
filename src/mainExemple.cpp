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
	
    return 0;
}

