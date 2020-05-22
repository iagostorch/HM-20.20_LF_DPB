#include "aux.h"


aux::~aux() {
}

void export_frame(string frame_title, TComPicYuv* pic)
{

    Pel* samples = pic->getBuf(COMPONENT_Y);
    int height = pic->getHeight(COMPONENT_Y);
    int width = pic->getWidth(COMPONENT_Y);

    ofstream image(frame_title + ".pgm");
    image << "P2" << endl;
//        image << "832 480" << endl;
    image << width << " " << height << endl;
    image << "255" << endl;
    for(int h=0; h<height; h++){
        for(int w=0; w<width; w++){
        // frame has a margin of maxCUwidth+16 (equals 80) around it
            image << samples[80*(width+2*80) + 80 + h*(width+2*80) + w] << " ";
        }
        image << endl;
    }    
}
        
 