#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"

class Image
{
    public:
        // Constructeur par défaut de la classe: initialise dimx et dimy à 0
        // ce constructeur n'alloue pas de pixel
        Image();
        
        ~Image();
        
        // Constructeur de la classe: initialise dimx et dimy (après vérification)
        // puis alloue le tableau de pixel dans le tas (image noire)
        Image (int dimensionX, int dimensionY);

        // Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
        // la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
        Pixel& getPix (int x,int y);

        // Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
        void dessinerRectangle (int Xmin,int Ymin,int Xmax,int Ymax, Pixel couleur);
        
        // Mutateur : modifie le pixel de coordonnées (x,y)
	    void setPix(int x, int y, const Pixel& couleur);

        //
        void effacer (Pixel couleur);

        //
        void testRegression ();

        /*
        //
        void sauver(const string & filename) const;

        //
        void ouvrir(const string & filename);

        //
        void afficherConsole();

        //
        void afficher ();
        */

    private:
        int dimx, dimy; //dimx, dimy : entier        // les dimensions de l'image
        Pixel* tab;   //tab : tableau de Pixel     // le tableau 1D de pixel

};

#endif // IMAGE_H
