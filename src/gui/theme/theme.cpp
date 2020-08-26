#include "config.h"
#include "theme.h"

theme_config_t theme_config;
LV_IMG_DECLARE(casio1);


  LV_FONT_DECLARE(Ubuntu_72px);
  // LV_FONT_DECLARE(Ubuntu_16px);


static lv_style_t theme_style;
static lv_style_t time_style;

lv_style_t *theme_get_style( void ) {
    return( &theme_style );
}

lv_style_t *theme_get_time_style(void) {
    return (&time_style);
}

theme_config_t *theme_get_config( void ) {
    return( &theme_config );
}

void theme_setup( void ) {
    if (theme_config.show_main_tile_image_background == true) {
        lv_coord_t hres = lv_disp_get_hor_res(NULL);
        lv_coord_t vres = lv_disp_get_ver_res(NULL);
        
        // Create wallpaper
        lv_obj_t *main_tile_background_image = lv_img_create( lv_scr_act() , NULL);  /*Create an image object*/
        lv_img_set_src(main_tile_background_image, &casio1);
        lv_obj_set_width(main_tile_background_image, hres );
        lv_obj_set_height(main_tile_background_image, vres );
        lv_obj_align(main_tile_background_image, NULL, LV_ALIGN_CENTER, 0, 0);
    }

    // default_background_theme
    lv_style_init( &theme_style );
    lv_style_set_bg_color( &theme_style, LV_OBJ_PART_MAIN, theme_config.default_tile_background_color);
    lv_style_set_bg_opa( &theme_style, LV_OBJ_PART_MAIN, theme_config.default_tile_background_opacity);
    lv_style_set_border_width( &theme_style, LV_OBJ_PART_MAIN, theme_config.default_tile_border_width);
    lv_style_set_image_recolor(&theme_style, LV_OBJ_PART_MAIN, LV_COLOR_WHITE);

    // time style
    lv_style_init( &time_style );
    lv_style_set_text_font( &time_style, LV_STATE_DEFAULT, &Ubuntu_72px);
    lv_style_set_text_color(&time_style, LV_OBJ_PART_MAIN, theme_config.time_color);
}
