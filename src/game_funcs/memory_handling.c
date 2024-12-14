/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** memory_handling
*/
#include "./../../include/my.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>

int destroy_textures(core_t *fm)
{
    sfTexture *texture_sp = (sfTexture *)sfSprite_getTexture(fm->bird_sprite);
    sfTexture *texture_back = (sfTexture *)sfSprite_getTexture(
        fm->background.back_sp);
    sfTexture *text_back_pause = (sfTexture *)sfSprite_getTexture(
        fm->background.back_pause);

    if (texture_sp)
        sfTexture_destroy(texture_sp);
    if (texture_back)
        sfTexture_destroy(texture_back);
    if (text_back_pause)
        sfTexture_destroy(text_back_pause);
    return 0;
}

int destroy_everything(core_t *fm)
{
    destroy_textures(fm);
    sfSprite_destroy(fm->background.back_pause);
    sfText_destroy(fm->text);
    sfRenderWindow_close(fm->window);
    sfSprite_destroy(fm->background.back_sp);
    sfSprite_destroy(fm->bird_sprite);
    sfRenderWindow_destroy(fm->window);
    sfClock_destroy(fm->time.clock);
    sfMusic_destroy(fm->background.background_music);
    sfMusic_destroy(fm->hit_sound);
    return 0;
}
