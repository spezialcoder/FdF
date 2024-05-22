import sdl2
import sdl2.ext
import numpy as np
from math import sqrt,cos,sin

class Wireframe:
    def __init__(self, width, height, file):
        self.width = width
        self.height = height
        self.file = file    
        self.verticies = []
        self.scale = 0.5
        self.rot_x = 0
        self.rot_y = 0
        self.pos_x = 0
        self.pos_y = 0
        self.height_scale = 1
        sdl2.ext.init()
        self.win = sdl2.ext.Window("Wireframe", size=(self.width,self.height))
        self.win.show()
        self.renderer = sdl2.ext.Renderer(self.win)
    
    def load_map(self):
        fl = open(self.file,"r")
        for y, line in enumerate(fl.read().split("\n")):
           self.verticies.append([(x,y,int(z)) for x,z in enumerate(line.split())])
        self.verticies.remove([])

    def get_matrix(self):
        return np.dot(np.array([
            [1,0,0],
            [0,cos(self.rot_x),-sin(self.rot_x)],
            [0,sin(self.rot_x),cos(self.rot_x)]
            ]),np.dot(np.array([
                [cos(self.rot_y),0,sin(self.rot_y)],
                [0,1,0],
                [-sin(self.rot_y),0,cos(self.rot_y)]]), np.array([
                    [self.scale,0,0],
                    [0,self.scale,0],
                    [0,0,self.scale]
                    ])))

    def plot_grid(self):
        self.renderer.clear(sdl2.ext.Color(0,0,0,255))
        isometric = np.array([
            [sqrt(3)/2,-sqrt(3)/2,0],
            [1/2,1/2,-1]])
        grid_x = lambda x: (((self.width)/len(self.verticies[0]))*x)
        grid_y = lambda y: (((self.height)/len(self.verticies))*y)
        vert = lambda x,y,i: self.verticies[y][x][i]
        iso_point = lambda x,y: np.dot(np.array([
            [1,0,self.pos_x],
            [0,1,self.pos_y]]),np.append(
                np.dot(isometric,np.dot(self.get_matrix(),np.array([
            grid_x(vert(x,y,0)),
            grid_y(vert(x,y,1)),
            vert(x,y,2)*self.height_scale]))),1))
        for x in range(0,len(self.verticies[0])):
            for y in range(0,len(self.verticies)):
                if x < len(self.verticies[0])-1:
                    self.renderer.draw_line([
                        #(grid_x(vert(x,y,0)),grid_y(vert(x,y,1))),
                        #(grid_x(vert(x+1,y,0)), grid_y(vert(x+1,y,1)))
                        iso_point(x,y),
                        iso_point(x+1,y)
                        ],
                            sdl2.ext.Color(125+vert(x,y,2)*11,125,125,255))
                if y < len(self.verticies)-1:
                    self.renderer.draw_line([
                        #(grid_x(vert(x,y,0)),grid_y(vert(x,y,1))),
                        #(grid_x(vert(x,y+1,0)),grid_y(vert(x,y+1,1)))
                        iso_point(x,y),
                        iso_point(x,y+1)
                        ],
                        sdl2.ext.Color(125+vert(x,y,2)*11,125,125,255))

        self.renderer.present()

if __name__ == "__main__":
    fdf = Wireframe(1920,1080,"test_maps/42.fdf")
    fdf.load_map()
    for row in fdf.verticies:
        print(row)
    fdf.plot_grid()
    running = True
    while running:
        events = sdl2.ext.get_events()
        for event in events:
            if event.type == sdl2.SDL_QUIT:
                running = False
            elif event.type == sdl2.SDL_MOUSEWHEEL:
                fdf.height_scale += event.wheel.y
                fdf.plot_grid()
            elif event.type == sdl2.SDL_KEYDOWN:
                if event.key.keysym.sym == sdl2.SDLK_UP:
                    fdf.rot_y += 0.05
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_DOWN:
                    fdf.rot_y -= 0.05
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_LEFT:
                    fdf.rot_x -= 0.05
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_RIGHT:
                    fdf.rot_x += 0.05
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_a:
                    fdf.pos_x -= 30
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_d:
                    fdf.pos_x += 30
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_w:
                    fdf.pos_y -= 30
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_s:
                    fdf.pos_y += 30
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_EQUALS:
                    fdf.scale -= 0.05
                    fdf.plot_grid()
                elif event.key.keysym.sym == sdl2.SDLK_MINUS:
                    fdf.scale += 0.05
                    fdf.plot_grid()
            elif event.type == sdl2.SDL_MOUSEBUTTONDOWN:
                fdf.pos_y = event.button.y
                fdf.pos_x = event.button.x
                fdf.plot_grid()
                
sdl2.ext.quit()
