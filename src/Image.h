//
// Created by User on 2020-03-27.
//

#ifndef ASSIGNMENT_4_IMAGE_H
#define ASSIGNMENT_4_IMAGE_H

#include <vector>
#include <string>

using std::vector;

namespace ZMMALE001{

    struct RGB {

        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char grey;

        RGB(): red(0),blue(0),green(0),grey(0){};

    };

    class Image{
    private:
        unsigned int width,height;
        vector<RGB> pixels;
        unsigned int clusterValue;
    public:
        unsigned int getClusterValue() const;

    public:
        void setClusterValue(unsigned int clusterValue);

    private:


        vector< vector<int> > hist_grey_bins;
    public:
        const vector<vector<int>> &getHistGreyBins() const;

    private:
        vector< vector<int> > hist_red_bins;
        vector< vector<int> > hist_green_bins;
        vector< vector<int> > hist_blue_bins;

        std::string filename;

    public:

        Image();
        Image(int w, int h, std::string fname);

        void addPixel(RGB pix);
        void processHist(int bin_size, bool colour);
        const std::string &getFilename() const;
        unsigned int &getHeight();
        unsigned int &getWidth();
        RGB &get(unsigned int a, unsigned int b);
    };
}
#endif //ASSIGNMENT_4_IMAGE_H