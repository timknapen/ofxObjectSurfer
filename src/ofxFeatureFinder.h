//
//  featureManager.h
//  ofxKinectOsc
//
//  Created by joe on 12/18/13.
//
//

#ifndef __ofxKinectOsc__featureManager__
#define __ofxKinectOsc__featureManager__

#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/calib3d/calib3d.hpp> // for homography

#include "ofMain.h"
#include "ofxFeatureFinderObject.h"


class ofxFeatureFinder {
private:
    ofRectangle rect;
    IplImage *image;
    
    CvMemStorage* storage;
    
    std::vector<ofPolyline> regions;
    bool bDrawingRegion;

    std::vector<cv::KeyPoint> imageKeypoints;
    cv::Mat imageDescriptors;
    
    std::vector<ofxFeatureFinderObject> objects;
    
    bool detectObject(ofxFeatureFinderObject object, cv::Mat &homography);

public:
    ofxFeatureFinder();

    CvSeq *getImageKeypoints();
    
    void setFrame(int x, int y, int width, int height);
    
    void findKeypoints(IplImage *image);
    
    void draw();
    void drawFeatures();
    void drawRegions();
    
    void createObject();
    
    void clearRegions();

    void detectObjects();

    void mouseMoved(ofMouseEventArgs &args);
    void mousePressed(ofMouseEventArgs &args);
    void mouseDragged(ofMouseEventArgs &args);
    void mouseReleased(ofMouseEventArgs &args);

};

#endif /* defined(__ofxKinectOsc__featureManager__) */
