import sys,pygame
from pygame import gfxdraw

white=(255,255,255)

# DDA Function Start
def dda(x1,y1,x2,y2):
	if(x1 > x2):
		x1 ,x2 = x2 ,x1
		y1 ,y2 = y2 ,y1
	x,y = x1,y1
	m = (y2 - y1) / (x2 - x1)
	print(m)
	length = (x2-x1) if (x2-x1) > (y2-y1) else (y2-y1)
	dx = (x2-x1)/float(length)
	dy = (y2-y1)/float(length)
	gfxdraw.pixel(screen,round(x),round(y),white)

	for i in range(length):
		x+= dx
		y+= dy
		gfxdraw.pixel(screen,round(x),round(y),white)
	pygame.display.flip()
# DDA Function End

# MAIN FUNCRION
x1 ,y1 = input("Enter the first point: ").split()
x2 ,y2 = input("Enter the second point: ").split()
pygame.init()
screen = pygame.display.set_mode((1000,1000))
screen.fill((0,0,0))
pygame.display.flip()
dda(int(x1),int(y1),int(x2),int(y2))

while 1:
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
