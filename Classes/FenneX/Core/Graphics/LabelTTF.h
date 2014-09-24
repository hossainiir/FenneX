/****************************************************************************
Copyright (c) 2013-2014 Auticiel SAS

http://www.fennex.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************///

#ifndef __FenneX__LabelTTF__
#define __FenneX__LabelTTF__

#include "Logs.h"
#include "cocos2d.h"
USING_NS_CC;
#include "RawObject.h"
#include "FenneXMacros.h"

NS_FENNEX_BEGIN
typedef enum
{
    ResizeFont = 0,//Default mode
    CutEnd = 1,
    NoResize = 2
}LabelFitType;

class LabelTTF : public RawObject
{
    CC_SYNTHESIZE(LabelFitType, fitType, FitType);
public:
    CCRect getBoundingBox();
    const char* getLabelValue();
    void setLabelValue(const char* value, bool async = false);
    
    //will return only the font name
    const char* getFontFile();
    float getFontSize();
    void setFontSize(float size);
    
    virtual CCNode* getNode();
    
    void setDimensions(CCSize dimensions);
    CCSize getDimensions();
    
    LabelTTF();
    //will try to load filenameLight.fnt before filename.fnt in case there is a light font (which includes less symbols than the full one)
    LabelTTF(const char* labelString, const char* filename, CCPoint location, CCSize dimensions = CCSizeZero, CCTextAlignment format = kCCTextAlignmentCenter);
    LabelTTF(Label* label);
    ~LabelTTF();
    
    virtual void update(float deltaTime);
    
    CCString* getFullFontFile();
    CCTextAlignment getAlignment();
    
protected:
    //the actual CCLabelBMFont which will perform cocos2d actions
    Label* delegate;
    
    CCSize realDimensions;
    void adjustLabel();
    CCString* fontFile;
    CCString* fullFontFile;
    CCTextAlignment alignment;
    
    std::string loadingValue;
};
NS_FENNEX_END

#endif /* defined(__FenneX__LabelTTF__) */