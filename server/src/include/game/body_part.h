#ifndef GAME_BODY_PART_H
#define GAME_BODY_PART_H

#define RIGHT_FRONT_DOWN 0
#define LEFT_FRONT_DOWN 1
#define RIGHT_FRONT_UP 2
#define LEFT_FRONT_UP 3
#define LEFT_BACK_DOWN 4
#define RIGHT_BACK_DOWN 5
#define LEFT_BACK_UP 6
#define RIGHT_BACK_UP 7
#include <game/items.h>
#include <string>

struct body_part {
    std::string name;
    float mod;
    item_t* item;
    bool is_fortified;
    body_part(std::string _name, float _mod);

    item_t* put_on(item_t* thing);
    item_t* put_off();
};

int count_dmg(body_part bp, int damage);
#endif // GAME_BODY_PART_H
