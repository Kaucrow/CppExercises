using std::string;

enum Category {ROCK, POP, METAL, JAZZ, COUNTRY, BLUES};

class Song{
    private:
        string title, artist;
        struct{
            int minutes, seconds;
        }Time;
        Category genre;
    public:
        Song();
        Song(string, string, int, int, Category);
        void SetTitle(string);
        void SetArtist(string);
        void SetMinutes(int);
        void SetSeconds(int);
        void SetGenre(Category);
        string GetData() const;
        bool Equal(Song) const;
};