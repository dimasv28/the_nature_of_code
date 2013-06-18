//
//  TouchDraw.cpp
//  Heroes
//
//  Created by sk8er on 13.05.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "DebugDraw.h"

DebugDraw* DebugDraw::create()
{
    DebugDraw* draw = new DebugDraw();
    draw->autorelease();
    return draw;
}

DebugDraw::DebugDraw()
{
    m_lines = new std::vector<DebugLine>();
    m_points = new std::vector<DebugPoint>();
}

DebugDraw::~DebugDraw()
{
    delete m_lines;
    delete m_points;
}

void DebugDraw::draw(void)
{
    int c = m_lines->size();
    for (int i = 0; i < c; i++)
    {
        DebugLine line = m_lines->at(i);
        //glEnable(GL_BLEND);
        //glColorMask(line.r, line.g, line.b, 255);
        glLineWidth(line.width);
        ccDrawColor4B(line.r, line.g, line.b, 255);
        ccDrawLine(line.pt1, line.pt2);
    }
    
    c = m_points->size();
    for (int i = 0; i < c; i++)
    {
        DebugPoint pt = m_points->at(i);
        //glColorMask(pt.r, pt.g, pt.b, 255);
        glLineWidth(10.0);
        ccDrawColor4B(pt.r, pt.g, pt.b, 255);
        ccDrawPoint(pt.pt);
    }
}

void DebugDraw::appendLine(CCPoint pt1, CCPoint pt2, float r, float g, float b, float width)
{
    DebugLine line;
    line.pt1 = pt1;
    line.pt2 = pt2;
    line.r = r;
    line.g = g;
    line.b = b;
    line.width = width;
    m_lines->push_back(line);
}

void DebugDraw::appendPoint(float x, float y, float r, float g, float b)
{
    appendPoint(ccp(x, y), r, g, b);
}

void DebugDraw::appendPoint(CCPoint pt, float r, float g, float b)
{
    CCSprite *sp = CCSprite::create("circle.png");
    sp->setPosition(pt);
    ccColor3B c = {144,7,23};
    sp->setColor(c);
    if (m_points->size() == 0) {
        sp->setScale(1);
    } else {
        sp->setScale(0.5);
    }
    addChild(sp);
    
    
    DebugPoint dp;
    dp.pt = pt;
    dp.r = r;
    dp.g = g;
    dp.b = b;
    m_points->push_back(dp);
    
}


void DebugDraw::clear()
{
    m_lines->clear();
    m_points->clear();
    removeAllChildren();
}



void DebugDraw::clearPart(int i)
{
    
    while (i<m_lines->size())
    {
        m_lines->pop_back();
    }
    while (i<m_points->size())
    {
        m_points->pop_back();
    }
}







