#include "../../exception.h"
#include "folderreader.h"

FolderReader::FolderReader(const std::string s)
{
    QDir dir( s.c_str() );

    bool rep = isPossible(s);

    if(rep == false)
        throw Exception::buildException("Attention ce dossier n'existe pas !!!", "FolderReader", "Folderreader", EPC);

    QFileInfoList liste = dir.entryInfoList(QDir::Files);
    std::map<QDateTime, QString> listePath;

    std::for_each(liste.begin(), liste.end(), [&listePath, this](QFileInfo & info){

                  listePath[parseFileName(info.fileName())] = info.fileName();
    });

   iterator = listePath.begin();
}



void FolderReader::grab()
{
    ++iterator;
}



void FolderReader::remplissage(const std::string nom, QDateTime date, QString s)
{
    std::map<QDateTime, QString> listePath;

    bool rep = isPossible(nom);

    if(rep == false)
        throw Exception::buildException("Attention ce n'est pas un nom de dossier valide !!!", "FolderReader", "Folderreader", EPC);

    for(ListPath::iterator it = listePath.begin() ; it != listePath.end() ; ++it)
    {
        if(it->first == date)
            it->second = s;
    }
}



bool FolderReader::isPossible(const std::string nom)
{
    QDir dir( nom.c_str() );

    if( (!(dir.isReadable())) )
        return false;

    return true;
}



IplImage * FolderReader::getImage(void)
{
    static IplImage * data = NULL;

    if( data )
    {
        cvReleaseImage(&data);
    }

    data = cvLoadImage( iterator->second.toStdString().c_str() );

    return data;
}



QDateTime FolderReader::parseFileName(QString fileName)
{

    return QDateTime();
}
