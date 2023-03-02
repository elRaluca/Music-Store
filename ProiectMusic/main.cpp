#include <iostream>
#include <vector>
#include <algorithm>


class Product {
protected:
    double price{};
    std::string name;
public:
    Product() = default;
    virtual ~Product() = default;
    Product(const Product &) = default;
    Product(double _price, std::string _name) {
        this->price = _price;
        this->name = _name;
    }
    friend std::istream &operator>>(std::istream &in, Product &product) {
        product.read(in);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const Product &product) {
        product.print(out);
        return out;
    }
    virtual void read(std::istream &in) {
        std::cout << "price: ";
        in >> price;
        std::cout << "name: ";
        in >> name;
    }
    virtual void print(std::ostream &out) const {
        out << "price: " << price << "\n";
        out << "name: " << name << "\n";
    }
    virtual void isCompatibleWith(Product *other) {
        std::cout << "Are they compatible?";
    }
};

class Song : public Product {
protected:
    int nrAuthors{};
    std::vector<std::string> authors;
    int length{};
    std::string title;
public:
    Song() = default;
    virtual ~Song() = default;
    Song(double _price, std::string _name, int _nrAuthors, std::vector<std::string> _authors,
         std::string _title, int _length) : Product(_price, _name) {
        this->nrAuthors = _nrAuthors;
        this->authors = _authors;
        this->title = _title;
        this->length = _length;
    }
    Song(const Song &) = default;
    friend std::istream &operator>>(std::istream &in, Song &song) {
        song.read(in);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const Song &song) {
        song.print(out);
        return out;
    }
    const std::string &getTitle() const {
        return title;
    }
    void read(std::istream &in) override {
        Product::read(in);
        std::cout << "numar autori: ";
        in >> nrAuthors;
        std::cout << "author(s): ";
        for (int i = 0; i < nrAuthors; i++) {
            std::string author;
            std::cout << "autorul " << i << ":  ";
            in >> author;
            authors.push_back(author);
        }
        std::cout << "title: ";
        in >> title;
        std::cout << "length: ";
        in >> length;
    }
    void print(std::ostream &out) const {
        Product::print(out);
        out << "authors: ";
        for (auto &p: authors) {
            out << p << " ";
        }
        out << "title: " << title << ",  ";
        out << "length: " << length;
    }
    virtual void isCompatibleWith(Product *other) override {
        Song *asSong = dynamic_cast<Song *>(other);
        if (asSong != nullptr) {
            if (authors == asSong->authors)
                std::cout << "Is compatible with\n";
            else
                std::cout << "Is not compatible with\n ";
        }
    }
};

class MusicPlayer : public Product {
protected:
    std::string title;
    std::string singer;
public:
    MusicPlayer() = default;
    virtual ~MusicPlayer() = default;
    MusicPlayer(double _price, std::string _name, std::string _title,
                std::string _singer) : Product(_price, _name) {
        this->title = _title;
        this->singer = _singer;
    }
    MusicPlayer(const MusicPlayer &) = default;
    friend std::istream &operator>>(std::istream &in, MusicPlayer &musicPlayer) {
        musicPlayer.read(in);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const MusicPlayer &musicPlayer) {
        musicPlayer.print(out);
        return out;
    }
    const std::string &getTitle() const {
        return title;
    }
    void read(std::istream &in) override {
        Product::read(in);
        std::cout << "title: ";
        in >> title;
        std::cout << "singer: ";
        in >> singer;
    }
    void print(std::ostream &out) const override {
        Product::print(out);
        out << "title: " << title << "," << "singer: " << singer;
    }
};

class Sticker : public Product {
private:
    std::string printed_text;
public:
    Sticker() = default;
    ~Sticker() = default;
    Sticker(const Sticker &) = default;
    Sticker(double _price, std::string _name, std::string _printedText) : Product(_price, _name) {
        this->printed_text = _printedText;
    }
    friend std::istream &operator>>(std::istream &in, Sticker &sticker) {
        sticker.read(in);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const Sticker &sticker) {
        sticker.print(out);
        return out;
    }
    void read(std::istream &in) override {
        Product::read(in);
            std::cout << "printed text: ";
            in >> printed_text;}
    void print(std::ostream &out) const override {
        Product::print(out);
        out << "printed text: " << printed_text;
    }
    virtual void isCompatibleWith(Product *other) override {
        Song *asSong = dynamic_cast<Song *>(other);
        if (asSong != nullptr) {
            std::size_t found;
            found = this->printed_text.find(asSong->getTitle());
            if (found != std::string::npos) {
                std::cout << "Is compatible with\n";
            } else
                std::cout << "Is not compatible with\n";
        }
        MusicPlayer *asMusicPlayer = dynamic_cast<MusicPlayer *>(other);
        if (asMusicPlayer != nullptr) {
            std::size_t found;
            found = this->printed_text.find(asMusicPlayer->getTitle());
            if (found != std::string::npos) {
                std::cout << "Is compatible with\n";
            } else
                std::cout << "Is not compatible with\n";
        }

    }
};

class Vinyl : public Song {
public:
    Vinyl() : Song() {};
    ~Vinyl() = default;
    Vinyl(double _price, std::string _name, int _nrAuthors, std::vector<std::string> _authors,
          std::string _title, int _length) : Song(_price, _name, _nrAuthors, _authors, _title, _length) {}
    Vinyl(const Vinyl &) = default;
    friend std::istream &operator>>(std::istream &in, Vinyl &vinyl) {
        vinyl.read(in);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const Vinyl &vinyl) {
        vinyl.print(out);
        return out;
    }
};

class CD : public Song {
public:
    CD() : Song() {};
    ~CD() = default;
    CD(double _price, std::string _name, int _nrAuthors, std::vector<std::string> _authors,
       std::string _title, int _length) : Song(_price, _name, _nrAuthors, _authors, _title, _length) {}
    CD(const CD &) = default;
    friend std::istream &operator>>(std::istream &in, CD &cd) {
        cd.read(in);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const CD &cd) {
        cd.print(out);
        return out;
    }
};

class VinylPlayer : public MusicPlayer {
public:
    VinylPlayer() : MusicPlayer() {};
    ~VinylPlayer() = default;
    VinylPlayer(const VinylPlayer &) = default;

    VinylPlayer(double _price, std::string _name,
                std::string _title, std::string _singer) : MusicPlayer(_price, _name, _title, _singer) {}


    friend std::istream &operator>>(std::istream &in, VinylPlayer &vinylPlayer) {
        vinylPlayer.read(in);
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const VinylPlayer &vinylPlayer) {
        vinylPlayer.print(out);
        return out;
    }

    virtual void isCompatibleWith(Product *other) override {
        Vinyl *asVinyl = dynamic_cast<Vinyl *>(other);
        if (asVinyl != nullptr) {
            std::cout << "Is compatible with\n";
        } else
            std::cout << "Is not compatible with\n";
    }
};

class CDPlayer : public MusicPlayer {
private:
public:
    CDPlayer() : MusicPlayer() {};
    ~CDPlayer() = default;
    CDPlayer(double _price, std::string _name,
             std::string _title, std::string _singer) : MusicPlayer(_price, _name, _title, _singer) {}
    CDPlayer(const CDPlayer &) = default;
    friend std::istream &operator>>(std::istream &in, CDPlayer &cdPlayer) {
        cdPlayer.read(in);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const CDPlayer &cdPlayer) {
        cdPlayer.print(out);
        return out;
    }
    virtual void isCompatibleWith(Product *other) override {
        CD *asCD = dynamic_cast<CD *>(other);
        if (asCD != nullptr) {
            std::cout << "Is compatible with\n";
        } else
            std::cout << "Is not compatible with\n";
    }
};

class MusicStore {
private:
    std::vector<Product *> products;
public:
    MusicStore() = default;
    ~MusicStore() = default;
    MusicStore(std::vector<Product *> _products) {
        this->products = _products;
    }
    MusicStore(const MusicStore &) = default;
    void addProduct() {
        int conditieCitire = 0;
        int tip;
        while (conditieCitire == 0) {
            std::cout << "Inserati tipul produsului\n";
            std::cout << "1.Song\n";
            std::cout << "2.Vinyl\n";
            std::cout << "3.CD\n";
            std::cout << "4.MusicPlayes\n";
            std::cout << "5.VinylPlayer\n";
            std::cout << "6.CDPlayer\n";
            std::cout << "7.Sticker\n";
            std::cin >> tip;
           conditieCitire = 1;
            if (tip == 1) {
                auto *p = new Song;
                std::cin >> *p;
                products.push_back(p);
            } else if (tip == 2) {
                auto *p = new Vinyl;
                std::cin >> *p;
                products.push_back(p);
            } else if (tip == 3) {
                auto *p = new CD;
                std::cin >> *p;
                products.push_back(p);
            } else if (tip == 4) {
                auto *p = new MusicPlayer;
                std::cin >> *p;
                products.push_back(p);
            } else if (tip == 5) {
                auto *p = new VinylPlayer;
                std::cin >> *p;
                products.push_back(p);
            } else if (tip == 6) {
                auto *p = new CDPlayer;
                std::cin >> *p;
                products.push_back(p);
            } else if (tip == 7) {
                auto *p = new Sticker;
                std::cin >> *p;
                products.push_back(p);
            }else{

                std::cout << "Eroare: Optiune gresita!\n";
                conditieCitire = 0;
            }

        }
    }

    const std::vector<Product *> &getProducts() const {
        return products;
    }

    void addProduct(Product &p) {
        products.push_back(&p);
    }

};

int main() {
    MusicStore musicStore;
    Song song(20, "Azi", 1, {"Maria"}, "clasic", 15);
    Song song2(67, "Rock", 1, {"Ivan"}, "Rock", 10);
    song.isCompatibleWith(&song2);
    Sticker sticker(30, "Craciun", "Colinde de Craciun");
    sticker.isCompatibleWith(&song2);
    MusicPlayer musicPlayer(80, "player_music", "Noapte", "JO");
    sticker.isCompatibleWith(&musicPlayer);
    Vinyl vinyl(45, "vinyl", 1, {"Andreea"}, "vinyl", 37);
    VinylPlayer vinylPlayer(100, "vinylPlayer", "PlayerV", "Andrei");
    vinylPlayer.isCompatibleWith(&vinyl);
    CD cd(90, "cd", 1, {"Ilinca"}, "cd", 70);
    CDPlayer cdPlayer(86, "cdplayer", "cdP", "Edi");
    cdPlayer.isCompatibleWith(&cd);
    cdPlayer.isCompatibleWith(&song);
    return 0;
}