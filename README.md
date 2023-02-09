# Module Image

## CONVENTION ##

Les noms des variables doivent êtres explicites, les premières lettres font références au type et la première lettre des variables doivent être en minuscule.

Commenter chaque ligne et chaques instructions importante.

CONSTANTE_MODELE en MAJUSCULE avec '_' pour les espaces.

Nom des classes avec la Première lettre en MAJ.

# Pour cloner le git : git clone lien.git

# Pour add un nouveau fichier au git : git add nom_du_fichier

# Pour commit le fichier modifier : git commit -a -m "COMMENTAIRE"

# Pour envoyer les modifications : git push

# Pour mettre à jour : git pull

---- NOTE MAJ1 ----
# Exécuter le bin
- Pour exécuter le bin, écrire dans le terminal > make bin
- aprés ./bin pour le lancer

# Le test de regression actuel n'est pas correcte (a mon avis) (Ca plante à l'execution), Dans le test de regression (a mon avis) il faut simplement manipuler monImage déclaré dans le mainTest.cpp, Donc il faut pas créer d'autres image dans la fonction testRegression(), mais simplement manipuler d'une façon exhaustif monImage.

# Problème réglé, Il suffit simplement de taper "make" 

---- Solution pour éviter de taper son num étudiant et mdp pour les push/pull ----
------------------------POUR CREER ET ETABLIR LIEN DU PROJET-----------------------------
1/- générer: ssh-keygen -t rsa -b 4096 -C "votre_email@exemple.com"
2/- copié: cat ~/.ssh/id_rsa.pub
3/- Copiez tout le texte affiché et collez-le dans la section "Key" sur votre compte Github lorsque vous ajoutez une nouvelle clé SSH.
4/- Copiez tout le texte affiché et collez-le dans la section "Key" sur votre compte Github lorsque vous ajoutez une nouvelle clé SSH.
	git clone git@github.com:superperx/Module_Image.git (git)
	git clone git@forge.univ-lyon1.fr:p2111020/Module_Image.git (forge)
et c'est bon !
-----------------------------------------------------------------------------------------
