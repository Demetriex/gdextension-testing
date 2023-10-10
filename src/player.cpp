#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/timer.hpp>

using namespace godot;

Player::Player()
{
    speed = 300;
}

Player::~Player()
{
}


void Player::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) return;

    Input& input = *Input::get_singleton();
    Vector2 direction = input.get_vector("left", "right", "up", "down");
    set_velocity(direction * speed);
    move_and_slide();
}

void Player::_bind_methods() 
{
}
