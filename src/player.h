#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/character_body2d.hpp>

namespace godot {

class Player : public  CharacterBody2D{
    GDCLASS(Player, CharacterBody2D)

private:
    double speed;

protected:
    static void _bind_methods();

public:
    Player();
    ~Player();

    void _ready();
    void _on_timeout();
    void _physics_process(double delta);
};

}

#endif