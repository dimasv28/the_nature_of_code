#ifndef __EXAMPLE_3_8__
#define __EXAMPLE_3_8__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Oscillator.h"

using namespace cocos2d;
using namespace std;
class Oscillator;

class Example_3_8 : public CCLayer {
protected:
	vector<Oscillator*> *oscillators;
	vector<Oscillator*>::iterator the_iterator;
	int arrLength;
	CCNode *centerPoint;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);

	CREATE_FUNC(Example_3_8);
};

#endif // __EXAMPLE_3_8__