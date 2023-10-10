#include "enemy.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

using namespace godot;


Enemy::Enemy()
{
    speed = 50;
    player_position = Vector2(0, 0);
}

Enemy::~Enemy()
{
}

void Enemy::_bind_methods()
{
}

void Enemy::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) return;

    Object* globals = get_tree()->get_root()->get_node<Object>(NodePath("Globals"));
    player_position = globals->call("get_player_position");
    Vector2 direction = (player_position - get_global_position()).normalized();
    set_velocity(direction * speed);
    move_and_slide();
}
