inc/
    cub3d.h 
    defs
    controls

hooks/
    on_key()
        move_player()
        rotate_player()
    close_window()

main()
 init()
    init_mlx()
    init_map()
    init_player()
 parse()
    validate_params()
    validate_map()
 run()
    render()
        draw_map()
            draw_tile()
        draw_player()
            draw_tile()
        draw_dir()
            draw_line()
 clean_up()
