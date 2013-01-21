#include "imagedata.h"

ImageData::ImageData(const IplImage & image)
    : m_image(image)
{

}


QPixmap ImageData::toPixmap(void)
{
    if( m_image.depth != IPL_DEPTH_8U)
    {
        qWarning("This type of IplImage is not implemented in QOpenCVWidget\ndepth must be 'IPL_DEPTH_8U'");
        return QPixmap();
    }
    if( m_image.nChannels != 3)
    {
        qWarning("This number of channels is not supported\n");
        return QPixmap();
    }
    QImage image(m_image.width, m_image.height, QImage::Format_RGB32);
    int cvIndex = 0;
    int cvLineStart = 0;
    for (int y = 0; y < m_image.height; y++)
    {
        unsigned char red,green,blue;
        cvIndex = cvLineStart;
        for (int x = 0; x < m_image.width; x++)
        {
            red = m_image.imageData[cvIndex+2];
            green = m_image.imageData[cvIndex+1];
            blue = m_image.imageData[cvIndex+0];

            image.setPixel(x,y,qRgb(red, green, blue));
            cvIndex += 3;
        }
        cvLineStart += m_image.widthStep;
    }

    return QPixmap::fromImage(image);
}
