//
//  Renderer_SDL2.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Renderer.h"

#include <SDL.h>

#include <map>

class Renderer_SDL2 : public Renderer {
    friend class Texture_SDL2;

    SDL_Window* m_win;
    SDL_Renderer* m_rend;
    std::map<std::string, TextureRef> m_textureCache;
public:
    Renderer_SDL2(SDL_Window* win, SDL_Renderer* rend);
    ~Renderer_SDL2();

    void set_logical_size(Vector2i size, bool keepAspect = true);

    void set_swap_interval(int swap);
    void update_window_size();
    void clear(const Color& c = Color());
    void draw_rect_fill(const Recti& r, const Color& c);
    void present();

    TextureRef load_texture(const std::string& name);
    void draw_texture(TextureRef texture, const Recti& src, const Recti& dst, float angle = 0.0f);
private:
    void set_draw_color(const Color& c);
};
