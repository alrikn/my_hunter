/*
** EPITECH PROJECT, 2024
** fake_my_hunter
** File description:
** movement
*/

#include "./../../include/my.h"
#include <SFML/Audio/Types.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

void respawn(core_t *fm)
{
    fm->position.x = 0;
    fm->position.y = rand() % (fm->mode.height - 100);
}

sfVector2f placement(core_t *fm)
{
    float speed = 10.0;

    speed += (fm->score.score_num / 1.0) - (fm->score.bad_score_num / 2.0);
    fm->position.x += speed;
    if (fm->position.x >= fm->mode.width) {
        respawn(fm);
        fm->score.bad_score_num += 1;
    }
    return fm->position;
}
