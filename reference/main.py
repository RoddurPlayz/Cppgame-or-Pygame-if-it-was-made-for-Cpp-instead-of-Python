import curses
from lupa import LuaRuntime

class GameEngine:
    def __init__(self, stdscr):
        self.stdscr = stdscr
        curses.curs_set(0)
        self.stdscr.timeout(100)
        self.height, self.width = self.stdscr.getmaxyx()
        self.entities = []
        self.camera_x = 0
        self.camera_y = 0
        self.smooth_scroll = None
        self.game_logic = None
        self.lua = LuaRuntime(unpack_returned_tuples=True)

    def add_entity(self, entity):
        self.entities.append(entity)

    def set_smooth_scroll(self, smooth_scroll):
        self.smooth_scroll = smooth_scroll

    def set_game_logic(self, game_logic):
        self.game_logic = game_logic

    def handle_input(self, key):
        for entity in self.entities:
            entity.handle_input(key)
        if self.smooth_scroll:
            self.smooth_scroll.handle_input(key)
        if self.game_logic:
            self.game_logic.handle_input(key)

    def update(self):
        for entity in self.entities:
            entity.update()
        if self.smooth_scroll:
            self.smooth_scroll.update()
        if self.game_logic:
            self.game_logic.update()

    def draw(self):
        self.stdscr.clear()
        for entity in self.entities:
            entity.draw(self.stdscr, self.camera_x, self.camera_y)

        self.stdscr.refresh()

    def run(self):
        while True:
            key = self.stdscr.getch()

            if key == ord('q'):
                break

            self.handle_input(key)
            self.update()
            self.draw()

# Animatable Entity
class Entity:
    def __init__(self, game_engine, y, x, char, lua_script=None):
        self.game_engine = game_engine
        self.y = y
        self.x = x
        self.char = char
        self.lua_script = lua_script
        self.collision_body = None

    def add_collision_body(self, collision_body):
        self.collision_body = collision_body

    def handle_input(self, key):
        if self.lua_script:
            self.game_engine.lua.execute(self.lua_script)

    def update(self):
        pass

    def draw(self, stdscr, camera_x, camera_y):
        stdscr.addch(self.y - camera_y, self.x - camera_x, self.char)

# Game Logic Class
class GameLogic:
    def __init__(self, game_engine):
        self.game_engine = game_engine

    def handle_input(self, key):
        pass

    def update(self):
        pass
