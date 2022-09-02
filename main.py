import time
import pygame
import numpy as np
import sys

pygame.init()

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 14, 71)

# Variables
WIDTH, HEIGHT = 800, 600
RES = 20
rows = WIDTH // RES
columns = HEIGHT // RES


SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Game of Life")


def draw_grid(grid, live_color, death_color):
  for i in range(rows):
    for j in range(columns):
      if grid[i][j] == 1:
        pygame.draw.rect(SCREEN, live_color, [i * RES, j * RES, RES-1, RES-1])
      else:
        pygame.draw.rect(SCREEN, death_color, [i * RES, j * RES, RES-1, RES-1])


def count_neighbours(x,y, grid):
  nsum = 0 

  for i in range(-1, 2):
    for j in range(-1, 2):
      col = (x + i + rows) % rows;
      row = (y + j + columns) % columns;
      nsum += grid[col][row];

  nsum -= grid[x][y]
  return nsum;

def game_of_life(grid):
  future = grid
  for i in range(rows):
    for j in range(columns):
      state = grid[i][j]
      neighbours = count_neighbours(i, j, grid)
      # Cell dies due to underpopulation
      if state == 1 and neighbours < 2:
        future[i][j] = 0

      # Cell dies due to overpopulation 
      elif state == 1 and neighbours > 3:
        future[i][j] = 0

      # A new cell is born
      elif state == 0 and neighbours == 3:
        future[i][j] = 1
  
  return future

def main():
  grid_array = np.zeros((rows, columns))
  draw_grid(grid_array, WHITE, BLUE)
  pygame.display.update()

  running = False

  while True:
    for event in pygame.event.get():
      if event.type == pygame.QUIT:
        pygame.quit()
        sys.exit()

      elif event.type == pygame.KEYDOWN:
        if event.key == pygame.K_SPACE:
          running = not running
        
        if event.key == pygame.K_c and not running:
          grid_array = np.zeros((rows, columns))
          draw_grid(grid_array, WHITE, BLUE)
          pygame.display.update()

      if pygame.mouse.get_pressed()[0]:
        pos = pygame.mouse.get_pos()
        grid_array[pos[0] // RES, pos[1] // RES] = 1
        draw_grid(grid_array, WHITE, BLUE) 
        pygame.display.update()


    if running:
      draw_grid(game_of_life(grid_array), WHITE, BLUE)
      pygame.display.update()
    
    time.sleep(0.1)

if __name__ == "__main__":
  main()