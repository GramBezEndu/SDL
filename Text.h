#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

class Text
{
    private:
        int x;
        int y;
        int w;
        int h;
    public:
        SDL_Surface* textSurface;
        bool apply_text(Window &, std::string, int x, int y);
};

#endif // TEXT_H_INCLUDED
