#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/window.hpp>

using namespace godot;

Player::Player()
{
    speed = 300;
}

Player::~Player()
{
}

void Player::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("_on_timeout"), &Player::_on_timeout);
}

void Player::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) return;

    Timer* timer = get_node<Timer>(NodePath("Timer"));
    timer->connect("timeout", Callable(this, "_on_timeout"));
}

void Player::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) return;

    Input& input = *Input::get_singleton();
    Vector2 direction = input.get_vector("left", "right", "up", "down");
    set_velocity(direction * speed);
    move_and_slide();
}

void Player::_on_timeout()
{
    Object* global = get_tree()->get_root()->get_node<Object>(NodePath("Globals"));
    global->call("set_player_position", get_global_position());
}
