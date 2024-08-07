'vr registers vars

'DIM input_register AS INTEGER = 0
DIM limit_switch AS INTEGER = 0 'jezeli != 0 to czujnik wlaczony

DIM base_control AS INTEGER = 1 'wlacza autobazowanie

DIM set_middle AS INTEGER = 2 'wlacza pozycjonowanie do srodka

DIM set_pos AS INTEGER = 3 'wlacza wpisywanie do numeric
DIM set_pos_x AS INTEGER = 4 'zapisuje wp. pozycje osi
DIM set_pos_y AS INTEGER = 5
DIM set_pos_z AS INTEGER = 6

DIM curr_speed AS INTEGER = 7 'default speed

DIM emergency_sw AS INTEGER = 8 'emergency sw
DIM on_off AS INTEGER = 9 'on/off sw
DIM resetting AS INTEGER = 10 'reset sw
