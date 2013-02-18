#include "putyourcodehere.h"
#include "Parameters/slider.h"
#include "Parameters/dial.h"
#include "Parameters/spinbox.h"
#include "Parameters/radiobutton.h"
#include "Parameters/colorselection.h"
#include "Parameters/inputtext.h"
#include "Parameters/checkbox.h"


PutYourCodeHere::PutYourCodeHere()
    : VirtualHandle("PutYourCodeHere") //handle's name
{
    m_listParameters.resize(3);
    m_listParameters[0] = std::shared_ptr<HandleParameters>(new HandleParameters() );
    m_listParameters[0]->changeSources( new ColorSelection("Nothing"));

    m_listParameters[1] = std::shared_ptr<HandleParameters>(new HandleParameters() );
    m_listParameters[1]->changeSources( new InputText("Nothing", "kikoo"));

    m_listParameters[2] = std::shared_ptr<HandleParameters>(new HandleParameters() );
    m_listParameters[2]->changeSources( new CheckBox("Nothing", QStringList({"ee","gg"}) ) );

    m_dependancies.push_back( VirtualHandle::getHandleForDependancies("Rotation") );
}

// your handle
ImageDataPtr PutYourCodeHere::startHandle(ImageDataPtr source, const ImageDataPtr source1)
{
    //executeHandle("ToFiles", source, source1);
    return executeHandle("Rotation", source, source1);
    //put your code here !
    //return source;
}
