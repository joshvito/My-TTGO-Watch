#ifndef _THEME_H

    #define _THEME_H

    #include <TTGO.h>
    
    LV_FONT_DECLARE(Ubuntu_72px);
    LV_FONT_DECLARE(Ubuntu_16px);

    typedef struct {
        bool show_main_tile_image_background = true;
        //lv_obj_t main_tile_background_image;
        lv_color16_t default_tile_background_color = LV_COLOR_BLACK;
        lv_color16_t time_color = LV_COLOR_BLACK;
        // lv_font_t time_font = Ubuntu_72px;
        int default_tile_background_opacity = LV_OPA_100;
        int default_tile_border_width = 0;
        // lv_font_t Ubuntu_72px = Ubuntu_72px;
        // lv_font_t Ubuntu_16px = Ubuntu_16px;
    } theme_config_t;

    theme_config_t *theme_get_config( void );
    
    /*
     * @brief setup the theme
     * this will add a bg image to the main tile
     */
    void theme_setup( void );
    /*
     * @brief get main theme style
     * 
     * @return  lv_style_t
     */
    lv_style_t *theme_get_style(void);
    /*
     * @brief get time digits style
     * 
     * @return  lv_style_t
     */
    lv_style_t *theme_get_time_style(void);

#endif // _THEME_H