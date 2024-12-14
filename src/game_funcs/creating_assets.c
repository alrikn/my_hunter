/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** creating_assets
*/

#include "./../../include/my.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

sfSprite *sprite_texture_add(char *filepath, core_t *fm)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    if (!texture) {
        return NULL;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfSprite *create_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfIntRect area = {0, 1 * 16, 1 * 16, 1 *16};
    sfVector2f scale = {-10, 10};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, area);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *create_background(char *filepath, core_t *fm)
{
    sfSprite *background = sprite_texture_add(filepath, fm);
    sfVector2u window_size = sfRenderWindow_getSize(fm->window);
    sfVector2u texr_s = sfTexture_getSize(sfSprite_getTexture(background));
    sfVector2f scale = {
        (float)window_size.x / texr_s.x,
        (float)window_size.y / texr_s.y
    };

    sfSprite_setScale(background, scale);
    return background;
}

void animate_sprite(sfSprite *sprite, int frame_count)
{
    sfIntRect area = sfSprite_getTextureRect(sprite);

    area.left = (area.left + 16);
    if (area.left >= frame_count * 16)
        area.left = 0;
    sfSprite_setTextureRect(sprite, area);
}

sfText *create_score_text(sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f position = {10, 10};

    if (!font) {
        my_cooler_putstr("font failed to load\n");
    }
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfWhite);
    sfText_setString(text, "score = 0");
    sfText_setPosition(text, position);
    return text;
}
