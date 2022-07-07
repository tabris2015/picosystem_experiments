#include "picosystem.hpp"

using namespace picosystem;

uint32_t last_time;
uint32_t interval = 100;
bool led_state = false;
struct ball_pos_t {
    int x;
    int y;
};

ball_pos_t ball_pos{60,0};
int ball_direction = 1;
void init() {
    last_time = time();
}

void update(uint32_t tick) {
    if (time() >= last_time + interval)
    {
        led_state = !led_state;
        led(0, led_state * 30, led_state * 30);
        last_time = time();

        if (ball_pos.y > 120 || ball_pos.y < 0)
        {
            ball_direction *= -1;
        }
        ball_pos.y += ball_direction;
    }

}

void draw(uint32_t tick) {
    pen(0, 0, 0);
    clear();

    pen(15, 15, 15);
    sprite(GREEN_BALL, ball_pos.x, ball_pos.y);
}