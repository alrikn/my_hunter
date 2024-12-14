/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** initializer
*/
#include "./../../include/my.h"
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Types.h>
#include <SFML/Config.h>
//sfMusic_pause(sfMusic *music);
//sfMusic_stop(sfMusic *music);

static sfSprite *create_start_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfIntRect area = {30, 30, 115, 40};
    sfVector2f scale = {10, 10};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, area);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

int music_time(core_t *fm)
{
    fm->background.background_music = sfMusic_createFromFile(
        "assets/mod_mice_on_venus.ogg");
    fm->hit_sound = sfMusic_createFromFile("assets/tap.ogg");
    sfMusic_setLoop(fm->background.background_music, sfTrue);
    sfMusic_play(fm->background.background_music);
    sfMusic_setVolume(fm->background.background_music, 60);
    sfMusic_setVolume(fm->hit_sound, 20);
    return 0;
}

int initializer(core_t *fm)
{
    sfVideoMode mode = {1200, 800, 32};
    sfUint32 style = {sfClose | sfResize};
    sfSprite *bird_sprite = create_sprite("assets/BirdSprite.png");
    sfVector2f position = {0, 300};
    sfFont *font = sfFont_createFromFile("assets/Xolonium-Regular.ttf");

    music_time(fm);
    fm->time.clock = sfClock_create();
    fm->status.game_over = false;
    fm->bird_sprite = bird_sprite;
    fm->mode = mode;
    fm->window = sfRenderWindow_create(mode, "amazing", style, 0);
    fm->position = position;
    fm->background.back_sp = create_background("assets/background.png", fm);
    fm->background.back_pause = create_background("assets/pause_scr.png", fm);
    fm->start_sprite = create_start_sprite("assets/start_button.png");
    fm->text = create_score_text(font);
    fm->status.is_paused = true;
    return 0;
}
