#1 
#2 git add

import matplotlib.mathtext as mathtext
import numpy as np
import random
import matplotlib
import math
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from time import sleep

def fraction_number():
   d = random.randint(1,9)
   return d, random.randint(d+1, 10)

def lcm(x, y):
   if x > y:
       greater = x
   else:
       greater = y
   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1
   return lcm


def pie_parameters(denomitor, numerator):
  d=1
  sizes = []
  labels = []
  colors= []
  explode= []
  while d<=numerator:
    sizes.append(1)
    labels.append(d)
    if d<=denomitor:
      colors.append("gold")
      explode.append(-0.02)
    else:
      colors.append("green")
      explode.append(0)
    d+=1
  return sizes, labels, colors, explode

def make_fraction_img(denomitor, numerator, name):
   parser = mathtext.MathTextParser("Bitmap")
   parser.to_png(name, r'$\frac{' +  str(denomitor) +r'}{' + str(numerator)+ r' }$ ', color='gold', fontsize=120, dpi=300)

def draw_fraction_pie(count):
   global n1, n2, d1, d2
   while True:
      plt.cla()
      plt.clf()
      if draw_fraction_pie.event%2 == 0:
         d1, n1 = fraction_number()
         d2, n2 = fraction_number()
         make_fraction_img(d1, n1, "num1.png")
         make_fraction_img(d2, n2, "num2.png")
      else:
         n = lcm(n1,n2);
         d1 *= n/n1
         n1 = n
         d2 *= n/n2
         n2 = n
         make_fraction_img(d1, n, "num1.png")
         make_fraction_img(d2, n, "num2.png")

      draw_fraction_pie.event+=1
      plt.subplot(2,2,1)
      num1 = mpimg.imread("num1.png")
      plt.axis('off')
      plt.imshow(num1)

      plt.subplot(2,2,3)
      sizes, labels, colors, explode = pie_parameters(d1, n1)
      explode=tuple(explode)
      plt.pie(sizes, explode=explode, labels=labels, colors=colors, shadow=False)
      plt.axis('equal')

      plt.subplot(2,2,2)
      num1 = mpimg.imread("num2.png")
      plt.axis('off')
      plt.imshow(num1)
      plt.subplot(2,2,4)
      sizes, labels, colors, explode = pie_parameters(d2, n2)
      explode=tuple(explode)
      plt.pie(sizes, explode=explode, labels=labels, colors=colors, shadow=False)
      plt.axis('equal')
      plt.show("off")
      #plt.draw()
      if draw_fraction_pie.event == 1:
        plt.draw()
      else:
         plt.draw()
         #plt.show()
draw_fraction_pie.event=0


new_draw = False
def onclick(event):
   print ("onclick")
   draw_fraction_pie(2)


d1 = 0
n1 = 0
d2 = 0
n2 = 0

#plt.ion()
fig = plt.figure()
##cid = fig.canvas.mpl_connect('key_press_event', onclick)
draw_fraction_pie(2)

while False:
  if new_draw:
    print ("new draw: %d" % new_draw)
    fig = plt.figure()
    cid = fig.canvas.mpl_connect('key_press_event', onclick)
    new_draw = False 
    draw_fraction_pie(2)
    print ("after drawing")
  else:
    print ("new draw: %d" % new_draw)

