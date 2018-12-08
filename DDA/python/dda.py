import sys,pygame
from pygame import gfxdraw

pygame.init()
screen = pygame.display.set_mode((400,400))
screen.fill((0,0,0))
pygame.display.flip()

white=(255,255,255)

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

dda(-5,10,5,20)

while 1:
	for event in pygame.event.get():
		if event.type == pygame.QUIT: sys.exit()
