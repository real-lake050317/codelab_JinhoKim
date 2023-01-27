import PIL 
from PIL import Image, ImageDraw
import numpy as np

# input image
im = Image.open("input.png")

# change to grayscale
im = im.convert("L")
