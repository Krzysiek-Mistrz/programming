BASE(0, 1, 2)
MERGE = ON 'wlaczenie funkcji laczenia ruchow
MOVE(0, -1600)
MHELICAL(300, -300, 300, 0, 0, 90, 0)
MOVE(1200, 0)
MHELICAL(300, 300, 0, 300, 0, 90, 0)
MOVE(0, 800)
MHELICAL(-300, 300, -300, 0, 0, 90, 0)
MOVE(-1200, 0)
MHELICAL(-300, -300, 0, -300, 0, 90, 0)
WAIT IDLE 'oczekiwanie na zakonczenie ruchow
MERGE = OFF

