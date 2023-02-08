#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
    public:
   // Constructeur par défaut de la classe: initialise le pixel à la couleur noire
   Pixel ();

   // Constructeur de la classe: initialise r,g,b avec les paramètres
    Pixel (int nr, int ng, int nb);

   // Accesseur : récupère la composante rouge du pixel
   int getRouge ()const;

   // Accesseur : récupère la composante verte du pixel
   int getVert ()const;
   
   // Accesseur : récupère la composante bleue du pixel
   int getBleu ()const;

 // Mutateur : modifie la composante rouge du pixel
   void setRouge (int nr);

   // Mutateur : modifie la composante verte du pixel
   void setVert (int ng);

   // Mutateur : modifie la composante bleue du pixel
   void setBleu (int nb);

    ~Pixel();
    
    private:
        unsigned char r,g,b; //le type "unsigned char" pour stocker des entiers non signés dans l'intervalle [0, 255]

};

#endif // PIXEL_H
