#pragma once
#define M_PI 3.14159265358979323846

struct parameters {
	static constexpr int game_width = 1280;
	static constexpr int game_height = 720;
	static constexpr char const* level1 = "assets/levels/level1.txt";
	static constexpr float tile_size = 32.f;

    // Player physics
    static constexpr float player_size[2] = { 20.f,30.f };
    static constexpr float player_weight = 10.f;
    static constexpr float player_jump = 50.f;
    static constexpr float player_impulse = 100.f;
    static constexpr float player_max_vel[2] = { 200.f,400.f };
    static constexpr float player_friction = 100.f;
    static constexpr float player_restitution = 0.0f;
};
