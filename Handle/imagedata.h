#ifndef IMAGEDATA_H
#define IMAGEDATA_H

#include <opencv2/opencv.hpp>
#include <memory>

/** @brief Contains an Image and his data */
class ImageData
{
public:
    /** @brief Construct an ImageData from an existant IplImage
        @param const IplImage & image : image which will be stocked */
    ImageData(const IplImage & image);

    /** @brief Get the stocked Image
        @return IplImage * : pointer to the stocked image. */
    IplImage * getImage(void);
private :

    /** @brief Image */
    IplImage m_image;
};

typedef std::shared_ptr<ImageData> ImageDataPtr;

#endif // IMAGEDATA_H
