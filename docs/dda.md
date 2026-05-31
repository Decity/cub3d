

DDA Pseudo:

for each column x:
    1. compute camera_x = 2 * x / SCREEN_W - 1  (-1 to +1 across screen)
    2. ray_dir = dir + plane * camera_x
    3. figure out which tile the player is in: map_x = (int)pos_x
    4. compute delta_dist_x/y (how far ray travels per grid crossing)
    5. DDA: step through tiles until you hit a '1'
    6. compute perp_wall_dist (perpendicular, not Euclidean)
    7. wall_height = (int)(SCREEN_H / perp_wall_dist)
    8. draw ceiling pixels (floor_color), wall slice, floor pixels