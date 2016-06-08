#include "orb.h"

Orb::Orb()
{
    
}

Orb::~Orb()
{
}

void Orb::work(std::string& file)
{
    VideoCapture cap(0); // Открыть камеру (устройство 1). Для открытия встроенной камеры вызывать 0 устройство.
	if(!cap.isOpened())  //  Проверка корректности отработки
	{
		string message = "Проверьте камеру или укажите другой номер устройства в коде";
		readme(message); 
		return -1;
	}

	Mat img_object = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
    int minHessian = 400;

    SurfFeatureDetector detector( minHessian );

    std::vector<KeyPoint> keypoints_object, keypoints_scene;

    detector.detect( img_object, keypoints_object );
    detector.detect( img_scene, keypoints_scene );
}
