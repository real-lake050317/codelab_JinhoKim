package converter;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.lang.Math;
//import java.io.File;
//import java.io.IOException;

interface blackwhite {
   
    BufferedImage using_bufferedimage(BufferedImage img);

}


public class convert_blackwhite implements blackwhite{

    public BufferedImage using_bufferedimage(BufferedImage img){    
        //get image width and height
        int width = img.getWidth();
        int height = img.getHeight();
    
        //convert to grayscale
        for(int y = 0; y < height; y++){
          for(int x = 0; x < width; x++){
            int p = img.getRGB(x,y);
    
            int a = (p>>24)&0xff;
            int r = (p>>16)&0xff;
            int g = (p>>8)&0xff;
            int b = p&0xff;
    
            //calculate average
            int avg = (r+g+b)/3;
    
            //replace RGB value with avg
            p = (a<<24) | (avg<<16) | (avg<<8) | avg;
    
            img.setRGB(x, y, p);
          }
        }
        return img;   
    }

}