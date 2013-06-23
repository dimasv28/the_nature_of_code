//
//  draw.h
//  Heroes
//
//  Created by sk8er on 13.05.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Heroes_draw_h
#define Heroes_draw_h

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

typedef struct
{
    CCPoint pt1;
    CCPoint pt2;
    float r;
    float g;
    float b;
    float width;
} DebugLine;

typedef struct
{
    CCPoint pt;
    float r;
    float g;
    float b;
} DebugPoint;

class DebugDraw : public CCNode
{
public:
    static DebugDraw* create();
    
    DebugDraw();
    ~DebugDraw();
    virtual void draw(void);
    
    void appendLine(CCPoint pt1, CCPoint pt2, float r = 1, float g = 1, float b = 1, float width = 10);
    void appendPoint(float x, float y, float r = 1, float g = 1, float b = 1);
    void appendPoint(CCPoint pt, float r = 1, float g = 1, float b = 1);
    void clear();
    void clearPart(int i);
    std::vector<DebugLine>* getLines() { return m_lines; }
    std::vector<DebugPoint>* getPoints() { return m_points; }
    
    
private:
    std::vector<DebugLine>* m_lines;
    std::vector<DebugPoint>* m_points;
};


#endif
