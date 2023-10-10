#ifndef ENEMY_H
#define ENEMY_H

#include <godot_cpp/classes/character_body2d.hpp>

namespace godot {

class Enemy : public  CharacterBody2D{
    GDCLASS(Enemy, CharacterBody2D)

private:
    double speed;
    Vector2 player_position;

protected:
    static void _bind_methods();

public:
    Enemy();
    ~Enemy();

    void _physics_process(double delta);
};

}

#endif