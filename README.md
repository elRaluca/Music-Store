# Music-Store
#Make a shopping cart and check whether the pair (music, player, sticker) fit well with each other.
#Another requirement will be to print the groups of compatible products (bonus, because you compute mathematical sets).

#Classes you will have three categories of Products: Music, Player, and Sticker.
#All of them have a price and a name, but:

#A Song also contains its author(s), a  title and its length (seconds)
#A music player also contains the title and the singer
#A sticker also includes an extra string -> the text it has printed on it

#Songs are of two types: Vinyl and CD;
#And music players also have two types: VinylPlayer and CdPlayer.

#Two product are compatible in one of the next cases:

#Two Songs are compatible if they have the same author.
#A Song and a MusicPlayer are compatible if the Song is a Vinyl- and the MusicPlayer is a VinylPlayer, and similarly for CD and CdPlayer
#A sticker is compatible with any Song that have common words with the Sticker’s message
#A sticker is compatible with any MusicPlayer that have common words with the Sticker’s message

#Cerinte:

#Implementati corect si complet ierarhia de clase (40% din punctaj). Inclusiv << si >> pentru fiecare obiect in parte.

#Creati si clasa MusicStore care va putea retina un vector de Product’s alocate dinamic (20% din punctaj)
	

#*alocate, adica nu vectorul, ci fiecare produs in parte, dupa modelul

#Product *products[100];
#// iar cand adaugam un nou produs vom face, spre exemplu,
#products[0] = new MusicPlayer(...)

#Adaugati in main un exemplu care sa contina cel putin 5 produse de tipuri diferite dintre care sa existe macar 3 perechi compatibile.

#Creati o metoda a magazinului care va afisa produsele compatible sub forma:

#VinylPlayer(..) is compatible with  Vinyl ()

#	*pentru simplitate, creati functia virtual isCompatibleWith(Product *other)

#Creati o functie pentru adaugarea unui nou produs, cu doua supraincarcari:

#void addProduct() 

#	Vom citi prima data tipul produsul, iar apoi vom apela >> pe un obiect temporar.

#void addProduct(const Product& p)
#	Va trebui prima data sa aflam tipul produsului. Folosim dynamic_cast.

