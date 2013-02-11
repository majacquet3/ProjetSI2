#ifndef FOLDERREADER_H
#define FOLDERREADER_H

#include "../imagedata.h"
#include "../videoreader.h"
#include <QDir>
#include <QDateTime>
#include <opencv2/opencv.hpp>


/** @brief Read a folder as an video stream */
class FolderReader : public VideoReader
{
private :
    typedef std::map<QDateTime, QString> ListPath;
    ListPath::iterator iterator;

public:
    FolderReader(const std::string);
    /** @brief Commentary */
    static QDateTime parseFileName(QString fileName);
    void grab();
    void remplissage(const std::string nom, QDateTime date, QString s);
    bool isPossible(const std::string s);
    IplImage * getImage(void);
};

#endif // FOLDERREADER_H
