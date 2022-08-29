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
WIDTH, HEIGHT = 900, 900
RES = 10
OFFSET = 1

cell_size = WIDTH // RES


SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Game of Life")

clock = pygame.time.Clock()


def draw_grid(grid, live_color, death_color):
  for i in range(cell_size):
    for j in range(cell_size):
      if grid[i][j] == 1:
        pygame.draw.rect(SCREEN, live_color, [i * RES, j * RES, RES-1, RES-1])
      else:
        pygame.draw.rect(SCREEN, death_color, [i * RES, j * RES, RES-1, RES-1])


def count_neighbours(x,y, grid):
  nsum = 0 

  for i in range(-1, 2):
    for j in range(-1, 2):

      col = (x + i + cell_size) % cell_size;
      row = (y + j + cell_size) % cell_size;
      nsum += grid[col][row];

  nsum -= grid[x][y]
  return nsum;

def game_of_life(grid):
  for i in range(cell_size):
    for j in range(cell_size):
      if (count_neighbours(i, j, grid) == 2 or count_neighbours(i, j, grid) == 3) and grid[i][j] == 1:
        grid[i][j] = 1
      
      elif count_neighbours(i, j, grid) == 3 and grid[i][j] == 0:
        grid[i][j] = 1
      
      else:
        grid[i][j] = 0
  
  return grid
def main():
  grid_array = np.random.randint(0, 2, size=(cell_size, cell_size))
  while True:
    clock.tick(60)
    for event in pygame.event.get():
      if event.type == pygame.QUIT:
        pygame.quit()
        sys.exit(0)
    SCREEN.fill(BLACK)
    draw_grid(game_of_life(grid_array), WHITE, BLUE)    
    pygame.display.update()



    # time.sleep(0.01)

if __name__ == "__main__":
  main()