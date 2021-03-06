//
//  Game.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Renderer.h"
#include "Player.h"
#include "Renderable.h"
#include "Enemy.h"
#include "Explosion.h"

#include <list>

class Game {
public:
    enum InputForce {
        InputForce_X_AXIS,
        InputForce_Y_AXIS,
        InputForce_SHOOT,
        InputForce_START,
        InputForce_MAX,
    };
private:
    Renderer& m_renderer;
    Player m_Player;

    float inputValues[InputForce_MAX];

    std::list<Projectile> m_projectiles;
    std::list<Enemy> m_enemies;
    std::list<Explosion> m_explosions;

    static const int MAX_LAYERS = 2;

    std::list<Renderable*> m_renderables[MAX_LAYERS];
    std::list<Updatable*> m_updatables;
public:
    Game(Renderer& r);

    void apply_input(InputForce force, float value);

    void update(float delta);
    void render();

    void add_renderable(Renderable* renderable, int layer = 0);
    void remove_renderable(Renderable *renderable, bool updatable_also = true);
private:
    void fire_torpedo(Player& player);
    void check_enemies();
    void check_collisions();
};